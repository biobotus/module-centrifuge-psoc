/*******************************************************************************
* File Name: Position_INT.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Position_INT_H)
#define CY_ISR_Position_INT_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Position_INT_Start(void);
void Position_INT_StartEx(cyisraddress address);
void Position_INT_Stop(void);

CY_ISR_PROTO(Position_INT_Interrupt);

void Position_INT_SetVector(cyisraddress address);
cyisraddress Position_INT_GetVector(void);

void Position_INT_SetPriority(uint8 priority);
uint8 Position_INT_GetPriority(void);

void Position_INT_Enable(void);
uint8 Position_INT_GetState(void);
void Position_INT_Disable(void);

void Position_INT_SetPending(void);
void Position_INT_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Position_INT ISR. */
#define Position_INT_INTC_VECTOR            ((reg32 *) Position_INT__INTC_VECT)

/* Address of the Position_INT ISR priority. */
#define Position_INT_INTC_PRIOR             ((reg8 *) Position_INT__INTC_PRIOR_REG)

/* Priority of the Position_INT interrupt. */
#define Position_INT_INTC_PRIOR_NUMBER      Position_INT__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Position_INT interrupt. */
#define Position_INT_INTC_SET_EN            ((reg32 *) Position_INT__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Position_INT interrupt. */
#define Position_INT_INTC_CLR_EN            ((reg32 *) Position_INT__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Position_INT interrupt state to pending. */
#define Position_INT_INTC_SET_PD            ((reg32 *) Position_INT__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Position_INT interrupt. */
#define Position_INT_INTC_CLR_PD            ((reg32 *) Position_INT__INTC_CLR_PD_REG)


#endif /* CY_ISR_Position_INT_H */


/* [] END OF FILE */
