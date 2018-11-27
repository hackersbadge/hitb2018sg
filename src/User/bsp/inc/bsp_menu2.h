#ifndef __BSP_MENU_H__
#define __BSP_MENU_H__

#define  PAGE_DISP_NUM	    8

/**************************************************************************************
* Variable definition
**************************************************************************************/
// �˵����� 
typedef struct _MENU_PRMT
{
	u8 ExitMark;             // �˳��˵�(0-���˳���1-�˳�) 
	u8 Cursor;             // ���ֵ(��ǰ���λ��) 
	u8 PageNo;             // �˵�ҳ(��ʾ��ʼ��) 
	u8 Index;             // �˵�����(��ǰѡ��Ĳ˵���) 
	u8 DispNum;             // ��ʾ����(ÿҳ�������ڲ˵���) 
	u8 MaxPage;             // ���ҳ��(����ж�������ʾҳ) 
} MENU_PRMT;

//------------------------------------------------------------------------------------ 
// �˵�ִ�� 
typedef struct _MENU_TABLE
{
	u8 *MenuName;            // �˵���Ŀ���� 
	void(*ItemHook)(void);                // Ҫ���еĲ˵����� 
} MENU_TABLE;

extern u8 err1;
extern u8 err2;
extern u8 err3;
extern u8 err4;

void Menu_Null(void);
void Menu_PrmtInit(MENU_PRMT *prmt, u8 num, u8 page);
void Menu_Display(MENU_TABLE *menu, u8 page, u8 dispNum, u8 cursor);
u8 Menu_Move(MENU_PRMT *prmt, uint8_t key_menu);
void Menu_Process(u8 *menuName, MENU_PRMT *prmt, MENU_TABLE *table, u8 num);
void MenuGeneralSet(u8 num);
//void Menu_Profile(void);
//void Menu_ExitProfile(void);
//void Menu_SetClock(void);
//void Menu_ExitClockSet(void);
/*void Menu_Day1(void);
void Menu_Day2(void)*/
;
void Menu_Mode(void);
void Menu_Test_Easy(void);
void Menu_Test_Expert(void);
void Menu_RF_Info(void);

void Menu_RX_Easy(void);
void Menu_TX_Num(void);
void Menu_TX_Easy(void);

void Menu_CH_Expert(void);
void Menu_Speed_Expert(void);
void Menu_Code_Expert(void);
void Menu_RSSI_Expert(void);
void Menu_RX_Expert(void);
void Menu_TX_Expert(void);

void Menu_RF_1(void);
void Menu_RF_2(void);
void Menu_RF_3(void);
void Menu_RF_4(void);
void Menu_RF_5(void);
void Menu_TFT_Light(void);

void Menu_Clock(void);
void Menu_RTC_OB_Clock(void);
//void Menu_RTC_OB_Clock(void);
//void Menu_RTC_EX_Clock(void);
//void Menu_BPC_Clock(void);
//void Menu_JJY_Clock(void);
//void Menu_Temp(void);
//void BPC_Send(void);
//void BPC_Receive(void);
//void JJY_Send(void);
//void JJY_Receive(void);
//
//void menu_time_display(uint8_t sel);
//void menu_set_time(uint8_t sel);
//void display_rtc(uint8_t sel);


#endif /* __BSP_MENU_H__ */
