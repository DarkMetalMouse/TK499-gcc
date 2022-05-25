#include "HAL_conf.h"
#include "LCD.h"
#include "UART.h"
#include "sys.h"
#include "TK499_I2C.h"
#include "touch_CTP.h"
#include "timer.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"

// void my_log_cb(const char *buf)
// {
//     send_str((char *)buf);
// }

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RemapVtorTable();
    SystemClk_HSEInit(RCC_PLLMul_20); // Start PLL clock，12MHz*20=240MHz
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_Pin_8);

    UartInit(UART1, 115200);

    LCD_Initial();
    I2CInitMasterMode(I2C1);

    TIM3_Config(1000, 240); // 1mS

    lv_init();

    lv_port_disp_init();
    lv_port_indev_init();

    ui_init();

    while (1)
    {
        lv_timer_handler();
    }
}
