/*******************************************************************************
* File Name: Data.c  
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
#include "Data.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Data__PORT == 15 && ((Data__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Data_Write
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
void Data_Write(uint8 value) 
{
    uint8 staticBits = (Data_DR & (uint8)(~Data_MASK));
    Data_DR = staticBits | ((uint8)(value << Data_SHIFT) & Data_MASK);
}


/*******************************************************************************
* Function Name: Data_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Data_DM_STRONG     Strong Drive 
*  Data_DM_OD_HI      Open Drain, Drives High 
*  Data_DM_OD_LO      Open Drain, Drives Low 
*  Data_DM_RES_UP     Resistive Pull Up 
*  Data_DM_RES_DWN    Resistive Pull Down 
*  Data_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Data_DM_DIG_HIZ    High Impedance Digital 
*  Data_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Data_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Data_0, mode);
}


/*******************************************************************************
* Function Name: Data_Read
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
*  Macro Data_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Data_Read(void) 
{
    return (Data_PS & Data_MASK) >> Data_SHIFT;
}


/*******************************************************************************
* Function Name: Data_ReadDataReg
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
uint8 Data_ReadDataReg(void) 
{
    return (Data_DR & Data_MASK) >> Data_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Data_INTSTAT) 

    /*******************************************************************************
    * Function Name: Data_ClearInterrupt
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
    uint8 Data_ClearInterrupt(void) 
    {
        return (Data_INTSTAT & Data_MASK) >> Data_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
