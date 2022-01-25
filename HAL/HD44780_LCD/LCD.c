

#include "LCD.h"
#include "Util.h"




void LCD_init(LCD_lcdConfig_t* p_lcdConfig)
{
   unsigned char LCD_D4;
    /* Initialize Pin */
    LCD_pinInitialize(p_lcdConfig);

    /* Initialize Sequence */
    LCD_initSequence(p_lcdConfig);

    if (p_lcdConfig->dataBusWidth == LCD_BUS_WIDTH_4){

        LCD_setStatus(p_lcdConfig,LCD_DISABLE);
        LCD_setDataType(p_lcdConfig , LCD_COMMAND);
        LCD_D4 = p_lcdConfig->startDataBusPin ;
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4 ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4+1 ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4+2 ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4+3 ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
        LCD_latchData(p_lcdConfig);

    }
   LCD_setStatus(p_lcdConfig,LCD_DISABLE);
   LCD_setDataType(p_lcdConfig , LCD_DISPLAY);
}

void LCD_pinInitialize(LCD_lcdConfig_t* p_lcdConfig){

    /* Initialize data bus */
     LCD_initDataPins(p_lcdConfig);

     /* Initialize Register Select (RS) pin */
     LCD_initRS(p_lcdConfig);

     /* Initialize Read/Write (R/W) pin */
     LCD_initRW(p_lcdConfig);

     /* Initialize Enable (EN) pin */
     LCD_initEN(p_lcdConfig);

}


void LCD_sendData(LCD_lcdConfig_t* p_lcdConfig, LCD_dataType_t dataType, LCD_data_t data){

    LCD_setDataType(p_lcdConfig , dataType);

    if (p_lcdConfig->dataBusWidth == LCD_BUS_WIDTH_8){
        LCD_8BIT( p_lcdConfig , data);
        }else{
        LCD_4BIT( p_lcdConfig , data);
        }

    LCD_setStatus(p_lcdConfig,LCD_DISABLE);
}





void LCD_8BIT(LCD_lcdConfig_t* p_lcdConfig, LCD_data_t data){

    LCD_setStatus(p_lcdConfig,LCD_DISABLE);
    LCD_setData(p_lcdConfig , data);
    LCD_latchData(p_lcdConfig);

}


void LCD_4BIT(LCD_lcdConfig_t* p_lcdConfig, LCD_data_t data){

 unsigned char low_nibble,high_nibble;

        LCD_setStatus(p_lcdConfig,LCD_DISABLE);

        high_nibble= ((data&0xf0) >> 4);
        LCD_setData(p_lcdConfig , high_nibble);
        LCD_latchData(p_lcdConfig);

        low_nibble= (data&0x0f);
        LCD_setData(p_lcdConfig , low_nibble);
        LCD_latchData(p_lcdConfig);


}

//void LCD_init_4BIT(LCD_lcdConfig_t* p_lcdConfig){
//
//        LCD_setStatus(p_lcdConfig,LCD_ENABLE);
//        init_4bit_word= (0b0010); // as given table-12 from hd44780u datasheet
//        LCD_setData(p_lcdConfig , init_4bit_word);
//        LCD_setStatus(p_lcdConfig,LCD_DISABLE);
//
//}

void LCD_initSequence(LCD_lcdConfig_t* p_lcdConfig){
     unsigned char loop_indx=0,LCD_D4;

    LCD_setMode(p_lcdConfig ,LCD_WRITE_MODE);
    LCD_setDataType(p_lcdConfig,LCD_COMMAND);
    LCD_D4 = p_lcdConfig->dataBusWidth == LCD_BUS_WIDTH_8 ? p_lcdConfig->startDataBusPin+4: p_lcdConfig->startDataBusPin ;

        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4 ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4+1 ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4+2 ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)LCD_D4+3 ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);

    for (loop_indx=0;loop_indx<3;loop_indx++){
        LCD_latchData(p_lcdConfig);
    }
        LCD_setStatus(p_lcdConfig,LCD_DISABLE);
}


void LCD_initDataPins(LCD_lcdConfig_t* p_lcdConfig){

    unsigned char loop_indx;
     /* Initialize data bus */
    for (loop_indx=0 ; (p_lcdConfig->dataBusWidth == LCD_BUS_WIDTH_4)? loop_indx<4 : loop_indx<8 ; loop_indx++){
         GPIO_setPinDirection((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)p_lcdConfig->startDataBusPin + loop_indx ,(GPIO_pinDirection_t)GPIO_OUTPUT_PIN);
         GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->dataPort,(GPIO_pin_t)p_lcdConfig->startDataBusPin + loop_indx ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);

        }

}



 /* Initialize Register Select (RS) pin */
void LCD_initRS(LCD_lcdConfig_t* p_lcdConfig){

    if(p_lcdConfig->RS_port != GPIO_PORT_DISABLE && p_lcdConfig->RS_pin != GPIO_PIN_DISABLE ){
        GPIO_setPinDirection((GPIO_port_t)p_lcdConfig->RS_port,(GPIO_pin_t)p_lcdConfig->RS_pin ,(GPIO_pinDirection_t)GPIO_OUTPUT_PIN);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->RS_port,(GPIO_pin_t)p_lcdConfig->RS_pin ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);

    }else{}

}


void LCD_setDataType(LCD_lcdConfig_t* p_lcdConfig , LCD_dataType_t dataType){
     if(p_lcdConfig->RS_port != GPIO_PORT_DISABLE && p_lcdConfig->RS_pin != GPIO_PIN_DISABLE ){
        switch (dataType){
                case LCD_COMMAND:
                 GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->RS_port,(GPIO_pin_t)p_lcdConfig->RS_pin ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
                break;
                case LCD_DISPLAY:
                 GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->RS_port,(GPIO_pin_t)p_lcdConfig->RS_pin ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
                break;
          }
     }else{}
}






/* Initialize Enable (EN) pin */
void LCD_initEN(LCD_lcdConfig_t* p_lcdConfig){

    if(p_lcdConfig->EN_port != GPIO_PORT_DISABLE && p_lcdConfig->EN_pin != GPIO_PIN_DISABLE ){
            GPIO_setPinDirection((GPIO_port_t)p_lcdConfig->EN_port,(GPIO_pin_t)p_lcdConfig->EN_pin ,(GPIO_pinDirection_t)GPIO_OUTPUT_PIN);
            GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->EN_port,(GPIO_pin_t)p_lcdConfig->EN_pin ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);

    }else{}

}

void LCD_setStatus(LCD_lcdConfig_t* p_lcdConfig , LCD_status_t status ){
     if(p_lcdConfig->EN_port != GPIO_PORT_DISABLE && p_lcdConfig->EN_pin != GPIO_PIN_DISABLE ){
        switch (status){
                case LCD_DISABLE:
                 GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->EN_port,(GPIO_pin_t)p_lcdConfig->EN_pin ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
                break;
                case LCD_ENABLE:
                 GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->EN_port,(GPIO_pin_t)p_lcdConfig->EN_pin ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
                break;
            }
     }else{}
}



  /* Initialize Read/Write (R/W) pin */
void LCD_initRW(LCD_lcdConfig_t* p_lcdConfig){

    if(p_lcdConfig->RW_port != GPIO_PORT_DISABLE && p_lcdConfig->RW_pin != GPIO_PIN_DISABLE ){
        GPIO_setPinDirection((GPIO_port_t)p_lcdConfig->RW_port,(GPIO_pin_t)p_lcdConfig->RW_pin ,(GPIO_pinDirection_t)GPIO_OUTPUT_PIN);
        GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->RW_port,(GPIO_pin_t)p_lcdConfig->RW_pin ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);

    }else{}

}

void LCD_setMode(LCD_lcdConfig_t* p_lcdConfig,LCD_mode_t mode){
     if(p_lcdConfig->RW_port != GPIO_PORT_DISABLE && p_lcdConfig->RW_pin != GPIO_PIN_DISABLE ){
            switch (mode){
                case LCD_WRITE_MODE:
                 GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->RW_port,(GPIO_pin_t)p_lcdConfig->RW_pin ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
                break;
                case LCD_READ_MODE:
                 GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->RW_port,(GPIO_pin_t)p_lcdConfig->RW_pin ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
                break;
            }
     }else{}
}



void LCD_setData(LCD_lcdConfig_t* p_lcdConfig , LCD_data_t data){

    unsigned char loop_indx,port,pin;
    for (loop_indx=0 ; (p_lcdConfig->dataBusWidth == LCD_BUS_WIDTH_4)? loop_indx<4 : loop_indx<8 ; loop_indx++){

    port = p_lcdConfig->dataPort;
    pin = p_lcdConfig->startDataBusPin+loop_indx;
    LCD_setDataBit( port , pin ,(GPIO_pinLevel_t)(READ_BIT(data,loop_indx)));

    }
}


void LCD_setDataBit(GPIO_port_t port , GPIO_pin_t pin ,GPIO_pinLevel_t pinLevel){

     if (pinLevel == GPIO_HIGH_LEVEL) {
         GPIO_setPinLevel((GPIO_port_t)port,(GPIO_pin_t)pin ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
     }else{
         GPIO_setPinLevel((GPIO_port_t)port,(GPIO_pin_t)pin ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);
     }

}

void LCD_latchData(LCD_lcdConfig_t* p_lcdConfig){


GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->EN_port,(GPIO_pin_t)p_lcdConfig->EN_pin ,(GPIO_pinLevel_t)GPIO_HIGH_LEVEL);
/* add delay if necessary */
GPIO_setPinLevel((GPIO_port_t)p_lcdConfig->EN_port,(GPIO_pin_t)p_lcdConfig->EN_pin ,(GPIO_pinLevel_t)GPIO_LOW_LEVEL);


}

