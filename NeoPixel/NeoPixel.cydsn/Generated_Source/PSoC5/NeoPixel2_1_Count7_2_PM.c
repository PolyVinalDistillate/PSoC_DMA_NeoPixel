/*******************************************************************************
* File Name: NeoPixel2_1_Count7_2_PM.c
* Version 1.0
*
* Description:
*  This file provides Low power mode APIs for Count7 component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "NeoPixel2_1_Count7_2.h"


NeoPixel2_1_Count7_2_BACKUP_STRUCT NeoPixel2_1_Count7_2_backup;


/*******************************************************************************
* Function Name: NeoPixel2_1_Count7_2_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component configuration and non-retention registers.
*  This function is called by the Count7_Sleep() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  NeoPixel2_1_Count7_2_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void NeoPixel2_1_Count7_2_SaveConfig(void) 
{
    NeoPixel2_1_Count7_2_backup.count = NeoPixel2_1_Count7_2_COUNT_REG;
}


/*******************************************************************************
* Function Name: NeoPixel2_1_Count7_2_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for low power mode
*  operation. The Count7_Sleep() API saves the current component state using
*  Count7_SaveConfig() and disables the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void NeoPixel2_1_Count7_2_Sleep(void) 
{
    if(0u != (NeoPixel2_1_Count7_2_AUX_CONTROL_REG & NeoPixel2_1_Count7_2_COUNTER_START))
    {
        NeoPixel2_1_Count7_2_backup.enableState = 1u;
        NeoPixel2_1_Count7_2_Stop();
    }
    else
    {
        NeoPixel2_1_Count7_2_backup.enableState = 0u;
    }

    NeoPixel2_1_Count7_2_SaveConfig();
}


/*******************************************************************************
* Function Name: NeoPixel2_1_Count7_2_RestoreConfig
********************************************************************************
*
* Summary:
*  This function restores the component configuration and non-retention
*  registers. This function is called by the Count7_Wakeup() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  NeoPixel2_1_Count7_2_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void NeoPixel2_1_Count7_2_RestoreConfig(void) 
{
    NeoPixel2_1_Count7_2_COUNT_REG = NeoPixel2_1_Count7_2_backup.count;
}


/*******************************************************************************
* Function Name: NeoPixel2_1_Count7_2_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when
*  Count7_Sleep() was called. The Count7_Wakeup() function calls the
*  Count7_RestoreConfig() function to restore the configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void NeoPixel2_1_Count7_2_Wakeup(void) 
{
    NeoPixel2_1_Count7_2_RestoreConfig();

    /* Restore enable state */
    if (NeoPixel2_1_Count7_2_backup.enableState != 0u)
    {
        NeoPixel2_1_Count7_2_Enable();
    }
}


/* [] END OF FILE */
