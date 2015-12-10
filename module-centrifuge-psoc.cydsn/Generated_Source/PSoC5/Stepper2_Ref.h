/*******************************************************************************
* File Name: Stepper2_Ref.h  
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

#if !defined(CY_PINS_Stepper2_Ref_H) /* Pins Stepper2_Ref_H */
#define CY_PINS_Stepper2_Ref_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Stepper2_Ref_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Stepper2_Ref__PORT == 15 && ((Stepper2_Ref__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Stepper2_Ref_Write(uint8 value) ;
void    Stepper2_Ref_SetDriveMode(uint8 mode) ;
uint8   Stepper2_Ref_ReadDataReg(void) ;
uint8   Stepper2_Ref_Read(void) ;
uint8   Stepper2_Ref_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Stepper2_Ref_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Stepper2_Ref_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Stepper2_Ref_DM_RES_UP          PIN_DM_RES_UP
#define Stepper2_Ref_DM_RES_DWN         PIN_DM_RES_DWN
#define Stepper2_Ref_DM_OD_LO           PIN_DM_OD_LO
#define Stepper2_Ref_DM_OD_HI           PIN_DM_OD_HI
#define Stepper2_Ref_DM_STRONG          PIN_DM_STRONG
#define Stepper2_Ref_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Stepper2_Ref_MASK               Stepper2_Ref__MASK
#define Stepper2_Ref_SHIFT              Stepper2_Ref__SHIFT
#define Stepper2_Ref_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Stepper2_Ref_PS                     (* (reg8 *) Stepper2_Ref__PS)
/* Data Register */
#define Stepper2_Ref_DR                     (* (reg8 *) Stepper2_Ref__DR)
/* Port Number */
#define Stepper2_Ref_PRT_NUM                (* (reg8 *) Stepper2_Ref__PRT) 
/* Connect to Analog Globals */                                                  
#define Stepper2_Ref_AG                     (* (reg8 *) Stepper2_Ref__AG)                       
/* Analog MUX bux enable */
#define Stepper2_Ref_AMUX                   (* (reg8 *) Stepper2_Ref__AMUX) 
/* Bidirectional Enable */                                                        
#define Stepper2_Ref_BIE                    (* (reg8 *) Stepper2_Ref__BIE)
/* Bit-mask for Aliased Register Access */
#define Stepper2_Ref_BIT_MASK               (* (reg8 *) Stepper2_Ref__BIT_MASK)
/* Bypass Enable */
#define Stepper2_Ref_BYP                    (* (reg8 *) Stepper2_Ref__BYP)
/* Port wide control signals */                                                   
#define Stepper2_Ref_CTL                    (* (reg8 *) Stepper2_Ref__CTL)
/* Drive Modes */
#define Stepper2_Ref_DM0                    (* (reg8 *) Stepper2_Ref__DM0) 
#define Stepper2_Ref_DM1                    (* (reg8 *) Stepper2_Ref__DM1)
#define Stepper2_Ref_DM2                    (* (reg8 *) Stepper2_Ref__DM2) 
/* Input Buffer Disable Override */
#define Stepper2_Ref_INP_DIS                (* (reg8 *) Stepper2_Ref__INP_DIS)
/* LCD Common or Segment Drive */
#define Stepper2_Ref_LCD_COM_SEG            (* (reg8 *) Stepper2_Ref__LCD_COM_SEG)
/* Enable Segment LCD */
#define Stepper2_Ref_LCD_EN                 (* (reg8 *) Stepper2_Ref__LCD_EN)
/* Slew Rate Control */
#define Stepper2_Ref_SLW                    (* (reg8 *) Stepper2_Ref__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Stepper2_Ref_PRTDSI__CAPS_SEL       (* (reg8 *) Stepper2_Ref__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Stepper2_Ref_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Stepper2_Ref__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Stepper2_Ref_PRTDSI__OE_SEL0        (* (reg8 *) Stepper2_Ref__PRTDSI__OE_SEL0) 
#define Stepper2_Ref_PRTDSI__OE_SEL1        (* (reg8 *) Stepper2_Ref__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Stepper2_Ref_PRTDSI__OUT_SEL0       (* (reg8 *) Stepper2_Ref__PRTDSI__OUT_SEL0) 
#define Stepper2_Ref_PRTDSI__OUT_SEL1       (* (reg8 *) Stepper2_Ref__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Stepper2_Ref_PRTDSI__SYNC_OUT       (* (reg8 *) Stepper2_Ref__PRTDSI__SYNC_OUT) 


#if defined(Stepper2_Ref__INTSTAT)  /* Interrupt Registers */

    #define Stepper2_Ref_INTSTAT                (* (reg8 *) Stepper2_Ref__INTSTAT)
    #define Stepper2_Ref_SNAP                   (* (reg8 *) Stepper2_Ref__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Stepper2_Ref_H */


/* [] END OF FILE */
