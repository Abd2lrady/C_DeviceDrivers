/*
 *		RCC_program.h
 *      Author: Abd2lrady
 */

#include "RCC.h"

bool RCC_boolEnableClock(u8 arg_u8BusID, u8 arg_u8PeripheralID)
{
	/*--------------------------------------------- 
	arg_u8BusID Fn parameter to specify bus
	options :-
		RCC_AHB
		RCC_APB1
		RCC_APB2
		
	arg_u8PeripheralID Fn parameter to specify peripheral on bus
	options :- 
		0 ... 31
	----------------------------------------------*/
		
	bool ret_boolStatus = FALSE;
	if (arg_u8PeripheralID < 32)
	{
		switch (arg_u8BusID)
		{
			case RCC_AHB:
				SET_BIT(RCC_AHBENR, arg_u8PeripheralID);
				ret_boolStatus = TRUE;
				break;
			case RCC_APB1:
				SET_BIT(RCC_APB1, arg_u8PeripheralID);
				ret_boolStatus = TRUE;
				break;
			case RCC_APB2:
				SET_BIT(RCC_APB2, arg_u8PeripheralID);
				ret_boolStatus = TRUE;
				break;
			default :
			/* MUST NOT ENTER HERE */
		}
	}
	return ret_boolStatus;
}

bool RCC_boolDisableClock(u8 arg_u8BusID, u8 arg_u8PeripheralID)
{
	/*--------------------------------------------- 
	arg_u8BusID Fn parameter to specify bus
	options :-
		RCC_AHB
		RCC_APB1
		RCC_APB2
		
	arg_u8PeripheralID Fn parameter to specify peripheral on bus
	options :- 
		0 ... 31
	----------------------------------------------*/
	bool ret_boolStatus = FALSE;
	if (arg_u8PeripheralID < 32)
	{
		switch (arg_u8BusID)
		{
			case RCC_AHB:
				CLEAR_BIT(RCC_AHBENR, arg_u8PeripheralID);
				ret_boolStatus = TRUE;
				break;
			case RCC_APB1:
				CLEAR_BIT(RCC_APB1, arg_u8PeripheralID);
				ret_boolStatus = TRUE;
				break;
			case RCC_APB2:
				CLEAR_BIT(RCC_APB2, arg_u8PeripheralID);
				ret_boolStatus = TRUE;
				break;
			default :
			/* MUST NOT ENTER HERE */
		}
	}
	return ret_boolStatus;
}

void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_SOURCE == RCC_HSI
		SET_BIT(RCC_CR, HSION);
		RCC_CFGR = (RCC_CFGR & (~(0b1111 << (PLLMUL)))) | (0b00 << (SW))
	#elif RCC_CLOCK_SOURCE == RCC_HSE_CRYSTAL
		SET_BIT(RCC_CR, HSEON);
		CLEAR_BIT(RCC_CR, HSEBYP);
		RCC_CFGR = (RCC_CFGR & (~(0b1111 << (PLLMUL)))) | (0b01 << (SW))
	#elif RCC_CLOCK_SOURCE == RCC_HSE_RC
		SET_BIT(RCC_CR, HSEON);
		SET_BIT(RCC_CR, HSEBYP);
		RCC_CFGR = (RCC_CFGR & (~(0b1111 << (PLLMUL)))) | (0b01 << (SW))
	#elif RCC_CLOCK_SOURCE == RCC_PLL
		SET_BIT(RCC_CR, PLLON);
		#if RCC_PLL_CLOCK_SOURCE == RCC_PLL_INPUT_CLOCK_HSI_DIVBY_2
			CLEAR_BIT(RCC_CFGR, PLLSRC);
		#elif RCC_PLL_CLOCK_SOURCE == RCC_PLL_INPUT_CLOCK_SOURCE_HSE
			SET_BIT(RCC_CFGR, PLLSRC);
			CLEAR_BIT(RCC_CFGR, PLLSRC);
		#elif RCC_PLL_CLOCK_SOURCE == RCC_PLL_INPUT_CLOCK_SOURCE_HSE_DIVBY_2
			SET_BIT(RCC_CFGR, PLLSRC);
			SET_BIT(RCC_CFGR, PLLSRC);
		#else
			#error("Wrong PLL Clock Source Chosen")
		#endif
		RCC_CFGR = (RCC_CFGR & (~(0b1111 << (PLLMUL))))	| ((RCC_PLL_MUL_FACTOR - 2) << (PLLMUL))
		RCC_CFGR = (RCC_CFGR & (~(0b11 << (SW)))) 	| (0b10 << (SW))
	#else 
		#error("Wrong clock source chosen")
	#endif
}

