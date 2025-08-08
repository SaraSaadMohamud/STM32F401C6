/*
 ******************************************************************************
 * @file           : CRC_private.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : CRC HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_CRC_CRC_PRIVATE_H_
#define MACL_CRC_CRC_PRIVATE_H_
/********************** include part ******************************/

/*************************** MACRO ****************************/

#define _AHB1_STR_ADD     ((volatile uint32*)0x40020000)
#define CRC_STR_ADD       ((volatile uint32*)0x40023000)
#define CRC_REG           ((volatile CRC_REG_CFG*)0x40023000)

/********************* user data type *****************************/
typedef struct
{
	uint32 CRC_DR;
	uint32 CRC_IDR;
	uint32 CRC_CR;
}CRC_REG_CFG;
/********************* user data type *****************************/
/*************************** MACRO ****************************/


#endif /* MACL_CRC_CRC_PRIVATE_H_ */
