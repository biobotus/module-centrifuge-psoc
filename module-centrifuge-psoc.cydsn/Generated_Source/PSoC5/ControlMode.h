/*******************************************************************************
* File Name: ControlMode.h  
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

#if !defined(CY_CONTROL_REG_ControlMode_H) /* CY_CONTROL_REG_ControlMode_H */
#define CY_CONTROL_REG_ControlMode_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} ControlMode_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    ControlMode_Write(uint8 control) ;
uint8   ControlMode_Read(void) ;

void ControlMode_SaveConfig(void) ;
void ControlMode_RestoreConfig(void) ;
void ControlMode_Sleep(void) ; 
void ControlMode_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define ControlMode_Control        (* (reg8 *) ControlMode_Sync_ctrl_reg__CONTROL_REG )
#define ControlMode_Control_PTR    (  (reg8 *) ControlMode_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_ControlMode_H */


/* [] END OF FILE */
