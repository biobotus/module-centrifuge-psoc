/*******************************************************************************
* File Name: RotarySensor_SSI_DIO.h  
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

#if !defined(CY_PINS_RotarySensor_SSI_DIO_H) /* Pins RotarySensor_SSI_DIO_H */
#define CY_PINS_RotarySensor_SSI_DIO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RotarySensor_SSI_DIO_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RotarySensor_SSI_DIO__PORT == 15 && ((RotarySensor_SSI_DIO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RotarySensor_SSI_DIO_Write(uint8 value) ;
void    RotarySensor_SSI_DIO_SetDriveMode(uint8 mode) ;
uint8   RotarySensor_SSI_DIO_ReadDataReg(void) ;
uint8   RotarySensor_SSI_DIO_Read(void) ;
uint8   RotarySensor_SSI_DIO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RotarySensor_SSI_DIO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RotarySensor_SSI_DIO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RotarySensor_SSI_DIO_DM_RES_UP          PIN_DM_RES_UP
#define RotarySensor_SSI_DIO_DM_RES_DWN         PIN_DM_RES_DWN
#define RotarySensor_SSI_DIO_DM_OD_LO           PIN_DM_OD_LO
#define RotarySensor_SSI_DIO_DM_OD_HI           PIN_DM_OD_HI
#define RotarySensor_SSI_DIO_DM_STRONG          PIN_DM_STRONG
#define RotarySensor_SSI_DIO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RotarySensor_SSI_DIO_MASK               RotarySensor_SSI_DIO__MASK
#define RotarySensor_SSI_DIO_SHIFT              RotarySensor_SSI_DIO__SHIFT
#define RotarySensor_SSI_DIO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RotarySensor_SSI_DIO_PS                     (* (reg8 *) RotarySensor_SSI_DIO__PS)
/* Data Register */
#define RotarySensor_SSI_DIO_DR                     (* (reg8 *) RotarySensor_SSI_DIO__DR)
/* Port Number */
#define RotarySensor_SSI_DIO_PRT_NUM                (* (reg8 *) RotarySensor_SSI_DIO__PRT) 
/* Connect to Analog Globals */                                                  
#define RotarySensor_SSI_DIO_AG                     (* (reg8 *) RotarySensor_SSI_DIO__AG)                       
/* Analog MUX bux enable */
#define RotarySensor_SSI_DIO_AMUX                   (* (reg8 *) RotarySensor_SSI_DIO__AMUX) 
/* Bidirectional Enable */                                                        
#define RotarySensor_SSI_DIO_BIE                    (* (reg8 *) RotarySensor_SSI_DIO__BIE)
/* Bit-mask for Aliased Register Access */
#define RotarySensor_SSI_DIO_BIT_MASK               (* (reg8 *) RotarySensor_SSI_DIO__BIT_MASK)
/* Bypass Enable */
#define RotarySensor_SSI_DIO_BYP                    (* (reg8 *) RotarySensor_SSI_DIO__BYP)
/* Port wide control signals */                                                   
#define RotarySensor_SSI_DIO_CTL                    (* (reg8 *) RotarySensor_SSI_DIO__CTL)
/* Drive Modes */
#define RotarySensor_SSI_DIO_DM0                    (* (reg8 *) RotarySensor_SSI_DIO__DM0) 
#define RotarySensor_SSI_DIO_DM1                    (* (reg8 *) RotarySensor_SSI_DIO__DM1)
#define RotarySensor_SSI_DIO_DM2                    (* (reg8 *) RotarySensor_SSI_DIO__DM2) 
/* Input Buffer Disable Override */
#define RotarySensor_SSI_DIO_INP_DIS                (* (reg8 *) RotarySensor_SSI_DIO__INP_DIS)
/* LCD Common or Segment Drive */
#define RotarySensor_SSI_DIO_LCD_COM_SEG            (* (reg8 *) RotarySensor_SSI_DIO__LCD_COM_SEG)
/* Enable Segment LCD */
#define RotarySensor_SSI_DIO_LCD_EN                 (* (reg8 *) RotarySensor_SSI_DIO__LCD_EN)
/* Slew Rate Control */
#define RotarySensor_SSI_DIO_SLW                    (* (reg8 *) RotarySensor_SSI_DIO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RotarySensor_SSI_DIO_PRTDSI__CAPS_SEL       (* (reg8 *) RotarySensor_SSI_DIO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RotarySensor_SSI_DIO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RotarySensor_SSI_DIO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RotarySensor_SSI_DIO_PRTDSI__OE_SEL0        (* (reg8 *) RotarySensor_SSI_DIO__PRTDSI__OE_SEL0) 
#define RotarySensor_SSI_DIO_PRTDSI__OE_SEL1        (* (reg8 *) RotarySensor_SSI_DIO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RotarySensor_SSI_DIO_PRTDSI__OUT_SEL0       (* (reg8 *) RotarySensor_SSI_DIO__PRTDSI__OUT_SEL0) 
#define RotarySensor_SSI_DIO_PRTDSI__OUT_SEL1       (* (reg8 *) RotarySensor_SSI_DIO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RotarySensor_SSI_DIO_PRTDSI__SYNC_OUT       (* (reg8 *) RotarySensor_SSI_DIO__PRTDSI__SYNC_OUT) 


#if defined(RotarySensor_SSI_DIO__INTSTAT)  /* Interrupt Registers */

    #define RotarySensor_SSI_DIO_INTSTAT                (* (reg8 *) RotarySensor_SSI_DIO__INTSTAT)
    #define RotarySensor_SSI_DIO_SNAP                   (* (reg8 *) RotarySensor_SSI_DIO__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RotarySensor_SSI_DIO_H */


/* [] END OF FILE */
