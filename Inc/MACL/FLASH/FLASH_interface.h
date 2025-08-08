/*
 ******************************************************************************
 * @file           : FLASH_interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : FLASH HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_FLASH_FLASH_INTERFACE_H_
#define MACL_FLASH_FLASH_INTERFACE_H_

/************************ INCLUDE PART ***************************/
#include "../STD_TYPES.h"
#include "../MATH.h"
#include "../Inc/MACL/RCC/RCC_interface.h"
#include "FLASH_config.h"
#include "FLASH_private.h"
/************************ INCLUDE PART ***************************/

/**************************** MACROS *****************************/
#define FLASH_OTP_KEY1    0X08192A3B
#define FLASH_OTP_KEY2    0X4C5D6E7F

#define FLASH_KAY1         0x45670123
#define FLASH_KAY2         0xCDEF89AB

#define FLASH_PROTECTION_ENABLE   0
#define FLASH_PROTECTION_DISABLE  1
#define RESET  0
#define SET    1

#define FLASH_CFG_START         1
#define FLASH_LOCKED            1

#define EOP_flag_bit			0
#define OPERR_flag_bit			1
#define WRPERR_flag_bit			4
#define PGAERR_flag_bit			5
#define PGPERR_flag_bit			6
#define PGSERR_flag_bit			7
#define RDERR_flag_bit			8
#define BSY_flag_bit			16

#define FLASH_LEVE0_CFG		    0XAA
#define FLASH_LEVE1_CFG			0XDD
#define FLASH_LEVE2_CFG			0XCC

#define SECTOR_NUM1				0
#define SECTOR_NUM2				1
#define SECTOR_NUM3				2
#define SECTOR_NUM4				3
#define SECTOR_NUM5				4
#define SECTOR_NUM6				5
#define SECTOR_NUM7				6
#define SECTOR_NUM8				7


#define FLASH_TYPEERASE_SECTOR  0
#define FLASH_TYPEERASE_MASS    1

#define FLASH_VOLTAGE_RANGE1    0  /* FROM 1.8V TO 2.1V */
#define FLASH_VOLTAGE_RANGE2    1  /* FROM 2.1V TO 2.7V */
#define FLASH_VOLTAGE_RANGE3    2  /* FROM 2.7V TO 3.6V */
#define FLASH_VOLTAGE_RANGE4    3  /* FROM 2.7V TO 3.6V + EXTRNAL VOLTAGE */

#define FLASH_BANK_NUM1         1

#define FLASH_ERASE_SUCCESS     1
#define FLASH_ERASE_SUCCESS     0

/* AVOID THIS LEVEL*/
/**************************** MACROS *****************************/

/************************ MACROS FUNCTION ************************/

/************************ MACROS FUNCTION ************************/

/************************* USER DATA TYPES *************************/
typedef struct
{
	uint32 erase_type; 			/* mass or sector erase*/
	uint32 bank_num;   			/* number of bank you want to erase*/
	uint32 sector_num; 			/* sector number you want to erase*/
	uint32 tot_sector_erase;	/* total number of sectors you want to erase*/
	uint32 voltage_range;		/* value of voltage you apply to MCU*/

}Flash_Erase_cfg;
/************************* USER DATA TYPES *************************/

/*********************** FUNCTION DECLERATION ************************/
STD_RETURN_TYPES FLASH_CONFIG(void);
STD_RETURN_TYPES FLASH_OB_UNLOCK(void);
STD_RETURN_TYPES FLASH_OB_LOCK(void);
STD_RETURN_TYPES FLASH_UNLOCK(void);
STD_RETURN_TYPES FLASH_LOCK(void);
uint8 FLASH_READ_PROTECTION_LEVEL(void);

STD_RETURN_TYPES FLASH_GET_FLAG_STATUS(uint16 flag_bit_num);
STD_RETURN_TYPES FLASH_WRITE_PROTECTION_CFG(uint8 sector_number);
STD_RETURN_TYPES FLASH_ERAESE(Flash_Erase_cfg *ptr, uint32 *sector_erase_state);
STD_RETURN_TYPES FLASH_WRITE_BYTE(uint32 *address , uint8 data );
STD_RETURN_TYPES FLASH_LEVEL_SELECT_FUN(uint32 level);
/* RETURN 0XFFFFFFFF IF THE ERASE IS DONE SUCCESSUFFLY*/
/*********************** FUNCTION DECLERATION ************************/
#endif /* MACL_FLASH_FLASH_INTERFACE_H_ */
