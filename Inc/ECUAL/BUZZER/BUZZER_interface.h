 /*
 *******************************************************************************
 * @file           : BUZZER_interface
 * @author         : SARA SAAD MAHMOUD
 * @brief          : BUZZER interfacing / headring  file
 ******************************************************************************
*/

#ifndef ECUAL_BUZZER_BUZZER_INTERFACE_H_
#define ECUAL_BUZZER_BUZZER_INTERFACE_H_

/************** Section: include part *************/
#include <MACL/GPiO/GPiO_interface.h>
/**************************************************/

/************** Section: Macros *******************/

/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef enum{
  TURN_OFF=0,
  TURN_ON,
}buzzer_state;


/**************************************************/

/*************  Section: Function Prototype *******/
STD_RETURN_TYPES BUZZER_INTIATIAZE(pin_cfg *ptr);
STD_RETURN_TYPES BUZZER_TURN_ON(pin_cfg *ptr);
STD_RETURN_TYPES BUZZER_TURN_OFF(pin_cfg *ptr);
STD_RETURN_TYPES BUZZER_TOGGLE(pin_cfg *ptr);
/**************************************************/


#endif /* ECUAL_BUZZER_BUZZER_INTERFACE_H_ */
