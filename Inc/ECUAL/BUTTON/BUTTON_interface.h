/*
 *******************************************************************************
 * @file           : BUTTON_interface
 * @author         : SARA SAAD MAHMOUD
 * @brief          : BUTTON interfacing / headring  file
 ******************************************************************************
*/

#ifndef ECUAL_BUTTON_BUTTON_INTERFACE_H_
#define ECUAL_BUTTON_BUTTON_INTERFACE_H_

/************** Section: include part *************/
#include <MACL/GPiO/GPiO_interface.h>
/**************************************************/

/************** Section: Macros *******************/

/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef enum{
    BUTTON_RELEASED=0,
    BUTTON_PREASED
}button_state_t;

typedef enum {
    BUTTON_ACTIVE_LOW=0,
    BUTTON_ACTIVE_HIGH
}button_connection;

/**************************************************/

/*************  Section: Function Prototype *******/
STD_RETURN_TYPES BUTTON_INTIALIZE(pin_cfg *ptr);
STD_RETURN_TYPES BUTTON_READ_STATE(pin_cfg *ptr,button_state_t*state);
/**************************************************/

#endif /* ECUAL_BUTTON_BUTTON_INTERFACE_H_ */
