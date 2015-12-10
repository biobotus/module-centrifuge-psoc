/*******************************************************************************
* File Name: RotarySensor_Ncc.h  
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

#if !defined(CY_PINS_RotarySensor_Ncc_H) /* Pins RotarySensor_Ncc_H */
#define CY_PINS_RotarySensor_Ncc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RotarySensor_Ncc_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RotarySensor_Ncc__PORT == 15 && ((RotarySensor_Ncc__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RotarySensor_Ncc_Write(uint8 value) ;
void    RotarySensor_Ncc_SetDriveMode(uint8 mode) ;
uint8   RotarySensor_Ncc_ReadDataReg(void) ;
uint8   RotarySensor_Ncc_Read(void) ;
uint8   RotarySensor_Ncc_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RotarySensor_Ncc_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RotarySensor_Ncc_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RotarySensor_Ncc_DM_RES_UP          PIN_DM_RES_UP
#define RotarySensor_Ncc_DM_RES_DWN         PIN_DM_RES_DWN
#define RotarySensor_Ncc_DM_OD_LO           PIN_DM_OD_LO
#define RotarySensor_Ncc_DM_OD_HI           PIN_DM_OD_HI
#define RotarySensor_Ncc_DM_STRONG          PIN_DM_STRONG
#define RotarySensor_Ncc_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RotarySensor_Ncc_MASK               RotarySensor_Ncc__MASK
#define RotarySensor_Ncc_SHIFT              RotarySensor_Ncc__SHIFT
#define RotarySensor_Ncc_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RotarySensor_Ncc_PS                     (* (reg8 *) RotarySensor_Ncc__PS)
/* Data Register */
#define RotarySensor_Ncc_DR                     (* (reg8 *) RotarySensor_Ncc__DR)
/* Port Number */
#define RotarySensor_Ncc_PRT_NUM                (* (reg8 *) RotarySensor_Ncc__PRT) 
/* Connect to Analog Globals */                                                  
#define RotarySensor_Ncc_AG                     (* (reg8 *) RotarySensor_Ncc__AG)                       
/* Analog MUX bux enable */
#define RotarySensor_Ncc_AMUX                   (* (reg8 *) RotarySensor_Ncc__AMUX) 
/* Bidirectional Enable */                                                        
#define RotarySensor_Ncc_BIE                    (* (reg8 *) RotarySensor_Ncc__BIE)
/* Bit-mask for Aliased Register Access */
#define RotarySensor_Ncc_BIT_MASK               (* (reg8 *) RotarySensor_Ncc__BIT_MASK)
/* Bypass Enable */
#define RotarySensor_Ncc_BYP                    (* (reg8 *) RotarySensor_Ncc__BYP)
/* Port wide control signals */                                                   
#define RotarySensor_Ncc_CTL                    (* (reg8 *) RotarySensor_Ncc__CTL)
/* Drive Modes */
#define RotarySensor_Ncc_DM0                    (* (reg8 *) RotarySensor_Ncc__DM0) 
#define RotarySensor_Ncc_DM1                    (* (reg8 *) RotarySensor_Ncc__DM1)
#define RotarySensor_Ncc_DM2                    (* (reg8 *) RotarySensor_Ncc__DM2) 
/* Input Buffer Disable Override */
#define RotarySensor_Ncc_INP_DIS                (* (reg8 *) RotarySensor_Ncc__INP_DIS)
/* LCD Common or Segment Drive */
#define RotarySensor_Ncc_LCD_COM_SEG            (* (reg8 *) RotarySensor_Ncc__LCD_COM_SEG)
/* Enable Segment LCD */
#define RotarySensor_Ncc_LCD_EN                 (* (reg8 *) RotarySensor_Ncc__LCD_EN)
/* Slew Rate Control */
#define RotarySensor_Ncc_SLW                    (* (reg8 *) RotarySensor_Ncc__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RotarySensor_Ncc_PRTDSI__CAPS_SEL       (* (reg8 *) RotarySensor_Ncc__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RotarySensor_Ncc_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RotarySensor_Ncc__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RotarySensor_Ncc_PRTDSI__OE_SEL0        (* (reg8 *) RotarySensor_Ncc__PRTDSI__OE_SEL0) 
#define RotarySensor_Ncc_PRTDSI__OE_SEL1        (* (reg8 *) RotarySensor_Ncc__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RotarySensor_Ncc_PRTDSI__OUT_SEL0       (* (reg8 *) RotarySensor_Ncc__PRTDSI__OUT_SEL0) 
#define RotarySensor_Ncc_PRTDSI__OUT_SEL1       (* (reg8 *) RotarySensor_Ncc__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RotarySensor_Ncc_PRTDSI__SYNC_OUT       (* (reg8 *) RotarySensor_Ncc__PRTDSI__SYNC_OUT) 


#if defined(RotarySensor_Ncc__INTSTAT)  /* Interrupt Registers */

    #define RotarySensor_Ncc_INTSTAT                (* (reg8 *) RotarySensor_Ncc__INTSTAT)
    #define RotarySensor_Ncc_SNAP                   (* (reg8 *) RotarySensor_Ncc__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RotarySensor_Ncc_H */


/* [] END OF FILE */
