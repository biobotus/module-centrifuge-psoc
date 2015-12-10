/*******************************************************************************
* File Name: PositionCounter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
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

static PositionCounter_backupStruct PositionCounter_backup;


/*******************************************************************************
* Function Name: PositionCounter_SaveConfig
********************************************************************************
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
*  PositionCounter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PositionCounter_SaveConfig(void) 
{
    #if (!PositionCounter_UsingFixedFunction)

        PositionCounter_backup.CounterUdb = PositionCounter_ReadCounter();

        #if(!PositionCounter_ControlRegRemoved)
            PositionCounter_backup.CounterControlRegister = PositionCounter_ReadControlRegister();
        #endif /* (!PositionCounter_ControlRegRemoved) */

    #endif /* (!PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_RestoreConfig
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
*  PositionCounter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PositionCounter_RestoreConfig(void) 
{      
    #if (!PositionCounter_UsingFixedFunction)

       PositionCounter_WriteCounter(PositionCounter_backup.CounterUdb);

        #if(!PositionCounter_ControlRegRemoved)
            PositionCounter_WriteControlRegister(PositionCounter_backup.CounterControlRegister);
        #endif /* (!PositionCounter_ControlRegRemoved) */

    #endif /* (!PositionCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PositionCounter_Sleep
********************************************************************************
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
*  PositionCounter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PositionCounter_Sleep(void) 
{
    #if(!PositionCounter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(PositionCounter_CTRL_ENABLE == (PositionCounter_CONTROL & PositionCounter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            PositionCounter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            PositionCounter_backup.CounterEnableState = 0u;
        }
    #else
        PositionCounter_backup.CounterEnableState = 1u;
        if(PositionCounter_backup.CounterEnableState != 0u)
        {
            PositionCounter_backup.CounterEnableState = 0u;
        }
    #endif /* (!PositionCounter_ControlRegRemoved) */
    
    PositionCounter_Stop();
    PositionCounter_SaveConfig();
}


/*******************************************************************************
* Function Name: PositionCounter_Wakeup
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
*  PositionCounter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PositionCounter_Wakeup(void) 
{
    PositionCounter_RestoreConfig();
    #if(!PositionCounter_ControlRegRemoved)
        if(PositionCounter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            PositionCounter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!PositionCounter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
