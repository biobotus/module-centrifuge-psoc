/*******************************************************************************
* File Name: CAN_BY.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CAN_BY_H) /* Pins CAN_BY_H */
#define CY_PINS_CAN_BY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CAN_BY_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CAN_BY__PORT == 15 && ((CAN_BY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CAN_BY_Write(uint8 value) ;
void    CAN_BY_SetDriveMode(uint8 mode) ;
uint8   CAN_BY_ReadDataReg(void) ;
uint8   CAN_BY_Read(void) ;
uint8   CAN_BY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CAN_BY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CAN_BY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CAN_BY_DM_RES_UP          PIN_DM_RES_UP
#define CAN_BY_DM_RES_DWN         PIN_DM_RES_DWN
#define CAN_BY_DM_OD_LO           PIN_DM_OD_LO
#define CAN_BY_DM_OD_HI           PIN_DM_OD_HI
#define CAN_BY_DM_STRONG          PIN_DM_STRONG
#define CAN_BY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CAN_BY_MASK               CAN_BY__MASK
#define CAN_BY_SHIFT              CAN_BY__SHIFT
#define CAN_BY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CAN_BY_PS                     (* (reg8 *) CAN_BY__PS)
/* Data Register */
#define CAN_BY_DR                     (* (reg8 *) CAN_BY__DR)
/* Port Number */
#define CAN_BY_PRT_NUM                (* (reg8 *) CAN_BY__PRT) 
/* Connect to Analog Globals */                                                  
#define CAN_BY_AG                     (* (reg8 *) CAN_BY__AG)                       
/* Analog MUX bux enable */
#define CAN_BY_AMUX                   (* (reg8 *) CAN_BY__AMUX) 
/* Bidirectional Enable */                                                        
#define CAN_BY_BIE                    (* (reg8 *) CAN_BY__BIE)
/* Bit-mask for Aliased Register Access */
#define CAN_BY_BIT_MASK               (* (reg8 *) CAN_BY__BIT_MASK)
/* Bypass Enable */
#define CAN_BY_BYP                    (* (reg8 *) CAN_BY__BYP)
/* Port wide control signals */                                                   
#define CAN_BY_CTL                    (* (reg8 *) CAN_BY__CTL)
/* Drive Modes */
#define CAN_BY_DM0                    (* (reg8 *) CAN_BY__DM0) 
#define CAN_BY_DM1                    (* (reg8 *) CAN_BY__DM1)
#define CAN_BY_DM2                    (* (reg8 *) CAN_BY__DM2) 
/* Input Buffer Disable Override */
#define CAN_BY_INP_DIS                (* (reg8 *) CAN_BY__INP_DIS)
/* LCD Common or Segment Drive */
#define CAN_BY_LCD_COM_SEG            (* (reg8 *) CAN_BY__LCD_COM_SEG)
/* Enable Segment LCD */
#define CAN_BY_LCD_EN                 (* (reg8 *) CAN_BY__LCD_EN)
/* Slew Rate Control */
#define CAN_BY_SLW                    (* (reg8 *) CAN_BY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CAN_BY_PRTDSI__CAPS_SEL       (* (reg8 *) CAN_BY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CAN_BY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CAN_BY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CAN_BY_PRTDSI__OE_SEL0        (* (reg8 *) CAN_BY__PRTDSI__OE_SEL0) 
#define CAN_BY_PRTDSI__OE_SEL1        (* (reg8 *) CAN_BY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CAN_BY_PRTDSI__OUT_SEL0       (* (reg8 *) CAN_BY__PRTDSI__OUT_SEL0) 
#define CAN_BY_PRTDSI__OUT_SEL1       (* (reg8 *) CAN_BY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CAN_BY_PRTDSI__SYNC_OUT       (* (reg8 *) CAN_BY__PRTDSI__SYNC_OUT) 


#if defined(CAN_BY__INTSTAT)  /* Interrupt Registers */

    #define CAN_BY_INTSTAT                (* (reg8 *) CAN_BY__INTSTAT)
    #define CAN_BY_SNAP                   (* (reg8 *) CAN_BY__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CAN_BY_H */


/* [] END OF FILE */
