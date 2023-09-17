/**
 ******************************************************************************
 * @file    led.c
 * @author  truongdv
 * @version 1.0
 * @date
 * @brief
 * @history
 ******************************************************************************/
/*******************************************************************************
 * Include
 ******************************************************************************/
#include "led.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

 /*******************************************************************************
 * Variables
 ******************************************************************************/

Blink_Config conf[LED_NUM_MAX] = {0};

GPIO_TypeDef *ledPort[LED_NUM_MAX] = {Led1_GPIO_Port};
uint16_t ledPin[LED_NUM_MAX] = {Led1_Pin};



uint32_t timeStartBlink[LED_NUM_MAX] = {0};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

void ledProcessBlink(void){
	for(uint8_t i = 0; i < (uint8_t)LED_NUM_MAX; i++){
		if( (uint32_t)(HAL_GetTick() - timeStartBlink[i]) > conf[i].period){
			LED_ON(conf[i].port, conf[i].pin);
			timeStartBlink[i] = HAL_GetTick();
		}
		else if((uint32_t)(HAL_GetTick() - timeStartBlink[i]) > conf[i].duty)
		{
			LED_OFF(conf[i].port, conf[i].pin);
		}
	}

}

void ledBlinkConf(uint8_t ledLevelBlink){
	for(uint8_t i = 0; i < LED_NUM_MAX; i++)
	{
		conf[i].period = (1*1000)/FREQ_BLINK;
		conf[i].duty = (conf[i].period * ledLevelBlink)/LEVEL_MAX;
		conf[i].port = ledPort[i];
		conf[i].pin = ledPin[i];
	}
}

void ledDimmingProcess(void){
	for(uint8_t level = 0; level <= (uint8_t)LEVEL_MAX; level ++){
		ledBlinkConf(level);
		static uint32_t timeStartBlink;
		timeStartBlink = (uint32_t)HAL_GetTick();
		while((uint32_t)(HAL_GetTick() - timeStartBlink) < 2000){
			ledProcessBlink();
			if((uint32_t)(HAL_GetTick() - timeStartBlink) >= 2000){
				break;
			}
		}
	}
}


/***********************************************/
