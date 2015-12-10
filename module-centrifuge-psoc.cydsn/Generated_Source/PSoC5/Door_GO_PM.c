/*******************************************************************************
* File Name: Door_GO_PM.c
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

#include "Door_GO.h"

/* Check for removal by optimization */
#if !defined(Door_GO_Sync_ctrl_reg__REMOVED)

static Door_GO_BACKUP_STRUCT  Door_GO_backup = {0u};

    
/*******************************************************************************
* Function Name: Door_GO_SaveConfig
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
void Door_GO_SaveConfig(void) 
{
    Door_GO_backup.controlState = Door_GO_Control;
}


/*******************************************************************************
* Function Name: Door_GO_RestoreConfig
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
void Door_GO_RestoreConfig(void) 
{
     Door_GO_Control = Door_GO_backup.controlState;
}


/*******************************************************************************
* Function Name: Door_GO_Sleep
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
void Door_GO_Sleep(void) 
{
    Door_GO_SaveConfig();
}


/*******************************************************************************
* Function Name: Door_GO_Wakeup
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
void Door_GO_Wakeup(void)  
{
    Door_GO_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
