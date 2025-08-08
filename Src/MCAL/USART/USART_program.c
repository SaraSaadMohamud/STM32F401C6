/*
 ******************************************************************************
 * @file           : USART_programm.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : USART source file
 ******************************************************************************
*/

#include "../Inc/MACL/USART/USART_interface.h"

static USART_REG_CFG* USART_GET_HANDLER(uint8 index);
static STD_RETURN_TYPES USART_CLOCK_ENABLE(uint8 index);

STD_RETURN_TYPES USART_INIT(uint8 index)
{
	STD_RETURN_TYPES RET = E_OK;
	USART_REG_CFG *U_Handeler = USART_GET_HANDLER(index);

	RET = USART_CLOCK_ENABLE(index);

	RET = USART_SELECT_BAUD_RATE(index,	BR_9600);

	U_Handeler->USART_CR1.TE = TX_ENABLE;
	U_Handeler->USART_CR1.RE = RX_ENABLE;

	U_Handeler->USART_CR1.M = DATA_8BIT;
	U_Handeler->USART_CR1.OVER8 = SAMPLE_16MODE;
	U_Handeler->USART_CR1.PCE = PARITY_DISABLE;



	U_Handeler->USART_CR2.STOP1 =0;
	U_Handeler->USART_CR2.STOP2 =0;

	U_Handeler->USART_CR1.UE = USART_ENABLE;

	return(RET);
}

STD_RETURN_TYPES USART_READ_DATA(uint8 index,uint32 *data)
{
	STD_RETURN_TYPES RET = E_OK;
	USART_REG_CFG *U_Handeler = USART_GET_HANDLER(index);

	if(NULL == data)
	{
		RET = E_NOK;
	}
	else
	{
		*data = U_Handeler->USART_DR;
	}

	return(RET);
}
STD_RETURN_TYPES USART_SEND_DATA(uint8 index, uint8 data)
{
	STD_RETURN_TYPES RET = E_OK;
	USART_REG_CFG *U_Handeler = USART_GET_HANDLER(index);

	while(!(U_Handeler->USART_SR.TXE));

	*((volatile uint32 *)0x40011004) = data;
	return(RET);
}

STD_RETURN_TYPES USART_RECIVE_DATA(uint8 index,uint8 *data)
{
	STD_RETURN_TYPES RET = E_OK;
	USART_REG_CFG *U_Handeler = USART_GET_HANDLER(index);

	if(NULL == data)
	{
		RET = E_NOK;
	}
	else
	{
		while(0 ==(U_Handeler->USART_SR.RXNE));
		*data = ((uint8)U_Handeler->USART_DR );
	}

	return(RET);
}

STD_RETURN_TYPES USART_RECIVE_STRING(uint8 index,uint8 *data)
{
	STD_RETURN_TYPES RET = E_OK;
	uint8 i =0 ;
	uint8 ch;
	if(NULL == data)
	{
		RET = E_NOK;
	}
	else
	{
		while(1)
		{
			RET = USART_RECIVE_DATA(index, &ch);

			if(ch == '\n' || ch == '\r')
			{
				break;
			}
			data[i] = ch;
			i++;
		}

		data[i] = '\0';

	return(RET);
	}
}

STD_RETURN_TYPES USART_SEND_STRING(uint8 index,uint8 *data)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == data)
	{
		RET = E_NOK;
	}
	else
	{
		for(int i=0 ; data[i]!= '\0' ;i++)
		{
			RET = USART_SEND_DATA(index,data[i]);
			for (volatile int j = 0; j < 100000; j++);
		}
	}

	return(RET);
}
static USART_REG_CFG* USART_GET_HANDLER(uint8 index)
{
	STD_RETURN_TYPES RET = E_OK;
	USART_REG_CFG *L_USART_NUM = USERT1_REG;

	switch(index)
	{
	case USART1_ENABLE:
		L_USART_NUM = USERT1_REG;
		break;
	case USART2_ENABLE:
		L_USART_NUM = USERT2_REG;
		break;
	case USART6_ENABLE:
		L_USART_NUM = USERT6_REG;
		break;
	default:
		RET = E_NOK;
	}
	return(L_USART_NUM);
}

STD_RETURN_TYPES USART_SELECT_BAUD_RATE(uint8 index,BR_CFG BRATE)
{
	STD_RETURN_TYPES RET = E_OK;
	USART_REG_CFG *U_Handeler = USART_GET_HANDLER(index);

	switch( BRATE)
	{
	case BR_2400:
		switch(U_Handeler->USART_CR1.OVER8)
		{
		case SAMPLE_8MODE:
			U_Handeler->USART_BRR = (( CLK16_8SAM_2400_Mantissa << 3) | CLK16_8SAMP_2400_Fraction);
			break;

		case SAMPLE_16MODE:
			U_Handeler->USART_BRR = (( CLK16_16SAMP_2400_Mantissa << 4) | CLK16_16SAMP_2400_Fraction);
			break;

		default:
			RET = E_NOK;
			break;
		}
		break;
	case BR_9600:
		switch(U_Handeler->USART_CR1.OVER8)
		{
		case SAMPLE_8MODE:
			U_Handeler->USART_BRR = ((CLK16_8SAM_9600_Mantissa << 3) | CLK16_8SAMP_9600_Fraction);
			break;

		case SAMPLE_16MODE:
			U_Handeler->USART_BRR = ((CLK16_16SAMP_9600_Mantissa << 4) | CLK16_16SAMP_9600_Fraction);
			break;

		default:
			RET = E_NOK;
			break;
		}
		break;
	case BR_19300:
		switch(U_Handeler->USART_CR1.OVER8)
		{
		case SAMPLE_8MODE:
			U_Handeler->USART_BRR = ((CLK16_8SAM_19300_Mantissa << 3) | CLK16_8SAMP_19300_Fraction );
			break;

		case SAMPLE_16MODE:
			U_Handeler->USART_BRR = ((CLK16_16SAMP_19300_Mantissa << 4) | CLK16_16SAMP_19300_Fraction );
			break;

		default:
			RET = E_NOK;
			break;
		}
		break;
	default:
		RET = E_NOK;
		break;
	}

	return(RET);
}

static STD_RETURN_TYPES USART_CLOCK_ENABLE(uint8 index)
{
	 STD_RETURN_TYPES RET = E_OK;

	    switch(index)
	    {
	    case USART1_ENABLE:
	    	RET = RCC_PERIPHERAL_ENABLE(APB2, USART1_PERIPHERAL);
	    	break;
	    case USART2_ENABLE:
	    	RET = RCC_PERIPHERAL_ENABLE(APB1, USART2_PERIPHERAL);
	    	break;
	    case USART6_ENABLE:
	    	RET = RCC_PERIPHERAL_ENABLE(APB2, USART6_PERIPHERAL);
	    	break;
		default:
			RET = E_NOK;
			break;
	    }

	    return(RET);
}
