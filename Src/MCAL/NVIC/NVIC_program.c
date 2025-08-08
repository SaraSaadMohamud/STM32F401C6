 /*
 *******************************************************************************
 * @file           : NVIC_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : NVIC source file
 ******************************************************************************
*/

/******************************* include part *********************************/
#include "MACL/NVIC/NVIC_interface.h"
/******************************* include part *********************************/


/************************** function difination ********************************/

STD_RETURN_TYPES NVIC_EnableIRQ(IRQn_Type IRQn)
{
	STD_RETURN_TYPES RET= E_OK;

	if(IRQn>0)
	{
		SET_BIT((NVIC_REG->NVIC_ISER[(IRQn / REG_NUMBER_SELE )]),(IRQn % REG_NUMBER_SELE));
	}
	else
	{
		RET = E_NOK;
	}
	return(RET);
}

STD_RETURN_TYPES NVIC_DisableIRQ(IRQn_Type IRQn)
{
	STD_RETURN_TYPES RET= E_OK;

	if(IRQn >= 0)
	{
		SET_BIT((NVIC_REG->NVIC_ICER[(IRQn / REG_NUMBER_SELE )]),(IRQn % REG_NUMBER_SELE));
	}
	else
	{
		RET = E_NOK;
	}
	return(RET);
}

STD_RETURN_TYPES NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	STD_RETURN_TYPES RET= E_OK;

	if(IRQn >= 0)
	{
		SET_BIT((NVIC_REG->NVIC_ISPR[(IRQn / REG_NUMBER_SELE )]),(IRQn % REG_NUMBER_SELE));
	}
	else
	{
		RET = E_NOK;
	}
	return(RET);
}

STD_RETURN_TYPES NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	STD_RETURN_TYPES RET= E_OK;

	if(IRQn >= 0)
	{
		SET_BIT((NVIC_REG->NVIC_ICPR[(IRQn / REG_NUMBER_SELE )]),(IRQn % REG_NUMBER_SELE));
	}
	else
	{
		RET = E_NOK;
	}

	return(RET);
}

STD_RETURN_TYPES NVIC_GetPendingIRQ(IRQn_Type IRQn, uint8 *pending_status)
{
	STD_RETURN_TYPES RET= E_OK;

	if(IRQn >= 0)
	{
		*pending_status = READ_BIT((NVIC_REG->NVIC_ICPR[(IRQn / REG_NUMBER_SELE )]),(IRQn % REG_NUMBER_SELE));
	}
	else
	{
		RET = E_NOK;
	}

	return(RET);
}

STD_RETURN_TYPES NVIC_GetActiveIRQ(IRQn_Type IRQn, uint8 *Active_status)
{
	STD_RETURN_TYPES RET= E_OK;

	if(IRQn >= 0)
	{
		*Active_status = READ_BIT((NVIC_REG->NVIC_IABR[(IRQn / REG_NUMBER_SELE )]),(IRQn % REG_NUMBER_SELE));
	}
	else
	{
		RET = E_NOK;
	}

	return(RET);
}

STD_RETURN_TYPES NVIC_SetPriority(IRQn_Type IRQn,uint8 priorty)
{
	STD_RETURN_TYPES RET= E_OK;

	if(priorty <= 15)
	{
		(NVIC_REG->NVIC_IPR[IRQn] )= (priorty << PRIORITY_SHIFT_NUM );
		RET = SYS_CTRL_Interrupt_SET_priority_level(SYS_CTRL_16SUBGROUB_0GROUB);
	}
	else
	{
		RET = E_NOK;
	}

	return(RET);
}

STD_RETURN_TYPES NVIC_GetPriority(IRQn_Type IRQn,uint8 *priorty)
{
	STD_RETURN_TYPES RET= E_OK;

	if(IRQn <= 0)
	{
		priorty = ((NVIC_REG->NVIC_IPR[IRQn]) << PRIORITY_SHIFT_NUM) ;
	}
	else
	{
		RET = E_NOK;
	}

	return(RET);
}


STD_RETURN_TYPES NVIC_Set_GLOBALPriority(IRQn_Type IRQn,group_priority groub, subgroup_priority sub_groub)
{
	STD_RETURN_TYPES  RET = E_OK;
	uint32 priority_eq = (sub_groub | (groub << ((SYS_CTRL_4SUBGROUB_4GROUB - SYS_CTRL_0SUBGROUB_16GROUB)/0x100)));

	#if  PRIORTY_GROUP == SYS_CTRL_0SUBGROUB_16GROUB
		if((groub<= GROUP16) &&(sub_groub == SUBGROUP1))
		{
			(NVIC_REG->NVIC_IPR[IRQn]) = (priority_eq << PRIORITY_SHIFT_NUM);
		}
		else
		{
			RET == E_NOK;
		}
	#elif  PRIORTY_GROUP == SYS_CTRL_2SUBGROUB_8GROUB
		if((groub<= GROUP8) &&(sub_groub <= SUBGROUP2))
		{
			(NVIC_REG->NVIC_IPR[IRQn]) = (priority_eq << PRIORITY_SHIFT_NUM);
		}
		else
		{
			RET == E_NOK;
		}
	#elif  PRIORTY_GROUP == SYS_CTRL_4SUBGROUB_4GROUB
		if((groub<= GROUP4) &&(sub_groub <= SUBGROUP4))
		{
			(NVIC_REG->NVIC_IPR[IRQn]) = (priority_eq << PRIORITY_SHIFT_NUM);
		}
		else
		{
			RET == E_NOK;
		}
	#elif  PRIORTY_GROUP == SYS_CTRL_8SUBGROUB_2GROUB
		if((groub<= GROUP2) &&(sub_groub <= SUBGROUP8))
		{
			(NVIC_REG->NVIC_IPR[IRQn]) = (priority_eq << PRIORITY_SHIFT_NUM);
		}
		else
		{
			RET == E_NOK;
		}
	#elif  PRIORTY_GROUP == SYS_CTRL_16SUBGROUB_0GROUB
		if((groub<= GROUP1) &&(sub_groub <= SUBGROUP16))
		{
			(NVIC_REG->NVIC_IPR[IRQn]) = (priority_eq << PRIORITY_SHIFT_NUM);
		}
		else
		{
			RET == E_NOK;
		}
	#else
		RET = E_NOK;
	#endif
	return(RET);
}
/************************** function difination ********************************/
