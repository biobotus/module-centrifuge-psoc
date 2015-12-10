/*******************************************************************************
* File Name: PositionTimer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "PositionTimer.h"

static PositionTimer_backupStruct PositionTimer_backup;


/*******************************************************************************
* Function Name: PositionTimer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PositionTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PositionTimer_SaveConfig(void) 
{
    #if (!PositionTimer_UsingFixedFunction)
        PositionTimer_backup.TimerUdb = PositionTimer_ReadCounter();
        PositionTimer_backup.InterruptMaskValue = PositionTimer_STATUS_MASK;
        #if (PositionTimer_UsingHWCaptureCounter)
            PositionTimer_backup.TimerCaptureCounter = PositionTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!PositionTimer_UDB_CONTROL_REG_REMOVED)
            PositionTimer_backup.TimerControlRegister = PositionTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: PositionTimer_RestoreConfig
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
* Global variables:
*  PositionTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PositionTimer_RestoreConfig(void) 
{   
    #if (!PositionTimer_UsingFixedFunction)

        PositionTimer_WriteCounter(PositionTimer_backup.TimerUdb);
        PositionTimer_STATUS_MASK =PositionTimer_backup.InterruptMaskValue;
        #if (PositionTimer_UsingHWCaptureCounter)
            PositionTimer_SetCaptureCount(PositionTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!PositionTimer_UDB_CONTROL_REG_REMOVED)
            PositionTimer_WriteControlRegister(PositionTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: PositionTimer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PositionTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void PositionTimer_Sleep(void) 
{
    #if(!PositionTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(PositionTimer_CTRL_ENABLE == (PositionTimer_CONTROL & PositionTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            PositionTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            PositionTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    PositionTimer_Stop();
    PositionTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: PositionTimer_Wakeup
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
*  PositionTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PositionTimer_Wakeup(void) 
{
    PositionTimer_RestoreConfig();
    #if(!PositionTimer_UDB_CONTROL_REG_REMOVED)
        if(PositionTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                PositionTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
