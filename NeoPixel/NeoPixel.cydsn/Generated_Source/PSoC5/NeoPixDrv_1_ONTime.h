/*******************************************************************************
* File Name: NeoPixDrv_1_ONTime.h
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

#if !defined(CY_COUNT7_NeoPixDrv_1_ONTime_H)
#define CY_COUNT7_NeoPixDrv_1_ONTime_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  NeoPixDrv_1_ONTime_Init(void) ;
void  NeoPixDrv_1_ONTime_Enable(void) ;
void  NeoPixDrv_1_ONTime_Start(void) ;
void  NeoPixDrv_1_ONTime_Stop(void) ;
void  NeoPixDrv_1_ONTime_WriteCounter(uint8 count) ;
uint8 NeoPixDrv_1_ONTime_ReadCounter(void) ;
void  NeoPixDrv_1_ONTime_WritePeriod(uint8 period) ;
uint8 NeoPixDrv_1_ONTime_ReadPeriod(void) ;
void  NeoPixDrv_1_ONTime_SaveConfig(void) ;
void  NeoPixDrv_1_ONTime_RestoreConfig(void) ;
void  NeoPixDrv_1_ONTime_Sleep(void) ;
void  NeoPixDrv_1_ONTime_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} NeoPixDrv_1_ONTime_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern NeoPixDrv_1_ONTime_BACKUP_STRUCT NeoPixDrv_1_ONTime_backup;
extern uint8 NeoPixDrv_1_ONTime_initVar;


/***************************************
* Initial Parameter
***************************************/
#define NeoPixDrv_1_ONTime_INITIAL_PERIOD               (7u)


/***************************************
* Registers
***************************************/
#define NeoPixDrv_1_ONTime_COUNT_REG                    (*(reg8 *) NeoPixDrv_1_ONTime_Counter7__COUNT_REG)
#define NeoPixDrv_1_ONTime_COUNT_PTR                    ( (reg8 *) NeoPixDrv_1_ONTime_Counter7__COUNT_REG)
#define NeoPixDrv_1_ONTime_PERIOD_REG                   (*(reg8 *) NeoPixDrv_1_ONTime_Counter7__PERIOD_REG)
#define NeoPixDrv_1_ONTime_PERIOD_PTR                   ( (reg8 *) NeoPixDrv_1_ONTime_Counter7__PERIOD_REG)
#define NeoPixDrv_1_ONTime_AUX_CONTROL_REG              (*(reg8 *) NeoPixDrv_1_ONTime_Counter7__CONTROL_AUX_CTL_REG)
#define NeoPixDrv_1_ONTime_AUX_CONTROL_PTR              ( (reg8 *) NeoPixDrv_1_ONTime_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define NeoPixDrv_1_ONTime_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define NeoPixDrv_1_ONTime_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_NeoPixDrv_1_ONTime_H */


/* [] END OF FILE */
