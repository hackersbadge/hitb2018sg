#ifndef __BSP_START_H__
#define __BSP_START_H__

#ifdef __cplusplus
extern "C" {
#endif

//static void ADC_Configuration(void);
//void bsp_AdcProDMA(void);
//uint16_t GetADC(void);
//void bsp_stat_tft(void);

void bsp_InitAdc(void);
u16 bsp_GetAdc(void);
u16 bsp_GetAdc_Average(u8 times);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BSP_TFT_H__ */
