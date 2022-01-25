/*
 *		RCC_config.h
 *      Author: Abd2lrady
 */

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* CLOCK_SOURCE Options 
   --------------------
 	RCC_HSI 			for internal clock
	RCC_HSE_CRYSTAL 	for external clock 
	RCC_HSE_RC 			for external RC clock
	RCC_PLL 			for phase loop 
*/
	
#define RCC_CLOCK_SOURCE RCC_HSI
/*---------------------------------------------------------------*/

/* Choose PLL Input Clock  */
#if RCC_CLOCK_SOURCE == RCC_PLL
/* PLL_CLOCK_SOURCE Options
   ------------------------
   RCC_PLL_INPUT_CLOCK_HSI_DIVBY_2
   RCC_PLL_INPUT_CLOCK_SOURCE_HSE_DIVBY_2
   RCC_PLL_INPUT_CLOCK_SOURCE_HSE
   */
#define RCC_PLL_CLOCK_SOURCE RCC_PLL_INPUT_CLOCK_HSI_DIVBY_2
#endif
/*---------------------------------------------------------------*/

/* Choose PLL Output Multiplication Factor */
#if RCC_CLOCK_SOURCE == RCC_PLL
/* PLL_CLOCK_MULTIPLICATION_FACTOR Options
   ------------------------
   from 2 ... 16
*/
#define RCC_PLL_MUL_FACTOR	(2)
#endif
/*---------------------------------------------------------------*/


#endif