#ifndef TMR0_H_INCLUDED
#define TMR0_H_INCLUDED

typedef unsigned char TMR0_dataReg_t;
/*typedef unsigned char TMR0_compareReg_t;*/
typedef unsigned char  TMR0_overFlowFlag_t;
/*typedef unsigned char  TMR0_compareMatchFlag_t;*/


typedef struct{
	TMR0_clockSource_t clockSource;
    TMR0_externalClockEdge_t externalClockEdge;
	TMR0_prescaler_t prescaler;
	TMR0_interruptStatus_t interruptStatus;
}TMR0_config_t;



typedef enum{ DIV_BY_2=0,
			  DIV_BY_4,
			  DIV_BY_8,
  			  DIV_BY_16,
  			  DIV_BY_32,
              DIV_BY_64,
		  	  DIV_BY_128,
			  DIV_BY_256
}TMR0_prescaler_t;

typedef enum{ TMR0_EXTERNAL_CLK_SOURCE=0,
			  TMR0_INTERNAL_CLK_SOURCE,
}TMR0_clockSource_t;

typedef enum {TMR0_INTERRUPT_DISABLE=0,
	TMR0_INTERRUPT_ENABLE
}TMR0_interruptStatus_t;



typedef enum{ TMR0_EXTERNAL_CLK_FALLING_EDGE=0,
			  TMR0_EXTERNAL_CLK_RISING_EDGE

}TMR0_externalClockEdge_t;


void TMR0_init(TMR0_config_t*);
TMR0_dataReg_t TMR0_getDataReg(void);
void TMR0_setDataReg(TMR0_dataReg_t);
void TMR0_setPrescaler(TMR0_prescaler_t);
void TMR0_enableOverFlowInterrupt(void);
void TMR0_disableOverFlowInterrupt(void);
TMR0_overFlowFlag_t TMR0_getOverFlowFlag(void);
void TMR0_clearOverFlowFlag(void);
void TMR0_disable(void);
void TMR0_enable(void);
void TMR0_setExternalClockEdge(TMR0_externalClockEdge_t);

#endif // TMR0_H_INCLUDED
