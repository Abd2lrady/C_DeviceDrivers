/*
 *		RCC_private.h
 *      Author: Abd2lrady
 */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* RCC Register Definitions
--------------------------*/
#define RCC_CR 			*((volatile u32 *)0x40021000)
#define RCC_CFGR 		*((volatile u32 *)0x40021004)
#define RCC_CIR 		*((volatile u32 *)0x40021008)
#define RCC_APB2RSTR 	*((volatile u32 *)0x4002100c)
#define RCC_APB1RSTR 	*((volatile u32 *)0x40021010)
#define RCC_AHBENR 		*((volatile u32 *)0x40021014)
#define RCC_APB2ENR 	*((volatile u32 *)0x40021018)
#define RCC_APB1ENR 	*((volatile u32 *)0x4002101c)
#define RCC_BDCR 		*((volatile u32 *)0x40021020)
#define RCC_CSR 		*((volatile u32 *)0x40021024)

/* RCC_CR Register Bits Postions
-------------------------------*/
#define HSION 			0
#define HSIRDY 			1
#define HSITRIM 		3
#define HSEON 			16
#define HSERDY 			17
#define HSEBYP			18
#define CSSON			19
#define PLLON			24
#define PLLRDY			25

/* RCC_CFGR Register Bits Postions
---------------------------------*/
#define SW			(0)
#define SWS			(2)
#define HPRE		(4)
#define PPRE1		(8)
#define PPRE2		(11)
#define ADCPRE		(14)
#define PLLSRC		(16)
#define PLLXTPRE 	(17)
#define PLLMUL 		(18)
#define USBPRE 		(22)
#define MCO 		(24)
#define PLLON		(24)
#define PLLRDY		(25)

/* RCC Bus Options
-----------------*/
#define RCC_AHB 	0
#define RCC_APB1	1
#define RCC_APB2	2

/* RCC Configration Options
--------------------------*/
#define RCC_HSE_CRYSTAL 0
#define RCC_HSE_RC		1
#define RCC_HSI			2
#define RCC_PLL			3

/* RCC_PLL Clock Source Configration Options
-------------------------------------------*/
#define RCC_PLL_INPUT_CLOCK_HSI_DIVBY_2				0
#define RCC_PLL_INPUT_CLOCK_SOURCE_HSE_DIVBY_2		1
#define RCC_PLL_INPUT_CLOCK_SOURCE_HSE				2



#endif