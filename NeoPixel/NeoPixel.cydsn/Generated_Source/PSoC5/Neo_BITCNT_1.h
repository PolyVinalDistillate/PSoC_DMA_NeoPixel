/*******************************************************************************
* File Name: Neo_BITCNT_1.h
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

#if !defined(CY_COUNT7_Neo_BITCNT_1_H)
#define CY_COUNT7_Neo_BITCNT_1_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  Neo_BITCNT_1_Init(void) ;
void  Neo_BITCNT_1_Enable(void) ;
void  Neo_BITCNT_1_Start(void) ;
void  Neo_BITCNT_1_Stop(void) ;
void  Neo_BITCNT_1_WriteCounter(uint8 count) ;
uint8 Neo_BITCNT_1_ReadCounter(void) ;
void  Neo_BITCNT_1_WritePeriod(uint8 period) ;
uint8 Neo_BITCNT_1_ReadPeriod(void) ;
void  Neo_BITCNT_1_SaveConfig(void) ;
void  Neo_BITCNT_1_RestoreConfig(void) ;
void  Neo_BITCNT_1_Sleep(void) ;
void  Neo_BITCNT_1_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} Neo_BITCNT_1_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern Neo_BITCNT_1_BACKUP_STRUCT Neo_BITCNT_1_backup;
extern uint8 Neo_BITCNT_1_initVar;


/***************************************
* Initial Parameter
***************************************/
#define Neo_BITCNT_1_INITIAL_PERIOD               (6u)


/***************************************
* Registers
***************************************/
#define Neo_BITCNT_1_COUNT_REG                    (*(reg8 *) Neo_BITCNT_1_Counter7__COUNT_REG)
#define Neo_BITCNT_1_COUNT_PTR                    ( (reg8 *) Neo_BITCNT_1_Counter7__COUNT_REG)
#define Neo_BITCNT_1_PERIOD_REG                   (*(reg8 *) Neo_BITCNT_1_Counter7__PERIOD_REG)
#define Neo_BITCNT_1_PERIOD_PTR                   ( (reg8 *) Neo_BITCNT_1_Counter7__PERIOD_REG)
#define Neo_BITCNT_1_AUX_CONTROL_REG              (*(reg8 *) Neo_BITCNT_1_Counter7__CONTROL_AUX_CTL_REG)
#define Neo_BITCNT_1_AUX_CONTROL_PTR              ( (reg8 *) Neo_BITCNT_1_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define Neo_BITCNT_1_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define Neo_BITCNT_1_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_Neo_BITCNT_1_H */


/* [] END OF FILE */
