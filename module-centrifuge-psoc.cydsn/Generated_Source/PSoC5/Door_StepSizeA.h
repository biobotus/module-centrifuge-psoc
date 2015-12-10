/*******************************************************************************
* File Name: Door_StepSizeA.h  
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

#if !defined(CY_PINS_Door_StepSizeA_H) /* Pins Door_StepSizeA_H */
#define CY_PINS_Door_StepSizeA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Door_StepSizeA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Door_StepSizeA__PORT == 15 && ((Door_StepSizeA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Door_StepSizeA_Write(uint8 value) ;
void    Door_StepSizeA_SetDriveMode(uint8 mode) ;
uint8   Door_StepSizeA_ReadDataReg(void) ;
uint8   Door_StepSizeA_Read(void) ;
uint8   Door_StepSizeA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Door_StepSizeA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Door_StepSizeA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Door_StepSizeA_DM_RES_UP          PIN_DM_RES_UP
#define Door_StepSizeA_DM_RES_DWN         PIN_DM_RES_DWN
#define Door_StepSizeA_DM_OD_LO           PIN_DM_OD_LO
#define Door_StepSizeA_DM_OD_HI           PIN_DM_OD_HI
#define Door_StepSizeA_DM_STRONG          PIN_DM_STRONG
#define Door_StepSizeA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Door_StepSizeA_MASK               Door_StepSizeA__MASK
#define Door_StepSizeA_SHIFT              Door_StepSizeA__SHIFT
#define Door_StepSizeA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Door_StepSizeA_PS                     (* (reg8 *) Door_StepSizeA__PS)
/* Data Register */
#define Door_StepSizeA_DR                     (* (reg8 *) Door_StepSizeA__DR)
/* Port Number */
#define Door_StepSizeA_PRT_NUM                (* (reg8 *) Door_StepSizeA__PRT) 
/* Connect to Analog Globals */                                                  
#define Door_StepSizeA_AG                     (* (reg8 *) Door_StepSizeA__AG)                       
/* Analog MUX bux enable */
#define Door_StepSizeA_AMUX                   (* (reg8 *) Door_StepSizeA__AMUX) 
/* Bidirectional Enable */                                                        
#define Door_StepSizeA_BIE                    (* (reg8 *) Door_StepSizeA__BIE)
/* Bit-mask for Aliased Register Access */
#define Door_StepSizeA_BIT_MASK               (* (reg8 *) Door_StepSizeA__BIT_MASK)
/* Bypass Enable */
#define Door_StepSizeA_BYP                    (* (reg8 *) Door_StepSizeA__BYP)
/* Port wide control signals */                                                   
#define Door_StepSizeA_CTL                    (* (reg8 *) Door_StepSizeA__CTL)
/* Drive Modes */
#define Door_StepSizeA_DM0                    (* (reg8 *) Door_StepSizeA__DM0) 
#define Door_StepSizeA_DM1                    (* (reg8 *) Door_StepSizeA__DM1)
#define Door_StepSizeA_DM2                    (* (reg8 *) Door_StepSizeA__DM2) 
/* Input Buffer Disable Override */
#define Door_StepSizeA_INP_DIS                (* (reg8 *) Door_StepSizeA__INP_DIS)
/* LCD Common or Segment Drive */
#define Door_StepSizeA_LCD_COM_SEG            (* (reg8 *) Door_StepSizeA__LCD_COM_SEG)
/* Enable Segment LCD */
#define Door_StepSizeA_LCD_EN                 (* (reg8 *) Door_StepSizeA__LCD_EN)
/* Slew Rate Control */
#define Door_StepSizeA_SLW                    (* (reg8 *) Door_StepSizeA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Door_StepSizeA_PRTDSI__CAPS_SEL       (* (reg8 *) Door_StepSizeA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Door_StepSizeA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Door_StepSizeA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Door_StepSizeA_PRTDSI__OE_SEL0        (* (reg8 *) Door_StepSizeA__PRTDSI__OE_SEL0) 
#define Door_StepSizeA_PRTDSI__OE_SEL1        (* (reg8 *) Door_StepSizeA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Door_StepSizeA_PRTDSI__OUT_SEL0       (* (reg8 *) Door_StepSizeA__PRTDSI__OUT_SEL0) 
#define Door_StepSizeA_PRTDSI__OUT_SEL1       (* (reg8 *) Door_StepSizeA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Door_StepSizeA_PRTDSI__SYNC_OUT       (* (reg8 *) Door_StepSizeA__PRTDSI__SYNC_OUT) 


#if defined(Door_StepSizeA__INTSTAT)  /* Interrupt Registers */

    #define Door_StepSizeA_INTSTAT                (* (reg8 *) Door_StepSizeA__INTSTAT)
    #define Door_StepSizeA_SNAP                   (* (reg8 *) Door_StepSizeA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Door_StepSizeA_H */


/* [] END OF FILE */
