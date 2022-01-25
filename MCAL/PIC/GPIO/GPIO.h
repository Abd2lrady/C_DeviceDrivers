#ifndef GPIO_H
#define GPIO_H


typedef enum {GPIO_PORT_A=0,
				GPIO_PORT_B,
				GPIO_PORT_C,
				GPIO_PORT_D,
				GPIO_PORT_E,
				GPIO_PORT_DISABLE
}GPIO_port_t;

typedef enum {	GPIO_PIN_0=0,
                GPIO_PIN_1,
				GPIO_PIN_2,
				GPIO_PIN_3,
				GPIO_PIN_4,
				GPIO_PIN_5,
				GPIO_PIN_6,
				GPIO_PIN_7,
				GPIO_PIN_DISABLE

}GPIO_pin_t;

typedef enum{GPIO_OUTPUT_PORT=0,
			GPIO_INPUT_PORT,
}GPIO_portDirection_t;

typedef enum{GPIO_OUTPUT_PIN=0,
			GPIO_INPUT_PIN,
}GPIO_pinDirection_t;

typedef enum{ GPIO_LOW_LEVEL=0,
	GPIO_HIGH_LEVEL
}GPIO_pinLevel_t;

typedef unsigned char GPIO_portData_t;


/*  GPIO Device Function Prototypes */
/*----------------------------------*/
void GPIO_initPin(GPIO_port_t,GPIO_pin_t,GPIO_pinDirection_t,GPIO_pinLevel_t);
void GPIO_initPort(GPIO_port_t,GPIO_portDirection_t,GPIO_portData_t);

void GPIO_setPortMode_DIO(GPIO_port_t);
void GPIO_setPinMode_DIO(GPIO_port_t,GPIO_pin_t);
void GPIO_setPinDirection(GPIO_port_t,GPIO_pin_t,GPIO_pinDirection_t);
GPIO_pinDirection_t GPIO_getPinDirection(GPIO_port_t,GPIO_pin_t);
void GPIO_setPinLevel(GPIO_port_t,GPIO_pin_t,GPIO_pinLevel_t);
GPIO_pinLevel_t GPIO_getPinLevel(GPIO_port_t,GPIO_pin_t);


void GPIO_setPortDirection(GPIO_port_t,GPIO_portDirection_t);
GPIO_portDirection_t GPIO_getPortDirection(GPIO_port_t);

void GPIO_setPortData(GPIO_port_t,GPIO_portData_t);
GPIO_portData_t GPIO_getPortData(GPIO_port_t);













#endif // GPIO_H
