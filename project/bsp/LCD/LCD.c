#include "tk499.h"
#include "LCD.h"
#include "ASCII.h"
__attribute__((aligned(256))) u32 LTDC_Buf[XSIZE_PHYS * YSIZE_PHYS];

void LCD_delay(volatile int time)
{
	volatile u32 i;
	while (time--)
		for (i = 500; i > 0; i--)
			;
}
void LTDC_Clock_Set(void)
{
	RCC->AHB1ENR |= ((uint32_t)1) << 31;
	RCC->CR |= 1 << 28;
	RCC->PLLDCKCFGR = 0x1 << 16; // Frequency division factor 0~3 --> 2,4,6,8
	RCC->PLLLCDCFGR = 7 << 6;	 // Frequency multiplication factor
}

static void LCD_Reset(void)
{
	LCD_RST(0);
	LCD_delay(10);
	LCD_RST(1);
	LCD_delay(10);
}
void LCD_WriteByteSPI(unsigned char byte)
{
	unsigned char n;

	for (n = 0; n < 8; n++)
	{
		if (byte & 0x80)
			SPI_SDA(1)
		else
			SPI_SDA(0)
		byte <<= 1;
		LCD_delay(1);
		SPI_DCLK(0);
		LCD_delay(1);
		SPI_DCLK(1);
	}
}
void SPI_WriteComm(u16 CMD) // 3wire 9 Bits
{
	LCD_SPI_CS(0);
	LCD_delay(1);
	SPI_SDA(0);
	LCD_delay(1);
	SPI_DCLK(0);
	LCD_delay(1);
	SPI_DCLK(1);
	LCD_delay(1);
	LCD_WriteByteSPI(CMD);
	LCD_delay(1);
	LCD_SPI_CS(1);
	LCD_delay(1);
}
void SPI_WriteData(u16 tem_data)
{
	LCD_SPI_CS(0);
	LCD_delay(1);
	SPI_SDA(1);
	LCD_delay(1);
	SPI_DCLK(0);
	LCD_delay(1);
	SPI_DCLK(1);
	LCD_delay(1);
	LCD_WriteByteSPI(tem_data);
	LCD_delay(1);
	LCD_SPI_CS(1);
	LCD_delay(1);
}
void Lcd_Initialize(void)
{

	LCD_Reset();

	//****************************************************************************//
	//****************************** Page 1 Command ******************************//
	//****************************************************************************//
	SPI_WriteComm(0xFF); // Change to Page 1
	SPI_WriteData(0xFF);
	SPI_WriteData(0x98);
	SPI_WriteData(0x06);
	SPI_WriteData(0x04);
	SPI_WriteData(0x01);

	SPI_WriteComm(0X08);
	SPI_WriteData(0X10); // output SDA

	SPI_WriteComm(0X21);
	SPI_WriteData(0X01); // DE = 1 Active

	SPI_WriteComm(0X30);
	SPI_WriteData(0X01); // 480 X 854

	SPI_WriteComm(0X31);
	SPI_WriteData(0X02); // 2-dot Inversion

	SPI_WriteComm(0X40);
	SPI_WriteData(0X18); // DDVDH/L BT 17 -10 5.94 -5.47 -2.3 1.6 43.4 21.88 0.17

	SPI_WriteComm(0X41);
	SPI_WriteData(0X66); // DDVDH/L CLAMP

	SPI_WriteComm(0X42);
	SPI_WriteData(0X02); // VGH/VGL

	SPI_WriteComm(0X43);
	SPI_WriteData(0X0A); // VGH/VGL

	SPI_WriteComm(0X50);
	SPI_WriteData(0X78); // VGMP 4.6

	SPI_WriteComm(0X51);
	SPI_WriteData(0X78); // VGMN 4.6

	SPI_WriteComm(0X52);
	SPI_WriteData(0X00); // Flicker

	SPI_WriteComm(0X53);
	SPI_WriteData(0X1F); // Flicker

	SPI_WriteComm(0X57);
	SPI_WriteData(0X50);

	SPI_WriteComm(0X60);
	SPI_WriteData(0X07); // SDTI

	SPI_WriteComm(0X61);
	SPI_WriteData(0X01); // CRTI 00

	SPI_WriteComm(0X62);
	SPI_WriteData(0X07); // EQTI 07

	SPI_WriteComm(0X63);
	SPI_WriteData(0X00); // PCTI  00

	////++++++++++++++++++ Gamma Setting ++++++++++++++++++//
	// SPI_WriteComm(0xFF); // Change to Page 1
	// SPI_WriteData(0xFF);
	// SPI_WriteData(0x98);
	// SPI_WriteData(0x06);
	// SPI_WriteData(0x04);
	// SPI_WriteData(0x01);

	SPI_WriteComm(0XA0);
	SPI_WriteData(0X00); // Gamma 0

	SPI_WriteComm(0XA1);
	SPI_WriteData(0X0A); // Gamma 4

	SPI_WriteComm(0XA2);
	SPI_WriteData(0X12); // Gamma 8

	SPI_WriteComm(0XA3);
	SPI_WriteData(0X0D); // Gamma 16

	SPI_WriteComm(0XA4);
	SPI_WriteData(0X07); // Gamma 24

	SPI_WriteComm(0XA5);
	SPI_WriteData(0X09); // Gamma 52

	SPI_WriteComm(0XA6);
	SPI_WriteData(0X06); // Gamma 80

	SPI_WriteComm(0XA7);
	SPI_WriteData(0X03); // Gamma 108

	SPI_WriteComm(0XA8);
	SPI_WriteData(0X09); // Gamma 147

	SPI_WriteComm(0XA9);
	SPI_WriteData(0X0D); // Gamma 175

	SPI_WriteComm(0XAA);
	SPI_WriteData(0X15); // Gamma 203

	SPI_WriteComm(0XAB);
	SPI_WriteData(0X07); // Gamma 231

	SPI_WriteComm(0XAC);
	SPI_WriteData(0X0D); // Gamma 239

	SPI_WriteComm(0XAD);
	SPI_WriteData(0X0D); // Gamma 247

	SPI_WriteComm(0XAE);
	SPI_WriteData(0X06); // Gamma 251

	SPI_WriteComm(0XAF);
	SPI_WriteData(0X00); // Gamma 255

	///==============Nagitive
	SPI_WriteComm(0XC0);
	SPI_WriteData(0X00); // Gamma 0

	SPI_WriteComm(0XC1);
	SPI_WriteData(0X0A); // Gamma 4

	SPI_WriteComm(0XC2);
	SPI_WriteData(0X12); // Gamma 8

	SPI_WriteComm(0XC3);
	SPI_WriteData(0X0E); // Gamma 16

	SPI_WriteComm(0XC4);
	SPI_WriteData(0X07); // Gamma 24

	SPI_WriteComm(0XC5);
	SPI_WriteData(0X09); // Gamma 52

	SPI_WriteComm(0XC6);
	SPI_WriteData(0X07); // Gamma 80

	SPI_WriteComm(0XC7);
	SPI_WriteData(0X03); // Gamma 108

	SPI_WriteComm(0XC8);
	SPI_WriteData(0X09); // Gamma 147

	SPI_WriteComm(0XC9);
	SPI_WriteData(0X0C); // Gamma 175

	SPI_WriteComm(0XCA);
	SPI_WriteData(0X15); // Gamma 203

	SPI_WriteComm(0XCB);
	SPI_WriteData(0X07); // Gamma 231

	SPI_WriteComm(0XCC);
	SPI_WriteData(0X0C); // Gamma 239

	SPI_WriteComm(0XCD);
	SPI_WriteData(0X0D); // Gamma 247

	SPI_WriteComm(0XCE);
	SPI_WriteData(0X06); // Gamma 251

	SPI_WriteComm(0XCF);
	SPI_WriteData(0X00); // Gamma 255

	//****************************************************************************//
	//****************************** Page 6 Command ******************************//
	//****************************************************************************//
	SPI_WriteComm(0xFF); // Change to Page 6
	SPI_WriteData(0xFF);
	SPI_WriteData(0x98);
	SPI_WriteData(0x06);
	SPI_WriteData(0x04);
	SPI_WriteData(0x06);

	SPI_WriteComm(0X00);
	SPI_WriteData(0X21);

	SPI_WriteComm(0X01);
	SPI_WriteData(0X06);

	SPI_WriteComm(0X02);
	SPI_WriteData(0XA0);

	SPI_WriteComm(0X03);
	SPI_WriteData(0X02);

	SPI_WriteComm(0X04);
	SPI_WriteData(0X01);

	SPI_WriteComm(0X05);
	SPI_WriteData(0X01);

	SPI_WriteComm(0X06);
	SPI_WriteData(0X80);

	SPI_WriteComm(0X07);
	SPI_WriteData(0X04);

	SPI_WriteComm(0X08);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X09);
	SPI_WriteData(0X80);

	SPI_WriteComm(0X0A);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X0B);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X0C);
	SPI_WriteData(0X2c);

	SPI_WriteComm(0X0D);
	SPI_WriteData(0X2c);

	SPI_WriteComm(0X0E);
	SPI_WriteData(0X1c);

	SPI_WriteComm(0X0F);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X10);
	SPI_WriteData(0XFF);

	SPI_WriteComm(0X11);
	SPI_WriteData(0XF0);

	SPI_WriteComm(0X12);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X13);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X14);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X15);
	SPI_WriteData(0XC0);

	SPI_WriteComm(0X16);
	SPI_WriteData(0X08);

	SPI_WriteComm(0X17);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X18);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X19);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X1A);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X1B);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X1C);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X1D);
	SPI_WriteData(0X00);

	SPI_WriteComm(0X20);
	SPI_WriteData(0X01);

	SPI_WriteComm(0X21);
	SPI_WriteData(0X23);

	SPI_WriteComm(0X22);
	SPI_WriteData(0X45);

	SPI_WriteComm(0X23);
	SPI_WriteData(0X67);

	SPI_WriteComm(0X24);
	SPI_WriteData(0X01);

	SPI_WriteComm(0X25);
	SPI_WriteData(0X23);

	SPI_WriteComm(0X26);
	SPI_WriteData(0X45);

	SPI_WriteComm(0X27);
	SPI_WriteData(0X67);

	SPI_WriteComm(0X30);
	SPI_WriteData(0X12);

	SPI_WriteComm(0X31);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X32);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X33);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X34);
	SPI_WriteData(0X87);

	SPI_WriteComm(0X35);
	SPI_WriteData(0X96);

	SPI_WriteComm(0X36);
	SPI_WriteData(0XAA);

	SPI_WriteComm(0X37);
	SPI_WriteData(0XDB);

	SPI_WriteComm(0X38);
	SPI_WriteData(0XCC);

	SPI_WriteComm(0X39);
	SPI_WriteData(0XBD);

	SPI_WriteComm(0X3A);
	SPI_WriteData(0X78);

	SPI_WriteComm(0X3B);
	SPI_WriteData(0X69);

	SPI_WriteComm(0X3C);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X3D);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X3E);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X3F);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X40);
	SPI_WriteData(0X22);

	SPI_WriteComm(0X52);
	SPI_WriteData(0X10);

	SPI_WriteComm(0X53);
	SPI_WriteData(0X10);

	// SPI_WriteComm(0xFF); // Change to Page 7
	// SPI_WriteData(0xFF);
	// SPI_WriteData(0x98);
	// SPI_WriteData(0x06);
	// SPI_WriteData(0x04);
	// SPI_WriteData(0x07);

	////SPI_WriteComm(0X17);SPI_WriteData(0X22);

	// SPI_WriteComm(0X18);SPI_WriteData(0X1D);

	////SPI_WriteComm(0X02);SPI_WriteData(0X77);

	////SPI_WriteComm(0XE1);SPI_WriteData(0X79);

	////SPI_WriteComm(0X06);SPI_WriteData(0X01);

	//****************************************************************************//
	SPI_WriteComm(0xFF); // Change to Page 0
	SPI_WriteData(0xFF);
	SPI_WriteData(0x98);
	SPI_WriteData(0x06);
	SPI_WriteData(0x04);
	SPI_WriteData(0x00);

	SPI_WriteComm(0X36);
	SPI_WriteData(0X08);
	SPI_WriteComm(0X3A);
	SPI_WriteData(0X77);

	SPI_WriteComm(0X11); // Sleep-Out
	LCD_delay(120);
	SPI_WriteComm(0X29); // Display On
}

void GPIO_RGB_INIT(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOD | RCC_AHBPeriph_GPIOE, ENABLE);

	// DE=PB4, PCLK=PB5, HSYNC=PB6, VSYNC=PB7
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//                            SPI_DCLK     LCD_SPI_CS
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // SPI_SDA
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	// lcd_reset=PD6      LCD_Black_Light On Off=PD8
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	Lcd_Initialize();

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_AF_LTDC); // PB4~7 are multiplexed as the synchronization signal line of LTDC
	GPIO_PinAFConfig(GPIOE, GPIO_Pin_All, GPIO_AF_LTDC);									  // GPIOE is multiplexed used as LTDC data lines
}

void set_resolutionXX(LCD_FORM_TypeDef *LCD_FORM)
{
	u32 aHorStart;
	u32 aHorEnd;
	u32 aVerStart;
	u32 aVerEnd;

	aHorStart = LCD_FORM->blkHorEnd + 1;
	aHorEnd = aHorStart + LCD_FORM->aHorLen;
	aVerStart = LCD_FORM->blkVerEnd + 1;
	aVerEnd = aVerStart + LCD_FORM->aVerLen;

	LTDC->P_HOR = aHorEnd;											   // Total width
	LTDC->HSYNC = (LCD_FORM->sHsyncStart << 16) | LCD_FORM->sHsyncEnd; // Start and end of hsync
	LTDC->A_HOR = (aHorStart << 16) | aHorEnd;						   // horizontal activation start and end
	LTDC->A_HOR_LEN = LCD_FORM->aHorLen;							   // horizontal activation length
	LTDC->BLK_HOR = (0 << 16) | LCD_FORM->blkHorEnd;				   // Background start and end width 0 ~ activation address
	LTDC->P_VER = aVerEnd;
	LTDC->VSYNC = (LCD_FORM->sVsyncStart << 16) | LCD_FORM->sVsyncEnd;
	LTDC->A_VER = (aVerStart << 16) | aVerEnd;
	LTDC->A_VER_LEN = LCD_FORM->aVerLen;
	LTDC->BLK_VER = (0 << 16) | LCD_FORM->blkVerEnd;
}

void Set_LCD_Timing_to_LTDC(void)
{
	LCD_FORM_TypeDef LCD_FORM;
	LTDC->OUT_EN = 0;
	LTDC->DP_ADDR0 = (u32)LTDC_Buf; // Layer 0 buffer
	// LTDC->DP_ADDR1 = (u32)(LTDC_Buf + SDRAM_RGB_OFFSET);//layer 1 buffer
	LTDC->BLK_DATA = 0x0000; // Background color

	//===============5 inch 854*480===============//
	LCD_FORM.sHsyncStart = 0x2;
	LCD_FORM.sHsyncEnd = 0x3;
	LCD_FORM.aHorLen = 480 - 1; // horizontal resolution
	LCD_FORM.blkHorEnd = 0x3f;	// horizontal blanking

	LCD_FORM.sVsyncStart = 0x2;
	LCD_FORM.sVsyncEnd = 0x3;
	LCD_FORM.aVerLen = 854 - 1; // vertical resolution
	LCD_FORM.blkVerEnd = 0xf;	// vertical blanking

	set_resolutionXX(&LCD_FORM);

	LTDC->VI_FORMAT = 0;
	LTDC->POL_CTL = 0x8 + 3;
	LTDC->OUT_EN |= 0x107;
}
void LTDC_IRQHandler(void)
{
	LTDC->INTR_CLR = 2;
	LTDC->DP_SWT ^= 1; // Display two pictures in a row
	if (LTDC->DP_SWT != 0)
	{
		//        fun_test(SDRAM_RGB_ADD);
	}
	else
	{
		//        fun_test(SDRAM_RGB_ADD+SDRAM_RGB_OFFSET);
	}
	//    if(LTDC->INTR_STA & 2)
	//    {

	//    }
}
/**********************************************
Function name: Lcd rectangle filling function

Entry parameter: xStart starting point in the x direction
ySrart y-direction end point
xLong the x-direction length of the selected rectangle
yLong The y-direction length of the rectangle to be selected
Return value: none
***********************************************/
/**
 * @brief Fill a recrangle on the screen
 *
 * @param xStart top left corner x
 * @param yStart top left cornery
 * @param xLong vertial size
 * @param yLong horizontal size
 * @param Color color encoded as 00BBGGRR
 */
void Lcd_ColorBox(u16 xStart, u16 yStart, u16 xLong, u16 yLong, u32 Color)
{
	u16 i, j;
	u32 temp;
	temp = XSIZE_PHYS * yStart;
	for (i = 0; i < yLong; i++)
	{
		for (j = 0; j < xLong; j++)
			LTDC_Buf[xStart + j + XSIZE_PHYS * i + temp] = Color;
	}
}
/**
 * @brief Initialize LCD
 */
void LCD_Initial(void)
{
	GPIO_RGB_INIT(); // Initialize LCD related GPIO
	LTDC_Clock_Set();
	Set_LCD_Timing_to_LTDC();
	Lcd_Light_ON; // Turn backlight on
}
/******************************************
Function name: Lcd image fill 100*100
Function: Fill the image to the specified position of Lcd
Entry parameters:
******************************************/

/**
 * @brief Draw image on screen
 *
 * @param x top left corner x
 * @param y top left corner y
 * @param pic_H image height
 * @param pic_V image width
 * @param pic image array {00BBGGRR, 00BBGGRR, 00BBGGRR, ...}
 */
void LCD_Fill_Pic(u16 x, u16 y, u16 pic_H, u16 pic_V, u32 *pic)
{
	// Draw portrait
	//	u16 i,j;
	//	u32 Xstart,k=0;
	//	Xstart = XSIZE_PHYS*x;
	//	for(i=pic_V;i>0;i--)
	//	{
	//		for(j=0;j<pic_H;j++)
	//		LTDC_Buf[Xstart+i+XSIZE_PHYS*j+y]=pic[k++];
	//	}

	// Draw landscape
	u16 i, j;
	u32 Ystart, k = 0;
	Ystart = XSIZE_PHYS * y;
	for (i = 0; i < pic_V; i++)
	{
		for (j = 0; j < pic_H; j++)
			LTDC_Buf[x + j + XSIZE_PHYS * i + Ystart] = pic[k++];
	}
}

void DrawPixel(u16 x, u16 y, int Color)
{

	LTDC_Buf[x + XSIZE_PHYS * y] = Color;
}
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
// 8*16 font ASCII code display
// Function name: SPILCD_ShowChar
// Parameters:
//(x,y):
// num: Characters to be displayed: " "--->"~"
// flag: with background color (1) without background color (0)

/**
 * @brief dispaly 8*16 ASCII character
 *
 * @param x top left corner x
 * @param y top left corner y
 * @param num the character to display
 * @param fColor forground color
 * @param bColor background color
 * @param draw_fg whether to g
 */
void SPILCD_ShowChar(unsigned short x, unsigned short y, unsigned char num, unsigned int fColor, unsigned int bColor, unsigned char fill_bg)
{
	unsigned char temp;
	unsigned int pos, i, j;

	num = num - ' '; // Get array index
	i = num * 16;
	for (pos = 0; pos < 16; pos++)
	{
		temp = nAsciiDot[i + pos]; // Get ASCII char line
		for (j = 0; j < 8; j++)
		{
			if (temp & 0x80)
				DrawPixel(x + j, y, fColor);
			else if (fill_bg)
				DrawPixel(x + j, y, bColor); // draw the background color if the fill_bg flag is true
			temp <<= 1;
		}
		y++;
	}
}

/**
 * @brief display a string on the screen
 *
 * @param x top left corner x
 * @param y top left corner y
 * @param s the string to display
 * @param fColor forground color
 * @param bColor background color
 * @param draw_fg whether to g
 */
void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor, unsigned char fill_bg)
{
	unsigned char l = 0;
	while (*s) // until null char
	{
		SPILCD_ShowChar(x + l * 8, y, *s, fColor, bColor, fill_bg);
		s++;
		l++;
	}
}
