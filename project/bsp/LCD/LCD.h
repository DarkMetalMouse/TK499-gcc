#include "HAL_conf.h"

#define XSIZE_PHYS 480
#define YSIZE_PHYS 854
extern __attribute__((aligned(256))) u32 LTDC_Buf[XSIZE_PHYS * YSIZE_PHYS];
#define LCD_SPI_CS(a)              \
	if (a)                         \
		GPIOB->BSRR = GPIO_Pin_11; \
	else                           \
		GPIOB->BRR = GPIO_Pin_11;
#define SPI_DCLK(a)               \
	if (a)                        \
		GPIOB->BSRR = GPIO_Pin_9; \
	else                          \
		GPIOB->BRR = GPIO_Pin_9;
#define SPI_SDA(a)                \
	if (a)                        \
		GPIOE->BSRR = GPIO_Pin_0; \
	else                          \
		GPIOE->BRR = GPIO_Pin_0;

#define LCD_RST(a)                \
	if (a)                        \
		GPIOD->BSRR = GPIO_Pin_6; \
	else                          \
		GPIOD->BRR = GPIO_Pin_6;

#define Lcd_Light_ON GPIOD->BSRR = GPIO_Pin_8 // PD8 is high, backlight is on
#define Lcd_Light_OFF GPIOD->BRR = GPIO_Pin_8 // PD8 is low, backlight is off

//************* 24bit color definition *************//
#define White 0xFFFFFF
#define Black 0x000000
#define Blue 0xFF0000
#define Blue2 0xFF3F3F
#define Red 0x0000FF
#define Magenta 0xFF00FF
#define Green 0x00FF00
#define Cyan 0xFFFF00
#define Yellow 0x00FFFF

void LCD_Initial(void);
void LCD_delay(volatile int time);
void WriteComm(unsigned char CMD);
void WriteData(u32 dat);
void LCD_WR_REG(u16 Index, u16 CongfigTemp);
void Lcd_ColorBox(u16 xStart, u16 yStart, u16 xLong, u16 yLong, u32 Color);
void DrawPixel(u16 x, u16 y, int Color);
// void SPILCD_DrawLine(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2,unsigned short color);
// void SPILCD_ShowChar(unsigned short x,unsigned short y,unsigned char num, unsigned int fColor, unsigned int bColor,unsigned char flag) ;
void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor, unsigned char draw_fg);
void LCD_Fill_Pic(u16 x, u16 y, u16 pic_H, u16 pic_V, u32 *pic);
