/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    
    for(;;)
    {
        
        /* Place your application code here. */
        
        /* PER-PIN SETING */
        /*
        // Set all three pins
        CyPins_SetPin(CYREG_PRT1_PC6);
        CyPins_SetPin(CYREG_PRT1_PC7);
        CyPins_SetPin(CYREG_PRT2_PC0);
        
        CyDelay(200u);
        
        // Clear all three pins
        CyPins_ClearPin(CYREG_PRT1_PC6);
        CyPins_ClearPin(CYREG_PRT1_PC7);
        CyPins_ClearPin(CYREG_PRT2_PC0);
        
        CyDelay(200u);
        */
        
        
        /* COMPONENT API SETING */
        ///*
        // Set all three pins
        Red_Write(1);
        Green_Write(1);
        Blue_Write(1);
        
        CyDelay(200u);
        
        Red_Write(0);
        Green_Write(0);
        Blue_Write(0);
        
        CyDelay(200u);
        //*/
        
        
        
    }
}

/* [] END OF FILE */
