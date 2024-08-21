#ifndef AT89S52_GPIO_H
#define AT89S52_GPIO_H

/*
 * at89s52_gpio.h
 * Description: This header files contains function declaration for at89s52_gpio.c file
 * Author: 		Jashuva
 * Date: 		june 20, 2024
 * License: 	Open source
 */

// Library for AT89S52 MCU, contains mnemounics for SFR's  
#include "at89s52.h"


/*
 *@fn        -   gpioMode
 *
 *@brief     -   Function to set the GPIO pin as input or output
 *
 *@param[1]  -   GPIO ports selection
 *@param[2]  -   Pin number of GPIO ports
 *@param[3]  -   enabling INPUT or OUTPUT
 *
 *return     -   void
 */
void gpioPinMode(uint8_t port, uint8_t pinNum, uint8_t value);

/*
 *@fn        -   gpioPortMode
 *
 *@brief     -   Function to set the GPIO port as input or output
 *
 *@param[1]  -   GPIO ports selection
 *@param[2]  -   value to write
 *
 *return     -   void
 */
void gpioPortMode(uint8_t port, uint8_t value);

/*
 *@fn        -   gpioPortWrite
 *
 *@brief     -   Function to write to the GPIO port
 *
 *@param[1]  -   GPIO ports selection
 *@param[2]  -   value to write
 *
 *return     -   void
 */
void gpioPortWrite(uint8_t port, uint8_t value);

/*
 *@fn        -   gpioPinWrite
 *
 *@brief     -   Function to write to the GPIO pin
 *
 *@param[1]  -   GPIO ports selection
 *@param[2]  -   Pin number of GPIO ports
 *@param[3]  -   value to write
 *
 *return     -   void
 */
void gpioPinWrite(uint8_t port, uint8_t pinNum, uint8_t value);

/*
 *@fn        -   gpioPortToggle
 *
 *@brief     -   Function to toggle the GPIO port
 *
 *@param[1]  -   GPIO ports selection
 *
 *return     -   void
 */
void gpioPortToggle(uint8_t port);

/*
 *@fn        -   gpioPinToggle
 *
 *@brief     -   Function to toggle the GPIO port
 *
 *@param[1]  -   GPIO ports selection
 *@param[2]  -   Pin number of GPIO ports
 *
 *return     -   void
 */
void gpioPinToggle(uint8_t port, uint8_t pinNum);

/*
 *@fn        -   gpioPortRead
 *
 *@brief     -   Function to read from the GPIO port
 *
 *@param[1]  -   GPIO ports selection
 *
 *return     -   uint8_t
 */
uint8_t gpioPortRead(uint8_t port);

/*
 *@fn        -   gpioPinRead
 *
 *@brief     -   Function to read from the GPIO pin
 *
 *@param[1]  -   GPIO ports selection
 *@param[2]  -   Pin number of GPIO ports
 *
 *return     -   uint8_t
 */
uint8_t gpioPinRead(uint8_t port, uint8_t pinNum);

/*
 *@fn        -   gpioInterruptConfig
 *
 *@brief     -   Function to configure the interrupt
 *
 *@param[1]  -   INTx to select the INT0 or INT1
 *@param[2]  -   To select the falling or (-ve)edge triggring
 *@param[3]  -	 Enable or disable the INTx
 *
 *return     -   void
 */
void gpioInterruptConfig(uint8_t INTx, uint8_t mode, uint8_t EorD);

#endif // at89s52_gpio.h
