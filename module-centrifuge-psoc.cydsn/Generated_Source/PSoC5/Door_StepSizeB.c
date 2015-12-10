/*******************************************************************************
* File Name: Door_StepSizeB.c  
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
#include "Door_StepSizeB.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Door_StepSizeB__PORT == 15 && ((Door_StepSizeB__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Door_StepSizeB_Write
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
void Door_StepSizeB_Write(uint8 value) 
{
    uint8 staticBits = (Door_StepSizeB_DR & (uint8)(~Door_StepSizeB_MASK));
    Door_StepSizeB_DR = staticBits | ((uint8)(value << Door_StepSizeB_SHIFT) & Door_StepSizeB_MASK);
}


/*******************************************************************************
* Function Name: Door_StepSizeB_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Door_StepSizeB_DM_STRONG     Strong Drive 
*  Door_StepSizeB_DM_OD_HI      Open Drain, Drives High 
*  Door_StepSizeB_DM_OD_LO      Open Drain, Drives Low 
*  Door_StepSizeB_DM_RES_UP     Resistive Pull Up 
*  Door_StepSizeB_DM_RES_DWN    Resistive Pull Down 
*  Door_StepSizeB_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Door_StepSizeB_DM_DIG_HIZ    High Impedance Digital 
*  Door_StepSizeB_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Door_StepSizeB_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Door_StepSizeB_0, mode);
}


/*******************************************************************************
* Function Name: Door_StepSizeB_Read
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
*  Macro Door_StepSizeB_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Door_StepSizeB_Read(void) 
{
    return (Door_StepSizeB_PS & Door_StepSizeB_MASK) >> Door_StepSizeB_SHIFT;
}


/*******************************************************************************
* Function Name: Door_StepSizeB_ReadDataReg
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
uint8 Door_StepSizeB_ReadDataReg(void) 
{
    return (Door_StepSizeB_DR & Door_StepSizeB_MASK) >> Door_StepSizeB_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Door_StepSizeB_INTSTAT) 

    /*******************************************************************************
    * Function Name: Door_StepSizeB_ClearInterrupt
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
    uint8 Door_StepSizeB_ClearInterrupt(void) 
    {
        return (Door_StepSizeB_INTSTAT & Door_StepSizeB_MASK) >> Door_StepSizeB_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
