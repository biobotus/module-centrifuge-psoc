/*******************************************************************************
* File Name: Xacc.c  
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
#include "Xacc.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Xacc__PORT == 15 && ((Xacc__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Xacc_Write
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
void Xacc_Write(uint8 value) 
{
    uint8 staticBits = (Xacc_DR & (uint8)(~Xacc_MASK));
    Xacc_DR = staticBits | ((uint8)(value << Xacc_SHIFT) & Xacc_MASK);
}


/*******************************************************************************
* Function Name: Xacc_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Xacc_DM_STRONG     Strong Drive 
*  Xacc_DM_OD_HI      Open Drain, Drives High 
*  Xacc_DM_OD_LO      Open Drain, Drives Low 
*  Xacc_DM_RES_UP     Resistive Pull Up 
*  Xacc_DM_RES_DWN    Resistive Pull Down 
*  Xacc_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Xacc_DM_DIG_HIZ    High Impedance Digital 
*  Xacc_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Xacc_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Xacc_0, mode);
}


/*******************************************************************************
* Function Name: Xacc_Read
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
*  Macro Xacc_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Xacc_Read(void) 
{
    return (Xacc_PS & Xacc_MASK) >> Xacc_SHIFT;
}


/*******************************************************************************
* Function Name: Xacc_ReadDataReg
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
uint8 Xacc_ReadDataReg(void) 
{
    return (Xacc_DR & Xacc_MASK) >> Xacc_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Xacc_INTSTAT) 

    /*******************************************************************************
    * Function Name: Xacc_ClearInterrupt
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
    uint8 Xacc_ClearInterrupt(void) 
    {
        return (Xacc_INTSTAT & Xacc_MASK) >> Xacc_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
