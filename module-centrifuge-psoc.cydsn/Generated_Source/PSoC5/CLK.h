/*******************************************************************************
* File Name: CLK.h  
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

#if !defined(CY_PINS_CLK_H) /* Pins CLK_H */
#define CY_PINS_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CLK_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CLK__PORT == 15 && ((CLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CLK_Write(uint8 value) ;
void    CLK_SetDriveMode(uint8 mode) ;
uint8   CLK_ReadDataReg(void) ;
uint8   CLK_Read(void) ;
uint8   CLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CLK_DM_RES_UP          PIN_DM_RES_UP
#define CLK_DM_RES_DWN         PIN_DM_RES_DWN
#define CLK_DM_OD_LO           PIN_DM_OD_LO
#define CLK_DM_OD_HI           PIN_DM_OD_HI
#define CLK_DM_STRONG          PIN_DM_STRONG
#define CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CLK_MASK               CLK__MASK
#define CLK_SHIFT              CLK__SHIFT
#define CLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CLK_PS                     (* (reg8 *) CLK__PS)
/* Data Register */
#define CLK_DR                     (* (reg8 *) CLK__DR)
/* Port Number */
#define CLK_PRT_NUM                (* (reg8 *) CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define CLK_AG                     (* (reg8 *) CLK__AG)                       
/* Analog MUX bux enable */
#define CLK_AMUX                   (* (reg8 *) CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define CLK_BIE                    (* (reg8 *) CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define CLK_BIT_MASK               (* (reg8 *) CLK__BIT_MASK)
/* Bypass Enable */
#define CLK_BYP                    (* (reg8 *) CLK__BYP)
/* Port wide control signals */                                                   
#define CLK_CTL                    (* (reg8 *) CLK__CTL)
/* Drive Modes */
#define CLK_DM0                    (* (reg8 *) CLK__DM0) 
#define CLK_DM1                    (* (reg8 *) CLK__DM1)
#define CLK_DM2                    (* (reg8 *) CLK__DM2) 
/* Input Buffer Disable Override */
#define CLK_INP_DIS                (* (reg8 *) CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define CLK_LCD_COM_SEG            (* (reg8 *) CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define CLK_LCD_EN                 (* (reg8 *) CLK__LCD_EN)
/* Slew Rate Control */
#define CLK_SLW                    (* (reg8 *) CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CLK_PRTDSI__CAPS_SEL       (* (reg8 *) CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CLK_PRTDSI__OE_SEL0        (* (reg8 *) CLK__PRTDSI__OE_SEL0) 
#define CLK_PRTDSI__OE_SEL1        (* (reg8 *) CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CLK_PRTDSI__OUT_SEL0       (* (reg8 *) CLK__PRTDSI__OUT_SEL0) 
#define CLK_PRTDSI__OUT_SEL1       (* (reg8 *) CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CLK_PRTDSI__SYNC_OUT       (* (reg8 *) CLK__PRTDSI__SYNC_OUT) 


#if defined(CLK__INTSTAT)  /* Interrupt Registers */

    #define CLK_INTSTAT                (* (reg8 *) CLK__INTSTAT)
    #define CLK_SNAP                   (* (reg8 *) CLK__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CLK_H */


/* [] END OF FILE */
