/*
 * KEYPAD_interface.h
 *
 *  Created on: Jul 20, 2025
 *      Author: DELL
 */

#ifndef ECUAL_KEYBAD_KEYPAD_INTERFACE_H_
#define ECUAL_KEYBAD_KEYPAD_INTERFACE_H_
/************** Section: include part *************/
#include "../../MACL/GPiO/GPiO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

/**************************************************/
/************** Section: Macros *******************/
#define KEYPAD_ROWS_NUM     4
#define KEYPAD_COLUMN_NUM   4
/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef struct
{
   pin_cfg key_row[KEYPAD_ROWS_NUM];
   pin_cfg key_column[KEYPAD_COLUMN_NUM];
}keypad_cfg;

/**************************************************/

/*************  Section: Function Prototype *******/

STD_RETURN_TYPES KEYPAD_INTIALIZE(keypad_cfg *PTR);
STD_RETURN_TYPES KEYPAD_GET_VALUE(keypad_cfg *PTR,uint8 *value);

/**************************************************/

#endif /* ECUAL_KEYBAD_KEYPAD_INTERFACE_H_ */
