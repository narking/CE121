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
#include "cyPm.h"

#define LED_CUTOFF 100

uint16_t timerGlobal = 0;
uint16_t intFlag = 0;

CY_ISR_PROTO(MyISR);
CY_ISR_PROTO(Snooze);

CY_ISR(MyISR)
{
 /* ISR Code here */
    timerGlobal = 65536 - Timer_1_ReadCounter();
    intFlag = 1;
}

CY_ISR(Snooze)
{
 /* ISR Code here */
        SleepTimer_1_GetStatus();

    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    isr_1_StartEx(MyISR);
    isr_2_StartEx(Snooze);
    SleepTimer_1_Start();
    isr_1_Enable();
    Timer_1_Start();
    Counter_1_Start();
    Counter_2_Start();
    LCD_Char_1_Start();
    LCD_Char_1_DisplayOn();
    LCD_Char_1_Init();
    LCD_Char_1_Enable();
    LCD_Char_1_IsReady();
    LCD_Char_1_Position(0,0); 
    
    //Initial reset to start counter
    Control_Reset_Write (1);  
    
    //Begin LED count down
    LED_Reset_Write (1); 
    
    char print[12];
    uint16_t distance = 0;
    int i = 0;
    
    //Write 1 to trigger, start 10 us count
    Control_Reg_1_Write (1);
    Control_Reset_Write (1); 

    // Print count and distance to LCD  
        sprintf(print,"Hello");           
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_IsReady();
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString(print);
    
    
    for(;;)
    {
        /* Place your application code here. */      
              
        
        uint8_t count = Counter_2_ReadCounter();
        
        if(intFlag == 1){
        
            i++;
            
            // Reset timer
            Control_Timer_Reset_Write (1); 
            intFlag = 0;
            
            // Calculate distance
            distance = timerGlobal/150;
            
            // Reset LED count if you're in the distance range
            if(distance < LED_CUTOFF){
                LED_Reset_Write (1); 
            }
            
            // Delay 500 milliseconds
            //CyDelay(500);
            
            // Print count and distance to LCD  
            sprintf(print,"Interrupt");           
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_IsReady();
            LCD_Char_1_Position(0,0);
            LCD_Char_1_PrintString(print);
            
            // Enter sleep mode for 512 ms
            Counter_1_Sleep();
            Counter_2_Sleep();
            Timer_1_Sleep();
            CyPmSaveClocks();
            CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_PICU);
            CyPmRestoreClocks();
            Counter_1_Wakeup();
            Counter_2_Wakeup();
            Timer_1_Wakeup(); 
            
            // Print count and distance to LCD  
            sprintf(print,"Wake");           
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_IsReady();
            LCD_Char_1_Position(0,0);
            LCD_Char_1_PrintString(print);
            
            // Write 1 to trigger, start 10 us count
            Control_Reg_1_Write (1);
            Control_Reset_Write (1);    
           
        }
        
        // Print count and distance to LCD  
        sprintf(print,"c = %u d = %u", count, distance);           
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_IsReady();
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString(print);
               
    }
}

/* [] END OF FILE */
