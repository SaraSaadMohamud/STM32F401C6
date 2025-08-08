/*
 ******************************************************************************
 * @file           : TFT_INTERFACE.H
 * @author         : SARA SAAD MAHMOUD
 * @brief          : TFT HEADER FILE
 ******************************************************************************
*/

#ifndef ECUAL_TFT_TFT_INTERFACE_H_
#define ECUAL_TFT_TFT_INTERFACE_H_
/************************ INCLUDE PART ****************************/
#include "../../MACL/GPiO/GPiO_interface.h"
#include "../../MACL/SYSTICK/SYSTICK_interface.h"
#include "../../MACL/SPI/SPI_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"

/************************ INCLUDE PART ****************************/

/************************** MACROS PART ***************************/
#define SLEEP_OUT_CMD            0X11

#define SLEEP_OUT_CMD            0X11
#define COLOUR_MODE_CMD          0X3A
#define DISPLAY_ON_CMD           0X29
#define X_DIRECTION_CMD          0X2A
#define Y_DIRECTION_CMD          0X2B
#define SCREEN_WRITE_CMD         0X2C

#define X_DIR_START_B0           0
#define X_DIR_START_B1           0
#define X_DIR_END_B0             0
#define X_DIR_END_B1             127

#define Y_DIR_START_B0           0
#define Y_DIR_START_B1           0
#define Y_DIR_END_B0             0
#define Y_DIR_END_B1             159

#define IMAGE_SIZE               20480

/************************** MACROS PART ***************************/

/************************* USER DATA TYPES ***************************/

/************************* USER DATA TYPES ***************************/

/********************** FUNCTION DECLERATION ***********************/
STD_RETURN_TYPES TFT_INI(pin_cfg *CTRL_PIN,pin_cfg *RESET_PIN);
STD_RETURN_TYPES TFT_SEND_COMMAND(pin_cfg *CTRL_PIN,uint8 CMD);
STD_RETURN_TYPES TFT_SEND_Data(pin_cfg *CTRL_PIN,uint8 data);
STD_RETURN_TYPES TFT_IMAGE_DISPLAY(pin_cfg *CTRL_PIN, const uint16 *pos);
/********************** FUNCTION DECLERATION ***********************/
#endif /* ECUAL_TFT_TFT_INTERFACE_H_ */
