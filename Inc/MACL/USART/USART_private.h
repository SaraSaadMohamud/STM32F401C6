/*
 ******************************************************************************
 * @file           : USART private.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : USART header file
 ******************************************************************************
*/

#ifndef MACL_USART_USART_PRIVATE_H_
#define MACL_USART_USART_PRIVATE_H_
/************************* INCLUDE PART ***********************************/

/************************* INCLUDE PART ***********************************/
/*************************** Macros ******************************/
#define USART1_STS_AD   ((volatile uint32*)0x40011000)
#define USART2_STS_AD   ((volatile uint32*)0x40004400)
#define USART6_STS_AD   ((volatile uint32*)0x40011400)

#define USERT1_REG      ((volatile USART_REG_CFG*)0x40011000)
#define USERT2_REG      ((volatile USART_REG_CFG*)0x40004400)
#define USERT6_REG      ((volatile USART_REG_CFG*)0x40011400)
#define test 			((volatile uint32*)0x4001100C)
/*************************** Macros ******************************/

/************************** User Data Types *****************************/
typedef struct
{
	volatile uint32 PE   : 1;
	volatile uint32 FE   : 1;
	volatile uint32 NF   : 1;
	volatile uint32 ORE  : 1;
	volatile uint32 IDLE : 1;
	volatile uint32 RXNE : 1;
	volatile uint32 TC   : 1;
	volatile uint32 TXE  : 1;
	volatile uint32 LBD  : 1;
	volatile uint32 CTS  : 1;
	volatile uint32 res1 : 6;
	volatile uint32 res2 : 16;
}SRbits_t;

typedef struct
{
	volatile uint32 PSC   : 8;
	volatile uint32 GT    : 8;
	volatile uint32 res   : 16;
}GTPRbits_t;

typedef struct
{
	volatile uint32 SBK   	: 1;
	volatile uint32 RWU  	: 1;
	volatile uint32 RE    	: 1;
	volatile uint32 TE    	: 1;
	volatile uint32 IDLEIE  : 1;
	volatile uint32 RXNEIE  : 1;
	volatile uint32 TCIE    : 1;
	volatile uint32 TXEIE 	: 1;
	volatile uint32 PEIE  	: 1;
	volatile uint32 PS  	: 1;
	volatile uint32 PCE	    : 1;
	volatile uint32 WAKE 	: 1;
	volatile uint32 M  		: 1;
	volatile uint32 UE  	: 1;
	volatile uint32 Res0  	: 1;
	volatile uint32 OVER8 	: 1;
	volatile uint32 Res1	: 16;
}CR1bits_t;

typedef struct
{
	volatile uint32 ADD   	: 4;
	volatile uint32 Res0  	: 1;
	volatile uint32 LBDL    : 1;
	volatile uint32 LBDIE   : 1;
	volatile uint32 IDLEIE  : 1;
	volatile uint32 Res1    : 1;
	volatile uint32 LBCL    : 1;
	volatile uint32 CPHA 	: 1;
	volatile uint32 CPOL  	: 1;
	volatile uint32 CLKEN  	: 1;
	volatile uint32 STOP1   : 1;
	volatile uint32 STOP2   : 1;
	volatile uint32 LINEN 	: 1;
	volatile uint32 Res2	: 1;
	volatile uint32 Res3	: 16;
}CR2bits_t;

typedef struct
{
	volatile uint32 EIE   	: 1;
	volatile uint32 IREN  	: 1;
	volatile uint32 IRLP    : 1;
	volatile uint32 HDSEL   : 1;
	volatile uint32 NACK    : 1;
	volatile uint32 SCEN    : 1;
	volatile uint32 DMAR    : 1;
	volatile uint32 DMAT 	: 1;
	volatile uint32 RTSE  	: 1;
	volatile uint32 CTSE  	: 1;
	volatile uint32 CTSIE   : 1;
	volatile uint32 ONEBIT 	: 1;
	volatile uint32 Res0	: 4;
	volatile uint32 Res1	: 16;
}CR3bits_t;

typedef struct
{
	SRbits_t   USART_SR;
	uint32     USART_DR;
	uint32     USART_BRR;
	CR1bits_t  USART_CR1;
	CR2bits_t  USART_CR2;
	CR3bits_t  USART_CR3;
	GTPRbits_t USART_GTPR;

}USART_REG_CFG;
/************************** User Data Types *****************************/
#endif /* MACL_USART_USART_PRIVATE_H_ */
