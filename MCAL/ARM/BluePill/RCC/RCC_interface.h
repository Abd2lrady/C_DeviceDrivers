/*
 *		RCC_interface.h
 *      Author: Abd2lrady
 */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



bool RCC_boolEnableClock(u8 arg_u8BusID, u8 arg_u8PeripheralID);

bool RCC_boolDisableClock(u8 arg_u8BusID, u8 arg_u8PeripheralID);
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

void RCC_voidInitSysClock(void);

#endif