#include "bsp.h"

/*
*********************************************************************************************************
*	函 数 名: USART_Scanf
*	功能说明: 接收串口数据
*	形    参：min表示输入数据最小值 max 表示输入数据最大值
*	返 回 值: 返回串口接收到的数值
*********************************************************************************************************
*/
uint8_t USART_Scanf(uint8_t min, uint8_t max)
{
	int data_input;
	do
	{
		printf("有效数据必须在 %d 和 %d 之间\r\n请输入：", min, max);
		scanf("%d", &data_input);
	} while ((data_input < min) || (data_input > max));

	return (uint8_t)data_input;
}

