/*******************************************************************************
* File Name: ADC.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ADC_H) /* Pins ADC_H */
#define CY_PINS_ADC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADC__PORT == 15 && ((ADC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ADC_Write(uint8 value);
void    ADC_SetDriveMode(uint8 mode);
uint8   ADC_ReadDataReg(void);
uint8   ADC_Read(void);
void    ADC_SetInterruptMode(uint16 position, uint16 mode);
uint8   ADC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ADC_SetDriveMode() function.
     *  @{
     */
        #define ADC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ADC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ADC_DM_RES_UP          PIN_DM_RES_UP
        #define ADC_DM_RES_DWN         PIN_DM_RES_DWN
        #define ADC_DM_OD_LO           PIN_DM_OD_LO
        #define ADC_DM_OD_HI           PIN_DM_OD_HI
        #define ADC_DM_STRONG          PIN_DM_STRONG
        #define ADC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ADC_MASK               ADC__MASK
#define ADC_SHIFT              ADC__SHIFT
#define ADC_WIDTH              1u

/* Interrupt constants */
#if defined(ADC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ADC_SetInterruptMode() function.
     *  @{
     */
        #define ADC_INTR_NONE      (uint16)(0x0000u)
        #define ADC_INTR_RISING    (uint16)(0x0001u)
        #define ADC_INTR_FALLING   (uint16)(0x0002u)
        #define ADC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ADC_INTR_MASK      (0x01u) 
#endif /* (ADC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADC_PS                     (* (reg8 *) ADC__PS)
/* Data Register */
#define ADC_DR                     (* (reg8 *) ADC__DR)
/* Port Number */
#define ADC_PRT_NUM                (* (reg8 *) ADC__PRT) 
/* Connect to Analog Globals */                                                  
#define ADC_AG                     (* (reg8 *) ADC__AG)                       
/* Analog MUX bux enable */
#define ADC_AMUX                   (* (reg8 *) ADC__AMUX) 
/* Bidirectional Enable */                                                        
#define ADC_BIE                    (* (reg8 *) ADC__BIE)
/* Bit-mask for Aliased Register Access */
#define ADC_BIT_MASK               (* (reg8 *) ADC__BIT_MASK)
/* Bypass Enable */
#define ADC_BYP                    (* (reg8 *) ADC__BYP)
/* Port wide control signals */                                                   
#define ADC_CTL                    (* (reg8 *) ADC__CTL)
/* Drive Modes */
#define ADC_DM0                    (* (reg8 *) ADC__DM0) 
#define ADC_DM1                    (* (reg8 *) ADC__DM1)
#define ADC_DM2                    (* (reg8 *) ADC__DM2) 
/* Input Buffer Disable Override */
#define ADC_INP_DIS                (* (reg8 *) ADC__INP_DIS)
/* LCD Common or Segment Drive */
#define ADC_LCD_COM_SEG            (* (reg8 *) ADC__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADC_LCD_EN                 (* (reg8 *) ADC__LCD_EN)
/* Slew Rate Control */
#define ADC_SLW                    (* (reg8 *) ADC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADC_PRTDSI__CAPS_SEL       (* (reg8 *) ADC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADC_PRTDSI__OE_SEL0        (* (reg8 *) ADC__PRTDSI__OE_SEL0) 
#define ADC_PRTDSI__OE_SEL1        (* (reg8 *) ADC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADC_PRTDSI__OUT_SEL0       (* (reg8 *) ADC__PRTDSI__OUT_SEL0) 
#define ADC_PRTDSI__OUT_SEL1       (* (reg8 *) ADC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADC_PRTDSI__SYNC_OUT       (* (reg8 *) ADC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ADC__SIO_CFG)
    #define ADC_SIO_HYST_EN        (* (reg8 *) ADC__SIO_HYST_EN)
    #define ADC_SIO_REG_HIFREQ     (* (reg8 *) ADC__SIO_REG_HIFREQ)
    #define ADC_SIO_CFG            (* (reg8 *) ADC__SIO_CFG)
    #define ADC_SIO_DIFF           (* (reg8 *) ADC__SIO_DIFF)
#endif /* (ADC__SIO_CFG) */

/* Interrupt Registers */
#if defined(ADC__INTSTAT)
    #define ADC_INTSTAT            (* (reg8 *) ADC__INTSTAT)
    #define ADC_SNAP               (* (reg8 *) ADC__SNAP)
    
	#define ADC_0_INTTYPE_REG 		(* (reg8 *) ADC__0__INTTYPE)
#endif /* (ADC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADC_H */


/* [] END OF FILE */
