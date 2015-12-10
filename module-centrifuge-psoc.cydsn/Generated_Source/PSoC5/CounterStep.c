/*******************************************************************************
* File Name: CounterStep.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CounterStep.h"

uint8 CounterStep_initVar = 0u;


/*******************************************************************************
* Function Name: CounterStep_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void CounterStep_Init(void) 
{
        #if (!CounterStep_UsingFixedFunction && !CounterStep_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!CounterStep_UsingFixedFunction && !CounterStep_ControlRegRemoved) */
        
        #if(!CounterStep_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 CounterStep_interruptState;
        #endif /* (!CounterStep_UsingFixedFunction) */
        
        #if (CounterStep_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            CounterStep_CONTROL &= CounterStep_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                CounterStep_CONTROL2 &= ((uint8)(~CounterStep_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                CounterStep_CONTROL3 &= ((uint8)(~CounterStep_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (CounterStep_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                CounterStep_CONTROL |= CounterStep_ONESHOT;
            #endif /* (CounterStep_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            CounterStep_CONTROL2 |= CounterStep_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            CounterStep_RT1 &= ((uint8)(~CounterStep_RT1_MASK));
            CounterStep_RT1 |= CounterStep_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            CounterStep_RT1 &= ((uint8)(~CounterStep_SYNCDSI_MASK));
            CounterStep_RT1 |= CounterStep_SYNCDSI_EN;

        #else
            #if(!CounterStep_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = CounterStep_CONTROL & ((uint8)(~CounterStep_CTRL_CMPMODE_MASK));
            CounterStep_CONTROL = ctrl | CounterStep_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = CounterStep_CONTROL & ((uint8)(~CounterStep_CTRL_CAPMODE_MASK));
            
            #if( 0 != CounterStep_CAPTURE_MODE_CONF)
                CounterStep_CONTROL = ctrl | CounterStep_DEFAULT_CAPTURE_MODE;
            #else
                CounterStep_CONTROL = ctrl;
            #endif /* 0 != CounterStep_CAPTURE_MODE */ 
            
            #endif /* (!CounterStep_ControlRegRemoved) */
        #endif /* (CounterStep_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!CounterStep_UsingFixedFunction)
            CounterStep_ClearFIFO();
        #endif /* (!CounterStep_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        CounterStep_WritePeriod(CounterStep_INIT_PERIOD_VALUE);
        #if (!(CounterStep_UsingFixedFunction && (CY_PSOC5A)))
            CounterStep_WriteCounter(CounterStep_INIT_COUNTER_VALUE);
        #endif /* (!(CounterStep_UsingFixedFunction && (CY_PSOC5A))) */
        CounterStep_SetInterruptMode(CounterStep_INIT_INTERRUPTS_MASK);
        
        #if (!CounterStep_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)CounterStep_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            CounterStep_WriteCompare(CounterStep_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            CounterStep_interruptState = CyEnterCriticalSection();
            
            CounterStep_STATUS_AUX_CTRL |= CounterStep_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(CounterStep_interruptState);
            
        #endif /* (!CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void CounterStep_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (CounterStep_UsingFixedFunction)
        CounterStep_GLOBAL_ENABLE |= CounterStep_BLOCK_EN_MASK;
        CounterStep_GLOBAL_STBY_ENABLE |= CounterStep_BLOCK_STBY_EN_MASK;
    #endif /* (CounterStep_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!CounterStep_ControlRegRemoved || CounterStep_UsingFixedFunction)
        CounterStep_CONTROL |= CounterStep_CTRL_ENABLE;                
    #endif /* (!CounterStep_ControlRegRemoved || CounterStep_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: CounterStep_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  CounterStep_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void CounterStep_Start(void) 
{
    if(CounterStep_initVar == 0u)
    {
        CounterStep_Init();
        
        CounterStep_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    CounterStep_Enable();        
}


/*******************************************************************************
* Function Name: CounterStep_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void CounterStep_Stop(void) 
{
    /* Disable Counter */
    #if(!CounterStep_ControlRegRemoved || CounterStep_UsingFixedFunction)
        CounterStep_CONTROL &= ((uint8)(~CounterStep_CTRL_ENABLE));        
    #endif /* (!CounterStep_ControlRegRemoved || CounterStep_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (CounterStep_UsingFixedFunction)
        CounterStep_GLOBAL_ENABLE &= ((uint8)(~CounterStep_BLOCK_EN_MASK));
        CounterStep_GLOBAL_STBY_ENABLE &= ((uint8)(~CounterStep_BLOCK_STBY_EN_MASK));
    #endif /* (CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void CounterStep_SetInterruptMode(uint8 interruptsMask) 
{
    CounterStep_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: CounterStep_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   CounterStep_ReadStatusRegister(void) 
{
    return CounterStep_STATUS;
}


#if(!CounterStep_ControlRegRemoved)
/*******************************************************************************
* Function Name: CounterStep_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   CounterStep_ReadControlRegister(void) 
{
    return CounterStep_CONTROL;
}


/*******************************************************************************
* Function Name: CounterStep_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    CounterStep_WriteControlRegister(uint8 control) 
{
    CounterStep_CONTROL = control;
}

#endif  /* (!CounterStep_ControlRegRemoved) */


#if (!(CounterStep_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: CounterStep_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void CounterStep_WriteCounter(uint16 counter) \
                                   
{
    #if(CounterStep_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (CounterStep_GLOBAL_ENABLE & CounterStep_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        CounterStep_GLOBAL_ENABLE |= CounterStep_BLOCK_EN_MASK;
        CY_SET_REG16(CounterStep_COUNTER_LSB_PTR, (uint16)counter);
        CounterStep_GLOBAL_ENABLE &= ((uint8)(~CounterStep_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(CounterStep_COUNTER_LSB_PTR, counter);
    #endif /* (CounterStep_UsingFixedFunction) */
}
#endif /* (!(CounterStep_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: CounterStep_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) The present value of the counter.
*
*******************************************************************************/
uint16 CounterStep_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(CounterStep_UsingFixedFunction)
		(void)CY_GET_REG16(CounterStep_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(CounterStep_COUNTER_LSB_PTR_8BIT);
	#endif/* (CounterStep_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(CounterStep_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(CounterStep_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(CounterStep_STATICCOUNT_LSB_PTR));
    #endif /* (CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint16) Present Capture value.
*
*******************************************************************************/
uint16 CounterStep_ReadCapture(void) 
{
    #if(CounterStep_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(CounterStep_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(CounterStep_STATICCOUNT_LSB_PTR));
    #endif /* (CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint16) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void CounterStep_WritePeriod(uint16 period) 
{
    #if(CounterStep_UsingFixedFunction)
        CY_SET_REG16(CounterStep_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(CounterStep_PERIOD_LSB_PTR, period);
    #endif /* (CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) Present period value.
*
*******************************************************************************/
uint16 CounterStep_ReadPeriod(void) 
{
    #if(CounterStep_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(CounterStep_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(CounterStep_PERIOD_LSB_PTR));
    #endif /* (CounterStep_UsingFixedFunction) */
}


#if (!CounterStep_UsingFixedFunction)
/*******************************************************************************
* Function Name: CounterStep_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void CounterStep_WriteCompare(uint16 compare) \
                                   
{
    #if(CounterStep_UsingFixedFunction)
        CY_SET_REG16(CounterStep_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(CounterStep_COMPARE_LSB_PTR, compare);
    #endif /* (CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint16) Present compare value.
*
*******************************************************************************/
uint16 CounterStep_ReadCompare(void) 
{
    return (CY_GET_REG16(CounterStep_COMPARE_LSB_PTR));
}


#if (CounterStep_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: CounterStep_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void CounterStep_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    CounterStep_CONTROL &= ((uint8)(~CounterStep_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    CounterStep_CONTROL |= compareMode;
}
#endif  /* (CounterStep_COMPARE_MODE_SOFTWARE) */


#if (CounterStep_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: CounterStep_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void CounterStep_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    CounterStep_CONTROL &= ((uint8)(~CounterStep_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    CounterStep_CONTROL |= ((uint8)((uint8)captureMode << CounterStep_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (CounterStep_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: CounterStep_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void CounterStep_ClearFIFO(void) 
{

    while(0u != (CounterStep_ReadStatusRegister() & CounterStep_STATUS_FIFONEMP))
    {
        (void)CounterStep_ReadCapture();
    }

}
#endif  /* (!CounterStep_UsingFixedFunction) */


/* [] END OF FILE */

