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
#include <stdlib.h>
#define MAX_LEN 80
#define NUM_SLIDERS 5

char input[MAX_LEN + 1]; // +1 for null char
char volume_message[MAX_LEN + 1];

lv_obj_t *sliders[NUM_SLIDERS];
int values[NUM_SLIDERS] = {0};

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
    sliders[0] = ui_Slider1;
    sliders[1] = ui_Slider2;
    sliders[2] = ui_Slider3;
    sliders[3] = ui_Slider4;
    sliders[4] = ui_Slider5;

    while (1)
    {
        if (receive_until(input, '\n'))
        {
            lv_bar_set_value(ui_Bar1, atoi(strtok(input, "|")) * 29 / 100, LV_ANIM_OFF);
            lv_bar_set_value(ui_Bar2, atoi(strtok(NULL, "|")) * 29 / 100, LV_ANIM_OFF);
            lv_bar_set_value(ui_Bar3, atoi(strtok(NULL, "|")) * 29 / 100, LV_ANIM_OFF);
            lv_bar_set_value(ui_Bar4, atoi(strtok(NULL, "|")) * 29 / 100, LV_ANIM_OFF);
            lv_bar_set_value(ui_Bar5, atoi(strtok(NULL, "|")) * 29 / 100, LV_ANIM_OFF);
        }
        if (1)
        {
            int update = 0;
            for (int i = 0; i < NUM_SLIDERS; i++)
            {
                int val = lv_slider_get_value(sliders[i]);
                if (val != values[i])
                {
                    update = 1;
                    values[i] = val;
                }
            }
            if (update)
            {
                lv_snprintf(
                    volume_message,
                    sizeof(volume_message),
                    "%d|%d|%d|%d|%d\r\n",
                    (int)lv_slider_get_value(ui_Slider1),
                    (int)lv_slider_get_value(ui_Slider2),
                    (int)lv_slider_get_value(ui_Slider2),
                    (int)lv_slider_get_value(ui_Slider3),
                    (int)lv_slider_get_value(ui_Slider5));
            }

            send_str(volume_message);
        }
        lv_timer_handler();
    }
}
