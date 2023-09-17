/**
 ******************************************************************************
 * @file    led.h
 * @author  truongdv
 * @version 1.0
 * @date    22/7/2023
 * @brief
 * @history
 ******************************************************************************/


#ifndef __LED_H
#define __LED_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
typedef enum{
	LED_NUM1 = 0,
	LED_NUM_MAX
}ledNumber;

typedef enum{
	LEVEL_1 = 0,
	LEVEL_2,
	LEVEL_3,
	LEVEL_4,
	LEVEL_MAX
}blinkLevel;

typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
	uint32_t duty;
	uint32_t period;
}Blink_Config;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

#define FREQ_BLINK 50 //Hz

#define LED_ON(port, pin)		HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET)
#define LED_OFF(port, pin)		HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET)

/* Exported functions ------------------------------------------------------- */

void ledBlinkConf(uint8_t ledLevelBlink);

void ledProcessBlink(void);

void ledDimmingProcess(void);






#endif /* __HEADER_FILE_H */
