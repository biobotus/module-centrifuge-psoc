/*******************************************************************************
* File Name: Zacc.c  
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
#include "Zacc.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Zacc__PORT == 15 && ((Zacc__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Zacc_Write
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
void Zacc_Write(uint8 value) 
{
    uint8 staticBits = (Zacc_DR & (uint8)(~Zacc_MASK));
    Zacc_DR = staticBits | ((uint8)(value << Zacc_SHIFT) & Zacc_MASK);
}


/*******************************************************************************
* Function Name: Zacc_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Zacc_DM_STRONG     Strong Drive 
*  Zacc_DM_OD_HI      Open Drain, Drives High 
*  Zacc_DM_OD_LO      Open Drain, Drives Low 
*  Zacc_DM_RES_UP     Resistive Pull Up 
*  Zacc_DM_RES_DWN    Resistive Pull Down 
*  Zacc_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Zacc_DM_DIG_HIZ    High Impedance Digital 
*  Zacc_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Zacc_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Zacc_0, mode);
}


/*******************************************************************************
* Function Name: Zacc_Read
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
*  Macro Zacc_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Zacc_Read(void) 
{
    return (Zacc_PS & Zacc_MASK) >> Zacc_SHIFT;
}


/*******************************************************************************
* Function Name: Zacc_ReadDataReg
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
uint8 Zacc_ReadDataReg(void) 
{
    return (Zacc_DR & Zacc_MASK) >> Zacc_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Zacc_INTSTAT) 

    /*******************************************************************************
    * Function Name: Zacc_ClearInterrupt
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
    uint8 Zacc_ClearInterrupt(void) 
    {
        return (Zacc_INTSTAT & Zacc_MASK) >> Zacc_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
