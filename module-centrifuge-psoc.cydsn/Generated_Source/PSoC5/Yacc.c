/*******************************************************************************
* File Name: Yacc.c  
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
#include "Yacc.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Yacc__PORT == 15 && ((Yacc__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Yacc_Write
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
void Yacc_Write(uint8 value) 
{
    uint8 staticBits = (Yacc_DR & (uint8)(~Yacc_MASK));
    Yacc_DR = staticBits | ((uint8)(value << Yacc_SHIFT) & Yacc_MASK);
}


/*******************************************************************************
* Function Name: Yacc_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Yacc_DM_STRONG     Strong Drive 
*  Yacc_DM_OD_HI      Open Drain, Drives High 
*  Yacc_DM_OD_LO      Open Drain, Drives Low 
*  Yacc_DM_RES_UP     Resistive Pull Up 
*  Yacc_DM_RES_DWN    Resistive Pull Down 
*  Yacc_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Yacc_DM_DIG_HIZ    High Impedance Digital 
*  Yacc_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Yacc_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Yacc_0, mode);
}


/*******************************************************************************
* Function Name: Yacc_Read
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
*  Macro Yacc_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Yacc_Read(void) 
{
    return (Yacc_PS & Yacc_MASK) >> Yacc_SHIFT;
}


/*******************************************************************************
* Function Name: Yacc_ReadDataReg
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
uint8 Yacc_ReadDataReg(void) 
{
    return (Yacc_DR & Yacc_MASK) >> Yacc_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Yacc_INTSTAT) 

    /*******************************************************************************
    * Function Name: Yacc_ClearInterrupt
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
    uint8 Yacc_ClearInterrupt(void) 
    {
        return (Yacc_INTSTAT & Yacc_MASK) >> Yacc_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
