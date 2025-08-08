/*
 ******************************************************************************
 * @file           : FLASH_PROGRAM.C
 * @author         : SARA SAAD MAHMOUD
 * @brief          : FLASH SOURCE FILE
 ******************************************************************************
*/

/**************************** INCLUDE PART ****************************/
#include "../Inc/MACL/FLASH/FLASH_interface.h"
/**************************** INCLUDE PART ****************************/

/********************** STATIC FUNCTION DECLERATION ***********************/
static void FLASH_APPLY_OPTION_CHANGES(void);
/********************** STATIC FUNCTION DECLERATION ***********************/

/*************************** FUNCTION DEFINITION ***************************/
STD_RETURN_TYPES FLASH_CONFIG(void)
{
	STD_RETURN_TYPES RET  =E_OK;


   if(RET == E_NOK)
   {

   }
   else
   {
	   RET = FLASH_OB_UNLOCK();

	   while(FLASH_GET_FLAG_STATUS(BSY_flag_bit) != RESET);
	   RET = E_OK;

		/* TIRGGER FLASH CONFIGURATION TO EECUTE*/
		FLASH_REG ->FLASH_OPTCR.OPTSTRT = FLASH_CFG_START;

		RET = FLASH_WRITE_PROTECTION_CFG(SECTOR_NUM2);

		/* WAIT BSP BIT TO BY CLEARED BE HARDWARE*/
		while(FLASH_GET_FLAG_STATUS(BSY_flag_bit) != RESET);


		/* LOCK THE FLASH */
		RET = FLASH_OB_LOCK();
   }

	return(RET);
}
STD_RETURN_TYPES FLASH_OB_UNLOCK(void)
{
	STD_RETURN_TYPES RET  =E_OK;

	if(FLASH_REG->FLASH_OPTCR.OPTLOCK == SET)
	{
		FLASH_REG->FLASH_OPTKEYR = FLASH_OTP_KEY1;
		FLASH_REG->FLASH_OPTKEYR = FLASH_OTP_KEY2;
	}
	else
	{
		RET = E_NOK;
	}

	return(RET);
}

STD_RETURN_TYPES FLASH_UNLOCK(void)
{
	STD_RETURN_TYPES RET  =E_OK;

	if(FLASH_REG->FLASH_CR.LOCK == SET)
	{
		FLASH_REG->FLASH_KEYR = FLASH_KAY1;
		FLASH_REG->FLASH_KEYR = FLASH_KAY2;
	}
	else
	{
		RET = E_NOK;
	}

	return(RET);
}

STD_RETURN_TYPES FLASH_LOCK(void)
{
	STD_RETURN_TYPES RET  =E_OK;

	FLASH_REG->FLASH_CR.LOCK = SET;

	return(RET);
}

STD_RETURN_TYPES FLASH_OB_LOCK(void)
{
	STD_RETURN_TYPES RET  =E_OK;

	FLASH_REG->FLASH_OPTCR.OPTLOCK = FLASH_LOCKED;

	return(RET);
}
STD_RETURN_TYPES FLASH_GET_FLAG_STATUS(uint16 flag_bit_num)
{
	STD_RETURN_TYPES RET = E_OK;

	switch( flag_bit_num)
	{
		case EOP_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.EOP);
			break;

		case OPERR_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.OPERR);
			break;

		case WRPERR_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.WRPERR);
			break;

		case PGAERR_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.PGAERR);
			break;

		case PGPERR_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.PGPERR);
			break;

		case PGSERR_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.PGSERR);
			break;

		case RDERR_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.RDERR);
			break;

		case BSY_flag_bit:
			RET = (FLASH_REG->FLASH_SR.FLASH_STRUCT.BSY);
			break;

		default:
			RET = 2;
			break;

	}
	return(RET);
}

STD_RETURN_TYPES FLASH_WRITE_PROTECTION_CFG(uint8 sector_number)
{
	STD_RETURN_TYPES RET = E_OK;

	switch(sector_number)
	{
		case SECTOR_NUM1:
			FLASH_REG->FLASH_OPTCR.nWRP1 = FLASH_PROTECTION_ENABLE;
			break;
		case SECTOR_NUM2:
			FLASH_REG->FLASH_OPTCR.nWRP2 = FLASH_PROTECTION_ENABLE;
			break;
		case SECTOR_NUM3:
			FLASH_REG->FLASH_OPTCR.nWRP3 = FLASH_PROTECTION_ENABLE;
			break;
		case SECTOR_NUM4:
			FLASH_REG->FLASH_OPTCR.nWRP4 = FLASH_PROTECTION_ENABLE;
			break;
		case SECTOR_NUM5:
			FLASH_REG->FLASH_OPTCR.nWRP5 = FLASH_PROTECTION_ENABLE;
			break;
		case SECTOR_NUM6:
			FLASH_REG->FLASH_OPTCR.nWRP6 = FLASH_PROTECTION_ENABLE;
			break;
		case SECTOR_NUM7:
			FLASH_REG->FLASH_OPTCR.nWRP7 = FLASH_PROTECTION_ENABLE;
			break;
		case SECTOR_NUM8:
			FLASH_REG->FLASH_OPTCR.nWRP8 = FLASH_PROTECTION_ENABLE;
			break;
		default:
			RET = E_NOK;
			break;
	}
	return(RET);
}

STD_RETURN_TYPES FLASH_ERAESE(Flash_Erase_cfg *ptr, uint32 *sector_erase_state)
{
	STD_RETURN_TYPES RET = E_OK;

	RET = FLASH_UNLOCK();
	if (RET != E_OK)
		return RET;

	FLASH_REG->FLASH_CR.PSIZE = ptr->voltage_range;

	/* CHECK ERASE TYPES */
	if (ptr->erase_type == FLASH_TYPEERASE_MASS)
	{
		FLASH_REG->FLASH_CR.SER  = RESET;
		FLASH_REG->FLASH_CR.MER  = SET;
		FLASH_REG->FLASH_CR.STRT = SET;

		while (FLASH_GET_FLAG_STATUS(BSY_flag_bit) != RESET);

		FLASH_REG->FLASH_CR.MER = RESET;
	}
	else
	{
		FLASH_REG->FLASH_CR.SER = SET;
		FLASH_REG->FLASH_CR.SNB = ptr->sector_num;
		FLASH_REG->FLASH_CR.MER = RESET;
		FLASH_REG->FLASH_CR.STRT = SET;

		while (FLASH_GET_FLAG_STATUS(BSY_flag_bit) != RESET);

		FLASH_REG->FLASH_CR.SER = RESET;
	}

	*sector_erase_state = (!FLASH_REG ->FLASH_SR.FLASH_STRUCT.OPERR) &&
			              (!FLASH_REG ->FLASH_SR.FLASH_STRUCT.WRPERR)&&
					      (!FLASH_REG ->FLASH_SR.FLASH_STRUCT.PGAERR)&&
					      (!FLASH_REG ->FLASH_SR.FLASH_STRUCT.PGPERR)&&
					      (!FLASH_REG ->FLASH_SR.FLASH_STRUCT.PGSERR);

	FLASH_REG->FLASH_SR.FLASH_SR_REG |= (1 << OPERR_flag_bit)  |
	                                     (1 << WRPERR_flag_bit) |
	                                     (1 << PGAERR_flag_bit) |
	                                     (1 << PGPERR_flag_bit) |
	                                     (1 << PGSERR_flag_bit);
	FLASH_LOCK();

	return RET;
}

STD_RETURN_TYPES FLASH_WRITE_BYTE(uint32 *address , uint8 data )
{
	STD_RETURN_TYPES RET = E_OK;

	RET = FLASH_UNLOCK();
	while((FLASH_GET_FLAG_STATUS(BSY_flag_bit)) != RESET);

	FLASH_REG ->FLASH_CR.PSIZE = RESET;
	FLASH_REG ->FLASH_CR.PG = SET;

	*(volatile uint8*)address = data;

	while((FLASH_GET_FLAG_STATUS(BSY_flag_bit)) != RESET);

	FLASH_REG->FLASH_CR.PG = RESET;

	FLASH_REG->FLASH_SR.FLASH_SR_REG |= (1 << OPERR_flag_bit)  |
	                                     (1 << WRPERR_flag_bit) |
	                                     (1 << PGAERR_flag_bit) |
	                                     (1 << PGPERR_flag_bit) |
	                                     (1 << PGSERR_flag_bit);

	RET |= FLASH_LOCK();

	return(RET);
}

uint8 FLASH_READ_PROTECTION_LEVEL(void)
{
	uint8 protection_level =0;

	protection_level = (FLASH_REG ->FLASH_OPTCR.RDP);

	return(protection_level);
}
/*************************** FUNCTION DEFINITION ***************************/

/********************** STATIC FUNCTION DEFINITION ***********************/
STD_RETURN_TYPES FLASH_LEVEL_SELECT_FUN(uint32 level)
{
	STD_RETURN_TYPES RET = E_OK;

	RET = FLASH_UNLOCK();
	if (RET == E_OK)
	{
		switch(level)
			{
			case FLASH_LEVE0_CFG:
				FLASH_REG ->FLASH_OPTCR.RDP = FLASH_LEVE0_CFG;
				FLASH_APPLY_OPTION_CHANGES();
				break;
			case FLASH_LEVE1_CFG:
				FLASH_REG ->FLASH_OPTCR.RDP = FLASH_LEVE1_CFG;
				FLASH_APPLY_OPTION_CHANGES();
				break;
			case FLASH_LEVE2_CFG:
				FLASH_REG ->FLASH_OPTCR.RDP = FLASH_LEVE2_CFG;
				FLASH_APPLY_OPTION_CHANGES();
				break;
			default:
				RET = E_NOK;
				break;
			}
	}
	else
	{

	}



	RET = FLASH_LOCK();

	return(RET);
}

/********************** STATIC FUNCTION DEFINITION ***********************/
static void FLASH_APPLY_OPTION_CHANGES(void)
{
    FLASH_REG->FLASH_OPTCR.OPTSTRT = FLASH_CFG_START;

    while (FLASH_GET_FLAG_STATUS(BSY_flag_bit) == SET);
}
