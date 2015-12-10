/*******************************************************************************
* File Name: Door_Power.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Door_Power.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Door_Power_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 Door_Power_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Door_Power_backupStruct Door_Power_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Door_Power_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Door_Power_Init(void) 
{
    Door_Power_CR0 = (Door_Power_MODE_V );

    /* Set default data source */
    #if(Door_Power_DEFAULT_DATA_SRC != 0 )
        Door_Power_CR1 = (Door_Power_DEFAULT_CNTL | Door_Power_DACBUS_ENABLE) ;
    #else
        Door_Power_CR1 = (Door_Power_DEFAULT_CNTL | Door_Power_DACBUS_DISABLE) ;
    #endif /* (Door_Power_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(Door_Power_DEFAULT_STRB != 0)
        Door_Power_Strobe |= Door_Power_STRB_EN ;
    #endif/* (Door_Power_DEFAULT_STRB != 0) */

    /* Set default range */
    Door_Power_SetRange(Door_Power_DEFAULT_RANGE); 

    /* Set default speed */
    Door_Power_SetSpeed(Door_Power_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Door_Power_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Door_Power_Enable(void) 
{
    Door_Power_PWRMGR |= Door_Power_ACT_PWR_EN;
    Door_Power_STBY_PWRMGR |= Door_Power_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Door_Power_restoreVal == 1u) 
        {
             Door_Power_CR0 = Door_Power_backup.data_value;
             Door_Power_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Door_Power_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  Door_Power_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Door_Power_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Door_Power_initVar == 0u)
    { 
        Door_Power_Init();
        Door_Power_initVar = 1u;
    }

    /* Enable power to DAC */
    Door_Power_Enable();

    /* Set default value */
    Door_Power_SetValue(Door_Power_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Door_Power_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Door_Power_Stop(void) 
{
    /* Disble power to DAC */
    Door_Power_PWRMGR &= (uint8)(~Door_Power_ACT_PWR_EN);
    Door_Power_STBY_PWRMGR &= (uint8)(~Door_Power_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Door_Power_backup.data_value = Door_Power_CR0;
        Door_Power_CR0 = Door_Power_CUR_MODE_OUT_OFF;
        Door_Power_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Door_Power_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Door_Power_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Door_Power_CR0 &= (uint8)(~Door_Power_HS_MASK);
    Door_Power_CR0 |=  (speed & Door_Power_HS_MASK);
}


/*******************************************************************************
* Function Name: Door_Power_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Door_Power_SetRange(uint8 range) 
{
    Door_Power_CR0 &= (uint8)(~Door_Power_RANGE_MASK);      /* Clear existing mode */
    Door_Power_CR0 |= (range & Door_Power_RANGE_MASK);      /*  Set Range  */
    Door_Power_DacTrim();
}


/*******************************************************************************
* Function Name: Door_Power_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Door_Power_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 Door_Power_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Door_Power_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Door_Power_Data = value;
        CyExitCriticalSection(Door_Power_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Door_Power_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Door_Power_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((Door_Power_CR0 & Door_Power_RANGE_MASK) >> 2) + Door_Power_TRIM_M7_1V_RNG_OFFSET;
    Door_Power_TR = CY_GET_XTND_REG8((uint8 *)(Door_Power_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
