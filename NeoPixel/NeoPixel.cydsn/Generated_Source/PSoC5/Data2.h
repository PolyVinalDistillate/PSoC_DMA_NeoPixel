/*******************************************************************************
* File Name: Data2.h  
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

#if !defined(CY_PINS_Data2_H) /* Pins Data2_H */
#define CY_PINS_Data2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Data2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Data2__PORT == 15 && ((Data2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Data2_Write(uint8 value) ;
void    Data2_SetDriveMode(uint8 mode) ;
uint8   Data2_ReadDataReg(void) ;
uint8   Data2_Read(void) ;
uint8   Data2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Data2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Data2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Data2_DM_RES_UP          PIN_DM_RES_UP
#define Data2_DM_RES_DWN         PIN_DM_RES_DWN
#define Data2_DM_OD_LO           PIN_DM_OD_LO
#define Data2_DM_OD_HI           PIN_DM_OD_HI
#define Data2_DM_STRONG          PIN_DM_STRONG
#define Data2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Data2_MASK               Data2__MASK
#define Data2_SHIFT              Data2__SHIFT
#define Data2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Data2_PS                     (* (reg8 *) Data2__PS)
/* Data Register */
#define Data2_DR                     (* (reg8 *) Data2__DR)
/* Port Number */
#define Data2_PRT_NUM                (* (reg8 *) Data2__PRT) 
/* Connect to Analog Globals */                                                  
#define Data2_AG                     (* (reg8 *) Data2__AG)                       
/* Analog MUX bux enable */
#define Data2_AMUX                   (* (reg8 *) Data2__AMUX) 
/* Bidirectional Enable */                                                        
#define Data2_BIE                    (* (reg8 *) Data2__BIE)
/* Bit-mask for Aliased Register Access */
#define Data2_BIT_MASK               (* (reg8 *) Data2__BIT_MASK)
/* Bypass Enable */
#define Data2_BYP                    (* (reg8 *) Data2__BYP)
/* Port wide control signals */                                                   
#define Data2_CTL                    (* (reg8 *) Data2__CTL)
/* Drive Modes */
#define Data2_DM0                    (* (reg8 *) Data2__DM0) 
#define Data2_DM1                    (* (reg8 *) Data2__DM1)
#define Data2_DM2                    (* (reg8 *) Data2__DM2) 
/* Input Buffer Disable Override */
#define Data2_INP_DIS                (* (reg8 *) Data2__INP_DIS)
/* LCD Common or Segment Drive */
#define Data2_LCD_COM_SEG            (* (reg8 *) Data2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Data2_LCD_EN                 (* (reg8 *) Data2__LCD_EN)
/* Slew Rate Control */
#define Data2_SLW                    (* (reg8 *) Data2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Data2_PRTDSI__CAPS_SEL       (* (reg8 *) Data2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Data2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Data2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Data2_PRTDSI__OE_SEL0        (* (reg8 *) Data2__PRTDSI__OE_SEL0) 
#define Data2_PRTDSI__OE_SEL1        (* (reg8 *) Data2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Data2_PRTDSI__OUT_SEL0       (* (reg8 *) Data2__PRTDSI__OUT_SEL0) 
#define Data2_PRTDSI__OUT_SEL1       (* (reg8 *) Data2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Data2_PRTDSI__SYNC_OUT       (* (reg8 *) Data2__PRTDSI__SYNC_OUT) 


#if defined(Data2__INTSTAT)  /* Interrupt Registers */

    #define Data2_INTSTAT                (* (reg8 *) Data2__INTSTAT)
    #define Data2_SNAP                   (* (reg8 *) Data2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Data2_H */


/* [] END OF FILE */
