#include "at89s52_serial.h" // 10526 baud rate

static void intToStr(int num, char *str);
/*
 * at89s52_serial.c
 * Description:     This file contains the functions to configure and send/receive data using UART
 * Author:          Jashuva
 * Date:            June 20, 2024
 * License:         Open source
 */

/*
 *@fn        -   serialInit
 *
 *@brief     -   Function to configure the UART
 *
 *@param[1]  -   Parameter takes the baud rate value
 *
 *return     -   void
 */
void serialInit(uint32_t baud)
{
    TMOD &= 0x0F;
    TMOD = 0x20;
    uint8_t value = CLOCK_SOURCE / (12 * 32 * baud);
    value = 256 - value;
    TH1 = value;
    TR1 = 1;

    SCON = 0x50;
    TI = 1;
}

/*
 *@fn        -   serialTx
 *
 *@brief     -   Function to transmit 1 byte of data
 *
 *@param[1]  -   Data buffer to transmit
 *
 *return     -   void
 */
void serialTx(uint8_t buffer)
{
    SBUF = buffer;
    while (!TI);
    TI = 0;
}

/*
 *@fn        -   serialRx
 *
 *@brief     -   Function to receive 1 byte of data and return the data
 *
 *@param[1]  -   void
 *
 *return     -   uint8_t
 */
uint8_t serialRx(void)
{
    while (!RI);
    RI = 0;
    return SBUF;
}

/*
 *@fn        -   serialPrint
 *
 *@brief     -   Function to transmit the data string
 *
 *@param[1]  -   Buffer reference for transmitting
 *@param[2]  -   For multiple parameters
 *
 *return     -   void
 */
void serialPrint(uint8_t *buffer, ...)
{
    va_list args;
    va_start(args, buffer);

    for (const uint8_t *p = buffer; *p != '\0'; p++)
    {
        if (*p == '%')
        {
            p++;
            switch (*p)
            {
                case 'd': {
                    int i = va_arg(args, int);
                    char temp[10];
                    intToStr(i, temp);
                    serialWrite((uint8_t *)temp);
                    break;
                }

                case 'c': {
                    char c = (char)va_arg(args, int); // char promoted to int
                    serialTx((uint8_t)c);
                    break;
                }

                case 's': {
                    char *str = va_arg(args, char *);
                    serialWrite((uint8_t *)str);
                    break;
                }

                default:
                    serialWrite((uint8_t *)"Error finding the format specifier");
                    break;
            }
        }
        else
        {
            serialTx(*p);
        }
    }

    va_end(args);
}

/*
 *@fn        -   serialWrite
 *
 *@brief     -   Function to transmit the data string
 *
 *@param[1]  -   Buffer reference for transmitting
 *
 *return     -   void
 */
void serialWrite(uint8_t *buffer)
{
    while (*buffer != '\0')
    {
        serialTx(*buffer++);
    }
}

/*
 *@fn        -   serialRead
 *
 *@brief     -   Function to read the data string and return it
 *
 *@param[1]  -   Buffer reference to store the data
 *@param[2]  -   Maximum length of the string
 *
 *return     -   void
 */
void serialRead(uint8_t *buffer, uint16_t maxLen)
{
    uint8_t i = 0;
    while (i < maxLen - 1) // Leave space for null terminator
    {
        buffer[i] = serialRx();
        if (buffer[i] == '\n' || buffer[i] == '\r') // Check for newline or carriage return
        {
            break;
        }
        i++;
    }
    buffer[i] = '\0'; // Null-terminate the string
}


/*
 *@fn        -   intToStr
 *
 *@brief     -   Convert an integer to a string
 *
 *@param[1]  -   Integer to convert
 *@param[2]  -   Buffer to store the resulting string
 *
 *return     -   void
 */
static void intToStr(int num, char *str)
{
    char temp[10];
    int i = 0, j;

    // Handle 0 explicitly
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Process individual digits
    while (num != 0)
    {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }

    // Append digits in reverse order
    for (j = i - 1; j >= 0; j--)
        str[i - j - 1] = temp[j];

    str[i] = '\0';
}
