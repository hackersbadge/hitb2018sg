/*
*********************************************************************************************************
*
*	ģ������ : ����STM32F4�ڲ�TIM���PWM�źţ�˳��ʵ��
*	�ļ����� : bsp_tim_pwm.h
*	��    �� : V1.0
*	˵    �� : ͷ�ļ�
*
*	Copyright (C), 2012-2013, 
*
*********************************************************************************************************
*/

#ifndef __BSP_TIM_PWM_H__
#define __BSP_TIM_PWM_H__

void bsp_SetTIMOutPWM(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, TIM_TypeDef* TIMx, uint8_t _ucChannel,
	uint32_t _ulFreq, uint32_t _ulDutyCycle);

void bsp_SetTIMOutPWM_N(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, TIM_TypeDef* TIMx, uint8_t _ucChannel,
	uint32_t _ulFreq, uint32_t _ulDutyCycle);

void bsp_TIM_Init(TIM_TypeDef* TIMx, uint32_t _ulFreq, uint8_t _PreemptionPriority, uint8_t _SubPriority);

uint32_t bsp_GetRCCofGPIO(GPIO_TypeDef* GPIOx);
uint16_t bsp_GetPinSource(uint16_t gpio_pin);

#endif

/***************************** (END OF FILE) *********************************/