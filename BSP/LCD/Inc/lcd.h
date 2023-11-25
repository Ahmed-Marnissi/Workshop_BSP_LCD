/*
 * LCD.h
 *
 *  Created on: Jun 3, 2023
 *      Author: 21624
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include "stdint.h"







/*
 * LCD.c
 *
 *  Created on: Jun 3, 2023
 *      Author: 21624
 */



void LCD_Init();



void LCD_Clear();

void LCD_Send_Command(uint8_t Command);
void LCD_Send_Data(uint8_t Data) ;

void LCD_Print(const  char  * Message );



#endif /* INC_LCD_H_ */
