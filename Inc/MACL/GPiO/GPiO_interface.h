 /*
 *******************************************************************************
 * @file           : GPIO_interface
 * @author         : SARA SAAD MAHMOUD
 * @brief          : GPIO interfacing / headring  file
 ******************************************************************************
*/

#ifndef MACL_GPIO_GPIO_INTERFACE_H_
#define MACL_GPIO_GPIO_INTERFACE_H_


/************************************* INCLUDE START ***********************************************************/
#include "../STD_TYPES.h"
#include "../MATH.h"
#include "GPIO_config.h"
#include "GPIO_private.h"
#include "../RCC/RCC_interface.h"
/************************************* INCLUDE START ***********************************************************/

/*************************************      MACRO START      ***********************************************************/
/*************************************      MACRO END      ***********************************************************/

/************************************* MACRO FUNCTION START***********************************************************/
#define LOCKED_PIN 		16




#define	AF0_SYSTEM  		0b0000
#define	AF1_TIM0_TIM2       0b0001
#define	AF2_TIM3_TO_TIM5	0b0010
#define	AF3_TIM9_TO_TIM11	0b0011
#define	AF4_I2C1_TO_12C3	0b0100
#define	AF5_SPI1_TO_SPI4	0b0101
#define	AF6_SPI3			0b0110
#define	AF7_USART1_USART2	0b0111
#define	AF8_USART6			0b1000
#define	AF9_I2C2_TO_I2C3	0b1001
#define	AF10_OTG			0b1010
#define	AF11_				0b1011
#define	AF12_SDIO			0b1100
#define	AF13_				0b1101
#define	AF14_				0b1110
#define	AF15_EVENTOUT		0b1111
/************************************* MACRO FUNCTION END ***********************************************************/

/************************************* USER DATA TYPES START ***********************************************************/
typedef enum
{
	GPIO_PORTA=0,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
	GPIO_PORTE,
	GPIO_PORTH,
}port_t;

typedef enum
{
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,

}pin_t;

typedef enum
{
	GPIO_INPUT_MODE = 0,
	GPIO_OUTPUE_MODE,
	GPIO_AF_MODE,
	GPIO_ANALOG_MODE,
}mode_cfg;

typedef enum
{
	PUSH_PULL_OUTPUT_TYPE = 0,
	OPEN_DRAIN_OUTPUT_TYPE,
}output_type;
typedef enum
{
	LOW_SPEED =0,
	MIDUIM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED,
}out_speed;

typedef enum
{
	NO_PULL =0,
	PULL_UP,
	PULL_DOWN,
}pull_cfg;

typedef enum
{
	GPIO_LOW =0,
	GPIO_HIGH,
}logic_t;

typedef enum{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}Alternative_t;
typedef struct
{
	port_t port;
	pin_t pin;
	mode_cfg mode;
	output_type out_type;
	out_speed speed;
	pull_cfg  pull_type;
	Alternative_t AF_PIN;
}pin_cfg;
/************************************* USER DATA TYPES END   ***********************************************************/

/************************************* FUNCTION PROTOTYPES   ***********************************************************/
STD_RETURN_TYPES GPIO_PIN_SET_MODE(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_SET_OUTPUT_TYPE(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_SET_OUTPUT_SPEED(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_SET_PULL_TYPE(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_SET_PIN_LOGIC(pin_cfg * ptr, logic_t logic);
STD_RETURN_TYPES GPIO_PIN_GET_PIN_LOGIC(pin_cfg * ptr,logic_t *logic);
STD_RETURN_TYPES GPIO_PIN_MODE_LOOKED(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_SET_BIT(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_CLEAR_BIT(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_SET_AFPIN(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_TOGGLE_LOGIC(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_OUTPUT_CFG(pin_cfg * ptr);
STD_RETURN_TYPES GPIO_PIN_INPUT_CFG(pin_cfg * ptr);
#endif /* MACL_GPIO_GPIO_INTERFACE_H_ */
