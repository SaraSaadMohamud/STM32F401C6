 /*
 *******************************************************************************
 * @file           : EXTI_interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : EXTI header file
 ******************************************************************************
*/

#ifndef MACL_EXTI_EXTI_INTERFACE_H_
#define MACL_EXTI_EXTI_INTERFACE_H_

/************************************* INCLUDE ****************************************/
#include "../GPiO/GPiO_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
/************************************* INCLUDE ****************************************/

/************************************ macros  *****************************************/
#define EXTI_LINE   15
#define SYS_CFG_DIV 4

#define EXTI_PORTA   0b0000
#define EXTI_PORTB   0b0001
#define EXTI_PORTC   0b0010
#define EXTI_PORTD   0b0011
#define EXTI_PORTE   0b0100
#define EXTI_PORTH   0b0111

/************************************ macros  *****************************************/
/******************************** user data type **************************************/
typedef enum
{
	RISING_TRIGGER =0,
	FALLING_TRIGGER,
	ONCHANGE_TRIGGER,
}EXTI_TRIGGER_SELE;

typedef enum
{
	EXTI_LIN0 = 0,
	EXTI_LIN1,
	EXTI_LIN2,
	EXTI_LIN3,
	EXTI_LIN4,
	EXTI_LIN5,
	EXTI_LIN6,
	EXTI_LIN7,
	EXTI_LIN8,
	EXTI_LIN9,
	EXTI_LIN10,
	EXTI_LIN11,
	EXTI_LIN12,
	EXTI_LIN13,
	EXTI_LIN14,
	EXTI_LIN15,
}EXTI_LINES;
/******************************** user data type **************************************/
/******************************** FUNCTON DECLERATION ************************************/
STD_RETURN_TYPES EXTI_SET_TRIGERR(EXTI_LINES line, EXTI_TRIGGER_SELE sele_trg);
STD_RETURN_TYPES EXTI_ENABLE_LINE(EXTI_LINES line);
STD_RETURN_TYPES EXTI_DISABLE_LINE(EXTI_LINES line);
STD_RETURN_TYPES EXTI_SET_SW_TRIGERR(EXTI_LINES line);
STD_RETURN_TYPES EXTI_SET_INTERRUPT_PORT(EXTI_LINES line,port_t port);
STD_RETURN_TYPES EXTI_INITIALIZE(EXTI_LINES line,port_t port,EXTI_TRIGGER_SELE sele_trg );
STD_RETURN_TYPES EXTI_CALLBACK_INT(EXTI_LINES line,void (*pf)(void));
/******************************** FUNCTON DECLERATION ************************************/
#endif /* MACL_EXTI_EXTI_INTERFACE_H_ */
