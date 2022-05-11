#include "HAL_conf.h"
#include "LCD.h"
#include "UART.h"
#include "sys.h"
#include "TK499_I2C.h"
#include "touch_CTP.h"

int main(void)
{
    volatile u32 i;
    GPIO_InitTypeDef GPIO_InitStructure;

    RemapVtorTable();
    SystemClk_HSEInit(RCC_PLLMul_20); // Start PLL clock，12MHz*20=240MHz
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    UartInit(UART1, 115200);
    send_str("Hello World");

    // send_str(" Welcome to use HJR TK499! \r\n");
    // putchar('A');

    LCD_Initial();
    I2CInitMasterMode(I2C1);

    Lcd_ColorBox(0, 0, XSIZE_PHYS, YSIZE_PHYS, Green);
    // Lcd_ColorBox(0, 0, 50, 50, Red);
    // Lcd_ColorBox(100, 30, 20, 300, Green);

    // LCD_DrawLine(20, 500, 320, 400, Black);

    while (1)
    {
        // fputc('A', stdout);
        send_data('A');
        // for (i = 0; i < 200000; i++)
        //     ;

        GPIO_SetBits(GPIOA, GPIO_Pin_8); // PA8 High - LED on
        // for (i = 0; i < 200000; i++)
        //     ;

        Touch_Test();
        GPIO_ResetBits(GPIOA, GPIO_Pin_8); // PA8 Low - LED off
        Touch_Test();
    }
}
