 /*
 *******************************************************************************
 * @file           : MOTOR_INTERFACE.H
 * @author         : SARA SAAD MAHMOUD
 * @brief          : MOTOR HEADER file
 ******************************************************************************
*/

#ifndef ECUAL_MOTOR_MOTOR_INTERFACE_H_
#define ECUAL_MOTOR_MOTOR_INTERFACE_H_

#include <MACL/GPiO/GPiO_interface.h>
#include "MOTOR_config.h"
#include "MOTOR_private.h"
/************** Section: Macros *******************/
#define MOTOR_TURN_OFF       0X00
#define MOTOR_TURN_FORWARD   0X01
#define MOTOR_TURN_BACKWORD  0X02

#define MOTOR_PIN1           0X00
#define MOTOR_PIN2           0X01
/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef struct
{
    pin_cfg motor_pin[2];
}motor_cfg_t;
/**************************************************/

/*************  Section: Function Prototype *******/
STD_RETURN_TYPES DC_MOTOR_INTIALIZE(motor_cfg_t *ptr);
STD_RETURN_TYPES DC_MOTOR_TURN_RIGHT(motor_cfg_t *ptr);
STD_RETURN_TYPES DC_MOTOR_TURN_LEFT(motor_cfg_t *ptr);
STD_RETURN_TYPES DC_MOTOR_TURN_OFF(motor_cfg_t *ptr);
/**************************************************/

#endif /* ECUAL_MOTOR_MOTOR_INTERFACE_H_ */
