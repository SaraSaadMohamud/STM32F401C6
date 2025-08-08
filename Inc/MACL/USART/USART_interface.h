/*
 ******************************************************************************
 * @file           : USART interface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : USART header file
 ******************************************************************************
*/

#ifndef MACL_USART_USART_INTERFACE_H_
#define MACL_USART_USART_INTERFACE_H_
/************************** include Part *********************************/
#include "../MATH.h"
#include "../STD_TYPES.h"
#include "USART_config.h"
#include "USART_private.h"
#include "../RCC/RCC_interface.h"

/************************** include Part *********************************/

/************************* Macros ************************************/
#define U_ENABLE        		1
#define U_DISABLE       		0

#define PARITY_ENABLE   		1
#define PARITY_DISABLE  		0

#define P_EVEN_MODE	    		0
#define P_ODD _MODE  			1

#define STOP_1BIT       		00
#define STOP_0_5BIT     		01
#define STOP_1_5BIT     		11
#define STOP_2BIT      		    10

#define SAMPLE_8MODE			1
#define SAMPLE_16MODE			0

#define DATA_8BIT			    0
#define DATA_9BIT			    1

#define BREAKE_FRAME_ENABLE     1
#define BREAKE_FRAME_DISABLE    0

#define TX_ENABLE				1
#define TX_DISABLE				0

#define RX_ENABLE				1
#define RX_DISABLE				0

#define USART_ENABLE            1
#define USART_DISABLE           0

#define TR_COMPLETE_INT_ENABLE  1
#define TR_COMPLETE_INT_DISABLE 0

#define RX_INT_ENABLE			1
#define RX_INT_DISABLE			0

#define CLK16_16SAMP_9600_Fraction      3
#define CLK16_16SAMP_9600_Mantissa      104

#define CLK16_8SAMP_9600_Fraction     	3
#define CLK16_8SAM_9600_Mantissa     	208

#define CLK16_16SAMP_2400_Fraction      11
#define CLK16_16SAMP_2400_Mantissa      416

#define CLK16_8SAMP_2400_Fraction       3
#define CLK16_8SAM_2400_Mantissa     	833

#define CLK16_16SAMP_19300_Fraction     12
#define CLK16_16SAMP_19300_Mantissa     51

#define CLK16_8SAMP_19300_Fraction     	4
#define CLK16_8SAM_19300_Mantissa     	103

#define USART1_ENABLE      1
#define USART2_ENABLE      2
#define USART6_ENABLE      6

/************************* Macros ************************************/
/*************************** USER DATA TYPES ******************************/
typedef enum
{
	BR_2400,
	BR_9600,
	BR_19300,
	BR_57600,
	BR_115200,
	BR_231900,
}BR_CFG;
/*************************** USER DATA TYPES ******************************/

/************************** FUNCTION DEFINITON ******************************/
STD_RETURN_TYPES USART_INIT(uint8 index);
STD_RETURN_TYPES USART_SEND_DATA(uint8 index, uint8 data);
STD_RETURN_TYPES USART_RECIVE_DATA(uint8 index,uint8 *data);
STD_RETURN_TYPES USART_RECIVE_STRING(uint8 index,uint8 *data);
STD_RETURN_TYPES USART_SEND_STRING(uint8 index,uint8 *data);
STD_RETURN_TYPES USART_READ_DATA(uint8 index,uint32 *data);
STD_RETURN_TYPES USART_SELECT_BAUD_RATE(uint8 index,BR_CFG BRATE);
/************************** FUNCTION DEFINITON ******************************/
#endif /* MACL_USART_USART_INTERFACE_H_ */
