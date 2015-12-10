/*******************************************************************************
* File Name: InH_C.c  
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
#include "InH_C.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 InH_C__PORT == 15 && ((InH_C__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: InH_C_Write
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
void InH_C_Write(uint8 value) 
{
    uint8 staticBits = (InH_C_DR & (uint8)(~InH_C_MASK));
    InH_C_DR = staticBits | ((uint8)(value << InH_C_SHIFT) & InH_C_MASK);
}


/*******************************************************************************
* Function Name: InH_C_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  InH_C_DM_STRONG     Strong Drive 
*  InH_C_DM_OD_HI      Open Drain, Drives High 
*  InH_C_DM_OD_LO      Open Drain, Drives Low 
*  InH_C_DM_RES_UP     Resistive Pull Up 
*  InH_C_DM_RES_DWN    Resistive Pull Down 
*  InH_C_DM_RES_UPDWN  Resistive Pull Up/Down 
*  InH_C_DM_DIG_HIZ    High Impedance Digital 
*  InH_C_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void InH_C_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(InH_C_0, mode);
}


/*******************************************************************************
* Function Name: InH_C_Read
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
*  Macro InH_C_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 InH_C_Read(void) 
{
    return (InH_C_PS & InH_C_MASK) >> InH_C_SHIFT;
}


/*******************************************************************************
* Function Name: InH_C_ReadDataReg
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
uint8 InH_C_ReadDataReg(void) 
{
    return (InH_C_DR & InH_C_MASK) >> InH_C_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(InH_C_INTSTAT) 

    /*******************************************************************************
    * Function Name: InH_C_ClearInterrupt
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
    uint8 InH_C_ClearInterrupt(void) 
    {
        return (InH_C_INTSTAT & InH_C_MASK) >> InH_C_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
