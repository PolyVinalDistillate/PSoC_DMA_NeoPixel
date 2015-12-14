/*******************************************************************************
* File Name: Test.h  
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

#if !defined(CY_PINS_Test_H) /* Pins Test_H */
#define CY_PINS_Test_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Test_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Test__PORT == 15 && ((Test__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Test_Write(uint8 value) ;
void    Test_SetDriveMode(uint8 mode) ;
uint8   Test_ReadDataReg(void) ;
uint8   Test_Read(void) ;
uint8   Test_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Test_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Test_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Test_DM_RES_UP          PIN_DM_RES_UP
#define Test_DM_RES_DWN         PIN_DM_RES_DWN
#define Test_DM_OD_LO           PIN_DM_OD_LO
#define Test_DM_OD_HI           PIN_DM_OD_HI
#define Test_DM_STRONG          PIN_DM_STRONG
#define Test_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Test_MASK               Test__MASK
#define Test_SHIFT              Test__SHIFT
#define Test_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Test_PS                     (* (reg8 *) Test__PS)
/* Data Register */
#define Test_DR                     (* (reg8 *) Test__DR)
/* Port Number */
#define Test_PRT_NUM                (* (reg8 *) Test__PRT) 
/* Connect to Analog Globals */                                                  
#define Test_AG                     (* (reg8 *) Test__AG)                       
/* Analog MUX bux enable */
#define Test_AMUX                   (* (reg8 *) Test__AMUX) 
/* Bidirectional Enable */                                                        
#define Test_BIE                    (* (reg8 *) Test__BIE)
/* Bit-mask for Aliased Register Access */
#define Test_BIT_MASK               (* (reg8 *) Test__BIT_MASK)
/* Bypass Enable */
#define Test_BYP                    (* (reg8 *) Test__BYP)
/* Port wide control signals */                                                   
#define Test_CTL                    (* (reg8 *) Test__CTL)
/* Drive Modes */
#define Test_DM0                    (* (reg8 *) Test__DM0) 
#define Test_DM1                    (* (reg8 *) Test__DM1)
#define Test_DM2                    (* (reg8 *) Test__DM2) 
/* Input Buffer Disable Override */
#define Test_INP_DIS                (* (reg8 *) Test__INP_DIS)
/* LCD Common or Segment Drive */
#define Test_LCD_COM_SEG            (* (reg8 *) Test__LCD_COM_SEG)
/* Enable Segment LCD */
#define Test_LCD_EN                 (* (reg8 *) Test__LCD_EN)
/* Slew Rate Control */
#define Test_SLW                    (* (reg8 *) Test__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Test_PRTDSI__CAPS_SEL       (* (reg8 *) Test__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Test_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Test__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Test_PRTDSI__OE_SEL0        (* (reg8 *) Test__PRTDSI__OE_SEL0) 
#define Test_PRTDSI__OE_SEL1        (* (reg8 *) Test__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Test_PRTDSI__OUT_SEL0       (* (reg8 *) Test__PRTDSI__OUT_SEL0) 
#define Test_PRTDSI__OUT_SEL1       (* (reg8 *) Test__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Test_PRTDSI__SYNC_OUT       (* (reg8 *) Test__PRTDSI__SYNC_OUT) 


#if defined(Test__INTSTAT)  /* Interrupt Registers */

    #define Test_INTSTAT                (* (reg8 *) Test__INTSTAT)
    #define Test_SNAP                   (* (reg8 *) Test__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Test_H */


/* [] END OF FILE */
