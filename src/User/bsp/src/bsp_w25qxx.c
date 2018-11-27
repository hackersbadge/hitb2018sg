 #include "bsp.h"	

//u16 W25QXX_TYPE = W25Q128;	//Ĭ����W25Q128
//							//ÿ��page 256 Byte��һ��65536��page 0-65535������65535��0��
//							//4KbytesΪһ��Sector
//							//16������Ϊ1��Block
//							//W25Q128
//							//����Ϊ16M�ֽ�,����128��Block,4096��Sector 

//SPI_FLASH_T W25QXX_INFO;

//selѡ��FlashоƬ��staΪʹ��ѡ�0/DISABLEΪ���ã�1/ENABLEΪʹ��
void W25QXX_CS(u8 sel, u8 sta)
{
	switch (sel)
	{
#if W25QXX_OB == 1
	case W25QXX_OB_SEL:
		W25QXX_OB_CS = !sta;		//W25QXX�ǵ͵�ƽʹ�ܣ�����Ҫȡ��
		break;
#endif
#if W25QXX_EX == 1
	case W25QXX_EX_SEL:
		W25QXX_EX_CS = !sta;
		break;
#endif
	default:
		break;
	}
}

//��ʼ��SPI FLASH��IO��
void bsp_W25QXX_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

#if W25QXX_OB == 1
	RCC_AHB1PeriphClockCmd(RCC_OB_CS_PORT, ENABLE);//ʹ��GPIOBʱ��
#endif // W25QXX_OB == 1

#if W25QXX_EX == 1
	RCC_AHB1PeriphClockCmd(RCC_EX_CS_PORT, ENABLE);//ʹ��GPIOGʱ��
#endif // W25QXX_EX == 1

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	
#if W25QXX_OB == 1
	GPIO_InitStructure.GPIO_Pin = OB_CS_PIN;//PB12 W25QXX_OB
	GPIO_Init(GPIO_PORT_OB, &GPIO_InitStructure);//��ʼ��
	W25QXX_CS(W25QXX_OB_SEL, DISABLE);					//����SPI FLASH��ѡ��
	bsp_Init_SPI(W25QXX_OB_SPI, W25QXX_OB_SPI_SPEED);	//��ʼ��SPI2������Ϊ21Mʱ��,����ģʽ 
#endif // W25QXX_OB == 1

#if W25QXX_EX == 1
	GPIO_InitStructure.GPIO_Pin = EX_CS_PIN;//PG10 W25QXX_EX
	GPIO_Init(GPIO_PORT_EX, &GPIO_InitStructure);//��ʼ��
	W25QXX_CS(W25QXX_EX_SEL, DISABLE);					//��չ��SPI FLASH��ѡ��
	bsp_Init_SPI(W25QXX_EX_SPI, W25QXX_EX_SPI_SPEED);	//��ʼ��SPI1������Ϊ42Mʱ��,����ģʽ 
#endif // W25QXX_EX == 1

	//W25QXX_TYPE = bsp_W25QXX_ReadID(SPI1, 1);	//��ȡFLASH ID.
}

//��ȡW25QXX��״̬�Ĵ���
//BIT7  6   5   4   3   2   1   0
//SPR   RV  TB BP2 BP1 BP0 WEL BUSY
//SPR:Ĭ��0,״̬�Ĵ�������λ,���WPʹ��
//TB,BP2,BP1,BP0:FLASH����д��������
//WEL:дʹ������
//BUSY:æ���λ(1,æ;0,����)
//Ĭ��:0x00
u8 W25QXX_ReadSR(SPI_TypeDef* SPIx, u8 sel)
{
	u8 byte = 0;
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_ReadStatusReg);    //���Ͷ�ȡ״̬�Ĵ�������    
	byte = bsp_SPI_RW_Byte(SPIx, W25X_DUMMY);             //��ȡһ���ֽ�  
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     
	return byte;
}
//дW25QXX״̬�Ĵ���
//ֻ��SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)����д!!!
void W25QXX_Write_SR(SPI_TypeDef* SPIx, u8 sel, u8 sr)
{
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_WriteStatusReg);   //����дȡ״̬�Ĵ�������    
	bsp_SPI_RW_Byte(SPIx, sr);               //д��һ���ֽ�  
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
}
//W25QXXдʹ��	
//��WEL��λ   
void W25QXX_Write_Enable(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_WriteEnable);      //����дʹ��  
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
}
//W25QXXд��ֹ	
//��WEL����  
void W25QXX_Write_Disable(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_WriteDisable);     //����д��ָֹ��    
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
}
//��ȡоƬID
//����ֵ����:				   
//0XEF13,��ʾоƬ�ͺ�ΪW25Q80  
//0XEF14,��ʾоƬ�ͺ�ΪW25Q16    
//0XEF15,��ʾоƬ�ͺ�ΪW25Q32  
//0XEF16,��ʾоƬ�ͺ�ΪW25Q64 
//0XEF17,��ʾоƬ�ͺ�ΪW25Q128 	  
u16 bsp_W25QXX_ReadID(SPI_TypeDef* SPIx, u8 sel)
{
	u16 Temp = 0;
	W25QXX_CS(sel, ENABLE);
	bsp_SPI_RW_Byte(SPIx, 0x90);//���Ͷ�ȡID����	    
	bsp_SPI_RW_Byte(SPIx, 0x00);
	bsp_SPI_RW_Byte(SPIx, 0x00);
	bsp_SPI_RW_Byte(SPIx, 0x00);
	Temp |= bsp_SPI_RW_Byte(SPIx, W25X_DUMMY) << 8;
	Temp |= bsp_SPI_RW_Byte(SPIx, W25X_DUMMY);
	W25QXX_CS(sel, DISABLE);
	return Temp;
}

//��ȡSPI FLASH  
//��ָ����ַ��ʼ��ȡָ�����ȵ�����
//pBuffer:���ݴ洢��
//ReadAddr:��ʼ��ȡ�ĵ�ַ(24bit)
//NumByteToRead:Ҫ��ȡ���ֽ���(���2^32-1,4294967295)
void bsp_W25QXX_Read(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 ReadAddr, u32 NumByteToRead)
{
	u32 i;
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_ReadData);         //���Ͷ�ȡ����   
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 16));  //����24bit��ַ    
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)ReadAddr);
	for (i = 0; i < NumByteToRead; i++)
	{
		pBuffer[i] = bsp_SPI_RW_Byte(SPIx, W25X_DUMMY);   //ѭ������  
	}
	W25QXX_CS(sel, DISABLE);
}

//��ȡSPI FLASH���ݽ��бȶ�  
//��ָ����ַ��ʼ��ȡָ�����ȵ�����
//pBuffer:���ݴ洢��
//ReadAddr:��ʼ��ȡ�ĵ�ַ(24bit)
//NumByteToRead:Ҫ��ȡ���ֽ���(���2^32-1,4294967295)
//����ֵ����ȫ��ͬ����0���в�ͬ����1
uint8_t bsp_W25QXX_CmpData(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 ReadAddr, u32 NumByteToRead)
{
	u32 i;
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_ReadData);         //���Ͷ�ȡ����   
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 16));  //����24bit��ַ    
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)ReadAddr);
	for (i = 0; i < NumByteToRead; i++)
	{
		if (pBuffer[i] != bsp_SPI_RW_Byte(SPIx, W25X_DUMMY))	//ѭ�������Ƚ�
		{
			W25QXX_CS(sel, DISABLE);
			return 1;
		}
	}
	W25QXX_CS(sel, DISABLE);
	return 0;
}

//SPI��һҳ(0~65535)��д������256���ֽڵ�����
//��ָ����ַ��ʼд�����256�ֽڵ�����
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)
//NumByteToWrite:Ҫд����ֽ���(���256),������Ӧ�ó�����ҳ��ʣ���ֽ���!!!	 
void W25QXX_Write_Page(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite)
{
	u16 i;
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_PageProgram);      //����дҳ����   
	bsp_SPI_RW_Byte(SPIx, (u8)((WriteAddr) >> 16)); //����24bit��ַ    
	bsp_SPI_RW_Byte(SPIx, (u8)((WriteAddr) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)WriteAddr);
	for (i = 0; i < NumByteToWrite; i++)bsp_SPI_RW_Byte(SPIx, pBuffer[i]);//ѭ��д��  
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ 
	W25QXX_Wait_Busy(SPIx, sel);					   //�ȴ�д�����
}
//�޼���дSPI FLASH 
//����ȷ����д�ĵ�ַ��Χ�ڵ�����ȫ��Ϊ0XFF,�����ڷ�0XFF��д������ݽ�ʧ��!
//�����Զ���ҳ���� 
//��ָ����ַ��ʼд��ָ�����ȵ�����,����Ҫȷ����ַ��Խ��!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)
//NumByteToWrite:Ҫд����ֽ���(���2^32-1,4294967295)
//CHECK OK
void bsp_W25QXX_Write_NoCheck(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u32 NumByteToWrite)
{
	u16 pageremain;
	pageremain = 256 - WriteAddr % 256; //��ҳʣ����ֽ���		 	    
	if (NumByteToWrite <= pageremain)pageremain = NumByteToWrite;//������256���ֽ�
	while (1)
	{
		W25QXX_Write_Page(SPIx, sel, pBuffer, WriteAddr, pageremain);
		if (NumByteToWrite == pageremain)break;//д�������
		else //NumByteToWrite>pageremain
		{
			pBuffer += pageremain;
			WriteAddr += pageremain;

			NumByteToWrite -= pageremain;			  //��ȥ�Ѿ�д���˵��ֽ���
			if (NumByteToWrite > 256)pageremain = 256; //һ�ο���д��256���ֽ�
			else pageremain = NumByteToWrite; 	  //����256���ֽ���
		}
	};
}

//дSPI FLASH  
//��ָ����ַ��ʼд��ָ�����ȵ�����
//�ú�������������!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)						
//NumByteToWrite:Ҫд����ֽ���(���2^32-1,4294967295) 
u8 W25QXX_BUFFER[4096];
void bsp_W25QXX_Write(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u32 NumByteToWrite)
{
	u32 secpos;
	u16 secoff;
	u16 secremain;
	u16 i;
	u8 * W25QXX_BUF;
	W25QXX_BUF = W25QXX_BUFFER;
	secpos = WriteAddr / 4096;//������ַ  
	secoff = WriteAddr % 4096;//�������ڵ�ƫ��
	secremain = 4096 - secoff;//����ʣ��ռ��С   
	//printf("ad:%X,nb:%X\r\n",WriteAddr,NumByteToWrite);//������
	if (NumByteToWrite <= secremain)secremain = NumByteToWrite;//������4096���ֽ�
	while (1)
	{
		bsp_W25QXX_Read(SPIx, sel, W25QXX_BUF, secpos * 4096, 4096);//������������������
		for (i = 0; i < secremain; i++)//У������
		{
			if (W25QXX_BUF[secoff + i] != 0XFF)break;//��Ҫ����  	  
		}
		if (i < secremain)//��Ҫ����
		{
			bsp_W25QXX_Erase_Sector(SPIx, sel, secpos);//�����������
			for (i = 0; i < secremain; i++)	   //����
			{
				W25QXX_BUF[i + secoff] = pBuffer[i];
			}
			bsp_W25QXX_Write_NoCheck(SPIx, sel, W25QXX_BUF, secpos * 4096, 4096);//д����������  
			//if (bsp_W25QXX_CmpData(SPIx, sel, W25QXX_BUF, secpos * 4096, 4096))
			//{
			//	printf("\r\nWrite Error!\r\n");
			//	break;
			//}
		}
		else
		{
			bsp_W25QXX_Write_NoCheck(SPIx, sel, pBuffer, WriteAddr, secremain);//д�Ѿ������˵�,ֱ��д������ʣ������. 	
			//if (bsp_W25QXX_CmpData(SPIx, sel, pBuffer, WriteAddr, secremain))
			//{
			//	printf("\r\nWrite Error!\r\n");
			//	break;
			//}
		}
					   
		if (NumByteToWrite == secremain)break;//д�������
		else//д��δ����
		{
			secpos++;//������ַ��1
			secoff = 0;//ƫ��λ��Ϊ0 	 

			pBuffer += secremain;  //ָ��ƫ��
			WriteAddr += secremain;//д��ַƫ��	   
			NumByteToWrite -= secremain;				//�ֽ����ݼ�
			if (NumByteToWrite > 4096)secremain = 4096;	//��һ����������д����
			else secremain = NumByteToWrite;			//��һ����������д����
		}
	};
}
//��������оƬ		  
//�ȴ�ʱ�䳬��...
//W25Q32 7-15�룬W25Q128 25-40�� 
void bsp_W25QXX_Erase_Chip(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 
	W25QXX_Wait_Busy(SPIx, sel);
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_ChipErase);        //����Ƭ��������  
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
	W25QXX_Wait_Busy(SPIx, sel);   				   //�ȴ�оƬ��������
}
//����һ������ 4K Byte
//Sector_Addr:������ַ ����ʵ����������
//����һ������������ʱ��:30ms
void bsp_W25QXX_Erase_Sector(SPI_TypeDef* SPIx, u8 sel, u16 Sector_Addr)
{
	u32 addr_tmp;
	//����falsh�������,������   
	//printf("fe:%x\r\n", Sector_Addr);
	addr_tmp = 4096 * Sector_Addr;
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 	 
	W25QXX_Wait_Busy(SPIx, sel);
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_SectorErase);      //������������ָ�� 
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 16));  //����24bit��ַ    
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)addr_tmp);
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
	W25QXX_Wait_Busy(SPIx, sel);   				   //�ȴ��������
}

//����һ������ 64K Byte
//Block_Addr:�����ַ ����ʵ����������
//����һ�����������ʱ��:150ms
void bsp_W25QXX_Erase_Block(SPI_TypeDef* SPIx, u8 sel, u16 Block_Addr)
{
	u32 addr_tmp;
	//����falsh�������,������   
	//printf("fe:%x\r\n", Block_Addr);
	addr_tmp = 4096 * 16 * Block_Addr;
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 	 
	W25QXX_Wait_Busy(SPIx, sel);
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_BlockErase);      //�����������ָ�� 
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 16));  //����24bit��ַ    
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)addr_tmp);
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
	W25QXX_Wait_Busy(SPIx, sel);   				   //�ȴ��������
}

//�ȴ�����
void W25QXX_Wait_Busy(SPI_TypeDef* SPIx, u8 sel)
{
	while ((W25QXX_ReadSR(SPIx, sel) & 0x01) == 0x01);   // �ȴ�BUSYλ���
}
//�������ģʽ
void W25QXX_PowerDown(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_PowerDown);        //���͵�������  
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
	bsp_DelayUS(3);                               //�ȴ�TPD  
}
//����
void W25QXX_WAKEUP(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //ʹ������   
	bsp_SPI_RW_Byte(SPIx, W25X_ReleasePowerDown);   //  send W25X_PowerDown command 0xAB    
	W25QXX_CS(sel, DISABLE);                          //ȡ��Ƭѡ     	      
	bsp_DelayUS(3);                               //�ȴ�TRES1
}
//
///*
//*********************************************************************************************************
//*	�� �� ��: sf_ReadInfo
//*	����˵��: ��ȡ����ID,�������������
//*	��    ��:  ��
//*	�� �� ֵ: ��
//*********************************************************************************************************
//*/
//void sf_ReadInfo(void)
//{
//	/* �Զ�ʶ����Flash�ͺ� */
//	{
//		W25QXX_INFO.ChipID = bsp_W25QXX_ReadID();	/* оƬID */
//
//		switch (W25QXX_INFO.ChipID)
//		{
//		case SST25VF016B_ID:
//			strcpy(W25QXX_INFO.ChipName, "SST25VF016B");
//			W25QXX_INFO.TotalSize = 2 * 1024 * 1024;	/* ������ = 2M */
//			W25QXX_INFO.PageSize = 4 * 1024;			/* ҳ���С = 4K */
//			break;
//
//		case MX25L1606E_ID:
//			strcpy(g_tSF.ChipName, "MX25L1606E");
//			W25QXX_INFO.TotalSize = 2 * 1024 * 1024;	/* ������ = 2M */
//			W25QXX_INFO.PageSize = 4 * 1024;			/* ҳ���С = 4K */
//			break;
//
//		case W25Q64BV_ID:
//			strcpy(W25QXX_INFO.ChipName, "W25Q64BV");
//			W25QXX_INFO.TotalSize = 8 * 1024 * 1024;	/* ������ = 8M */
//			W25QXX_INFO.PageSize = 4 * 1024;			/* ҳ���С = 4K */
//			break;
//
//		default:
//			strcpy(W25QXX_INFO.ChipName, "Unknow Flash");
//			W25QXX_INFO.TotalSize = 2 * 1024 * 1024;
//			W25QXX_INFO.PageSize = 4 * 1024;
//			break;
//		}
//	}
//}

