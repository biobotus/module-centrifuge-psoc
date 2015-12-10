/*******************************************************************************
* File Name: RotarySensor_Step.h  
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

#if !defined(CY_PINS_RotarySensor_Step_H) /* Pins RotarySensor_Step_H */
#define CY_PINS_RotarySensor_Step_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RotarySensor_Step_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RotarySensor_Step__PORT == 15 && ((RotarySensor_Step__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RotarySensor_Step_Write(uint8 value) ;
void    RotarySensor_Step_SetDriveMode(uint8 mode) ;
uint8   RotarySensor_Step_ReadDataReg(void) ;
uint8   RotarySensor_Step_Read(void) ;
uint8   RotarySensor_Step_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RotarySensor_Step_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RotarySensor_Step_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RotarySensor_Step_DM_RES_UP          PIN_DM_RES_UP
#define RotarySensor_Step_DM_RES_DWN         PIN_DM_RES_DWN
#define RotarySensor_Step_DM_OD_LO           PIN_DM_OD_LO
#define RotarySensor_Step_DM_OD_HI           PIN_DM_OD_HI
#define RotarySensor_Step_DM_STRONG          PIN_DM_STRONG
#define RotarySensor_Step_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RotarySensor_Step_MASK               RotarySensor_Step__MASK
#define RotarySensor_Step_SHIFT              RotarySensor_Step__SHIFT
#define RotarySensor_Step_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RotarySensor_Step_PS                     (* (reg8 *) RotarySensor_Step__PS)
/* Data Register */
#define RotarySensor_Step_DR                     (* (reg8 *) RotarySensor_Step__DR)
/* Port Number */
#define RotarySensor_Step_PRT_NUM                (* (reg8 *) RotarySensor_Step__PRT) 
/* Connect to Analog Globals */                                                  
#define RotarySensor_Step_AG                     (* (reg8 *) RotarySensor_Step__AG)                       
/* Analog MUX bux enable */
#define RotarySensor_Step_AMUX                   (* (reg8 *) RotarySensor_Step__AMUX) 
/* Bidirectional Enable */                                                        
#define RotarySensor_Step_BIE                    (* (reg8 *) RotarySensor_Step__BIE)
/* Bit-mask for Aliased Register Access */
#define RotarySensor_Step_BIT_MASK               (* (reg8 *) RotarySensor_Step__BIT_MASK)
/* Bypass Enable */
#define RotarySensor_Step_BYP                    (* (reg8 *) RotarySensor_Step__BYP)
/* Port wide control signals */                                                   
#define RotarySensor_Step_CTL                    (* (reg8 *) RotarySensor_Step__CTL)
/* Drive Modes */
#define RotarySensor_Step_DM0                    (* (reg8 *) RotarySensor_Step__DM0) 
#define RotarySensor_Step_DM1                    (* (reg8 *) RotarySensor_Step__DM1)
#define RotarySensor_Step_DM2                    (* (reg8 *) RotarySensor_Step__DM2) 
/* Input Buffer Disable Override */
#define RotarySensor_Step_INP_DIS                (* (reg8 *) RotarySensor_Step__INP_DIS)
/* LCD Common or Segment Drive */
#define RotarySensor_Step_LCD_COM_SEG            (* (reg8 *) RotarySensor_Step__LCD_COM_SEG)
/* Enable Segment LCD */
#define RotarySensor_Step_LCD_EN                 (* (reg8 *) RotarySensor_Step__LCD_EN)
/* Slew Rate Control */
#define RotarySensor_Step_SLW                    (* (reg8 *) RotarySensor_Step__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RotarySensor_Step_PRTDSI__CAPS_SEL       (* (reg8 *) RotarySensor_Step__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RotarySensor_Step_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RotarySensor_Step__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RotarySensor_Step_PRTDSI__OE_SEL0        (* (reg8 *) RotarySensor_Step__PRTDSI__OE_SEL0) 
#define RotarySensor_Step_PRTDSI__OE_SEL1        (* (reg8 *) RotarySensor_Step__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RotarySensor_Step_PRTDSI__OUT_SEL0       (* (reg8 *) RotarySensor_Step__PRTDSI__OUT_SEL0) 
#define RotarySensor_Step_PRTDSI__OUT_SEL1       (* (reg8 *) RotarySensor_Step__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RotarySensor_Step_PRTDSI__SYNC_OUT       (* (reg8 *) RotarySensor_Step__PRTDSI__SYNC_OUT) 


#if defined(RotarySensor_Step__INTSTAT)  /* Interrupt Registers */

    #define RotarySensor_Step_INTSTAT                (* (reg8 *) RotarySensor_Step__INTSTAT)
    #define RotarySensor_Step_SNAP                   (* (reg8 *) RotarySensor_Step__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RotarySensor_Step_H */


/* [] END OF FILE */
