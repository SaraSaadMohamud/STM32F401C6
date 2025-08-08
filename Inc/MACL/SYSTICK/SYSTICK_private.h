/*
 ******************************************************************************
 * @file           : SYSTICK_private.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SYSTICK header file
 ******************************************************************************
*/

#ifndef MACL_SYSTICK_SYSTICK_PRIVATE_H_
#define MACL_SYSTICK_SYSTICK_PRIVATE_H_

/************************ MACROS ******************************/
#define  SYSTICK_STR_ADD   ((volatile uint32*)0xE000E010)
#define  SYSTICK_REG		((volatile SYSTICK_REG_CFG*)0xE000E010)

/************************ MACROS ******************************/

/************************ USER DATA TYPES *****************************/
typedef struct
{
	uint32 STK_CTRL;
	uint32 STK_LOAD;
	uint32 STK_VAL;
	uint32 STK_CALIB;
}SYSTICK_REG_CFG;

/************************ USER DATA TYPES *****************************/

#endif /* MACL_SYSTICK_SYSTICK_PRIVATE_H_ */
