/*******************************************************************************
* File Name: Xacc.h  
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

#if !defined(CY_PINS_Xacc_H) /* Pins Xacc_H */
#define CY_PINS_Xacc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Xacc_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Xacc__PORT == 15 && ((Xacc__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Xacc_Write(uint8 value) ;
void    Xacc_SetDriveMode(uint8 mode) ;
uint8   Xacc_ReadDataReg(void) ;
uint8   Xacc_Read(void) ;
uint8   Xacc_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Xacc_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Xacc_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Xacc_DM_RES_UP          PIN_DM_RES_UP
#define Xacc_DM_RES_DWN         PIN_DM_RES_DWN
#define Xacc_DM_OD_LO           PIN_DM_OD_LO
#define Xacc_DM_OD_HI           PIN_DM_OD_HI
#define Xacc_DM_STRONG          PIN_DM_STRONG
#define Xacc_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Xacc_MASK               Xacc__MASK
#define Xacc_SHIFT              Xacc__SHIFT
#define Xacc_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Xacc_PS                     (* (reg8 *) Xacc__PS)
/* Data Register */
#define Xacc_DR                     (* (reg8 *) Xacc__DR)
/* Port Number */
#define Xacc_PRT_NUM                (* (reg8 *) Xacc__PRT) 
/* Connect to Analog Globals */                                                  
#define Xacc_AG                     (* (reg8 *) Xacc__AG)                       
/* Analog MUX bux enable */
#define Xacc_AMUX                   (* (reg8 *) Xacc__AMUX) 
/* Bidirectional Enable */                                                        
#define Xacc_BIE                    (* (reg8 *) Xacc__BIE)
/* Bit-mask for Aliased Register Access */
#define Xacc_BIT_MASK               (* (reg8 *) Xacc__BIT_MASK)
/* Bypass Enable */
#define Xacc_BYP                    (* (reg8 *) Xacc__BYP)
/* Port wide control signals */                                                   
#define Xacc_CTL                    (* (reg8 *) Xacc__CTL)
/* Drive Modes */
#define Xacc_DM0                    (* (reg8 *) Xacc__DM0) 
#define Xacc_DM1                    (* (reg8 *) Xacc__DM1)
#define Xacc_DM2                    (* (reg8 *) Xacc__DM2) 
/* Input Buffer Disable Override */
#define Xacc_INP_DIS                (* (reg8 *) Xacc__INP_DIS)
/* LCD Common or Segment Drive */
#define Xacc_LCD_COM_SEG            (* (reg8 *) Xacc__LCD_COM_SEG)
/* Enable Segment LCD */
#define Xacc_LCD_EN                 (* (reg8 *) Xacc__LCD_EN)
/* Slew Rate Control */
#define Xacc_SLW                    (* (reg8 *) Xacc__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Xacc_PRTDSI__CAPS_SEL       (* (reg8 *) Xacc__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Xacc_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Xacc__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Xacc_PRTDSI__OE_SEL0        (* (reg8 *) Xacc__PRTDSI__OE_SEL0) 
#define Xacc_PRTDSI__OE_SEL1        (* (reg8 *) Xacc__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Xacc_PRTDSI__OUT_SEL0       (* (reg8 *) Xacc__PRTDSI__OUT_SEL0) 
#define Xacc_PRTDSI__OUT_SEL1       (* (reg8 *) Xacc__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Xacc_PRTDSI__SYNC_OUT       (* (reg8 *) Xacc__PRTDSI__SYNC_OUT) 


#if defined(Xacc__INTSTAT)  /* Interrupt Registers */

    #define Xacc_INTSTAT                (* (reg8 *) Xacc__INTSTAT)
    #define Xacc_SNAP                   (* (reg8 *) Xacc__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Xacc_H */


/* [] END OF FILE */
