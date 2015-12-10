/*******************************************************************************
* File Name: PWM_HB8.h  
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

#if !defined(CY_PINS_PWM_HB8_H) /* Pins PWM_HB8_H */
#define CY_PINS_PWM_HB8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM_HB8_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWM_HB8__PORT == 15 && ((PWM_HB8__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM_HB8_Write(uint8 value) ;
void    PWM_HB8_SetDriveMode(uint8 mode) ;
uint8   PWM_HB8_ReadDataReg(void) ;
uint8   PWM_HB8_Read(void) ;
uint8   PWM_HB8_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM_HB8_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWM_HB8_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWM_HB8_DM_RES_UP          PIN_DM_RES_UP
#define PWM_HB8_DM_RES_DWN         PIN_DM_RES_DWN
#define PWM_HB8_DM_OD_LO           PIN_DM_OD_LO
#define PWM_HB8_DM_OD_HI           PIN_DM_OD_HI
#define PWM_HB8_DM_STRONG          PIN_DM_STRONG
#define PWM_HB8_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWM_HB8_MASK               PWM_HB8__MASK
#define PWM_HB8_SHIFT              PWM_HB8__SHIFT
#define PWM_HB8_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM_HB8_PS                     (* (reg8 *) PWM_HB8__PS)
/* Data Register */
#define PWM_HB8_DR                     (* (reg8 *) PWM_HB8__DR)
/* Port Number */
#define PWM_HB8_PRT_NUM                (* (reg8 *) PWM_HB8__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM_HB8_AG                     (* (reg8 *) PWM_HB8__AG)                       
/* Analog MUX bux enable */
#define PWM_HB8_AMUX                   (* (reg8 *) PWM_HB8__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM_HB8_BIE                    (* (reg8 *) PWM_HB8__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM_HB8_BIT_MASK               (* (reg8 *) PWM_HB8__BIT_MASK)
/* Bypass Enable */
#define PWM_HB8_BYP                    (* (reg8 *) PWM_HB8__BYP)
/* Port wide control signals */                                                   
#define PWM_HB8_CTL                    (* (reg8 *) PWM_HB8__CTL)
/* Drive Modes */
#define PWM_HB8_DM0                    (* (reg8 *) PWM_HB8__DM0) 
#define PWM_HB8_DM1                    (* (reg8 *) PWM_HB8__DM1)
#define PWM_HB8_DM2                    (* (reg8 *) PWM_HB8__DM2) 
/* Input Buffer Disable Override */
#define PWM_HB8_INP_DIS                (* (reg8 *) PWM_HB8__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM_HB8_LCD_COM_SEG            (* (reg8 *) PWM_HB8__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM_HB8_LCD_EN                 (* (reg8 *) PWM_HB8__LCD_EN)
/* Slew Rate Control */
#define PWM_HB8_SLW                    (* (reg8 *) PWM_HB8__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM_HB8_PRTDSI__CAPS_SEL       (* (reg8 *) PWM_HB8__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM_HB8_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM_HB8__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM_HB8_PRTDSI__OE_SEL0        (* (reg8 *) PWM_HB8__PRTDSI__OE_SEL0) 
#define PWM_HB8_PRTDSI__OE_SEL1        (* (reg8 *) PWM_HB8__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM_HB8_PRTDSI__OUT_SEL0       (* (reg8 *) PWM_HB8__PRTDSI__OUT_SEL0) 
#define PWM_HB8_PRTDSI__OUT_SEL1       (* (reg8 *) PWM_HB8__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM_HB8_PRTDSI__SYNC_OUT       (* (reg8 *) PWM_HB8__PRTDSI__SYNC_OUT) 


#if defined(PWM_HB8__INTSTAT)  /* Interrupt Registers */

    #define PWM_HB8_INTSTAT                (* (reg8 *) PWM_HB8__INTSTAT)
    #define PWM_HB8_SNAP                   (* (reg8 *) PWM_HB8__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWM_HB8_H */


/* [] END OF FILE */
