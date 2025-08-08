 /*
 *******************************************************************************
 * @file           : SYS_CTRL_interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SYS_CTRL header file
 ******************************************************************************
*/

#ifndef MACL_SESTEM_CTRL_SYS_CTRL_INTERFACE_H_
#define MACL_SESTEM_CTRL_SYS_CTRL_INTERFACE_H_

/********************************** INCLUDE ************************************/
#include "../STD_TYPES.h"
#include "../MATH.h"
#include "SYS_CTRL_config.h"
#include "SYS_CTRL_private.h"
/********************************** INCLUDE ************************************/

/******************************* USER DATA TYPES *******************************/
#define SYS_CTRL_0SUBGROUB_16GROUB     0X05FA0030
#define SYS_CTRL_2SUBGROUB_8GROUB      0X05FA0040
#define SYS_CTRL_4SUBGROUB_4GROUB      0X05FA0500
#define SYS_CTRL_8SUBGROUB_2GROUB      0X05FA0600
#define SYS_CTRL_16SUBGROUB_0GROUB     0X05FA0700
/******************************* USER DATA TYPES *******************************/

/******************************* USER DATA TYPES *******************************/

/******************************* USER DATA TYPES *******************************/

/***************************** FUNCTION DECLERATION *****************************/
STD_RETURN_TYPES SYS_CTRL_Interrupt_SET_priority_level(uint32 value);
/***************************** FUNCTION DECLERATION *****************************/
#endif /* MACL_SESTEM_CTRL_SYS_CTRL_INTERFACE_H_ */
