#ifndef __BSP_TFT_H__
#define __BSP_TFT_H__

#ifdef __cplusplus
extern "C" {
#endif 


//------------------------- 预定义 --------------------------------------//

//#define TFT_ST7735_1_44		//ST7735S_STD	36h寄存器写C8是RGB
#define TFT_ST7735_1_8		//ST7735B_ALT	36h寄存器写C0是RGB
//#define TFT_ILI9163_1_8		//ILI9163B
// #define TFT_ILI9341_2_2		//ILI9341B

#define TFT_Light_Ctl           //使能背光亮度调节

//------------------------- LCD接线和命令 --------------------------------------//

#define LCD_SPI		SPI1
#define LCD_CS		PBout(12) 	//LCD片选
#define LCD_A0		PBout(10) 	//寄存器选择	   
#define LCD_RES		PBout(11)  	//低电平复位
#define LCD_BK		PBout(1)  	//背光

#define LCD_CMD  0	//写命令
#define LCD_DATA 1	//写数据

#define ON	1	//开
#define OFF 0	//关

//------------------------- 屏幕物理像素设置 --------------------------------------//

#if defined (TFT_ST7735_1_44)	//ST7735S

#define LCD_ID				0x7735
#define LCD_BASE_WIDTH		0
#define LCD_BASE_HEIGHT		32
#define LCD_MAX_WIDTH		128
#define LCD_MAX_HEIGHT		160
#define LCD_MOVE_WIDTH		0		//偏移地址
#define LCD_MOVE_HEIGHT		0

#define LCD_WRAM			0x2C
#define LCD_SETX			0x2A
#define LCD_SETY			0x2B

#define LCD_DIR_REG			0x36
#define LCD_RGB				0x08

#define DLOOK		0xC0	//0点在左上，正竖屏
#define ULOOK		0x00	//0点在右下，倒竖屏
#define LLOOK		0xA0	//0点在右上，左看横屏
#define RLOOK		0x60	//0点在左下，右看横屏

#elif defined (TFT_ST7735_1_8)	//ST7735B

#define LCD_ID				0x7735
#define LCD_BASE_WIDTH		0
#define LCD_BASE_HEIGHT		0
#define LCD_MAX_WIDTH		128
#define LCD_MAX_HEIGHT		160
#define LCD_MOVE_WIDTH		2		//偏移地址
#define LCD_MOVE_HEIGHT		1

#define LCD_WRAM			0x2C
#define LCD_SETX			0x2A
#define LCD_SETY			0x2B

#define LCD_DIR_REG			0x36
#define LCD_RGB				0x00

#define DLOOK		0xC0	//0点在左上，正竖屏
#define ULOOK		0x00	//0点在右下，倒竖屏
#define LLOOK		0xA0	//0点在右上，左看横屏
#define RLOOK		0x60	//0点在左下，右看横屏

#elif defined (TFT_ILI9163_1_8)	//ILI9163B

#define LCD_ID				0x9163
#define LCD_BASE_WIDTH		0
#define LCD_BASE_HEIGHT		0
#define LCD_MAX_WIDTH		128
#define LCD_MAX_HEIGHT		160
#define LCD_MOVE_WIDTH		0		//偏移地址
#define LCD_MOVE_HEIGHT		0

#define LCD_WRAM			0x2C
#define LCD_SETX			0x2A
#define LCD_SETY			0x2B

#define LCD_DIR_REG			0x36
#define LCD_RGB				0x00

#define DLOOK		0xC0	//0点在左上，正竖屏
#define ULOOK		0x00	//0点在右下，倒竖屏
#define LLOOK		0xA0	//0点在右上，左看横屏
#define RLOOK		0x60	//0点在左下，右看横屏

#elif defined(TFT_ILI9341_2_2)	//ILI9341

#define LCD_ID				0x9341
#define LCD_BASE_WIDTH		0
#define LCD_BASE_HEIGHT		0
#define LCD_MAX_WIDTH		240
#define LCD_MAX_HEIGHT		320
#define LCD_MOVE_WIDTH		0		//偏移宽度
#define LCD_MOVE_HEIGHT		0		//偏移高度，屏幕下面有4排遮住了看不到

#define LCD_WRAM			0x2C
#define LCD_SETX			0x2A
#define LCD_SETY			0x2B

#define LCD_DIR_REG			0x36
#define LCD_RGB				0x08

#define DLOOK		0x40	//0点在左上，正竖屏
#define ULOOK		0x80	//0点在右下，倒竖屏
#define LLOOK		0x20	//0点在右上，左看横屏
#define RLOOK		0xe0	//0点在左下，右看横屏

#endif

//------------------------- 颜色设置 --------------------------------------//


//画笔颜色 RGB565
#define BLACK       	0x0000      /*   0,   0,   0 */
#define NAVY        	0x000F      /*   0,   0, 128 */
#define DARKGREEN   	0x03E0      /*   0, 128,   0 */
#define DARKCYAN    	0x03EF      /*   0, 128, 128 */
#define MAROON      	0x7800      /* 128,   0,   0 */
#define PURPLE      	0x780F      /* 128,   0, 128 */
#define OLIVE       	0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   	0xC618      /* 192, 192, 192 */	 //浅灰色(PANNEL),窗体背景色
#define DARKGREY    	0x7BEF      /* 128, 128, 128 */
#define BLUE        	0x001F      /*   0,   0, 255 */
#define GREEN       	0x07E0      /*   0, 255,   0 */
#define CYAN        	0x07FF      /*   0, 255, 255 */
#define RED         	0xF800      /* 255,   0,   0 */
#define MAGENTA     	0xF81F      /* 255,   0, 255 */
#define YELLOW      	0xFFE0      /* 255, 255,   0 */
#define WHITE       	0xFFFF      /* 255, 255, 255 */
#define ORANGE      	0xFD20      /* 255, 165,   0 */
#define GREENYELLOW 	0xAFE5      /* 173, 255,  47 */
#define PINK        	0xF81F
 
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色

//GUI颜色 RGB565

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色

//以上三色为PANEL的颜色 RGB565

#define LIGHTGREEN     	 0X841F //浅绿色
//#define LIGHTGRAY 		 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

//------------------------- 参数、函数预定义 --------------------------------------//

//LCD重要参数集
typedef struct
{
	u16 id;				//LCD ID
	u8  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。	

	u16 base_width;		//LCD 基础宽度
	u16 base_height;	//LCD 基础高度
						//u16 width;			//LCD 使用宽度
						//u16 height;			//LCD 使用高度
	u16 max_width;		//LCD 全屏宽度
	u16 max_height;		//LCD 全屏高度

	u16 move_width;		//偏移宽度
	u16 move_height;	//偏移高度

	u16	wramcmd;		//开始写gram指令
	u16 setxcmd;		//设置x坐标指令
	u16 setycmd;		//设置y坐标指令 
}_lcd_dev;

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
//LCD的画笔颜色和背景色

extern u16  POINT_COLOR;//默认红色    
extern u16  BACK_COLOR; //背景颜色.默认为白色

void LCD_WR(u8 cmd, u8 data1);
void LCD_WR_16Bit(u16 data1);
void LCD_WR_Reg(u8 LCD_Reg, u8 LCD_RegValue);
void LCD_WR_GRAM(void);
u16 LCD_BGR2RGB(u16 c);
void LCD_RESET(void);
void LCD_GPIO_Init(void);
void LCD_Init(void);
void LCD_Light_Init(void);
void LCD_Light_Set(u8 light);
void lcd_param(void);
void lcd_set_window(u16 x, u16 y, u16 w, u16 h);
void lcd_cursor(u16 Xpos, u16 Ypos);
void LCD_Rotate(u8 dir);
void LCD_Clear(u16 color);
void LCD_Clear_Sel(u16 x, u16 y, u16 x_total, u16 y_total, u16 color);
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color);
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);
void LCD_DrawPixel(u16 x, u16 y, u16 color);
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);
void LCD_DrawFastHLine(u16 x1, u16 y1, u16 w, u16 color);
void LCD_DrawFastVLine(u16 x1, u16 y1, u16 h, u16 color);
void LCD_DrawCircle(u16 x0, u16 y0, u8 r, u16 color);
void LCD_FillCircle(u16 x0, u16 y0, u8 r, u16 color);
void LCD_DrawRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);
void LCD_FillRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);
void LCD_DrawFrame(u16 x1, u16 y1, u16 w, u16 h, u16 color);
void LCD_DrawBox(u16 x1, u16 y1, u16 w, u16 h, u16 color);
void LCD_DrawRoundRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 r, u16 color);
void LCD_FillRoundRect(u16 x1, u16 y1, u16 x2, u16 y2, u16 r, u16 color);
void LCD_DrawTriangle(u16 x0, u16 y0, u16 x1, u16 y1, u16 x2, u16 y2, u16 color);
//void LCD_DrawBitmap(u16 x0, u16 y0, u8 *bitmap, u16 w, u16 h, u16 color, u16 bg);
void LCD_DrawBitmap(u16 x0, u16 y0, const unsigned char  *bitmap, u16 w, u16 h, u16 color, u16 bg);
void LCD_DrawChar(u16 x, u16 y, unsigned char c, u16 color, u16 bg, u8 size);
void LCD_write(char c);
void LCD_DrawChar(u16 x, u16 y, unsigned char c, u16 color, u16 bg, u8 size);
void LCD_setTextSize(u8 s);
void LCD_setTextColor(u16 c, u16 b);
void LCD_setTextWrap(u8  w);
void LCD_setCursor(u16 x, u16 y);
void LCD_text(const char * text, u16 x, u16 y);
void LCD_textWrap(const char * text, u16 x, u16 y);
void LCD_print(const char * text);
void LCD_println(const char * text);
void LCD_text_color(u16 x, u16 y, const char *text,u16 word_color, u16 back_color);

void LCD_Display(u8 mode);

void display_graphic_5x7(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color);
void display_graphic_8x16(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color);
void display_graphic_16x16(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color);
void display_graphic_32x32(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color);
void display_graphic_48x48(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color);
//void display_graphic_128x64(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color);
//void display_graphic_192x96(u16 x, u16 y, u8 *dp, u16 word_color, u16 back_color);
void display_char_ascii(u16 x, u16 y, char text, u8 size, u16 word_color, u16 back_color);
void display_string_ascii(u16 x, u16 y, const char *text, u8 size, u16 word_color, u16 back_color);
void display_num(u16 x, u16 y, u32 num, u8 size, u16 word_color, u16 back_color);
void display_num_format(u16 x, u16 y, u32 num, u8 size, char * format, u16 word_color, u16 back_color);
//void display_num_dec(u16 x, u16 y, u32 num, u8 size, u8 mode, u16 word_color, u16 back_color);
//void display_num_hex(u16 x, u16 y, u32 num, u8 size, u8 mode, u16 word_color, u16 back_color);
void display_string_GB2312(u16 x, u16 y, const char *text, u16 word_color, u16 back_color);

void display_qrcode(u16 x_offset, u16 y_offset, const char *data, u8 size, u16 bg);

#ifdef __cplusplus
	}
#endif /* __cplusplus */

#endif /* __BSP_TFT_H__ */
