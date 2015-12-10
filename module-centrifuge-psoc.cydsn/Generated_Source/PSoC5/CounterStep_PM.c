/*******************************************************************************
* File Name: CounterStep_PM.c  
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

#include "CounterStep.h"

static CounterStep_backupStruct CounterStep_backup;


/*******************************************************************************
* Function Name: CounterStep_SaveConfig
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
*  CounterStep_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void CounterStep_SaveConfig(void) 
{
    #if (!CounterStep_UsingFixedFunction)

        CounterStep_backup.CounterUdb = CounterStep_ReadCounter();

        #if(!CounterStep_ControlRegRemoved)
            CounterStep_backup.CounterControlRegister = CounterStep_ReadControlRegister();
        #endif /* (!CounterStep_ControlRegRemoved) */

    #endif /* (!CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_RestoreConfig
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
*  CounterStep_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CounterStep_RestoreConfig(void) 
{      
    #if (!CounterStep_UsingFixedFunction)

       CounterStep_WriteCounter(CounterStep_backup.CounterUdb);

        #if(!CounterStep_ControlRegRemoved)
            CounterStep_WriteControlRegister(CounterStep_backup.CounterControlRegister);
        #endif /* (!CounterStep_ControlRegRemoved) */

    #endif /* (!CounterStep_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CounterStep_Sleep
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
*  CounterStep_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void CounterStep_Sleep(void) 
{
    #if(!CounterStep_ControlRegRemoved)
        /* Save Counter's enable state */
        if(CounterStep_CTRL_ENABLE == (CounterStep_CONTROL & CounterStep_CTRL_ENABLE))
        {
            /* Counter is enabled */
            CounterStep_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            CounterStep_backup.CounterEnableState = 0u;
        }
    #else
        CounterStep_backup.CounterEnableState = 1u;
        if(CounterStep_backup.CounterEnableState != 0u)
        {
            CounterStep_backup.CounterEnableState = 0u;
        }
    #endif /* (!CounterStep_ControlRegRemoved) */
    
    CounterStep_Stop();
    CounterStep_SaveConfig();
}


/*******************************************************************************
* Function Name: CounterStep_Wakeup
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
*  CounterStep_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CounterStep_Wakeup(void) 
{
    CounterStep_RestoreConfig();
    #if(!CounterStep_ControlRegRemoved)
        if(CounterStep_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            CounterStep_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!CounterStep_ControlRegRemoved) */
    
}


/* [] END OF FILE */
