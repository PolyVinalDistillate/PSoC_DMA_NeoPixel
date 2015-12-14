/*******************************************************************************
* File Name: Neo_BITCNT_PM.c
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

#include "Neo_BITCNT.h"


Neo_BITCNT_BACKUP_STRUCT Neo_BITCNT_backup;


/*******************************************************************************
* Function Name: Neo_BITCNT_SaveConfig
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
*  Neo_BITCNT_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void Neo_BITCNT_SaveConfig(void) 
{
    Neo_BITCNT_backup.count = Neo_BITCNT_COUNT_REG;
}


/*******************************************************************************
* Function Name: Neo_BITCNT_Sleep
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
void Neo_BITCNT_Sleep(void) 
{
    if(0u != (Neo_BITCNT_AUX_CONTROL_REG & Neo_BITCNT_COUNTER_START))
    {
        Neo_BITCNT_backup.enableState = 1u;
        Neo_BITCNT_Stop();
    }
    else
    {
        Neo_BITCNT_backup.enableState = 0u;
    }

    Neo_BITCNT_SaveConfig();
}


/*******************************************************************************
* Function Name: Neo_BITCNT_RestoreConfig
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
*  Neo_BITCNT_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void Neo_BITCNT_RestoreConfig(void) 
{
    Neo_BITCNT_COUNT_REG = Neo_BITCNT_backup.count;
}


/*******************************************************************************
* Function Name: Neo_BITCNT_Wakeup
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
void Neo_BITCNT_Wakeup(void) 
{
    Neo_BITCNT_RestoreConfig();

    /* Restore enable state */
    if (Neo_BITCNT_backup.enableState != 0u)
    {
        Neo_BITCNT_Enable();
    }
}


/* [] END OF FILE */
