#ifndef __BSP_MENU_H__
#define __BSP_MENU_H__

#ifdef __cplusplus
 extern "C" {
#endif 

//typedef struct
//{
//	char *track,
//	char *time,
//	char *title,
//	char *t_web,
//	char *speaker,
//	char *s_web,
//}agent_type;

void Menu_Init(void);
void Menu_Loop(void);
void Menu_DrawFrame(void);
void Menu_UpdateFrame(void);
void mFunc_agenda(uint8_t param);
void mFunc_about(uint8_t param);
void mFunc_lcd_setlight(uint8_t param);
void mFunc_secret(uint8_t param);
void mFunc_guess_num(uint8_t param);
void mFunc_light(uint8_t param);


/*

// Bit pos control
#define _LCDML_control_menu_back            7
#define _LCDML_control_disp_update          6
#define _LCDML_control_cursor_update        5
#define _LCDML_control_setup                4
#define _LCDML_control_update_direct        3
#define _LCDML_control_search_display       2
#define _LCDML_control_rollover             1
#define _LCDML_control_disable_hidden       0

#define _LCDML_button_free                  7
#define _LCDML_button                       6
#define _LCDML_button_quit                  5
#define _LCDML_button_enter                 4
#define _LCDML_button_up                    3
#define _LCDML_button_down                  2
#define _LCDML_button_left                  1
#define _LCDML_button_right                 0

// stored in ram (esp)
#define LCDML_LANG_DEF(name, content) \
            char g_LCDML_DISP_lang_ ## name ##_var[] = {content}

#define LCDML_getContent(var, id) \
            if(id < _LCDML_NO_FUNC) {\
                strcpy(var, g_LCDML_DISP_lang_table[id]); \
            }

#define LCDML_createMenu(N)\
            char * g_LCDML_DISP_lang_table[] = { LCDML_DISP_lang_repeat(N) }


#define LCDML_getElementName(var, element_id) \
            if(element_id < _LCDML_NO_FUNC && (sizeof(g_LCDML_DISP_lang_table)-1) >= element_id) {\
                strcpy_P(var, (char*)(g_LCDML_DISP_lang_table[element_id]));\
            }

#define LCDML_add(id, parent, child, content, callback) \
        LCDML_addAdvanced(id, parent, child, NULL, content, callback, 0, _LCDML_TYPE_default)    

//Menu Item Types        
#define LCDML_addAdvanced(id, parent, child, condetion, content, callback, param, settings) \
        LCDML_LANG_DEF(id, content); \
        LCDMenuLib2_menu parent ## _ ## child(id, param, settings, callback, condetion ); \
        void LCDML_DISP_ ## id ## _function() { \
            parent.addChild(parent ## _ ## child); \
        }

#define LCDML_setup(N)\
        LCDML_DISP_initFunction(N); \
        LCDML_MENU_display(); \
        LCDML_DISP_menuUpdate() 

#define LCDML_DISP_lang(name)           g_LCDML_DISP_lang_ ## name ## _var

// call repeat of function 
#define LCDML_DISP_initFunction(N)      LCDML_DISP_func_repeat(N);

#define LCDML_LANG_DEF(name, content) \
            char g_LCDML_DISP_lang_ ## name ##_var[] = {content}

#define LCDML_getContent(var, id) \
            if(id < _LCDML_NO_FUNC) {\
                strcpy(var, g_LCDML_DISP_lang_table[id]); \
            }

#define LCDML_createMenu(N)\
            char * g_LCDML_DISP_lang_table[] = { LCDML_DISP_lang_repeat(N) }

#define LCDML_getElementName(var, element_id) \
            if(element_id < _LCDML_NO_FUNC && (sizeof(g_LCDML_DISP_lang_table)-1) >= element_id) {\
                strcpy_P(var, (char*)(g_LCDML_DISP_lang_table[element_id]));\
            }

typedef void(*LCDML_FuncPtr)       ();
typedef void(*LCDML_FuncPtr_pu8)   (uint8_t);  // with parameter u8
typedef boolean(*LCDML_FuncPtr_rb)    ();         // with return value boolean

LCDMenuLib2_menu * parent;                               // Parent menu, NULL if this is the top
LCDMenuLib2_menu * child;                                // First child menu, NULL if no children
LCDMenuLib2_menu * sibling;                              // Next sibling menu, NULL if this is the last sibling

LCDML_FuncPtr_pu8 cb_function;                          // Menu Funktion callback            
LCDML_FuncPtr_rb  cb_condetion;                         // Menu Condetion callback

void setParent(LCDMenuLib2_menu &p);                     // Sets the menu's parent to p
void addSibling(LCDMenuLib2_menu &s, LCDMenuLib2_menu &p); // Adds a sibling s with parent p.  If the menu already has a sibling, ask that sibling to add it

uint8_t id;                                             // Name of this menu           
uint8_t param;
uint8_t configuration;

LCDMenuLib2_menu *activMenu;
uint8_t menu_scroll;

#define _LCDML_DISP_cfg_cursor_deep          10  // save the last position of the cursor until layer xx
#define _LCDML_DISP_cfg_max_rows             10  // max rows which are supported
#define _LCDML_cfg_use_ram                   0   // set this to 1 when you will use the ram mode     

LCDMenuLib2_menu *rootMenu;
LCDMenuLib2_menu *curMenu;
LCDMenuLib2_menu *activMenu;

// callback functions
LCDML_FuncPtr       callback_menuControl;
LCDML_FuncPtr       callback_contentUpdate;     // Update Content            
LCDML_FuncPtr       callback_contentClear;      // Clear Content 
LCDML_FuncPtr_pu8   cb_screensaver;

uint8_t reg1;                                    //                                       
uint8_t cols;                                    // display cols 
uint8_t rows;                                    // display rows 
uint8_t layer_save[_LCDML_DISP_cfg_cursor_deep]; // save cursor position for every layer        
uint8_t curloc;                                  // current corsor position          
uint8_t scroll;                                  // current scroll position 
uint8_t scroll_save[_LCDML_DISP_cfg_cursor_deep];// save cursor position for every layer 
uint8_t cursor_pos;                              // save the last cursor position when a menue element is called 
uint8_t child_cnt;                               // how many childs exists on next layer 
uint8_t layer;                                   // containes the current layer 
uint8_t parents[_LCDML_DISP_cfg_cursor_deep];    // save last parent 
uint8_t button;                                  // button variable 
uint8_t control;                                 // control bits 
uint8_t funcReg;                                 // control bits   

uint8_t menu_child_cnt;

*/

//#define  PAGE_DISP_NUM	    8

///**************************************************************************************
//* Variable definition
//**************************************************************************************/
//// 菜单参数 
//typedef struct _MENU_PRMT
//{
//	// private variables			
//	uint8_t reg1;									 // */										
//	uint8_t cols;									 // display cols 
//	uint8_t rows;									 // display rows 
//	uint8_t layer_save[_LCDML_DISP_cfg_cursor_deep]; // save cursor position for every layer		
//	uint8_t curloc; 								 // current corsor position 		 
//	uint8_t scroll; 								 // current scroll position 
//	uint8_t scroll_save[_LCDML_DISP_cfg_cursor_deep];// save cursor position for every layer 
//	uint8_t cursor_pos; 							 // save the last cursor position when a menue element is called 
//	uint8_t child_cnt;								 // how many childs exists on next layer 
//	uint8_t layer;									 // containes the current layer 
//	uint8_t parents[_LCDML_DISP_cfg_cursor_deep];	 // save last parent 
//	uint8_t button; 								 // button variable 
//	uint8_t control;								 // control bits 
//	uint8_t funcReg;								 // control bits			
//	

//	u8 ExitMark;             // 退出菜单(0-不退出，1-退出) 
//	u8 Cursor;             // 光标值(当前光标位置) 
//	u8 PageNo;             // 菜单页(显示开始项) 
//	u8 Index;             // 菜单索引(当前选择的菜单项) 
//	u8 DispNum;             // 显示项数(每页可以现在菜单项) 
//	u8 MaxPage;             // 最大页数(最大有多少种显示页) 
//} MENU_PRMT;

////------------------------------------------------------------------------------------ 
//// 菜单执行 
//typedef struct _MENU_TABLE
//{
//	u8 id;
//	u8 parent;
//	u8 child;
//	u8 condetion;
//	u8 *MenuName;            // 菜单项目名称 
//	void(*callback)(void);                // 要运行的菜单函数 
//	u8 param;
//	u8 settings;
//} MENU_TABLE;

//extern u8 err1;
//extern u8 err2;
//extern u8 err3;
//extern u8 err4;

//void Menu_Null(void);
//void Menu_PrmtInit(MENU_PRMT *prmt, u8 num, u8 page);
//void Menu_Display(MENU_TABLE *menu, u8 page, u8 dispNum, u8 cursor);
//u8 Menu_Move(MENU_PRMT *prmt, uint8_t key_menu);
//void Menu_Process(u8 *menuName, MENU_PRMT *prmt, MENU_TABLE *table, u8 num);
//void MenuGeneralSet(u8 num);
////void Menu_Profile(void);
////void Menu_ExitProfile(void);
////void Menu_SetClock(void);
////void Menu_ExitClockSet(void);
///*void Menu_Day1(void);
//void Menu_Day2(void)*/
//;
//void Menu_Mode(void);
//void Menu_Test_Easy(void);
//void Menu_Test_Expert(void);
//void Menu_RF_Info(void);

//void Menu_RX_Easy(void);
//void Menu_TX_Num(void);
//void Menu_TX_Easy(void);

//void Menu_CH_Expert(void);
//void Menu_Speed_Expert(void);
//void Menu_Code_Expert(void);
//void Menu_RSSI_Expert(void);
//void Menu_RX_Expert(void);
//void Menu_TX_Expert(void);

//void Menu_RF_1(void);
//void Menu_RF_2(void);
//void Menu_RF_3(void);
//void Menu_RF_4(void);
//void Menu_RF_5(void);
//void Menu_TFT_Light(void);

//void Menu_Clock(void);
//void Menu_RTC_OB_Clock(void);
//void Menu_RTC_EX_Clock(void);
//void Menu_BPC_Clock(void);
//void Menu_JJY_Clock(void);
//void Menu_Temp(void);
//void BPC_Send(void);
//void BPC_Receive(void);
//void JJY_Send(void);
//void JJY_Receive(void);

//void menu_time_display(uint8_t sel);
//void menu_set_time(uint8_t sel);
//void display_rtc(uint8_t sel);


#ifdef __cplusplus
	}
#endif /* __cplusplus */


#endif /* __BSP_MENU_H__ */


