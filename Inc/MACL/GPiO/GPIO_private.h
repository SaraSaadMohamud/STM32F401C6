 /*
 *******************************************************************************
 * @file           : GPIO_PRIVATE.H
 * @author         : SARA SAAD MAHMOUD
 * @brief          : GPIO HEADER file
 ******************************************************************************
*/

#ifndef MACL_GPIO_GPIO_PRIVATE_H_
#define MACL_GPIO_GPIO_PRIVATE_H_

/*************************************      MACRO START      ***********************************************************/
#define PERIPHERAL_STR_ADD 		0x40000000
#define AHB1_STR_ADD			0x40020000
#define GPIOA_STR_ADD           0x40020000
#define GPIOB_STR_ADD           0x40020400
#define GPIOC_STR_ADD           0x40020800
#define GPIOD_STR_ADD           0x40020C00
#define GPIOE_STR_ADD           0x40021000
#define GPIOH_STR_ADD           0x40021C00


#define  GPIOX_SMODER   0X00
#define  GPIOX_OTYPER   0X04
#define  GPIOX_OSPEEDR  0X08
#define  GPIOX_PUPDR    0X0C
#define  GPIOX_IDR      0X10
#define  GPIOX_ODR      0X14
#define  GPIOX_BSRR     0X18
#define  GPIOX_LCKR     0X1C
#define  GPIOX_AFRL     0X20
#define  GPIOX_AFRH     0X24

/*************************************      MACRO END       ***********************************************************/


#endif /* MACL_GPIO_GPIO_PRIVATE_H_ */
