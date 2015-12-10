/*******************************************************************************
* File Name: PhaseControl_PM.c
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

#include "PhaseControl.h"

/* Check for removal by optimization */
#if !defined(PhaseControl_Sync_ctrl_reg__REMOVED)

static PhaseControl_BACKUP_STRUCT  PhaseControl_backup = {0u};

    
/*******************************************************************************
* Function Name: PhaseControl_SaveConfig
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
void PhaseControl_SaveConfig(void) 
{
    PhaseControl_backup.controlState = PhaseControl_Control;
}


/*******************************************************************************
* Function Name: PhaseControl_RestoreConfig
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
void PhaseControl_RestoreConfig(void) 
{
     PhaseControl_Control = PhaseControl_backup.controlState;
}


/*******************************************************************************
* Function Name: PhaseControl_Sleep
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
void PhaseControl_Sleep(void) 
{
    PhaseControl_SaveConfig();
}


/*******************************************************************************
* Function Name: PhaseControl_Wakeup
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
void PhaseControl_Wakeup(void)  
{
    PhaseControl_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
