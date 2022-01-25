#ifndef __LCD_H__
#define __LCD_H__

#include "GPIO.h"
#include "Bit_Manipulation.h"
#include "LCD_COMMANDS.h"


typedef unsigned char LCD_address_t ;

typedef unsigned char LCD_data_t ;





typedef enum { LCD_BUS_WIDTH_8=0,
              LCD_BUS_WIDTH_4

}LCD_dataBusWidth_t;


typedef enum { LCD_COMMAND=0,
              LCD_DISPLAY
}LCD_dataType_t;

typedef enum { LCD_WRITE_MODE=0,
              LCD_READ_MODE
}LCD_mode_t;


typedef enum { LCD_DISABLE=0,
              LCD_ENABLE
}LCD_status_t;



typedef struct lcdConfig {
LCD_dataBusWidth_t      dataBusWidth;
GPIO_port_t          dataPort;
GPIO_pin_t               startDataBusPin;
GPIO_port_t              RS_port;
GPIO_pin_t               RS_pin;
GPIO_port_t              RW_port;
GPIO_pin_t               RW_pin;
GPIO_port_t              EN_port;
GPIO_pin_t               EN_pin;

}LCD_lcdConfig_t;



void LCD_init(LCD_lcdConfig_t*);
void LCD_pinInitialize(LCD_lcdConfig_t* );
void LCD_init_4BIT(LCD_lcdConfig_t* );

void LCD_sendData(LCD_lcdConfig_t*,LCD_dataType_t,LCD_data_t);
void LCD_8BIT( LCD_lcdConfig_t* , LCD_data_t);
void LCD_4BIT( LCD_lcdConfig_t* , LCD_data_t);

//void LCD_SendString(tByte line, tByte * str);

void LCD_initSequence(LCD_lcdConfig_t* );

void LCD_initDataPins(LCD_lcdConfig_t* );

void LCD_initRS(LCD_lcdConfig_t* );
void LCD_setDataType(LCD_lcdConfig_t*  , LCD_dataType_t );

void LCD_initEN(LCD_lcdConfig_t* );
void LCD_setStatus(LCD_lcdConfig_t*  , LCD_status_t  );


void LCD_initRW(LCD_lcdConfig_t* );
void LCD_setMode(LCD_lcdConfig_t* ,LCD_mode_t );


void LCD_setData(LCD_lcdConfig_t*  , LCD_data_t );
void LCD_setDataBit(GPIO_port_t , GPIO_pin_t pin ,GPIO_pinLevel_t );

void LCD_latchData(LCD_lcdConfig_t*);



#endif // __LCD_H__
