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
	uint32_t duty;
	uint32_t period;
}Blink_Config;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

#define FREQ_BLINK 100 //Hz

#define LED_ON
#define LED_OFF

/* Exported functions ------------------------------------------------------- */

void setLevelBlink();








#endif /* __HEADER_FILE_H */
