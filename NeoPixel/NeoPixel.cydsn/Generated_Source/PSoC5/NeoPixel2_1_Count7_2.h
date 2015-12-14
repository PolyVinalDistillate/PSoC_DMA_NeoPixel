/*******************************************************************************
* File Name: NeoPixel2_1_Count7_2.h
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

#if !defined(CY_COUNT7_NeoPixel2_1_Count7_2_H)
#define CY_COUNT7_NeoPixel2_1_Count7_2_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  NeoPixel2_1_Count7_2_Init(void) ;
void  NeoPixel2_1_Count7_2_Enable(void) ;
void  NeoPixel2_1_Count7_2_Start(void) ;
void  NeoPixel2_1_Count7_2_Stop(void) ;
void  NeoPixel2_1_Count7_2_WriteCounter(uint8 count) ;
uint8 NeoPixel2_1_Count7_2_ReadCounter(void) ;
void  NeoPixel2_1_Count7_2_WritePeriod(uint8 period) ;
uint8 NeoPixel2_1_Count7_2_ReadPeriod(void) ;
void  NeoPixel2_1_Count7_2_SaveConfig(void) ;
void  NeoPixel2_1_Count7_2_RestoreConfig(void) ;
void  NeoPixel2_1_Count7_2_Sleep(void) ;
void  NeoPixel2_1_Count7_2_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} NeoPixel2_1_Count7_2_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern NeoPixel2_1_Count7_2_BACKUP_STRUCT NeoPixel2_1_Count7_2_backup;
extern uint8 NeoPixel2_1_Count7_2_initVar;


/***************************************
* Initial Parameter
***************************************/
#define NeoPixel2_1_Count7_2_INITIAL_PERIOD               (127u)


/***************************************
* Registers
***************************************/
#define NeoPixel2_1_Count7_2_COUNT_REG                    (*(reg8 *) NeoPixel2_1_Count7_2_Counter7__COUNT_REG)
#define NeoPixel2_1_Count7_2_COUNT_PTR                    ( (reg8 *) NeoPixel2_1_Count7_2_Counter7__COUNT_REG)
#define NeoPixel2_1_Count7_2_PERIOD_REG                   (*(reg8 *) NeoPixel2_1_Count7_2_Counter7__PERIOD_REG)
#define NeoPixel2_1_Count7_2_PERIOD_PTR                   ( (reg8 *) NeoPixel2_1_Count7_2_Counter7__PERIOD_REG)
#define NeoPixel2_1_Count7_2_AUX_CONTROL_REG              (*(reg8 *) NeoPixel2_1_Count7_2_Counter7__CONTROL_AUX_CTL_REG)
#define NeoPixel2_1_Count7_2_AUX_CONTROL_PTR              ( (reg8 *) NeoPixel2_1_Count7_2_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define NeoPixel2_1_Count7_2_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define NeoPixel2_1_Count7_2_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_NeoPixel2_1_Count7_2_H */


/* [] END OF FILE */
