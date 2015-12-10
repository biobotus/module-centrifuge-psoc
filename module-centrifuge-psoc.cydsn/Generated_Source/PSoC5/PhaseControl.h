/*******************************************************************************
* File Name: PhaseControl.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_PhaseControl_H) /* CY_CONTROL_REG_PhaseControl_H */
#define CY_CONTROL_REG_PhaseControl_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} PhaseControl_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    PhaseControl_Write(uint8 control) ;
uint8   PhaseControl_Read(void) ;

void PhaseControl_SaveConfig(void) ;
void PhaseControl_RestoreConfig(void) ;
void PhaseControl_Sleep(void) ; 
void PhaseControl_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define PhaseControl_Control        (* (reg8 *) PhaseControl_Sync_ctrl_reg__CONTROL_REG )
#define PhaseControl_Control_PTR    (  (reg8 *) PhaseControl_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_PhaseControl_H */


/* [] END OF FILE */
