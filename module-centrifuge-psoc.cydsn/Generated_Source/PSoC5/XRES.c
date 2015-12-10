/*******************************************************************************
* File Name: XRES.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "XRES.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 XRES__PORT == 15 && ((XRES__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: XRES_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void XRES_Write(uint8 value) 
{
    uint8 staticBits = (XRES_DR & (uint8)(~XRES_MASK));
    XRES_DR = staticBits | ((uint8)(value << XRES_SHIFT) & XRES_MASK);
}


/*******************************************************************************
* Function Name: XRES_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  XRES_DM_STRONG     Strong Drive 
*  XRES_DM_OD_HI      Open Drain, Drives High 
*  XRES_DM_OD_LO      Open Drain, Drives Low 
*  XRES_DM_RES_UP     Resistive Pull Up 
*  XRES_DM_RES_DWN    Resistive Pull Down 
*  XRES_DM_RES_UPDWN  Resistive Pull Up/Down 
*  XRES_DM_DIG_HIZ    High Impedance Digital 
*  XRES_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void XRES_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(XRES_0, mode);
}


/*******************************************************************************
* Function Name: XRES_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro XRES_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 XRES_Read(void) 
{
    return (XRES_PS & XRES_MASK) >> XRES_SHIFT;
}


/*******************************************************************************
* Function Name: XRES_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 XRES_ReadDataReg(void) 
{
    return (XRES_DR & XRES_MASK) >> XRES_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(XRES_INTSTAT) 

    /*******************************************************************************
    * Function Name: XRES_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 XRES_ClearInterrupt(void) 
    {
        return (XRES_INTSTAT & XRES_MASK) >> XRES_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
