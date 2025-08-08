 /*
 *******************************************************************************
 * @file           : MOTOR_PROGRAM.C
 * @author         : SARA SAAD MAHMOUD
 * @brief          : MOTOR SOURCE file
 ******************************************************************************
*/

#include <ECUAL/MOTOR/MOTOR_interface.h>

STD_RETURN_TYPES DC_MOTOR_INTIALIZE(motor_cfg_t *ptr)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
        for(int i=0 ; i<2 ; i++)
        {
            if((ptr->motor_pin[i].port) == GPIO_PORTH)
            {
         	   RET =  RCC_PERIPHERAL_ENABLE(AHB1, GPIOH_PERIPHERAL);
            }
            else
            {
         	   RET =  RCC_PERIPHERAL_ENABLE(AHB1,(ptr->motor_pin[i].port));
            }

            RET =  GPIO_PIN_SET_MODE(&(ptr->motor_pin[i]));
            RET =  GPIO_PIN_SET_OUTPUT_TYPE(&(ptr->motor_pin[i]));
            RET =  GPIO_PIN_SET_OUTPUT_SPEED(&(ptr->motor_pin[i]));
            RET =  GPIO_PIN_SET_PULL_TYPE(&(ptr->motor_pin[i]));
            RET = GPIO_PIN_GET_PIN_LOGIC(&(ptr->motor_pin[i]), GPIO_LOW);
        }

    }
    return(RET);
}
STD_RETURN_TYPES DC_MOTOR_TURN_RIGHT(motor_cfg_t *ptr) // 5 0
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
        RET =  GPIO_PIN_SET_PIN_LOGIC(&(ptr->motor_pin[MOTOR_PIN1]),GPIO_HIGH);
        RET =  GPIO_PIN_SET_PIN_LOGIC(&(ptr->motor_pin[MOTOR_PIN2]),GPIO_LOW);
    }
    return(RET);
}
STD_RETURN_TYPES DC_MOTOR_TURN_LEFT(motor_cfg_t *ptr) //0  // 5
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
        RET =  GPIO_PIN_SET_PIN_LOGIC(&(ptr->motor_pin[MOTOR_PIN1]),GPIO_LOW);
        RET =  GPIO_PIN_SET_PIN_LOGIC(&(ptr->motor_pin[MOTOR_PIN2]),GPIO_HIGH);
    }
    return(RET);
}
STD_RETURN_TYPES DC_MOTOR_TURN_OFF(motor_cfg_t *ptr)
{
    STD_RETURN_TYPES RET = E_OK;
    if(NULL == ptr)
    {
        RET = E_NOK;
    }
    else
    {
        RET =  GPIO_PIN_SET_PIN_LOGIC(&(ptr->motor_pin[MOTOR_PIN1]),GPIO_HIGH);
        RET =  GPIO_PIN_SET_PIN_LOGIC(&(ptr->motor_pin[MOTOR_PIN2]),GPIO_HIGH);
    }
    return(RET);
}
