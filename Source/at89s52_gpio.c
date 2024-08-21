/*
 * at89s52_gpio.c
 * Description: This files contains functions for configuring and read/write the GPIO ports
 * Author:      Jashuva
 * Date:        june 20, 2024
 * License:     Open source
 */

// Library for function declarations
#include "at89s52_gpio.h"


/*
 *@fn        -   gpioMode
 *
 *@brief     -   Function to set the GPIO as input or output
 *
 *@param[1]  -   GPIO ports selection
 *@param[2]  -   Pin number of GPIO ports
 *@param[3]  -   enabling INPUT or OUTPUT
 *
 *return     -   void
 */
void gpioPinMode(uint8_t port, uint8_t pinNum, uint8_t mode)
{
    uint8_t mask = 1 << pinNum;
    if (mode == OUTPUT)
    {
        switch (port)
        {
        case PORT0:
            P0 &= ~mask; // Clear bit to set as output
            break;
        case PORT1:
            P1 &= ~mask;
            break;
        case PORT2:
            P2 &= ~mask;
            break;
        case PORT3:
            P3 &= ~mask;
            break;
        }
    }
    else if (mode == INPUT)
    {
        switch (port)
        {
        case PORT0:
            P0 |= mask; // Set bit to set as input
            break;
        case PORT1:
            P1 |= mask;
            break;
        case PORT2:
            P2 |= mask;
            break;
        case PORT3:
            P3 |= mask;
            break;
        }
    }
}

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
void gpioPortMode(uint8_t port, uint8_t mode)
{
    uint8_t mask = 0xFF;
    if (mode == OUTPUT)
    {
        switch (port)
        {
        case PORT0:
            P0 &= ~mask;
            break;
        case PORT1:
            P1 &= ~mask;
            break;
        case PORT2:
            P2 &= ~mask;
            break;
        case PORT3:
            P3 &= ~mask;
            break;
        }
    }
    else if (mode == INPUT)
    {
        switch (port)
        {
        case PORT0:
            P0 |= mask;
            break;
        case PORT1:
            P1 |= mask;
            break;
        case PORT2:
            P2 |= mask;
            break;
        case PORT3:
            P3 |= mask;
            break;
        }
    }
}

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
void gpioPortWrite(uint8_t port, uint8_t value)
{
    switch (port)
    {
    case PORT0:
        P0 = value;
        break;
    case PORT1:
        P1 = value;
        break;
    case PORT2:
        P2 = value;
        break;
    case PORT3:
        P3 = value;
        break;
    }
}

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
void gpioPinWrite(uint8_t port, uint8_t pinNum, uint8_t value)
{
    uint8_t mask = 1 << pinNum;
    switch (port)
    {
    case PORT0:
        if (value)
            P0 |= mask; // Set bit
        else
            P0 &= ~mask; // Clear bit
        break;
    case PORT1:
        if (value)
            P1 |= mask;
        else
            P1 &= ~mask;
        break;
    case PORT2:
        if (value)
            P2 |= mask;
        else
            P2 &= ~mask;
        break;
    case PORT3:
        if (value)
            P3 |= mask;
        else
            P3 &= ~mask;
        break;
    }
}

/*
 *@fn        -   gpioPortToggle
 *
 *@brief     -   Function to toggle the GPIO port
 *
 *@param[1]  -   GPIO ports selection
 *
 *return     -   void
 */
void gpioPortToggle(uint8_t port)
{
    switch (port)
    {
    case PORT0:
        P0 ^= 0xFF;
        break;

    case PORT1:
        P1 ^= 0xFF;
        break;

    case PORT2:
        P2 = 0xFF;
        break;

    case PORT3:
        P3 = 0xFF;
        break;
    }
}

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
void gpioPinToggle(uint8_t port, uint8_t pinNum)
{
    switch (port)
    {
    case PORT0:
        P0 ^= (1 << pinNum);
        break;

    case PORT1:
        P1 ^= (1 << pinNum);
        break;

    case PORT2:
        P2 ^= (1 << pinNum);
        break;

    case PORT3:
        P3 ^= (1 << pinNum);
        break;
    }
}

/*
 *@fn        -   gpioPortRead
 *
 *@brief     -   Function to read from the GPIO port
 *
 *@param[1]  -   GPIO ports selection
 *
 *return     -   uint8_t
 */
uint8_t gpioPortRead(uint8_t port)
{
    switch (port)
    {
    case PORT0:
        return P0;
    case PORT1:
        return P1;
    case PORT2:
        return P2;
    case PORT3:
        return P3;
    default:
        return 0; // Invalid port
    }
}

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
uint8_t gpioPinRead(uint8_t port, uint8_t pinNum)
{
    uint8_t mask = 1 << pinNum;
    switch (port)
    {
    case PORT0:
        return (P0 & mask) ? 1 : 0;
    case PORT1:
        return (P1 & mask) ? 1 : 0;
    case PORT2:
        return (P2 & mask) ? 1 : 0;
    case PORT3:
        return (P3 & mask) ? 1 : 0;
    default:
        return 0; // Invalid port
    }
}

/*
 *@fn        -   gpioInterruptConfig
 *
 *@brief     -   Function to configure the interrupt
 *
 *@param[1]  -   INTx to select the INT0 or INT1
 *@param[2]  -   To select the falling or (-ve)edge triggring
 *@param[3]  -   Enable or disable the INTx
 *
 *return     -   void
 */
void gpioInterruptConfig(uint8_t INTx, uint8_t mode, uint8_t EorD)
{
    if(INTx == INT0_VECTOR)
    {
        if(mode == FALLING)
        {
            IT0 = FALLING;
        }
        else
        {
            IT0 = ~FALLING;
        }

        if(EorD == ENABLE)
        {
            EX0 = ENABLE;
        }
        else
        {
            EX0 = ~ENABLE;
        }
    }
    else if(INTx == INT1_VECTOR)
    {
        if(mode == FALLING)
        {
            IT1 = FALLING;
        }
        else
        {
            IT1 = ~FALLING;
        }

        if(EorD == ENABLE)
        {
            EX1 = ENABLE;
        }
        else
        {
            EX1 = ~ENABLE;
        }
    }

    if(EorD == ENABLE)
    {
        EA = ENABLE;
    }
    else
    {
        EA = ~ENABLE;
    }
}
