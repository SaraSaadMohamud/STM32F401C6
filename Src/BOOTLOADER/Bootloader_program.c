/*
 ******************************************************************************
 * @file           : Bootloader_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : Bootloader program body
 ******************************************************************************
*/

/********************** INCLUDE PART **************************/
#include "../Inc/BOOTLOADER/Bootloader_interface.h"
/********************** INCLUDE PART **************************/

/********************* function Decleration ********************/

 STD_RETURN_TYPES BL_Print_Message(char *formate, ...);

 CRC_statue BL_CRC_MODIFY(uint8 *BL_BUFFER,uint32 data_len , uint32 HOST_CRC);

 static void BL_SEND_ACK(uint8 REPLY_MES);
 static void BL_SEND_NACK(void);
 static void BL_GET_PROTECTION_LEVEL(uint8 *RPE_LEVEL);

 static STD_RETURN_TYPES CBL_GET_VER_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_GET_CID_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_GET_HELP_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_GET_RDP_STATUS_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_JUMP_TO_ADDR_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_FLASH_ERASE_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_MEM_WRITE_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_CHANGE_READ_PROTECT_LEVEL_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_MEM_READ_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_READ_SECTOR_STATUS_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_OTP_READ_CMD_FUN(void);
 static STD_RETURN_TYPES CBL_DIS_R_W_PROTECT_CMD_FUN(void);


 static uint8 HOST_JUMP_ADD_VERFACATION(uint32 ADD);
 static STD_RETURN_TYPES PERFORM_FLASH_ERASE(uint8 SECTOR_NUMBER , uint8 NUM_OF_SECTORS);
 static uint8 FLASH_MEMORY_WRITE_PAYLOADING(uint8 *Host_Payload, uint32 *Host_Start_Address, uint32 Payload_Len);
 static STD_RETURN_TYPES CHANGE_READ_PROTECTION_LEVEL(uint32 protection_level);

/********************* function Decleration ********************/

/********************* Global variable Intialization ***********************/
static char BL_HOST_BUFFER[HOST_COMMAND_MAX_SIZE ];

char BL_SEND_CMD[CMD_NUMBER] =
 {
		 CBL_GET_VER_CMD,
		 CBL_GET_HELP_CMD,
		 CBL_GET_CID_CMD,
		 CBL_GET_RDP_STATUS_CMD,
		 CBL_JUMP_TO_ADDR_CMD,
		 CBL_FLASH_ERASE_CMD,
		 CBL_MEM_WRITE_CMD,
		 CBL_EN_R_W_PROTECT_CMD,
 };
/********************* Global variable Intialization ***********************/

/***************************** Interfaces Definition  ***********************/

/***************************** Interfaces Definition  ***********************/

/*********************** Static Function Definition ************************/
 STD_RETURN_TYPES BL_USART_FEATCH_HOST_COMMAND(void)
 {
	 STD_RETURN_TYPES RET= E_OK;
	 uint8 Data_Length[4];
	 uint8 cmd[4] ;

	 memset(BL_HOST_BUFFER,0,HOST_COMMAND_MAX_SIZE);
	 memset(Data_Length,0,4);

	 RET = USART_SEND_STRING(USART1_ENABLE, "BOOTLOADER START\r\n");
	 RET = USART_RECIVE_STRING(USART1_ENABLE,Data_Length);

	 if (RET == E_NOK)
	 {

	 }
	 else
	 {
		 BL_HOST_BUFFER[0] = atoi(Data_Length);
		 for(int i=1 ; i<=BL_HOST_BUFFER[0] ; i++)
		 {
			 memset(cmd,0,4);
			 RET = USART_RECIVE_STRING(USART1_ENABLE,cmd);
			 BL_HOST_BUFFER[i] = (uint8_t)strtol(cmd, NULL, 16);
		 }
		 if(RET == E_NOK)
		 {

		 }
		 else
		 {

			 switch(BL_HOST_BUFFER[1])
			 {
				 case CBL_GET_VER_CMD:
					 	 RET =BL_Print_Message("\r\nRead the bootloader version from MCU.\r\n");
					 RET = CBL_GET_VER_CMD_FUN();
					 break;

				 case CBL_GET_CID_CMD:
					#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
						 //RET =BL_Print_Message("Read the MCU chip identification Number.\r\n");
					#endif
					RET = CBL_GET_CID_CMD_FUN();
					break;

				 case CBL_GET_HELP_CMD:
					#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
						 RET =BL_Print_Message("Read the command supported by bootloader.\r\n");
					#endif
					RET = CBL_GET_HELP_CMD_FUN();
					break;

				 case CBL_GET_RDP_STATUS_CMD:
					#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
						 RET =BL_Print_Message("Read the flash protection level.\r\n");
					#endif
					RET = CBL_GET_RDP_STATUS_CMD_FUN();
					break;

				 case CBL_JUMP_TO_ADDR_CMD:
					#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
						 RET =BL_Print_Message("JUMP TO HOST ADDRESS.\r\n");
					#endif
					RET = CBL_JUMP_TO_ADDR_CMD_FUN();
					break;

				 case CBL_FLASH_ERASE_CMD:
					#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
						 RET =BL_Print_Message("Mess erase or Sector erase for the User Flag.\r\n");
					#endif
					RET = CBL_FLASH_ERASE_CMD_FUN();
					break;

				 case CBL_MEM_WRITE_CMD :
					#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
						 RET =BL_Print_Message("WRITE DATA INTO DIFFERENT MEMORIES OF MCU.\r\n");
					#endif
					RET = CBL_MEM_WRITE_CMD_FUN();
					break;

				 case CBL_EN_R_W_PROTECT_CMD :
					#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
						 RET =BL_Print_Message("CHANGE THE READ PROTECTION LEVEL.\r\n");
					#endif
					RET = CBL_CHANGE_READ_PROTECT_LEVEL_CMD_FUN();
				   break;

				default:
					RET = BL_Print_Message("INVALID CMD\r\n");
					RET = E_NOK;
					break;
			 }
		 }
	 }
	 return(RET);
 }
/*********************** Static Function Definition ************************/

 static STD_RETURN_TYPES CBL_GET_VER_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK; //55
	 uint8 BL_Version[4] = {BL_VENDOR_ID, BL_SW_MEJOR_VERSION, BL_SW_MINOR_VERSION, BL_SW_PATCH_VERSION};
	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));

	 /*if (CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {*/
		 BL_SEND_ACK(4);
		 RET = BL_Print_Message("Bootloader Vendor IDE: %d\r\n",BL_Version[0]);
		 RET = BL_Print_Message("Bootloader Vergion %d . %d . %d\r\n",BL_Version[1],BL_Version[2],BL_Version[3]);
	 /*}
	 else
	 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("CRC Fail!!\r\n");
#endif
		 BL_SEND_NACK();
	 }*/

	 return(RET);
 }

 /*************************************************************************************************/

 static STD_RETURN_TYPES CBL_GET_HELP_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK;

	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));

    /* if (CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {
		 BL_SEND_ACK(CMD_NUMBER);*/
		 for(int i=0 ; i< CMD_NUMBER; i++)
		 {

		     RET =  BL_Print_Message("0X%X  ",BL_SEND_CMD[i]);
		 }/*
	 }
	 else
	 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("CRC Fail!!\r\n");
#endif
		 BL_SEND_NACK();
	 }*/

	 return(RET);
 }
 /*************************************************************************************************/
 static STD_RETURN_TYPES CBL_GET_CID_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK;
	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));

	 uint32 MCU_ID = *DBGMCU_IDCODE_ADD;
	 uint16  ID= (uint16) (MCU_ID & 0x00000FFF);

     if (CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {
		 BL_SEND_ACK(2);
	  	 RET =  BL_Print_Message("%X\r\n",ID);
		 /*RET =  BL_Print_Message("0X423\r\n");*/
	 }
	 else
	 {
		 BL_SEND_NACK();
	 }

	 return(RET);
 }
 /*************************************************************************************************/
 static STD_RETURN_TYPES CBL_JUMP_TO_ADDR_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK;
	 uint32 Host_ADD = 0;
	 uint8 Address_state = ADDRESS_UNVALID	;
	 void (*jAdd)(void) = NULL;

	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));


    if (CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {
		 BL_SEND_ACK(1);
		  Host_ADD = *( (uint32*)(&BL_HOST_BUFFER[2]));
		  RET = HOST_JUMP_ADD_VERFACATION(Host_ADD);

		  if(Address_state == ADDRESS_VALID)
		  {

#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("Valid Address!!\r\n");
#endif
	 	 	 /*BL_Print_Message("Jump to : 0x%X \r\n",Host_ADD);*/
	 	 	 jAdd =(void (*) (void))(Host_ADD);

	 	 	 jAdd();
		  }
		  else
		  {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("unValid Address!!\r\n");
#endif
		  }

	  }
	 else
	 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("CRC  Vervacation Fail!!\r\n");
#endif
		 BL_SEND_NACK();
	 }
	 return(RET);
 }

 /*************************************************************************************************/
static STD_RETURN_TYPES CBL_FLASH_ERASE_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK;

	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));

	 uint8 Sec_num = (uint8)BL_HOST_BUFFER[2];
	 uint8 Tot_sectors = (uint8)BL_HOST_BUFFER[3];

     /*if (CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {
		 BL_SEND_ACK(1);*/
		 RET = PERFORM_FLASH_ERASE(Sec_num,Tot_sectors);

		 if(RET == E_OK)
		 {
			RET =  BL_Print_Message("FLASH ERASE DONE SUCCESSFULLY!!\r\n");
		 }
		 else
		 {
			RET =  BL_Print_Message("FLASH ERASE FAILED!!\r\n");
		 }
	/* }
	 else
	 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("CRC  Vervication Fail!!\r\n");
#endif
		 BL_SEND_NACK();
	 }
*/
	 return(RET);
 }

 /*************************************************************************************************/
 static STD_RETURN_TYPES CBL_MEM_WRITE_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK;
	 uint8 Address_Verification = ADDRESS_UNVALID;
	 uint8 FLASH_WRITE_STATE = FLASH_WRITE_FAILE;

	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));

	 uint32 HOST_ADD = 0;
	 uint8 Payload_len = 0;

     if (CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {
		 BL_SEND_ACK(1);
		 HOST_ADD = *((uint32*)(&BL_HOST_BUFFER[2]));
		 Payload_len = BL_HOST_BUFFER[5];

		 Address_Verification =  HOST_JUMP_ADD_VERFACATION(HOST_ADD);
		 if(Address_Verification == ADDRESS_VALID)
		 {
			 RET = FLASH_MEMORY_WRITE_PAYLOADING((uint8 *)&(BL_HOST_BUFFER[7]),HOST_ADD,Payload_len);
			 if(FLASH_WRITE_SUCCESSE == FLASH_WRITE_STATE)
			 {
				 BL_Print_Message("FLASH PAYLOAD WRITE WAS SUCCESSED!!\r\n");
			 }
			 else
			 {
				 BL_Print_Message("FLASH PAYLOAD WRITE WAS FAILED!!\r\n");
			 }
		 }
		 else
		 {
			 BL_Print_Message("INVALID MEMORY ADDRESS!!\r\n");
		 }
	 }
	 else
	 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("CRC  Vervication Fail!!\r\n");
#endif
		 BL_SEND_NACK();
	 }

	 return(RET);
 }
 /*************************************************************************************************/

 static STD_RETURN_TYPES CBL_GET_RDP_STATUS_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK;
	 uint8 protection_level = FLASH_WRITE_FAILE;
     uint8 RDP_STATE =  level_check_unvalid;

	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));

     if(CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {
		 BL_SEND_ACK(1);

		 BL_GET_PROTECTION_LEVEL(&protection_level);

		 RET =BL_Print_Message("protection level: %\r\n",protection_level);
	 }
	 else
	 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("CRC  Vervication Fail!!\r\n");
#endif
		 BL_SEND_NACK();
	 }

	 return(RET);
 }
 /*************************************************************************************************/
 static STD_RETURN_TYPES CBL_CHANGE_READ_PROTECT_LEVEL_CMD_FUN(void)
 {
	 STD_RETURN_TYPES RET = E_OK;

	 uint16 HOST_CMD_PACKET_LEN = BL_HOST_BUFFER[0] + 1;
	 uint32 HOST_CRC = *((uint32 *)(BL_HOST_BUFFER + HOST_CMD_PACKET_LEN- CRC_TYPE_SIZE));
	 uint32 Protection_level = BL_HOST_BUFFER[2];

     if(CRC_VERFACATION_PASS == BL_CRC_MODIFY((uint8 *)(&BL_HOST_BUFFER[0]),HOST_CMD_PACKET_LEN-4,HOST_CRC))
	 {
		 BL_SEND_ACK(1);
		 if(Protection_level == 2)
		 {
			 BL_Print_Message("Can't change level protection to level2.. \r\n");
		 }
		 else
		 {
			 if(Protection_level == 0)
			 {
				 Protection_level = 0xAA;
				 RET = CHANGE_READ_PROTECTION_LEVEL(Protection_level);
				 if(RET == E_NOK)
				 {
					 BL_Print_Message("change faild\r\n");
				 }
				 else
				 {
					 BL_Print_Message("change done successuffly\r\n");
				 }
			 }
			 else if (Protection_level == 1)
			 {
				 Protection_level = 0XDD;
				 RET = CHANGE_READ_PROTECTION_LEVEL(Protection_level);
				 if(RET == E_NOK)
				 {
					 BL_Print_Message("change faild\r\n");
				 }
				 else
				 {
					 BL_Print_Message("change done successuffly\r\n");
				 }
			 }
			 else
			 {
				 BL_Print_Message("Invalid Level\r\n");
			 }
		 }
	 }
	 else
	 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE

#endif
		 BL_SEND_NACK();
	 }
	 return(RET);
 }

 /*************************************************************************************************/
 CRC_statue BL_CRC_MODIFY(uint8 *BL_BUFFER,uint32 data_len , uint32 HOST_CRC)
{
	 CRC_statue CRC_status = CRC_VERFACATION_PASS;
	 uint32 CRC_CALCULATED_VALUE =0 ;
	 uint32 data_buff = 0;

	 CRC_status = CRC_INIT();
	 CRC_status|= CRC_RESET();

	    for (int i = 0; i < data_len; i++)
	    {
	    	data_buff  = (uint32)BL_BUFFER[i];
	    	CRC_status =  CRC_CALCULAT(&CRC_CALCULATED_VALUE,1,&data_buff);

	       /* ( (volatile uint8*)(&(CRC_REG->CRC_DR)) ) = BL_BUFFER[i]; */
	    }
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("HOST CRC = %X\r\n",HOST_CRC);
#endif
	    CRC_status = CRC_RESET();

	    /*CRC_CALCULATED_VALUE = CRC_REG->CRC_DR;*/

#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("BL_CRC_ = %X\r\n",CRC_CALCULATED_VALUE);
#endif

	  if(CRC_CALCULATED_VALUE == HOST_CRC)
	  {
		CRC_status= CRC_VERFACATION_PASS;
	  }
	  else
	  {
		  CRC_status = CRC_VERFACATION_FAILD;
	  }

	 return(CRC_status);
 }
 /*******************************************************************************************/
 STD_RETURN_TYPES BL_Print_Message(char *formate, ...)
{
	STD_RETURN_TYPES RET =E_OK;
	char Message[100] = {0};
	if(NULL == formate)
	{
		RET = E_NOK;
	}
	else
	{
		va_list args;
		/* ENABLE ACCESS TO THE VARIABLE ARGUMENTS*/
		va_start(args,formate);
		/* WRITE FORMATTED DATA FROM VARIABLE ARGUMENTS LIST TO STRING*/
		vsprintf(Message,formate,args);
		// TRANSIMMETE DATA TO USART */
#if USART_PERIPHERAL_ENABLE == SERIAL_CONNECTION_FEATURE_ENABLE
		RET = USART_SEND_STRING(USART1_ENABLE ,Message);
#endif
		/* DISABLE ACCESS TO THE VARIABLE ARGUMENTS*/
		va_end(args);
	}
	return(RET);
}

 /*******************************************************************************************/

 static void BL_SEND_ACK(uint8 REPLY_MES)
 {
	 uint8 len = REPLY_MES;

	 USART_SEND_STRING(USART1_ENABLE,"AB");

#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("\r\nRescive ACK from thE Bootloader \r\n");
#endif

	 BL_Print_Message("%d\r\n",REPLY_MES);

 }

 static void BL_SEND_NACK(void)
 {
	 USART_SEND_STRING(USART1_ENABLE,"CD");
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("\r\nRescive NOT ACK from thE Bootloader \r\n");
#endif

 }
/****************************************************************************************************/
 static uint8 HOST_JUMP_ADD_VERFACATION(uint32 ADD)
 {
	uint8 address_state = ADDRESS_UNVALID;

	 if((ADD >= FLASH_STR_ADD) && (ADD <= FLASH_END_ADD))
	 {
		 address_state = ADDRESS_VALID;
	 }
	 else if ((ADD >= SRAM1_STR_ADD) && (ADD <= SRAM1_END_ADD))
	 {
		 address_state = ADDRESS_VALID;
	 }
	 else if ((ADD >= SYSTEM_MEM_STR_ADD) && (ADD <= SYSTEM_MEM_END_ADD))
	 {
		 address_state = ADDRESS_VALID;
	 }
	 else
	 {
		 address_state = ADDRESS_UNVALID;
	 }

	 return(address_state);
 }

 static STD_RETURN_TYPES PERFORM_FLASH_ERASE(uint8 SECTOR_NUMBER , uint8 NUM_OF_SECTORS)
 {
	 STD_RETURN_TYPES RET = E_OK;

	 Flash_Erase_cfg *L_FPTR = NULL;
	 uint8 Remaining_sector = 0;
	 uint32 Flash_Erase_state = 0;

	 if(NUM_OF_SECTORS > FLASH_MAX_SECTORS_NUMBER)
	 {
		 RET = E_NOK;
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("INVALID NUMBER OF SECTORS TO EREASE \r\n");
#endif
	 }
	 else
	 {
		 RET = E_OK;

		 if( (SECTOR_NUMBER <= (FLASH_MAX_SECTORS_NUMBER-1)))
		 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("FLASH SECTOR ERASE START! \r\n");
#endif
			 Remaining_sector = (FLASH_MAX_SECTORS_NUMBER - SECTOR_NUMBER);

			 if(Remaining_sector < NUM_OF_SECTORS)
			 {
				 NUM_OF_SECTORS = Remaining_sector;
			 }
			 else
			 {
				 /*NOTHING*/
			 }

			 L_FPTR ->erase_type       = FLASH_TYPEERASE_SECTOR;
			 L_FPTR ->bank_num         = FLASH_BANK_NUM1 ;
			 L_FPTR ->sector_num 	   = SECTOR_NUMBER;
			 L_FPTR ->tot_sector_erase = NUM_OF_SECTORS;
			 L_FPTR ->voltage_range    = FLASH_VOLTAGE_RANGE3;

			 RET = FLASH_OB_UNLOCK();
			 RET = FLASH_ERAESE(L_FPTR, &Flash_Erase_state);
			 RET = FLASH_OB_LOCK();

			 if(FLASH_ERASE_SUCCESS == Flash_Erase_state)
			 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("FLASH SECTOR ERASE DONE SUCCESSFULLY \r\n");
#endif
				 RET = E_OK;
			 }
			 else
			 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("FLASH SECTOR ERASE FAILED \r\n");
#endif
				 RET = E_NOK;
			 }

		 }
		 else if ((SECTOR_NUMBER == MASS_ERASE_TOT_SECTORS))
		 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("FLASH MASS ERASE START \r\n");
#endif
			 L_FPTR->erase_type		= FLASH_TYPEERASE_MASS;
			 L_FPTR->bank_num 		= FLASH_BANK_NUM1 ;
			 L_FPTR ->voltage_range = FLASH_VOLTAGE_RANGE3;

			 RET = FLASH_OB_UNLOCK();
			 RET = FLASH_ERAESE(L_FPTR, &Flash_Erase_state);
			 RET = FLASH_OB_LOCK();

			 if(FLASH_ERASE_SUCCESS == Flash_Erase_state)
			 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("FLASH MASS ERASE DONE SUCCESSFULLTY \r\n");
#endif
				 RET = E_OK;
			 }
			 else
			 {
#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 BL_Print_Message("FLASH MASS ERASE FAIL \r\n");
#endif
				 RET = E_NOK;
			 }
		 }
		 else
		 {
			 RET = E_NOK;
	#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
		 BL_Print_Message("INVALID SECTORS NUMBER, OUT OF RANGE!.\r\n");
	#endif
		 }

	 }

	 return(RET);
 }

 static uint8 FLASH_MEMORY_WRITE_PAYLOADING(uint8 *Host_Payload, uint32 *Host_Start_Address, uint32 Payload_Len)
 {
	 STD_RETURN_TYPES RET = E_OK;
     uint8 Flash_write_state = FLASH_WRITE_FAILE;
	 RET = FLASH_OB_UNLOCK();

	 if(RET == E_NOK)
	 {
		 Flash_write_state = FLASH_WRITE_FAILE;
	 }
	 else
	 {
		 for(int i=0 ; i<Payload_Len ; i++)
		 {
			 RET = FLASH_WRITE_BYTE((Host_Start_Address+i), Host_Payload[i]);

			 if(RET == E_NOK)
			 {
				 Flash_write_state = FLASH_WRITE_FAILE;
				 BL_Print_Message("FLASH WRITE PROCCESS FAILD!.\r\n");
				 break;
			 }
			 else
			 {
				 Flash_write_state =  FLASH_WRITE_SUCCESSE;
				 /*NOTHING*/
			 }
		 }
	 }

	 if(( Flash_write_state ==  FLASH_WRITE_SUCCESSE) && (RET == E_OK))
	 {
		 RET = FLASH_OB_LOCK();

		 if(RET == E_NOK)
		 {
			 Flash_write_state = FLASH_WRITE_FAILE;
		 }
		 else
		 {
			 Flash_write_state =  FLASH_WRITE_SUCCESSE;
		 }
	 }
	 else
	 {
		 Flash_write_state = FLASH_WRITE_FAILE;
	 }

	 return(Flash_write_state);
 }

 static void BL_GET_PROTECTION_LEVEL(uint8 *RPE_LEVEL)
 {
	 uint8 RDP_LEVEL=0;
	 uint8 state =0;

	 RDP_LEVEL = FLASH_READ_PROTECTION_LEVEL();
	 switch( RDP_LEVEL)
	 {
	 case FLASH_LEVE0_CFG	:
		 *RPE_LEVEL = 0;
		 break;
	 case FLASH_LEVE2_CFG	:
		 *RPE_LEVEL = 2;
		 break;
	 default:
		 *RPE_LEVEL = 1;
		 break;
	 }
 }

 static STD_RETURN_TYPES CHANGE_READ_PROTECTION_LEVEL(uint32 protection_level)
 {
	 STD_RETURN_TYPES RET = E_OK;

	 RET = FLASH_OB_UNLOCK();
	 if(RET == E_NOK)
	 {

	 }
	 else
	 {
		 RET= FLASH_LEVEL_SELECT_FUN(protection_level);

		 if(RET == E_NOK)
		 {
			 RET = FLASH_OB_LOCK();
		 }
		 else
		 {
			 RET = FLASH_OB_LOCK();
		 }

	 }

	 return(RET);
 }
