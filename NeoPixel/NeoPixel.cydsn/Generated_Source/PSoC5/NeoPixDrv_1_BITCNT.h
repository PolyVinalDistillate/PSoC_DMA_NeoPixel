/*******************************************************************************
* File Name: NeoPixDrv_1_BITCNT.h
* Version 1.0
*
* Description:
*  This header file contains registers and constants associated with the
*  Count7 component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COUNT7_NeoPixDrv_1_BITCNT_H)
#define CY_COUNT7_NeoPixDrv_1_BITCNT_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  NeoPixDrv_1_BITCNT_Init(void) ;
void  NeoPixDrv_1_BITCNT_Enable(void) ;
void  NeoPixDrv_1_BITCNT_Start(void) ;
void  NeoPixDrv_1_BITCNT_Stop(void) ;
void  NeoPixDrv_1_BITCNT_WriteCounter(uint8 count) ;
uint8 NeoPixDrv_1_BITCNT_ReadCounter(void) ;
void  NeoPixDrv_1_BITCNT_WritePeriod(uint8 period) ;
uint8 NeoPixDrv_1_BITCNT_ReadPeriod(void) ;
void  NeoPixDrv_1_BITCNT_SaveConfig(void) ;
void  NeoPixDrv_1_BITCNT_RestoreConfig(void) ;
void  NeoPixDrv_1_BITCNT_Sleep(void) ;
void  NeoPixDrv_1_BITCNT_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} NeoPixDrv_1_BITCNT_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern NeoPixDrv_1_BITCNT_BACKUP_STRUCT NeoPixDrv_1_BITCNT_backup;
extern uint8 NeoPixDrv_1_BITCNT_initVar;


/***************************************
* Initial Parameter
***************************************/
#define NeoPixDrv_1_BITCNT_INITIAL_PERIOD               (6u)


/***************************************
* Registers
***************************************/
#define NeoPixDrv_1_BITCNT_COUNT_REG                    (*(reg8 *) NeoPixDrv_1_BITCNT_Counter7__COUNT_REG)
#define NeoPixDrv_1_BITCNT_COUNT_PTR                    ( (reg8 *) NeoPixDrv_1_BITCNT_Counter7__COUNT_REG)
#define NeoPixDrv_1_BITCNT_PERIOD_REG                   (*(reg8 *) NeoPixDrv_1_BITCNT_Counter7__PERIOD_REG)
#define NeoPixDrv_1_BITCNT_PERIOD_PTR                   ( (reg8 *) NeoPixDrv_1_BITCNT_Counter7__PERIOD_REG)
#define NeoPixDrv_1_BITCNT_AUX_CONTROL_REG              (*(reg8 *) NeoPixDrv_1_BITCNT_Counter7__CONTROL_AUX_CTL_REG)
#define NeoPixDrv_1_BITCNT_AUX_CONTROL_PTR              ( (reg8 *) NeoPixDrv_1_BITCNT_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define NeoPixDrv_1_BITCNT_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define NeoPixDrv_1_BITCNT_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_NeoPixDrv_1_BITCNT_H */


/* [] END OF FILE */
