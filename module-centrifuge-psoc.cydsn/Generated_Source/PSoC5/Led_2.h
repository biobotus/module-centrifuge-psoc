/*******************************************************************************
* File Name: Led_2.h  
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

#if !defined(CY_PINS_Led_2_H) /* Pins Led_2_H */
#define CY_PINS_Led_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Led_2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Led_2__PORT == 15 && ((Led_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Led_2_Write(uint8 value) ;
void    Led_2_SetDriveMode(uint8 mode) ;
uint8   Led_2_ReadDataReg(void) ;
uint8   Led_2_Read(void) ;
uint8   Led_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Led_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Led_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Led_2_DM_RES_UP          PIN_DM_RES_UP
#define Led_2_DM_RES_DWN         PIN_DM_RES_DWN
#define Led_2_DM_OD_LO           PIN_DM_OD_LO
#define Led_2_DM_OD_HI           PIN_DM_OD_HI
#define Led_2_DM_STRONG          PIN_DM_STRONG
#define Led_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Led_2_MASK               Led_2__MASK
#define Led_2_SHIFT              Led_2__SHIFT
#define Led_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Led_2_PS                     (* (reg8 *) Led_2__PS)
/* Data Register */
#define Led_2_DR                     (* (reg8 *) Led_2__DR)
/* Port Number */
#define Led_2_PRT_NUM                (* (reg8 *) Led_2__PRT) 
/* Connect to Analog Globals */                                                  
#define Led_2_AG                     (* (reg8 *) Led_2__AG)                       
/* Analog MUX bux enable */
#define Led_2_AMUX                   (* (reg8 *) Led_2__AMUX) 
/* Bidirectional Enable */                                                        
#define Led_2_BIE                    (* (reg8 *) Led_2__BIE)
/* Bit-mask for Aliased Register Access */
#define Led_2_BIT_MASK               (* (reg8 *) Led_2__BIT_MASK)
/* Bypass Enable */
#define Led_2_BYP                    (* (reg8 *) Led_2__BYP)
/* Port wide control signals */                                                   
#define Led_2_CTL                    (* (reg8 *) Led_2__CTL)
/* Drive Modes */
#define Led_2_DM0                    (* (reg8 *) Led_2__DM0) 
#define Led_2_DM1                    (* (reg8 *) Led_2__DM1)
#define Led_2_DM2                    (* (reg8 *) Led_2__DM2) 
/* Input Buffer Disable Override */
#define Led_2_INP_DIS                (* (reg8 *) Led_2__INP_DIS)
/* LCD Common or Segment Drive */
#define Led_2_LCD_COM_SEG            (* (reg8 *) Led_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Led_2_LCD_EN                 (* (reg8 *) Led_2__LCD_EN)
/* Slew Rate Control */
#define Led_2_SLW                    (* (reg8 *) Led_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Led_2_PRTDSI__CAPS_SEL       (* (reg8 *) Led_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Led_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Led_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Led_2_PRTDSI__OE_SEL0        (* (reg8 *) Led_2__PRTDSI__OE_SEL0) 
#define Led_2_PRTDSI__OE_SEL1        (* (reg8 *) Led_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Led_2_PRTDSI__OUT_SEL0       (* (reg8 *) Led_2__PRTDSI__OUT_SEL0) 
#define Led_2_PRTDSI__OUT_SEL1       (* (reg8 *) Led_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Led_2_PRTDSI__SYNC_OUT       (* (reg8 *) Led_2__PRTDSI__SYNC_OUT) 


#if defined(Led_2__INTSTAT)  /* Interrupt Registers */

    #define Led_2_INTSTAT                (* (reg8 *) Led_2__INTSTAT)
    #define Led_2_SNAP                   (* (reg8 *) Led_2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Led_2_H */


/* [] END OF FILE */
