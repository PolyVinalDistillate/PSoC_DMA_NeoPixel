/*******************************************************************************
* File Name: NeoPixDrv_1_BITCNT_PM.c
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

#include "NeoPixDrv_1_BITCNT.h"


NeoPixDrv_1_BITCNT_BACKUP_STRUCT NeoPixDrv_1_BITCNT_backup;


/*******************************************************************************
* Function Name: NeoPixDrv_1_BITCNT_SaveConfig
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
*  NeoPixDrv_1_BITCNT_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void NeoPixDrv_1_BITCNT_SaveConfig(void) 
{
    NeoPixDrv_1_BITCNT_backup.count = NeoPixDrv_1_BITCNT_COUNT_REG;
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_BITCNT_Sleep
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
void NeoPixDrv_1_BITCNT_Sleep(void) 
{
    if(0u != (NeoPixDrv_1_BITCNT_AUX_CONTROL_REG & NeoPixDrv_1_BITCNT_COUNTER_START))
    {
        NeoPixDrv_1_BITCNT_backup.enableState = 1u;
        NeoPixDrv_1_BITCNT_Stop();
    }
    else
    {
        NeoPixDrv_1_BITCNT_backup.enableState = 0u;
    }

    NeoPixDrv_1_BITCNT_SaveConfig();
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_BITCNT_RestoreConfig
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
*  NeoPixDrv_1_BITCNT_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void NeoPixDrv_1_BITCNT_RestoreConfig(void) 
{
    NeoPixDrv_1_BITCNT_COUNT_REG = NeoPixDrv_1_BITCNT_backup.count;
}


/*******************************************************************************
* Function Name: NeoPixDrv_1_BITCNT_Wakeup
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
void NeoPixDrv_1_BITCNT_Wakeup(void) 
{
    NeoPixDrv_1_BITCNT_RestoreConfig();

    /* Restore enable state */
    if (NeoPixDrv_1_BITCNT_backup.enableState != 0u)
    {
        NeoPixDrv_1_BITCNT_Enable();
    }
}


/* [] END OF FILE */
