#include "bsp.h"
#include "LCDMenuLib2.h"
#include "LCDMenuLib2_menu.h"

static const char *name_temp[5] = { "   Hacknown  ","  overl0rd  ","   amigoh   ","   guess    ","  l33tdawg "};
static const char *about[6] = { "White-Alone","https://twitter.com/WhiteA10n3","xwings","https://twitter.com/sgniwx","Earl Marcus","https://twitter.com/klks84" };
//static const char *agenda[] = { };
static const char *agenda[288]= {	\
"Expo Area", "08:00 - 08:45", "Morning Coffee", "https://bit.ly/2Bpvk7p", "Morning Coffee", "https://bit.ly/2Bpvk7p", \
"B1", "09:00 - 09:45", "(in)Security is Eating the World", "https://bit.ly/2N2fRLI", "michael-coates", "https://bit.ly/2MqLsKY", \
"Expo Area", "09:45 - 10:00", "Morning Coffee", "https://bit.ly/2Bpvk7p", "Morning Coffee", "https://bit.ly/2Bpvk7p", \
"B1", "10:00 - 11:00", "A Year Of Purple", "https://bit.ly/2Bq4Tyn", "ryan-shepherd", "https://bit.ly/2OPtK0y", \
"B2", "10:00 - 10:55", "COMMSEC WELCOME", "https://bit.ly/2BqcUn0", "andrea", "https://bit.ly/2L80NKG", \
"B2", "11:00 - 11:30", "Your New Friend", "https://bit.ly/2Mlugqa", "dan-demeter", "https://bit.ly/2L72I2j", \
"B1", "11:00 - 12:00", "ASM To Java", "https://bit.ly/2wbvXeV", "robert-gawlik", "https://bit.ly/2MVwOaG", \
"B2", "11:30 - 12:00", "Darkweb", "https://bit.ly/2MoYAjx", "fadli", "https://bit.ly/2L63mgg", \
"B2", "12:00 - 12:30", "Brain Surgery", "https://bit.ly/2Mwudan", "vitaly/nicolas", "https://bit.ly/2MXHw0d", \
"B1", "12:00 - 13:00", "God Mode Unlock", "https://bit.ly/2N47fUR", "christopher", "https://bit.ly/2LfgD6C", \
"Lunch", "13:00 - 14:00", "Lunch", "https://bit.ly/2Bpvk7p", "Lunch", "https://bit.ly/2Bpvk7p", \
"B1", "14:00 - 15:00", "Ghost In The Lock", "https://bit.ly/2MrhaYB", "Tomi/Timo", "https://bit.ly/2wijLZN", \
"B2", "14:00 - 14:30", "Mobile Malware", "https://bit.ly/2MHPEoR", "minh-tran", "https://bit.ly/2Lg8mzn", \
"B2", "14:30 - 15:00", "scada", "https://bit.ly/2OSeZdm", "mike", "https://bit.ly/2OSfoMU", \
"B1", "15:00 - 16:00", "Anther Binary Exploitation", "https://bit.ly/2BwFUJL", "an-jie yang", "https://bit.ly/2MpB9Xj", \
"B2", "15:00 - 16:00", "Winshift APT", "https://bit.ly/2LeLQGL", "taha-karim", "https://bit.ly/2MtynjW", \
"Coffee", "16:00 - 16:30", "Coffee", "https://bit.ly/2Bpvk7p", "Coffee", "https://bit.ly/2Bpvk7p", \
"B2", "16:30 - 17:00", "sayakenahack", "https://bit.ly/2nV2DW9", "keith", "https://bit.ly/2MriRoV", \
"B1", "16:30 - 17:30", "Automation In Lte", "https://bit.ly/2wjwprk", "ravishankar/altaf", "https://bit.ly/2nXqiFK", \
"B2", "17:00 - 17:30", "Rant 2.0", "https://bit.ly/2whhqOZ", "joern", "https://bit.ly/2OV1g5w", \
"B1", "17:30 - 18:30", "Apple Pencil", "https://bit.ly/2MolV4V", "stefan", "https://bit.ly/2ORjHrI", \
"Panal", "18:30 - 19:30", "Panal", "https://bit.ly/2Bpvk7p", "Panal", "https://bit.ly/2Bpvk7p", \
"Party", "19:30 - 20:00", "Party", "https://bit.ly/2Bpvk7p", "Party", "https://bit.ly/2Bpvk7p", \

"Coffee", "08:00 - 09:00", "Coffee", "https://bit.ly/2Bpvk7p", "Coffee", "https://bit.ly/2Bpvk7p", \
"B1", "09:00 - 09:45", "Ok Computer", "https://bit.ly/2MFgtu2", "alexander", "https://bit.ly/2wghI8x", \
"Coffee", "09:45 - 10:30", "Coffee", "https://bit.ly/2Bpvk7p", "Coffee", "https://bit.ly/2Bpvk7p", \
"B1", "10:30 - 11:30", "Bicycle Day", "https://bit.ly/2nUXBJt", "vincent", "https://bit.ly/2OTF4bE", \
"B2", "10:30 - 11:30", "Deep Hooks", "https://bit.ly/2N67MWv", "assaf/yarden", "https://bit.ly/2nWuyoX", \
"B2", "11:30 - 12:00", "Data Centric", "https://bit.ly/2N67MWv", "eng/lim", "https://bit.ly/2Psx82w", \
"B1", "11:30 - 12:30", "Viewer Discretion", "https://bit.ly/2MH228J", "adam", "https://bit.ly/2nYTrjv", \
"B2", "12:00 - 12:30", "Cognitive Automation", "https://bit.ly/2weE0aR", "Rishi", "https://bit.ly/2MsWb7x", \
"B2", "12:30 - 13:00", "Redphishing", "https://bit.ly/2Lfxt50", "Matteo", "https://bit.ly/2o2Ia21", \
"Lunch", "12:30 - 14:00", "Lunch", "https://bit.ly/2Bpvk7p", "Lunch", "https://bit.ly/2Bpvk7p", \
"B1", "14:00 - 15:00", "Sandbox Escape", "https://bit.ly/2w0Mlj6", "Rani", "https://bit.ly/2o2Ia21", \
"B2", "14:00 - 14:30", "Iot:Bots", "https://bit.ly/2LfZidx", "Rommel", "https://bit.ly/2w15t0v", \
"B2", "14:30 - 15:00", "ML: Opensource", "https://bit.ly/2PsPZuc", "Asankhaya", "https://bit.ly/2OS70Ne", \
"B1", "15:00 - 16:00", "NFC Payments", "https://bit.ly/2N6rqSg", "Salvador", "https://bit.ly/2BwSb0V", \
"B2", "15:00 - 15:30", "Smurf honeyports", "https://bit.ly/2L99u7L", "Emil", "https://bit.ly/2N6xlqt", \
"B2", "15:30 - 16:00", "Security Era", "https://bit.ly/2LiljIG", "nafiez/yeh", "https://bit.ly/2nVQ9gY", \
"Coffee", "16:00 - 16:30", "Coffee", "https://bit.ly/2Bpvk7p", "Coffee", "https://bit.ly/2Bpvk7p", \
"B1", "16:30 - 17:30", "Kill Chain", "https://bit.ly/2BwhnEx", "vincent", "https://bit.ly/2N3NEo0", \
"B2", "16:30 - 17:00", "Smartcontract", "https://bit.ly/2wgTefw", "jorden", "https://bit.ly/2Bsy5Vi", \
"B2", "17:00 - 17:30", "Hacking Mobile Games", "https://bit.ly/2wbvw44", "nicolas", "https://bit.ly/2ByXRra", \
"B1", "17:00 - 17:30", "Closing Keynote", "https://bit.ly/2MoYHvN", "alexis", "https://bit.ly/2wglzm1", \
"B1", "18:00 - 18:45", "Lock Note ", "https://bit.ly/2Po68RL", "Philippe ", "https://bit.ly/2OVgnvH", \
"B1", "18:45 - 19:00", "CTF Prize", "https://bit.ly/2Bpvk7p", "CTF Prize", "https://bit.ly/2Bpvk7p", \
"B1", "19:00 - 20:00", "Reception", "https://bit.ly/2Bpvk7p", "Reception", "https://bit.ly/2Bpvk7p", \
};

static uint8_t n_last = 0;

// settings for u8g lib and lcd
#define _LCDML_DISP_w                 160            // lcd width
#define _LCDML_DISP_h                 128             // lcd height
// font settings
#define _LCDML_DISP_font              1  
#define _LCDML_DISP_font_w            6              // font width
#define _LCDML_DISP_font_h            12             // font heigt  
// cursor settings
#define _LCDML_DISP_cursor_string       "->"            // cursor char
#define _LCDML_DISP_cursor_len             2            // 光标长度
#define _LCDML_DISP_cur_space_before       2              // cursor space between
#define _LCDML_DISP_cur_space_behind       2              // cursor space between  
// menu position and size
#define _LCDML_DISP_box_x0            1              // start point (x0, y0)
#define _LCDML_DISP_box_y0            32              // start point (x0, y0)
#define _LCDML_DISP_box_x1            159+1            // width x  (x0 + width)
#define _LCDML_DISP_box_y1            127+1             // hight y  (y0 + height)
#define _LCDML_DISP_draw_frame        1              // draw a box around the menu
// scrollbar width
#define _LCDML_DISP_scrollbar_w       6  // scrollbar width (if this value is < 3, the scrollbar is disabled)    

// nothing change here
#define _LCDML_DISP_cols_max          ((_LCDML_DISP_box_x1-_LCDML_DISP_box_x0)/_LCDML_DISP_font_w) 
#define _LCDML_DISP_rows_max          ((_LCDML_DISP_box_y1-_LCDML_DISP_box_y0-((_LCDML_DISP_box_y1-_LCDML_DISP_box_y0)/_LCDML_DISP_font_h))/_LCDML_DISP_font_h) 

// rows and cols 
// when you use more rows or cols as allowed change in LCDMenuLib.h the define "_LCDML_DISP_cfg_max_rows" and "_LCDML_DISP_cfg_max_string_length"
// the program needs more ram with this changes
#define _LCDML_DISP_rows              _LCDML_DISP_rows_max  // max rows 
#define _LCDML_DISP_cols              _LCDML_DISP_cols_max	// max cols

// *********************************************************************
// Prototypes
// *********************************************************************
  void lcdml_menu_display(); 
  void lcdml_menu_clear(); 
  void lcdml_menu_control();   


// *********************************************************************
// Objects
// *********************************************************************
  //LCDMenuLib2_menu LCDML_0;
  //LCDMenuLib2_menu_init(LCDML_0 ,255, 0, 0, NULL, NULL); // root menu element (do not change)
  //LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);

LCDMenuLib2_menu LCDML_0 (255, 0, 0, NULL, NULL); // root menu element (do not change)
LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);

// *********************************************************************
// LCDML MENU/DISP
// *********************************************************************
  // LCDML_0        => layer 0 
  // LCDML_0_X      => layer 1 
  // LCDML_0_X_X    => layer 2 
  // LCDML_0_X_X_X  => layer 3 
  // LCDML_0_...      => layer ... 

  // For beginners
  // LCDML_add(id, prev_layer, new_num, lang_char_array, callback_function)  

LCDML_add ( 0 , LCDML_0         ,  1  , " 01. Agenda           ", NULL);     
LCDML_add ( 1 , LCDML_0         ,  2  , " 02. Sponsors         ", NULL);         
LCDML_add ( 2 , LCDML_0         ,  3  , " 03. Secret Menu      ", mFunc_secret);
LCDML_add ( 3 , LCDML_0         ,  4  , " 04. Game             ", mFunc_guess_num);
LCDML_add ( 4 , LCDML_0         ,  5  , " 05. TFT Light        ", mFunc_lcd_setlight);
LCDML_add ( 5 , LCDML_0         ,  6  , " 06. About            ", NULL);
LCDML_add ( 6 , LCDML_0_1       ,  1  , " August 30, 2018      ", NULL);
LCDML_add ( 7 , LCDML_0_1       ,  2  , " August 31, 2018      ", NULL);
LCDML_add ( 8,   LCDML_0_1_1 	,  1  , " 08:00 - 08:45        ", mFunc_agenda);
LCDML_add ( 9,   LCDML_0_1_1 	,  2  , " 09:00 - 09:45        ", mFunc_agenda);
LCDML_add ( 10,  LCDML_0_1_1	,  3  , " 09:45 - 10:00        ", mFunc_agenda);
LCDML_add ( 11,  LCDML_0_1_1	,  4  , " 10:00 - 11:00        ", mFunc_agenda);
LCDML_add ( 12,  LCDML_0_1_1	,  5  , " 10:00 - 10:55        ", mFunc_agenda);
LCDML_add ( 13,  LCDML_0_1_1	,  6  , " 11:00 - 11:30        ", mFunc_agenda);
LCDML_add ( 14,  LCDML_0_1_1	,  7  , " 11:00 - 12:00        ", mFunc_agenda);
LCDML_add ( 15,  LCDML_0_1_1	,  8  , " 11:30 - 12:00        ", mFunc_agenda);
LCDML_add ( 16,  LCDML_0_1_1	,  9  , " 12:00 - 12:30        ", mFunc_agenda);
LCDML_add ( 17,  LCDML_0_1_1	,  10 , " 12:00 - 13:00        ", mFunc_agenda);
LCDML_add ( 18,  LCDML_0_1_1	,  11 , " 13:00 - 14:00        ", mFunc_agenda);
LCDML_add ( 19,  LCDML_0_1_1	,  12 , " 14:00 - 15:00        ", mFunc_agenda);
LCDML_add ( 20,  LCDML_0_1_1	,  13 , " 14:00 - 14:30        ", mFunc_agenda);
LCDML_add ( 21,  LCDML_0_1_1	,  14 , " 14:30 - 15:00        ", mFunc_agenda);
LCDML_add ( 22,  LCDML_0_1_1	,  15 , " 15:00 - 16:00        ", mFunc_agenda);
LCDML_add ( 23,  LCDML_0_1_1	,  16 , " 15:00 - 16:00        ", mFunc_agenda);
LCDML_add ( 24,  LCDML_0_1_1	,  17 , " 16:00 - 16:30        ", mFunc_agenda);
LCDML_add ( 25,  LCDML_0_1_1	,  18 , " 16:30 - 17:00        ", mFunc_agenda);
LCDML_add ( 26,  LCDML_0_1_1	,  19 , " 16:30 - 17:30        ", mFunc_agenda);
LCDML_add ( 27,  LCDML_0_1_1	,  20 , " 17:00 - 17:30        ", mFunc_agenda);
LCDML_add ( 28,  LCDML_0_1_1	,  21 , " 17:30 - 18:30        ", mFunc_agenda);
LCDML_add ( 29,  LCDML_0_1_1	,  22 , " 18:30 - 19:30        ", mFunc_agenda);
LCDML_add ( 30,  LCDML_0_1_1	,  23 , " 19:30 - 20:00        ", mFunc_agenda);
LCDML_add ( 31,  LCDML_0_1_2	,  1  , " 08:00 - 09:00        ", mFunc_agenda);
LCDML_add ( 32,  LCDML_0_1_2	,  2  , " 09:00 - 09:45        ", mFunc_agenda);
LCDML_add ( 33,  LCDML_0_1_2	,  3  , " 09:45 - 10:30        ", mFunc_agenda);
LCDML_add ( 34,  LCDML_0_1_2	,  4  , " 10:30 - 11:30        ", mFunc_agenda);
LCDML_add ( 35,  LCDML_0_1_2	,  5  , " 10:30 - 11:30        ", mFunc_agenda);
LCDML_add ( 36,  LCDML_0_1_2	,  6  , " 11:30 - 12:00        ", mFunc_agenda);
LCDML_add ( 37,  LCDML_0_1_2	,  7  , " 11:30 - 12:30        ", mFunc_agenda);
LCDML_add ( 38,  LCDML_0_1_2	,  8  , " 12:00 - 12:30        ", mFunc_agenda);
LCDML_add ( 39,  LCDML_0_1_2	,  9  , " 12:30 - 13:00        ", mFunc_agenda);
LCDML_add ( 40,  LCDML_0_1_2	,  10 , " 12:30 - 14:00        ", mFunc_agenda);
LCDML_add ( 41,  LCDML_0_1_2	,  11 , " 14:00 - 15:00        ", mFunc_agenda);
LCDML_add ( 42,  LCDML_0_1_2	,  12 , " 14:00 - 14:30        ", mFunc_agenda);
LCDML_add ( 43,  LCDML_0_1_2	,  13 , " 14:30 - 15:00        ", mFunc_agenda);
LCDML_add ( 44,  LCDML_0_1_2	,  14 , " 15:00 - 16:00        ", mFunc_agenda);
LCDML_add ( 45,  LCDML_0_1_2	,  15 , " 15:00 - 15:30        ", mFunc_agenda);
LCDML_add ( 46,  LCDML_0_1_2	,  16 , " 15:30 - 16:00        ", mFunc_agenda);
LCDML_add ( 47,  LCDML_0_1_2	,  17 , " 16:00 - 16:30        ", mFunc_agenda);
LCDML_add ( 48,  LCDML_0_1_2	,  18 , " 16:30 - 17:30        ", mFunc_agenda);
LCDML_add ( 49,  LCDML_0_1_2	,  19 , " 16:30 - 17:00        ", mFunc_agenda);
LCDML_add ( 50,  LCDML_0_1_2	,  20 , " 17:00 - 17:30        ", mFunc_agenda);
LCDML_add ( 51,  LCDML_0_1_2	,  21 , " 17:00 - 17:30        ", mFunc_agenda);
LCDML_add ( 52,  LCDML_0_1_2	,  22 , " 18:00 - 18:45        ", mFunc_agenda);
LCDML_add ( 53,  LCDML_0_1_2	,  23 , " 18:45 - 19:00        ", mFunc_agenda);
LCDML_add ( 54,  LCDML_0_1_2	,  24 , " 19:00 - 20:00        ", mFunc_agenda);
LCDML_add ( 55,  LCDML_0_6      ,  1  , " WhiteA10n3           ", mFunc_about);
LCDML_add ( 56 , LCDML_0_6      ,  2  , " xwings               ", mFunc_about);
LCDML_add ( 57 , LCDML_0_6      ,  3  , " KLKS                 ", mFunc_about); 
LCDML_add ( 58 , LCDML_0_6      ,  4  , " Hacknown             ", mFunc_light); 
LCDML_add ( 59 , LCDML_0_6      ,  5  , " overl0rd             ", mFunc_light); 
LCDML_add ( 60 , LCDML_0_6      ,  6  , " amigoh               ", mFunc_light); 
LCDML_add ( 61 , LCDML_0_6      ,  7  , " guess                ", mFunc_light); 
LCDML_add ( 62 , LCDML_0_6      ,  8  , " l33tdawg             ", mFunc_light); 
LCDML_add ( 63 , LCDML_0_2      ,  1  , " Organizer            ", NULL);
LCDML_add ( 64 , LCDML_0_2_1    ,  1  , " HITB                 ", NULL);
LCDML_add ( 65 , LCDML_0_2      ,  2  , " Endorsed by          ", NULL);
LCDML_add ( 66 , LCDML_0_2_2    ,  1  , " HSD                  ", NULL);
LCDML_add ( 67 , LCDML_0_2      ,  3  , " Gold Sponsors        ", NULL);
LCDML_add ( 68 , LCDML_0_2_3    ,  1  , " Microsoft            ", NULL);
LCDML_add ( 69 , LCDML_0_2_3    ,  2  , " Darkmatter           ", NULL);
LCDML_add ( 70 , LCDML_0_2      ,  4  , " Silver Sponsors      ", NULL);
LCDML_add ( 71 , LCDML_0_2_4    ,  1  , " Applied Risk         ", NULL);
LCDML_add ( 72 , LCDML_0_2_4    ,  2  , " Beyond Security      ", NULL);
LCDML_add ( 73 , LCDML_0_2_4    ,  3  , " Facebook             ", NULL);
LCDML_add ( 74 , LCDML_0_2_4    ,  4 , " Google                ", NULL);
LCDML_add ( 75 , LCDML_0_2      ,  5  , " Commsec Sponsor      ", NULL);
LCDML_add ( 76 , LCDML_0_2_5    ,  1  , " NIXU Security        ", NULL);
LCDML_add ( 77 , LCDML_0_2      ,  6  , " CTF Main Sponsor     ", NULL);
LCDML_add ( 78 , LCDML_0_2_6    ,  1  , " S-Unit               ", NULL);
LCDML_add ( 79 , LCDML_0_2      ,  7  , " CTF Prize Sponsor    ", NULL);
LCDML_add ( 80 , LCDML_0_2      ,  8  , " Bronze Sponsor       ", NULL);
LCDML_add ( 81 , LCDML_0_2_8    ,  1  , " Zerodium             ", NULL);
LCDML_add ( 82 , LCDML_0_2      ,  9  , " Connectivity Partners", NULL);
LCDML_add ( 83 , LCDML_0_2_9    ,  1  , " Aruba                ", NULL);
LCDML_add ( 84 , LCDML_0_2_9    ,  2  , " Juniper              ", NULL);
LCDML_add ( 85 , LCDML_0_2      ,  10 , " Media Partners       ", NULL);
LCDML_add ( 86 , LCDML_0_2_10   ,  1  , " Virtually Informed   ", NULL);
LCDML_add ( 87 , LCDML_0_2_10   ,  2  , " CISO Mag             ", NULL);
LCDML_add ( 88 , LCDML_0_2_10   ,  3  , " Mundo Hacker         ", NULL);
LCDML_add ( 89 , LCDML_0_2_10   ,  4  , " O'Reilly             ", NULL);
LCDML_add ( 90 , LCDML_0_2_10   ,  5  , " Computerworld        ", NULL);
LCDML_add ( 91 , LCDML_0_2_10   ,  6  , " Webwereld            ", NULL);
LCDML_add ( 92 , LCDML_0_2      ,  11 , " Extra Support        ", NULL);
LCDML_add ( 93 , LCDML_0_2_11   ,  1  , " nVIDIA               ", NULL);
LCDML_add ( 94 , LCDML_0_2      ,  12 , " Friends of HITB      ", NULL);
LCDML_add ( 95 , LCDML_0_2_12   ,  1  , " Hacknown             ", NULL);
LCDML_add ( 96 , LCDML_0_2_12   ,  2  , " 360 UnicornTeam      ", NULL);
LCDML_add ( 97 , LCDML_0_2_12   ,  3  , " Security Happenings  ", NULL);
LCDML_add ( 98 , LCDML_0_2_12   ,  4  , " No Starch Press      ", NULL);
LCDML_add ( 99 , LCDML_0_2_12   ,  5  , " WICS                 ", NULL);
LCDML_add ( 100, LCDML_0_2_12   ,  6  , " peerlyst             ", NULL);
LCDML_add ( 101, LCDML_0_2_12   ,  7  , " Vulnerability Labs   ", NULL);
LCDML_add ( 102, LCDML_0_2_12   ,  8  , " OWASP                ", NULL);
LCDML_add ( 103, LCDML_0_2      ,  13 , " Partner Events       ", NULL);
LCDML_add ( 104, LCDML_0_2_13   ,  1  , " BEVX                 ", NULL);
LCDML_add ( 105, LCDML_0_2_13   ,  2  , " infosec city         ", NULL);
LCDML_add ( 106, LCDML_0_2_13   ,  3  , " Blackhoodie          ", NULL);
LCDML_add ( 107, LCDML_0_2_13   ,  4  , " BSides Budapest      ", NULL);
LCDML_add ( 108, LCDML_0_2_13   ,  5  , " Nullcon              ", NULL);
LCDML_add ( 109, LCDML_0_2_13   ,  6  , " Confidence           ", NULL);
LCDML_add ( 110, LCDML_0_2_13   ,  7  , " 44 Con               ", NULL);
LCDML_add ( 111, LCDML_0_2_13   ,  8  , " Hitcon               ", NULL);
LCDML_add ( 112, LCDML_0_2_13   ,  9  , " PHD                  ", NULL);
LCDML_add ( 113, LCDML_0_2_13   ,  10 , " Troopers             ", NULL);
LCDML_add ( 114, LCDML_0_2_13   ,  11 , " Zero Nights          ", NULL);
LCDML_add ( 115, LCDML_0_2_13   ,  12 , " Code Blue            ", NULL); 

/*LCDML_add ( 56 , LCDML_0_1       ,  3  , " 03. FSK         ", NULL);
LCDML_add ( 57 , LCDML_0_1       ,  4  , " 04. GFSK        ", NULL);
LCDML_add ( 58 , LCDML_0_1       ,  5  , " 05. PSK         ", NULL);
LCDML_add ( 59 , LCDML_0_1       ,  6  , " 06. BPSK        ", NULL);
LCDML_add ( 12 , LCDML_0_1       ,  7  , " 07. QPSK        ", NULL);
LCDML_add (13 , LCDML_0_1       ,  8  , " 08. 8PSK        ", NULL);
LCDML_add (14 , LCDML_0_1_1		,  1  , " 01. SimpleRF    ", NULL); */

// ***TIP*** Try to update _LCDML_DISP_cnt when you add a menu elment.

// menu element count - last element id
// this value must be the same as the last menu element
#define _LCDML_DISP_cnt    115  

// create menu
LCDML_createMenu(_LCDML_DISP_cnt);

//// LCDMenuLib Setup
//LCDML_setup(_LCDML_DISP_cnt);

void lcdml_menu_control(void)
{
	uint8_t keysta;
	
	if(LCDML.BT_setup());

	keysta = bsp_GetKey();
	if (keysta == KEY_DOWN_A) { LCDML.BT_enter(); }
	if (keysta == KEY_DOWN_U) { LCDML.BT_up();    }
	if (keysta == KEY_DOWN_D) { LCDML.BT_down();  }
	if (keysta == KEY_DOWN_B) { LCDML.BT_quit();  }
	if (keysta == KEY_DOWN_L) { LCDML.BT_left();  }
	if (keysta == KEY_DOWN_R) { LCDML.BT_right(); }


}

/* ******************************************************************** */
void lcdml_menu_clear()
/* ******************************************************************** */
{

}

/* ******************************************************************** */
void lcdml_menu_display()
/* ******************************************************************** */
{
  // decalration of some variables
  // ***************    
  // content variable
  char content_text[_LCDML_DISP_cols];  // save the content text of every menu element 
  // menu element object
  LCDMenuLib2_menu *tmp;    
  // some limit values
  uint8_t i = LCDML.MENU_getScroll();
  uint8_t maxi = _LCDML_DISP_rows + i;
  uint8_t n = 0;  

   // init vars
  uint8_t n_max             = (LCDML.MENU_getChilds() >= _LCDML_DISP_rows) ? _LCDML_DISP_rows : (LCDML.MENU_getChilds());
 
  uint8_t scrollbar_min     = 0;
  uint8_t scrollbar_max     = LCDML.MENU_getChilds();
  uint8_t scrollbar_cur_pos = LCDML.MENU_getCursorPosAbs();
  uint8_t scroll_pos        = ((1.*n_max * _LCDML_DISP_rows) / (scrollbar_max - 1) * scrollbar_cur_pos);

  //do {

    n = 0;
    i = LCDML.MENU_getScroll();
    // update content
    // ***************
    
      // clear menu
      // ***************      
	if ( n_last != n_max )
	{
		n_last = n_max;
		LCD_DrawBox(_LCDML_DISP_box_x1 - _LCDML_DISP_scrollbar_w, _LCDML_DISP_box_y0+1, _LCDML_DISP_scrollbar_w-1, _LCDML_DISP_box_y1-_LCDML_DISP_box_y0-2, BLACK);    //清滚动条
	    LCD_Fill(_LCDML_DISP_box_x0+_LCDML_DISP_cur_space_before,_LCDML_DISP_box_y0+8+_LCDML_DISP_font_h*n_max,_LCDML_DISP_box_x1-2,_LCDML_DISP_box_y1-2, BLACK);       //清菜单显示多余的行
	}
	
	  //LCD_Clear(WHITE);
      
    // check if this element has children
    if (tmp = LCDML.MENU_getObj()->getChild(LCDML.MENU_getScroll())) 
    {
      // loop to display lines       
      //逐行显示菜单
      do
      {            
        // check if a menu element has a condetion and if the condetion be true               
        if (tmp->checkCondetion()) 
        {          
          // check the type off a menu element
          if(tmp->checkType_menu() == true)
          {          
            // display normal content
            LCDML_getContent(content_text, tmp->getID());
			if ( LCDML.MENU_getCursorPos() == n )
			{
				LCD_text_color(_LCDML_DISP_box_x0+_LCDML_DISP_cur_space_before,   _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * n+8, _LCDML_DISP_cursor_string, RED, BLACK);    //显示光标
				LCD_text_color(_LCDML_DISP_box_x0+_LCDML_DISP_font_w*_LCDML_DISP_cursor_len + _LCDML_DISP_cur_space_behind,  _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * n+8, content_text, RED, BLACK);    //反显选中菜单内容
				    // display scrollbar when more content as rows available and with > 2 
			    //显示滚动条
			    if (scrollbar_max > n_max && _LCDML_DISP_scrollbar_w > 2) 
			    {
			    	LCD_DrawBox(_LCDML_DISP_box_x1 - _LCDML_DISP_scrollbar_w+1, _LCDML_DISP_box_y0+1, _LCDML_DISP_scrollbar_w-2, _LCDML_DISP_box_y1-_LCDML_DISP_box_y0-2, BLACK);    //清楚滚动条
			      // set frame for scrollbar
			      //LCD_DrawFrame(_LCDML_DISP_box_x1 - _LCDML_DISP_scrollbar_w, _LCDML_DISP_box_y0, _LCDML_DISP_scrollbar_w, _LCDML_DISP_box_y1-_LCDML_DISP_box_y0, RED);
				  LCD_DrawLine(_LCDML_DISP_box_x1 - _LCDML_DISP_scrollbar_w, _LCDML_DISP_box_y0+1, _LCDML_DISP_box_x1 - _LCDML_DISP_scrollbar_w, _LCDML_DISP_box_y1-2, GREEN);    //显示滚动条框线
			      //LCD_FillRect(_LCDML_DISP_box_x1 - _LCDML_DISP_scrollbar_w, _LCDML_DISP_box_y0, _LCDML_DISP_box_x1, _LCDML_DISP_box_y1-1, RED);

			      // calculate scrollbar length
			      uint8_t scrollbar_block_length = scrollbar_max - n_max;
			      scrollbar_block_length = (_LCDML_DISP_box_y1-_LCDML_DISP_box_y0) / (scrollbar_block_length + _LCDML_DISP_rows);

			      //set scrollbar
			      if (scrollbar_cur_pos == 0) {                                   // top position     (min)
			        LCD_DrawBox(_LCDML_DISP_box_x1 - (_LCDML_DISP_scrollbar_w-1), _LCDML_DISP_box_y0 + 1, (_LCDML_DISP_scrollbar_w-2)  , scrollbar_block_length, GREEN);
			        //LCD_FillRect(_LCDML_DISP_box_x1 - (_LCDML_DISP_scrollbar_w-1), _LCDML_DISP_box_y0 + 1  , (_LCDML_DISP_box_x1-2), _LCDML_DISP_box_y1, RED);
			      } 
			      else if (scrollbar_cur_pos == (scrollbar_max-1)) {            // bottom position  (max)         
			        LCD_DrawBox(_LCDML_DISP_box_x1 - (_LCDML_DISP_scrollbar_w-1), _LCDML_DISP_box_y1 - scrollbar_block_length, (_LCDML_DISP_scrollbar_w-2)  , scrollbar_block_length, GREEN);
			        //LCD_FillRect(_LCDML_DISP_box_x1 - (_LCDML_DISP_scrollbar_w-1), _LCDML_DISP_box_y1 - scrollbar_block_length, (_LCDML_DISP_box_x1-2)  , _LCDML_DISP_box_y1, RED);
			      } 
			      else {                                                                // between top and bottom
			        LCD_DrawBox(_LCDML_DISP_box_x1 - (_LCDML_DISP_scrollbar_w-1), _LCDML_DISP_box_y0 + (scrollbar_block_length * scrollbar_cur_pos + 1),(_LCDML_DISP_scrollbar_w-2)  , scrollbar_block_length, GREEN);
			        //LCD_FillRect(_LCDML_DISP_box_x1 - (_LCDML_DISP_scrollbar_w-1), _LCDML_DISP_box_y0 + (scrollbar_block_length * scrollbar_cur_pos + 1),(_LCDML_DISP_box_x1-2)  , _LCDML_DISP_box_y1, RED);
			      }       
    }
			}
			else
			{
				LCD_text_color(_LCDML_DISP_box_x0+_LCDML_DISP_cur_space_before,   _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * n+8, _LCDML_DISP_cursor_string, BLACK, BLACK);    //清除光标
				//LCD_DrawBox(_LCDML_DISP_box_x0+_LCDML_DISP_cur_space_before,   _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * n+8, _LCDML_DISP_font_w*_LCDML_DISP_cursor_len, _LCDML_DISP_font_h, WHITE);
				LCD_text_color(_LCDML_DISP_box_x0+_LCDML_DISP_font_w*_LCDML_DISP_cursor_len + _LCDML_DISP_cur_space_behind,  _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * n+8, content_text, GREEN, BLACK);//正显菜单内容
			}
			//display_string_GB2312(_LCDML_DISP_box_x0+_LCDML_DISP_font_w*_LCDML_DISP_cursor_len + _LCDML_DISP_cur_space_behind,  _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * (n + 1), content_text, RED, WHITE);
            //u8g2.drawStr( _LCDML_DISP_box_x0+_LCDML_DISP_font_w + _LCDML_DISP_cur_space_behind, _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * (n + 1), content_text);
          }            
          else 
          { 
            if(tmp->checkType_dynParam()) {                      
              tmp->callback(n);
            }                 
          }
          // increment some values 
          i++; 
          n++;     
        } 
      // try to go to the next sibling and check the number of displayed rows           
      } while (((tmp = tmp->getSibling(1)) != NULL) && (i < maxi));
    }

    // set cursor
    //显示光标
    //u8g2.drawStr( _LCDML_DISP_box_x0+_LCDML_DISP_cur_space_before, _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * (LCDML.MENU_getCursorPos() + 1),  _LCDML_DISP_cursor_string);
	//display_string_GB2312(_LCDML_DISP_box_x0+_LCDML_DISP_cur_space_before, _LCDML_DISP_box_y0 + _LCDML_DISP_font_h * (LCDML.MENU_getCursorPos())+8, _LCDML_DISP_cursor_string, RED, WHITE);
    
    if(_LCDML_DISP_draw_frame == 1) {
       //u8g2.drawFrame(_LCDML_DISP_box_x0, _LCDML_DISP_box_y0, (_LCDML_DISP_box_x1-_LCDML_DISP_box_x0), (_LCDML_DISP_box_y1-_LCDML_DISP_box_y0));
    }

  //} while ( 1 );
}

void Menu_DrawFrame(void)
{
//	uint32_t CPU_Sn0;

	//画框
	
	LCD_DrawRect(0, 0, 159, 127, GREEN);
	LCD_DrawLine(0, 32, 159, 32, GREEN);

	LCD_setTextColor(WHITE, BLACK);
	LCD_text("      HITB 2018 GSEC      ", 1, 12);

}

void Menu_UpdateFrame(void)
{

}


void Menu_Init(void)
{
	Menu_DrawFrame();
    // LCDMenuLib Setup
    LCDML_setup(_LCDML_DISP_cnt);

    // Enable Men眉 Rollover 
    LCDML.MENU_enRollover();
}

void Menu_Loop(void)
{
	// this function must called here, do not delete it
	LCDML.loop();
}

uint8_t g_button_value = 0;
u16 g_agenda_id = 0;
void mFunc_agenda(uint8_t param)
{
	u16 agenda_id;
	if (LCDML.FUNC_setup())          // ****** SETUP *********
	{
		agenda_id = LCDML.FUNC_getID() - 8;
		LCD_Fill(0, 0, 159, 127, BLACK);
		LCD_setTextColor(RED, BLACK);
		LCD_text("Track: ", 0, 3); LCD_println(&agenda[agenda_id * 6][0]);
		LCD_text("Time: ", 0, 14); LCD_println(&agenda[agenda_id * 6 + 1][0]);
		LCD_text("Title: ", 0, 25); LCD_println(&agenda[agenda_id * 6+ 2][0]);
		LCD_text("Speaker: ", 0, 47); LCD_println(&agenda[agenda_id * 6 + 4][0]);
		display_qrcode(0, 70, &agenda[agenda_id * 6 + 3][0], 2, BLACK);
		display_qrcode(102, 70, &agenda[agenda_id * 6 + 5][0], 2, BLACK);
		g_button_value = 0;
		g_agenda_id = agenda_id;
	}
	if (LCDML.FUNC_loop())           // ****** LOOP *********
	{
		if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
		{
			if (LCDML.BT_checkLeft() || LCDML.BT_checkUp()) // check if button left is pressed
			{
				LCDML.BT_resetLeft(); // reset the left button
				LCDML.BT_resetUp(); // reset the left button
				g_button_value++;
				//agenda_id = LCDML.FUNC_getID() - 8;
				if (g_agenda_id > 0)
				{
					g_agenda_id--;
					LCD_Fill(0, 0, 159, 127, BLACK);
					LCD_setTextColor(RED, BLACK);
					LCD_text("Track: ", 0, 3); LCD_println(&agenda[g_agenda_id * 6][0]);
					LCD_text("Time: ", 0, 14); LCD_println(&agenda[g_agenda_id * 6 + 1][0]);
					LCD_text("Title: ", 0, 25); LCD_println(&agenda[g_agenda_id * 6 + 2][0]);
					LCD_text("Speaker: ", 0, 47); LCD_println(&agenda[g_agenda_id * 6 + 4][0]);
					display_qrcode(0, 70, &agenda[g_agenda_id * 6 + 3][0], 2, BLACK);
					display_qrcode(102, 70, &agenda[g_agenda_id * 6 + 5][0], 2, BLACK);
				}

			}
			else  if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) // check if button left is pressed
			{
				LCDML.BT_resetRight(); // reset the left button
				LCDML.BT_resetDown(); // reset the left button
				g_button_value++;
				//agenda_id = LCDML.FUNC_getID() - 8;

				if (g_agenda_id < 47)
				{
					g_agenda_id++;
					LCD_Fill(0, 0, 159, 127, BLACK);
					LCD_setTextColor(RED, BLACK);
					LCD_text("Track: ", 0, 3); LCD_println(&agenda[g_agenda_id * 6][0]);
					LCD_text("Time: ", 0, 14); LCD_println(&agenda[g_agenda_id * 6 + 1][0]);
					LCD_text("Title: ", 0, 25); LCD_println(&agenda[g_agenda_id * 6 + 2][0]);
					LCD_text("Speaker: ", 0, 47); LCD_println(&agenda[g_agenda_id * 6 + 4][0]);
					display_qrcode(0, 70, &agenda[g_agenda_id * 6 + 3][0], 2, BLACK);
					display_qrcode(102, 70, &agenda[g_agenda_id * 6 + 5][0], 2, BLACK);
				}
			}
		}
	}
	if (LCDML.FUNC_close())     // ****** STABLE END *********
	{
		// you can here reset some global vars or do nothing
		LCD_Fill(0, 0, 159, 127, BLACK);
		Menu_DrawFrame();
	}
}

void mFunc_about(uint8_t param)
{
	u16 agenda_id;
	if (LCDML.FUNC_setup())          // ****** SETUP *********
	{
		agenda_id = LCDML.FUNC_getID() - 55;
		LCD_Fill(1, 1, 158, 126, BLACK);
		LCD_setTextColor(GREEN, BLACK);
		LCD_text("Designer: ", 4, 8); 
		LCD_setTextColor(RED, BLACK); 
		LCD_println(&about[agenda_id * 2][0]);
		LCD_setTextColor(GREEN, BLACK);
		LCD_text("Twitter: ", 4, 22); 
		display_qrcode(4, 36, &about[agenda_id*2+1][0], 3, BLACK);
		ws2812_rainbow(5);
		
	}
	if (LCDML.FUNC_loop())           // ****** LOOP *********
	{
	}
	if (LCDML.FUNC_close())     // ****** STABLE END *********
	{
		// you can here reset some global vars or do nothing
		ws2812_clear();
		LCD_Fill(1, 1, 158, 126, BLACK);
		Menu_DrawFrame();

	}
}


void mFunc_lcd_setlight(uint8_t param)
{
	static uint16_t t_light;
	if (LCDML.FUNC_setup())          // ****** SETUP *********
	{
		bsp_ReadCpuFlash(LIGHT_ADDR, (uint8_t *)&t_light, 2);
		LCD_Fill(1, 1, 158, 126, BLACK);
		LCD_DrawRect(0, 0, 159, 127, GREEN);
		LCD_DrawLine(0, 32, 159, 32, GREEN);
		LCD_setTextColor(WHITE, BLACK);
		//LCD_text("      TFT LIGHT SET       ", 1, 12);
		LCD_text("    TFT LIGHT ( 1 - 9 )   ", 1, 12);
		LCD_text("    <<==           ==>>   ", 1, 56);

		LCD_setCursor(79, 56);
		LCD_write(t_light+0x30);
		LCD_DrawRect(26, 86, 134, 96, WHITE);
		LCD_Fill(27, 87, 133, 95, BLACK);
		LCD_DrawBox(27 + (t_light - 1) * 12, 87, 12, 9, WHITE);
	}
	if (LCDML.FUNC_loop())           // ****** LOOP *********
	{
		if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
		{
			if (LCDML.BT_checkLeft() || LCDML.BT_checkDown()) // check if button left is pressed
			{
				LCDML.BT_resetLeft(); // reset the left button
				LCDML.BT_resetDown(); // reset the left button
				if (t_light > 1)
				{
					t_light--;
				}
				LCD_Light_Set(t_light);
				LCD_setCursor(79, 56);
				LCD_write(t_light + 0x30);
				//LCD_DrawRect(26, 86, 134, 96, WHITE);
				LCD_Fill(27, 87, 133, 95, BLACK);
				LCD_DrawBox(27 + (t_light - 1) * 12, 87, 12, 9, WHITE);
			}
			else  if (LCDML.BT_checkRight() || LCDML.BT_checkUp()) // check if button left is pressed
			{
				LCDML.BT_resetRight(); // reset the left button
				LCDML.BT_resetDown(); // reset the left button

				if (t_light < 9)
				{
					t_light++;
				}
				LCD_Light_Set(t_light);
				LCD_setCursor(79, 56);
				LCD_write(t_light + 0x30);
				//LCD_DrawRect(26, 86, 134, 96, WHITE);
				LCD_Fill(27, 87, 133, 95, BLACK);
				LCD_DrawBox(27 + (t_light - 1) * 12, 87, 12, 9, WHITE);
			}
			else  if (LCDML.BT_checkEnter()) // check if button left is pressed
			{
				bsp_WriteCpuFlash(LIGHT_ADDR, (uint8_t *)&t_light, 2);
				LCDML.FUNC_goBackToMenu();
			}
		}
	}
	if (LCDML.FUNC_close())     // ****** STABLE END *********
	{
		// you can here reset some global vars or do nothing
		LCD_Fill(1, 1, 158, 126, BLACK);
		Menu_DrawFrame();
	}
}

void mFunc_secret(uint8_t param)
{
	static uint8_t n_pos = 0;	//位置
	static uint16_t crack_temp = 0;
	static uint8_t pwd[8] = { 0x30, 0x30,0x30,0x30,0x30,0x30,0x30,0x30 };
	static uint8_t CPU_ID[8] = { 0 };
	if (LCDML.FUNC_setup())          // ****** SETUP *********
	{
		uint8_t i;
		uint32_t CPU_Sn0, CPU_Sn1;

		CPU_Sn0 = *(__IO uint32_t*)(0x1ffff7e8);
		CPU_Sn1 = *(__IO uint32_t*)(0x1ffff7e8 + 4);

		for (i = 0; i < 4; i++)
		{
			CPU_ID[7-i] = ((CPU_Sn0 >> (i * 4)) & 0x0f);
		}
		for (i = 0; i < 4; i++)
		{
			CPU_ID[3-i] = ((CPU_Sn1 >> (i * 4)) & 0x0f);
		}
		
		CPU_ID[0] += 0x01;
		CPU_ID[1] += 0x03;
		CPU_ID[2] += 0x03;
		CPU_ID[3] += 0x07;
		CPU_ID[4] += 0x05;
		CPU_ID[5] += 0x03;
		CPU_ID[6] += 0x04;
		CPU_ID[7] += 0x07;
		
		for (i = 0; i < 8; i++)
		{
			if (CPU_ID[i] > 15)
			{
				CPU_ID[i] -= 16;
				CPU_ID[i] += 0x30;
			}
			else if (CPU_ID[i] > 9)
			{
				CPU_ID[i] += 0x37;
			}
			else
			{
				CPU_ID[i] += 0x30;
			}
		}

		LCD_Fill(1, 1, 158, 126, BLACK);
		LCD_DrawRect(0, 0, 159, 127, GREEN);
		LCD_DrawLine(0, 32, 159, 32, GREEN);
		LCD_setTextColor(WHITE, BLACK);
		//LCD_text("      TFT LIGHT SET       ", 1, 12);
		LCD_text("UID: ", 14, 12);
		display_num_format(44, 12, CPU_Sn1, 1, "%08X", RED, BLACK);
		display_num_format(98, 12, CPU_Sn0, 1, "%08X", RED, BLACK);	

		bsp_ReadCpuFlash(CRACK_ADDR, (uint8_t *)&crack_temp, 2);

		if (crack_temp == 0x0301)
		{
			LCD_setTextColor(WHITE, BLACK);
			LCD_text("          pwned!          ", 1, 64);
			ws2812_theaterChaseRainbow(10);
			ws2812_clear();
		}
		else
		{
			LCD_setTextColor(WHITE, BLACK);
			LCD_text("PASSWORD: ", 14, 48);

			LCD_text("________", 14, 80);
		}
	}
	if (LCDML.FUNC_loop())           // ****** LOOP *********
	{
		if (crack_temp != 0x0301)
		{
			if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
			{
				if (LCDML.BT_checkLeft()) // check if button left is pressed
				{
					LCDML.BT_resetLeft(); // reset the left button

					if (n_pos > 0)
					{
						LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], WHITE, BLACK, 1);
						n_pos--;
						LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
						//if (n_pos == 0)
						//{
						//	LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
						//}
					}
				}
				else if (LCDML.BT_checkRight()) // check if button left is pressed
				{
					LCDML.BT_resetRight(); // reset the left button

					if (n_pos < 7)
					{
						//if (n_pos == 0)
						//{
						//	LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
						//}
						LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], WHITE, BLACK, 1);
						n_pos++;
						LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
					}
				}
				else if (LCDML.BT_checkUp())
				{
					LCDML.BT_resetUp(); // reset the left button

					if (pwd[n_pos] == 0x20)
					{
						pwd[n_pos] = 0x7f;
					}
					pwd[n_pos]--;
					LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
				}
				else if (LCDML.BT_checkDown())
				{
					if (pwd[n_pos] == 0x7f)
					{
						pwd[n_pos] = 0x19;
					}
					pwd[n_pos]++;
					LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
				}
				else if (LCDML.BT_checkEnter())
				{
					LCDML.BT_resetEnter(); // reset the left button

					uint8_t cmp_flag = 0;
					uint8_t i;
					for (i = 0; i < 8; i++)
					{
						if (pwd[i] != CPU_ID[i])
						{
							cmp_flag = 1;
							break;
						}
					}
					if (cmp_flag == 0)
					{
						LCD_setTextColor(RED, BLACK);
						LCD_text("Cool!", 94, 48);
						bsp_DelayMS(1000);
						LCD_text("      ", 94, 48);
						crack_temp = 0x0301;
						bsp_WriteCpuFlash(CRACK_ADDR, (uint8_t *)&crack_temp, 2);

						LCD_Fill(1, 33, 158, 126, BLACK);
						LCD_setTextColor(WHITE, BLACK);
						LCD_text("          pwned!          ", 1, 64);
						ws2812_theaterChaseRainbow(10);
						LCDML.FUNC_close();
					}
					else
					{
						LCD_setTextColor(RED, BLACK);
						LCD_text("Error!", 94, 48);
						bsp_DelayMS(1000);
						LCD_text("      ", 94, 48);
					}
				}
			}
		}
	}
	if (LCDML.FUNC_close())     // ****** STABLE END *********
	{
		// you can here reset some global vars or do nothing
		LCD_Fill(1, 1, 158, 126, BLACK);
		Menu_DrawFrame();
	}
}

void mFunc_guess_num(uint8_t param)
{
	static uint8_t n_pos = 0;
	static uint16_t highsc_temp = 0;
	static uint8_t guess[4] = { 0x5f, 0x5f, 0x5f, 0x5f };
	static uint8_t rand_num[4] = { 0 };
	static uint8_t guess_time = 0;
	
	if (LCDML.FUNC_setup())          // ****** SETUP *********
	{
		u16 iSeed = 0;
		u8 i, j;
		uint16_t crack_temp = 0;
		LCD_Fill(1, 1, 158, 126, BLACK);
		LCD_DrawRect(0, 0, 159, 127, GREEN);

		bsp_ReadCpuFlash(CRACK_ADDR, (uint8_t *)&crack_temp, 2);

		if (crack_temp != 0x0301)
		{
			LCD_setTextColor(WHITE, BLACK);
			LCD_text("     Touch me please!     ", 1, 48);
			bsp_DelayMS(2000);
			LCDML.MENU_goRoot();
		}
		else
		{
			LCD_DrawLine(0, 32, 159, 32, GREEN);
			LCD_DrawLine(79, 32, 79, 127, GREEN);
			LCD_setTextColor(WHITE, BLACK);
			LCD_text("       Guess Number       ", 1, 12);

			bsp_ReadCpuFlash(GUESSNUM_ADDR, (uint8_t *)&highsc_temp, 2);

			if (highsc_temp == 0xffff)
			{
				highsc_temp = 0;
				bsp_WriteCpuFlash(GUESSNUM_ADDR, (uint8_t *)&highsc_temp, 2);
			}
			LCD_text("Tiptop: ", 83, 48);
			display_num_format(131, 48, highsc_temp, 1, "%04d", RED, BLACK);
			LCD_text("_ _ _ _", 99, 80);

			iSeed = bsp_GetAdc_Average(1);//通过模拟输入获取悬空引脚的电平产生随机种子
			srand(iSeed);
			rand_num[0] = (u8)(rand() % 10);//产生随机数0~3
			for (i = 1; i < 4; i++)
			{
				do
				{
					rand_num[i] = (u8)(rand() % 10);//产生随机数0~3
					for (j = 0; j < i; j++)
					{
						if (rand_num[i] == rand_num[j])
						{
							break;
						}
					}
					if (j == i) break;
				} while (1);
			}
			n_pos = 0;
			guess_time = 0;
			guess[0] = 0x5f;
			guess[1] = 0x5f;
			guess[2] = 0x5f;
			guess[3] = 0x5f;
		}
	}
	if (LCDML.FUNC_loop())           // ****** LOOP *********
	{
		uint8_t countA = 0;
		uint8_t countB = 0;
		uint8_t i,j;
		if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
		{
			if (LCDML.BT_checkLeft()) // check if button left is pressed
			{
				LCDML.BT_resetLeft(); // reset the left button

				if (n_pos > 0)
				{
					guess[n_pos] = 0x5f;
					LCD_DrawChar(99 + n_pos * 12, 80, guess[n_pos], WHITE, BLACK, 1);
					n_pos--;
					LCD_DrawChar(99 + n_pos * 12, 80, guess[n_pos], RED, BLACK, 1);
					//if (n_pos == 0)
					//{
					//	LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
					//}
				}
			}
			else if (LCDML.BT_checkRight()) // check if button left is pressed
			{
				LCDML.BT_resetRight(); // reset the left button

				if (n_pos < 4)
				{
					//if (n_pos == 0)
					//{
					//	LCD_DrawChar(14 + n_pos * 6, 80, pwd[n_pos], RED, BLACK, 1);
					//}
					LCD_DrawChar(99 + n_pos * 12, 80, guess[n_pos], WHITE, BLACK, 1);
					n_pos++;
					LCD_DrawChar(99 + n_pos * 12, 80, guess[n_pos], RED, BLACK, 1);
				}
			}
			else if (LCDML.BT_checkUp())
			{
				LCDML.BT_resetUp(); // reset the left button

				if ((guess[n_pos] > 0x39) || (guess[n_pos] < 0x30) )
				{
					guess[n_pos] = 0x3A;
				}
				else if (guess[n_pos] == 0x30)
				{
					guess[n_pos] = 0x3A;
				}
				guess[n_pos]--;
				
				LCD_DrawChar(99 + n_pos * 12, 80, guess[n_pos], RED, BLACK, 1);
			}
			else if (LCDML.BT_checkDown())
			{
				LCDML.BT_resetDown(); // reset the down button
				if ((guess[n_pos] > 0x39) || (guess[n_pos] < 0x30))
				{
					guess[n_pos] = 0x2F;
				}
				else if (guess[n_pos] == 0x39)
				{
					guess[n_pos] = 0x2F;
				}
				guess[n_pos]++;
				
				LCD_DrawChar(99 + n_pos * 12, 80, guess[n_pos], RED, BLACK, 1);
			}
			else if (LCDML.BT_checkEnter())
			{
				LCDML.BT_resetEnter(); // reset the left button

				u8 t_flag = 0;

				for (i = 0; i < 4; i++)
				{
					for (j = i + 1; j < 4; j++)
					{
						if (guess[i] == guess[j])
						{
							t_flag = 1;
							break;
						}
					}
				}
				if (t_flag == 0)
				{

					for (i = 0; i < 4; i++)
					{
						for (j = 0; j < 4; j++)
						{
							if (guess[j] == rand_num[i]+0x30)
							{
								if (j == i)
								{
									countA++;
								}
								else
								{
									countB++;
								}
							}
						}
					}

					if (guess_time < 8)
					{
						if (countA == 4)
						{
							LCD_Fill(1, 33, 158, 126, BLACK);
							LCD_setTextColor(WHITE, BLACK);
							LCD_text("     Congratulation!      ", 1, 48);
							highsc_temp++;
							bsp_WriteCpuFlash(GUESSNUM_ADDR, (uint8_t *)&highsc_temp, 2);
							LCD_text("     Tiptop: ", 1, 80);
							display_num_format(79, 80, highsc_temp, 1, "%04d", RED, BLACK);
							bsp_DelayMS(2000);
							LCDML.OTHER_jumpToFunc(mFunc_guess_num);
						}
						else
						{
							LCD_text("  A   B", 16, 40 + 10 * guess_time);
							LCD_DrawChar(16, 40 + 10 * guess_time, countA+0x30, RED, BLACK, 1);
							LCD_DrawChar(16 + 24, 40 + 10 * guess_time, countB+0x30, RED, BLACK, 1);
							guess_time++;
						}

					}
					else
					{
						LCD_Fill(1, 33, 158, 126, BLACK);
						LCD_setTextColor(WHITE, BLACK);
						LCD_text("       Game Over !        ", 1, 48);
						LCD_text("     Tiptop: ", 1, 80);
						display_num_format(79, 80, highsc_temp, 1, "%04d", RED, BLACK);
						bsp_DelayMS(2000);
						LCDML.FUNC_goBackToMenu();
					}
				}
			}
		}
	}
	if (LCDML.FUNC_close())     // ****** STABLE END *********
	{
		// you can here reset some global vars or do nothing
		LCD_Fill(1, 1, 158, 126, BLACK);
		Menu_DrawFrame();
	}
}

static u8 tt = 0;
void mFunc_light(uint8_t param)
{
	u16 agenda_id;
	if (LCDML.FUNC_setup())          // ****** SETUP *********
	{
		agenda_id = LCDML.FUNC_getID() - 58;
		LCD_Fill(1, 1, 158, 126, BLACK);
		LCD_setTextColor(WHITE, BLACK);
		LCD_setTextSize(2);
		LCD_text(&name_temp[agenda_id][0],1,48);
		LCD_setTextSize(1);
	}
	if (LCDML.FUNC_loop())           // ****** LOOP *********
	{
		if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
		{
			//if (LCDML.BT_checkLeft() || LCDML.BT_checkUp()) // check if button left is pressed
			//{
			//	LCDML.BT_resetLeft(); // reset the left button
			//	LCDML.BT_resetUp(); // reset the left button
			//	LCDML.FUNC_close();
			//}
			//else  if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) // check if button left is pressed
			//{
			//	LCDML.BT_resetRight(); // reset the left button
			//	LCDML.BT_resetDown(); // reset the left button
			//	LCDML.FUNC_close();
			//}
			if (LCDML.BT_checkQuit()) // check if button left is pressed
			{
				tt = 1;
				ws2812_clear();
				LCDML.BT_resetQuit(); // reset the left button
				LCDML.FUNC_close();
			}
		}
		while (tt == 0)
		{
			ws2812_theaterChase(ws2812_RGB_Color(255, 0, 0), 20);
			ws2812_theaterChase(ws2812_RGB_Color(0, 255, 0), 20);
			ws2812_theaterChase(ws2812_RGB_Color(0, 0, 255), 20);
			ws2812_rainbow(20);
			ws2812_rainbowCycle(20);
			ws2812_theaterChaseRainbow(20);
		}
	}
	if (LCDML.FUNC_close())     // ****** STABLE END *********
	{
		// you can here reset some global vars or do nothing
		LCD_Fill(1, 1, 158, 126, BLACK);
		ws2812_clear();
		Menu_DrawFrame();
	}
}

//void mFunc_temp(uint8_t param)
//{
//	if (LCDML.FUNC_setup())          // ****** SETUP *********
//	{
//		g_button_value = 0;
//	}
//	if (LCDML.FUNC_loop())           // ****** LOOP *********
//	{
//		if (LCDML.BT_checkAny()) // check if any button is pressed (enter, up, down, left, right)
//		{
//			if (LCDML.BT_checkLeft() || LCDML.BT_checkUp()) // check if button left is pressed
//			{
//				LCDML.BT_resetLeft(); // reset the left button
//				LCDML.BT_resetUp(); // reset the left button
//				g_button_value++;
//			}
//			else  if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) // check if button left is pressed
//			{
//				LCDML.BT_resetRight(); // reset the left button
//				LCDML.BT_resetDown(); // reset the left button
//				g_button_value++;
//			}
//			else  if (LCDML.BT_checkEnter()) // check if button left is pressed
//			{
//				LCDML.BT_resetEnter(); // reset the left button
//				g_button_value++;
//			}
//		}
//	}
//	if (LCDML.FUNC_close())     // ****** STABLE END *********
//	{
//		// you can here reset some global vars or do nothing
//		LCD_Fill(1, 1, 158, 126, BLACK);
//		Menu_DrawFrame();
//	}
//}

