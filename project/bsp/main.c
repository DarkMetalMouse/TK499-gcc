#include "HAL_conf.h"
#include "sys.h"
#include <stdint.h>

int main(void)
{
	u32 i;

	GPIO_InitTypeDef GPIO_InitStructure;
	RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_20); // Start PLL clock，12MHz*20=240MHz
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	// Configure LED GPIO pin
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	while (1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_8); // PA8 High - LED on
		for (i = 0; i < 2000000; i++)
			; // delay

		GPIO_ResetBits(GPIOA, GPIO_Pin_8); // PA8 Low - LED off
		for (i = 0; i < 2000000; i++)
			; // delay
	}
}
