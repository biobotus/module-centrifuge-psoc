/*******************************************************************************
* File Name: RotarySensor_U.h  
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

#if !defined(CY_PINS_RotarySensor_U_H) /* Pins RotarySensor_U_H */
#define CY_PINS_RotarySensor_U_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RotarySensor_U_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RotarySensor_U__PORT == 15 && ((RotarySensor_U__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RotarySensor_U_Write(uint8 value) ;
void    RotarySensor_U_SetDriveMode(uint8 mode) ;
uint8   RotarySensor_U_ReadDataReg(void) ;
uint8   RotarySensor_U_Read(void) ;
uint8   RotarySensor_U_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RotarySensor_U_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RotarySensor_U_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RotarySensor_U_DM_RES_UP          PIN_DM_RES_UP
#define RotarySensor_U_DM_RES_DWN         PIN_DM_RES_DWN
#define RotarySensor_U_DM_OD_LO           PIN_DM_OD_LO
#define RotarySensor_U_DM_OD_HI           PIN_DM_OD_HI
#define RotarySensor_U_DM_STRONG          PIN_DM_STRONG
#define RotarySensor_U_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RotarySensor_U_MASK               RotarySensor_U__MASK
#define RotarySensor_U_SHIFT              RotarySensor_U__SHIFT
#define RotarySensor_U_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RotarySensor_U_PS                     (* (reg8 *) RotarySensor_U__PS)
/* Data Register */
#define RotarySensor_U_DR                     (* (reg8 *) RotarySensor_U__DR)
/* Port Number */
#define RotarySensor_U_PRT_NUM                (* (reg8 *) RotarySensor_U__PRT) 
/* Connect to Analog Globals */                                                  
#define RotarySensor_U_AG                     (* (reg8 *) RotarySensor_U__AG)                       
/* Analog MUX bux enable */
#define RotarySensor_U_AMUX                   (* (reg8 *) RotarySensor_U__AMUX) 
/* Bidirectional Enable */                                                        
#define RotarySensor_U_BIE                    (* (reg8 *) RotarySensor_U__BIE)
/* Bit-mask for Aliased Register Access */
#define RotarySensor_U_BIT_MASK               (* (reg8 *) RotarySensor_U__BIT_MASK)
/* Bypass Enable */
#define RotarySensor_U_BYP                    (* (reg8 *) RotarySensor_U__BYP)
/* Port wide control signals */                                                   
#define RotarySensor_U_CTL                    (* (reg8 *) RotarySensor_U__CTL)
/* Drive Modes */
#define RotarySensor_U_DM0                    (* (reg8 *) RotarySensor_U__DM0) 
#define RotarySensor_U_DM1                    (* (reg8 *) RotarySensor_U__DM1)
#define RotarySensor_U_DM2                    (* (reg8 *) RotarySensor_U__DM2) 
/* Input Buffer Disable Override */
#define RotarySensor_U_INP_DIS                (* (reg8 *) RotarySensor_U__INP_DIS)
/* LCD Common or Segment Drive */
#define RotarySensor_U_LCD_COM_SEG            (* (reg8 *) RotarySensor_U__LCD_COM_SEG)
/* Enable Segment LCD */
#define RotarySensor_U_LCD_EN                 (* (reg8 *) RotarySensor_U__LCD_EN)
/* Slew Rate Control */
#define RotarySensor_U_SLW                    (* (reg8 *) RotarySensor_U__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RotarySensor_U_PRTDSI__CAPS_SEL       (* (reg8 *) RotarySensor_U__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RotarySensor_U_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RotarySensor_U__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RotarySensor_U_PRTDSI__OE_SEL0        (* (reg8 *) RotarySensor_U__PRTDSI__OE_SEL0) 
#define RotarySensor_U_PRTDSI__OE_SEL1        (* (reg8 *) RotarySensor_U__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RotarySensor_U_PRTDSI__OUT_SEL0       (* (reg8 *) RotarySensor_U__PRTDSI__OUT_SEL0) 
#define RotarySensor_U_PRTDSI__OUT_SEL1       (* (reg8 *) RotarySensor_U__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RotarySensor_U_PRTDSI__SYNC_OUT       (* (reg8 *) RotarySensor_U__PRTDSI__SYNC_OUT) 


#if defined(RotarySensor_U__INTSTAT)  /* Interrupt Registers */

    #define RotarySensor_U_INTSTAT                (* (reg8 *) RotarySensor_U__INTSTAT)
    #define RotarySensor_U_SNAP                   (* (reg8 *) RotarySensor_U__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RotarySensor_U_H */


/* [] END OF FILE */
