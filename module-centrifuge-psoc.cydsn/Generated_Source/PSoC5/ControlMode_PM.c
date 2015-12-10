/*******************************************************************************
* File Name: ControlMode_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ControlMode.h"

/* Check for removal by optimization */
#if !defined(ControlMode_Sync_ctrl_reg__REMOVED)

static ControlMode_BACKUP_STRUCT  ControlMode_backup = {0u};

    
/*******************************************************************************
* Function Name: ControlMode_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlMode_SaveConfig(void) 
{
    ControlMode_backup.controlState = ControlMode_Control;
}


/*******************************************************************************
* Function Name: ControlMode_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void ControlMode_RestoreConfig(void) 
{
     ControlMode_Control = ControlMode_backup.controlState;
}


/*******************************************************************************
* Function Name: ControlMode_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlMode_Sleep(void) 
{
    ControlMode_SaveConfig();
}


/*******************************************************************************
* Function Name: ControlMode_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ControlMode_Wakeup(void)  
{
    ControlMode_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
