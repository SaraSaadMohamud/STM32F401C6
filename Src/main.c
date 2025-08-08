/*
 ******************************************************************************
 * @file           : main.c
 * @author         : SARA SAAD MAHMOUD
 * @brief          : Main program body
 ******************************************************************************
*/

#include "main.h"

uint32 RET =E_OK;

pin_cfg LED1 =
{
	.port = GPIO_PORTA,
	.pin = GPIO_PIN0,
	.mode = GPIO_OUTPUE_MODE,
	.speed = MIDUIM_SPEED,
	.pull_type = NO_PULL,
};
pin_cfg LED2 =
{
	.port = GPIO_PORTA,
	.pin = GPIO_PIN1,
	.mode = GPIO_OUTPUE_MODE,
	.speed = MIDUIM_SPEED,
	.pull_type = NO_PULL,
};

pin_cfg BUZZER =
{
	.port = GPIO_PORTA,
	.pin = GPIO_PIN2,
	.mode = GPIO_OUTPUE_MODE,
	.speed = MIDUIM_SPEED,
	.pull_type = NO_PULL,
};


int main(void)
{
   pin_intialize();



/*#if CBL_DEBUG_SELECTOR  ==  BL_DEBUG_FEATURE_ENABLE
	 RET =BL_Print_Message("BOOTLOADER STARTED!!\r\n");
#endif*/



	for(;;)
	{
		RET = LED_TURN_ON(&LED1);
		RET = LED_TURN_ON(&LED2);
		RET = BUZZER_TURN_ON(&BUZZER);
	}


	return(0);
}

void pin_intialize(void)
{
	RET= RCC_INTIALIZE();
	RET = RCC_PERIPHERAL_ENABLE(AHB1, GPIOA_PERIPHERAL);

	RET = LED_INTIALIZE(&LED1);
	RET = LED_INTIALIZE(&LED2);
    RET = BUZZER_INTIATIAZE(&BUZZER);


}

