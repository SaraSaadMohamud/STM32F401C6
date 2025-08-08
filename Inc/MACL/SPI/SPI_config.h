/*
 ******************************************************************************
 * @file           : SPI_CONFIG.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SPI HEADER FILE
 ******************************************************************************
*/


#ifndef MACL_SPI_SPI_CONFIG_H_
#define MACL_SPI_SPI_CONFIG_H_

/************** Section: include part *************/

/**************************************************/

/************** Section: Macros *******************/

/*
 * options:
 *  FORMATE_8BIT_DATA
 *  FORMATE_16BIT_DATA
 */

#define DATA_TRANSIEVE_SIZE FORMATE_8BIT_DATA
/*
 * OPTIONS [CPOL]
 * CPOL_IDEAL_CLK_LOW
 * CPOL_IDEAL_CLK_HIGH
 */
#define DATA_IDEL_CLOCK_   CPOL_IDEAL_CLK_HIGH

/*
 * OPTIONS[CPHA]
 * FIRST_CLK_PHASE
 * SECOND_CLK_PHASE
 */

#define DATA_CLOCK_PHASE  SECOND_CLK_PHASE
/*
 * OPTIONS:
 * MSB_transmitted_first
 * LSB_transmitted_first
 */
#define DATA_TRANSIVE_DIR MSB_transmitted_first

/*
 * OPTIONS:
 * NSS_SW_MANAGE
 * NSS_HW_MANAGE
 */
#define MASTER_CONTROL_SLAVE_   NSS_HW_MANAGE
/*
 * OPTIONS:
 * MOTROLA_FORMATE_FRAME
 * TI_FORMATE_FRAME
 *
 */
#define FRAME_FORMATE TI_FORMATE_FRAME
/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/

/**************************************************/

/*************  Section: Function Prototype *******/

/**************************************************/

#endif /* MACL_SPI_SPI_CONFIG_H_ */
