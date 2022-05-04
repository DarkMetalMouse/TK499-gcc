#include "HAL_conf.h"
#include "LCD.h"
#include "sys.h"
#include <stdint.h>

int main(void)
{
    RemapVtorTable();
    SystemClk_HSEInit(RCC_PLLMul_20); // Start PLL clock，12MHz*20=240MHz
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    LCD_Initial();
    Lcd_ColorBox(0, 0, XSIZE_PHYS, YSIZE_PHYS, Blue);
    Lcd_ColorBox(0, 0, 50, 50, Red);
    Lcd_ColorBox(100, 30, 20, 300, Green);

    while (1)
    {
    }
}
