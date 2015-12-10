/*******************************************************************************
* File Name: Door_Clock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Door_Clock_H)
#define CY_CLOCK_Door_Clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Door_Clock_Start(void) ;
void Door_Clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Door_Clock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Door_Clock_StandbyPower(uint8 state) ;
void Door_Clock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Door_Clock_GetDividerRegister(void) ;
void Door_Clock_SetModeRegister(uint8 modeBitMask) ;
void Door_Clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 Door_Clock_GetModeRegister(void) ;
void Door_Clock_SetSourceRegister(uint8 clkSource) ;
uint8 Door_Clock_GetSourceRegister(void) ;
#if defined(Door_Clock__CFG3)
void Door_Clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 Door_Clock_GetPhaseRegister(void) ;
#endif /* defined(Door_Clock__CFG3) */

#define Door_Clock_Enable()                       Door_Clock_Start()
#define Door_Clock_Disable()                      Door_Clock_Stop()
#define Door_Clock_SetDivider(clkDivider)         Door_Clock_SetDividerRegister(clkDivider, 1u)
#define Door_Clock_SetDividerValue(clkDivider)    Door_Clock_SetDividerRegister((clkDivider) - 1u, 1u)
#define Door_Clock_SetMode(clkMode)               Door_Clock_SetModeRegister(clkMode)
#define Door_Clock_SetSource(clkSource)           Door_Clock_SetSourceRegister(clkSource)
#if defined(Door_Clock__CFG3)
#define Door_Clock_SetPhase(clkPhase)             Door_Clock_SetPhaseRegister(clkPhase)
#define Door_Clock_SetPhaseValue(clkPhase)        Door_Clock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Door_Clock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Door_Clock_CLKEN              (* (reg8 *) Door_Clock__PM_ACT_CFG)
#define Door_Clock_CLKEN_PTR          ((reg8 *) Door_Clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Door_Clock_CLKSTBY            (* (reg8 *) Door_Clock__PM_STBY_CFG)
#define Door_Clock_CLKSTBY_PTR        ((reg8 *) Door_Clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Door_Clock_DIV_LSB            (* (reg8 *) Door_Clock__CFG0)
#define Door_Clock_DIV_LSB_PTR        ((reg8 *) Door_Clock__CFG0)
#define Door_Clock_DIV_PTR            ((reg16 *) Door_Clock__CFG0)

/* Clock MSB divider configuration register. */
#define Door_Clock_DIV_MSB            (* (reg8 *) Door_Clock__CFG1)
#define Door_Clock_DIV_MSB_PTR        ((reg8 *) Door_Clock__CFG1)

/* Mode and source configuration register */
#define Door_Clock_MOD_SRC            (* (reg8 *) Door_Clock__CFG2)
#define Door_Clock_MOD_SRC_PTR        ((reg8 *) Door_Clock__CFG2)

#if defined(Door_Clock__CFG3)
/* Analog clock phase configuration register */
#define Door_Clock_PHASE              (* (reg8 *) Door_Clock__CFG3)
#define Door_Clock_PHASE_PTR          ((reg8 *) Door_Clock__CFG3)
#endif /* defined(Door_Clock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Door_Clock_CLKEN_MASK         Door_Clock__PM_ACT_MSK
#define Door_Clock_CLKSTBY_MASK       Door_Clock__PM_STBY_MSK

/* CFG2 field masks */
#define Door_Clock_SRC_SEL_MSK        Door_Clock__CFG2_SRC_SEL_MASK
#define Door_Clock_MODE_MASK          (~(Door_Clock_SRC_SEL_MSK))

#if defined(Door_Clock__CFG3)
/* CFG3 phase mask */
#define Door_Clock_PHASE_MASK         Door_Clock__CFG3_PHASE_DLY_MASK
#endif /* defined(Door_Clock__CFG3) */

#endif /* CY_CLOCK_Door_Clock_H */


/* [] END OF FILE */
