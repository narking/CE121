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
#include <stdio.h>

#define OVER 65000
#define UNDER 200
#define OVERCORRECT 64000
#define UNDERCORRECT 1000
#define AVG 5

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_DelSig_1_Start();
    PWM_1_Start();
    LCD_Char_1_Start();
    LCD_Char_1_DisplayOn();
    LCD_Char_1_Init();
    LCD_Char_1_Enable();
    LCD_Char_1_IsReady();
    LCD_Char_1_Position(0,0); 
    LCD_Char_1_PrintString("Hello World");
    
    
    uint16_t readADC = 0;  
    
    char print[12];
    sprintf(print,"readADC = %u", readADC);
    
    for(;;)
    {
             
        readADC = ADC_DelSig_1_Read16();
        
        if (readADC > OVER){
            readADC = UNDERCORRECT;
        } else if (readADC < UNDER) {
            readADC = OVERCORRECT;
        }       
        
        readADC = readADC/65;
        
        sprintf(print,"readADC = %u", readADC);
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_IsReady();
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString(print);
        PWM_1_WriteCompare(readADC);
    }
}

/* [] END OF FILE */
