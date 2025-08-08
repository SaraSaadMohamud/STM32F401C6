/*\
 ******************************************************************************
 * @file           : CRC_interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : CRC HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_CRC_CRC_INTERFACE_H_
#define MACL_CRC_CRC_INTERFACE_H_

/********************** include part ******************************/
#include "../MATH.h"
#include "../STD_TYPES.h"
#include "CRC_config.h"
#include "CRC_private.h"
#include "../RCC/RCC_interface.h"
/*************************** MACRO ****************************/
#define RESET_BIT     0
/*************************** MACRO ****************************/

/********************* user data type *****************************/
typedef enum
{
	CRC_VERFACATION_FAILD =0 ,
	CRC_VERFACATION_PASS,
}CRC_statue;
/********************* user data type *****************************/

/*********************FUNCTION DECLERATION ************************/

CRC_statue CRC_INIT(void);
CRC_statue CRC_RESET(void);
CRC_statue CRC_CALCULAT(uint32 *CRC_CAL_VALU , uint32 len , uint32 Buffer_data[]);
/*********************FUNCTION DECLERATION ************************/

#endif /* MACL_CRC_CRC_INTERFACE_H_ */
