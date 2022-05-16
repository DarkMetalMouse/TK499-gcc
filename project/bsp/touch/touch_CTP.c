
//#ifdef  use_capacitive_touch_panel
#include "touch_CTP.h"
#include "HAL_rcc.h"
#include "LCD.h"
#include "touch_CTP.h"
#include "UART.h"
#if USE_CTP

volatile u16 lastX = UINT16_MAX, lastY = UINT16_MAX;
u8 buf[10];
char string[32];
volatile int GUI_Value_X, GUI_Value_Y;
volatile unsigned char touchInfo_flag;
void GUI_TOUCH_Measure(void)
{
	int i;
	I2CTXByte(I2C1, CMD_WRITE, 0x01);

	for (i = 0; i < 6; i++)
	{
		*(buf + i) = I2CRXByte(I2C1); //库函数法读取IIC数据
	}
	if ((buf[1] & 0x0f) == 1)
	{

		GUI_Value_X = 480 - 1 - ((int16_t)(buf[4] & 0x0F) << 8 | (int16_t)buf[5]);
		if (GUI_Value_X < 0)
			GUI_Value_X = 0;
		GUI_Value_Y = (int16_t)(buf[2] & 0x0F) << 8 | (int16_t)buf[3];
		touchInfo_flag = 1; //触摸有效
	}
	else
	{
		touchInfo_flag = 0;
		GUI_Value_X = UINT16_MAX;
		GUI_Value_Y = UINT16_MAX;
	}
}

/****************************************************************************************
																	电容屏 FTXXXX全系列通用芯片驱动

***************************************************************************************/
void Touch_Test(void)
{
	char i, j;
	u8 buf[32];
	u16 touchX = 0, touchY = 0;
	//	I2C1->IC_DATA_CMD =FT6206_ADDR | 0x200;//写入从机地址，开启起始信号
	I2CTXByte(I2C1, CMD_WRITE, 0x01);
	for (i = 0; i < 6; i++)
	{
		*(buf + i) = I2CRXByte(I2C1); //库函数法读取IIC数据
	}
	j = buf[1] & 0x0f;
	if (j > 5)
		return;
	for (i = 6; i < 6 * j; i++)
	{
		*(buf + i) = I2CRXByte(I2C1); //库函数法读取IIC数据
	}
	if (j == 0)
	{
		lastX = UINT16_MAX;
		lastY = UINT16_MAX;
	}
	else if (j > 1)
	{
		Lcd_ColorBox(0, 0, XSIZE_PHYS, YSIZE_PHYS, Blue);
	}
	for (i = 0; i < j; i++)
	{

		touchX = 480 - ((int16_t)(buf[4 + 6 * i] & 0x0F) << 8 | (int16_t)buf[5 + 6 * i]); // x坐标
		touchY = (int16_t)(buf[2 + 6 * i] & 0x0F) << 8 | (int16_t)buf[3 + 6 * i];		  // y坐标

		if ((touchX > 0) && (touchX < 2048))
		{
			if (lastX == UINT16_MAX)
			{
				lastX = touchX;
				lastY = touchY;
			}
			if (i > 2)
				LCD_DrawLine(lastX, lastY, touchX, touchY, Yellow >> (8 * (i - 3)));
			else
				LCD_DrawLine(lastX, lastY, touchX, touchY, Red >> (8 * i));
			lastX = touchX;
			lastY = touchY;

			sprintf(string, "X = %03d\r\n", touchX);
			LCD_PutString(10, 10, string, 0, Blue, 1);
			send_str(string);

			sprintf(string, "Y = %03d\r\n", touchY);
			LCD_PutString(10, 36, string, 0, Blue, 1);
			send_str(string);
		}
	}
}
#endif