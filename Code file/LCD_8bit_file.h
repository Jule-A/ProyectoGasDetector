
#ifndef LCD_8BIT_FILE_H
#define	LCD_8BIT_FILE_H

#include <pic18f4550.h>

#define RS LATD0                    /*PORTD 0 pin is used for Register Select*/
#define EN LATD1                    /*PORTD 1 pin is used for Enable*/
#define ldata LATB                  /*PORTB is used for transmitting data to LCD*/

void LCD_Init();
void LCD_Command(char );
void LCD_Char(char x);
void LCD_String(const char *);
void MSdelay(unsigned int );
void LCD_String_xy(char ,char ,const char*);
void LCD_Clear();

#endif	/* LCD_8BIT_FILE_H */

