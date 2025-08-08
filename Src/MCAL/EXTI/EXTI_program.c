 /*
 *******************************************************************************
 * @file           : EXTI_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : EXTI source file
 ******************************************************************************
*/

#include "MACL/EXTI/EXTI_interface.h"
void (*G_pf[16])(void);

/************************** FUNCTION DIFINATION ****************************/
STD_RETURN_TYPES EXTI_INITIALIZE(EXTI_LINES line,port_t port,EXTI_TRIGGER_SELE sele_trg )
{
	STD_RETURN_TYPES RET = E_OK;

	if(line > EXTI_LINE)
	{
		RET = E_NOK;
	}
	else
	{
		RET = EXTI_SET_TRIGERR(line,sele_trg);
		RET = EXTI_SET_INTERRUPT_PORT(line,port);
		RET = EXTI_ENABLE_LINE(line);
	}

	return(RET);
}
STD_RETURN_TYPES EXTI_SET_TRIGERR(EXTI_LINES line, EXTI_TRIGGER_SELE sele_trg)
{
	STD_RETURN_TYPES RET = E_OK;

	if(line > EXTI_LINE)
	{
		RET = E_NOK;
	}
	else
	{
		switch(sele_trg)
		{
			case RISING_TRIGGER:
				SET_BIT((EXTI_REG ->EXTI_RTSR),line);
				CLEAR_BIT((EXTI_REG ->EXTI_FTSR),line);
				break;
			case FALLING_TRIGGER:
				SET_BIT((EXTI_REG ->EXTI_FTSR),line);
				CLEAR_BIT((EXTI_REG ->EXTI_RTSR),line);
				break;
			case ONCHANGE_TRIGGER:
				SET_BIT((EXTI_REG ->EXTI_RTSR),line);
				SET_BIT((EXTI_REG ->EXTI_FTSR),line);
				break;
			default:
				RET= E_NOK;
				break;

		}
	}

	return(RET);
}
STD_RETURN_TYPES EXTI_ENABLE_LINE(EXTI_LINES line)
{
	STD_RETURN_TYPES RET = E_OK;

	if(line > EXTI_LINE)
	{
		RET = E_NOK;
	}
	else
	{
		SET_BIT((EXTI_REG -> EXTI_IMR), line);
	}

	return(RET);
}
STD_RETURN_TYPES EXTI_DISABLE_LINE(EXTI_LINES line)
{
	STD_RETURN_TYPES RET = E_OK;

	if(line > EXTI_LINE)
	{
		RET = E_NOK;
	}
	else
	{
		CLEAR_BIT((EXTI_REG -> EXTI_IMR), line);
	}

	return(RET);
}


STD_RETURN_TYPES EXTI_SET_SW_TRIGERR(EXTI_LINES line)
{
	STD_RETURN_TYPES RET = E_OK;

	if(line > EXTI_LINE)
	{
		RET = E_NOK;
	}
	else
	{
		SET_BIT((EXTI_REG->EXTI_SWIER),line);
	}
}

STD_RETURN_TYPES EXTI_SET_INTERRUPT_PORT(EXTI_LINES line,uint8 port)
{
	STD_RETURN_TYPES RET = E_OK;

	if(line > EXTI_LINE)
	{
		RET= E_NOK;
	}
	else
	{
		RCC_PERIPHERAL_ENABLE(APB2, SYSCFG_PERIPHERAL);
		SYS_CFG_REG->SYSCFG_EXTICR[line/SYS_CFG_DIV] &= ~(port << ( 4*(line%SYS_CFG_DIV)));
		SYS_CFG_REG->SYSCFG_EXTICR[line/SYS_CFG_DIV] |=  (port << ( 4*(line%SYS_CFG_DIV)));
	}
}

STD_RETURN_TYPES EXTI_CALLBACK_INT(EXTI_LINES line,void (*pf)(void))
{
	STD_RETURN_TYPES RET = E_OK;
	if(NULL == pf)
	{
		RET = E_NOK;
	}
	else
	{
		G_pf[line] = pf;
	}

}

void EXTI0_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[0]();
	}
}
void EXTI1_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[1]();
	}
}

void EXTI2_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[2]();
	}
}

void EXTI3_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[3]();
	}
}

void EXTI4_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[4]();
	}
}

void EXTI5_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[5]();
	}
}

void EXTI6_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[6]();
	}
}

void EXTI7_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[7]();
	}
}

void EXTI8_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[8]();
	}
}

void EXTI9_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[10]();
	}
}

void EXTI10_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[10]();
	}
}

void EXTI11_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[11]();
	}
}

void EXTI12_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[12]();
	}
}

void EXTI13_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[13]();
	}
}

void EXTI14_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[14]();
	}
}

void EXTI15_IRQHandler()
{
	if(NULL != G_pf)
	{
		G_pf[15]();
	}
}
/************************** FUNCTION DIFINATION ****************************/
