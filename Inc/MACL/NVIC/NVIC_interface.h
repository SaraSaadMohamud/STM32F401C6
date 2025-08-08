 /*
 *******************************************************************************
 * @file           : NVIC_interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : NVIC header file
 ******************************************************************************
*/

#ifndef MACL_NVIC_NVIC_INTERFACE_H_
#define MACL_NVIC_NVIC_INTERFACE_H_
#include "../MATH.h"
#include "../STD_TYPES.h"
#include "../SESTEM_CTRL/SYS_CTRL_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"


/************************** MACROS ***************************/
#define REG_NUMBER_SELE      32
#define PRIORITY_SHIFT_NUM   4
#define GROUP_MAX_NUM        16
#define SUBGROUP_MAX_NUM     16


/************************** MACROS ***************************/
/************************** User data type decleration ***************************/
typedef enum
{
	GROUP1 = 1,
	GROUP2,
	GROUP3,
	GROUP4,
	GROUP5,
	GROUP6,
	GROUP7,
	GROUP8,
	GROUP9,
	GROUP10,
	GROUP11,
	GROUP12,
	GROUP13,
	GROUP14,
	GROUP15,
	GROUP16,

}group_priority;

typedef enum
{
	SUBGROUP1 = 1,
	SUBGROUP2,
	SUBGROUP3,
	SUBGROUP4,
	SUBGROUP5,
	SUBGROUP6,
	SUBGROUP7,
	SUBGROUP8,
	SUBGROUP9,
	SUBGROUP10,
	SUBGROUP11,
	SUBGROUP12,
	SUBGROUP13,
	SUBGROUP14,
	SUBGROUP15,
	SUBGROUP16,

}subgroup_priority;
typedef enum
{
	WWDG_INT = 0,
	EXTI16_PVD_INT ,
	EXTI21_TAMP_STAMP_INT ,
	EXTI22_RTC_WKUP_INT ,
	FLASH_INT ,
	RCC_INT ,
	EXTI0_INT ,
	EXTI1_INT ,
	EXTI2_INT ,
	EXTI3_INT ,
	EXTI4_INT ,
	DMA1_Stream0_INT ,
	DMA1_Stream1_INT ,
	DMA1_Stream2_INT ,
	DMA1_Stream3_INT ,
	DMA1_Stream4_INT ,
	DMA1_Stream5_INT ,
	DMA1_Stream6_INT ,
	ADC_INT ,
	EXTI9_5_INT =23,
	TIM1_BRK_TIM9_INT ,
	TIM1_UP_TIM10_INT ,
	TIM1_TRG_COM_TIM11_INT ,
	TIM1_CC_INT ,
	TIM2_INT ,
	TIM3_INT ,
	TIM4_INT ,
	I2C1_EV_INT ,
	I2C1_ER_INT ,
	I2C2_EV_INT ,
	I2C2_ER_INT ,
	SPI1_INT ,
	SPI2_INT ,
	USART1_INT ,
	USART2_INT ,
	EXTI15_10_INT = 40,
	EXTI17_RTC_Alarm_INT ,
	EXTI18_OTG_FS_WKUP_INT ,
	DMA1_Stream7_INT = 47,
	SDIO_INT = 49,
	TIM5_INT ,
	SPI3_INT ,
	DMA2_Stream0_INT = 56,
	DMA2_Stream1_INT ,
	DMA2_Stream2_INT ,
	DMA2_Stream3_INT ,
	DMA2_Stream4_INT ,
	OTG_FS_INT = 67,
	DMA2_Stream5_INT ,
	DMA2_Stream6_INT ,
	DMA2_Stream7_INT ,
	USART6_INT ,
	I2C3_EV_INT ,
	I2C3_ER_INT ,
	FPU_INT = 81,
	SPI4_INT = 84,

}IRQn_Type;
/************************** User data type decleration ***************************/

/************************** Function Dicleration *********************************/

STD_RETURN_TYPES NVIC_EnableIRQ(IRQn_Type IRQn);
STD_RETURN_TYPES NVIC_DisableIRQ(IRQn_Type IRQn);
STD_RETURN_TYPES NVIC_SetPendingIRQ(IRQn_Type IRQn);
STD_RETURN_TYPES NVIC_ClearPendingIRQ(IRQn_Type IRQn);
STD_RETURN_TYPES NVIC_GetPendingIRQ(IRQn_Type IRQn, uint8 *pending_status);
STD_RETURN_TYPES NVIC_GetActiveIRQ(IRQn_Type IRQn, uint8 *Active_status);
STD_RETURN_TYPES NVIC_SetPriority(IRQn_Type IRQn,uint8 priorty);
STD_RETURN_TYPES NVIC_Set_GLOBALPriority(IRQn_Type IRQn,group_priority groub, subgroup_priority sub_groub);
STD_RETURN_TYPES NVIC_GetPriority(IRQn_Type IRQn,uint8 *priorty);

/************************** Function Dicleration *********************************/

#endif /* MACL_NVIC_NVIC_INTERFACE_H_ */
