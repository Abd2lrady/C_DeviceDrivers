#ifndef LCD_COMMANDS_H_INCLUDED
#define LCD_COMMANDS_H_INCLUDED


#define CLEAR_SCREEN_COMMAND                0x01
#define RETURN_HOME_COMMAND                 0x02

#define CURSOR_DECREMENT_SCREEN_NOT_SHIFT   0x04
#define CURSOR_DECREMENT_SCREEN_SHIFT       0x05
#define CURSOR_INCREMENT_SCREEN_NOT_SHIFT   0X06
#define CURSOR_INCREMENT_SCREEN_SHIFT       0x07

#define DISPLAY_OFF_CURSOR_OFF_BLINK_OFF    0x08
#define DISPLAY_OFF_CURSOR_OFF_BLINK_ON     0x09
#define DISPLAY_OFF_CURSOR_ON_BLINK_OFF     0x0a
#define DISPLAY_OFF_CURSOR_ON_BLINK_ON      0x0b
#define DISPLAY_ON_CURSOR_OFF_BLINK_OFF     0x0c
#define DISPLAY_ON_CURSOR_OFF_BLINK_ON      0x0d
#define DISPLAY_ON_CURSOR_ON_BLINK_OFF      0x0e
#define DISPLAY_ON_CURSOR_ON_BLINK_ON       0x0f

#define CURSOR_SHIFT_LEFT                   0x10
#define CURSOR_SHIFT_RIGHT                  0x14
#define SCREEN_SHIFT_LEFT                   0x18
#define SCREEN_SHIFT_RIGHT                  0x1c

#define _4_BIT_1_LINE_8_DOT                  0x20
#define _4_BIT_1_LINE_11_DOT                 0x24
#define _4_BIT_2_LINE_8_DOT                  0x28
#define _4_BIT_2_LINE_11_DOT                 0x2c
#define _8_BIT_1_LINE_8_DOT                  0x30
#define _8_BIT_1_LINE_11_DOT                 0x34
#define _8_BIT_2_LINE_8_DOT                  0x38
#define _8_BIT_2_LINE_11_DOT                 0x3c


#define LCD_4BIT_INITIALIZE                  0b0010
#define LCD_INITIALIZE                       0x03



#endif // LCD_COMMANDS_H_INCLUDED
