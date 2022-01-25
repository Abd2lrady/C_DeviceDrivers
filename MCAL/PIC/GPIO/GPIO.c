#include "GPIO.h"
#include "GPIO_PIC16f877a_mCAL.h"


void GPIO_setPinDirection(GPIO_port_t GPIOport,GPIO_pin_t GPIOpin,GPIO_pinDirection_t pinDirection){
	switch (GPIOport){
	case GPIO_PORT_A:
			GPIO_PIN_DIR_CTRL(GPIO_DIR_CTRL_REG_A,GPIOpin,pinDirection);
			break;
	case GPIO_PORT_B:
			GPIO_PIN_DIR_CTRL(GPIO_DIR_CTRL_REG_B,GPIOpin,pinDirection);
			break;
	case GPIO_PORT_C:
			GPIO_PIN_DIR_CTRL(GPIO_DIR_CTRL_REG_C,GPIOpin,pinDirection);
			break;
	case GPIO_PORT_D:
			GPIO_PIN_DIR_CTRL(GPIO_DIR_CTRL_REG_D,GPIOpin,pinDirection);
			break;
	case GPIO_PORT_E:
			GPIO_PIN_DIR_CTRL(GPIO_DIR_CTRL_REG_E,GPIOpin,pinDirection);
			break;
	default:/* CODE SHOULD NOT ENTER HERE */
		break;
	}

}


GPIO_pinDirection_t GPIO_getPinDirection(GPIO_port_t GPIOport,GPIO_pin_t GPIOpin){

	switch (GPIOport){
		case GPIO_PORT_A:
			return READ_BIT(GPIO_DIR_CTRL_REG_A,GPIOpin);

		case GPIO_PORT_B:
			return READ_BIT(GPIO_DIR_CTRL_REG_B,GPIOpin);

		case GPIO_PORT_C:
			return READ_BIT(GPIO_DIR_CTRL_REG_C,GPIOpin);

		case GPIO_PORT_D:
			return READ_BIT(GPIO_DIR_CTRL_REG_D,GPIOpin);

		case GPIO_PORT_E:
			return READ_BIT(GPIO_DIR_CTRL_REG_E,GPIOpin);
		default:/* CODE SHOULD NOT ENTER HERE */
			break;
		}
}



void GPIO_setPinLevel(GPIO_port_t GPIOport,GPIO_pin_t GPIOpin,GPIO_pinLevel_t GPIOpinLevel){

	switch (GPIOport){
		case GPIO_PORT_A:
				GPIO_PIN_WRITE_DATA(GPIO_DATA_OUT_REG_A,GPIOpin,GPIOpinLevel);
				break;
		case GPIO_PORT_B:
				GPIO_PIN_WRITE_DATA(GPIO_DATA_OUT_REG_B,GPIOpin,GPIOpinLevel);
				break;
		case GPIO_PORT_C:
				GPIO_PIN_WRITE_DATA(GPIO_DATA_OUT_REG_C,GPIOpin,GPIOpinLevel);
				break;
		case GPIO_PORT_D:
				GPIO_PIN_WRITE_DATA(GPIO_DATA_OUT_REG_D,GPIOpin,GPIOpinLevel);
				break;
		case GPIO_PORT_E:
				GPIO_PIN_WRITE_DATA(GPIO_DATA_OUT_REG_E,GPIOpin,GPIOpinLevel);
				break;
		default:/* CODE SHOULD NOT ENTER HERE */
			break;
		}
}




GPIO_pinLevel_t GPIO_getPinLevel(GPIO_port_t GPIOport,GPIO_pin_t GPIOpin){

	switch (GPIOport){
			case GPIO_PORT_A:
				return	GPIO_PIN_READ_DATA(GPIO_DATA_IN_REG_A,GPIOpin);

			case GPIO_PORT_B:
				return	GPIO_PIN_READ_DATA(GPIO_DATA_IN_REG_B,GPIOpin);

			case GPIO_PORT_C:
				return	GPIO_PIN_READ_DATA(GPIO_DATA_IN_REG_C,GPIOpin);

			case GPIO_PORT_D:
				return	GPIO_PIN_READ_DATA(GPIO_DATA_IN_REG_D,GPIOpin);

			case GPIO_PORT_E:
				return	GPIO_PIN_READ_DATA(GPIO_DATA_IN_REG_E,GPIOpin);

			default:/* CODE SHOULD NOT ENTER HERE */
				break;
			}
}



void GPIO_setPortDirection(GPIO_port_t GPIOport,GPIO_portDirection_t GPIOportDirection){

	switch (GPIOport){
			case GPIO_PORT_A:
				GPIO_PORT_DIR_CTRL(GPIO_DIR_CTRL_REG_A,GPIOportDirection);
					break;
			case GPIO_PORT_B:
				GPIO_PORT_DIR_CTRL(GPIO_DIR_CTRL_REG_B,GPIOportDirection);
					break;
			case GPIO_PORT_C:
				GPIO_PORT_DIR_CTRL(GPIO_DIR_CTRL_REG_C,GPIOportDirection);
					break;
			case GPIO_PORT_D:
				GPIO_PORT_DIR_CTRL(GPIO_DIR_CTRL_REG_D,GPIOportDirection);
					break;
			case GPIO_PORT_E:
				GPIO_PORT_DIR_CTRL(GPIO_DIR_CTRL_REG_E,GPIOportDirection);
					break;
			default:/* CODE SHOULD NOT ENTER HERE */
				break;
			}
}

GPIO_portDirection_t GPIO_getPortDirection(GPIO_port_t GPIOport){

	switch (GPIOport){
				case GPIO_PORT_A:
					return GPIO_DIR_CTRL_REG_A;

				case GPIO_PORT_B:
					return GPIO_DIR_CTRL_REG_B;

				case GPIO_PORT_C:
					return GPIO_DIR_CTRL_REG_C;

				case GPIO_PORT_D:
					return GPIO_DIR_CTRL_REG_D;

				case GPIO_PORT_E:
					return GPIO_DIR_CTRL_REG_E;


				default:/* CODE SHOULD NOT ENTER HERE */
					break;
				}
}

void GPIO_setPortData(GPIO_port_t GPIOport,GPIO_portData_t GPIOportData){

	switch (GPIOport){
				case GPIO_PORT_A:
					GPIO_PORT_WRITE_DATA(GPIO_DATA_OUT_REG_A,GPIOportData);
						break;
				case GPIO_PORT_B:
					GPIO_PORT_WRITE_DATA(GPIO_DATA_OUT_REG_B,GPIOportData);
						break;
				case GPIO_PORT_C:
					GPIO_PORT_WRITE_DATA(GPIO_DATA_OUT_REG_C,GPIOportData);
						break;
				case GPIO_PORT_D:
					GPIO_PORT_WRITE_DATA(GPIO_DATA_OUT_REG_D,GPIOportData);
						break;
				case GPIO_PORT_E:
					GPIO_PORT_WRITE_DATA(GPIO_DATA_OUT_REG_E,GPIOportData);
						break;
				default:/* CODE SHOULD NOT ENTER HERE */
					break;
				}

}

GPIO_portData_t GPIO_getPortData(GPIO_port_t GPIOport){

	switch (GPIOport){
					case GPIO_PORT_A:
						return GPIO_PORT_READ_DATA(GPIO_DATA_IN_REG_A);

					case GPIO_PORT_B:
						return GPIO_PORT_READ_DATA(GPIO_DATA_IN_REG_B);

					case GPIO_PORT_C:
						return GPIO_PORT_READ_DATA(GPIO_DATA_IN_REG_C);

					case GPIO_PORT_D:
						return GPIO_PORT_READ_DATA(GPIO_DATA_IN_REG_D);

					case GPIO_PORT_E:
						return GPIO_PORT_READ_DATA(GPIO_DATA_IN_REG_E);

					default:/* CODE SHOULD NOT ENTER HERE */
						break;
					}
}
void GPIO_setPortMode_DIO(GPIO_port_t port){
    
    switch(port){
        case GPIO_PORT_A :
            SELECT_PORTA_DIO_MODE;
            break;
            
        case GPIO_PORT_E:
            SELECT_PORTE_DIO_MODE;
            break;
        default:
            break;       
    }    
    
}

void GPIO_initPin(GPIO_port_t GPIOport,GPIO_pin_t GPIOpin,GPIO_pinDirection_t pinDirection,GPIO_pinLevel_t GPIOpinLevel){
    /* set pin as DIO pin */
    GPIO_setPortMode_DIO(GPIOport);
    /*set initial pin direction*/
    GPIO_setPinDirection(GPIOport, GPIOpin, pinDirection);
    /*set initial pin level*/
    GPIO_setPinLevel( GPIOport, GPIOpin,GPIOpinLevel);   
    
}

void GPIO_initPort(GPIO_port_t GPIOport,GPIO_portDirection_t GPIOportDirection,GPIO_portData_t GPIOportData){
   
    /* set port as DIO pin */
    GPIO_setPortMode_DIO(GPIOport);
    /*set initial port direction*/
    GPIO_setPortDirection(GPIOport, GPIOportDirection);
    /*set initial pin level*/
    GPIO_setPortData( GPIOport, GPIOportData);   
    
}
