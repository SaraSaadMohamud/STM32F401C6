/*
 ******************************************************************************
 * @file           : LCD_interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : LCD header file
 ******************************************************************************
*/

#ifndef ECUAL_LCD_LCD_INTERFACE_H_
#define ECUAL_LCD_LCD_INTERFACE_H_

/*********************** include part *************************/
#include "../../MACL/GPiO/GPiO_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include <string.h>
/*********************** include part *************************/

/************** Section: Macros *******************/
#define LCD_CLEAR_DISPLAY        0X01
#define LCD_CURSOR_RETURN_HOME   0X02

#define LCD_DECREMENT_ADDRESS_CTR_SHIFT_OFF  0X04 // 100
#define LCD_DECREMENT_ADDRESS_CTR_SHIFT_ON   0X05 // 101
#define LCD_IECREMENT_ADDRESS_CTR_SHIFT_OFF  0X06 // 110
#define LCD_IECREMENT_ADDRESS_CTR_SHIFT_ON   0X07 // 111

#define LCD_DISPLAY_OFF_CURSOR_OFF_BLINKING_OFF  0X08
#define LCD_DISPLAY_OFF_CURSOR_OFF_BLINKING_ON   0X09
#define LCD_DISPLAY_OFF_CURSOR_ON_BLINKING_OFF   0X0A
#define LCD_DISPLAY_OFF_CURSOR_ON_BLINKING_ON    0X0B

#define LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_OFF    0X0C
#define LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_ON     0X0D
#define LCD_DISPLAY_ON_CURSOR_ON_BLINKING_OFF     0X0E
#define LCD_DISPLAY_ON_CURSOR_ON_BLINKING_ON      0X0F

#define LCD_MOVE_CURSOR_LEFT  0X10
#define LCD_MOVE_CURSOR_RIGTH 0X14
#define LCD_SHIFT_LEFT        0X18
#define LCD_SHIFT_RIGHT       0X1C

#define LCD_8MODE_1LINE_8DOT  0X30
#define LCD_8MODE_1LINE_11DOT 0X34
#define LCD_8MODE_2LINE_8DOT  0X38
#define LCD_8MODE_2LINE_11DOT 0X3C

#define LCD_4MODE_1LINE_8DOT  0X20
#define LCD_4MODE_1LINE_11DOT 0X24
#define LCD_4MODE_2LINE_8DOT  0X28
#define LCD_4MODE_2LINE_11DOT 0X2C

#define LCD_CGRAM_START_ADDRESS 0X40
#define LCD_DDRAM_START_ADDRESS 0X80

#define ROW1  0X00
#define ROW2  0X01
#define ROW3  0X02
#define ROW4  0X03

/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef struct
{
	pin_cfg Rs_pin;
	pin_cfg en_pin;
	pin_cfg lcd_pins[8];
}lcd_8mode;

typedef struct
{
    pin_cfg Rs_pin;
    pin_cfg en_pin;
    pin_cfg lcd_pins[4];
}lcd_4mode;
/**************************************************/

/*************  Section: Function Prototype *******/
STD_RETURN_TYPES LCD_8MODE_INTIALIZED(lcd_8mode *PTR);
STD_RETURN_TYPES LCD_8MODE_SEND_COMMAND(lcd_8mode *PTR,uint8 command);
STD_RETURN_TYPES LCD_8MODE_SEND_CHAR_DATA(lcd_8mode *PTR,uint8 data);
STD_RETURN_TYPES LCD_8MODE_SEND_CHAR_DATA_WITH_POS(lcd_8mode *PTR,uint8 data,uint8 row,uint8 column);
STD_RETURN_TYPES LCD_8MODE_SEND_STRING(lcd_8mode *PTR,uint8 *str);
STD_RETURN_TYPES LCD_8MODE_SEND_STRING_WITH_POS(lcd_8mode *PTR,uint8 *str,uint8 row, uint8 column);
STD_RETURN_TYPES LCD_8MODE_SEND_CUSTORMER_CHAR(lcd_8mode *PTR,uint8 *data,uint8 mem_pos, uint8 row, uint8 column);

STD_RETURN_TYPES LCD_4MODE_INTIALIZED(lcd_4mode *PTR);
STD_RETURN_TYPES LCD_4MODE_SEND_COMMAND(lcd_4mode *PTR,uint8 command);
STD_RETURN_TYPES LCD_4MODE_SEND_CHAR_DATA(lcd_4mode *PTR,uint8 data);
STD_RETURN_TYPES LCD_4MODE_SEND_CHAR_DATA_WITH_POS(lcd_4mode *PTR,uint8 data,uint8 row,uint8 column);
STD_RETURN_TYPES LCD_4MODE_SEND_STRING(lcd_4mode *PTR,uint8 *str);
STD_RETURN_TYPES LCD_4MODE_SEND_STRING_WITH_POS(lcd_4mode *PTR,uint8 *str,uint8 row, uint8 column);
STD_RETURN_TYPES LCD_4MODE_SEND_CUSTORMER_CHAR(lcd_4mode *PTR,uint8 *data,uint8 mem_pos, uint8 row, uint8 column);

STD_RETURN_TYPES LCD_CONVERT_BYTE(uint8 number, uint8 str[4]);
STD_RETURN_TYPES LCD_CONVERT_SHORT(uint16 number, uint8 str[6]);
STD_RETURN_TYPES LCD_CONVERT_INT(uint32 number, uint8 str[11]);
/**************************************************/

#endif /* ECUAL_LCD_LCD_INTERFACE_H_ */
