/*******************************************************************************
* File Name: Data.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Data_H) /* Pins Data_H */
#define CY_PINS_Data_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Data_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Data__PORT == 15 && ((Data__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Data_Write(uint8 value) ;
void    Data_SetDriveMode(uint8 mode) ;
uint8   Data_ReadDataReg(void) ;
uint8   Data_Read(void) ;
uint8   Data_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Data_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Data_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Data_DM_RES_UP          PIN_DM_RES_UP
#define Data_DM_RES_DWN         PIN_DM_RES_DWN
#define Data_DM_OD_LO           PIN_DM_OD_LO
#define Data_DM_OD_HI           PIN_DM_OD_HI
#define Data_DM_STRONG          PIN_DM_STRONG
#define Data_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Data_MASK               Data__MASK
#define Data_SHIFT              Data__SHIFT
#define Data_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Data_PS                     (* (reg8 *) Data__PS)
/* Data Register */
#define Data_DR                     (* (reg8 *) Data__DR)
/* Port Number */
#define Data_PRT_NUM                (* (reg8 *) Data__PRT) 
/* Connect to Analog Globals */                                                  
#define Data_AG                     (* (reg8 *) Data__AG)                       
/* Analog MUX bux enable */
#define Data_AMUX                   (* (reg8 *) Data__AMUX) 
/* Bidirectional Enable */                                                        
#define Data_BIE                    (* (reg8 *) Data__BIE)
/* Bit-mask for Aliased Register Access */
#define Data_BIT_MASK               (* (reg8 *) Data__BIT_MASK)
/* Bypass Enable */
#define Data_BYP                    (* (reg8 *) Data__BYP)
/* Port wide control signals */                                                   
#define Data_CTL                    (* (reg8 *) Data__CTL)
/* Drive Modes */
#define Data_DM0                    (* (reg8 *) Data__DM0) 
#define Data_DM1                    (* (reg8 *) Data__DM1)
#define Data_DM2                    (* (reg8 *) Data__DM2) 
/* Input Buffer Disable Override */
#define Data_INP_DIS                (* (reg8 *) Data__INP_DIS)
/* LCD Common or Segment Drive */
#define Data_LCD_COM_SEG            (* (reg8 *) Data__LCD_COM_SEG)
/* Enable Segment LCD */
#define Data_LCD_EN                 (* (reg8 *) Data__LCD_EN)
/* Slew Rate Control */
#define Data_SLW                    (* (reg8 *) Data__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Data_PRTDSI__CAPS_SEL       (* (reg8 *) Data__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Data_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Data__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Data_PRTDSI__OE_SEL0        (* (reg8 *) Data__PRTDSI__OE_SEL0) 
#define Data_PRTDSI__OE_SEL1        (* (reg8 *) Data__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Data_PRTDSI__OUT_SEL0       (* (reg8 *) Data__PRTDSI__OUT_SEL0) 
#define Data_PRTDSI__OUT_SEL1       (* (reg8 *) Data__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Data_PRTDSI__SYNC_OUT       (* (reg8 *) Data__PRTDSI__SYNC_OUT) 


#if defined(Data__INTSTAT)  /* Interrupt Registers */

    #define Data_INTSTAT                (* (reg8 *) Data__INTSTAT)
    #define Data_SNAP                   (* (reg8 *) Data__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Data_H */


/* [] END OF FILE */
