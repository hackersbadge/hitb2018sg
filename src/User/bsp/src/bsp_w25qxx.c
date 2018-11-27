 #include "bsp.h"	

//u16 W25QXX_TYPE = W25Q128;	//默认是W25Q128
//							//每个page 256 Byte，一共65536个page 0-65535，超过65535回0。
//							//4Kbytes为一个Sector
//							//16个扇区为1个Block
//							//W25Q128
//							//容量为16M字节,共有128个Block,4096个Sector 

//SPI_FLASH_T W25QXX_INFO;

//sel选择Flash芯片，sta为使能选项，0/DISABLE为禁用，1/ENABLE为使能
void W25QXX_CS(u8 sel, u8 sta)
{
	switch (sel)
	{
#if W25QXX_OB == 1
	case W25QXX_OB_SEL:
		W25QXX_OB_CS = !sta;		//W25QXX是低电平使能，所以要取反
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

//初始化SPI FLASH的IO口
void bsp_W25QXX_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

#if W25QXX_OB == 1
	RCC_AHB1PeriphClockCmd(RCC_OB_CS_PORT, ENABLE);//使能GPIOB时钟
#endif // W25QXX_OB == 1

#if W25QXX_EX == 1
	RCC_AHB1PeriphClockCmd(RCC_EX_CS_PORT, ENABLE);//使能GPIOG时钟
#endif // W25QXX_EX == 1

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	
#if W25QXX_OB == 1
	GPIO_InitStructure.GPIO_Pin = OB_CS_PIN;//PB12 W25QXX_OB
	GPIO_Init(GPIO_PORT_OB, &GPIO_InitStructure);//初始化
	W25QXX_CS(W25QXX_OB_SEL, DISABLE);					//板载SPI FLASH不选中
	bsp_Init_SPI(W25QXX_OB_SPI, W25QXX_OB_SPI_SPEED);	//初始化SPI2，设置为21M时钟,高速模式 
#endif // W25QXX_OB == 1

#if W25QXX_EX == 1
	GPIO_InitStructure.GPIO_Pin = EX_CS_PIN;//PG10 W25QXX_EX
	GPIO_Init(GPIO_PORT_EX, &GPIO_InitStructure);//初始化
	W25QXX_CS(W25QXX_EX_SEL, DISABLE);					//扩展板SPI FLASH不选中
	bsp_Init_SPI(W25QXX_EX_SPI, W25QXX_EX_SPI_SPEED);	//初始化SPI1，设置为42M时钟,高速模式 
#endif // W25QXX_EX == 1

	//W25QXX_TYPE = bsp_W25QXX_ReadID(SPI1, 1);	//读取FLASH ID.
}

//读取W25QXX的状态寄存器
//BIT7  6   5   4   3   2   1   0
//SPR   RV  TB BP2 BP1 BP0 WEL BUSY
//SPR:默认0,状态寄存器保护位,配合WP使用
//TB,BP2,BP1,BP0:FLASH区域写保护设置
//WEL:写使能锁定
//BUSY:忙标记位(1,忙;0,空闲)
//默认:0x00
u8 W25QXX_ReadSR(SPI_TypeDef* SPIx, u8 sel)
{
	u8 byte = 0;
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_ReadStatusReg);    //发送读取状态寄存器命令    
	byte = bsp_SPI_RW_Byte(SPIx, W25X_DUMMY);             //读取一个字节  
	W25QXX_CS(sel, DISABLE);                          //取消片选     
	return byte;
}
//写W25QXX状态寄存器
//只有SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)可以写!!!
void W25QXX_Write_SR(SPI_TypeDef* SPIx, u8 sel, u8 sr)
{
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_WriteStatusReg);   //发送写取状态寄存器命令    
	bsp_SPI_RW_Byte(SPIx, sr);               //写入一个字节  
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
}
//W25QXX写使能	
//将WEL置位   
void W25QXX_Write_Enable(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_WriteEnable);      //发送写使能  
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
}
//W25QXX写禁止	
//将WEL清零  
void W25QXX_Write_Disable(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_WriteDisable);     //发送写禁止指令    
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
}
//读取芯片ID
//返回值如下:				   
//0XEF13,表示芯片型号为W25Q80  
//0XEF14,表示芯片型号为W25Q16    
//0XEF15,表示芯片型号为W25Q32  
//0XEF16,表示芯片型号为W25Q64 
//0XEF17,表示芯片型号为W25Q128 	  
u16 bsp_W25QXX_ReadID(SPI_TypeDef* SPIx, u8 sel)
{
	u16 Temp = 0;
	W25QXX_CS(sel, ENABLE);
	bsp_SPI_RW_Byte(SPIx, 0x90);//发送读取ID命令	    
	bsp_SPI_RW_Byte(SPIx, 0x00);
	bsp_SPI_RW_Byte(SPIx, 0x00);
	bsp_SPI_RW_Byte(SPIx, 0x00);
	Temp |= bsp_SPI_RW_Byte(SPIx, W25X_DUMMY) << 8;
	Temp |= bsp_SPI_RW_Byte(SPIx, W25X_DUMMY);
	W25QXX_CS(sel, DISABLE);
	return Temp;
}

//读取SPI FLASH  
//在指定地址开始读取指定长度的数据
//pBuffer:数据存储区
//ReadAddr:开始读取的地址(24bit)
//NumByteToRead:要读取的字节数(最大2^32-1,4294967295)
void bsp_W25QXX_Read(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 ReadAddr, u32 NumByteToRead)
{
	u32 i;
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_ReadData);         //发送读取命令   
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 16));  //发送24bit地址    
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)ReadAddr);
	for (i = 0; i < NumByteToRead; i++)
	{
		pBuffer[i] = bsp_SPI_RW_Byte(SPIx, W25X_DUMMY);   //循环读数  
	}
	W25QXX_CS(sel, DISABLE);
}

//读取SPI FLASH数据进行比对  
//在指定地址开始读取指定长度的数据
//pBuffer:数据存储区
//ReadAddr:开始读取的地址(24bit)
//NumByteToRead:要读取的字节数(最大2^32-1,4294967295)
//返回值：完全相同返回0，有不同返回1
uint8_t bsp_W25QXX_CmpData(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 ReadAddr, u32 NumByteToRead)
{
	u32 i;
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_ReadData);         //发送读取命令   
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 16));  //发送24bit地址    
	bsp_SPI_RW_Byte(SPIx, (u8)((ReadAddr) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)ReadAddr);
	for (i = 0; i < NumByteToRead; i++)
	{
		if (pBuffer[i] != bsp_SPI_RW_Byte(SPIx, W25X_DUMMY))	//循环读数比较
		{
			W25QXX_CS(sel, DISABLE);
			return 1;
		}
	}
	W25QXX_CS(sel, DISABLE);
	return 0;
}

//SPI在一页(0~65535)内写入少于256个字节的数据
//在指定地址开始写入最大256字节的数据
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)
//NumByteToWrite:要写入的字节数(最大256),该数不应该超过该页的剩余字节数!!!	 
void W25QXX_Write_Page(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite)
{
	u16 i;
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_PageProgram);      //发送写页命令   
	bsp_SPI_RW_Byte(SPIx, (u8)((WriteAddr) >> 16)); //发送24bit地址    
	bsp_SPI_RW_Byte(SPIx, (u8)((WriteAddr) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)WriteAddr);
	for (i = 0; i < NumByteToWrite; i++)bsp_SPI_RW_Byte(SPIx, pBuffer[i]);//循环写数  
	W25QXX_CS(sel, DISABLE);                          //取消片选 
	W25QXX_Wait_Busy(SPIx, sel);					   //等待写入结束
}
//无检验写SPI FLASH 
//必须确保所写的地址范围内的数据全部为0XFF,否则在非0XFF处写入的数据将失败!
//具有自动换页功能 
//在指定地址开始写入指定长度的数据,但是要确保地址不越界!
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)
//NumByteToWrite:要写入的字节数(最大2^32-1,4294967295)
//CHECK OK
void bsp_W25QXX_Write_NoCheck(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u32 NumByteToWrite)
{
	u16 pageremain;
	pageremain = 256 - WriteAddr % 256; //单页剩余的字节数		 	    
	if (NumByteToWrite <= pageremain)pageremain = NumByteToWrite;//不大于256个字节
	while (1)
	{
		W25QXX_Write_Page(SPIx, sel, pBuffer, WriteAddr, pageremain);
		if (NumByteToWrite == pageremain)break;//写入结束了
		else //NumByteToWrite>pageremain
		{
			pBuffer += pageremain;
			WriteAddr += pageremain;

			NumByteToWrite -= pageremain;			  //减去已经写入了的字节数
			if (NumByteToWrite > 256)pageremain = 256; //一次可以写入256个字节
			else pageremain = NumByteToWrite; 	  //不够256个字节了
		}
	};
}

//写SPI FLASH  
//在指定地址开始写入指定长度的数据
//该函数带擦除操作!
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)						
//NumByteToWrite:要写入的字节数(最大2^32-1,4294967295) 
u8 W25QXX_BUFFER[4096];
void bsp_W25QXX_Write(SPI_TypeDef* SPIx, u8 sel, u8* pBuffer, u32 WriteAddr, u32 NumByteToWrite)
{
	u32 secpos;
	u16 secoff;
	u16 secremain;
	u16 i;
	u8 * W25QXX_BUF;
	W25QXX_BUF = W25QXX_BUFFER;
	secpos = WriteAddr / 4096;//扇区地址  
	secoff = WriteAddr % 4096;//在扇区内的偏移
	secremain = 4096 - secoff;//扇区剩余空间大小   
	//printf("ad:%X,nb:%X\r\n",WriteAddr,NumByteToWrite);//测试用
	if (NumByteToWrite <= secremain)secremain = NumByteToWrite;//不大于4096个字节
	while (1)
	{
		bsp_W25QXX_Read(SPIx, sel, W25QXX_BUF, secpos * 4096, 4096);//读出整个扇区的内容
		for (i = 0; i < secremain; i++)//校验数据
		{
			if (W25QXX_BUF[secoff + i] != 0XFF)break;//需要擦除  	  
		}
		if (i < secremain)//需要擦除
		{
			bsp_W25QXX_Erase_Sector(SPIx, sel, secpos);//擦除这个扇区
			for (i = 0; i < secremain; i++)	   //复制
			{
				W25QXX_BUF[i + secoff] = pBuffer[i];
			}
			bsp_W25QXX_Write_NoCheck(SPIx, sel, W25QXX_BUF, secpos * 4096, 4096);//写入整个扇区  
			//if (bsp_W25QXX_CmpData(SPIx, sel, W25QXX_BUF, secpos * 4096, 4096))
			//{
			//	printf("\r\nWrite Error!\r\n");
			//	break;
			//}
		}
		else
		{
			bsp_W25QXX_Write_NoCheck(SPIx, sel, pBuffer, WriteAddr, secremain);//写已经擦除了的,直接写入扇区剩余区间. 	
			//if (bsp_W25QXX_CmpData(SPIx, sel, pBuffer, WriteAddr, secremain))
			//{
			//	printf("\r\nWrite Error!\r\n");
			//	break;
			//}
		}
					   
		if (NumByteToWrite == secremain)break;//写入结束了
		else//写入未结束
		{
			secpos++;//扇区地址增1
			secoff = 0;//偏移位置为0 	 

			pBuffer += secremain;  //指针偏移
			WriteAddr += secremain;//写地址偏移	   
			NumByteToWrite -= secremain;				//字节数递减
			if (NumByteToWrite > 4096)secremain = 4096;	//下一个扇区还是写不完
			else secremain = NumByteToWrite;			//下一个扇区可以写完了
		}
	};
}
//擦除整个芯片		  
//等待时间超长...
//W25Q32 7-15秒，W25Q128 25-40秒 
void bsp_W25QXX_Erase_Chip(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 
	W25QXX_Wait_Busy(SPIx, sel);
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_ChipErase);        //发送片擦除命令  
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
	W25QXX_Wait_Busy(SPIx, sel);   				   //等待芯片擦除结束
}
//擦除一个扇区 4K Byte
//Sector_Addr:扇区地址 根据实际容量设置
//擦除一个扇区的最少时间:30ms
void bsp_W25QXX_Erase_Sector(SPI_TypeDef* SPIx, u8 sel, u16 Sector_Addr)
{
	u32 addr_tmp;
	//监视falsh擦除情况,测试用   
	//printf("fe:%x\r\n", Sector_Addr);
	addr_tmp = 4096 * Sector_Addr;
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 	 
	W25QXX_Wait_Busy(SPIx, sel);
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_SectorErase);      //发送扇区擦除指令 
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 16));  //发送24bit地址    
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)addr_tmp);
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
	W25QXX_Wait_Busy(SPIx, sel);   				   //等待擦除完成
}

//擦除一个区块 64K Byte
//Block_Addr:区块地址 根据实际容量设置
//擦除一个区块的最少时间:150ms
void bsp_W25QXX_Erase_Block(SPI_TypeDef* SPIx, u8 sel, u16 Block_Addr)
{
	u32 addr_tmp;
	//监视falsh擦除情况,测试用   
	//printf("fe:%x\r\n", Block_Addr);
	addr_tmp = 4096 * 16 * Block_Addr;
	W25QXX_Write_Enable(SPIx, sel);                  //SET WEL 	 
	W25QXX_Wait_Busy(SPIx, sel);
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_BlockErase);      //发送区块擦除指令 
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 16));  //发送24bit地址    
	bsp_SPI_RW_Byte(SPIx, (u8)((addr_tmp) >> 8));
	bsp_SPI_RW_Byte(SPIx, (u8)addr_tmp);
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
	W25QXX_Wait_Busy(SPIx, sel);   				   //等待擦除完成
}

//等待空闲
void W25QXX_Wait_Busy(SPI_TypeDef* SPIx, u8 sel)
{
	while ((W25QXX_ReadSR(SPIx, sel) & 0x01) == 0x01);   // 等待BUSY位清空
}
//进入掉电模式
void W25QXX_PowerDown(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_PowerDown);        //发送掉电命令  
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
	bsp_DelayUS(3);                               //等待TPD  
}
//唤醒
void W25QXX_WAKEUP(SPI_TypeDef* SPIx, u8 sel)
{
	W25QXX_CS(sel, ENABLE);                          //使能器件   
	bsp_SPI_RW_Byte(SPIx, W25X_ReleasePowerDown);   //  send W25X_PowerDown command 0xAB    
	W25QXX_CS(sel, DISABLE);                          //取消片选     	      
	bsp_DelayUS(3);                               //等待TRES1
}
//
///*
//*********************************************************************************************************
//*	函 数 名: sf_ReadInfo
//*	功能说明: 读取器件ID,并填充器件参数
//*	形    参:  无
//*	返 回 值: 无
//*********************************************************************************************************
//*/
//void sf_ReadInfo(void)
//{
//	/* 自动识别串行Flash型号 */
//	{
//		W25QXX_INFO.ChipID = bsp_W25QXX_ReadID();	/* 芯片ID */
//
//		switch (W25QXX_INFO.ChipID)
//		{
//		case SST25VF016B_ID:
//			strcpy(W25QXX_INFO.ChipName, "SST25VF016B");
//			W25QXX_INFO.TotalSize = 2 * 1024 * 1024;	/* 总容量 = 2M */
//			W25QXX_INFO.PageSize = 4 * 1024;			/* 页面大小 = 4K */
//			break;
//
//		case MX25L1606E_ID:
//			strcpy(g_tSF.ChipName, "MX25L1606E");
//			W25QXX_INFO.TotalSize = 2 * 1024 * 1024;	/* 总容量 = 2M */
//			W25QXX_INFO.PageSize = 4 * 1024;			/* 页面大小 = 4K */
//			break;
//
//		case W25Q64BV_ID:
//			strcpy(W25QXX_INFO.ChipName, "W25Q64BV");
//			W25QXX_INFO.TotalSize = 8 * 1024 * 1024;	/* 总容量 = 8M */
//			W25QXX_INFO.PageSize = 4 * 1024;			/* 页面大小 = 4K */
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

