/*
 ******************************************************************************
 * @file           : BOOTLOADER_interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : BOOTLOADER HEADER FILE
 ******************************************************************************
*/

#ifndef BOOTLOADER_BOOTLOADER_INTERFACE_H_
#define BOOTLOADER_BOOTLOADER_INTERFACE_H_


/********************** include part ******************************/
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "Bootloader_private.h"
#include "Bootloader_config.h"
#include "../MACL/USART/USART_interface.h"
#include "../MACL/CRC/CRC_interface.h"
#include "../MACL/FLASH/FLASH_interface.h"
/*************************** MACRO ****************************/

#define HOST_COMMAND_MAX_SIZE 				 200
#define CMD_NUMBER						     8

#define FLASH_MAX_SECTORS_NUMBER             8
#define MASS_ERASE_TOT_SECTORS				 0XFF

#define SECTOR_NUM0                          0
#define SECTOR_NUM1                          1
#define SECTOR_NUM2                          2
#define SECTOR_NUM3                          3
#define SECTOR_NUM4                          4
#define SECTOR_NUM5                          5
#define SECTOR_NUM6                          6
#define SECTOR_NUM7                          7

#define STM32F401CC_SRAM1_SIZE				(64*1024)
#define STM32F401CC_FLASH_SIZE				(256*1024)
#define STM32F401CC_SYS_MEM_SIZE			(30*1024)

#define CBL_GET_VER_CMD         			0X10
#define CBL_GET_HELP_CMD        			0X11
#define CBL_GET_CID_CMD         			0X12
#define CBL_GET_RDP_STATUS_CMD  			0X13
#define CBL_JUMP_TO_ADDR_CMD     			0X14
#define CBL_FLASH_ERASE_CMD 				0X15
#define CBL_MEM_WRITE_CMD       			0X16
#define CBL_EN_R_W_PROTECT_CMD  			0X17


#define BL_VENDOR_ID			100
#define BL_SW_MEJOR_VERSION		1
#define BL_SW_MINOR_VERSION		0
#define BL_SW_PATCH_VERSION		0

#define CRC_TYPE_SIZE			4

#define CBL_SEND_NACK		   0XAB
#define CBL_SEND_ACK		   0XCD

#define ADDRESS_VALID		   1
#define ADDRESS_UNVALID		   0

#define FLASH_WRITE_SUCCESSE   1
#define FLASH_WRITE_FAILE      0

#define level_check_valid  1
#define level_check_unvalid  0
/*************************** MACRO ****************************/

/********************* user data type *****************************/

/********************* user data type *****************************/

/*********************FUNCTION DECLERATION ************************/


/*********************FUNCTION DECLERATION ************************/
STD_RETURN_TYPES BL_USART_FEATCH_HOST_COMMAND(void);

#endif /* BOOTLOADER_BOOTLOADER_INTERFACE_H_ */
