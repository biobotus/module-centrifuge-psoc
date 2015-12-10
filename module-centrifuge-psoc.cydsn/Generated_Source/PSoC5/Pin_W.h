/*******************************************************************************
* File Name: Pin_W.h  
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

#if !defined(CY_PINS_Pin_W_H) /* Pins Pin_W_H */
#define CY_PINS_Pin_W_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_W_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_W__PORT == 15 && ((Pin_W__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_W_Write(uint8 value) ;
void    Pin_W_SetDriveMode(uint8 mode) ;
uint8   Pin_W_ReadDataReg(void) ;
uint8   Pin_W_Read(void) ;
uint8   Pin_W_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_W_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_W_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_W_DM_RES_UP          PIN_DM_RES_UP
#define Pin_W_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_W_DM_OD_LO           PIN_DM_OD_LO
#define Pin_W_DM_OD_HI           PIN_DM_OD_HI
#define Pin_W_DM_STRONG          PIN_DM_STRONG
#define Pin_W_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_W_MASK               Pin_W__MASK
#define Pin_W_SHIFT              Pin_W__SHIFT
#define Pin_W_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_W_PS                     (* (reg8 *) Pin_W__PS)
/* Data Register */
#define Pin_W_DR                     (* (reg8 *) Pin_W__DR)
/* Port Number */
#define Pin_W_PRT_NUM                (* (reg8 *) Pin_W__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_W_AG                     (* (reg8 *) Pin_W__AG)                       
/* Analog MUX bux enable */
#define Pin_W_AMUX                   (* (reg8 *) Pin_W__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_W_BIE                    (* (reg8 *) Pin_W__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_W_BIT_MASK               (* (reg8 *) Pin_W__BIT_MASK)
/* Bypass Enable */
#define Pin_W_BYP                    (* (reg8 *) Pin_W__BYP)
/* Port wide control signals */                                                   
#define Pin_W_CTL                    (* (reg8 *) Pin_W__CTL)
/* Drive Modes */
#define Pin_W_DM0                    (* (reg8 *) Pin_W__DM0) 
#define Pin_W_DM1                    (* (reg8 *) Pin_W__DM1)
#define Pin_W_DM2                    (* (reg8 *) Pin_W__DM2) 
/* Input Buffer Disable Override */
#define Pin_W_INP_DIS                (* (reg8 *) Pin_W__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_W_LCD_COM_SEG            (* (reg8 *) Pin_W__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_W_LCD_EN                 (* (reg8 *) Pin_W__LCD_EN)
/* Slew Rate Control */
#define Pin_W_SLW                    (* (reg8 *) Pin_W__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_W_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_W__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_W_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_W__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_W_PRTDSI__OE_SEL0        (* (reg8 *) Pin_W__PRTDSI__OE_SEL0) 
#define Pin_W_PRTDSI__OE_SEL1        (* (reg8 *) Pin_W__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_W_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_W__PRTDSI__OUT_SEL0) 
#define Pin_W_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_W__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_W_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_W__PRTDSI__SYNC_OUT) 


#if defined(Pin_W__INTSTAT)  /* Interrupt Registers */

    #define Pin_W_INTSTAT                (* (reg8 *) Pin_W__INTSTAT)
    #define Pin_W_SNAP                   (* (reg8 *) Pin_W__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_W_H */


/* [] END OF FILE */
