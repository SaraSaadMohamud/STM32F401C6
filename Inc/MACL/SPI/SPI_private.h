/*
 ******************************************************************************
 * @file           : SPI_PRIVATE.h
 * @author         : SARA SAAD MAHMOUD
 * @brief          : SPI HEADER FILE
 ******************************************************************************
*/

#ifndef MACL_SPI_SPI_PRIVATE_H_
#define MACL_SPI_SPI_PRIVATE_H_
/************** Section: include part *************/

/**************************************************/

/************** Section: Macros *******************/
#define SPI1_STR_ADD        ((volatile uint32*)0x40013000)
#define SPI2_STR_ADD        ((volatile uint32*)0x40003800)
#define SPI3_STR_ADD        ((volatile uint32*)0x40003C00)
#define SPI4_STR_ADD        ((volatile uint32*)0x40013400)

#define SPI1_REG        	((volatile SPI_REG_CFG*)0x40013000)
#define SPI2_REG        	((volatile SPI_REG_CFG*)0x40003800)
#define SPI3_REG        	((volatile SPI_REG_CFG*)0x40003C00)
#define SPI4_REG        	((volatile SPI_REG_CFG*)0x40013400)
/**************************************************/

/************** Section: macro functions **********/


/**************************************************/

/************* ?Section: USER DATA TYPE ***********/
typedef struct
{
	uint32 CPHA_bit 		: 1;
	uint32 CPOL_bit 		: 1;
	uint32 MSTR_bit 		: 1;
	uint32 BR_bit 			: 3;
	uint32 SPE_bit    		: 1;
	uint32 LSBFIRST_bit 	: 1;
	uint32 SSI_bit			: 1;
	uint32 SSM_bit   		: 1;
	uint32 RXONLY_bit 		: 1;
	uint32 DFF_bit 			: 1;
	uint32 CRCNEXT_bit 		: 1;
	uint32 CRCEN_bit 		: 1;
	uint32 BIDIOE_bit 		: 1;
	uint32 BIDIMODE_bit		: 1;
	uint32 Res2_bit 		: 16;

}CR1bits_t_;

typedef struct
{
	uint32 RXDMAEN_bit		: 1;
	uint32 TXDMAEN_bit		: 1;
	uint32 SSOE_bit			: 1;
	uint32 Res0_bit			: 1;
	uint32 FRF_bit			: 1;
	uint32 ERRIE_bit		: 1;
	uint32 RXNEIE_bit		: 1;
	uint32 TXEIE_bit		: 1;
	uint32 Res1_bit		 	: 8;
	uint32 Res2_bit		 	: 16;

}CR2bits_t_;

typedef struct
{
	uint32 RXNE_bit			: 1;
	uint32 TXE_bit			: 1;
	uint32 CHSIDE_bit		: 1;
	uint32 CRCERR_bit		: 1;
	uint32 OVR_bit			: 1;
	uint32 BSY_bit		 	: 1;
	uint32 FRE_bit			: 1;
	uint32 Res0_bit			: 8;
	uint32 Res1_bit		 	: 16;

}SRbits_t_;

typedef struct
{
	uint32 CHLEN_bit		: 1;
	uint32 DATLEN_bit		: 1;
	uint32 CKPOL_bit		: 1;
	uint32 I2SSTD_bit		: 1;
	uint32 Res0_bit			: 1;
	uint32 PCMSYNC_bit		: 1;
	uint32 I2SCFG_bit		: 1;
	uint32 I2SE_bit			: 1;
	uint32 I2SMOD_bit		: 1;
	uint32 RES1_bit			: 4;
	uint32 RES2_bit			: 16;

}CFGRbits_t;


typedef struct
{
	CR1bits_t_  SPI_CR1;
	CR2bits_t_  SPI_CR2;
	SRbits_t_   SPI_SR;
	uint32 		SPI_DR;
	uint32 		SPI_CRCPR;
	uint32 	    SPI_RXCRCR;
	uint32      SPI_TXCRCR;
	CFGRbits_t  SPI_I2SCFGR;
	uint32      SPI_I2SPR;

}SPI_REG_CFG;

/**************************************************/

/*************  Section: Function Prototype *******/

/**************************************************/

#endif /* MACL_SPI_SPI_PRIVATE_H_ */
