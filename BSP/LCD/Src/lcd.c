/*
 * LCD.c
 *
 *  Created on: Jun 3, 2023
 *      Author: 21624
 */


#include "lcd_cfg.h"

#include "lcd.h"

#include "stm32f4xx.h"

I2C_HandleTypeDef hi2c;


void Init_I2C();
void Init_GPIO_I2C();
void LCD_Send_Command(uint8_t Command);
void LCD_Send_Data(uint8_t Data);

void LCD_Init()



{

	/*-----------Init I2C --------------*/

	Init_I2C();




	/*-----------Init I2C GPIOS  --------------*/

	Init_GPIO_I2C();

	// Initialize the LCD module sequence
	HAL_Delay(50);
	LCD_Send_Command(0x30);
	HAL_Delay(5);
	LCD_Send_Command(0x30);
	HAL_Delay(1);
	LCD_Send_Command(0x30);
	HAL_Delay(10);
	LCD_Send_Command(0x20);
	HAL_Delay(10);
	LCD_Send_Command(0x28);
	HAL_Delay(1);
	LCD_Send_Command(0x08);
	HAL_Delay(1);
	LCD_Send_Command(0x01);
	HAL_Delay(2);
	LCD_Send_Command(0x06);
	HAL_Delay(1);
	LCD_Send_Command(0x0C);
	HAL_Delay(1);



}

void LCD_Send_Command(uint8_t Command)

{
	uint8_t Data[4];
	Data[0] = (Command & 0xF0 ) | 0x0C  ;                 // Enable = 1, RS = 0
	Data[1] = (Command & 0xF0 ) | 0x08  ;  			 	 // Enable = 0, RS = 0
	Data[2] = ((Command & 0x0F ) << 4) | 0x0C;          // Enable = 1, RS = 0
	Data[3] = ((Command & 0x0F ) << 4) | 0x08;         // Enable = 0, RS = 0



	HAL_I2C_Master_Transmit(& hi2c, LCD_I2C_ADDRESS   , Data, 4U , 100U );



}

void LCD_Send_Data(uint8_t Data)
{
	uint8_t d[4];
	d[0] = (Data & 0xF0) | 0x0D;  				// Enable = 1, RS = 1
	d[1] = (Data & 0xF0) | 0x09;  				// Enable = 0, RS = 1
	d[2] = ((Data & 0x0F) << 4) | 0x0D;  		// Enable = 1, RS = 1
	d[3] = ((Data & 0x0F) << 4) | 0x09;  		// Enable = 0, RS = 1


	HAL_I2C_Master_Transmit(&hi2c, LCD_I2C_ADDRESS, d , 4U, 100U );


}






void LCD_Clear()
{


}



void LCD_Print(const  char  * Message )
{
}


void  Init_GPIO_I2C()
{
GPIO_InitTypeDef GPIO_InitStruct = {0};



	__HAL_RCC_GPIOB_CLK_ENABLE();


	// I2C1 GPIO Configuration
	//PB6     ------> I2C1_SCL
	//PB7     ------> I2C1_SDA
	GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}


void  Init_I2C()
{

	/*------------------ Peripheral clock enable ------------------- */
	__HAL_RCC_I2C1_CLK_ENABLE();

	hi2c.Instance = I2C1;
	hi2c.Init.ClockSpeed = 100000;
	hi2c.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c.Init.OwnAddress1 = 0;
	hi2c.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c.Init.OwnAddress2 = 0;
	hi2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

	 HAL_I2C_Init(  &hi2c   ) ;


}
