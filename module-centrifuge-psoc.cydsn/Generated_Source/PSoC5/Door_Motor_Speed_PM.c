/*******************************************************************************
* File Name: Door_Motor_Speed_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Door_Motor_Speed.h"

static Door_Motor_Speed_backupStruct Door_Motor_Speed_backup;


/*******************************************************************************
* Function Name: Door_Motor_Speed_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Door_Motor_Speed_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Door_Motor_Speed_SaveConfig(void) 
{

    #if(!Door_Motor_Speed_UsingFixedFunction)
        #if(!Door_Motor_Speed_PWMModeIsCenterAligned)
            Door_Motor_Speed_backup.PWMPeriod = Door_Motor_Speed_ReadPeriod();
        #endif /* (!Door_Motor_Speed_PWMModeIsCenterAligned) */
        Door_Motor_Speed_backup.PWMUdb = Door_Motor_Speed_ReadCounter();
        #if (Door_Motor_Speed_UseStatus)
            Door_Motor_Speed_backup.InterruptMaskValue = Door_Motor_Speed_STATUS_MASK;
        #endif /* (Door_Motor_Speed_UseStatus) */

        #if(Door_Motor_Speed_DeadBandMode == Door_Motor_Speed__B_PWM__DBM_256_CLOCKS || \
            Door_Motor_Speed_DeadBandMode == Door_Motor_Speed__B_PWM__DBM_2_4_CLOCKS)
            Door_Motor_Speed_backup.PWMdeadBandValue = Door_Motor_Speed_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Door_Motor_Speed_KillModeMinTime)
             Door_Motor_Speed_backup.PWMKillCounterPeriod = Door_Motor_Speed_ReadKillTime();
        #endif /* (Door_Motor_Speed_KillModeMinTime) */

        #if(Door_Motor_Speed_UseControl)
            Door_Motor_Speed_backup.PWMControlRegister = Door_Motor_Speed_ReadControlRegister();
        #endif /* (Door_Motor_Speed_UseControl) */
    #endif  /* (!Door_Motor_Speed_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Motor_Speed_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Door_Motor_Speed_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Door_Motor_Speed_RestoreConfig(void) 
{
        #if(!Door_Motor_Speed_UsingFixedFunction)
            #if(!Door_Motor_Speed_PWMModeIsCenterAligned)
                Door_Motor_Speed_WritePeriod(Door_Motor_Speed_backup.PWMPeriod);
            #endif /* (!Door_Motor_Speed_PWMModeIsCenterAligned) */

            Door_Motor_Speed_WriteCounter(Door_Motor_Speed_backup.PWMUdb);

            #if (Door_Motor_Speed_UseStatus)
                Door_Motor_Speed_STATUS_MASK = Door_Motor_Speed_backup.InterruptMaskValue;
            #endif /* (Door_Motor_Speed_UseStatus) */

            #if(Door_Motor_Speed_DeadBandMode == Door_Motor_Speed__B_PWM__DBM_256_CLOCKS || \
                Door_Motor_Speed_DeadBandMode == Door_Motor_Speed__B_PWM__DBM_2_4_CLOCKS)
                Door_Motor_Speed_WriteDeadTime(Door_Motor_Speed_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Door_Motor_Speed_KillModeMinTime)
                Door_Motor_Speed_WriteKillTime(Door_Motor_Speed_backup.PWMKillCounterPeriod);
            #endif /* (Door_Motor_Speed_KillModeMinTime) */

            #if(Door_Motor_Speed_UseControl)
                Door_Motor_Speed_WriteControlRegister(Door_Motor_Speed_backup.PWMControlRegister);
            #endif /* (Door_Motor_Speed_UseControl) */
        #endif  /* (!Door_Motor_Speed_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Door_Motor_Speed_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Door_Motor_Speed_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Door_Motor_Speed_Sleep(void) 
{
    #if(Door_Motor_Speed_UseControl)
        if(Door_Motor_Speed_CTRL_ENABLE == (Door_Motor_Speed_CONTROL & Door_Motor_Speed_CTRL_ENABLE))
        {
            /*Component is enabled */
            Door_Motor_Speed_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Door_Motor_Speed_backup.PWMEnableState = 0u;
        }
    #endif /* (Door_Motor_Speed_UseControl) */

    /* Stop component */
    Door_Motor_Speed_Stop();

    /* Save registers configuration */
    Door_Motor_Speed_SaveConfig();
}


/*******************************************************************************
* Function Name: Door_Motor_Speed_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Door_Motor_Speed_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Door_Motor_Speed_Wakeup(void) 
{
     /* Restore registers values */
    Door_Motor_Speed_RestoreConfig();

    if(Door_Motor_Speed_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Door_Motor_Speed_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
