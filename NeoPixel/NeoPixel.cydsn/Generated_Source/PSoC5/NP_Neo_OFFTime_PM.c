/*******************************************************************************
* File Name: NP_Neo_OFFTime_PM.c
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

#include "NP_Neo_OFFTime.h"


NP_Neo_OFFTime_BACKUP_STRUCT NP_Neo_OFFTime_backup;


/*******************************************************************************
* Function Name: NP_Neo_OFFTime_SaveConfig
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
*  NP_Neo_OFFTime_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void NP_Neo_OFFTime_SaveConfig(void) 
{
    NP_Neo_OFFTime_backup.count = NP_Neo_OFFTime_COUNT_REG;
}


/*******************************************************************************
* Function Name: NP_Neo_OFFTime_Sleep
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
void NP_Neo_OFFTime_Sleep(void) 
{
    if(0u != (NP_Neo_OFFTime_AUX_CONTROL_REG & NP_Neo_OFFTime_COUNTER_START))
    {
        NP_Neo_OFFTime_backup.enableState = 1u;
        NP_Neo_OFFTime_Stop();
    }
    else
    {
        NP_Neo_OFFTime_backup.enableState = 0u;
    }

    NP_Neo_OFFTime_SaveConfig();
}


/*******************************************************************************
* Function Name: NP_Neo_OFFTime_RestoreConfig
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
*  NP_Neo_OFFTime_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void NP_Neo_OFFTime_RestoreConfig(void) 
{
    NP_Neo_OFFTime_COUNT_REG = NP_Neo_OFFTime_backup.count;
}


/*******************************************************************************
* Function Name: NP_Neo_OFFTime_Wakeup
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
void NP_Neo_OFFTime_Wakeup(void) 
{
    NP_Neo_OFFTime_RestoreConfig();

    /* Restore enable state */
    if (NP_Neo_OFFTime_backup.enableState != 0u)
    {
        NP_Neo_OFFTime_Enable();
    }
}


/* [] END OF FILE */
