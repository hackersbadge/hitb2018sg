#include "bsp.h"

u16 key;
u8 MenuLv;				//菜单级别

//// 按键值定义 
//#define KV_NO                      (0x00)          // 无 
//#define KV_UP                      (0x02)          // 上 
//#define KV_DN                      (0x04)          // 下 
//#define KV_MD                      (0x08)          // 中 
//#define KV_LF                      (0x10)          // 左 
//#define KV_RT                      (0x20)          // 右 

//----------------------------------   主菜单   --------------------------------------- 
MENU_PRMT  GSetPrmt;                   // 常规设置参数 
MENU_TABLE GeneralSet[] =                        // 常规设置 
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

//-----------------------------------   二级菜单  ------------------------------------- 

//MENU_PRMT  ProfilePrmt;                   // 情景模式参数 
//MENU_TABLE Profile[] =                            // 情景模式 
//{
//	{ "1. 标准         ", Menu_Null },                   // 标准 
//	{ "7. 离线模式     ", Menu_Null },                   // 离线模式 
//	//{ "8. 退出菜单     ", Menu_ExitProfile },                   // 退出菜单 
//};
//
//MENU_PRMT  ClockPrmt;                         // 时间与日期参数 
//MENU_TABLE Clock[] =                            // 时间与日期 
//{
//	{ "1. 时间/日期设置", Menu_Null },                   // 时间/日期设置 
//	//{ "5. 退出时钟设置 ", Menu_ExitClockSet },       // 退出时钟设置 
//};

//MENU_PRMT  Day1_Prmt;                         //会议议程一 
//MENU_TABLE Day1[] = 
//{
//	{ "09:00-09:20     ", Menu_Null }, 
//};
//
//MENU_PRMT  Day2_Prmt;                         //会议议程二 
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

MENU_PRMT Test_Mode_Prmt;     //简单模式参数
MENU_TABLE Test_Mode[] =                            //简单模式设置 
{
	{ " 1. 简单测试                        ", Menu_Test_Easy },         //无线模块选择
	{ " 2. 高级测试                        ", Menu_Test_Expert },         //无线模块选择
	{ " 3. 模块信息                        ", Menu_RF_Info },         //无线模块选择
};

MENU_PRMT  Clock_Mode_Prmt;                         // 时间与日期参数 
MENU_TABLE Clock_Mode[] =                            // 时间与日期 
{
	{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //无线模块选择
	//{ " 2. RTC_EX Clock                     ", Menu_RTC_EX_Clock },         //无线模块选择
	//{ " 3. BPC Clock                        ", Menu_BPC_Clock },         //无线模块选择
	//{ " 4. JJY Clock                        ", Menu_JJY_Clock },         //无线模块选择
};

//-----------------------------------   三级菜单  ------------------------------------- 

MENU_PRMT Test_Easy_Prmt;     //简单模式参数
MENU_TABLE Test_Easy[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //无线模块选择
	//{ " 1. 开始接收                        ", Menu_RX_Easy },
	//{ " 2. 发包数                          ", Menu_TX_Num },
	//{ " 3. 开始发射                        ", Menu_TX_Easy },
};

MENU_PRMT Test_Expert_Prmt;     //高级模式参数
MENU_TABLE Test_Expert[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //无线模块选择
	//{ " 1. 频率设置                        ", Menu_CH_Expert },
	//{ " 2. 速率设置                        ", Menu_Speed_Expert },
	//{ " 3. 编码设置                        ", Menu_Code_Expert },
	//{ " 4. 信号强度                        ", Menu_RSSI_Expert },
	//{ " 5. 开始接收                        ", Menu_RX_Expert },
	//{ " 6. 发包数                          ", Menu_TX_Num },
	//{ " 7. 开始发射                        ", Menu_TX_Expert },
};

MENU_PRMT BPC_Mode_Prmt;     //BPC模式参数
MENU_TABLE BPC_Mode[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //无线模块选择
	//{ " 1. BPC Send                        ", BPC_Send },
	//{ " 2. BPC Receive                     ", BPC_Receive },
};

MENU_PRMT JJY_Mode_Prmt;     //JJY模式参数
MENU_TABLE JJY_Mode[] =
{
		{ " 1. RTC_OB Clock                  ", Menu_RTC_OB_Clock },         //无线模块选择
	//{ " 1. JJY Send                        ", JJY_Send },
	//{ " 2. JJY Receive                     ", JJY_Receive },
};


/**************************************************************************************
* FunctionName   : Menu_Null()
* Description    : 空函数
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void Menu_Null(void)
{
	;
}

/**************************************************************************************
* FunctionName   : Menu_PrmtInit()
* Description    : 初始化菜单参数
* EntryParameter : prmt - 菜单参数, num - 显示项, page - 显示页
* ReturnValue    : None
**************************************************************************************/
void Menu_PrmtInit(MENU_PRMT *prmt, u8 num, u8 page)
{
	prmt->ExitMark = 0;                     // 清除退出菜单标志 
	prmt->Cursor = 0;                     // 光标清零 
	prmt->PageNo = 0;                     // 页清零 
	prmt->Index = 0;                     // 索引清零 
	prmt->DispNum = num;                    // 页最多显示项目数 
	prmt->MaxPage = page;                    // 最多页数 
}

/**************************************************************************************
* FunctionName   : Menu_Display()
* Description    : 显示菜单
* EntryParameter : page - 显示页，dispNum - 每一页的显示项，cursor - 光标位置
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
			//display_string_GB2312(0, (i + 3) * 16, menu[page + i].MenuName, WHITE, RED);           // 反白显示菜单项 
		}
		else
		{
			LCD_setTextColor(GREEN, BLACK);
			LCD_text(menu[page + i].MenuName, 0, (i + 3) * 12);
			//display_string_GB2312(0, (i + 3) * 16, menu[page + i].MenuName, RED, WHITE);             // 显示菜单项   
		}
	}
}

/**************************************************************************************
* FunctionName   : Menu_Move()
* Description    : 菜单移动
* EntryParameter : prmt - 菜单参数, key - 按键值
* ReturnValue    : 有确认返回0，否则返回1
**************************************************************************************/
u8 Menu_Move(MENU_PRMT *prmt, uint8_t key_menu)
{
	u8 rValue = 1;

	switch (key_menu)
	{
	case KEY_DOWN_U:                   // 向上 
		if (prmt->Cursor != 0)                       // 光标不在顶端 
		{
			prmt->Cursor--;                        // 光标上移 
		}
		else                        // 光标在顶端 
		{
			if (prmt->PageNo != 0)                      // 页面没有到最小 
			{
				prmt->PageNo--;                       // 向上翻 
			}
			else
			{
				prmt->Cursor = prmt->DispNum - 1;                      // 光标到底 
				prmt->PageNo = prmt->MaxPage - 1;                  // 最后页 
			}
		}
		break;

	case KEY_DOWN_D:                   // 向下 
		if (prmt->Cursor < prmt->DispNum - 1)                          // 光标没有到底，移动光标 
		{
			prmt->Cursor++;                        // 光标向下移动 
		}
		else                                                         // 光标到底 
		{
			if (prmt->PageNo < prmt->MaxPage - 1)                      // 页面没有到底，页面移动 
			{
				prmt->PageNo++;                       // 下翻一页 
			}
			else                                                     // 页面和光标都到底，返回开始页 
			{
				prmt->Cursor = 0;
				prmt->PageNo = 0;
			}
		}
		break;

	case KEY_DOWN_A:                   // 确认   
		prmt->Index = prmt->Cursor + prmt->PageNo;                   // 计算执行项的索引 
		rValue = 0;
		break;

	case KEY_DOWN_B:                   // 取消   
									//prmt->Index = prmt->Cursor + prmt->PageNo;                   // 计算执行项的索引 
		if (MenuLv != 1)
		{
			prmt->ExitMark = 0x01;
			MenuLv -= 1;
			rValue = 2;
		}
		break;

	case KEY_DOWN_L:                   // 左键跳到顶部 
		prmt->Cursor = 0;
		prmt->PageNo = 0;
		break;

	case KEY_DOWN_R:                   // 右键跳到底部 
		prmt->Cursor = prmt->DispNum - 1;                              // 光标到底 
		prmt->PageNo = prmt->MaxPage - 1;                          // 最后页 
		break;

	default:
		break;
	}
	return rValue;                          // 返回执行索引 
}

/**************************************************************************************
* FunctionName   : Menu_Process()
* Description    : 处理菜单项
* EntryParameter : menuName - 菜单名称，prmt - 菜单参数，table - 菜单表项, num - 菜单项数
* ReturnValue    : None
**************************************************************************************/
void Menu_Process(u8 *menuName, MENU_PRMT *prmt, MENU_TABLE *table, u8 num)
{
	u8 key_temp;

	if (num > PAGE_DISP_NUM)
	{
		Menu_PrmtInit(prmt, PAGE_DISP_NUM, num - PAGE_DISP_NUM + 1);         // 显示项数和页数设置，项数超过一页需要翻页，设置页数 
	}
	else
	{
		Menu_PrmtInit(prmt, num, 1);                          // 显示项数和页数设置，不超过一页最大页数为1
	}
	//lcd_clean_screen(WHITE);
	LCD_setTextColor(WHITE, BLACK);
	LCD_text("--------------------------", 0, 0);
	LCD_text(menuName, 0, 12);
	LCD_text("--------------------------", 0, 24);
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(0, 16, menuName, RED, WHITE);                                   // 菜单标题显示 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // 菜单标题显示 
	Menu_Display(table, prmt->PageNo, prmt->DispNum, prmt->Cursor);               // 显示菜单项 
	do
	{
		key_temp = bsp_GetKey();	// 获取按键         
		if (key_temp != KEY_NONE)
		{
			if (Menu_Move(prmt, key_temp) == 0x00)                          // 菜单移动，判断是是否有确认键按下 
			{
				//LCD_Clear(BLACK);								 // 清屏 
				LCD_Fill(0, 32, 160, 128, BLACK);
				table[prmt->Index].ItemHook();                               // 执行相应项 
			}
			if (key_temp == KEY_DOWN_A)
			{
				LCD_Fill(0, 32, 160, 128, BLACK);
				//LCD_Clear(BLACK);                       // 清屏 
			}
			//lcd_clean_screen(WHITE); 
			LCD_setTextColor(WHITE, BLACK);
			LCD_text("--------------------------", 0, 0);
			LCD_text(menuName, 0, 12);
			LCD_text("--------------------------", 0, 24);
			//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // 菜单标题显示 
			//display_string_GB2312(0, 16, menuName, RED, WHITE);                                   // 菜单标题显示 
			//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // 菜单标题显示 
			Menu_Display(table, prmt->PageNo, prmt->DispNum, prmt->Cursor);               // 显示菜单项 
		}
	} while (prmt->ExitMark == 0);
}

/**************************************************************************************
* FunctionName   : MenuGeneralSet()
* Description    : 常规设置
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void MenuGeneralSet(u8 num)
{
	u8 menuNum;
	menuNum = sizeof(GeneralSet) / sizeof(GeneralSet[0]) - num;         // 菜单项数 
	MenuLv = 1;
	Menu_Process("      HITB 2018 GSEC      ", &GSetPrmt, GeneralSet, menuNum);
}

///**************************************************************************************
//* FunctionName   : Menu_Profile()
//* Description    : 情景模式
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_Profile(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Profile) / sizeof(Profile[0]);         // 菜单项数 
//	MenuLv = 2;
//	Menu_Process(" -= 情景模式 =- ", &ProfilePrmt, Profile, menuNum);
//}

///**************************************************************************************
//* FunctionName   : Menu_ExitProfile()
//* Description    : 退出情景模式
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_ExitProfile(void)
//{
//	ProfilePrmt.ExitMark = 0x01;         // 退出情景模式 
//	lcd_clean_screen(0);              // 清屏   
//}

///**************************************************************************************
//* FunctionName   : Menu_SetClock()
//* Description    : 时间与日期设置
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_SetClock(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Clock) / sizeof(Clock[0]);         // 菜单项数 
//	MenuLv = 2;
//	Menu_Process(" -= 时间日期 =- ", &ClockPrmt, Clock, menuNum);
//}

///**************************************************************************************
//* FunctionName   : Menu_ExitClockSet()
//* Description    : 退出日期与时钟
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_ExitClockSet(void)
//{
//	ClockPrmt.ExitMark = 0x01;             // 退出时钟设置 
//	lcd_clean_screen(0);              // 清屏   
//}

//void Menu_Day1(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Day1) / sizeof(Day1[0]);         // 菜单项数 
//	MenuLv = 2;
//	Menu_Process("11月24日会议日程", &Day1_Prmt, Day1, menuNum);
//}
//
//void Menu_Day2(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Day2) / sizeof(Day2[0]);         // 菜单项数 
//	MenuLv = 2;
//	Menu_Process("11月25日会议日程", &Day2_Prmt, Day2, menuNum);
//}

///**************************************************************************************
//* FunctionName   : Easy_Mode()
//* Description    : 简单测试
//* EntryParameter : None
//* ReturnValue    : None
//**************************************************************************************/
//void Menu_Profile(void)
//{
//	u8 menuNum;
//	menuNum = sizeof(Profile) / sizeof(Profile[0]);         // 菜单项数 
//	MenuLv = 2;
//	Menu_Process(" -= 情景模式 =- ", &ProfilePrmt, Profile, menuNum);
//}

/************************************* 二级菜单 *************************************************/

void Menu_Mode(void)
{
	u8 menuNum;
	menuNum = sizeof(Test_Mode) / sizeof(Test_Mode[0]);         // 菜单项数 
	MenuLv = 2;
	Menu_Process("           模式选择           ", &Test_Mode_Prmt, Test_Mode, menuNum);
}


void Menu_Clock(void)
{
	u8 menuNum;
	menuNum = sizeof(Clock_Mode) / sizeof(Clock_Mode[0]);         // 菜单项数 
	MenuLv = 2;
	Menu_Process("           时钟测试           ", &Clock_Mode_Prmt, Clock_Mode, menuNum);
}

/************************************* 三级菜单 *************************************************/

void Menu_Test_Easy(void)
{
	u8 menuNum;
	menuNum = sizeof(Test_Easy) / sizeof(Test_Easy[0]);         // 菜单项数 
	MenuLv = 3;
	Menu_Process("           简单测试           ", &Test_Easy_Prmt, Test_Easy, menuNum);
}

void Menu_Test_Expert(void)
{
	u8 menuNum;
	menuNum = sizeof(Test_Expert) / sizeof(Test_Expert[0]);         // 菜单项数 
	MenuLv = 3;
	Menu_Process("           高级测试           ", &Test_Expert_Prmt, Test_Expert, menuNum);
}

void Menu_RF_Info(void)
{

	//u8 menuNum;
	//menuNum = sizeof(Expert1) / sizeof(Expert1[0]);         // 菜单项数 
	//MenuLv = 2;
	//Menu_Process("           高级测试           ", &ExpertPrmt_1, Easy1, menuNum);

}

void Menu_BPC_Clock(void)
{
	u8 menuNum;
	menuNum = sizeof(BPC_Mode) / sizeof(BPC_Mode[0]);         // 菜单项数 
	MenuLv = 3;
	Menu_Process("          BPC电波钟           ", &BPC_Mode_Prmt, BPC_Mode, menuNum);
}

void Menu_JJY_Clock(void)
{
	u8 menuNum;
	menuNum = sizeof(JJY_Mode) / sizeof(JJY_Mode[0]);         // 菜单项数 
	MenuLv = 3;
	Menu_Process("          JJY电波钟           ", &JJY_Mode_Prmt, JJY_Mode, menuNum);
}

/************************************* 函数 *************************************************/

void Menu_RX_Easy(void)
{
	//TIM5_CH1_Cap_Init(0XFFFFFFFF, 84 - 1); //以1MHz频率计数
	//ASK_Mode(1);
	//ask_rx_enable(RX1_ASK, true);

	//lcd_clean_screen(WHITE);
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(0, 16, "             接收             ", RED, WHITE);          // 菜单标题显示 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(2, 64, "1527 ADDR: ", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(2, 80, "1527 DATA: ", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(2, 96, "1527 Get Num: ", RED, WHITE);           // 菜单标题显示 

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
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(0, 16, "             发射             ", RED, WHITE);          // 菜单标题显示 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(2, 64, "1527 ADDR: ", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(2, 80, "1527 DATA: ", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(2, 96, "1527 Send Num: 4*", RED, WHITE);           // 菜单标题显示 


	//for (t_addr = 0; t_addr < 1048576; t_addr++)       //地址遍历
	//{
	//	for (t_data = 0; t_data < 16; t_data++)        //数据遍历
	//	{
	//		ask_send_1527(TX1_ASK, t_addr, t_data, 4);
	//		display_string_GB2312(90, 64, "                   ", RED, WHITE);           // 菜单标题显示 
	//		display_string_GB2312(90, 80, "                   ", RED, WHITE);           // 菜单标题显示 
	//		display_num_format(90, 64, t_addr, 4, "%04X", RED, WHITE);           // 菜单标题显示 
	//		display_num_format(90, 80, t_data, 4, "%02X", RED, WHITE);           // 菜单标题显示 
	//		display_num_format(140, 96, ++tx_num, 4, "%u", RED, WHITE);           // 菜单标题显示 
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
	//display_string_GB2312(0, 0, "------------------------------", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(0, 16, "           亮度设置           ", RED, WHITE);                                   // 菜单标题显示 
	//display_string_GB2312(0, 32, "------------------------------", RED, WHITE);           // 菜单标题显示 
	//display_string_GB2312(0, 64, " <          -    -          > ", RED, WHITE);           // 菜单标题显示 

	//display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // 菜单标题显示 

	//do
	//{
	//	key_lcd = bsp_GetKey();	// 获取按键    
	//	if (key_lcd != KEY_NONE)
	//	{
	//		switch (key_lcd)
	//		{
	//		case KEY_DOWN_L:
	//			if (light_temp > 0)
	//			{
	//				light_temp--;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // 菜单标题显示 
	//			lcd_light_set(light_temp);
	//			break;
	//		case KEY_DOWN_R:
	//			if (light_temp < 10)
	//			{
	//				light_temp++;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // 菜单标题显示 
	//			lcd_light_set(light_temp);
	//			break;
	//		case KEY_DOWN_U:
	//			if (light_temp < 10)
	//			{
	//				light_temp++;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // 菜单标题显示 
	//			lcd_light_set(light_temp);
	//			break;
	//		case KEY_DOWN_D:
	//			if (light_temp > 0)
	//			{
	//				light_temp--;
	//			}
	//			display_num_format(112, 64, light_temp, 4, "%02u", RED, WHITE);           // 菜单标题显示 
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


