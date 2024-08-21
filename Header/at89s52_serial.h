#ifndef AT89S52_SERIAL_H
#define AT89S52_SERIAL_H

/*
 * at89s52_serial.h
 * Description: This header files contains function declaration for at89s52_serial.c file
 * Author: 		Jashuva
 * Date: 		june 20, 2024
 * License: 	Open source
 */

/* Standard library for standard args and i/o*/
#include <stdarg.h>
#include <stdio.h>
// Library for AT89S52 MCU, contains mnemounics for SFR's  
#include "at89s52.h"

/*
 *@fn        -   serialInit
 *
 *@brief     -   Function to configure the UART
 *
 *@param[1]  -   Parameter will takes the baud rate value
 *
 *return     -   void
 */
void serialInit(uint32_t baud);

/*
 *@fn        -   serialTx
 *
 *@brief     -   Function to transmitt 1byte data
 *
 *@param[1]  -   Data buffer to transmit
 *
 *return     -   void
 */
void serialTx(uint8_t buffer);

/*
 *@fn        -   serialRx
 *
 *@brief     -   Function to receive 1byte data and return the data
 *
 *@param[1]  -   void
 *
 *return     -   uint8_t
 */
uint8_t serialRx(void);

/*
 *@fn        -   serialPrint
 *
 *@brief     -   Function to transmitt the data string
 *
 *@param[1]  -   Buffer reference for transmitting
 *@param[2]  -   For multiple parameters
 *
 *return     -   void
 */
void serialPrint(uint8_t *buffer, ...);

/*
 *@fn        -   serialWrite
 *
 *@brief     -   Function to receive 1byte data and return the data
 *
 *@param[1]  -   Buffer reference for transmitting
 *
 *return     -   void
 */
void serialWrite(uint8_t *buffer);

/*
 *@fn        -   serialRead
 *
 *@brief     -   Function to read the data string and returns
 *
 *@param[1]  -   buffer reference to store the data
 *@param[2]  -	 Maximum length of the string
 *
 *return     -   void
 */
void serialRead(uint8_t *buffer, uint16_t maxLen);

#endif // at89s52_serial.h
