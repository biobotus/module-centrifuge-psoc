/*******************************************************************************
* File Name: Zacc.h  
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

#if !defined(CY_PINS_Zacc_H) /* Pins Zacc_H */
#define CY_PINS_Zacc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Zacc_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Zacc__PORT == 15 && ((Zacc__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Zacc_Write(uint8 value) ;
void    Zacc_SetDriveMode(uint8 mode) ;
uint8   Zacc_ReadDataReg(void) ;
uint8   Zacc_Read(void) ;
uint8   Zacc_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Zacc_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Zacc_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Zacc_DM_RES_UP          PIN_DM_RES_UP
#define Zacc_DM_RES_DWN         PIN_DM_RES_DWN
#define Zacc_DM_OD_LO           PIN_DM_OD_LO
#define Zacc_DM_OD_HI           PIN_DM_OD_HI
#define Zacc_DM_STRONG          PIN_DM_STRONG
#define Zacc_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Zacc_MASK               Zacc__MASK
#define Zacc_SHIFT              Zacc__SHIFT
#define Zacc_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Zacc_PS                     (* (reg8 *) Zacc__PS)
/* Data Register */
#define Zacc_DR                     (* (reg8 *) Zacc__DR)
/* Port Number */
#define Zacc_PRT_NUM                (* (reg8 *) Zacc__PRT) 
/* Connect to Analog Globals */                                                  
#define Zacc_AG                     (* (reg8 *) Zacc__AG)                       
/* Analog MUX bux enable */
#define Zacc_AMUX                   (* (reg8 *) Zacc__AMUX) 
/* Bidirectional Enable */                                                        
#define Zacc_BIE                    (* (reg8 *) Zacc__BIE)
/* Bit-mask for Aliased Register Access */
#define Zacc_BIT_MASK               (* (reg8 *) Zacc__BIT_MASK)
/* Bypass Enable */
#define Zacc_BYP                    (* (reg8 *) Zacc__BYP)
/* Port wide control signals */                                                   
#define Zacc_CTL                    (* (reg8 *) Zacc__CTL)
/* Drive Modes */
#define Zacc_DM0                    (* (reg8 *) Zacc__DM0) 
#define Zacc_DM1                    (* (reg8 *) Zacc__DM1)
#define Zacc_DM2                    (* (reg8 *) Zacc__DM2) 
/* Input Buffer Disable Override */
#define Zacc_INP_DIS                (* (reg8 *) Zacc__INP_DIS)
/* LCD Common or Segment Drive */
#define Zacc_LCD_COM_SEG            (* (reg8 *) Zacc__LCD_COM_SEG)
/* Enable Segment LCD */
#define Zacc_LCD_EN                 (* (reg8 *) Zacc__LCD_EN)
/* Slew Rate Control */
#define Zacc_SLW                    (* (reg8 *) Zacc__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Zacc_PRTDSI__CAPS_SEL       (* (reg8 *) Zacc__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Zacc_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Zacc__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Zacc_PRTDSI__OE_SEL0        (* (reg8 *) Zacc__PRTDSI__OE_SEL0) 
#define Zacc_PRTDSI__OE_SEL1        (* (reg8 *) Zacc__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Zacc_PRTDSI__OUT_SEL0       (* (reg8 *) Zacc__PRTDSI__OUT_SEL0) 
#define Zacc_PRTDSI__OUT_SEL1       (* (reg8 *) Zacc__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Zacc_PRTDSI__SYNC_OUT       (* (reg8 *) Zacc__PRTDSI__SYNC_OUT) 


#if defined(Zacc__INTSTAT)  /* Interrupt Registers */

    #define Zacc_INTSTAT                (* (reg8 *) Zacc__INTSTAT)
    #define Zacc_SNAP                   (* (reg8 *) Zacc__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Zacc_H */


/* [] END OF FILE */
