/*******************************************************************************
* File Name: HB3.h  
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

#if !defined(CY_PINS_HB3_H) /* Pins HB3_H */
#define CY_PINS_HB3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HB3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HB3__PORT == 15 && ((HB3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HB3_Write(uint8 value) ;
void    HB3_SetDriveMode(uint8 mode) ;
uint8   HB3_ReadDataReg(void) ;
uint8   HB3_Read(void) ;
uint8   HB3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HB3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HB3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HB3_DM_RES_UP          PIN_DM_RES_UP
#define HB3_DM_RES_DWN         PIN_DM_RES_DWN
#define HB3_DM_OD_LO           PIN_DM_OD_LO
#define HB3_DM_OD_HI           PIN_DM_OD_HI
#define HB3_DM_STRONG          PIN_DM_STRONG
#define HB3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HB3_MASK               HB3__MASK
#define HB3_SHIFT              HB3__SHIFT
#define HB3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HB3_PS                     (* (reg8 *) HB3__PS)
/* Data Register */
#define HB3_DR                     (* (reg8 *) HB3__DR)
/* Port Number */
#define HB3_PRT_NUM                (* (reg8 *) HB3__PRT) 
/* Connect to Analog Globals */                                                  
#define HB3_AG                     (* (reg8 *) HB3__AG)                       
/* Analog MUX bux enable */
#define HB3_AMUX                   (* (reg8 *) HB3__AMUX) 
/* Bidirectional Enable */                                                        
#define HB3_BIE                    (* (reg8 *) HB3__BIE)
/* Bit-mask for Aliased Register Access */
#define HB3_BIT_MASK               (* (reg8 *) HB3__BIT_MASK)
/* Bypass Enable */
#define HB3_BYP                    (* (reg8 *) HB3__BYP)
/* Port wide control signals */                                                   
#define HB3_CTL                    (* (reg8 *) HB3__CTL)
/* Drive Modes */
#define HB3_DM0                    (* (reg8 *) HB3__DM0) 
#define HB3_DM1                    (* (reg8 *) HB3__DM1)
#define HB3_DM2                    (* (reg8 *) HB3__DM2) 
/* Input Buffer Disable Override */
#define HB3_INP_DIS                (* (reg8 *) HB3__INP_DIS)
/* LCD Common or Segment Drive */
#define HB3_LCD_COM_SEG            (* (reg8 *) HB3__LCD_COM_SEG)
/* Enable Segment LCD */
#define HB3_LCD_EN                 (* (reg8 *) HB3__LCD_EN)
/* Slew Rate Control */
#define HB3_SLW                    (* (reg8 *) HB3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HB3_PRTDSI__CAPS_SEL       (* (reg8 *) HB3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HB3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HB3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HB3_PRTDSI__OE_SEL0        (* (reg8 *) HB3__PRTDSI__OE_SEL0) 
#define HB3_PRTDSI__OE_SEL1        (* (reg8 *) HB3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HB3_PRTDSI__OUT_SEL0       (* (reg8 *) HB3__PRTDSI__OUT_SEL0) 
#define HB3_PRTDSI__OUT_SEL1       (* (reg8 *) HB3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HB3_PRTDSI__SYNC_OUT       (* (reg8 *) HB3__PRTDSI__SYNC_OUT) 


#if defined(HB3__INTSTAT)  /* Interrupt Registers */

    #define HB3_INTSTAT                (* (reg8 *) HB3__INTSTAT)
    #define HB3_SNAP                   (* (reg8 *) HB3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HB3_H */


/* [] END OF FILE */
