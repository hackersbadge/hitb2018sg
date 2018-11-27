#include "bsp.h"

//#define SAMP_COUNT	20		/* ������������ʾ200ms�ڵĲ���������ƽ��ֵ */
//
//uint16_t g_usAdcValue;	/* ADC ����ֵ��ƽ��ֵ */
//
///*
//*********************************************************************************************************
//*	�� �� ��: ADC_Configuration
//*	����˵��: ����ADC, PA3��ΪADCͨ������
//*	��    �Σ���
//*	�� �� ֵ: ��
//*********************************************************************************************************
//*/
//static void ADC_Configuration(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	ADC_InitTypeDef ADC_InitStructure;
//	__IO uint16_t ADCConvertedValue;
//
//	/* ʹ�� ADC1 and GPIOC clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);
//
//	/* ����PC4Ϊģ������(ADC Channel14) */
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//	/* ����ADC1, ����DMA, ��������� */
//	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
//	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
//	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
//	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
//	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
//	ADC_InitStructure.ADC_NbrOfChannel = 1;
//	ADC_Init(ADC1, &ADC_InitStructure);
//
//	/* ����ADC1 ����ͨ��14 channel14 configuration */
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_55Cycles5);
//
//	/* ʹ��ADC1 DMA���� */
//	ADC_DMACmd(ADC1, ENABLE);
//
//	/* ʹ�� ADC1 */
//	ADC_Cmd(ADC1, ENABLE);
//
//	/* ʹ��ADC1 ��λУ׼�Ĵ��� */
//	ADC_ResetCalibration(ADC1);
//	/* ���ADC1�ĸ�λ�Ĵ��� */
//	while (ADC_GetResetCalibrationStatus(ADC1));
//
//	/* ����ADC1У׼ */
//	ADC_StartCalibration(ADC1);
//	/* ���У׼�Ƿ���� */
//	while (ADC_GetCalibrationStatus(ADC1));
//
//	/* �������ADCת�� */
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
//}
//
///*
//*********************************************************************************************************
//*	�� �� ��: AdcPro
//*	����˵��: ADC������������1ms systick �жϽ��е���
//*	��    �Σ���
//*	�� �� ֵ: ��
//*********************************************************************************************************
//*/
//void bsp_AdcProDMA(void)
//{
//	static uint16_t buf[SAMP_COUNT];
//	static uint8_t write;
//	uint32_t sum;
//	uint8_t i;
//
//	buf[write] = ADC_GetConversionValue(ADC1);
//	if (++write >= SAMP_COUNT)
//	{
//		write = 0;
//	}
//
//	/* ������δ��������ƽ��ֵ�ķ��������˲�
//		Ҳ���Ը����£�ѡ��ȥ����������2��ֵ��ʹ���ݸ��Ӿ�ȷ
//	*/
//	sum = 0;
//	for (i = 0; i < SAMP_COUNT; i++)
//	{
//		sum += buf[i];
//	}
//	g_usAdcValue = sum / SAMP_COUNT;	/* ADC����ֵ�����ɴβ���ֵƽ�� */
//
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);	/* ��������´�ADCת�� */
//}
//
///*
//*********************************************************************************************************
//*	�� �� ��: GetADC
//*	����˵��: ��ȡADC������ƽ��ֵ
//*	��    �Σ���
//*	�� �� ֵ: ��
//*********************************************************************************************************
//*/
//uint16_t GetADC(void)
//{
//	uint16_t ret;
//
//	/* ��Ϊ	g_AdcValue ������systick�ж��и�д��Ϊ�˱��������������ʱ���жϳ�����ҵ������ݴ��������Ҫ
//	�ر��жϽ��б��� */
//
//	/* �����ٽ����������ر��ж� */
//	__set_PRIMASK(1);  /* ���ж� */
//
//	ret = g_usAdcValue;
//
//	__set_PRIMASK(0);  /* ���ж� */
//
//	return ret;
//}

void  bsp_InitAdc(void)
{
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);   //ʹ��ADC1ͨ��ʱ��


	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M

	//PA1 ��Ϊģ��ͨ����������                         
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;       //ģ����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	ADC_DeInit(ADC1);  //��λADC1,������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;  //ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;   //ģ��ת�������ڵ�ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; //ģ��ת�������ڵ���ת��ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //ת��������������ⲿ��������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  //ADC�����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 1; //˳����й���ת����ADCͨ������Ŀ
	ADC_Init(ADC1, &ADC_InitStructure); //����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���   


	ADC_Cmd(ADC1, ENABLE);  //ʹ��ָ����ADC1

	ADC_ResetCalibration(ADC1); //ʹ�ܸ�λУ׼  

	while (ADC_GetResetCalibrationStatus(ADC1)); //�ȴ���λУ׼����

	ADC_StartCalibration(ADC1);  //����ADУ׼

	while (ADC_GetCalibrationStatus(ADC1));   //�ȴ�У׼����

//  ADC_SoftwareStartConvCmd(ADC1, ENABLE);     //ʹ��ָ����ADC1�����ת����������

}
//���ADCֵ
//ch:ͨ��ֵ 0~3
u16 bsp_GetAdc(void)
{
	//����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_239Cycles5);   //ADC1,ADCͨ��,����ʱ��Ϊ239.5����                   

	ADC_SoftwareStartConvCmd(ADC1, ENABLE);     //ʹ��ָ����ADC1�����ת����������    

	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));//�ȴ�ת������

	return ADC_GetConversionValue(ADC1);    //�������һ��ADC1�������ת�����
}

u16 bsp_GetAdc_Average(u8 times)
{
	u32 temp_val = 0;
	u8 t;
	for (t = 0; t < times; t++)
	{
		temp_val += bsp_GetAdc();
		bsp_DelayMS(5);
	}
	return temp_val / times;
}


