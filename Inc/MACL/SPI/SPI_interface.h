/*
 ******************************************************************************
 * @file           : SPI_incterface.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SPI HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_SPI_SPI_INTERFACE_H_
#define MACL_SPI_SPI_INTERFACE_H_

/************** Section: include part *************/
#include "../MATH.h"
#include "../STD_TYPES.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "../RCC/RCC_interface.h"
/**************************************************/

/************** Section: Macros *******************/
#define BIT_SET        			1
#define BIT_CLEAR      			0

#define NSS_SW_MANAGE			1
#define NSS_HW_MANAGE			0

#define FORMATE_8BIT_DATA		0
#define FORMATE_16BIT_DATA      1

#define MSB_transmitted_first   0
#define LSB_transmitted_first   1

#define SPI_PERIPHERAL_ENABLE   1
#define SPI_PERIPHERAL_DISABLE  0

#define MASTER_CFG_ENABLE		1
#define SLAVE_CFG_ENABLE		0

/* BUAD RATE CONFIGURATION  */
#define SPI_CLK_DIV2			0b000
#define SPI_CLK_DIV4			0b001
#define SPI_CLK_DIV8			0b010
#define SPI_CLK_DIV16			0b011
#define SPI_CLK_DIV32			0b100
#define SPI_CLK_DIV64			0b101
#define SPI_CLK_DIV128			0b110
#define SPI_CLK_DIV256			0b111

#define CPOL_IDEAL_CLK_LOW  	0
#define CPOL_IDEAL_CLK_HIGH  	1

#define FIRST_CLK_PHASE			0
#define SECOND_CLK_PHASE		1

#define FULL_DUPLEX_MODE_ENABLE 0 // RECIVE AND TRANSIMTE
#define SYMPOLEX_MODE_ENABLE    1 // RECIEVE ONLY

#define SPI_CRC_ENABLE			1
#define SPI_CRC_DISABLE			0

#define UNDIRECTIONAL_DATA_2LINES_MOOD  0
#define DIRECTIONAL_DATA_1LINES_MOOD  	1

#define DIRECTIONAL_RESCIVE_MODE        0
#define DIRECTIONAL_TRANSMITE_MODE      1

#define TRANSMIT_INTERRUPT_ENABLE		1
#define TRANSMIT_INTERRUPT_DISABLE		0

#define RESCIVE_INTERRUPT_ENABLE		1
#define RESCIVE_INTERRUPT_DISABLE		0

#define ERROR_INTERRUPT_ENABLE			1
#define ERROR_INTERRUPT_DISABLE			0

#define MOTROLA_FORMATE_FRAME			0
#define	TI_FORMATE_FRAME				1

#define FRAME_ERROR_DETECTED            0
#define FRAME_ERROR_UNDETECTED          1

#define SP_BUSSY                        1
#define SP_EMPTY                        0

#define OVERRUN_OCCURED                 0
#define NO_OVERRUN_OCCURED              1

#define RX_BUFFER_EMPTY                 0
#define RX_BUFFER_BUSY                  1

#define TX_BUFFER_EMPTY                 0
#define TX_BUFFER_BUSY                  1

#define MASTER_CLK_OUTPUT_ENABLE		1
#define MASTER_CLK_OUTPUT_DISABLE		0
/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef enum
{
	SPI1_ENABLE = 1 ,
	SPI2_ENABLE ,
	SPI3_ENABLE ,
	SPI4_ENABLE ,
}SPI_INDEX;
/**************************************************/

/*************  Section: Function Prototype *******/
STD_RETURN_TYPES  SPI_MASTER_INT(SPI_INDEX index);
STD_RETURN_TYPES  SPI_SLAVE_INT(SPI_INDEX index);
STD_RETURN_TYPES  SPI_TRANSCIVE(SPI_INDEX index,uint16 data_t , uint16 *data_r );
/**************************************************/

#endif /* MACL_SPI_SPI_INTERFACE_H_ */
