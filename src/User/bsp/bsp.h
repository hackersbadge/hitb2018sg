/*
*********************************************************************************************************
*
*	模块名称 : BSP模块
*	文件名称 : bsp.h
*	说    明 : 这是底层驱动模块所有的h文件的汇总文件。 应用程序只需 #include bsp.h 即可，
*			  不需要#include 每个模块的 h 文件
*
*	Copyright (C), 2013-2014,  
*
*********************************************************************************************************
*/

#ifndef _BSP_H_
#define _BSP_H

#ifdef __cplusplus
extern "C" {
#endif 

#define STM32_V4
//#define STM32_X2

/* 检查是否定义了开发板型号 */
#if !defined (STM32_V4) && !defined (STM32_X2)
	#error "Please define the board model : STM32_X2 or STM32_V4"
#endif

/* 定义 BSP 版本号 */
#define __STM32F1_BSP_VERSION		"1.1"

/* CPU空闲时执行的函数 */
//#define CPU_IDLE()		bsp_Idle()

/* 开关全局中断的宏 */
#define ENABLE_INT()	__set_PRIMASK(0)	/* 使能全局中断 */
#define DISABLE_INT()	__set_PRIMASK(1)	/* 禁止全局中断 */

/* 这个宏仅用于调试阶段排错 */
#define BSP_Printf		printf
//#define BSP_Printf(...)

//位带操作,实现51类似的GPIO控制功能
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).M4同M3类似,只是寄存器地址变了.
//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO?????
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08

//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

#include "stm32f10x.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef TRUE
	#define TRUE  1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#ifndef PI
#define PI 3.14159265358979
#endif

#ifndef ABS
#define ABS(x) (((x)>=0)?(x):-(x))
#endif

#ifndef MIN
#define MIN(x,y) (((x)<(y))?(x):(y))
#endif

#ifndef MAX
#define MAX(x,y) (((x)>(y))?(x):(y))
#endif

//位操作宏定义
#define bit(b)                         			(1UL << (b))
#define lowByte(w)                    			((w) & 0xFF)
#define highByte(w)                    			(((w) >> 8) & 0xFF)
#define bitRead(value, bit)          		  	(((value) >> (bit)) & 0x01)
#define bitSet(value, bit)           		  	((value) |= (1UL << (bit)))
#define bitClear(value, bit)           			((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) 			(bitvalue ? bitSet(value, bit) : bitClear(value, bit))

typedef bool boolean;

#ifndef pgm_read_byte
	#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif

#define LIGHT_ADDR   (0x08000000 + 0x10000 - 0x400)
#define CRACK_ADDR   (0x08000000 + 0x10000 - 0x800)
#define GUESSNUM_ADDR (0x08000000 + 0x10000 - 0xC00)

#include "bsp_user_lib.h"
#include "bsp_led.h"
#include "bsp_timer.h"
#include "bsp_key.h"
#include "bsp_spi_bus.h"
#include "bsp_tft.h"
#include "bsp_font.h"
#include "bsp_uart_fifo.h"
#include "qrcode.h"
#include "bsp_menu.h"
#include "bsp_tim_pwm.h"
#include "bsp_cpu_flash.h"
#include "bsp_adc.h"
//#include "snake.h"

/* 提供给其他C文件调用的函数 */
void bsp_Init(void);
void bsp_Idle(void);
void PrintfID(void);

#ifdef __cplusplus
	}
#endif /* __cplusplus */

#endif

/*****************************  (END OF FILE) *********************************/
