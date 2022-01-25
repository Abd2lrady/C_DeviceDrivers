#ifndef SWITCH_H_INCLUDED
#define SWITCH_H_INCLUDED

typedef unsigned char SWITCH_filterAccummulator_t;

typedef enum{SWITCH_ACTIVE_LOW=0,
                SWITCH_ACTIVE_HIGH
} SWITCH_activeLevel_t;

typedef enum{SWITCH_BREAK=0,
                SWITCH_MAKE
}SWITCH_activeState_t;

typedef enum{SWITCH_INVALID_PRESS=0,
                SWITCH_VALID_PRESS
}SWITCH_pressState_t;

typedef enum{SWITCH_RELEASED=0,
                SWITCH_PREPRESSED,
                SWITCH_PRESSED,
                SWITCH_PRERELEASED
}SWITCH_state_t;

typedef enum{SWITCH_PORT_A=0,
                SWITCH_PORT_B,
                SWITCH_PORT_C,
                SWITCH_PORT_D
}SWITCH_port_t;

typedef enum{SWITCH_PIN_0=0,
                SWITCH_PIN_1,
				SWITCH_PIN_2,
				SWITCH_PIN_3,
				SWITCH_PIN_4,
				SWITCH_PIN_5,
				SWITCH_PIN_6,
				SWITCH_PIN_7
}SWITCH_pin_t;

typedef struct SWITCH_config{
SWITCH_port_t port;
SWITCH_pin_t pin;
SWITCH_activeLevel_t activeLevel;
SWITCH_state_t state;
SWITCH_filterAccummulator_t filterAccummulator;
SWITCH_activeState_t activeState;
SWITCH_pressState_t pressState;
}SWITCH_switchID_t;


void SWITCH_init(SWITCH_switchID_t*);

void SWITCH_setState(SWITCH_switchID_t*,SWITCH_state_t);
SWITCH_state_t SWITCH_getState(SWITCH_switchID_t*);

void SWITCH_setActiveLevel(SWITCH_switchID_t*,SWITCH_activeLevel_t);
SWITCH_activeLevel_t SWITCH_getActiveLevel(SWITCH_switchID_t*);

void SWITCH_setActiveState(SWITCH_switchID_t*,SWITCH_activeState_t);
SWITCH_activeState_t SWITCH_getActiveState(SWITCH_switchID_t*);

void SWITCH_setPressState(SWITCH_switchID_t*,SWITCH_pressState_t);
SWITCH_pressState_t SWITCH_getPressState(SWITCH_switchID_t*);

void SWITCH_setPort(SWITCH_switchID_t*,SWITCH_port_t);
SWITCH_port_t SWITCH_getPort(SWITCH_switchID_t*);

void SWITCH_setPin(SWITCH_switchID_t*,SWITCH_pin_t);
SWITCH_pin_t SWITCH_getPin(SWITCH_switchID_t*);

void SWITCH_setPinDirection(SWITCH_switchID_t* );

static void SWITCH_filter_6N(SWITCH_switchID_t*);

void SWITCH_updateState(SWITCH_switchID_t*);

















#endif // SWITCH_H_INCLUDED
