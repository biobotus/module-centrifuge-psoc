/*******************************************************************************
* File Name: Door_Step_Dist_PM.c  
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

#include "Door_Step_Dist.h"

static Door_Step_Dist_backupStruct Door_Step_Dist_backup;


/*******************************************************************************
* Function Name: Door_Step_Dist_SaveConfig
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
*  Door_Step_Dist_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Door_Step_Dist_SaveConfig(void) 
{
    #if (!Door_Step_Dist_UsingFixedFunction)

        Door_Step_Dist_backup.CounterUdb = Door_Step_Dist_ReadCounter();

        #if(!Door_Step_Dist_ControlRegRemoved)
            Door_Step_Dist_backup.CounterControlRegister = Door_Step_Dist_ReadControlRegister();
        #endif /* (!Door_Step_Dist_ControlRegRemoved) */

    #endif /* (!Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_RestoreConfig
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
*  Door_Step_Dist_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Door_Step_Dist_RestoreConfig(void) 
{      
    #if (!Door_Step_Dist_UsingFixedFunction)

       Door_Step_Dist_WriteCounter(Door_Step_Dist_backup.CounterUdb);

        #if(!Door_Step_Dist_ControlRegRemoved)
            Door_Step_Dist_WriteControlRegister(Door_Step_Dist_backup.CounterControlRegister);
        #endif /* (!Door_Step_Dist_ControlRegRemoved) */

    #endif /* (!Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_Sleep
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
*  Door_Step_Dist_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Door_Step_Dist_Sleep(void) 
{
    #if(!Door_Step_Dist_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Door_Step_Dist_CTRL_ENABLE == (Door_Step_Dist_CONTROL & Door_Step_Dist_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Door_Step_Dist_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Door_Step_Dist_backup.CounterEnableState = 0u;
        }
    #else
        Door_Step_Dist_backup.CounterEnableState = 1u;
        if(Door_Step_Dist_backup.CounterEnableState != 0u)
        {
            Door_Step_Dist_backup.CounterEnableState = 0u;
        }
    #endif /* (!Door_Step_Dist_ControlRegRemoved) */
    
    Door_Step_Dist_Stop();
    Door_Step_Dist_SaveConfig();
}


/*******************************************************************************
* Function Name: Door_Step_Dist_Wakeup
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
*  Door_Step_Dist_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Door_Step_Dist_Wakeup(void) 
{
    Door_Step_Dist_RestoreConfig();
    #if(!Door_Step_Dist_ControlRegRemoved)
        if(Door_Step_Dist_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Door_Step_Dist_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Door_Step_Dist_ControlRegRemoved) */
    
}


/* [] END OF FILE */
