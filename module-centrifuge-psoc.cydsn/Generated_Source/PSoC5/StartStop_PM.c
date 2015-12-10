/*******************************************************************************
* File Name: StartStop_PM.c
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

#include "StartStop.h"

/* Check for removal by optimization */
#if !defined(StartStop_Sync_ctrl_reg__REMOVED)

static StartStop_BACKUP_STRUCT  StartStop_backup = {0u};

    
/*******************************************************************************
* Function Name: StartStop_SaveConfig
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
void StartStop_SaveConfig(void) 
{
    StartStop_backup.controlState = StartStop_Control;
}


/*******************************************************************************
* Function Name: StartStop_RestoreConfig
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
void StartStop_RestoreConfig(void) 
{
     StartStop_Control = StartStop_backup.controlState;
}


/*******************************************************************************
* Function Name: StartStop_Sleep
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
void StartStop_Sleep(void) 
{
    StartStop_SaveConfig();
}


/*******************************************************************************
* Function Name: StartStop_Wakeup
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
void StartStop_Wakeup(void)  
{
    StartStop_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
