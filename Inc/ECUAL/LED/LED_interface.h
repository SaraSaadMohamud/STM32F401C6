 /*
 *******************************************************************************
 * @file           : LED_INTERFACE.H
 * @author         : SARA SAAD MAHMOUD
 * @brief          : LDE HEADER file
 ******************************************************************************
*/

#ifndef ECUAL_LED_LED_INTERFACE_H_
#define ECUAL_LED_LED_INTERFACE_H_

/************** Section: include part *************/
#include "MACL/GPiO/GPiO_interface.h"
#include "LED_config.h"
#include "LED_private.h"
/**************************************************/

/************** Section: Macros *******************/

/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef enum
{
    LED_ACTIVE_LOW = 0,
    LED_ACTIVE_HIGH
}led_connetion_t;

typedef enum{
   _TURN_OFF_=0,
   _TURN_ON_,
}led_state_t;

#define LED_CONNECTION1  LED_ACTIVE_LOW
/**************************************************/

/*************  Section: Function Prototype *******/
STD_RETURN_TYPES LED_INTIALIZE(pin_cfg *ptr);
STD_RETURN_TYPES LED_TURN_ON(pin_cfg *ptr);
STD_RETURN_TYPES LED_TURN_OFF(pin_cfg *ptr);
STD_RETURN_TYPES LED_TOGGLE(pin_cfg *ptr);
/**************************************************/

#endif /* ECUAL_LED_LED_INTERFACE_H_ */
