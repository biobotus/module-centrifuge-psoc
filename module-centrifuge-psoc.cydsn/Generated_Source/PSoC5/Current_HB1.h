/*******************************************************************************
* File Name: Current_HB1.h  
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

#if !defined(CY_PINS_Current_HB1_H) /* Pins Current_HB1_H */
#define CY_PINS_Current_HB1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Current_HB1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Current_HB1__PORT == 15 && ((Current_HB1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Current_HB1_Write(uint8 value) ;
void    Current_HB1_SetDriveMode(uint8 mode) ;
uint8   Current_HB1_ReadDataReg(void) ;
uint8   Current_HB1_Read(void) ;
uint8   Current_HB1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Current_HB1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Current_HB1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Current_HB1_DM_RES_UP          PIN_DM_RES_UP
#define Current_HB1_DM_RES_DWN         PIN_DM_RES_DWN
#define Current_HB1_DM_OD_LO           PIN_DM_OD_LO
#define Current_HB1_DM_OD_HI           PIN_DM_OD_HI
#define Current_HB1_DM_STRONG          PIN_DM_STRONG
#define Current_HB1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Current_HB1_MASK               Current_HB1__MASK
#define Current_HB1_SHIFT              Current_HB1__SHIFT
#define Current_HB1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Current_HB1_PS                     (* (reg8 *) Current_HB1__PS)
/* Data Register */
#define Current_HB1_DR                     (* (reg8 *) Current_HB1__DR)
/* Port Number */
#define Current_HB1_PRT_NUM                (* (reg8 *) Current_HB1__PRT) 
/* Connect to Analog Globals */                                                  
#define Current_HB1_AG                     (* (reg8 *) Current_HB1__AG)                       
/* Analog MUX bux enable */
#define Current_HB1_AMUX                   (* (reg8 *) Current_HB1__AMUX) 
/* Bidirectional Enable */                                                        
#define Current_HB1_BIE                    (* (reg8 *) Current_HB1__BIE)
/* Bit-mask for Aliased Register Access */
#define Current_HB1_BIT_MASK               (* (reg8 *) Current_HB1__BIT_MASK)
/* Bypass Enable */
#define Current_HB1_BYP                    (* (reg8 *) Current_HB1__BYP)
/* Port wide control signals */                                                   
#define Current_HB1_CTL                    (* (reg8 *) Current_HB1__CTL)
/* Drive Modes */
#define Current_HB1_DM0                    (* (reg8 *) Current_HB1__DM0) 
#define Current_HB1_DM1                    (* (reg8 *) Current_HB1__DM1)
#define Current_HB1_DM2                    (* (reg8 *) Current_HB1__DM2) 
/* Input Buffer Disable Override */
#define Current_HB1_INP_DIS                (* (reg8 *) Current_HB1__INP_DIS)
/* LCD Common or Segment Drive */
#define Current_HB1_LCD_COM_SEG            (* (reg8 *) Current_HB1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Current_HB1_LCD_EN                 (* (reg8 *) Current_HB1__LCD_EN)
/* Slew Rate Control */
#define Current_HB1_SLW                    (* (reg8 *) Current_HB1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Current_HB1_PRTDSI__CAPS_SEL       (* (reg8 *) Current_HB1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Current_HB1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Current_HB1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Current_HB1_PRTDSI__OE_SEL0        (* (reg8 *) Current_HB1__PRTDSI__OE_SEL0) 
#define Current_HB1_PRTDSI__OE_SEL1        (* (reg8 *) Current_HB1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Current_HB1_PRTDSI__OUT_SEL0       (* (reg8 *) Current_HB1__PRTDSI__OUT_SEL0) 
#define Current_HB1_PRTDSI__OUT_SEL1       (* (reg8 *) Current_HB1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Current_HB1_PRTDSI__SYNC_OUT       (* (reg8 *) Current_HB1__PRTDSI__SYNC_OUT) 


#if defined(Current_HB1__INTSTAT)  /* Interrupt Registers */

    #define Current_HB1_INTSTAT                (* (reg8 *) Current_HB1__INTSTAT)
    #define Current_HB1_SNAP                   (* (reg8 *) Current_HB1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Current_HB1_H */


/* [] END OF FILE */
