 /*
 *******************************************************************************
 * @file           : MOTOR_INTERFACE.H
 * @author         : SARA SAAD MAHMOUD
 * @brief          : MOTOR HEADER file
 ******************************************************************************
*/

#ifndef ECUAL_SEGEMENT_SEGMENT_INTERFACE_H_
#define ECUAL_SEGEMENT_SEGMENT_INTERFACE_H_


/************** Section: include part *************/
#include <MACL/GPiO/GPiO_interface.h>
#include "SEGMENT_private.h"
#include "SEGEMENT_config.h"
/**************************************************/
/************** Section: Macros *******************/

/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef enum{
    SEGMENT_COMMON_CATHODE=0,
    SEGMENT_COMMONE_ANODE
}segment_type_t;

typedef struct {
	pin_cfg segment_pins[4];
    segment_type_t segment_connection;
}segment_cfg_t;
/**************************************************/

/*************  Section: Function Prototype *******/
STD_RETURN_TYPES SEGEMENT_INTIALIZE(segment_cfg_t *ptr);
STD_RETURN_TYPES SEGEMENT_WRITE_NUMBER(segment_cfg_t *ptr,uint8 number);
/**************************************************/

#endif /* ECUAL_SEGEMENT_SEGMENT_INTERFACE_H_ */
