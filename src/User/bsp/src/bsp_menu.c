#include "bsp.h"

u16 key;
u8 MenuLv;				//�˵�����

//// ����ֵ���� 
//#define KV_NO                      (0x00)          // �� 
//#define KV_UP                      (0x02)          // �� 
//#define KV_DN                      (0x04)          // �� 
//#define KV_MD                      (0x08)          // �� 
//#define KV_LF                      (0x10)          // �� 
//#define KV_RT                      (0x20)          // �� 

//----------------------------------   ���˵�   --------------------------------------- 
MENU_PRMT  GSetPrmt;                   // �������ò��� 
MENU_TABLE GeneralSet[] =                        // �������� 
{
	{ " 1. Agenda                ", Menu_RF_1 },
	{ " 2. Sponsors              ", Menu_RF_2 },
	{ " 3. Secret Menu           ", Menu_RF_3 },
	{ " 4. TFT Light             ", Menu_RF_4 },
	{ " 5. About                 ", Menu_RF_5 },
	{ " 6. Game1                 ", Menu_TFT_Light },
	//{ " 1. Agenda                ", Menu_Agenda },
	//{ " 2. Sponsors              ", Menu_Sponsors },
	//{ " 3. Secret Menu           ", Menu_Secret },
	//{ " 4. TFT Light             ", Menu_TFT_Light },
	//{ " 5. About                 ", Menu_About },
	//{ " 6. Game1                 ", Menu_Game1 },
};

//-----------------------------------   �����˵�  ------------------------------------- 

//MENU_PRMT  ProfilePrmt;                   // �龰ģʽ���� 
//MENU_TABLE Profile[] =                            // �龰ģʽ 
//{
//	{ "1. ��׼         ", Menu_Null },                   // ��׼ 
//	{ "7. ����ģʽ     ", Menu_Null },                   // ����ģʽ 
//	//{ "8. �˳��˵�     ", Menu_ExitProfile },                   // �˳��˵� 
//};
//
//MENU_PRMT  ClockPrmt;                         // ʱ�������ڲ��� 
//MENU_TABLE Clock[] =                            // ʱ�������� 
//{
//	{ "1. ʱ��/��������", Menu_Null },                   // ʱ��/�������� 
//	//{ "5. �˳�ʱ������ ", Menu_ExitClockSet },       // �˳�ʱ������ 
//};

//MENU_PRMT  Day1_Prmt;                         //�������һ 
//MENU_TABLE Day1[] = 
//{
//	{ "09:00-09:20     ", Menu_Null }, 
//};
//
//MENU_PRMT  Day2_Prmt;                         //������̶� 
//MENU_TABLE Day2[] =
//{
//	{ "09:00-09:50     ", Menu_Null },
//};

//MENU_PRMT Agenda_Mode_Prmt;     //
//MENU_TABLE Agenda_Mode[] =                            // 
//{
//	{ " 1. August 30, 2018       ", Agenda30 },         //
//	{ " 2. August 31, 2018       ", Agenda31 },         //
//};

MENU_PRMT Test_Mode_Prmt;     //��ģʽ����
MENU_TABLE Test_Mode[] =                            //��ģʽ���� 
{
	{ " 1. �򵥲���                        ", Menu_Test_Easy },         //����ģ��ѡ��
	{ " 2. �߼�����                        ", Menu_Test_Expert },         //����ģ��ѡ��
	{ " 3. ģ����Ϣ                        ", Menu_RF_Info },         //����ģ��ѡ��
};

MENU_PRMT  Clock_Mode_Prmt;                         // ʱ�������ڲ��� 
MENU_TABLE Clock_Mode[] =                            // ʱ�������� 
{
	{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //����ģ��ѡ��
	//{ " 2. RTC_EX Clock                     ", Menu_RTC_EX_Clock },         //����ģ��ѡ��
	//{ " 3. BPC Clock                        ", Menu_BPC_Clock },         //����ģ��ѡ��
	//{ " 4. JJY Clock                        ", Menu_JJY_Clock },         //����ģ��ѡ��
};

//-----------------------------------   �����˵�  ------------------------------------- 

MENU_PRMT Test_Easy_Prmt;     //��ģʽ����
MENU_TABLE Test_Easy[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //����ģ��ѡ��
	//{ " 1. ��ʼ����                        ", Menu_RX_Easy },
	//{ " 2. ������                          ", Menu_TX_Num },
	//{ " 3. ��ʼ����                        ", Menu_TX_Easy },
};

MENU_PRMT Test_Expert_Prmt;     //�߼�ģʽ����
MENU_TABLE Test_Expert[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //����ģ��ѡ��
	//{ " 1. Ƶ������                        ", Menu_CH_Expert },
	//{ " 2. ��������                        ", Menu_Speed_Expert },
	//{ " 3. ��������                        ", Menu_Code_Expert },
	//{ " 4. �ź�ǿ��                        ", Menu_RSSI_Expert },
	//{ " 5. ��ʼ����                        ", Menu_RX_Expert },
	//{ " 6. ������                          ", Menu_TX_Num },
	//{ " 7. ��ʼ����                        ", Menu_TX_Expert },
};

MENU_PRMT BPC_Mode_Prmt;     //BPCģʽ����
MENU_TABLE BPC_Mode[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //����ģ��ѡ��
	//{ " 1. BPC Send                        ", BPC_Send },
	//{ " 2. BPC Receive                     ", BPC_Receive },
};

MENU_PRMT JJY_Mode_Prmt;     //JJYģʽ����
MENU_TABLE JJY_Mode[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //����ģ��ѡ��
	//{ " 1. JJY Send                        ", JJY_Send },
	//{ " 2. JJY Receive                     ", JJY_Receive },
};


/**************************************************************************************
* FunctionName   : Menu_Null()
* Description    : �պ���
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void Menu_Null(void)
{
	;
}

/**************************************************************************************
* FunctionName   : Menu_PrmtInit()
* Description    : ��ʼ���˵�����
* EntryParameter : prmt - �˵�����, num - ��ʾ��, page - ��ʾҳ
* ReturnValue    : None
**************************************************************************************/
void Menu_PrmtInit(MENU_PRMT *prmt, u8 num, u8 page)
{
	prmt->ExitMark = 0;                     // ����˳��˵���־ 
	prmt->Cursor = 0;                     // ������� 
	prmt->PageNo = 0;                     // ҳ���� 
	prmt->Index = 0;                     // �������� 
	prmt->DispNum = num;                    // ҳ�����ʾ��Ŀ�� 
	prmt->MaxPage = page;                    // ���ҳ�� 
}

/**************************************************************************************
* FunctionName   : Menu_Display()
* Description    : ��ʾ�˵�
* EntryParameter : page - ��ʾҳ��dispNum - ÿһҳ����ʾ�cursor - ���λ��
* ReturnValue    : None
**************************************************************************************/
void Menu_Display(MENU_TABLE *menu, u8 page, u8 dispNum, u8 cursor)
{
	u8 i;
	for (i = 0; i < dispNum; i++)
	{
		if (cursor == i)
		{
			LCD_setTextColor(RED, BLACK);
			LCD_text(menu[page + i].MenuName, 0, (i + 3) * 12);
			//display_string_GB2312(0, (i + 3) * 16, menu[page + i].MenuName, WHITE, RED);           // ������ʾ�˵��� 
		}
		else
		{
			LCD_setTextColor(GREEN, BLACK);
			LCD_text(menu[page + i].MenuName, 0, (i + 3) * 12);
			//display_string_GB2312(0, (i + 3) * 16, menu[page + i].MenuName, RED, WHITE);             // ��ʾ�˵���   
		}
	}
}

/**************************************************************************************
* FunctionName   : Menu_Move()
* Description    : �˵��ƶ�
* EntryParameter : prmt - �˵�����, key - ����ֵ
* ReturnValue    : ��ȷ�Ϸ���0�����򷵻�1
**************************************************************************************/
u8 Menu_Move(MENU_PRMT *prmt, uint8_t key_menu)
{
	u8 rValue = 1;

	switch (key_menu)
	{
	case KEY_DOWN_U:                   // ���� 
		if (prmt->Cursor != 0)                       // ��겻�ڶ��� 
		{
			prmt->Cursor--;                        // ������� 
		}
		else                        // ����ڶ��� 
		{
			if (prmt->PageNo != 0)                      // ҳ��û�е���С 
			{
				prmt->PageNo--;                       // ���Ϸ� 
			}
			else
			{
				prmt->Cursor = prmt->DispNum - 1;                      // ��굽�� 
				prmt->PageNo = prmt->MaxPage - 1;                  // ���ҳ 
			}
		}
		break;

	case KEY_DOWN_D:                   // ���� 
		if (prmt->Cursor < prmt->DispNum - 1)                          // ���û�е��ף��ƶ���� 
		{
			prmt->Cursor++;                        // ��������ƶ� 
		}
		else                                                         // ��굽�� 
		{
			if (prmt->PageNo < prmt->MaxPage - 1)                      // ҳ��û�е��ף�ҳ���ƶ� 
			{
				prmt->PageNo++;                       // �·�һҳ 
			}
			else                                                     // ҳ��͹�궼���ף����ؿ�ʼҳ 
			{
				prmt->Cursor = 0;
				prmt->PageNo = 0;
			}
		}
		break;

	case KEY_DOWN_A:                   // ȷ��   
		prmt->Index = prmt->Cursor + prmt->PageNo;                   // ����ִ��������� 
		rValue = 0;
		break;

	case KEY_DOWN_B:                   // ȡ��   
									//prmt->Index = prmt->Cursor + prmt->PageNo;                   // ����ִ��������� 
		if (MenuLv != 1)
		{
			prmt->ExitMark = 0x01;
			MenuLv -= 1;
			rValue = 2;
		}
		break;

	case KEY_DOWN_L:                   // ����������� 
		prmt->Cursor = 0;
		prmt->PageNo = 0;
		break;

	case KEY_DOWN_R:                   // �Ҽ������ײ� 
		prmt->Cursor = prmt->DispNum - 1;                              // ��굽�� 
		prmt->PageNo = prmt->MaxPage - 1;                          // ���ҳ 
		break;

	default:
		break;
	}
	return rValue;                          // ����ִ������ 
}

/**************************************************************************************
* FunctionName   : Menu_Process()
* Description    : ����˵���
* EntryParameter : menuName - �˵����ƣ�prmt - �˵�������table - �˵�����, num - �˵�����
* ReturnValue    : None
**************************************************************************************/
void Menu_Process(u8 *menuName, MENU_PRMT *prmt, MENU_TABLE *table, u8 num)
{
	u8 key_temp;

	if (num > PAGE_DISP_NUM)
	{
		Menu_PrmtInit(prmt, PAGE_DISP_NUM, num - PAGE_DISP_NUM + 1);         // ��ʾ������ҳ�����ã���������һҳ��Ҫ��ҳ������ҳ�� 
	}
	else
	{
		Menu_PrmtInit(prmt, num, 1);                          // ��ʾ������ҳ�����ã�������һҳ���ҳ��Ϊ1
	}
	//lcd_clean_screen(WHITE);
	LCD_setTextColor(WHITE, BLACK);
	LCD_text("--------------------------", 0, 0);
	LCD_text(menuName, 0, 12);
	LCD_text("--------------------------", 0, 24);
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(0, 16, menuName, RED, WHITE);                                   // �˵�������ʾ 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	Menu_Display(table, prmt->PageNo, prmt->DispNum, prmt->Cursor);               // ��ʾ�˵��� 
	do
	{
		key_temp = bsp_GetKey();	// ��ȡ����         
		if (key_temp != KEY_NONE)
		{
			if (Menu_Move(prmt, key_temp) == 0x00)                          // �˵��ƶ����ж����Ƿ���ȷ�ϼ����� 
			{
				//LCD_Clear(BLACK);								 // ���� 
				LCD_Fill(0, 32, 160, 128, BLACK);
				table[prmt->Index].ItemHook();                               // ִ����Ӧ�� 
			}
			if (key_temp == KEY_DOWN_A)
			{
				LCD_Fill(0, 32, 160, 128, BLACK);
				//LCD_Clear(BLACK);                       // ���� 
			}
			//lcd_clean_screen(WHITE); 
			LCD_setTextColor(WHITE, BLACK);
			LCD_text("--------------------------", 0, 0);
			LCD_text(menuName, 0, 12);
			LCD_text("--------------------------", 0, 24);
			//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // �˵�������ʾ 
			//display_string_GB2312(0, 16, menuName, RED, WHITE);                                   // �˵�������ʾ 
			//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // �˵�������ʾ 
			Menu_Display(table, prmt->PageNo, prmt->DispNum, prmt->Cursor);               // ��ʾ�˵��� 
		}
	} while (prmt->ExitMark == 0);
}

/**************************************************************************************
* FunctionName   : MenuGeneralSet()
* Description    : ��������
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void MenuGeneralSet(u8 num)
{
	u8 menuNum;
	menuNum = sizeof(GeneralSet) / sizeof(GeneralSet[0]) - num;         // �˵����� 
	MenuLv = 1;
	Menu_Process("      HITB 2018 GSEC      ", &GSetPrmt, GeneralSet, menuNum);
}

///**************************************************************************************
//* FunctionName   : Menu_Profile()
//* Description    : �龰ģʽ
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_Profile(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Profile) / sizeof(Profile[0]);         // �˵����� 
//	MenuLv = 2;
//	Menu_Process(" -= �龰ģʽ =- ", &ProfilePrmt, Profile, menuNum);
//}

///**************************************************************************************
//* FunctionName   : Menu_ExitProfile()
//* Description    : �˳��龰ģʽ
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_ExitProfile(void)
//{
//	ProfilePrmt.ExitMark = 0x01;         // �˳��龰ģʽ 
//	lcd_clean_screen(0);              // ����   
//}

///**************************************************************************************
//* FunctionName   : Menu_SetClock()
//* Description    : ʱ������������
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_SetClock(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Clock) / sizeof(Clock[0]);         // �˵����� 
//	MenuLv = 2;
//	Menu_Process(" -= ʱ������ =- ", &ClockPrmt, Clock, menuNum);
//}

///**************************************************************************************
//* FunctionName   : Menu_ExitClockSet()
//* Description    : �˳�������ʱ��
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_ExitClockSet(void)
//{
//	ClockPrmt.ExitMark = 0x01;             // �˳�ʱ������ 
//	lcd_clean_screen(0);              // ����   
//}

//void Menu_Day1(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Day1) / sizeof(Day1[0]);         // �˵����� 
//	MenuLv = 2;
//	Menu_Process("11��24�ջ����ճ�", &Day1_Prmt, Day1, menuNum);
//}
//
//void Menu_Day2(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Day2) / sizeof(Day2[0]);         // �˵����� 
//	MenuLv = 2;
//	Menu_Process("11��25�ջ����ճ�", &Day2_Prmt, Day2, menuNum);
//}

///**************************************************************************************
//* FunctionName   : Easy_Mode()
//* Description    : �򵥲���
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_Profile(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Profile) / sizeof(Profile[0]);         // �˵����� 
//	MenuLv = 2;
//	Menu_Process(" -= �龰ģʽ =- ", &ProfilePrmt, Profile, menuNum);
//}

/************************************* �����˵� *************************************************/

void Menu_Mode(void)
{
	u8 menuNum;
	menuNum = sizeof(Test_Mode) / sizeof(Test_Mode[0]);         // �˵����� 
	MenuLv = 2;
	Menu_Process("           ģʽѡ��           ", &Test_Mode_Prmt, Test_Mode, menuNum);
}


void Menu_Clock(void)
{
	u8 menuNum;
	menuNum = sizeof(Clock_Mode) / sizeof(Clock_Mode[0]);         // �˵����� 
	MenuLv = 2;
	Menu_Process("           ʱ�Ӳ���           ", &Clock_Mode_Prmt, Clock_Mode, menuNum);
}

/************************************* �����˵� *************************************************/

void Menu_Test_Easy(void)
{
	u8 menuNum;
	menuNum = sizeof(Test_Easy) / sizeof(Test_Easy[0]);         // �˵����� 
	MenuLv = 3;
	Menu_Process("           �򵥲���           ", &Test_Easy_Prmt, Test_Easy, menuNum);
}

void Menu_Test_Expert(void)
{
	u8 menuNum;
	menuNum = sizeof(Test_Expert) / sizeof(Test_Expert[0]);         // �˵����� 
	MenuLv = 3;
	Menu_Process("           �߼�����           ", &Test_Expert_Prmt, Test_Expert, menuNum);
}

void Menu_RF_Info(void)
{

	//u8 menuNum;
	//menuNum = sizeof(Expert1) / sizeof(Expert1[0]);         // �˵����� 
	//MenuLv = 2;
	//Menu_Process("           �߼�����           ", &ExpertPrmt_1, Easy1, menuNum);

}

void Menu_BPC_Clock(void)
{
	u8 menuNum;
	menuNum = sizeof(BPC_Mode) / sizeof(BPC_Mode[0]);         // �˵����� 
	MenuLv = 3;
	Menu_Process("          BPC�粨��           ", &BPC_Mode_Prmt, BPC_Mode, menuNum);
}

void Menu_JJY_Clock(void)
{
	u8 menuNum;
	menuNum = sizeof(JJY_Mode) / sizeof(JJY_Mode[0]);         // �˵����� 
	MenuLv = 3;
	Menu_Process("          JJY�粨��           ", &JJY_Mode_Prmt, JJY_Mode, menuNum);
}

/************************************* ���� *************************************************/

void Menu_RX_Easy(void)
{
	//TIM5_CH1_Cap_Init(0XFFFFFFFF, 84 - 1); //��1MHzƵ�ʼ���
	//ASK_Mode(1);
	//ask_rx_enable(RX1_ASK, true);

	//lcd_clean_screen(WHITE);
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(0, 16, "             ����             ", RED, WHITE);          // �˵�������ʾ 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(2, 64, "1527 ADDR: ", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(2, 80, "1527 DATA: ", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(2, 96, "1527 Get Num: ", RED, WHITE);           // �˵�������ʾ 

	//Time_RESET(TIM5);
	//saveCount = 0;

	//while (1)
	//{
	//	ask_rx_available();
	//	delay_ms(10);
	//}
}

void Menu_TX_Num(void)
{
}

void Menu_TX_Easy(void)
{
	//u16 tx_num = 0;
	//u32 t_addr;
	//u16 t_data;

	//ASK_Mode(1);

	//lcd_clean_screen(WHITE);
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(0, 16, "             ����             ", RED, WHITE);          // �˵�������ʾ 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(2, 64, "1527 ADDR: ", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(2, 80, "1527 DATA: ", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(2, 96, "1527 Send Num: 4*", RED, WHITE);           // �˵�������ʾ 


	//for (t_addr = 0; t_addr < 1048576; t_addr++)       //��ַ����
	//{
	//	for (t_data = 0; t_data < 16; t_data++)        //���ݱ���
	//	{
	//		ask_send_1527(TX1_ASK, t_addr, t_data, 4);
	//		display_string_GB2312(90, 64, "                   ", RED, WHITE);           // �˵�������ʾ 
	//		display_string_GB2312(90, 80, "                   ", RED, WHITE);           // �˵�������ʾ 
	//		display_num_format(90, 64, t_addr, 4, "%04X", RED, WHITE);           // �˵�������ʾ 
	//		display_num_format(90, 80, t_data, 4, "%02X", RED, WHITE);           // �˵�������ʾ 
	//		display_num_format(140, 96, ++tx_num, 4, "%u", RED, WHITE);           // �˵�������ʾ 
	//		delay_ms(500);
	//	}
	//}
}

void Menu_CH_Expert(void)
{
}

void Menu_Speed_Expert(void)
{
}

void Menu_Code_Expert(void)
{
}

void Menu_RSSI_Expert(void)
{
}

void Menu_RX_Expert(void)
{
}

void Menu_TX_Expert(void)
{
}


void Menu_RF_1(void)
{
	//CC1101_Init();
	Menu_Mode();

}

void Menu_RF_2(void)
{
	//SI4463_Init();
	Menu_Mode();

}

void Menu_RF_3(void)
{
	//ASK_Init();
	Menu_Mode();
}

void Menu_RF_4(void)
{
	//nRF24L01_Init();
	Menu_Mode();

}

void Menu_RF_5(void)
{
	//A7125_Init();
	Menu_Mode();

}

void Menu_RTC_OB_Clock(void)
{
	Menu_Mode();
}

void Menu_TFT_Light(void)
{
	//u8 light_temp = 5;
	//u8 flag = 1;
	//u8 key_lcd;

	//LCD_Clear(WHITE);
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(0, 16, "           ��������           ", RED, WHITE);                                   // �˵�������ʾ 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // �˵�������ʾ 
	//display_string_GB2312(0, 64, " <          -    -          > ", RED, WHITE);           // �˵�������ʾ 

	//display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // �˵�������ʾ 

	//do
	//{
	//	key_lcd = bsp_GetKey();	// ��ȡ����    
	//	if (key_lcd != KEY_NONE)
	//	{
	//		switch (key_lcd)
	//		{
	//		case KEY_DOWN_L:
	//			if (light_temp > 0)
	//			{
	//				light_temp--;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // �˵�������ʾ 
	//			lcd_light_set(light_temp);
	//			break;
	//		case KEY_DOWN_R:
	//			if (light_temp < 10)
	//			{
	//				light_temp++;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // �˵�������ʾ 
	//			lcd_light_set(light_temp);
	//			break;
	//		case KEY_DOWN_U:
	//			if (light_temp < 10)
	//			{
	//				light_temp++;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // �˵�������ʾ 
	//			lcd_light_set(light_temp);
	//			break;
	//		case KEY_DOWN_D:
	//			if (light_temp > 0)
	//			{
	//				light_temp--;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // �˵�������ʾ 
	//			lcd_light_set(light_temp);
	//			break;
	//		case KEY_DOWN_A:
	//			flag = 0;
	//			break;
	//		case KEY_DOWN_B:
	//			flag = 0;
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//} while (flag);
}


