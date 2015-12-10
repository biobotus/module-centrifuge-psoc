/*******************************************************************************
* File Name: XRES.h  
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

#if !defined(CY_PINS_XRES_H) /* Pins XRES_H */
#define CY_PINS_XRES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "XRES_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 XRES__PORT == 15 && ((XRES__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    XRES_Write(uint8 value) ;
void    XRES_SetDriveMode(uint8 mode) ;
uint8   XRES_ReadDataReg(void) ;
uint8   XRES_Read(void) ;
uint8   XRES_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define XRES_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define XRES_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define XRES_DM_RES_UP          PIN_DM_RES_UP
#define XRES_DM_RES_DWN         PIN_DM_RES_DWN
#define XRES_DM_OD_LO           PIN_DM_OD_LO
#define XRES_DM_OD_HI           PIN_DM_OD_HI
#define XRES_DM_STRONG          PIN_DM_STRONG
#define XRES_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define XRES_MASK               XRES__MASK
#define XRES_SHIFT              XRES__SHIFT
#define XRES_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define XRES_PS                     (* (reg8 *) XRES__PS)
/* Data Register */
#define XRES_DR                     (* (reg8 *) XRES__DR)
/* Port Number */
#define XRES_PRT_NUM                (* (reg8 *) XRES__PRT) 
/* Connect to Analog Globals */                                                  
#define XRES_AG                     (* (reg8 *) XRES__AG)                       
/* Analog MUX bux enable */
#define XRES_AMUX                   (* (reg8 *) XRES__AMUX) 
/* Bidirectional Enable */                                                        
#define XRES_BIE                    (* (reg8 *) XRES__BIE)
/* Bit-mask for Aliased Register Access */
#define XRES_BIT_MASK               (* (reg8 *) XRES__BIT_MASK)
/* Bypass Enable */
#define XRES_BYP                    (* (reg8 *) XRES__BYP)
/* Port wide control signals */                                                   
#define XRES_CTL                    (* (reg8 *) XRES__CTL)
/* Drive Modes */
#define XRES_DM0                    (* (reg8 *) XRES__DM0) 
#define XRES_DM1                    (* (reg8 *) XRES__DM1)
#define XRES_DM2                    (* (reg8 *) XRES__DM2) 
/* Input Buffer Disable Override */
#define XRES_INP_DIS                (* (reg8 *) XRES__INP_DIS)
/* LCD Common or Segment Drive */
#define XRES_LCD_COM_SEG            (* (reg8 *) XRES__LCD_COM_SEG)
/* Enable Segment LCD */
#define XRES_LCD_EN                 (* (reg8 *) XRES__LCD_EN)
/* Slew Rate Control */
#define XRES_SLW                    (* (reg8 *) XRES__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define XRES_PRTDSI__CAPS_SEL       (* (reg8 *) XRES__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define XRES_PRTDSI__DBL_SYNC_IN    (* (reg8 *) XRES__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define XRES_PRTDSI__OE_SEL0        (* (reg8 *) XRES__PRTDSI__OE_SEL0) 
#define XRES_PRTDSI__OE_SEL1        (* (reg8 *) XRES__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define XRES_PRTDSI__OUT_SEL0       (* (reg8 *) XRES__PRTDSI__OUT_SEL0) 
#define XRES_PRTDSI__OUT_SEL1       (* (reg8 *) XRES__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define XRES_PRTDSI__SYNC_OUT       (* (reg8 *) XRES__PRTDSI__SYNC_OUT) 


#if defined(XRES__INTSTAT)  /* Interrupt Registers */

    #define XRES_INTSTAT                (* (reg8 *) XRES__INTSTAT)
    #define XRES_SNAP                   (* (reg8 *) XRES__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_XRES_H */


/* [] END OF FILE */
