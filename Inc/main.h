 /*
 *******************************************************************************
 * @file           : STD_TYPES.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : main application header file
 ******************************************************************************
*/

#ifndef MAIN_H_
#define MAIN_H_

/************************************* INCLUDE START ***********************************************************/

#include "MACL/GPiO/GPiO_interface.h"
#include "MACL/RCC/RCC_interface.h"
#include "MACL/NVIC/NVIC_interface.h"
#include "MACL/EXTI/EXTI_interface.h"
#include "MACL/SYSTICK/SYSTICK_interface.h"
#include "MACL/SESTEM_CTRL/SYS_CTRL_interface.h"
#include "MACL/USART/USART_interface.h"
#include "MACL/SPI/SPI_interface.h"
#include "MACL/FLASH/FLASH_interface.h"
#include "Bootloader/Bootloader_interface.h"

#include "ECUAL/LED/LED_interface.h"
#include "ECUAL/BUTTON/BUTTON_interface.h"
#include "ECUAL/BUZZER/BUZZER_interface.h"
#include "ECUAL/MOTOR/MOTOR_interface.h"
#include "ECUAL/SEGEMENT/SEGMENT_interface.h"
#include "ECUAL/KEYBAD/KEYPAD_interface.h"
#include "ECUAL/LCD/LCD_interface.h"
#include "ECUAL/TFT/TFT_interface.h"
/************************************* INCLUDE START ***********************************************************/


void pin_intialize(void);
#endif /* MAIN_H_ */
