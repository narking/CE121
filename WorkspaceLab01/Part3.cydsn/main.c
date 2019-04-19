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
    
    LCD_Char_1_Start();
    LCD_Char_1_DisplayOn();
    LCD_Char_1_Init();
    LCD_Char_1_Enable();
    LCD_Char_1_IsReady();
    LCD_Char_1_Position(0,0); 
    LCD_Char_1_PrintString("Hello World");
    

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
