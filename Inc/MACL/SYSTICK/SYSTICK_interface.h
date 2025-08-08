/*
 ******************************************************************************
 * @file           : SYSTICK_interface.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SYSTICK header file
 ******************************************************************************
*/

#ifndef MACL_SYSTICK_SYSTICK_INTERFACE_H_
#define MACL_SYSTICK_SYSTICK_INTERFACE_H_

/********************** include part ******************************/
#include "../STD_TYPES.h"
#include "../MATH.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
/********************** include part ******************************/

/*************************** MACRO ****************************/
#define SYSTICK_CTRL_ENABLE    		 0
#define SYSTICK_CTRL_INT_ENABLE 	 1
#define SYSTICK_CTRL_CLK_SRC	   	 2
#define SYSTICK_CTRL_CONFG  		 16

#define SYS_PERIODIC_TICK       	 0
#define SYS_SINGLE_TICK        		 1

#define SYSTICK_AHB_DIV8_CLOCK       0
#define SYSTICK_AHB_DIV1_CLOCK       1

#define SYS_MAX_VALUE  (uint32)(16777215)
/*************************** MACRO ****************************/

/********************* user data type *****************************/

/********************* user data type *****************************/

/*********************FUNCTION DECLERATION ************************/
/* FUNCTION TO INTIALIZE THE SYSTICLK PERIPHERAL*/
STD_RETURN_TYPES SYSTICK_INIT(uint32 SYS_TIME);

/*FUNCTION TO STOP INTERVAL*/
STD_RETURN_TYPES SYSTICK_DE_INIT(void);

/* FUNCTION to SELECT THE VALUE AND START COUNT UNTILE FINISH*/
STD_RETURN_TYPES SYSTICK_SET_LOAD_REG(uint32 SYS_TIME);

/* FUNCTION to SELECT THE SYSTICK CLOCK SOURCE to be [AHB, AHB/8] */
STD_RETURN_TYPES SYSTICK_SELECT_CLK(void);

/* FUNCTION to GET THE TICK WILL BE COUNT UNTILE FINISH*/
STD_RETURN_TYPES SYSTICK_GET_REMAINIG_TIME(uint32 *time);

/* FUNCTION to GET THE TICK TICKS THAT EXECUTED ALREADY*/
STD_RETURN_TYPES SYSTICK_GET_ELAPSED_TIME(uint32 *time);

/* FUNCTION TO EXECUTE THE SYSTICK UNTILL EXECUTE*/
STD_RETURN_TYPES SYSTICK_SET_WAITING_TIME(uint32 SYS_TIME);

/* FUNCTION to SET THE VALUE BY USING ISR*/
STD_RETURN_TYPES SYSTICK_SET_INTERVAL_PRIODIC(uint32 SYS_TIME,void(*pf)(void));

/* FUNCTION to GET THE TICK TICKS THAT EXECUTED ALREADY*/
STD_RETURN_TYPES SYSTICK_SET_INTERVAL_SINGLE(uint32 SYS_TIME,void(*pf)(void));


/*********************FUNCTION DECLERATION ************************/
#endif /* MACL_SYSTICK_SYSTICK_INTERFACE_H_ */
