 /*
 *******************************************************************************
 * @file           : GPIO_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : GPIO SOURCE file
 ******************************************************************************
*/

#include <MACL/GPiO/GPiO_interface.h>

uint32 *MODE_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_SMODER),(uint32*)(GPIOB_STR_ADD+GPIOX_SMODER),
					   (uint32*)(GPIOC_STR_ADD+GPIOX_SMODER),(uint32*)(GPIOD_STR_ADD+GPIOX_SMODER),
					   (uint32*)(GPIOE_STR_ADD+GPIOX_SMODER),(uint32*)(GPIOH_STR_ADD+GPIOX_SMODER)};

uint32 *ODR_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_ODR),(uint32*)(GPIOB_STR_ADD+GPIOX_ODR),
					  (uint32*)(GPIOC_STR_ADD+GPIOX_ODR),(uint32*)(GPIOD_STR_ADD+GPIOX_ODR),
					  (uint32*)(GPIOE_STR_ADD+GPIOX_ODR),(uint32*)(GPIOH_STR_ADD+GPIOX_ODR)};

uint32 *IDR_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_IDR),(uint32*)(GPIOB_STR_ADD+GPIOX_IDR),
		   	   	   	  (uint32*)(GPIOC_STR_ADD+GPIOX_IDR),(uint32*)(GPIOD_STR_ADD+GPIOX_IDR),
					  (uint32*)(GPIOE_STR_ADD+GPIOX_IDR),(uint32*)(GPIOH_STR_ADD+GPIOX_IDR)};

uint32 *OTYPER_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_OTYPER),(uint32*)(GPIOB_STR_ADD+GPIOX_OTYPER),
		   	   	   	   	 (uint32*)(GPIOC_STR_ADD+GPIOX_OTYPER),(uint32*)(GPIOD_STR_ADD+GPIOX_OTYPER),
						 (uint32*)(GPIOE_STR_ADD+GPIOX_OTYPER),(uint32*)(GPIOH_STR_ADD+GPIOX_OTYPER)};


uint32 *OSPEEDR_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_OSPEEDR),(uint32*)(GPIOB_STR_ADD+GPIOX_OSPEEDR),
						  (uint32*)(GPIOC_STR_ADD+GPIOX_OSPEEDR),(uint32*)(GPIOD_STR_ADD+GPIOX_OSPEEDR),
		                  (uint32*)(GPIOE_STR_ADD+GPIOX_OSPEEDR),(uint32*)(GPIOH_STR_ADD+GPIOX_OSPEEDR)};

uint32 *PUPDR_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_PUPDR),(uint32*)(GPIOB_STR_ADD+GPIOX_PUPDR),
						(uint32*)(GPIOC_STR_ADD+GPIOX_PUPDR),(uint32*)(GPIOD_STR_ADD+GPIOX_PUPDR),
						(uint32*)(GPIOE_STR_ADD+GPIOX_PUPDR),(uint32*)(GPIOH_STR_ADD+GPIOX_PUPDR)};

uint32 *LCKR_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_LCKR),(uint32*)(GPIOB_STR_ADD+GPIOX_LCKR),
		   	   	   	   (uint32*)(GPIOC_STR_ADD+GPIOX_LCKR),(uint32*)(GPIOD_STR_ADD+GPIOX_LCKR),
					   (uint32*)(GPIOE_STR_ADD+GPIOX_LCKR),(uint32*)(GPIOH_STR_ADD+GPIOX_LCKR)};

uint32 *BSRR_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_BSRR),(uint32*)(GPIOB_STR_ADD+GPIOX_BSRR),
		   	   	   	   (uint32*)(GPIOC_STR_ADD+GPIOX_BSRR),(uint32*)(GPIOD_STR_ADD+GPIOX_BSRR),
					   (uint32*)(GPIOE_STR_ADD+GPIOX_BSRR),(uint32*)(GPIOH_STR_ADD+GPIOX_BSRR)};

uint32 *AFRL_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_AFRL),(uint32*)(GPIOB_STR_ADD+GPIOX_AFRL),
		   	   	   	   (uint32*)(GPIOC_STR_ADD+GPIOX_AFRL),(uint32*)(GPIOD_STR_ADD+GPIOX_AFRL),
					   (uint32*)(GPIOE_STR_ADD+GPIOX_AFRL),(uint32*)(GPIOH_STR_ADD+GPIOX_AFRL)};

uint32 *AFRH_REG[6] = {(uint32*)(GPIOA_STR_ADD+GPIOX_AFRH),(uint32*)(GPIOB_STR_ADD+GPIOX_AFRH),
		   	   	   	   (uint32*)(GPIOC_STR_ADD+GPIOX_AFRH),(uint32*)(GPIOD_STR_ADD+GPIOX_AFRH),
					   (uint32*)(GPIOE_STR_ADD+GPIOX_AFRH),(uint32*)(GPIOH_STR_ADD+GPIOX_AFRH)};


STD_RETURN_TYPES GPIO_PIN_INPUT_CFG(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		RET = GPIO_PIN_SET_MODE(ptr);
		RET = GPIO_PIN_SET_PULL_TYPE(ptr);
	}
	return(RET);
}
STD_RETURN_TYPES GPIO_PIN_OUTPUT_CFG(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		RET = GPIO_PIN_SET_MODE(ptr);
		RET = GPIO_PIN_SET_OUTPUT_SPEED(ptr);
		RET = GPIO_PIN_SET_OUTPUT_TYPE(ptr);
		RET = GPIO_PIN_SET_PULL_TYPE(ptr);
	}
	return(RET);
}
STD_RETURN_TYPES GPIO_PIN_SET_MODE(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		switch(ptr ->mode)
		{
			case GPIO_INPUT_MODE:
				CLEAR_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin)));	 /*PIN[0]*/
				CLEAR_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin))+1);  /*PIN[1]*/
				break;
			case GPIO_OUTPUE_MODE:
				SET_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin)));	 	 /*PIN[0]*/
				CLEAR_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin))+1);  /*PIN[1]*/
				break;
			case GPIO_AF_MODE:
				CLEAR_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin)));	 /*PIN[0]*/
				SET_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin))+1);  	 /*PIN[1]*/
				break;
			case GPIO_ANALOG_MODE:
				SET_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin)));	   	 /*PIN[0]*/
				SET_BIT(*(MODE_REG[ptr->port]),(2*(ptr->pin))+1);    /*PIN[1]*/
				break;
			default:
				RET = E_NOK;
				break;
		}
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_SET_OUTPUT_TYPE(pin_cfg *ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		switch(ptr ->out_type)
		{
			case PUSH_PULL_OUTPUT_TYPE:
				CLEAR_BIT(*(OTYPER_REG[ptr->port]),(ptr->pin));
				break;
			case OPEN_DRAIN_OUTPUT_TYPE:
				SET_BIT(*(OTYPER_REG[ptr->port]),(ptr->pin));
				break;
			default:
				RET = E_NOK;
				break;
		}
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_SET_OUTPUT_SPEED(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		switch(ptr ->speed)
		{
			case LOW_SPEED:
				CLEAR_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin)));	 /*PIN[0]*/
				CLEAR_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin))+1);  /*PIN[1]*/
				break;
			case MIDUIM_SPEED:
				SET_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin)));	 	 /*PIN[0]*/
				CLEAR_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin))+1);  /*PIN[1]*/
				break;
			case HIGH_SPEED:
				CLEAR_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin)));	 /*PIN[0]*/
				SET_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin))+1);  	 /*PIN[1]*/
				break;
			case VERY_HIGH_SPEED:
				SET_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin)));	   	 /*PIN[0]*/
				SET_BIT(*(OSPEEDR_REG[ptr->port]),(2*(ptr->pin))+1);    /*PIN[1]*/
				break;
			default:
				RET = E_NOK;
				break;
		}
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_SET_PULL_TYPE(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		switch(ptr -> pull_type)
		{
			case NO_PULL:
				CLEAR_BIT(*(PUPDR_REG[ptr->port]),(2*(ptr->pin)));	     /*PIN[0]*/
				CLEAR_BIT(*(PUPDR_REG[ptr->port]),(2*(ptr->pin))+1);     /*PIN[1]*/
				break;
			case PULL_UP:
				SET_BIT(*(PUPDR_REG[ptr->port]),(2*(ptr->pin)));	 	 /*PIN[0]*/
				CLEAR_BIT(*(PUPDR_REG[ptr->port]),(2*(ptr->pin))+1);     /*PIN[1]*/
				break;
			case PULL_DOWN:
				CLEAR_BIT(*(PUPDR_REG[ptr->port]),(2*(ptr->pin)));	     /*PIN[0]*/
				SET_BIT(*(PUPDR_REG[ptr->port]),(2*(ptr->pin))+1);  	 /*PIN[1]*/
				break;
			default:
				RET = E_NOK;
				break;
		}
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_GET_PIN_LOGIC(pin_cfg * ptr, logic_t *logic)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		* logic = READ_BIT(*(IDR_REG[ptr->port]),(ptr->pin));
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_SET_PIN_LOGIC(pin_cfg * ptr, logic_t logic)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		switch(logic)
		{
		case GPIO_LOW:
			CLEAR_BIT(*(ODR_REG[ptr->port]),(ptr->pin));
			break;
		case GPIO_HIGH:
			SET_BIT(*(ODR_REG[ptr->port]),(ptr->pin));
			break;
		default:
			RET = E_NOK;
			break;
		}
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_MODE_LOOKED(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		SET_BIT(*(LCKR_REG[ptr->port]),ptr->pin);
		SET_BIT(*(LCKR_REG[ptr->port]),LOCKED_PIN);
		while(!READ_BIT(*(LCKR_REG[ptr->port]),LOCKED_PIN));
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_SET_BIT(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		READ_BIT(*BSRR_REG[ptr->port],ptr->pin);
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_CLEAR_BIT(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		READ_BIT(*BSRR_REG[ptr->port],(ptr->pin + 16));
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_SET_AFPIN(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;

	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		if((ptr->pin) < GPIO_PIN8)
		{
			uint32 mask = 0xF << ((ptr->pin) * 4);
			*(AFRL_REG[ptr->port]) &= ~mask;
			*(AFRL_REG[ptr->port]) |= ((ptr->AF_PIN & 0xF) << ((ptr->pin) * 4));
		}
		else if((ptr->pin) <= GPIO_PIN15)
		{
			uint32 shift = (ptr->pin - 8) * 4;
			uint32 mask = 0xF << shift;
			*(AFRH_REG[ptr->port]) &= ~mask;
			*(AFRH_REG[ptr->port]) |= ((ptr->AF_PIN & 0xF) << shift);
		}
		else
		{
			RET = E_NOK;
		}
	}

	return(RET);
}

STD_RETURN_TYPES GPIO_PIN_TOGGLE_LOGIC(pin_cfg * ptr)
{
	STD_RETURN_TYPES RET = E_OK;
    logic_t logic_state = GPIO_LOW;
	if(NULL == ptr)
	{
		RET = E_NOK;
	}
	else
	{
		GPIO_PIN_GET_PIN_LOGIC(ptr,&logic_state);
		RET = GPIO_PIN_SET_PIN_LOGIC(ptr,!logic_state);
	}

	return(RET);
}
