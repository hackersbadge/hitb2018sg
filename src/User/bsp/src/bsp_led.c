/*
*********************************************************************************************************
*
*	模块名称 : LED指示灯驱动模块
*	文件名称 : bsp_led.c
*	版    本 : V1.0
*	说    明 : 驱动LED指示灯
*
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2013-02-01   正式发布
*
*	Copyright (C), 2013-2014,  
*
*********************************************************************************************************
*/

#include "bsp.h"

uint16_t PixelBuffer[256] = {0};
uint16_t PixelPointer = 0;
uint8_t brightness = 0;

uint32_t ws2812_temp[6] = { 0x000000,0x000000,0x000000,
						  0x000000,0x000000,0x000000 };

#if defined RGBW
const uint8_t LEDGamma[] = {
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
	2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
	5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

#endif

void LED_SPI_LowLevel_Init(void)
{
    uint16_t i = 0;

    GPIO_InitTypeDef  GPIO_InitStructure;
    SPI_InitTypeDef   SPI_InitStructure;
    DMA_InitTypeDef   DMA_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

    DMA_DeInit(DMA1_Channel5);
    DMA_InitStructure.DMA_BufferSize = 0;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) & (SPI2->DR);
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)PixelBuffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Low;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_Init(DMA1_Channel5, &DMA_InitStructure); /* DMA1 CH3 = MEM -> DR */

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    SPI_I2S_DeInit(SPI2);

    SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4; /* 48MHz / 8 = 6MHz */
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial = 7;
    SPI_Init(SPI2, &SPI_InitStructure);

    SPI_I2S_DMACmd(SPI2, SPI_I2S_DMAReq_Tx, ENABLE);

    SPI_Cmd(SPI2, ENABLE);

    for (i = 0; i < 256; i++)
    {
        PixelBuffer[i] = 0xAAAA;
    }

    PixelPointer = 0;
	//brightness = 0;
	//numLEDs = 6;
//	ws2812_clear();
}

void LED_SPI_WriteByte(uint16_t Data)
{
    /* Wait until the transmit buffer is empty */
    /*
    while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET)
    {
    }
    */

    PixelBuffer[PixelPointer] = Data;
    PixelPointer++;

    /* Send the byte */
    /* SPI_I2S_SendData16(SPI2, Data); */
}

void LED_SPI_SendBits(uint8_t bits)
{
    int zero = 0x7000;  //11100000000000
    int one = 0x7F00;  //111111100000000
    int i = 0x00;

    for (i = 0x80; i >= 0x01; i >>= 1)
    {
        LED_SPI_WriteByte((bits & i) ? one : zero);
    }
}

void LED_SPI_SendPixel(uint32_t color)
{
    /*
     r7,r6,r5,r4,r3,r2,r1,r0,g7,g6,g5,g4,g3,g2,g1,g0,b7,b6,b5,b4,b3,b2,b1,b0
     \_____________________________________________________________________/
                               |      _________________...
                               |     /   __________________...
                               |    /   /   ___________________...
                               |   /   /   /
                              RGB,RGB,RGB,RGB,...,STOP
    */

    /*
    	BUG Fix : Actual is GRB,datasheet is something wrong.
    */
	  uint8_t Red, Green, Blue;  // 三原色
		// 绿 红 蓝 三原色分解
	  Red   = color>>8;
	  Green = color>>16;
	  Blue  = color;
    LED_SPI_SendBits(Green);
    LED_SPI_SendBits(Red);
    LED_SPI_SendBits(Blue);
}

void LED_SPI_Update(uint32_t buffer[], uint32_t length)
{
    uint8_t i = 0;
    uint8_t m = 0;
    if(DMA_GetCurrDataCounter(DMA1_Channel5) == 0)
    {

        for (i = 0; i < length; i++)
        {
            LED_SPI_SendPixel(buffer[i]);
        }

        if(length < 6)
        {
            for(i = 6 - length; i < length; i++)
            {
                for(m = 0; m < 3; m++)
                {
                    LED_SPI_SendBits(0x00);
                }
            }
        }

        for (i = 0; i < 20; i++)   
        {
            LED_SPI_WriteByte(0x00);
        }

        PixelPointer = 0;

        DMA_Cmd(DMA1_Channel5, DISABLE);
        DMA_ClearFlag(DMA1_FLAG_TC5);
        DMA_SetCurrDataCounter(DMA1_Channel5, 24*length+20);
        DMA_Cmd(DMA1_Channel5, ENABLE);
    }
}

void ws2812_clear(void)
{
	u8 i = 0;
	for (i = 0; i < 6; i++)
	{
		ws2812_temp[i] = 0x000000;
	}
	LED_SPI_Update(ws2812_temp, 6);
}

void ws2812_colorWipe(uint32_t c, uint16_t wait)
{
	u8 i = 0;
	for (i = 0; i < 6; i++)
	{
		ws2812_setPixelColor(i, c);
		LED_SPI_Update(ws2812_temp, 6);
		bsp_DelayMS(wait);
	}
}

void ws2812_setPixelColor_RGB(u8 i, uint8_t r, uint8_t g, uint8_t b)
{
	ws2812_temp[i] = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

void ws2812_setPixelColor(u8 i, u32 c)
{
	uint8_t r, g, b;

	if (brightness)
	{
		r = ((int)((uint8_t)(c >> 16)) * (int)brightness) >> 8;
		g = ((int)((uint8_t)(c >> 8)) * (int)brightness) >> 8;
		b = ((int)((uint8_t)c) * (int)brightness) >> 8;
		ws2812_temp[i] = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
	}
	else
	{
		ws2812_temp[i] = c;
	}
}

void ws2812_rainbow(uint16_t wait)
{
	uint16_t i, j;

	for (j = 0; j < 256; j++) 
	{
		for (i = 0; i < 6; i++)
		{
			ws2812_setPixelColor(i, ws2812_wheel((i + j) & 255));
		}
		LED_SPI_Update(ws2812_temp, 6);
		bsp_DelayMS(wait);
	}
}

// Slightly different, this makes the rainbow equally distributed throughout
void ws2812_rainbowCycle(uint16_t wait)
{
	uint16_t i, j;

	for (j = 0; j < 256 * 5; j++)
	{ // 5 cycles of all colors on wheel
		for (i = 0; i < 6; i++)
		{
			ws2812_setPixelColor(i, ws2812_wheel(((i * 256 / 6) + j) & 255));
		}
		LED_SPI_Update(ws2812_temp, 6);
		bsp_DelayMS(wait);
	}
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t ws2812_wheel(int16_t WheelPos)
{
	if (WheelPos < 85)
	{
		return ws2812_RGB_Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	}
	else
	{
		if (WheelPos < 170)
		{
			WheelPos -= 85;
			return ws2812_RGB_Color(255 - WheelPos * 3, 0, WheelPos * 3);
		}
		else
		{
			WheelPos -= 170;
			return ws2812_RGB_Color(0, WheelPos * 3, 255 - WheelPos * 3);
		}
	}
}

// Convert separate R,G,B into packed 32-bit RGB color.
// Packed format is always RGB, regardless of LED strand color order.
uint32_t ws2812_RGB_Color(uint8_t r, uint8_t g, uint8_t b) 
{
	return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

void ws2812_setBrightness(uint8_t b) 
{
	brightness = b;
}



//Theatre-style crawling lights.
void ws2812_theaterChase(uint32_t c, uint16_t wait)
{
	u8 i, j, q;

	for (j = 0; j < 10; j++) {  //do 10 cycles of chasing
		for (q = 0; q < 3; q++) {
			for (i = 0; i < 6; i = i + 3) {
				ws2812_setPixelColor(i + q, c);    //turn every third pixel on
			}
			LED_SPI_Update(ws2812_temp, 6);

			bsp_DelayMS(wait);

			for (i = 0; i < 6; i = i + 3) {
				ws2812_setPixelColor(i + q, 0);        //turn every third pixel off
			}
		}
	}
}

//Theatre-style crawling lights with rainbow effect
void ws2812_theaterChaseRainbow(uint16_t wait)
{
	u16 j;
	u8 i, q;
	for (j = 0; j < 256; j++) 
	{     // cycle all 256 colors in the wheel
		for (q = 0; q < 3; q++) 
		{
			for (i = 0; i < 6; i = i + 3) 
			{
				ws2812_setPixelColor(i + q, ws2812_wheel((i + j) % 255));    //turn every third pixel on
			}
			LED_SPI_Update(ws2812_temp, 6);

			bsp_DelayMS(wait);

			for (i = 0; i < 6; i = i + 3) 
			{
				ws2812_setPixelColor(i + q, 0);        //turn every third pixel off
			}
		}
	}
}


void ws2812_whiteOverRainbow(uint16_t wait, uint8_t whiteSpeed, uint8_t whiteLength)
{

	int16_t j;
	u8 i;
	int head;
	int tail = 0;
	int loops = 3;
	int loopNum = 0;
	static unsigned long lastTime = 0;

	if (whiteLength >= 6) whiteLength = 6 - 1;
	head = whiteLength - 1;

	while (TRUE)
	{
		for (j = 0; j < 256; j++)
		{
			for (i = 0; i < 6; i++)
			{
				if ((i >= tail && i <= head) || (tail > head && i >= tail) || (tail > head && i <= head))
				{
					ws2812_setPixelColor(i, ws2812_RGB_Color(255, 255, 255));
				}
				else {
					ws2812_setPixelColor(i, ws2812_wheel(((i * 256 / 6) + j) & 255));
				}

			}

			if (bsp_GetRunTime() - lastTime > whiteSpeed)
			{
				head++;
				tail++;
				if (head == 6)
				{
					loopNum++;
				}
				lastTime = bsp_GetRunTime();
			}

			if (loopNum == loops) return;

			head %= 6;
			tail %= 6;
			LED_SPI_Update(ws2812_temp, 6);
			bsp_DelayMS(wait);
		}
	}

}

void ws2812_fullWhite(void)
{
	u8 i;
	for (i = 0; i < 6; i++) {
		ws2812_setPixelColor(i, ws2812_RGB_Color(255, 255, 255));
	}
	LED_SPI_Update(ws2812_temp, 6);
}

uint8_t red(uint32_t c)
{
	return (c >> 16);
}
uint8_t green(uint32_t c)
{
	return (c >> 8);
}
uint8_t blue(uint32_t c)
{
	return (c);
}

#if defined RGBW

// Convert separate R,G,B,W into packed 32-bit WRGB color.
// Packed format is always WRGB, regardless of LED strand color order.
uint32_t ws2812_RGBW_Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
	return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

void ws2812_pulseWhite(uint16_t wait)
{
	u8 i;
	int16_t j;
	for (j = 0; j < 256; j++) 
	{
		for (i = 0; i < 6; i++) 
		{
			ws2812_setPixelColor(i, ws2812_RGBW_Color(0, 0, 0, LEDGamma[j]));
		}
		bsp_DelayMS(wait);
		LED_SPI_Update(ws2812_temp, 6);
	}

	for (j = 255; j >= 0; j--) 
	{
		for (i = 0; i < 6; i++) 
		{
			ws2812_setPixelColor(i, ws2812_RGBW_Color(0, 0, 0, LEDGamma[j]));
		}
		bsp_DelayMS(wait);
		LED_SPI_Update(ws2812_temp, 6);
	}
}

void ws2812_rainbowFade2White(uint16_t wait, int rainbowLoops, int whiteLoops)
{
	float fadeMax = 100.0;
	float fadeVal = 0.0;
	uint32_t wheelVal;
	int k, redVal, greenVal, blueVal;
	int16_t j;
	u8 i;
	for (k = 0; k < rainbowLoops; k++) 
	{
		for (j = 0; j < 256; j++) 
		{ // 5 cycles of all colors on wheel
			for (i = 0; i < 6; i++) 
			{
				wheelVal = ws2812_wheel(((i * 256 / 6) + j) & 255);

				//redVal = red(wheelVal) * (float(fadeVal / fadeMax));
				//greenVal = green(wheelVal) * (float(fadeVal / fadeMax));
				//blueVal = blue(wheelVal) * (float(fadeVal / fadeMax));

				ws2812_setPixelColor(i, ws2812_RGB_Color(redVal, greenVal, blueVal));
			}

			//First loop, fade in!
			if (k == 0 && fadeVal < fadeMax - 1) 
			{
				fadeVal++;
			}

			//Last loop, fade out!
			else if (k == rainbowLoops - 1 && j > 255 - fadeMax) 
			{
				fadeVal--;
			}

			LED_SPI_Update(ws2812_temp, 6);
			bsp_DelayMS(wait);
		}
	}

	bsp_DelayMS(500);

	for (k = 0; k < whiteLoops; k++) 
	{

		for (j = 0; j < 256; j++) 
		{

			for (i = 0; i < 6; i++) {
				ws2812_setPixelColor(i, ws2812_RGBW_Color(0, 0, 0, LEDGamma[j]));
			}
			LED_SPI_Update(ws2812_temp, 6);
		}

		bsp_DelayMS(2000);
		for (j = 255; j >= 0; j--) 
		{

			for (i = 0; i < 6; i++) 
			{
				ws2812_setPixelColor(i, ws2812_RGBW_Color(0, 0, 0, LEDGamma[j]));
			}
			LED_SPI_Update(ws2812_temp, 6);
		}
	}
	bsp_DelayMS(500);
}

#endif

static const unsigned char hitb_glcd_bmp[] = {
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xB8, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xE1, 0x9E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x81, 0x87, 0x80, 0x00, 0x00,
0x00, 0x00, 0x07, 0x01, 0x81, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x01, 0x80, 0xF0, 0x00, 0x00,
0x00, 0x00, 0x70, 0x01, 0x80, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x80, 0x0E, 0x00, 0x00,
0x00, 0x03, 0x80, 0x01, 0x80, 0x03, 0x80, 0x00, 0x00, 0x0E, 0x00, 0x01, 0x80, 0x01, 0xE0, 0x00,
0x00, 0x38, 0x00, 0x01, 0x80, 0x00, 0x78, 0x00, 0x00, 0x70, 0x00, 0x01, 0x80, 0x00, 0x1C, 0x00,
0x01, 0xC0, 0x00, 0x01, 0x80, 0x00, 0x0F, 0x00, 0x07, 0x00, 0x00, 0x01, 0x80, 0x00, 0x03, 0xC0,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0xE0, 0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0x1C, 0x70, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x38, 0x3C, 0x00, 0x00, 0x60,
0x0C, 0x00, 0x00, 0xE0, 0x0F, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x03, 0x80, 0x03, 0x80, 0x00, 0x60,
0x0C, 0x00, 0x0F, 0x00, 0x01, 0xE0, 0x00, 0x60, 0x0C, 0x00, 0x1F, 0x00, 0x01, 0xF8, 0x00, 0x60,
0x0C, 0x00, 0x7F, 0xC0, 0x07, 0xFE, 0x00, 0x60, 0x0C, 0x01, 0xFF, 0xF0, 0x1F, 0xFF, 0x00, 0x60,
0x0C, 0x03, 0xFF, 0xF8, 0x3F, 0xFF, 0xC0, 0x60, 0x0C, 0x0F, 0xFF, 0xFE, 0xFF, 0xFF, 0xF0, 0x60,
0x0C, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x60, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x60,
0x0D, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x0F, 0xFE, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0,
0x0F, 0xF8, 0x79, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x0F, 0xF1, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0,
0x07, 0xE7, 0x86, 0x3F, 0xFF, 0xFF, 0xFF, 0xC0, 0x01, 0xFE, 0x1C, 0x0F, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0x7E, 0x70, 0xC3, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x1F, 0xC3, 0xE1, 0xFF, 0xFF, 0xF0, 0x00,
0x00, 0x0F, 0xCF, 0x08, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x03, 0xFE, 0x1E, 0x1F, 0xFF, 0x80, 0x00,
0x00, 0x00, 0xFC, 0x78, 0xCF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xF0, 0xC7, 0xFC, 0x00, 0x00,
0x00, 0x00, 0x1F, 0xC3, 0x07, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xE3, 0x3F, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x01, 0xF8, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x3F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xE0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00
};



void hitb_start(void)
{
	const char hitb2018gsec[] = "HITB 2018 GSEC";
	const char hitb[] = "HITB 2018";
	const char gsec[] = "Singapore";
	const char only_hitb[] = "HITB";
	const char only_2018[] = "2018";
	uint8_t i;

	LCD_Clear(BLACK);
	LCD_setTextColor(WHITE,BLACK);
	LCD_setTextSize(2);

	u16 iSeed = 0;

	iSeed = bsp_GetAdc_Average(1);//通过模拟输入获取悬空引脚的电平产生随机种子
	srand(iSeed);
		
	//u16 r = (u16)(rand() % 4);//产生随机数0~3
	u16 r = 1;
	int loop_len = 0;

	switch(r){
	case 0: //HITB 2018 U->D, GSEC D->U 
		loop_len = 65;
		for(i=0; i<65; i++)
		{
			LCD_setCursor(26, i - 35);
			LCD_print(hitb);
			LCD_setCursor(26, i - 35);
			LCD_print("        ");
			LCD_setCursor(26, (loop_len + 65) - i);
			LCD_print(gsec);
			LCD_setCursor(26, (loop_len + 65) - i);
			LCD_print("         ");
		}
		break;
	case 1: //HITB 2018 D->U, GSEC U->D
		loop_len = 65;
		for(i=0; i<loop_len; i++)
		{
			//LCD_DrawLine(0, (loop_len + 35) - i - 1, 160, (loop_len + 35) - i, BLACK);
			LCD_textWrap(hitb, 26, (loop_len + 35) - i);
			LCD_textWrap(gsec, 26, (65 - loop_len) + i);
			LCD_DrawFastHLine(0, (65 - loop_len) + i, 160, BLACK);
//		ws2812_rainbow(20);
		}
		break;
	case 2: //HITB 2018 L->R, GSEC R->L
		loop_len = 65;
		for(i=0; i<loop_len; i++)
		{
		LCD_setCursor( (26+loop_len) - i, 35);
		LCD_print(hitb);
		LCD_setCursor((26 + loop_len) - i, 35);
		LCD_print("         ");
		LCD_setCursor( (26-loop_len) + i , 65);
		LCD_print(gsec);
		LCD_setCursor((26 - loop_len) + i, 65);
		LCD_print("         ");
			//ws2812_rainbow(20);
//		ws2812_theaterChase(20);
		}
		break;
	case 3: //HITB L->R, 2018 R->L, GSEC D->U
		loop_len = 65;
		for(i=0; i<loop_len; i++){
		LCD_setCursor( (26-loop_len) + i, 35);
		LCD_println(only_hitb);
		LCD_setCursor((26 - loop_len) + i, 35);
		LCD_print("    ");
		LCD_setCursor( (87+loop_len) - i, 35);
		LCD_print(only_2018);
		LCD_setCursor((87 + loop_len) - i, 35);
		LCD_print("    ");
		LCD_setCursor(26, (loop_len+65) - i);
		LCD_print(gsec);
		LCD_setCursor(26, (loop_len + 65) - i);
		LCD_print("         ");
//		ws2812_theaterChaseRainbow(20);
		}
		break; 
	default:
		break;
	}

	LCD_setCursor(26, 35);
	LCD_println(only_hitb);
	LCD_setCursor(87, 35);
	LCD_println(only_2018);
	LCD_setCursor(26, 65);
	LCD_println(gsec);


	ws2812_rainbowCycle(5);
	//Wait 1500ms
	//for(int i=0; i<150; i++){
	//	ws2812_rainbowCycle(i);
	//}

	//Queue in logo
	LCD_Clear(BLACK);
	LCD_DrawBitmap(48, 32, hitb_glcd_bmp, 64, 64, WHITE,BLACK);
	bsp_DelayMS(2000);

	//Wait 2000ms
	
	//ws2812_theaterChaseRainbow(5);

	ws2812_clear();
	LCD_setTextSize(1);
	LCD_Clear(BLACK);

}


