/*******************************************************************************
* File Name: Rotary_PWM.c  
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
#include "Rotary_PWM.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Rotary_PWM__PORT == 15 && ((Rotary_PWM__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Rotary_PWM_Write
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
void Rotary_PWM_Write(uint8 value) 
{
    uint8 staticBits = (Rotary_PWM_DR & (uint8)(~Rotary_PWM_MASK));
    Rotary_PWM_DR = staticBits | ((uint8)(value << Rotary_PWM_SHIFT) & Rotary_PWM_MASK);
}


/*******************************************************************************
* Function Name: Rotary_PWM_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Rotary_PWM_DM_STRONG     Strong Drive 
*  Rotary_PWM_DM_OD_HI      Open Drain, Drives High 
*  Rotary_PWM_DM_OD_LO      Open Drain, Drives Low 
*  Rotary_PWM_DM_RES_UP     Resistive Pull Up 
*  Rotary_PWM_DM_RES_DWN    Resistive Pull Down 
*  Rotary_PWM_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Rotary_PWM_DM_DIG_HIZ    High Impedance Digital 
*  Rotary_PWM_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Rotary_PWM_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Rotary_PWM_0, mode);
}


/*******************************************************************************
* Function Name: Rotary_PWM_Read
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
*  Macro Rotary_PWM_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Rotary_PWM_Read(void) 
{
    return (Rotary_PWM_PS & Rotary_PWM_MASK) >> Rotary_PWM_SHIFT;
}


/*******************************************************************************
* Function Name: Rotary_PWM_ReadDataReg
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
uint8 Rotary_PWM_ReadDataReg(void) 
{
    return (Rotary_PWM_DR & Rotary_PWM_MASK) >> Rotary_PWM_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Rotary_PWM_INTSTAT) 

    /*******************************************************************************
    * Function Name: Rotary_PWM_ClearInterrupt
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
    uint8 Rotary_PWM_ClearInterrupt(void) 
    {
        return (Rotary_PWM_INTSTAT & Rotary_PWM_MASK) >> Rotary_PWM_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
