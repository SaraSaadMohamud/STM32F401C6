 /*
 *******************************************************************************
 * @file           : EXTI_private.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : EXTI header file
 ******************************************************************************
*/

#ifndef MACL_EXTI_EXTI_PRIVATE_H_
#define MACL_EXTI_EXTI_PRIVATE_H_

/********************************** include part **********************************/
#define EX_APB2_STR_ADD  		((volatile uint32*)0x40010000)
#define EXTI_STR_ADD  		((volatile uint32*)0x40013C00)
#define SYS_CFG_STR_ADD 	((volatile uint32*)0x40013800)
#define SYS_CFG_REG			((volatile SYS_CFG_REG_t*)SYS_CFG_STR_ADD )
#define EXTI_REG     	 	((volatile EXTI_REG_CFG*)0x40013C00)
/********************************** include part **********************************/

/******************************** user data type **************************************/
typedef struct
{
	uint32 EXTI_IMR;
	uint32 EXTI_EMR;
	uint32 EXTI_RTSR;
	uint32 EXTI_FTSR;
	uint32 EXTI_SWIER;
	uint32 EXTI_PR;
}EXTI_REG_CFG;

typedef struct
{
	uint32 SYSCFG_MEMRMP;
	uint32 SYSCFG_PMC;
	uint32 SYSCFG_EXTICR[4];
	uint32 Reserved0[2];
	uint32 SYSCFG_CMPCR;
}SYS_CFG_REG_t;

#endif /* MACL_EXTI_EXTI_PRIVATE_H_ */
