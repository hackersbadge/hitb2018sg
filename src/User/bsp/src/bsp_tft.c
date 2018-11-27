#include "bsp.h"

static const unsigned char  font[] = {
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x3E, 0x5B, 0x4F, 0x5B, 0x3E,
	0x3E, 0x6B, 0x4F, 0x6B, 0x3E,
	0x1C, 0x3E, 0x7C, 0x3E, 0x1C,
	0x18, 0x3C, 0x7E, 0x3C, 0x18,
	0x1C, 0x57, 0x7D, 0x57, 0x1C,
	0x1C, 0x5E, 0x7F, 0x5E, 0x1C,
	0x00, 0x18, 0x3C, 0x18, 0x00,
	0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
	0x00, 0x18, 0x24, 0x18, 0x00,
	0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
	0x30, 0x48, 0x3A, 0x06, 0x0E,
	0x26, 0x29, 0x79, 0x29, 0x26,
	0x40, 0x7F, 0x05, 0x05, 0x07,
	0x40, 0x7F, 0x05, 0x25, 0x3F,
	0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
	0x7F, 0x3E, 0x1C, 0x1C, 0x08,
	0x08, 0x1C, 0x1C, 0x3E, 0x7F,
	0x14, 0x22, 0x7F, 0x22, 0x14,
	0x5F, 0x5F, 0x00, 0x5F, 0x5F,
	0x06, 0x09, 0x7F, 0x01, 0x7F,
	0x00, 0x66, 0x89, 0x95, 0x6A,
	0x60, 0x60, 0x60, 0x60, 0x60,
	0x94, 0xA2, 0xFF, 0xA2, 0x94,
	0x08, 0x04, 0x7E, 0x04, 0x08,
	0x10, 0x20, 0x7E, 0x20, 0x10,
	0x08, 0x08, 0x2A, 0x1C, 0x08,
	0x08, 0x1C, 0x2A, 0x08, 0x08,
	0x1E, 0x10, 0x10, 0x10, 0x10,
	0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
	0x30, 0x38, 0x3E, 0x38, 0x30,
	0x06, 0x0E, 0x3E, 0x0E, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x5F, 0x00, 0x00,
	0x00, 0x07, 0x00, 0x07, 0x00,
	0x14, 0x7F, 0x14, 0x7F, 0x14,
	0x24, 0x2A, 0x7F, 0x2A, 0x12,
	0x23, 0x13, 0x08, 0x64, 0x62,
	0x36, 0x49, 0x56, 0x20, 0x50,
	0x00, 0x08, 0x07, 0x03, 0x00,
	0x00, 0x1C, 0x22, 0x41, 0x00,
	0x00, 0x41, 0x22, 0x1C, 0x00,
	0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
	0x08, 0x08, 0x3E, 0x08, 0x08,
	0x00, 0x80, 0x70, 0x30, 0x00,
	0x08, 0x08, 0x08, 0x08, 0x08,
	0x00, 0x00, 0x60, 0x60, 0x00,
	0x20, 0x10, 0x08, 0x04, 0x02,
	0x3E, 0x51, 0x49, 0x45, 0x3E,
	0x00, 0x42, 0x7F, 0x40, 0x00,
	0x72, 0x49, 0x49, 0x49, 0x46,
	0x21, 0x41, 0x49, 0x4D, 0x33,
	0x18, 0x14, 0x12, 0x7F, 0x10,
	0x27, 0x45, 0x45, 0x45, 0x39,
	0x3C, 0x4A, 0x49, 0x49, 0x31,
	0x41, 0x21, 0x11, 0x09, 0x07,
	0x36, 0x49, 0x49, 0x49, 0x36,
	0x46, 0x49, 0x49, 0x29, 0x1E,
	0x00, 0x00, 0x14, 0x00, 0x00,
	0x00, 0x40, 0x34, 0x00, 0x00,
	0x00, 0x08, 0x14, 0x22, 0x41,
	0x14, 0x14, 0x14, 0x14, 0x14,
	0x00, 0x41, 0x22, 0x14, 0x08,
	0x02, 0x01, 0x59, 0x09, 0x06,
	0x3E, 0x41, 0x5D, 0x59, 0x4E,
	0x7C, 0x12, 0x11, 0x12, 0x7C,
	0x7F, 0x49, 0x49, 0x49, 0x36,
	0x3E, 0x41, 0x41, 0x41, 0x22,
	0x7F, 0x41, 0x41, 0x41, 0x3E,
	0x7F, 0x49, 0x49, 0x49, 0x41,
	0x7F, 0x09, 0x09, 0x09, 0x01,
	0x3E, 0x41, 0x41, 0x51, 0x73,
	0x7F, 0x08, 0x08, 0x08, 0x7F,
	0x00, 0x41, 0x7F, 0x41, 0x00,
	0x20, 0x40, 0x41, 0x3F, 0x01,
	0x7F, 0x08, 0x14, 0x22, 0x41,
	0x7F, 0x40, 0x40, 0x40, 0x40,
	0x7F, 0x02, 0x1C, 0x02, 0x7F,
	0x7F, 0x04, 0x08, 0x10, 0x7F,
	0x3E, 0x41, 0x41, 0x41, 0x3E,
	0x7F, 0x09, 0x09, 0x09, 0x06,
	0x3E, 0x41, 0x51, 0x21, 0x5E,
	0x7F, 0x09, 0x19, 0x29, 0x46,
	0x26, 0x49, 0x49, 0x49, 0x32,
	0x03, 0x01, 0x7F, 0x01, 0x03,
	0x3F, 0x40, 0x40, 0x40, 0x3F,
	0x1F, 0x20, 0x40, 0x20, 0x1F,
	0x3F, 0x40, 0x38, 0x40, 0x3F,
	0x63, 0x14, 0x08, 0x14, 0x63,
	0x03, 0x04, 0x78, 0x04, 0x03,
	0x61, 0x59, 0x49, 0x4D, 0x43,
	0x00, 0x7F, 0x41, 0x41, 0x41,
	0x02, 0x04, 0x08, 0x10, 0x20,
	0x00, 0x41, 0x41, 0x41, 0x7F,
	0x04, 0x02, 0x01, 0x02, 0x04,
	0x40, 0x40, 0x40, 0x40, 0x40,
	0x00, 0x03, 0x07, 0x08, 0x00,
	0x20, 0x54, 0x54, 0x78, 0x40,
	0x7F, 0x28, 0x44, 0x44, 0x38,
	0x38, 0x44, 0x44, 0x44, 0x28,
	0x38, 0x44, 0x44, 0x28, 0x7F,
	0x38, 0x54, 0x54, 0x54, 0x18,
	0x00, 0x08, 0x7E, 0x09, 0x02,
	0x18, 0xA4, 0xA4, 0x9C, 0x78,
	0x7F, 0x08, 0x04, 0x04, 0x78,
	0x00, 0x44, 0x7D, 0x40, 0x00,
	0x20, 0x40, 0x40, 0x3D, 0x00,
	0x7F, 0x10, 0x28, 0x44, 0x00,
	0x00, 0x41, 0x7F, 0x40, 0x00,
	0x7C, 0x04, 0x78, 0x04, 0x78,
	0x7C, 0x08, 0x04, 0x04, 0x78,
	0x38, 0x44, 0x44, 0x44, 0x38,
	0xFC, 0x18, 0x24, 0x24, 0x18,
	0x18, 0x24, 0x24, 0x18, 0xFC,
	0x7C, 0x08, 0x04, 0x04, 0x08,
	0x48, 0x54, 0x54, 0x54, 0x24,
	0x04, 0x04, 0x3F, 0x44, 0x24,
	0x3C, 0x40, 0x40, 0x20, 0x7C,
	0x1C, 0x20, 0x40, 0x20, 0x1C,
	0x3C, 0x40, 0x30, 0x40, 0x3C,
	0x44, 0x28, 0x10, 0x28, 0x44,
	0x4C, 0x90, 0x90, 0x90, 0x7C,
	0x44, 0x64, 0x54, 0x4C, 0x44,
	0x00, 0x08, 0x36, 0x41, 0x00,
	0x00, 0x00, 0x77, 0x00, 0x00,
	0x00, 0x41, 0x36, 0x08, 0x00,
	0x02, 0x01, 0x02, 0x04, 0x02,
	0x3C, 0x26, 0x23, 0x26, 0x3C,
	0x1E, 0xA1, 0xA1, 0x61, 0x12,
	0x3A, 0x40, 0x40, 0x20, 0x7A,
	0x38, 0x54, 0x54, 0x55, 0x59,
	0x21, 0x55, 0x55, 0x79, 0x41,
	0x21, 0x54, 0x54, 0x78, 0x41,
	0x21, 0x55, 0x54, 0x78, 0x40,
	0x20, 0x54, 0x55, 0x79, 0x40,
	0x0C, 0x1E, 0x52, 0x72, 0x12,
	0x39, 0x55, 0x55, 0x55, 0x59,
	0x39, 0x54, 0x54, 0x54, 0x59,
	0x39, 0x55, 0x54, 0x54, 0x58,
	0x00, 0x00, 0x45, 0x7C, 0x41,
	0x00, 0x02, 0x45, 0x7D, 0x42,
	0x00, 0x01, 0x45, 0x7C, 0x40,
	0xF0, 0x29, 0x24, 0x29, 0xF0,
	0xF0, 0x28, 0x25, 0x28, 0xF0,
	0x7C, 0x54, 0x55, 0x45, 0x00,
	0x20, 0x54, 0x54, 0x7C, 0x54,
	0x7C, 0x0A, 0x09, 0x7F, 0x49,
	0x32, 0x49, 0x49, 0x49, 0x32,
	0x32, 0x48, 0x48, 0x48, 0x32,
	0x32, 0x4A, 0x48, 0x48, 0x30,
	0x3A, 0x41, 0x41, 0x21, 0x7A,
	0x3A, 0x42, 0x40, 0x20, 0x78,
	0x00, 0x9D, 0xA0, 0xA0, 0x7D,
	0x39, 0x44, 0x44, 0x44, 0x39,
	0x3D, 0x40, 0x40, 0x40, 0x3D,
	0x3C, 0x24, 0xFF, 0x24, 0x24,
	0x48, 0x7E, 0x49, 0x43, 0x66,
	0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
	0xFF, 0x09, 0x29, 0xF6, 0x20,
	0xC0, 0x88, 0x7E, 0x09, 0x03,
	0x20, 0x54, 0x54, 0x79, 0x41,
	0x00, 0x00, 0x44, 0x7D, 0x41,
	0x30, 0x48, 0x48, 0x4A, 0x32,
	0x38, 0x40, 0x40, 0x22, 0x7A,
	0x00, 0x7A, 0x0A, 0x0A, 0x72,
	0x7D, 0x0D, 0x19, 0x31, 0x7D,
	0x26, 0x29, 0x29, 0x2F, 0x28,
	0x26, 0x29, 0x29, 0x29, 0x26,
	0x30, 0x48, 0x4D, 0x40, 0x20,
	0x38, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x08, 0x08, 0x08, 0x38,
	0x2F, 0x10, 0xC8, 0xAC, 0xBA,
	0x2F, 0x10, 0x28, 0x34, 0xFA,
	0x00, 0x00, 0x7B, 0x00, 0x00,
	0x08, 0x14, 0x2A, 0x14, 0x22,
	0x22, 0x14, 0x2A, 0x14, 0x08,
	0xAA, 0x00, 0x55, 0x00, 0xAA,
	0xAA, 0x55, 0xAA, 0x55, 0xAA,
	0x00, 0x00, 0x00, 0xFF, 0x00,
	0x10, 0x10, 0x10, 0xFF, 0x00,
	0x14, 0x14, 0x14, 0xFF, 0x00,
	0x10, 0x10, 0xFF, 0x00, 0xFF,
	0x10, 0x10, 0xF0, 0x10, 0xF0,
	0x14, 0x14, 0x14, 0xFC, 0x00,
	0x14, 0x14, 0xF7, 0x00, 0xFF,
	0x00, 0x00, 0xFF, 0x00, 0xFF,
	0x14, 0x14, 0xF4, 0x04, 0xFC,
	0x14, 0x14, 0x17, 0x10, 0x1F,
	0x10, 0x10, 0x1F, 0x10, 0x1F,
	0x14, 0x14, 0x14, 0x1F, 0x00,
	0x10, 0x10, 0x10, 0xF0, 0x00,
	0x00, 0x00, 0x00, 0x1F, 0x10,
	0x10, 0x10, 0x10, 0x1F, 0x10,
	0x10, 0x10, 0x10, 0xF0, 0x10,
	0x00, 0x00, 0x00, 0xFF, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0xFF, 0x10,
	0x00, 0x00, 0x00, 0xFF, 0x14,
	0x00, 0x00, 0xFF, 0x00, 0xFF,
	0x00, 0x00, 0x1F, 0x10, 0x17,
	0x00, 0x00, 0xFC, 0x04, 0xF4,
	0x14, 0x14, 0x17, 0x10, 0x17,
	0x14, 0x14, 0xF4, 0x04, 0xF4,
	0x00, 0x00, 0xFF, 0x00, 0xF7,
	0x14, 0x14, 0x14, 0x14, 0x14,
	0x14, 0x14, 0xF7, 0x00, 0xF7,
	0x14, 0x14, 0x14, 0x17, 0x14,
	0x10, 0x10, 0x1F, 0x10, 0x1F,
	0x14, 0x14, 0x14, 0xF4, 0x14,
	0x10, 0x10, 0xF0, 0x10, 0xF0,
	0x00, 0x00, 0x1F, 0x10, 0x1F,
	0x00, 0x00, 0x00, 0x1F, 0x14,
	0x00, 0x00, 0x00, 0xFC, 0x14,
	0x00, 0x00, 0xF0, 0x10, 0xF0,
	0x10, 0x10, 0xFF, 0x10, 0xFF,
	0x14, 0x14, 0x14, 0xFF, 0x14,
	0x10, 0x10, 0x10, 0x1F, 0x00,
	0x00, 0x00, 0x00, 0xF0, 0x10,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
	0xFF, 0xFF, 0xFF, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFF, 0xFF,
	0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
	0x38, 0x44, 0x44, 0x38, 0x44,
	0x7C, 0x2A, 0x2A, 0x3E, 0x14,
	0x7E, 0x02, 0x02, 0x06, 0x06,
	0x02, 0x7E, 0x02, 0x7E, 0x02,
	0x63, 0x55, 0x49, 0x41, 0x63,
	0x38, 0x44, 0x44, 0x3C, 0x04,
	0x40, 0x7E, 0x20, 0x1E, 0x20,
	0x06, 0x02, 0x7E, 0x02, 0x02,
	0x99, 0xA5, 0xE7, 0xA5, 0x99,
	0x1C, 0x2A, 0x49, 0x2A, 0x1C,
	0x4C, 0x72, 0x01, 0x72, 0x4C,
	0x30, 0x4A, 0x4D, 0x4D, 0x30,
	0x30, 0x48, 0x78, 0x48, 0x30,
	0xBC, 0x62, 0x5A, 0x46, 0x3D,
	0x3E, 0x49, 0x49, 0x49, 0x00,
	0x7E, 0x01, 0x01, 0x01, 0x7E,
	0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
	0x44, 0x44, 0x5F, 0x44, 0x44,
	0x40, 0x51, 0x4A, 0x44, 0x40,
	0x40, 0x44, 0x4A, 0x51, 0x40,
	0x00, 0x00, 0xFF, 0x01, 0x03,
	0xE0, 0x80, 0xFF, 0x00, 0x00,
	0x08, 0x08, 0x6B, 0x6B, 0x08,
	0x36, 0x12, 0x36, 0x24, 0x36,
	0x06, 0x0F, 0x09, 0x0F, 0x06,
	0x00, 0x00, 0x18, 0x18, 0x00,
	0x00, 0x00, 0x10, 0x10, 0x00,
	0x30, 0x40, 0xFF, 0x01, 0x01,
	0x00, 0x1F, 0x01, 0x01, 0x1E,
	0x00, 0x19, 0x1D, 0x17, 0x12,
	0x00, 0x3C, 0x3C, 0x3C, 0x3C,
	0x00, 0x00, 0x00, 0x00, 0x00,
};

//管理LCD重要参数
//默认为竖屏
_lcd_dev lcddev;

u16 cursor_x, cursor_y, textcolor, textbgcolor;
u8 textsize, wrap; // If set, 'wrap' text at right edge of display

//画笔颜色,背景颜色
u16 POINT_COLOR = BLACK, BACK_COLOR = WHITE;
//u16 DeviceCode;

//向LCD控制芯片写入一个字节。
//data1:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void LCD_WR(u8 cmd, u8 data1)
{
	LCD_CS = 0;
	if (cmd)
	{
		LCD_A0 = 1;
	}
	else
	{
		LCD_A0 = 0;
	}
	bsp_spiWrite1(data1);
	LCD_CS = 1;
}

void LCD_WR_16Bit(u16 data1)
{
	LCD_CS = 0;
	LCD_A0 = 1;
	bsp_spiWrite1(data1 >> 8);
	bsp_spiWrite1(data1);
	LCD_CS = 1;
}

//******************************************************************
//函数名：  LCD_WR_REG
//作者：    
//日期：    
//功能：    写寄存器数据
//输入参数：LCD_Reg:寄存器地址
//			LCD_RegValue:要写入的数据
//返回值：  无
//修改记录：无
//******************************************************************
void LCD_WR_REG(u8 LCD_Reg, u8 LCD_RegValue)
{
	LCD_WR(LCD_CMD, LCD_Reg);
	LCD_WR(LCD_DATA, LCD_RegValue);
}

//******************************************************************
//函数名：  LCD_WR_GRAM
//作者：    
//日期：    
//功能：    开始写GRAM
//			在给液晶屏传送RGB数据前，应该发送写GRAM指令
//输入参数：无
//返回值：  无
//修改记录：无
//******************************************************************
void LCD_WR_GRAM(void)
{
	LCD_WR(LCD_CMD, lcddev.wramcmd);
}

//从ILI93xx读出的数据为GBR格式，而我们写入的时候为RGB格式。
//通过该函数转换
//c:GBR格式的颜色值
//返回值：RGB格式的颜色值
u16 LCD_BGR2RGB(u16 c)
{
	u16  r,g,b,rgb;   
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
} 


//******************************************************************
//函数名：  LCD_Reset
//作者：    
//日期：    
//功能：    LCD复位函数，液晶初始化前要调用此函数
//输入参数：无
//返回值：  无
//修改记录：无
//******************************************************************
void LCD_RESET(void)
{
	LCD_RES = 1;
	bsp_DelayMS(50);
	LCD_RES = 0;
	bsp_DelayMS(50);
	LCD_RES = 1;
	bsp_DelayMS(50);
}

/*LCD模块GPIO初始化*/
//BK PE4 A0(RS/DC) PE2 RES PE5 CS PE3
void LCD_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//使能GPIOA,C时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;	//PA4推挽输出
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化PA4

	LCD_CS = 1;			//SPI片选取消

	//SPI_Init_n(LCD_SPI);    		//初始化LCD_SPI 

	//SPI_SetSpeed(LCD_SPI, SPI_BaudRatePrescaler_4);

	//	LCD_SPI_Init();//针对LCD的特点修改SPI的设置
}


void LCD_Init(void)
{
	uint16_t light_temp = 0;
	LCD_GPIO_Init();
	LCD_Light_Init();

	LCD_RESET();	//复位液晶

#if defined (TFT_ST7735_1_44) || defined (TFT_ST7735_1_8)

	LCD_WR(LCD_CMD, 0x11);	//退出睡眠
	bsp_DelayMS(120);

	//ST7735R Frame Rate
	LCD_WR(LCD_CMD, 0xB1);		//Frame Rate Control 帧率控制
	LCD_WR(LCD_DATA, 0x01);
	LCD_WR(LCD_DATA, 0x2C);
	LCD_WR(LCD_DATA, 0x2D);

	LCD_WR(LCD_CMD, 0xB2);
	LCD_WR(LCD_DATA, 0x01);
	LCD_WR(LCD_DATA, 0x2C);
	LCD_WR(LCD_DATA, 0x2D);

	LCD_WR(LCD_CMD, 0xB3);
	LCD_WR(LCD_DATA, 0x01);
	LCD_WR(LCD_DATA, 0x2C);
	LCD_WR(LCD_DATA, 0x2D);
	LCD_WR(LCD_DATA, 0x01);
	LCD_WR(LCD_DATA, 0x2C);
	LCD_WR(LCD_DATA, 0x2D);

	LCD_WR(LCD_CMD, 0xB4); //Display Inversion Control 显示反转控制
	LCD_WR(LCD_DATA, 0x07);

	//ST7735R Power Sequence
	LCD_WR(LCD_CMD, 0xC0);
	LCD_WR(LCD_DATA, 0xA2);
	LCD_WR(LCD_DATA, 0x02);
	LCD_WR(LCD_DATA, 0x84);

	LCD_WR(LCD_CMD, 0xC1);
	LCD_WR(LCD_DATA, 0xC5);

	LCD_WR(LCD_CMD, 0xC2);
	LCD_WR(LCD_DATA, 0x0A);
	LCD_WR(LCD_DATA, 0x00);

	LCD_WR(LCD_CMD, 0xC3);
	LCD_WR(LCD_DATA, 0x8A);
	LCD_WR(LCD_DATA, 0x2A);

	LCD_WR(LCD_CMD, 0xC4);
	LCD_WR(LCD_DATA, 0x8A);
	LCD_WR(LCD_DATA, 0xEE);

	LCD_WR(LCD_CMD, 0xC5); //VCOM 
	LCD_WR(LCD_DATA, 0x0E);

	LCD_WR(LCD_CMD, 0x36); //MX, MY, RGB mode 	Memory Data Access Control	 		 
	LCD_WR(LCD_DATA, 0xC0 | LCD_RGB);

	//ST7735R Gamma Sequence
	LCD_WR(LCD_CMD, 0xe0);	//Gamma (‘+’polarity) Correction Characteristics Setting
	LCD_WR(LCD_DATA, 0x0f);
	LCD_WR(LCD_DATA, 0x1a);
	LCD_WR(LCD_DATA, 0x0f);
	LCD_WR(LCD_DATA, 0x18);
	LCD_WR(LCD_DATA, 0x2f);
	LCD_WR(LCD_DATA, 0x28);
	LCD_WR(LCD_DATA, 0x20);
	LCD_WR(LCD_DATA, 0x22);
	LCD_WR(LCD_DATA, 0x1f);
	LCD_WR(LCD_DATA, 0x1b);
	LCD_WR(LCD_DATA, 0x23);
	LCD_WR(LCD_DATA, 0x37);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x07);
	LCD_WR(LCD_DATA, 0x02);
	LCD_WR(LCD_DATA, 0x10);

	LCD_WR(LCD_CMD, 0xe1); //Gamma (‘-’polarity) Correction Characteristics Setting
	LCD_WR(LCD_DATA, 0x0f);
	LCD_WR(LCD_DATA, 0x1b);
	LCD_WR(LCD_DATA, 0x0f);
	LCD_WR(LCD_DATA, 0x17);
	LCD_WR(LCD_DATA, 0x33);
	LCD_WR(LCD_DATA, 0x2c);
	LCD_WR(LCD_DATA, 0x29);
	LCD_WR(LCD_DATA, 0x2e);
	LCD_WR(LCD_DATA, 0x30);
	LCD_WR(LCD_DATA, 0x30);
	LCD_WR(LCD_DATA, 0x39);
	LCD_WR(LCD_DATA, 0x3f);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x07);
	LCD_WR(LCD_DATA, 0x03);
	LCD_WR(LCD_DATA, 0x10);

	LCD_WR(LCD_CMD, 0x2a);	//Column Address Set
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x02);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x7f);	//128*128 为0x7f 128*160 0x81

	LCD_WR(LCD_CMD, 0x2b);	//Row Address Set
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x01);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x9f);	////128*128 为0x7f，128*160为0x9f 默认设置为0x9f

	LCD_WR(LCD_CMD, 0xF0); //Enable test command  
	LCD_WR(LCD_DATA, 0x01);
	LCD_WR(LCD_CMD, 0xF6); //Disable ram power save mode 
	LCD_WR(LCD_DATA, 0x00);

	LCD_WR(LCD_CMD, 0x3A); //65k mode Interface Pixel Format
	LCD_WR(LCD_DATA, 0x05);

	LCD_WR(LCD_CMD, 0x29);//Display on

#elif defined (TFT_ILI9163_1_8)

	LCD_WR(LCD_CMD, 0x11);       		  	//关闭睡眠，振荡器工作
	bsp_DelayMS(100);

	LCD_WR(LCD_CMD, 0x3a);       		  	//每次传送16位数据(VIPF3-0=0101)，每个像素16位(IFPF2-0=101)
	LCD_WR(LCD_DATA, 0x55);

	LCD_WR(LCD_CMD, 0x26);
	LCD_WR(LCD_DATA, 0x04);

	LCD_WR(LCD_CMD, 0xf2);              		//Driver Output Control(1)
	LCD_WR(LCD_DATA, 0x01);

	LCD_WR(LCD_CMD, 0xe0);              		//Driver Output Control(1)
	LCD_WR(LCD_DATA, 0x3f);
	LCD_WR(LCD_DATA, 0x25);
	LCD_WR(LCD_DATA, 0x1c);
	LCD_WR(LCD_DATA, 0x1e);
	LCD_WR(LCD_DATA, 0x20);
	LCD_WR(LCD_DATA, 0x12);
	LCD_WR(LCD_DATA, 0x2a);
	LCD_WR(LCD_DATA, 0x90);
	LCD_WR(LCD_DATA, 0x24);
	LCD_WR(LCD_DATA, 0x11);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x00);

	LCD_WR(LCD_CMD, 0xe1);              //Driver Output Control(1)
	LCD_WR(LCD_DATA, 0x20);
	LCD_WR(LCD_DATA, 0x20);
	LCD_WR(LCD_DATA, 0x20);
	LCD_WR(LCD_DATA, 0x20);
	LCD_WR(LCD_DATA, 0x05);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x15);
	LCD_WR(LCD_DATA, 0xa7);
	LCD_WR(LCD_DATA, 0x3d);
	LCD_WR(LCD_DATA, 0x18);
	LCD_WR(LCD_DATA, 0x25);
	LCD_WR(LCD_DATA, 0x2a);
	LCD_WR(LCD_DATA, 0x2b);
	LCD_WR(LCD_DATA, 0x2b);
	LCD_WR(LCD_DATA, 0x3a);

	LCD_WR(LCD_CMD, 0xb1);              	//设置屏幕刷新频率
	LCD_WR(LCD_DATA, 0x08);				   	//DIVA=8
	LCD_WR(LCD_DATA, 0x08);				   	//VPA =8，约90Hz

	LCD_WR(LCD_CMD, 0xb4);              	//LCD Driveing control
	LCD_WR(LCD_DATA, 0x07);				  	//NLA=1,NLB=1,NLC=1


	LCD_WR(LCD_CMD, 0xc0);              //LCD Driveing control
	LCD_WR(LCD_DATA, 0x0a);
	LCD_WR(LCD_DATA, 0x02);

	LCD_WR(LCD_CMD, 0xc1);              //LCD Driveing control
	LCD_WR(LCD_DATA, 0x02);

	LCD_WR(LCD_CMD, 0xc5);              //LCD Driveing control
	LCD_WR(LCD_DATA, 0x4f);
	LCD_WR(LCD_DATA, 0x5a);

	LCD_WR(LCD_CMD, 0xc7);              //LCD Driveing control
	LCD_WR(LCD_DATA, 0x40);

	LCD_WR(LCD_CMD, 0x2a);              	//配置MCU可操作的LCD内部RAM横坐标起始、结束参数
	LCD_WR(LCD_DATA, 0x00);				   	//横坐标起始地址0x0000
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x00);				   	//横坐标结束地址0x007f(127)
	LCD_WR(LCD_DATA, 0x7f);

	LCD_WR(LCD_CMD, 0x2b);              	//配置MCU可操作的LCD内部RAM纵坐标起始结束参数
	LCD_WR(LCD_DATA, 0x00);				   	//纵坐标起始地址0x0000
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x00);				  	//纵坐标结束地址0x009f(159)
	LCD_WR(LCD_DATA, 0x9f);

	LCD_WR(LCD_CMD, 0x36);              	//配置MPU和DDRAM对应关系
	LCD_WR(LCD_DATA, 0xc0);					//MX=1,MY=1

	LCD_WR(LCD_CMD, 0xb7);              	//LCD Driveing control
	LCD_WR(LCD_DATA, 0x00);				   	//CRL=0

	LCD_WR(LCD_CMD, 0x29);   		  	//开启屏幕显示

#elif defined (TFT_ILI9341_2_2)

	LCD_WR(LCD_CMD, 0xCB);
	LCD_WR(LCD_DATA, 0x39);
	LCD_WR(LCD_DATA, 0x2C);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x34);
	LCD_WR(LCD_DATA, 0x02);

	LCD_WR(LCD_CMD, 0xCF);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0XC1);
	LCD_WR(LCD_DATA, 0X30);

	LCD_WR(LCD_CMD, 0xE8);
	LCD_WR(LCD_DATA, 0x85);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x78);

	LCD_WR(LCD_CMD, 0xEA);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x00);

	LCD_WR(LCD_CMD, 0xED);
	LCD_WR(LCD_DATA, 0x64);
	LCD_WR(LCD_DATA, 0x03);
	LCD_WR(LCD_DATA, 0X12);
	LCD_WR(LCD_DATA, 0X81);

	LCD_WR(LCD_CMD, 0xF7);
	LCD_WR(LCD_DATA, 0x20);

	LCD_WR(LCD_CMD, 0xC0);    //Power control 
	LCD_WR(LCD_DATA, 0x23);   //VRH[5:0] 

	LCD_WR(LCD_CMD, 0xC1);    //Power control 
	LCD_WR(LCD_DATA, 0x10);   //SAP[2:0];BT[3:0] 

	LCD_WR(LCD_CMD, 0xC5);    //VCM control 
	LCD_WR(LCD_DATA, 0x3e); //对比度调节
	LCD_WR(LCD_DATA, 0x28);

	LCD_WR(LCD_CMD, 0xC7);    //VCM control2 
	LCD_WR(LCD_DATA, 0x86);  //--

	LCD_WR(LCD_CMD, 0x36);    // Memory Access Control 
	LCD_WR(LCD_DATA, 0x48);

	LCD_WR(LCD_CMD, 0x3A);
	LCD_WR(LCD_DATA, 0x55);

	LCD_WR(LCD_CMD, 0xB1);
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x18);

	LCD_WR(LCD_CMD, 0xB6);    // Display Function Control 
	LCD_WR(LCD_DATA, 0x08);
	LCD_WR(LCD_DATA, 0x82);
	LCD_WR(LCD_DATA, 0x27);

	LCD_WR(LCD_CMD, 0xF2);    // 3Gamma Function Disable 
	LCD_WR(LCD_DATA, 0x00);

	LCD_WR(LCD_CMD, 0x26);    //Gamma curve selected 
	LCD_WR(LCD_DATA, 0x01);

	LCD_WR(LCD_CMD, 0xE0);    //Set Gamma 
	LCD_WR(LCD_DATA, 0x0F);
	LCD_WR(LCD_DATA, 0x31);
	LCD_WR(LCD_DATA, 0x2B);
	LCD_WR(LCD_DATA, 0x0C);
	LCD_WR(LCD_DATA, 0x0E);
	LCD_WR(LCD_DATA, 0x08);
	LCD_WR(LCD_DATA, 0x4E);
	LCD_WR(LCD_DATA, 0xF1);
	LCD_WR(LCD_DATA, 0x37);
	LCD_WR(LCD_DATA, 0x07);
	LCD_WR(LCD_DATA, 0x10);
	LCD_WR(LCD_DATA, 0x03);
	LCD_WR(LCD_DATA, 0x0E);
	LCD_WR(LCD_DATA, 0x09);
	LCD_WR(LCD_DATA, 0x00);

	LCD_WR(LCD_CMD, 0XE1);    //Set Gamma 
	LCD_WR(LCD_DATA, 0x00);
	LCD_WR(LCD_DATA, 0x0E);
	LCD_WR(LCD_DATA, 0x14);
	LCD_WR(LCD_DATA, 0x03);
	LCD_WR(LCD_DATA, 0x11);
	LCD_WR(LCD_DATA, 0x07);
	LCD_WR(LCD_DATA, 0x31);
	LCD_WR(LCD_DATA, 0xC1);
	LCD_WR(LCD_DATA, 0x48);
	LCD_WR(LCD_DATA, 0x08);
	LCD_WR(LCD_DATA, 0x0F);
	LCD_WR(LCD_DATA, 0x0C);
	LCD_WR(LCD_DATA, 0x31);
	LCD_WR(LCD_DATA, 0x36);
	LCD_WR(LCD_DATA, 0x0F);

	LCD_WR(LCD_CMD, 0x11);    //Exit Sleep 
	bsp_DelayMS(120);

	LCD_WR(LCD_CMD, 0x29);    //Display on 

#endif

	lcd_param();		//设置LCD参数
	LCD_Rotate(LLOOK);

	bsp_ReadCpuFlash(LIGHT_ADDR, (uint8_t *)&light_temp, 2);

	if ((light_temp == 0) || (light_temp > 9))
	{
		light_temp = 9;
		bsp_WriteCpuFlash(LIGHT_ADDR, (uint8_t *)&light_temp, 2);
	}

	LCD_Light_Set(light_temp);	//点亮背光
}

//******************************************************************
//函数名：  LCD_Light_Init
//作者：    
//日期：    
//功能：    lcd背光控制初始化
//输入参数：0:背光只能控制开关. 1:背光pwm调节亮度
//返回值：  无
//修改记录：无
//******************************************************************
void LCD_Light_Init(void)
{
#ifdef TFT_Light_Ctl	
	bsp_SetTIMOutPWM(GPIOB, GPIO_Pin_1, TIM3, 4, 2000, 50);
	//TIM11_PWM_Init(500 - 1, 84 - 1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz. 
#else

	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//使能GPIOB时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;   //PB9推挽输出
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化PB9

#endif
}

//******************************************************************
//函数名：  LCD_Light_Set
//作者：    
//日期：    
//功能：    lcd背光设置
//输入参数：ctl 是否启用亮度调节，light 亮度等级0-10，禁用背光亮度调节时，0为关，其他为开
//返回值：  无
//修改记录：无
//******************************************************************
void LCD_Light_Set(u8 light)
{
#if defined (TFT_Light_Ctl)	

	if (light < 5)
	{
		TIM_SetCompare4(TIM3, 10 * light);   //修改比较值，修改占空比，因为用的TIM11的CH1，所以用TIM_SetCompare1，如果是CH2，就是TIM_SetCompare2
	} 
	else
	{
		TIM_SetCompare4(TIM3, 50 + 50 * (light - 5));   //修改比较值，修改占空比，因为用的TIM11的CH1，所以用TIM_SetCompare1，如果是CH2，就是TIM_SetCompare2
	}

#else

	if (light == 0)
	{
		LCD_BK = 0;
	}
	else
	{
		LCD_BK = 1;
	}

#endif
}


//设置LCD参数
//方便进行横竖屏旋转模式切换
void lcd_param(void)
{
	lcddev.id = LCD_ID;
	lcddev.dir = 0;

	lcddev.base_width = LCD_BASE_WIDTH;
	lcddev.base_height = LCD_BASE_HEIGHT;
	lcddev.max_width = LCD_MAX_WIDTH;
	lcddev.max_height = LCD_MAX_HEIGHT;

	lcddev.wramcmd = LCD_WRAM;
	lcddev.setxcmd = LCD_SETX;
	lcddev.setycmd = LCD_SETY;

	cursor_x = 0;
	cursor_y = 0;
	textsize = 1;
	textcolor = 0xFFFF;
	textbgcolor = 0xFFFF;
	wrap = TRUE;
}



/*************************************************
函数名：lcd_set_window
功能：设置lcd显示窗口，在此区域写点数据自动换行,窗体大小:w*h.
入口参数：x,y窗口起始坐标(左上角);w,h窗口宽度和高度,必须大于0!!
返回值：无
*************************************************/
void lcd_set_window(u16 x, u16 y, u16 w, u16 h)
{
	x = x + lcddev.base_width + lcddev.move_width;
	y = y + lcddev.base_height + lcddev.move_height;
	w += lcddev.move_width;
	h += lcddev.move_height;

	LCD_WR(LCD_CMD, lcddev.setxcmd);
	LCD_WR(LCD_DATA, x >> 8);
	LCD_WR(LCD_DATA, 0xFF & x);
	LCD_WR(LCD_DATA, w >> 8);
	LCD_WR(LCD_DATA, 0xFF & w);

	LCD_WR(LCD_CMD, lcddev.setycmd);
	LCD_WR(LCD_DATA, y >> 8);
	LCD_WR(LCD_DATA, 0xFF & y);
	LCD_WR(LCD_DATA, h >> 8);
	LCD_WR(LCD_DATA, 0xFF & h);

	LCD_WR_GRAM();	//开始写入GRAM		
}

/*************************************************
函数名：lcd_cursor
功能：设置光标位置
入口参数：xy坐标
返回值：无
*************************************************/
void lcd_cursor(u16 Xpos, u16 Ypos)
{
	//lcd_set_window(Xpos,Ypos,Xpos,Ypos);

	Xpos = Xpos + lcddev.base_width + lcddev.move_width;
	Ypos = Ypos + lcddev.base_height + lcddev.move_height;

	LCD_WR(LCD_CMD, lcddev.setxcmd);
	LCD_WR(LCD_DATA, Xpos >> 8);
	LCD_WR(LCD_DATA, 0xFF & Xpos);

	LCD_WR(LCD_CMD, lcddev.setycmd);
	LCD_WR(LCD_DATA, Ypos >> 8);
	LCD_WR(LCD_DATA, 0xFF & Ypos);

	LCD_WR_GRAM();	//开始写入GRAM	
}

/*************************************************
函数名：LCD_Rotate
功能：屏幕旋转
入口参数：方向
返回值：无
*************************************************/

void LCD_Rotate(u8 dir)
{
	switch (dir)
	{
	case DLOOK:		//0点在左上，正竖屏，默认情况
		lcddev.dir = 0;
		lcddev.base_width = LCD_BASE_WIDTH;
		lcddev.base_height = LCD_BASE_HEIGHT;
		lcddev.max_width = LCD_MAX_WIDTH;
		lcddev.max_height = LCD_MAX_HEIGHT;
		lcddev.move_width = LCD_MOVE_WIDTH;
		lcddev.move_height = LCD_MOVE_HEIGHT;
		LCD_WR_REG(LCD_DIR_REG, DLOOK | LCD_RGB);
		break;
	case ULOOK:		//0点在右下，倒竖屏
		lcddev.dir = 0;
		lcddev.base_width = LCD_BASE_WIDTH;
		lcddev.base_height = LCD_BASE_HEIGHT - LCD_BASE_HEIGHT;
		lcddev.max_width = LCD_MAX_WIDTH;
		lcddev.max_height = LCD_MAX_HEIGHT - LCD_BASE_HEIGHT;
		lcddev.move_width = LCD_MOVE_WIDTH;
		lcddev.move_height = LCD_MOVE_HEIGHT;
		LCD_WR_REG(LCD_DIR_REG, ULOOK | LCD_RGB);
		break;
	case LLOOK:		//0点在右上，左看横屏
		lcddev.dir = 1;
		lcddev.base_width = LCD_BASE_HEIGHT;
		lcddev.base_height = LCD_BASE_WIDTH;
		lcddev.max_width = LCD_MAX_HEIGHT;
		lcddev.max_height = LCD_MAX_WIDTH;
		lcddev.move_width = LCD_MOVE_HEIGHT;
		lcddev.move_height = LCD_MOVE_WIDTH;
		LCD_WR_REG(LCD_DIR_REG, LLOOK | LCD_RGB);
		break;
	case RLOOK:		//0点在左下，右看横屏
		lcddev.dir = 1;
		lcddev.base_width = LCD_BASE_HEIGHT - LCD_BASE_HEIGHT;
		lcddev.base_height = LCD_BASE_WIDTH;
		lcddev.max_width = LCD_MAX_HEIGHT - LCD_BASE_HEIGHT;
		lcddev.max_height = LCD_MAX_WIDTH;
		lcddev.move_width = LCD_MOVE_HEIGHT;
		lcddev.move_height = LCD_MOVE_WIDTH;
		LCD_WR_REG(LCD_DIR_REG, RLOOK | LCD_RGB);
		break;
	default:
		break;
	}
}

//******************************************************************
//函数名：  lcd_clean_screen
//作者：    
//日期：    
//功能：    LCD全屏填充清屏函数
//输入参数：Color:要清屏的填充色
//返回值：  无
//修改记录：无
//******************************************************************
void LCD_Clear(u16 color)
{
	u16 i, j;
	lcd_set_window(0, 0, lcddev.max_width - 1, lcddev.max_height - 1);
	for (i = lcddev.base_height; i < lcddev.max_height; i++)
	{
		for (j = lcddev.base_width; j < lcddev.max_width; j++)
			LCD_WR_16Bit(color);	//写入数据 	
	}
}

/*清屏，x为列号0-X_MAX_PIXEL-1，x_total为清的列数，y为行号0-Y_MARK-1，y_total为清的行数，mode=0为清白屏，mode=1为清黑屏*/
void LCD_Clear_Sel(u16 x, u16 y, u16 w, u16 h, u16 color)
{
	u8 i, j;

	for (i = 0; i < h; i++)
	{
		lcd_set_window(x, y + i, x + w, y + h);
		for (j = 0; j < w; j++)
		{
			LCD_WR_16Bit(color);	//写入数据 	
		}
	}
}


//在指定区域内填充单个颜色
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color)
{          
	u16 i,j;
	u16 xlen=0;
//	u16 temp;
	xlen=ex-sx+1;	 
	for(i=sy;i<=ey;i++)
	{
	 	lcd_cursor(sx,i);      				//设置光标位置  
		for(j=0;j<xlen;j++)
			LCD_WR_16Bit(color);	//显示颜色 	    
	}	 
}  
//在指定区域内填充指定颜色块			 
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color)
{  
	u16 height,width;
	u16 i,j;
	width=ex-sx+1; 			//得到填充的宽度
	height=ey-sy+1;			//高度
 	for(i=0;i<height;i++)
	{
 		lcd_cursor(sx,sy+i);   	//设置光标位置 
		for(j=0;j<width;j++)
			LCD_WR_16Bit(color[i*width+j]);//写入数据 
	}		  
}  


//******************************************************************
//函数名：  LCD_DrawPixel
//作者：    
//日期：    
//功能：    在指定位置写入一个像素点数据
//输入参数：(x,y,color):光标坐标，颜色
//返回值：  无
//修改记录：无
//******************************************************************
void LCD_DrawPixel(u16 x, u16 y, u16 color)
{
	lcd_cursor(x, y);//设置光标位置 
	LCD_WR_16Bit(color);
}

//画线
//x1,y1:起点坐标
//x2,y2:终点坐标  
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //设置单步方向 
	else if(delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出 
	{  
		LCD_DrawPixel(uRow, uCol, color);//画点 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
} 

//画水平线
//x1,y1:起点坐标
//w:长度
void LCD_DrawFastHLine(u16 x1, u16 y1, u16 w, u16 color)
{
	LCD_DrawLine(x1,y1,x1+w-1,y1,color);
}

//画垂直线
//x1,y1:起点坐标
//w:高度
void LCD_DrawFastVLine(u16 x1, u16 y1, u16 h, u16 color)
{
	LCD_DrawLine(x1,y1,x1,y1+h-1,color);
}

//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void LCD_DrawCircle(u16 x0, u16 y0, u8 r, u16 color)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPixel(x0+a,y0-b, color);             //5
 		LCD_DrawPixel(x0+b,y0-a, color);             //0           
		LCD_DrawPixel(x0+b,y0+a, color);             //4               
		LCD_DrawPixel(x0+a,y0+b, color);             //6 
		LCD_DrawPixel(x0-a,y0+b, color);             //1       
 		LCD_DrawPixel(x0-b,y0+a, color);             
		LCD_DrawPixel(x0-a,y0-b, color);             //2             
  		LCD_DrawPixel(x0-b,y0-a, color);             //7       	         
		a++;
		//使用Bresenham算法画圆     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} 	

//在指定位置画一个指定大小的实心圆
//(x,y):中心点
//r    :半径
void LCD_FillCircle(u16 x0, u16 y0, u8 r, u16 color)
{
}

//画矩形	  
//(x1,y1),(x2,y2):矩形的对角坐标
void LCD_DrawRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
	LCD_DrawLine(x1,y1,x2,y1, color);
	LCD_DrawLine(x1,y1,x1,y2, color);
	LCD_DrawLine(x1,y2,x2,y2, color);
	LCD_DrawLine(x2,y1,x2,y2, color);
}

//画实心矩形
//(x1,y1),(x2,y2):矩形的对角坐标
void LCD_FillRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
    LCD_Fill(x1,y1,x2,y2, color);
}

//画矩形	  
//(x1,y1,w,h):矩形点坐标、宽、长
void LCD_DrawFrame(u16 x1, u16 y1, u16 w, u16 h, u16 color)
{
	LCD_DrawLine(x1,y1,x1+w-1,y1, color);
	LCD_DrawLine(x1,y1,x1,y1+h-1, color);
	LCD_DrawLine(x1,y1+h-1,x1+w-1,y1+h-1, color);
	LCD_DrawLine(x1+w-1,y1,x1+w-1,y1+h-1, color);
}

//画实心矩形
//(x1,y1,w,h):矩形点坐标、宽、长
void LCD_DrawBox(u16 x1, u16 y1, u16 w, u16 h, u16 color)
{
	LCD_Fill(x1,y1,x1+w-1,y1+h-1, color);
}



//画圆角矩形	  
//(x1,y1),(x2,y2):矩形的对角坐标
void LCD_DrawRoundRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 r, u16 color)
{
}

//画实心圆角矩形	  
//(x1,y1),(x2,y2):矩形的对角坐标
void LCD_FillRoundRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 r, u16 color)
{
}

//画三角形
//(x0,y0),(x1,y1),(x2,y2):三角形的三角坐标
void LCD_DrawTriangle(u16 x0, u16 y0, u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
}

//画图
void LCD_DrawBitmap(u16 x0, u16 y0, const unsigned char  *bitmap, u16 w, u16 h, u16 color, u16 bg)
{
	int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
	uint8_t byte = 0;

	for (int16_t j = 0; j < h; j++, y0++) 
	{
		for (int16_t i = 0; i < w; i++) 
		{
			if (i & 7) byte <<= 1;
			else      byte = pgm_read_byte(&bitmap[j * byteWidth + i / 8]);
			if (byte & 0x80) LCD_DrawPixel(x0 + i, y0, color);
		}
	}
}

//开启、关闭LCD显示
void LCD_Display(u8 mode)
{
	if (mode)
	{
		LCD_WR(LCD_CMD, 0x29);//Display on
		LCD_Light_Set(10);	//点亮背光
	}
	else
	{
		LCD_WR(LCD_CMD, 0x28);//Display off
		LCD_Light_Set(0);	//点亮背光
	}
}

//显示5x7点阵图像、ASCII, 或5x7点阵的自造字符、其他图标
//x，y为坐标，*dp为字体，word_color为字体颜色，back_color为背景颜色
void display_graphic_5x7(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color)
{
	u8 i, j;

	for (j = 0; j < 8; j++)
	{
		//lcd_set_window(x, y + j, x + 5, y + 7);
		for (i = 0; i < 6; i++)
		{
			if ((*dp++) & (0x01 << j))		/*写数据到LCD,每写完一个6位的数据后列地址自动加1*/
				LCD_DrawPixel(x+i, y+j, word_color);
				//LCD_WR_16Bit(word_color);
			else
				LCD_DrawPixel(x+i, y+j, back_color);
				//LCD_WR_16Bit(back_color);
		}
		dp -= 6;
	}
}

//显示8x16点阵图像、ASCII, 或8x16点阵的自造字符、其他图标
//x，y为坐标，*dp为字体，word_color为字体颜色，back_color为背景颜色
void display_graphic_8x16(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color)
{
	u8 i, j, k;

	for (k = 0; k < 2; k++)
	{
		for (j = 0; j < 8; j++)
		{
			//lcd_set_window(x, y + k * 8 + j, x + 7, y + 15);
			for (i = 0; i < 8; i++)
			{
				if ((*dp++) & (0x01 << j))		/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
					LCD_DrawPixel(x+i, y+j+8*k, word_color);
					//LCD_WR_16Bit(word_color);
				else
					LCD_DrawPixel(x+i, y+j+8*k, back_color);
					//LCD_WR_16Bit(back_color);
			}
			dp -= 8;
		}
		dp += 8;
	}
}

/*显示16x16点阵图像、汉字、生僻字或16x16点阵的其他图标*/
void display_graphic_16x16(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color)
{
	u8 i, j, k;

	for (k = 0; k < 2; k++)
	{
		for (j = 0; j < 8; j++)
		{
			//lcd_set_window(x, y + k * 8 + j, x + 15, y + 15);
			for (i = 0; i < 16; i++)
			{
				if ((*dp++) & (0x01 << j))		/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
					LCD_DrawPixel(x+i, y+j+8*k, word_color);
					//LCD_WR_16Bit(word_color);
				else
					LCD_DrawPixel(x+i, y+j+8*k, back_color);
					//LCD_WR_16Bit(back_color);
			}
			dp -= 16;
		}
		dp += 16;
	}
}

/*显示32x32点阵图像、汉字、生僻字或32x32点阵的其他图标*/
void display_graphic_32x32(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color)
{
	u8 i, j, k;

	for (k = 0; k < 4; k++)
	{
		for (j = 0; j < 8; j++)
		{
			//lcd_set_window(x, y + k * 8 + j, x + 31, y + 31);
			for (i = 0; i < 32; i++)
			{
				if ((*dp++) & (0x01 << j))		/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
					LCD_DrawPixel(x+i, y+j+8*k, word_color);
					//LCD_WR_16Bit(word_color);
				else
					LCD_DrawPixel(x+i, y+j+8*k, back_color);
					//LCD_WR_16Bit(back_color);
			}
			dp -= 32;
		}
		dp += 32;
	}
}

/*显示48x48点阵图像、汉字、生僻字或48x48点阵的其他图标*/
void display_graphic_48x48(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color)
{
	u8 i, j, k;

	for (k = 0; k < 6; k++)
	{
		for (j = 0; j < 8; j++)
		{
			lcd_set_window(x, y + k * 8 + j, x + 47, y + 47);
			for (i = 0; i < 48; i++)
			{
				if ((*dp++) & (0x01 << j))		/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
					LCD_DrawPixel(x+i, y+j+8*k, word_color);
					//LCD_WR_16Bit(word_color);
				else
					LCD_DrawPixel(x+i, y+j+8*k, back_color);
					//LCD_WR_16Bit(back_color);
			}
			dp -= 48;
		}
		dp += 48;
	}
}

///*显示128x64点阵图像、汉字、生僻字或192x96点阵的其他图标*/
//void display_graphic_128x64(u16 x, u16 y, u8 *dp, u8 mode)
//{
//	u8 i, j;
//	if (mode)
//	{
//		lcd_set_window(x, y + j, 127, 7);
//		for (j = 0; j < 8; j++)
//		{
//			for (i = 0; i < 128; i++)
//			{
//				LCD_WR(LCD_DATA, ~(*dp));					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
//				dp++;
//			}
//		}
//	}
//	else
//	{
//		lcd_set_window(x, y + j, 127, 7);
//		for (j = 0; j < 8; j++)
//		{
//			for (i = 0; i < 128; i++)
//			{
//				LCD_WR(LCD_DATA, *dp);					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
//				dp++;
//			}
//		}
//	}
//}
//
///*显示192x96点阵图像、汉字、生僻字或192x96点阵的其他图标*/
//void display_graphic_192x96(u16 x, u16 y, u8 *dp, u8 mode)
//{
//	u8 i, j;
//	if (mode)
//	{
//		lcd_set_window(x, y + j, 191, 11);
//		for (j = 0; j < 12; j++)
//		{
//			for (i = 0; i < 192; i++)
//			{
//				LCD_WR(LCD_DATA, ~(*dp));					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
//				dp++;
//			}
//		}
//	}
//	else
//	{
//		lcd_set_window(x, y + j, 191, 11);
//		for (j = 0; j < 12; j++)
//		{
//			for (i = 0; i < 192; i++)
//			{
//				LCD_WR(LCD_DATA, *dp);					/*写数据到LCD,每写完一个8位的数据后列地址自动加1*/
//				dp++;
//			}
//		}
//	}
//}

/********************字符显示************************/

//x,y	坐标
//text	显示的字符
//size	字体1为5x7 3为8x16 4为8x16粗体

void display_char_ascii(u16 x, u16 y, char text, u8 size, u16 word_color, u16 back_color)
{
	if ((text >= 0x20) && (text <= 0x7e))
	{
		if (size == 1)
		{
			u8 fontbuf[6] = { 0 };
			//get_font(text, fontbuf);
			//font_ascii_h(fontbuf, text, size);
			display_graphic_5x7(x, y, fontbuf, word_color, back_color);//显示5x7的ASCII字到LCD上
		}
		else if ((size == 3) || (size == 4))
		{
			u8 fontbuf[16] = { 0 };
			//font_ascii_h(fontbuf, text, size);
			display_graphic_8x16(x, y, fontbuf, word_color, back_color);//显示8x16的ASCII字到LCD上
		}
	}
}

void display_string_ascii(u16 x, u16 y, const char *text, u8 size, u16 word_color, u16 back_color)
{
	u8 x_num;
	switch (size)
	{
	case 1:
		x_num = 6;
		break;
	case 3:
		x_num = 8;
		break;
	case 4:
		x_num = 8;
		break;
	}
	while (*text)
	{
		//display_char_ascii(x, y, *text++, size, word_color, back_color);
		LCD_DrawChar(x, y, *text++, word_color, back_color, 1);
		x += x_num;
	}
	//	lcd_set_window(lcddev.base_width, lcddev.base_height, lcddev.max_width - 1, lcddev.max_height - 1);//恢复窗口为全屏  
}

//范围0-4294967295
void display_num(u16 x, u16 y, u32 num, u8 size, u16 word_color, u16 back_color)
{
	char tem[10];
	sprintf(tem, "%u", num);
	display_string_ascii(x, y, tem, size, word_color, back_color);
}

//格式化数字为字符串,format格式要加""比如"%08X"

void display_num_format(u16 x, u16 y, u32 num, u8 size, char * format, u16 word_color, u16 back_color)
{
	char tem[10];
	sprintf(tem, format, num);
	display_string_ascii(x, y, tem, size, word_color, back_color);
}


////10进制数输出
//void display_num_dec(u16 x, u16 y, u32 num, u8 size, u8 mode, u16 word_color, u16 back_color)
//{
//	char tem[10];
//	switch ( mode )
//	{
//	    case 0 :
//	        sprintf(tem, "%d", num);
//	        break;
//	    case 1 :
//	        sprintf(tem, "%u", num);
//	        break;
//	    case 2 :
//	        sprintf(tem, "%2u", num);
//	        break;
//	    case 3 :
//	        sprintf(tem, "%02u", num);
//	        break;
//	    case 4 :
//	        sprintf(tem, "%10u", num);
//	        break;
//	    case 5 :
//	        sprintf(tem, "%010u", num);
//	        break;
//	    default:
//	        break;
//	}
//	
//	display_string_ascii(x, y, tem, size, word_color, back_color);
//}

////16进制输出
//void display_num_hex(u16 x, u16 y, u32 num, u8 size, u8 mode, u16 word_color, u16 back_color)
//{
//	char tem[10];
//	switch ( mode )
//	{
//	    case 0 :
//	        sprintf(tem, "%X", num);
//	        break;
//	    case 1 :
//	        sprintf(tem, "%2X", num);
//	        break;
//	    case 2 :
//	        sprintf(tem, "%4X", num);
//	        break;
//	    case 3 :
//	        sprintf(tem, "%8X", num);
//	        break;
//	    case 4 :
//	        sprintf(tem, "%#2X", num);
//	        break;
//	    case 5 :
//	        sprintf(tem, "%#4X", num);
//	        break;
//	    case 6 :
//	        sprintf(tem, "%#6x", num);
//	        break;
//	    case 7 :
//	        sprintf(tem, "%#8X", num);
//	        break;
//	    case 8 :
//	        sprintf(tem, "%#02X", num);
//	        break;
//	    case 9 :
//	        sprintf(tem, "%#04X", num);
//	        break;
//	    case 10 :
//	        sprintf(tem, "%#06X", num);
//	        break;
//	    case 11 :
//	        sprintf(tem, "%#08X", num);
//	        break;
//	    default:
//	        break;
//	}
//	
//	display_string_ascii(x, y, tem, size, word_color, back_color);
//}



//显示GB2312汉字及字符
void display_string_GB2312(u16 x, u16 y,const char *text, u16 word_color, u16 back_color)
{
	u8 i = 0;
	u8 fontbuf[32] = { 0 };
	while ((text[i] > 0x00))
	{
		if ((text[i] >= 0x20) && (text[i] <= 0x7e))
		{
			//font_ascii_h(fontbuf, text[i], 4);
			display_graphic_8x16(x, y, fontbuf, word_color, back_color);
			i++;
			x += 8;
		}
		else
		{
			//font_gb2312_h(fontbuf, text[i], text[i + 1]);
			display_graphic_16x16(x, y, fontbuf, word_color, back_color);
			i += 2;
			x += 16;
		}
	}
}

void LCD_write(char c)
{
	if (c == '\n') {
		cursor_y += textsize * 8;
		cursor_x = 0;
	}
	else if (c == '\r') {
		// skip em
	}
	else {
		LCD_DrawChar(cursor_x, cursor_y, c, textcolor, textbgcolor, textsize);
		cursor_x += textsize * 6;
		if (wrap && (cursor_x > (lcddev.max_width - textsize * 6))) {
			cursor_y += textsize * 8;
			cursor_x = 0;
		}
	}
}

// draw a character
void LCD_DrawChar(u16 x, u16 y, unsigned char c, u16 color, u16 bg, u8 size)
{
	u8 i, j, line;

	if ((x >= lcddev.max_width) || // Clip right
		(y >= lcddev.max_height) || // Clip bottom
		((x + 6 * size - 1) < 0) || // Clip left
		((y + 8 * size - 1) < 0))     // Clip top
		return;

	for (i = 0; i < 6; i++) 
	{
		if (i == 5)
			line = 0x0;
		else
			line = pgm_read_byte(font + (c * 5) + i);
		for (j = 0; j < 8; j++) {
			if (line & 0x1) {
				if (size == 1) // default size
					LCD_DrawPixel(x + i, y + j, color);
				else {  // big size
					LCD_DrawBox(x + (i*size), y + (j*size), size, size, color);
				}
			}
			else if (bg != color) {
				if (size == 1) // default size
					LCD_DrawPixel(x + i, y + j, bg);
				else {  // big size
					LCD_DrawBox(x + i * size, y + j * size, size, size, bg);
				}
			}
			line >>= 1;
		}
	}
}

void LCD_setTextSize(u8 s)
{
	textsize = (s > 0) ? s : 1;
}

void LCD_setTextColor(u16 c, u16 b)
{
	textcolor = c;
	textbgcolor = b;
}

void LCD_setTextWrap(u8  w)
{
	wrap = w;
}

void LCD_setCursor(u16 x, u16 y)
{
	cursor_x = x;
	cursor_y = y;
}

void LCD_text(const char * text, u16 x, u16 y)
{
	LCD_setTextWrap(FALSE);
	LCD_setCursor(x, y);
	while (*text)
	{
		LCD_write(*text++);
	}
}

void LCD_text_color(u16 x, u16 y, const char *text, u16 word_color, u16 back_color)
{
	LCD_setTextColor(word_color, back_color);
	LCD_text(text, x, y);
}

void LCD_textWrap(const char * text, u16 x, u16 y)
{
	LCD_setTextWrap(TRUE);
	LCD_setCursor(x, y);
	while (*text)
	{
		LCD_write(*text++);
	}
}

void LCD_print(const char * text)
{
	LCD_textWrap(text, cursor_x, cursor_y);
}

void LCD_println(const char * text)
{
	LCD_textWrap(text, cursor_x, cursor_y);
	LCD_write('\n');
}

void display_qrcode(u16 x_offset, u16 y_offset, const char *data, u8 size, u16 bg)
{
	QRCode qrcode;
	uint8_t qrcodeData[qrcode_getBufferSize(3)];

	qrcode_initText(&qrcode, qrcodeData, 3, ECC_HIGH, data);

	LCD_DrawBox(x_offset, y_offset, qrcode.size*size, qrcode.size*size, WHITE);
	for (uint8_t y = 0; y < qrcode.size; y++)
	{
		for (uint8_t x = 0; x < qrcode.size; x++) 
		{
			if (qrcode_getModule(&qrcode, x, y)) 
			{
				//tft.drawPixel(x_offset + x, y_offset + y, ST7735_BLACK);
				//LCD_DrawPixel(x_offset + (x * 2), y_offset + (y * 2), BLACK);
				//LCD_DrawPixel(x_offset + (x * 2) + 1, y_offset + (y * 2), BLACK);
				//LCD_DrawPixel(x_offset + (x * 2) + 1, y_offset + (y * 2) + 1, BLACK);
				//LCD_DrawPixel(x_offset + (x * 2), y_offset + (y * 2) + 1, BLACK);
				LCD_DrawBox(x_offset + x * size, y_offset + y * size, size, size, bg);
			}
		}
	}
}







