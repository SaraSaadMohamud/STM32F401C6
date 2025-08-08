 /*
 *******************************************************************************
 * @file           : SYS_CTRL_private.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SYS_CTRL header file
 ******************************************************************************
*/

#ifndef MACL_SESTEM_CTRL_SYS_CTRL_PRIVATE_H_
#define MACL_SESTEM_CTRL_SYS_CTRL_PRIVATE_H_
/******************************* MACRO ************************************/
#define SYS_CTRL_STR_ADD ((volatile uint32*)0xE000ED00)
#define SYS_CTRL_REG     ((volatile SYS_CTRL_REG_CFG*)0xE000ED00)
/******************************* MACRO ************************************/

/******************************* USER DATA TYPE ************************************/
typedef struct
{
	uint32 CPUID;
	uint32 ICSR;
	uint32 VTOR;
	uint32 AIRCR;
	uint32 SCR;
	uint32 CCR;
	uint32 SHPR1;
	uint32 SHPR2;
	uint32 SHPR3;
	uint32 SHCSR;
	uint32 CFSR;
	uint32 HFSR;
	uint32 Reserved0;
	uint32 MMAR;
	uint32 BFAR;
	uint32 AFSR;
}SYS_CTRL_REG_CFG;
/******************************* USER DATA TYPE ************************************/
#endif /* MACL_SESTEM_CTRL_SYS_CTRL_PRIVATE_H_ */
