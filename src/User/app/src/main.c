/*
*********************************************************************************************************
*
*	ģ������ : ���������
*	�ļ����� : main.c
*	��    �� : V1.0
*	˵    �� : ����ͨ�����ӣ���PC�������ն�������н���
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		V1.0    2015-08-30 armfly  �׷�
*
*	Copyright (C), 2015-2016, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "bsp.h"				/* �ײ�Ӳ������ */

unsigned long w0[6] = { 0x000000,0x000000,0x000000,
						  0x000000,0x000000,0x000000 };
unsigned long w1[6] = { 0x0000ff,0x0000ff,0x0000ff,
						  0x0000ff,0x0000ff,0x0000ff };
unsigned long w2[6] = { 0x00ff00,0x00ff00,0x00ff00,
						  0x00ff00,0x00ff00,0x00ff00 };
unsigned long w3[6] = { 0xff0000,0xff0000,0xff0000,
						  0xff0000,0xff0000,0xff0000 };
unsigned long w4[6] = { 0xffffff,0xffffff,0xffffff,
						  0xffffff,0xffffff,0xffffff };

/*
*********************************************************************************************************
*	�� �� ��: main
*	����˵��: c�������
*	��    �Σ���
*	�� �� ֵ: �������(���账��)
*********************************************************************************************************
*/
int main(void)
{
	uint8_t ucKeyCode;	
	uint16_t i,j;

	/*
		ST�̼����е������ļ��Ѿ�ִ���� SystemInit() �������ú����� system_stm32f4xx.c �ļ�����Ҫ������
	����CPUϵͳ��ʱ�ӣ��ڲ�Flash����ʱ������FSMC�����ⲿSRAM
	*/
	
	bsp_Init();		/* Ӳ����ʼ�� */
	
	PrintfID();	/* ��ӡ�������ƺͰ汾����Ϣ */
	
	LCD_Clear(BLACK);

	bsp_StartAutoTimer(0, 500);	/* ����1��1000ms���Զ���װ�Ķ�ʱ�� */

//******************************* Menu *********************************//
	while (1)
	{
		MenuGeneralSet(0);
	}

	/* �������ѭ�� */
	while (1)
	{
		bsp_Idle();		/* CPU����ʱִ�еĺ������� bsp.c */

		bsp_DelayMS(100);
		/* �������¼� */
		ucKeyCode = bsp_GetKey();
		if (ucKeyCode > 0)
		{
			/* �м����� */
			switch (ucKeyCode)
			{
				case KEY_DOWN_L:		/* ҡ��LEFT������, ����LED��ʾ���� */
					printf("KEY_L\n");
					break;		
				
				case KEY_DOWN_R:		/* ҡ��RIGHT������ */
					printf("KEY_R\n");
					break;

				case KEY_DOWN_U:		/* ҡ��UP������ */
					printf("KEY_U\n");
					break;				
				
				case KEY_DOWN_D:		/* ҡ��DOWN������ */
					printf("KEY_D\n");
					break;	
				
				case KEY_DOWN_A:		/* ҡ��LEFT������, ����LED��ʾ���� */
					printf("KEY_A\n");
					break;		
				
				case KEY_DOWN_B:		/* ҡ��RIGHT������ */
					printf("KEY_B\n");
					break;

				case KEY_DOWN_X:		/* ҡ��UP������ */
					printf("KEY_X\n");
					break;				
				
				case KEY_DOWN_Y:		/* ҡ��DOWN������ */
					printf("KEY_Y\n");
					break;	
				
				default:
					break;
			}
		}
	}
}

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
