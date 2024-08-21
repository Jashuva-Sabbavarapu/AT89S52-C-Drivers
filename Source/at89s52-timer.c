/*
 * at89s52_timer.c
 * Description: This file contains functions for configuring and controlling the timers/counters
 * Author: 		Jashuva
 * Date: 		june 20, 2024
 * License: 	Open source
 */

// Library for function declarations
#include "at89s52_timer.h"

static uint32_t global_counter = 0;
static uint16_t count = 0;

static void timer0_ISR(void) __interrupt(TIMER0_VECTOR);
static void timer1_ISR(void) __interrupt(TIMER1_VECTOR);

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
void timerConfig(uint8_t Tx, uint8_t TorC, uint8_t mode)
{
	uint8_t Tmod = 0;
	Tmod |= (mode << 0);
	Tmod |= (TorC << 2);

	if(Tx == T0)
	{
		TMOD &= 0xF0;
		TMOD |= Tmod;
	}
	else if(Tx == T1)
	{
		TMOD &= 0x0F;
		TMOD |= Tmod;
	}
}

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
void timerInterruptConfig(uint8_t Tx, uint16_t count, uint8_t mode)
{
	if(mode == ENABLE)
	{
		if(Tx == T0)
		{
			TMOD &= 0xF0;
			TMOD |= 0x01;

			TL0 = count & 0xFF;
			TH0 = (count >> 8) & 0xFF;

			ET0 = 1;
			TR0 = 1;
		}
		else if(Tx == T1)
		{
			TMOD &= 0x0F;
			TMOD |= (0x01 << 4);

			TL1 = count & 0xFF;
			TH1 = (count >> 8) & 0xFF;

			ET1 = 1;
			TR1 = 1;
		}

		EA = 1;
	}
	else if(mode == DISABLE)
	{
		if(Tx == T0)
		{
			ET0 = 0;
			TR0 = 0;
		}
		else if(Tx == T1)
		{
			ET1 = 0;
			TR1 = 1;
		}

		EA = 0;
	}
}


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
void timerLoad(uint8_t Tx, uint16_t load)
{
	if(Tx == T0)
	{
		TL0 = load & 0xFF;
		TH0 = (load >> 8) & 0xFF;
	}
	else if(Tx == T1)
	{
		TL1 = load & 0xFF;
		TH1 = (load >> 8) & 0xFF;
	}
}

/*
 *@fn        -   timerStart
 *
 *@brief     -   Function to start the Timer 0 or 1
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *
 *return     -   void
 */
void timerStart(uint8_t Tx)
{
	if(Tx == T0)
	{
		TR0 = 1;
	}
	else if(Tx == T1)
	{
		TR1 = 1;
	}
}

/*
 *@fn        -   timerFlag
 *
 *@brief     -   Function to check the flag of Timer 0 or 1
 *
TCON |= (1 << 6); *@param[1]  -   Selecting the Timer 0 or 1
 *
 *return     -   void
 */
uint8_t timerFlag(uint8_t Tx)
{
	if(Tx == T0)
	{
		if(TF0 & 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(Tx == T1)
	{
		if(TF1 & 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

/*
 *@fn        -   timerStop
 *
 *@brief     -   Function to stop the Timer 0 or 1
 *
 *@param[1]  -   Selecting the Timer 0 or 1
 *
 *return     -   void
 */
void timerStop(uint8_t Tx)
{
	if(Tx == T0)
	{
		TR0 = 0;
		TF0 = 0;
	}
	else if(Tx == T1)
	{
		TR1 = 0;
		TF1 = 0;
	}
}

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
void getTimerInit(uint8_t Tx, uint8_t timer)
{
	if(timer == MS)
	{
		count = ((1 * CLOCK_SOURCE) / (1000 * 12));
    	count = (65536 - count);

    	timerInterruptConfig(Tx, count, ENABLE);
	}
	else if(timer == US)
	{
		count = ((1 * CLOCK_SOURCE) / (1000000 * 12));
    	count = (65536 - count);

    	timerInterruptConfig(Tx, count, ENABLE);
	}
}

/*
 *@fn        -   getTimer
 *
 *@brief     -   Function to get the current time in milliseconds
 *
 @param[1]   -   void
 *
 *return     -   uint32_t
 */
uint32_t getTimer(void)
{
	uint32_t temp_counter = 0;
	EA = 0;
	temp_counter = global_counter;
	EA = 1;
	return temp_counter;
}

/*
 *@fn        -   delay_us
 *
 *@brief     -   Function to generate 1us delay
 *
 *@param[1]  -   Takes 1us time
 *
 *return     -   void
 */
void delay_us(uint32_t us)
{
    // Calculate the timer value
    uint16_t count = ((1 * CLOCK_SOURCE) / (1000000 * 12));
    count = (65536 - count);

    TMOD &= 0xF0;
    TMOD |= 0x01;

    while(us > 0)
    {
        // Load the Timer 0
        TH0 = (count >> 8) & 0xFF;  // Load higher byte of count
        TL0 = count & 0xFF;  // Load lower byte of count

        // Start Timer 0
        TR0 = 1;  // Set TR0 (Timer 0 Run Control) bit to 1

        while (!TF0);   // Wait until TF0 (Timer 0 Overflow Flag) is set

        // Stop Timer 0
        TR0 = 0;  // Clear TR0 bit to 0
        TF0 = 0;  // Clear TF0 bit to 0
        us--;
    } 
}

/*
 *@fn        -   delay_ms
 *
 *@brief     -   Function to generate 1ms delay
 *
 *@param[1]  -   Takes 1ms time
 *
 *return     -   void
 */
void delay_ms(uint32_t ms)
{
    // Calculate the timer value
    uint16_t count = ((1 * CLOCK_SOURCE) / (1000 * 12));
    count = (65536 - count);

    TMOD &= 0xF0;
    TMOD |= 0x01;

    while(ms > 0)
    {
        // Load the Timer 0
        TH0 = (count >> 8) & 0xFF;  // Load higher byte of count
        TL0 = count & 0xFF;  // Load lower byte of count

        // Start Timer 0
        TR0 = 1;  // Set TR0 (Timer 0 Run Control) bit to 1

        while (!TF0);   // Wait until TF0 (Timer 0 Overflow Flag) is set

        // Stop Timer 0
        TR0 = 0;  // Clear TR0 bit to 0
        TF0 = 0;  // Clear TF0 bit to 0
        ms--;
    }
}

static void timer0_ISR(void) __interrupt(TIMER0_VECTOR)
{
	timerLoad(T0, count);
	global_counter++;
}
static void timer1_ISR(void) __interrupt(TIMER1_VECTOR)
{
	timerLoad(T1, count);
	global_counter++;
}
