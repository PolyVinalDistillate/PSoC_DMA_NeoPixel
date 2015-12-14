/*******************************************************************************
* File Name: Neo_ONTime.c
* Version 1.0
*
* Description:
*  This file provides source code for the Count7 component's API.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Neo_ONTime.h"
#include "CyLib.h"


uint8 Neo_ONTime_initVar = 0u;


/*******************************************************************************
* Function Name: Neo_ONTime_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the parameter editor
*  settings.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Theory:
*  It is not necessary to call Count7_Init() because the Count7_Start() API
*  calls this function and is the preferred method to begin component
*  operation.
*
*******************************************************************************/
void Neo_ONTime_Init(void) 
{
    /* Set the initial period value from parameter editor */
    Neo_ONTime_PERIOD_REG = Neo_ONTime_INITIAL_PERIOD;
}


/*******************************************************************************
* Function Name: Neo_ONTime_Enable
********************************************************************************
*
* Summary:
*  Enables the software enable of the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Theory:
*  It is not necessary to call Count7_Enable() because the Count7_Start() API
*  calls this function, which is the preferred method to begin component
*  operation.
*  This API performs modification of auxiliary control register which is a
*  shared resource so it is required to disable interrupts until the
*  modification will complete.
*
*******************************************************************************/
void Neo_ONTime_Enable(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    /* Set the counter start bit in auxiliary control. If routed enable
    * isn't used then this will immediately star the Count7 operation.
    */
    Neo_ONTime_AUX_CONTROL_REG |= Neo_ONTime_COUNTER_START;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Neo_ONTime_Start
********************************************************************************
*
* Summary:
*  Performs all of the required initialization for the component and enables
*  the counter. The first time the routine is executed, the period is set as
*  configured in the customizer. When called to restart the counter following a
*  Count7_Stop() call, the current period value is retained.
*
* Parameters:
*  None.
*
* Global Variables:
*  Neo_ONTime_initVar - global variable.
*
* Return:
*  None.
*
*******************************************************************************/
void Neo_ONTime_Start(void) 
{
    /* If not initialized then perform initialization */
    if(Neo_ONTime_initVar == 0u)
    {
        Neo_ONTime_Init();
        Neo_ONTime_initVar = 1u;
    }

    /* Enable Count7 */
    Neo_ONTime_Enable();
}


/*******************************************************************************
* Function Name: Neo_ONTime_Stop
********************************************************************************
*
* Summary:
*  Disables the software enable of the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Neo_ONTime_Stop(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    /* Clear the counter start bit in auxiliary control. */
    Neo_ONTime_AUX_CONTROL_REG &= (uint8) ~((uint8) Neo_ONTime_COUNTER_START);

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Neo_ONTime_WriteCounter
********************************************************************************
*
* Summary:
*  This function writes the counter directly. The counter should be disabled
*  before calling this function.
*
* Parameters:
*  count - Value to be written to counter.
*
* Return:
*  None
*
*******************************************************************************/
void Neo_ONTime_WriteCounter(uint8 count) 
{
    Neo_ONTime_COUNT_REG = (count & Neo_ONTime_COUNT_7BIT_MASK);
}


/*******************************************************************************
* Function Name: Neo_ONTime_ReadCounter
********************************************************************************
*
* Summary:
*  This function reads the counter value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
uint8 Neo_ONTime_ReadCounter(void) 
{
    return(Neo_ONTime_COUNT_REG & Neo_ONTime_COUNT_7BIT_MASK);
}


/*******************************************************************************
* Function Name: Neo_ONTime_WritePeriod
********************************************************************************
*
* Summary:
*  This function writes the period register. The actual period is one greater
*  than the value in the period register since the counting sequence starts
*  with the period register and counts down to 0 inclusive. The period of the
*  counter output does not change until the counter is reloaded following the
*  terminal count value of 0 or due to a hardware load signal.
*
* Parameters:
*  period - Period value to be written.
*
* Return:
*  None
*
*******************************************************************************/
void Neo_ONTime_WritePeriod(uint8 period) 
{
    Neo_ONTime_PERIOD_REG = period;
}


/*******************************************************************************
* Function Name: Neo_ONTime_ReadPeriod
********************************************************************************
*
* Summary:
*  This function reads the period register.
*
* Parameters:
*  None
*
* Return:
*  uint8 - Current period value.
*
*******************************************************************************/
uint8 Neo_ONTime_ReadPeriod(void) 
{
    return(Neo_ONTime_PERIOD_REG);
}


/* [] END OF FILE */
