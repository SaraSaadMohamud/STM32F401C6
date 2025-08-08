/*
 ******************************************************************************
 * @file           : Bootloader_config.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : Bootloader header body
 ******************************************************************************
*/


#ifndef BOOTLOADER_BOOTLOADER_CONFIG_H_
#define BOOTLOADER_BOOTLOADER_CONFIG_H_

#define BL_DEBUG_FEATURE_DISABLE    0
#define BL_DEBUG_FEATURE_ENABLE     1

#define CBL_DEBUG_SELECTOR    BL_DEBUG_FEATURE_ENABLE


#define SERIAL_CONNECTION_FEATURE_ENABLE	1
#define SERIAL_CONNECTION_FEATURE_DISABLE   0

#define USART_PERIPHERAL_ENABLE  SERIAL_CONNECTION_FEATURE_ENABLE
#define SPI_PERIPHERAL_ENABLE  	 SERIAL_CONNECTION_FEATURE_ENABLE
#define CAN_PERIPHERAL_ENABLE    SERIAL_CONNECTION_FEATURE_ENABLE
#define LIN_PERIPHERAL_ENABLE    SERIAL_CONNECTION_FEATURE_ENABLE

#endif /* BOOTLOADER_BOOTLOADER_CONFIG_H_ */
