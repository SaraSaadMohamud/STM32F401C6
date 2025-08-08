 /*
 *******************************************************************************
 * @file           : LED_program.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : LED SOURCE file
 ******************************************************************************
*/

#include "ECUAL/LED/LED_interface.h"


 STD_RETURN_TYPES LED_INTIALIZE(pin_cfg *ptr)
{
	 STD_RETURN_TYPES RET = E_OK;
    if(ptr == NULL)
    {
        RET = E_NOK;
    }
    else
    {
       if((ptr->port) == GPIO_PORTH)
       {
    	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, GPIOH_PERIPHERAL);
       }
       else
       {
    	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, ptr->port);
       }

       RET =  GPIO_PIN_SET_MODE(ptr);
       RET =  GPIO_PIN_SET_OUTPUT_TYPE(ptr);
       RET =  GPIO_PIN_SET_OUTPUT_SPEED(ptr);
       RET =  GPIO_PIN_SET_PULL_TYPE(ptr);
       RET = GPIO_PIN_GET_PIN_LOGIC(ptr, GPIO_LOW);
    }

    return(RET);
}
STD_RETURN_TYPES LED_TURN_ON(pin_cfg *ptr)
{
	 STD_RETURN_TYPES RET = E_OK;
    if(ptr == NULL)
    {
        RET = E_NOK;
    }
    else
    {
		#if  (LED_CONNECTION == LED_ACTIVE_HIGH)
			RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_HIGH);
		#elif  (LED_CONNECTION == LED_ACTIVE_LOW)
			RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_LOW);
		#else
						RET = E_NOK;
		#endif
    }

    return(RET);
}
STD_RETURN_TYPES LED_TURN_OFF(pin_cfg *ptr)
{

     STD_RETURN_TYPES RET = E_OK;
    if(ptr == NULL)
    {
        RET = E_NOK;
    }
    else
    {
		#if  LED_CONNECTION == LED_ACTIVE_HIGH
			 RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_LOW);
		#elif  LED_CONNECTION == LED_ACTIVE_LOW
			RET = GPIO_PIN_SET_PIN_LOGIC(ptr, GPIO_HIGH);
		#else
			RET = E_NOK;
		#endif
    }

    return(RET);
}
STD_RETURN_TYPES LED_TOGGLE(pin_cfg *ptr)
{
	 STD_RETURN_TYPES RET = E_OK;

    if(ptr == NULL)
    {
        RET = E_NOK;
    }
    else
    {
    	RET = GPIO_PIN_TOGGLE_LOGIC(ptr);
    }

    return(RET);
}
