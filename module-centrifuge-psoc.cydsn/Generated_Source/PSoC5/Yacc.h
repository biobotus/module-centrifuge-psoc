/*******************************************************************************
* File Name: Yacc.h  
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

#if !defined(CY_PINS_Yacc_H) /* Pins Yacc_H */
#define CY_PINS_Yacc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Yacc_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Yacc__PORT == 15 && ((Yacc__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Yacc_Write(uint8 value) ;
void    Yacc_SetDriveMode(uint8 mode) ;
uint8   Yacc_ReadDataReg(void) ;
uint8   Yacc_Read(void) ;
uint8   Yacc_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Yacc_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Yacc_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Yacc_DM_RES_UP          PIN_DM_RES_UP
#define Yacc_DM_RES_DWN         PIN_DM_RES_DWN
#define Yacc_DM_OD_LO           PIN_DM_OD_LO
#define Yacc_DM_OD_HI           PIN_DM_OD_HI
#define Yacc_DM_STRONG          PIN_DM_STRONG
#define Yacc_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Yacc_MASK               Yacc__MASK
#define Yacc_SHIFT              Yacc__SHIFT
#define Yacc_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Yacc_PS                     (* (reg8 *) Yacc__PS)
/* Data Register */
#define Yacc_DR                     (* (reg8 *) Yacc__DR)
/* Port Number */
#define Yacc_PRT_NUM                (* (reg8 *) Yacc__PRT) 
/* Connect to Analog Globals */                                                  
#define Yacc_AG                     (* (reg8 *) Yacc__AG)                       
/* Analog MUX bux enable */
#define Yacc_AMUX                   (* (reg8 *) Yacc__AMUX) 
/* Bidirectional Enable */                                                        
#define Yacc_BIE                    (* (reg8 *) Yacc__BIE)
/* Bit-mask for Aliased Register Access */
#define Yacc_BIT_MASK               (* (reg8 *) Yacc__BIT_MASK)
/* Bypass Enable */
#define Yacc_BYP                    (* (reg8 *) Yacc__BYP)
/* Port wide control signals */                                                   
#define Yacc_CTL                    (* (reg8 *) Yacc__CTL)
/* Drive Modes */
#define Yacc_DM0                    (* (reg8 *) Yacc__DM0) 
#define Yacc_DM1                    (* (reg8 *) Yacc__DM1)
#define Yacc_DM2                    (* (reg8 *) Yacc__DM2) 
/* Input Buffer Disable Override */
#define Yacc_INP_DIS                (* (reg8 *) Yacc__INP_DIS)
/* LCD Common or Segment Drive */
#define Yacc_LCD_COM_SEG            (* (reg8 *) Yacc__LCD_COM_SEG)
/* Enable Segment LCD */
#define Yacc_LCD_EN                 (* (reg8 *) Yacc__LCD_EN)
/* Slew Rate Control */
#define Yacc_SLW                    (* (reg8 *) Yacc__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Yacc_PRTDSI__CAPS_SEL       (* (reg8 *) Yacc__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Yacc_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Yacc__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Yacc_PRTDSI__OE_SEL0        (* (reg8 *) Yacc__PRTDSI__OE_SEL0) 
#define Yacc_PRTDSI__OE_SEL1        (* (reg8 *) Yacc__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Yacc_PRTDSI__OUT_SEL0       (* (reg8 *) Yacc__PRTDSI__OUT_SEL0) 
#define Yacc_PRTDSI__OUT_SEL1       (* (reg8 *) Yacc__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Yacc_PRTDSI__SYNC_OUT       (* (reg8 *) Yacc__PRTDSI__SYNC_OUT) 


#if defined(Yacc__INTSTAT)  /* Interrupt Registers */

    #define Yacc_INTSTAT                (* (reg8 *) Yacc__INTSTAT)
    #define Yacc_SNAP                   (* (reg8 *) Yacc__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Yacc_H */


/* [] END OF FILE */
