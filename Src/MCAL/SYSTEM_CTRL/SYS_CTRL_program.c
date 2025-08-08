 /*
 *******************************************************************************
 * @file           : SYS_CTRL_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SYS_CTRL source file
 ******************************************************************************
*/

#include "MACL/SESTEM_CTRL/SYS_CTRL_interface.h"


STD_RETURN_TYPES SYS_CTRL_Interrupt_SET_priority_level(uint32 value)
{
	STD_RETURN_TYPES RET = E_OK;

	SYS_CTRL_REG ->AIRCR = value;

	return(RET);
}
