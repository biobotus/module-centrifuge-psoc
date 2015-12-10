/*******************************************************************************
* File Name: PositionCounter.c  
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

#include "PositionCounter.h"

uint8 PositionCounter_initVar = 0u;


/*******************************************************************************
* Function Name: PositionCounter_Init
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
void PositionCounter_Init(void) 
{
        #if (!PositionCounter_UsingFixedFunction && !PositionCounter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!PositionCounter_UsingFixedFunction && !PositionCounter_ControlRegRemoved) */
        
        #if(!PositionCounter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 PositionCounter_interruptState;
        #endif /* (!PositionCounter_UsingFixedFunction) */
        
        #if (PositionCounter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            PositionCounter_CONTROL &= PositionCounter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                PositionCounter_CONTROL2 &= ((uint8)(~PositionCounter_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                PositionCounter_CONTROL3 &= ((uint8)(~PositionCounter_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (PositionCounter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                PositionCounter_CONTROL |= PositionCounter_ONESHOT;
            #endif /* (PositionCounter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            PositionCounter_CONTROL2 |= PositionCounter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            PositionCounter_RT1 &= ((uint8)(~PositionCounter_RT1_MASK));
            PositionCounter_RT1 |= PositionCounter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            PositionCounter_RT1 &= ((uint8)(~PositionCounter_SYNCDSI_MASK));
            PositionCounter_RT1 |= PositionCounter_SYNCDSI_EN;

        #else
            #if(!PositionCounter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = PositionCounter_CONTROL & ((uint8)(~PositionCounter_CTRL_CMPMODE_MASK));
            PositionCounter_CONTROL = ctrl | PositionCounter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = PositionCounter_CONTROL & ((uint8)(~PositionCounter_CTRL_CAPMODE_MASK));
            
            #if( 0 != PositionCounter_CAPTURE_MODE_CONF)
                PositionCounter_CONTROL = ctrl | PositionCounter_DEFAULT_CAPTURE_MODE;
            #else
                PositionCounter_CONTROL = ctrl;
            #endif /* 0 != PositionCounter_CAPTURE_MODE */ 
            
            #endif /* (!PositionCounter_ControlRegRemoved) */
        #endif /* (PositionCounter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!PositionCounter_UsingFixedFunction)
            PositionCounter_ClearFIFO();
        #endif /* (!PositionCounter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        PositionCounter_WritePeriod(PositionCounter_INIT_PERIOD_VALUE);
        #if (!(PositionCounter_UsingFixedFunction && (CY_PSOC5A)))
            PositionCounter_WriteCounter(PositionCounter_INIT_COUNTER_VALUE);
        #endif /* (!(PositionCounter_UsingFixedFunction && (CY_PSOC5A))) */
        PositionCounter_SetInterruptMode(PositionCounter_INIT_INTERRUPTS_MASK);
        
        #if (!PositionCounter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)PositionCounter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            PositionCounter_WriteCompare(PositionCounter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            PositionCounter_interruptState = CyEnterCriticalSection();
            
            PositionCounter_STATUS_AUX_CTRL |= PositionCounter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(PositionCounter_interruptState);
            
        #endif /* (!PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_Enable
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
void PositionCounter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (PositionCounter_UsingFixedFunction)
        PositionCounter_GLOBAL_ENABLE |= PositionCounter_BLOCK_EN_MASK;
        PositionCounter_GLOBAL_STBY_ENABLE |= PositionCounter_BLOCK_STBY_EN_MASK;
    #endif /* (PositionCounter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!PositionCounter_ControlRegRemoved || PositionCounter_UsingFixedFunction)
        PositionCounter_CONTROL |= PositionCounter_CTRL_ENABLE;                
    #endif /* (!PositionCounter_ControlRegRemoved || PositionCounter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: PositionCounter_Start
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
*  PositionCounter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void PositionCounter_Start(void) 
{
    if(PositionCounter_initVar == 0u)
    {
        PositionCounter_Init();
        
        PositionCounter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    PositionCounter_Enable();        
}


/*******************************************************************************
* Function Name: PositionCounter_Stop
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
void PositionCounter_Stop(void) 
{
    /* Disable Counter */
    #if(!PositionCounter_ControlRegRemoved || PositionCounter_UsingFixedFunction)
        PositionCounter_CONTROL &= ((uint8)(~PositionCounter_CTRL_ENABLE));        
    #endif /* (!PositionCounter_ControlRegRemoved || PositionCounter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (PositionCounter_UsingFixedFunction)
        PositionCounter_GLOBAL_ENABLE &= ((uint8)(~PositionCounter_BLOCK_EN_MASK));
        PositionCounter_GLOBAL_STBY_ENABLE &= ((uint8)(~PositionCounter_BLOCK_STBY_EN_MASK));
    #endif /* (PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_SetInterruptMode
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
void PositionCounter_SetInterruptMode(uint8 interruptsMask) 
{
    PositionCounter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: PositionCounter_ReadStatusRegister
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
uint8   PositionCounter_ReadStatusRegister(void) 
{
    return PositionCounter_STATUS;
}


#if(!PositionCounter_ControlRegRemoved)
/*******************************************************************************
* Function Name: PositionCounter_ReadControlRegister
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
uint8   PositionCounter_ReadControlRegister(void) 
{
    return PositionCounter_CONTROL;
}


/*******************************************************************************
* Function Name: PositionCounter_WriteControlRegister
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
void    PositionCounter_WriteControlRegister(uint8 control) 
{
    PositionCounter_CONTROL = control;
}

#endif  /* (!PositionCounter_ControlRegRemoved) */


#if (!(PositionCounter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: PositionCounter_WriteCounter
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
void PositionCounter_WriteCounter(uint16 counter) \
                                   
{
    #if(PositionCounter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (PositionCounter_GLOBAL_ENABLE & PositionCounter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        PositionCounter_GLOBAL_ENABLE |= PositionCounter_BLOCK_EN_MASK;
        CY_SET_REG16(PositionCounter_COUNTER_LSB_PTR, (uint16)counter);
        PositionCounter_GLOBAL_ENABLE &= ((uint8)(~PositionCounter_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(PositionCounter_COUNTER_LSB_PTR, counter);
    #endif /* (PositionCounter_UsingFixedFunction) */
}
#endif /* (!(PositionCounter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: PositionCounter_ReadCounter
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
uint16 PositionCounter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(PositionCounter_UsingFixedFunction)
		(void)CY_GET_REG16(PositionCounter_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(PositionCounter_COUNTER_LSB_PTR_8BIT);
	#endif/* (PositionCounter_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(PositionCounter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(PositionCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(PositionCounter_STATICCOUNT_LSB_PTR));
    #endif /* (PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_ReadCapture
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
uint16 PositionCounter_ReadCapture(void) 
{
    #if(PositionCounter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(PositionCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(PositionCounter_STATICCOUNT_LSB_PTR));
    #endif /* (PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_WritePeriod
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
void PositionCounter_WritePeriod(uint16 period) 
{
    #if(PositionCounter_UsingFixedFunction)
        CY_SET_REG16(PositionCounter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(PositionCounter_PERIOD_LSB_PTR, period);
    #endif /* (PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_ReadPeriod
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
uint16 PositionCounter_ReadPeriod(void) 
{
    #if(PositionCounter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(PositionCounter_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(PositionCounter_PERIOD_LSB_PTR));
    #endif /* (PositionCounter_UsingFixedFunction) */
}


#if (!PositionCounter_UsingFixedFunction)
/*******************************************************************************
* Function Name: PositionCounter_WriteCompare
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
void PositionCounter_WriteCompare(uint16 compare) \
                                   
{
    #if(PositionCounter_UsingFixedFunction)
        CY_SET_REG16(PositionCounter_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(PositionCounter_COMPARE_LSB_PTR, compare);
    #endif /* (PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_ReadCompare
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
uint16 PositionCounter_ReadCompare(void) 
{
    return (CY_GET_REG16(PositionCounter_COMPARE_LSB_PTR));
}


#if (PositionCounter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: PositionCounter_SetCompareMode
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
void PositionCounter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    PositionCounter_CONTROL &= ((uint8)(~PositionCounter_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    PositionCounter_CONTROL |= compareMode;
}
#endif  /* (PositionCounter_COMPARE_MODE_SOFTWARE) */


#if (PositionCounter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: PositionCounter_SetCaptureMode
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
void PositionCounter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    PositionCounter_CONTROL &= ((uint8)(~PositionCounter_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    PositionCounter_CONTROL |= ((uint8)((uint8)captureMode << PositionCounter_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (PositionCounter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: PositionCounter_ClearFIFO
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
void PositionCounter_ClearFIFO(void) 
{

    while(0u != (PositionCounter_ReadStatusRegister() & PositionCounter_STATUS_FIFONEMP))
    {
        (void)PositionCounter_ReadCapture();
    }

}
#endif  /* (!PositionCounter_UsingFixedFunction) */


/* [] END OF FILE */

