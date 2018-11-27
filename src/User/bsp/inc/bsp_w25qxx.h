#ifndef __BSP_W25QXX_H__
#define __BSP_W25QXX_H__

//W25Xϵ��/Qϵ��оƬ�б���ӦID
   	
#define W25X05  	0xEF05
#define W25X10  	0xEF10
#define W25Q20 	    0xEF11
#define W25X40 	    0xEF12
#define W25Q80 	    0xEF13 	
#define W25Q16 	    0xEF14
#define W25Q32  	0xEF15
#define W25Q64  	0xEF16
#define W25Q128		0xEF17

//typedef enum
//{
//	W25X05_ID = 0xEF05,
//	W25X10_ID = 0xEF10,
//	W25Q20_ID = 0xEF11,
//	W25X40_ID = 0xEF12,
//	W25Q80_ID = 0xEF13,
//	W25Q16_ID = 0xEF14,
//	W25Q32_ID = 0xEF15,
//	W25Q64_ID = 0xEF16,
//	W25Q128_ID = 0xEF17
//}W25QXX_ID;

//typedef struct
//{
//	uint32_t ChipID;		/* оƬID */
//	char ChipName[16];		/* оƬ�ͺ��ַ�������Ҫ������ʾ */
//	uint32_t TotalSize;		/* ������ */
//	uint16_t PageSize;		/* ҳ���С */
//}SPI_FLASH_T;
//
//extern SPI_FLASH_T W25QXX_INFO;					//����W25QXXоƬ�ͺ�		   		

#define	W25QXX_OB	1	//���ð���W25QXX
#define	W25QXX_EX	1	//������չ��W25QXX

#if W25QXX_OB == 1
	#define GPIO_PORT_OB			GPIOB			/* GPIO�˿� */
	#define RCC_OB_CS_PORT 			RCC_AHB1Periph_GPIOB		/* GPIO�˿�ʱ�� */
	#define OB_CS_PIN				GPIO_Pin_12			/* ���ӵ�CS��GPIO */
	#define W25QXX_OB_CS			PBout(12)	//����W25QXX��Ƭѡ�ź�
	#define W25QXX_OB_SPI			SPI2
	#define W25QXX_OB_SPI_SPEED		SPI_SPEED_21M
	//#define W25QXX_OB_WP			NULL		//����W25QXX��д�����ź�
#endif

#if W25QXX_EX == 1
	#define GPIO_PORT_EX			GPIOG			/* GPIO�˿� */
	#define RCC_EX_CS_PORT 			RCC_AHB1Periph_GPIOG		/* GPIO�˿�ʱ�� */
	#define EX_CS_PIN				GPIO_Pin_10			/* ���ӵ�CS��GPIO */
	#define W25QXX_EX_CS			PGout(10)	//��չ��W25QXX��Ƭѡ�ź�
	#define W25QXX_EX_SPI			SPI1
	#define W25QXX_EX_SPI_SPEED		SPI_SPEED_42M
	
	//#define W25QXX_EX_WP			PGout(11)	//��չ��W25QXX��д�����ź�
#endif

////////////////////////////////////////////////////////////////////////////////// 
//ָ���

#define W25X_WriteEnable		    0x06 
#define W25X_WriteDisable		    0x04 
#define W25X_ReadStatusReg			0x05 
#define W25X_WriteStatusReg			0x01 
#define W25X_ReadData			    0x03 
#define W25X_FastReadData		    0x0B 
#define W25X_FastReadDual		    0x3B 
#define W25X_PageProgram		    0x02 
#define W25X_BlockErase				0xD8 
#define W25X_SectorErase		    0x20 
#define W25X_ChipErase				0xC7 
#define W25X_PowerDown				0xB9 
#define W25X_ReleasePowerDown		0xAB 
#define W25X_DeviceID			    0xAB 
#define W25X_ManufactDeviceID		0x90 
#define W25X_JedecDeviceID			0x9F 
#define W25X_DUMMY					0xFF		// ���������Ϊ����ֵ�����ڶ�������ͨ����0xff

//W25QXXоƬѡ�񣬰��ػ�����չ����
typedef enum
{
	W25QXX_OB_SEL = 0,
	W25QXX_EX_SEL
}_W25QXX_SEL;

void bsp_W25QXX_Init(void);
uint16_t  bsp_W25QXX_ReadID(SPI_TypeDef* SPIx, u8 sel);  	    		//��ȡFLASH ID
void bsp_W25QXX_Read(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 ReadAddr, u32 NumByteToRead);   //��ȡflash
uint8_t bsp_W25QXX_CmpData(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 ReadAddr, u32 NumByteToRead);   //У��flash����
void bsp_W25QXX_Write(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u32 NumByteToWrite);//д��flash
void bsp_W25QXX_Write_NoCheck(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u32 NumByteToWrite);
void bsp_W25QXX_Erase_Chip(SPI_TypeDef* SPIx, u8 sel);    	  	//��Ƭ����
void bsp_W25QXX_Erase_Sector(SPI_TypeDef* SPIx, u8 sel, u16 Sector_Addr);	//��������
void bsp_W25QXX_Erase_Block(SPI_TypeDef* SPIx, u8 sel, u16 Block_Addr);	//�������

void W25QXX_CS(u8 sel, u8 sta);			//ѡ��FLASH
uint8_t	W25QXX_ReadSR(SPI_TypeDef* SPIx, u8 sel);        		//��ȡ״̬�Ĵ��� 
void W25QXX_Write_SR(SPI_TypeDef* SPIx, u8 sel, u8 sr);  			//д״̬�Ĵ���
void W25QXX_Write_Enable(SPI_TypeDef* SPIx, u8 sel);  		//дʹ�� 
void W25QXX_Write_Disable(SPI_TypeDef* SPIx, u8 sel);		//д����
void W25QXX_Write_Page(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite);//ҳд
void W25QXX_Wait_Busy(SPI_TypeDef* SPIx, u8 sel);           	//�ȴ�����
void W25QXX_PowerDown(SPI_TypeDef* SPIx, u8 sel);        	//�������ģʽ
void W25QXX_WAKEUP(SPI_TypeDef* SPIx, u8 sel);				//����

#endif /* __BSP_W25QXX_H__ */


