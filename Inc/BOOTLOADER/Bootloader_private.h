/*
 ******************************************************************************
 * @file           : BOOTLOADER_private.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : BOOTLOADER HEADER FILE
 ******************************************************************************
*/


#ifndef BOOTLOADER_BOOTLOADER_PRIVATE_H_
#define BOOTLOADER_BOOTLOADER_PRIVATE_H_
#include "../MACL/STD_TYPES.h"

#define DBGMCU_IDCODE_ADD       ((volatile uint32*)0xE0042000)


#define FLASH_STR_ADD            0x08000000
#define SRAM1_STR_ADD            0x20000000
#define SYSTEM_MEM_STR_ADD       0x1FFF0000

#define FLASH_END_ADD            0x2000FFFF
#define SRAM1_END_ADD            0x1FFF77FF
#define SYSTEM_MEM_END_ADD       0x0803FFFF

#endif /* BOOTLOADER_BOOTLOADER_PRIVATE_H_ */
