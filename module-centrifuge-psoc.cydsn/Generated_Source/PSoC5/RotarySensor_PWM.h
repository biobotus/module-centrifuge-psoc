/*******************************************************************************
* File Name: RotarySensor_PWM.h  
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

#if !defined(CY_PINS_RotarySensor_PWM_H) /* Pins RotarySensor_PWM_H */
#define CY_PINS_RotarySensor_PWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RotarySensor_PWM_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RotarySensor_PWM__PORT == 15 && ((RotarySensor_PWM__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RotarySensor_PWM_Write(uint8 value) ;
void    RotarySensor_PWM_SetDriveMode(uint8 mode) ;
uint8   RotarySensor_PWM_ReadDataReg(void) ;
uint8   RotarySensor_PWM_Read(void) ;
uint8   RotarySensor_PWM_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RotarySensor_PWM_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RotarySensor_PWM_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RotarySensor_PWM_DM_RES_UP          PIN_DM_RES_UP
#define RotarySensor_PWM_DM_RES_DWN         PIN_DM_RES_DWN
#define RotarySensor_PWM_DM_OD_LO           PIN_DM_OD_LO
#define RotarySensor_PWM_DM_OD_HI           PIN_DM_OD_HI
#define RotarySensor_PWM_DM_STRONG          PIN_DM_STRONG
#define RotarySensor_PWM_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RotarySensor_PWM_MASK               RotarySensor_PWM__MASK
#define RotarySensor_PWM_SHIFT              RotarySensor_PWM__SHIFT
#define RotarySensor_PWM_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RotarySensor_PWM_PS                     (* (reg8 *) RotarySensor_PWM__PS)
/* Data Register */
#define RotarySensor_PWM_DR                     (* (reg8 *) RotarySensor_PWM__DR)
/* Port Number */
#define RotarySensor_PWM_PRT_NUM                (* (reg8 *) RotarySensor_PWM__PRT) 
/* Connect to Analog Globals */                                                  
#define RotarySensor_PWM_AG                     (* (reg8 *) RotarySensor_PWM__AG)                       
/* Analog MUX bux enable */
#define RotarySensor_PWM_AMUX                   (* (reg8 *) RotarySensor_PWM__AMUX) 
/* Bidirectional Enable */                                                        
#define RotarySensor_PWM_BIE                    (* (reg8 *) RotarySensor_PWM__BIE)
/* Bit-mask for Aliased Register Access */
#define RotarySensor_PWM_BIT_MASK               (* (reg8 *) RotarySensor_PWM__BIT_MASK)
/* Bypass Enable */
#define RotarySensor_PWM_BYP                    (* (reg8 *) RotarySensor_PWM__BYP)
/* Port wide control signals */                                                   
#define RotarySensor_PWM_CTL                    (* (reg8 *) RotarySensor_PWM__CTL)
/* Drive Modes */
#define RotarySensor_PWM_DM0                    (* (reg8 *) RotarySensor_PWM__DM0) 
#define RotarySensor_PWM_DM1                    (* (reg8 *) RotarySensor_PWM__DM1)
#define RotarySensor_PWM_DM2                    (* (reg8 *) RotarySensor_PWM__DM2) 
/* Input Buffer Disable Override */
#define RotarySensor_PWM_INP_DIS                (* (reg8 *) RotarySensor_PWM__INP_DIS)
/* LCD Common or Segment Drive */
#define RotarySensor_PWM_LCD_COM_SEG            (* (reg8 *) RotarySensor_PWM__LCD_COM_SEG)
/* Enable Segment LCD */
#define RotarySensor_PWM_LCD_EN                 (* (reg8 *) RotarySensor_PWM__LCD_EN)
/* Slew Rate Control */
#define RotarySensor_PWM_SLW                    (* (reg8 *) RotarySensor_PWM__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RotarySensor_PWM_PRTDSI__CAPS_SEL       (* (reg8 *) RotarySensor_PWM__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RotarySensor_PWM_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RotarySensor_PWM__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RotarySensor_PWM_PRTDSI__OE_SEL0        (* (reg8 *) RotarySensor_PWM__PRTDSI__OE_SEL0) 
#define RotarySensor_PWM_PRTDSI__OE_SEL1        (* (reg8 *) RotarySensor_PWM__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RotarySensor_PWM_PRTDSI__OUT_SEL0       (* (reg8 *) RotarySensor_PWM__PRTDSI__OUT_SEL0) 
#define RotarySensor_PWM_PRTDSI__OUT_SEL1       (* (reg8 *) RotarySensor_PWM__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RotarySensor_PWM_PRTDSI__SYNC_OUT       (* (reg8 *) RotarySensor_PWM__PRTDSI__SYNC_OUT) 


#if defined(RotarySensor_PWM__INTSTAT)  /* Interrupt Registers */

    #define RotarySensor_PWM_INTSTAT                (* (reg8 *) RotarySensor_PWM__INTSTAT)
    #define RotarySensor_PWM_SNAP                   (* (reg8 *) RotarySensor_PWM__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RotarySensor_PWM_H */


/* [] END OF FILE */
