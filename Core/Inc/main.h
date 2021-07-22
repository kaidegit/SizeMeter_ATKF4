/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TOUCH_CS_Pin GPIO_PIN_13
#define TOUCH_CS_GPIO_Port GPIOC
#define TOF_TX_Pin GPIO_PIN_2
#define TOF_TX_GPIO_Port GPIOA
#define TOF_RX_Pin GPIO_PIN_3
#define TOF_RX_GPIO_Port GPIOA
#define TOUCH_SCK_Pin GPIO_PIN_0
#define TOUCH_SCK_GPIO_Port GPIOB
#define TOUCH_PEN_Pin GPIO_PIN_1
#define TOUCH_PEN_GPIO_Port GPIOB
#define TOUCH_MISO_Pin GPIO_PIN_2
#define TOUCH_MISO_GPIO_Port GPIOB
#define TOUCH_MOSI_Pin GPIO_PIN_11
#define TOUCH_MOSI_GPIO_Port GPIOF
#define PS_TX_Pin GPIO_PIN_10
#define PS_TX_GPIO_Port GPIOB
#define LCD_BL_Pin GPIO_PIN_15
#define LCD_BL_GPIO_Port GPIOB
#define L_MOTOR_DIR_Pin GPIO_PIN_6
#define L_MOTOR_DIR_GPIO_Port GPIOG
#define H_MOTOR_DIR_Pin GPIO_PIN_7
#define H_MOTOR_DIR_GPIO_Port GPIOG
#define L_MOTOR_EN_Pin GPIO_PIN_8
#define L_MOTOR_EN_GPIO_Port GPIOG
#define L_MOTOR_Pin GPIO_PIN_8
#define L_MOTOR_GPIO_Port GPIOC
#define H_MOTOR_Pin GPIO_PIN_9
#define H_MOTOR_GPIO_Port GPIOC
#define DBG_TX_Pin GPIO_PIN_9
#define DBG_TX_GPIO_Port GPIOA
#define DBG_RX_Pin GPIO_PIN_10
#define DBG_RX_GPIO_Port GPIOA
#define H_MOTOR_EN_Pin GPIO_PIN_11
#define H_MOTOR_EN_GPIO_Port GPIOA
#define PS_RX_Pin GPIO_PIN_11
#define PS_RX_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
