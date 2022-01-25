
#include "SWITCH.h"

/* Initialization Button states */
void SWITCH_init(SWITCH_switchID_t * p_switchID){

p_switchID->filterAccummulator=0;
SWITCH_setPressState(p_switchID,0);
SWITCH_setActiveState(p_switchID,0);
SWITCH_setPinDirection(p_switchID);
}


/* Setting Button port */
 void SWITCH_setPort(SWITCH_switchID_t* p_switchID,SWITCH_port_t port){

    p_switchID->port=port;

}

/* Getting Button port */
 SWITCH_port_t SWITCH_getPort(SWITCH_switchID_t* p_switchID){

return p_switchID->port;
}

/* Setting Button pin */
 void SWITCH_setPin(SWITCH_switchID_t* p_switchID,SWITCH_pin_t pin){

    p_switchID->pin=pin;
}

/* Getting Button pin */
 SWITCH_pin_t SWITCH_getPin(SWITCH_switchID_t* p_switchID){

        return p_switchID->pin;
}

 void SWITCH_setPinDirection(SWITCH_switchID_t* p_switchID){

GPIO_setPinDirection((GPIO_port_t)p_switchID->port,(GPIO_pin_t)p_switchID->pin,(GPIO_pinDirection_t)SWITCH_DIR);

}


/* Setting Button active level */
 void SWITCH_setActiveLevel(SWITCH_switchID_t* p_switchID,SWITCH_activeLevel_t activeLevel){

    p_switchID->activeLevel=activeLevel;
}

/* Getting Button active level */
SWITCH_activeLevel_t SWITCH_getActiveLevel(SWITCH_switchID_t* p_switchID){

    return p_switchID->activeLevel;
}


/*Setting switch activate state*/
 void SWITCH_setActiveState(SWITCH_switchID_t* p_switchID,SWITCH_activeState_t activeState){

    p_switchID->activeState=activeState;
}

/*Getting switch activate state*/
 SWITCH_activeState_t SWITCH_getActiveState(SWITCH_switchID_t* p_switchID){

return p_switchID->activeState ;
}

/*Setting switch press state*/
 void SWITCH_setPressState(SWITCH_switchID_t* p_switchID,SWITCH_pressState_t pressState){

    p_switchID->pressState=pressState;
}

/*Getting switch press state*/
 SWITCH_pressState_t SWITCH_getPressState(SWITCH_switchID_t* p_switchID){

    return p_switchID->pressState ;
}

/* Setting Button states */
 void SWITCH_setState(SWITCH_switchID_t* p_switchID,SWITCH_state_t state){

    p_switchID->state=state;
}

/* Getting Button states */
 SWITCH_state_t SWITCH_getState(SWITCH_switchID_t* p_switchID){

    return p_switchID->state;
}



/* Software Filter for Switch With 6 consecutive samples*/
 void SWITCH_filter_6N(SWITCH_switchID_t* p_switchID){

    p_switchID->filterAccummulator = p_switchID->filterAccummulator << 1;

    if (SWITCH_getActiveState(p_switchID) == SWITCH_MAKE){
        p_switchID->filterAccummulator = p_switchID->filterAccummulator | 1;
        }


    if (((p_switchID->filterAccummulator) & 0x3f) == 0x3f) {
        SWITCH_setPressState(p_switchID,SWITCH_VALID_PRESS);
    }else{
        SWITCH_setPressState(p_switchID,SWITCH_INVALID_PRESS);
    }

}


/* update switch state */
void SWITCH_updateState (SWITCH_switchID_t* p_switchID){


    /* getting switch pin data from GPIO */
    if (GPIO_getPinLevel((GPIO_port_t)p_switchID->port,(GPIO_pin_t)p_switchID->pin) == SWITCH_getActiveLevel(p_switchID)){
        SWITCH_setActiveState(p_switchID,SWITCH_MAKE);
    }else{
        SWITCH_setActiveState(p_switchID,SWITCH_BREAK);
    }

    /* Filtering read data form GPIO */
    SWITCH_filter_6N(p_switchID);

    /* checking if a valid switch press after filtering noise */
    if (SWITCH_getPressState(p_switchID) == SWITCH_VALID_PRESS) {
        /*changing switch state*/
        switch (SWITCH_getState(p_switchID)){
            case SWITCH_RELEASED :
                SWITCH_setState(p_switchID,SWITCH_PREPRESSED);
            break;

            case SWITCH_PREPRESSED:
                SWITCH_setState(p_switchID,SWITCH_PRESSED);
            break;

        }

    }else{
        switch (SWITCH_getState(p_switchID)){
            case SWITCH_PRESSED:
                SWITCH_setState(p_switchID,SWITCH_PRERELEASED);
            break;

            case SWITCH_PRERELEASED:
                SWITCH_setState(p_switchID,SWITCH_RELEASED);
            break;


        }


    }
}
