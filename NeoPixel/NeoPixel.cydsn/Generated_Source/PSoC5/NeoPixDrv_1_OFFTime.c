/*******************************************************************************
* File Name: NeoPixDrv_1_OFFTime.c
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

#include "NeoPixDrv_1_OFFTime.h"
#include "CyLib.h"


uint8 NeoPixDrv_1_OFFTime_initVar = 0u;


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_Init
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
void NeoPixDrv_1_OFFTime_Init(void) 
{
    /* Set the initial period value from parameter editor */
    NeoPixDrv_1_OFFTime_PERIOD_REG = NeoPixDrv_1_OFFTime_INITIAL_PERIOD;
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_Enable
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
void NeoPixDrv_1_OFFTime_Enable(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    /* Set the counter start bit in auxiliary control. If routed enable
    * isn't used then this will immediately star the Count7 operation.
    */
    NeoPixDrv_1_OFFTime_AUX_CONTROL_REG |= NeoPixDrv_1_OFFTime_COUNTER_START;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_Start
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
*  NeoPixDrv_1_OFFTime_initVar - global variable.
*
* Return:
*  None.
*
*******************************************************************************/
void NeoPixDrv_1_OFFTime_Start(void) 
{
    /* If not initialized then perform initialization */
    if(NeoPixDrv_1_OFFTime_initVar == 0u)
    {
        NeoPixDrv_1_OFFTime_Init();
        NeoPixDrv_1_OFFTime_initVar = 1u;
    }

    /* Enable Count7 */
    NeoPixDrv_1_OFFTime_Enable();
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_Stop
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
void NeoPixDrv_1_OFFTime_Stop(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    /* Clear the counter start bit in auxiliary control. */
    NeoPixDrv_1_OFFTime_AUX_CONTROL_REG &= (uint8) ~((uint8) NeoPixDrv_1_OFFTime_COUNTER_START);

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_WriteCounter
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
void NeoPixDrv_1_OFFTime_WriteCounter(uint8 count) 
{
    NeoPixDrv_1_OFFTime_COUNT_REG = (count & NeoPixDrv_1_OFFTime_COUNT_7BIT_MASK);
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_ReadCounter
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
uint8 NeoPixDrv_1_OFFTime_ReadCounter(void) 
{
    return(NeoPixDrv_1_OFFTime_COUNT_REG & NeoPixDrv_1_OFFTime_COUNT_7BIT_MASK);
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_WritePeriod
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
void NeoPixDrv_1_OFFTime_WritePeriod(uint8 period) 
{
    NeoPixDrv_1_OFFTime_PERIOD_REG = period;
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_OFFTime_ReadPeriod
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
uint8 NeoPixDrv_1_OFFTime_ReadPeriod(void) 
{
    return(NeoPixDrv_1_OFFTime_PERIOD_REG);
}


/* [] END OF FILE */
