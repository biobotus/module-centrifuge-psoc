/*******************************************************************************
* File Name: Door_Power_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Door_Power.h"

static Door_Power_backupStruct Door_Power_backup;


/*******************************************************************************
* Function Name: Door_Power_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Door_Power_SaveConfig(void) 
{
    if (!((Door_Power_CR1 & Door_Power_SRC_MASK) == Door_Power_SRC_UDB))
    {
        Door_Power_backup.data_value = Door_Power_Data;
    }
}


/*******************************************************************************
* Function Name: Door_Power_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void Door_Power_RestoreConfig(void) 
{
    if (!((Door_Power_CR1 & Door_Power_SRC_MASK) == Door_Power_SRC_UDB))
    {
        if((Door_Power_Strobe & Door_Power_STRB_MASK) == Door_Power_STRB_EN)
        {
            Door_Power_Strobe &= (uint8)(~Door_Power_STRB_MASK);
            Door_Power_Data = Door_Power_backup.data_value;
            Door_Power_Strobe |= Door_Power_STRB_EN;
        }
        else
        {
            Door_Power_Data = Door_Power_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Door_Power_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  Door_Power_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Door_Power_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Door_Power_ACT_PWR_EN == (Door_Power_PWRMGR & Door_Power_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Door_Power_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Door_Power_backup.enableState = 0u;
    }
    
    Door_Power_Stop();
    Door_Power_SaveConfig();
}


/*******************************************************************************
* Function Name: Door_Power_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Door_Power_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Door_Power_Wakeup(void) 
{
    Door_Power_RestoreConfig();
    
    if(Door_Power_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Door_Power_Enable();

        /* Restore the data register */
        Door_Power_SetValue(Door_Power_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
