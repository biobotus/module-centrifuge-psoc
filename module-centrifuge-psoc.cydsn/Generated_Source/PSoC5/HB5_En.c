/*******************************************************************************
* File Name: HB5_En.c  
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
#include "HB5_En.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 HB5_En__PORT == 15 && ((HB5_En__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: HB5_En_Write
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
void HB5_En_Write(uint8 value) 
{
    uint8 staticBits = (HB5_En_DR & (uint8)(~HB5_En_MASK));
    HB5_En_DR = staticBits | ((uint8)(value << HB5_En_SHIFT) & HB5_En_MASK);
}


/*******************************************************************************
* Function Name: HB5_En_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  HB5_En_DM_STRONG     Strong Drive 
*  HB5_En_DM_OD_HI      Open Drain, Drives High 
*  HB5_En_DM_OD_LO      Open Drain, Drives Low 
*  HB5_En_DM_RES_UP     Resistive Pull Up 
*  HB5_En_DM_RES_DWN    Resistive Pull Down 
*  HB5_En_DM_RES_UPDWN  Resistive Pull Up/Down 
*  HB5_En_DM_DIG_HIZ    High Impedance Digital 
*  HB5_En_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void HB5_En_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HB5_En_0, mode);
}


/*******************************************************************************
* Function Name: HB5_En_Read
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
*  Macro HB5_En_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HB5_En_Read(void) 
{
    return (HB5_En_PS & HB5_En_MASK) >> HB5_En_SHIFT;
}


/*******************************************************************************
* Function Name: HB5_En_ReadDataReg
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
uint8 HB5_En_ReadDataReg(void) 
{
    return (HB5_En_DR & HB5_En_MASK) >> HB5_En_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HB5_En_INTSTAT) 

    /*******************************************************************************
    * Function Name: HB5_En_ClearInterrupt
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
    uint8 HB5_En_ClearInterrupt(void) 
    {
        return (HB5_En_INTSTAT & HB5_En_MASK) >> HB5_En_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
