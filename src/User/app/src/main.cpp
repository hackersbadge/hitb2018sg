/*
*********************************************************************************************************
*
*	模块名称 : 主程序入口
*	文件名称 : main.c
*	版    本 : V1.0
*	说    明 : 串口通信例子，和PC机超级终端软件进行交互
*	修改记录 :
*		版本号  日期       作者    说明
*		V1.0    2015-08-30   首发
*
*	Copyright (C), 2015-2016,  
*
*********************************************************************************************************
*/

#include "bsp.h"				/* 底层硬件驱动 */
#include "bsp_menu.h"
/*
*********************************************************************************************************
*	函 数 名: main
*	功能说明: c程序入口
*	形    参：无
*	返 回 值: 错误代码(无需处理)
*********************************************************************************************************
*/
int main(void)
{
	//uint8_t ucKeyCode;	
	//uint16_t i,j;

	/*
		ST固件库中的启动文件已经执行了 SystemInit() 函数，该函数在 system_stm32f4xx.c 文件，主要功能是
	配置CPU系统的时钟，内部Flash访问时序，配置FSMC用于外部SRAM
	*/
	
	bsp_Init();		/* 硬件初始化 */

	hitb_start();
	while(1);
	
//	PrintfID();	/* 打印例程名称和版本等信息 */
	LCD_Clear(BLACK);
//	Menu_DrawFrame();
//	Menu_Init();
	
	bsp_StartAutoTimer(0, 500);	/* 启动1个1000ms的自动重装的定时器 */

//******************************* Menu *********************************//

	/* 主程序大循环 */
	while (1)
	{
		bsp_Idle();		/* CPU空闲时执行的函数，在 bsp.c */
//		Menu_Loop();
		
		if (bsp_CheckTimer(0))	/* 判断定时器超时时间 */
		{
//			Menu_UpdateFrame();

			//uint16_t adc;

			//adc = bsp_GetAdc_Average(1);

			///* 注意： 末尾只有 \r回车, 没有\n换行，可以使PC超级终端界面稳定在1行显示 */
			//{
			//	/* 超级终端界面上会显示一个不断旋转的字符
			//	增加这个功能，是为了避免程序死机的假象，因为ADC采样值很稳定
			//	*/
			//	static uint8_t pos = 0;

			//	if (pos == 0)
			//		printf("|");
			//	else if (pos == 1)
			//		printf("/");
			//	else if (pos == 2)
			//		printf("-");
			//	else if (pos == 3)
			//		printf("\\");		/* 注意：这个特殊字符需要转义 */

			//	if (++pos >= 4)
			//	{
			//		pos = 0;
			//	}

			//	printf(" PC4口线ADC采样值 = %5d , 电压 = %4dmV\r",
			//		adc, ((uint32_t)adc * 2500) / 4095);
			//}
		}


//		bsp_DelayMS(100);
//		/* 处理按键事件 */
//		ucKeyCode = bsp_GetKey();
//		if (ucKeyCode > 0)
//		{
//			/* 有键按下 */
//			switch (ucKeyCode)
//			{
//				case KEY_DOWN_L:		/* 摇杆LEFT键按下, 控制LED显示流动 */
//					printf("KEY_L\n");
//					break;		
//				
//				case KEY_DOWN_R:		/* 摇杆RIGHT键按下 */
//					printf("KEY_R\n");
//					break;

//				case KEY_DOWN_U:		/* 摇杆UP键按下 */
//					printf("KEY_U\n");
//					break;				
//				
//				case KEY_DOWN_D:		/* 摇杆DOWN键按下 */
//					printf("KEY_D\n");
//					break;	
//				
//				case KEY_DOWN_A:		/* 摇杆LEFT键按下, 控制LED显示流动 */
//					printf("KEY_A\n");
//					break;		
//				
//				case KEY_DOWN_B:		/* 摇杆RIGHT键按下 */
//					printf("KEY_B\n");
//					break;

//				case KEY_DOWN_X:		/* 摇杆UP键按下 */
//					printf("KEY_X\n");
//					break;				
//				
//				case KEY_DOWN_Y:		/* 摇杆DOWN键按下 */
//					printf("KEY_Y\n");
//					break;	
//				
//				default:
//					break;
//			}
//		}
	}
}

/*****************************  (END OF FILE) *********************************/
