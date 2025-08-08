 /*
 *******************************************************************************
 * @file           : NVIC_private.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : NVIC header file
 ******************************************************************************
*/

#ifndef MACL_NVIC_NVIC_PRIVATE_H_
#define MACL_NVIC_NVIC_PRIVATE_H_

/************************** MACROS ***************************/
#define NVIC_STR_ADD  		((volatile uint32*)0xE000E100)
#define NVIC_REG            ((volatile NVIC_REG_CFG*)0xE000E100)
/************************** MACROS ***************************/

/************************** User data type decleration ***************************/
typedef struct
{
	uint32 NVIC_ISER[8];
	uint32 Reserved0[24];
	uint32 NVIC_ICER[8];
	uint32 Reserved1[24];
	uint32 NVIC_ISPR[8];
	uint32 Reserved2[24];
	uint32 NVIC_ICPR[8];
	uint32 Reserved3[24];
	uint32 NVIC_IABR[8];
	uint32 Reserved4[56];
	uint8  NVIC_IPR[240];
	uint32 Reserved5[580];
	uint32 NVIC_STIR;
}NVIC_REG_CFG;
/************************** User data type decleration ***************************/
#endif /* MACL_NVIC_NVIC_PRIVATE_H_ */
