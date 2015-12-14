/*******************************************************************************
* File Name: NP_Neo_BITCNT.h
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

#if !defined(CY_COUNT7_NP_Neo_BITCNT_H)
#define CY_COUNT7_NP_Neo_BITCNT_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  NP_Neo_BITCNT_Init(void) ;
void  NP_Neo_BITCNT_Enable(void) ;
void  NP_Neo_BITCNT_Start(void) ;
void  NP_Neo_BITCNT_Stop(void) ;
void  NP_Neo_BITCNT_WriteCounter(uint8 count) ;
uint8 NP_Neo_BITCNT_ReadCounter(void) ;
void  NP_Neo_BITCNT_WritePeriod(uint8 period) ;
uint8 NP_Neo_BITCNT_ReadPeriod(void) ;
void  NP_Neo_BITCNT_SaveConfig(void) ;
void  NP_Neo_BITCNT_RestoreConfig(void) ;
void  NP_Neo_BITCNT_Sleep(void) ;
void  NP_Neo_BITCNT_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} NP_Neo_BITCNT_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern NP_Neo_BITCNT_BACKUP_STRUCT NP_Neo_BITCNT_backup;
extern uint8 NP_Neo_BITCNT_initVar;


/***************************************
* Initial Parameter
***************************************/
#define NP_Neo_BITCNT_INITIAL_PERIOD               (6u)


/***************************************
* Registers
***************************************/
#define NP_Neo_BITCNT_COUNT_REG                    (*(reg8 *) NP_Neo_BITCNT_Counter7__COUNT_REG)
#define NP_Neo_BITCNT_COUNT_PTR                    ( (reg8 *) NP_Neo_BITCNT_Counter7__COUNT_REG)
#define NP_Neo_BITCNT_PERIOD_REG                   (*(reg8 *) NP_Neo_BITCNT_Counter7__PERIOD_REG)
#define NP_Neo_BITCNT_PERIOD_PTR                   ( (reg8 *) NP_Neo_BITCNT_Counter7__PERIOD_REG)
#define NP_Neo_BITCNT_AUX_CONTROL_REG              (*(reg8 *) NP_Neo_BITCNT_Counter7__CONTROL_AUX_CTL_REG)
#define NP_Neo_BITCNT_AUX_CONTROL_PTR              ( (reg8 *) NP_Neo_BITCNT_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define NP_Neo_BITCNT_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define NP_Neo_BITCNT_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_NP_Neo_BITCNT_H */


/* [] END OF FILE */
