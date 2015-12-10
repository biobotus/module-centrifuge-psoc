/*******************************************************************************
* File Name: Led_1.h  
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

#if !defined(CY_PINS_Led_1_H) /* Pins Led_1_H */
#define CY_PINS_Led_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Led_1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Led_1__PORT == 15 && ((Led_1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Led_1_Write(uint8 value) ;
void    Led_1_SetDriveMode(uint8 mode) ;
uint8   Led_1_ReadDataReg(void) ;
uint8   Led_1_Read(void) ;
uint8   Led_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Led_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Led_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Led_1_DM_RES_UP          PIN_DM_RES_UP
#define Led_1_DM_RES_DWN         PIN_DM_RES_DWN
#define Led_1_DM_OD_LO           PIN_DM_OD_LO
#define Led_1_DM_OD_HI           PIN_DM_OD_HI
#define Led_1_DM_STRONG          PIN_DM_STRONG
#define Led_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Led_1_MASK               Led_1__MASK
#define Led_1_SHIFT              Led_1__SHIFT
#define Led_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Led_1_PS                     (* (reg8 *) Led_1__PS)
/* Data Register */
#define Led_1_DR                     (* (reg8 *) Led_1__DR)
/* Port Number */
#define Led_1_PRT_NUM                (* (reg8 *) Led_1__PRT) 
/* Connect to Analog Globals */                                                  
#define Led_1_AG                     (* (reg8 *) Led_1__AG)                       
/* Analog MUX bux enable */
#define Led_1_AMUX                   (* (reg8 *) Led_1__AMUX) 
/* Bidirectional Enable */                                                        
#define Led_1_BIE                    (* (reg8 *) Led_1__BIE)
/* Bit-mask for Aliased Register Access */
#define Led_1_BIT_MASK               (* (reg8 *) Led_1__BIT_MASK)
/* Bypass Enable */
#define Led_1_BYP                    (* (reg8 *) Led_1__BYP)
/* Port wide control signals */                                                   
#define Led_1_CTL                    (* (reg8 *) Led_1__CTL)
/* Drive Modes */
#define Led_1_DM0                    (* (reg8 *) Led_1__DM0) 
#define Led_1_DM1                    (* (reg8 *) Led_1__DM1)
#define Led_1_DM2                    (* (reg8 *) Led_1__DM2) 
/* Input Buffer Disable Override */
#define Led_1_INP_DIS                (* (reg8 *) Led_1__INP_DIS)
/* LCD Common or Segment Drive */
#define Led_1_LCD_COM_SEG            (* (reg8 *) Led_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Led_1_LCD_EN                 (* (reg8 *) Led_1__LCD_EN)
/* Slew Rate Control */
#define Led_1_SLW                    (* (reg8 *) Led_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Led_1_PRTDSI__CAPS_SEL       (* (reg8 *) Led_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Led_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Led_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Led_1_PRTDSI__OE_SEL0        (* (reg8 *) Led_1__PRTDSI__OE_SEL0) 
#define Led_1_PRTDSI__OE_SEL1        (* (reg8 *) Led_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Led_1_PRTDSI__OUT_SEL0       (* (reg8 *) Led_1__PRTDSI__OUT_SEL0) 
#define Led_1_PRTDSI__OUT_SEL1       (* (reg8 *) Led_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Led_1_PRTDSI__SYNC_OUT       (* (reg8 *) Led_1__PRTDSI__SYNC_OUT) 


#if defined(Led_1__INTSTAT)  /* Interrupt Registers */

    #define Led_1_INTSTAT                (* (reg8 *) Led_1__INTSTAT)
    #define Led_1_SNAP                   (* (reg8 *) Led_1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Led_1_H */


/* [] END OF FILE */
