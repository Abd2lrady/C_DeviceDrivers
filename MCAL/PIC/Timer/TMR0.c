

#include "TMR0.h"

void TMR0_init(TMR0_config_t* config){

	TMR0_setExternalClockEdge(config->externalClockEdge);
	TMR0_setPrescaler(config-> prescaler);
	config->interruptStatus?TMR0_enableOverFlowInterrupt():TMR0_disableOverFlowInterrupt();
	TMR0_setClockSource(config->clockSource);
}


TMR0_dataReg_t TMR0_getDataReg(void){
	return TMR0_DATA_REG;
}



void TMR0_setDataReg(TMR0_dataReg_t dataReg){
	TMR0_DATA_REG=dataReg;
}



TMR0_overFlowFlag_t TMR0_getOverFlowFlag(void){
	return TMR0_READ_OVERFLOW_FLAG;
}



void TMR0_enableOverFlowInterrupt(void){
	TMR0_ENABLE_OVERFLOW_INTERRUPT;
}



void TMR0_disableOverFlowInterrupt(void){
	TMR0_DISABLE_OVERFLOW_INTERRUPT;
}

void TMR0_clearOverFlowFlag(void){
	TMR0_CLEAR_OVERFLOW_FLAG;
}

void TMR0_setPrescaler(TMR0_prescaler_t prescaler){

	 switch (prescaler){
    case DIV_BY_2 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_2;
		 break;
    case DIV_BY_4 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_4;
		 break;
    case DIV_BY_8 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_8;
		 break;
    case DIV_BY_16 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_16;
		 break;
    case DIV_BY_32 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_32;
		 break;
    case DIV_BY_64 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_64;
		 break;
    case DIV_BY_128 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_128;
		 break;
    case DIV_BY_256 :
		 TMR0_SET_CLK_PRESCALER_DIV_BY_256;
		 break;
	 default:/*SHOULD NOT ENTER HERE*/
		 break;
	 }
    TMR0_PRESCALER_ASSIGNMENT;
}

	 switch(mode){
	 case NORMAL_MODE:
		 TMR0_NORMAL_OPERATION_MODE;
		 break;
	 case COMPARE_MATCH_MODE:
		 TMR0_COMPARE_MATCH_OPERATION_MODE;
		 break;
	 case FAST_PWM_MODE:
		 TMR0_FAST_PWM_OPERATION_MODE;
		 break;
	 default:
		 break;
	 }
}


void TMR0_disable(void){
    TMR0_COUNTER_MODE;
}

void TMR0_enable(void){
    TMR0_TIMER_MODE;
}

void TMR0_setExternalClockEdge(TMR0_externalClockEdge_t externalClockEdge){
	switch(externalClockEdge){
	case TMR0_FALLING_EDGE:
		TMR0_SET_EXTERNAL_CLK_FALLING_EDGE;
		break;
	case TMR0_RISING_EDGE:
		TMR0_SET_EXTERNAL_CLK_RISING_EDGE;
		break;
	default:
		break;
	}
}
void TMR0_setClockSource(TMR0_clockSource_t clockSource){
	switch(clockSource){
	case TMR0_INTERNAL_CLK_SOURCE:
		TMR0_TIMER_MODE;
		break;
	case TMR0_EXTERNAL_CLK_SOURCE:
		TMR0_COUNTER_MODE;
		break;
	default:
		break;
	}
}



