#ifndef AT89S52_TIMER_H
#define AT89S52_TIMER_H

/*
 * at89s52_timer.h
 * Description: This header files contains function declarations for at89s52_timer.c file
 * Author: 		Jashuva
 * Date: 		june 20, 2024
 * License: 	Open source
 */

// Library for AT89S52 MCU, contains mnemounics for SFR's
#include "at89s52.h"


/*
 *@fn        -   timerConfig
 *
 *@brief     -   Function to configure the Timer 0 and Timer 1
 *
 *@param[1]  -   Timer 0 or 1 selection
 *@param[2]  -   Setting it to be Timer or Counter
 *@param[3]  -   Setting the Timer or Counter in 4 diffrent modes
 *
 *return     -   void
 */
void timerConfig(uint8_t Tx, uint8_t TorC, uint8_t mode);

/*
 *@fn        -   timerInterruptConfig
 *
 *@brief     -   Function to config the T0 or T1 has timer interrupt
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *@param[2]	 -	 count value to load
 *@param[2]  -   Enabling or Disabling the mode
 *
 *return     -   void
 */
void timerInterruptConfig(uint8_t Tx, uint16_t count, uint8_t mode);

/*
 *@fn        -   timerLoad
 *
 *@brief     -   Function to load the Timer 0 and Timer 1, TH's and TL's
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *@param[2]  -   Loading the value to the TH's and TL's register
 *
 *return     -   void
 */
void timerLoad(uint8_t Tx, uint16_t load);

/*
 *@fn        -   timerStart
 *
 *@brief     -   Function to start the Timer 0 or 1
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *
 *return     -   void
 */
void timerStart(uint8_t Tx);

/*
 *@fn        -   timerFlag
 *
 *@brief     -   Function to check the flag of Timer 0 or 1
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *
 *return     -   void
 */
uint8_t timerFlag(uint8_t Tx);

/*
 *@fn        -   timerStop
 *
 *@brief     -   Function to stop the Timer 0 or 1
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *
 *return     -   void
 */
void timerStop(uint8_t Tx);

/*
 *@fn        -   getTimerInit
 *
 *@brief     -   Function to configure the timer for getTimer function
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *@param[2]  -   Value for selecting ms or us
 *
 *return     -   void
 */
void getTimerInit(uint8_t Tx, uint8_t timer);

/*
 *@fn        -   getTimer
 *
 *@brief     -   Function to get the current time in milliseconds
 *
 @param[1]   -   void
 *
 *return     -   uint32_t
 */
uint32_t getTimer(void);

/*
 *@fn        -   delay_us
 *
 *@brief     -   Function to generate 1us delay
 *
 *@param[1]  -   Takes 1us time
 *
 *return     -   void
 */
void delay_us(uint32_t us);

/*
 *@fn        -   delay_ms
 *
 *@brief     -   Function to generate 1ms delay
 *
 *@param[1]  -   Takes 1ms time
 *
 *return     -   void
 */
void delay_ms(uint32_t ms);

#endif
