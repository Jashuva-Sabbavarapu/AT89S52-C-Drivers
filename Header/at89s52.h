#ifndef AT89S52_H
#define AT89S52_H

/*
 * at89s52.h
 * Description: This header file contains mnemonics for bit and byte addressable SFRs and
 *              general macros for AT89S52 MCU.
 * Author:      Jashuva
 * Date:        June 20, 2024
 * License:     Open source
 */

/* Standard library for proper data types */
#include <stdint.h>

/*------------------------------Byte and Bit addressable SFRs--------------------------------------------*/

/* BYTE addressable registers */
__sfr __at 0x80 P0;
__sfr __at 0x81 SP;
__sfr __at 0x82 DPL;
__sfr __at 0x83 DPH;
__sfr __at 0x87 PCON;
__sfr __at 0x88 TCON;
__sfr __at 0x89 TMOD;
__sfr __at 0x8A TL0;
__sfr __at 0x8B TL1;
__sfr __at 0x8C TH0;
__sfr __at 0x8D TH1;
__sfr __at 0x90 P1;
__sfr __at 0x98 SCON;
__sfr __at 0x99 SBUF;
__sfr __at 0xA0 P2;
__sfr __at 0xA8 IE;
__sfr __at 0xB0 P3;
__sfr __at 0xB8 IP;
__sfr __at 0xC8 T2CON;
__sfr __at 0xC9 T2MOD;
__sfr __at 0xCA RCAP2L;
__sfr __at 0xCB RCAP2H;
__sfr __at 0xCC TL2;
__sfr __at 0xCD TH2;
__sfr __at 0xD0 PSW;
__sfr __at 0xE0 ACC;
__sfr __at 0xF0 B;

/* BIT addressable registers */
/* P0 */
__sbit __at 0x80 P0_0;
__sbit __at 0x81 P0_1;
__sbit __at 0x82 P0_2;
__sbit __at 0x83 P0_3;
__sbit __at 0x84 P0_4;
__sbit __at 0x85 P0_5;
__sbit __at 0x86 P0_6;
__sbit __at 0x87 P0_7;

/* TCON */
__sbit __at 0x88 IT0;
__sbit __at 0x89 IE0;
__sbit __at 0x8A IT1;
__sbit __at 0x8B IE1;
__sbit __at 0x8C TR0;
__sbit __at 0x8D TF0;
__sbit __at 0x8E TR1;
__sbit __at 0x8F TF1;

/* P1 */
__sbit __at 0x90 P1_0;
__sbit __at 0x91 P1_1;
__sbit __at 0x92 P1_2;
__sbit __at 0x93 P1_3;
__sbit __at 0x94 P1_4;
__sbit __at 0x95 P1_5;
__sbit __at 0x96 P1_6;
__sbit __at 0x97 P1_7;

/* Timer 2 Control */
__sbit __at 0x90 T2;
__sbit __at 0x91 T2EX;

/* SCON */
__sbit __at 0x98 RI;
__sbit __at 0x99 TI;
__sbit __at 0x9A RB8;
__sbit __at 0x9B TB8;
__sbit __at 0x9C REN;
__sbit __at 0x9D SM2;
__sbit __at 0x9E SM1;
__sbit __at 0x9F SM0;

/* P2 */
__sbit __at 0xA0 P2_0;
__sbit __at 0xA1 P2_1;
__sbit __at 0xA2 P2_2;
__sbit __at 0xA3 P2_3;
__sbit __at 0xA4 P2_4;
__sbit __at 0xA5 P2_5;
__sbit __at 0xA6 P2_6;
__sbit __at 0xA7 P2_7;

/* IE */
__sbit __at 0xA8 EX0;
__sbit __at 0xA9 ET0;
__sbit __at 0xAA EX1;
__sbit __at 0xAB ET1;
__sbit __at 0xAC ES;
__sbit __at 0xAD ET2;
__sbit __at 0xAF EA;

/* P3 */
__sbit __at 0xB0 P3_0;
__sbit __at 0xB1 P3_1;
__sbit __at 0xB2 P3_2;
__sbit __at 0xB3 P3_3;
__sbit __at 0xB4 P3_4;
__sbit __at 0xB5 P3_5;
__sbit __at 0xB6 P3_6;
__sbit __at 0xB7 P3_7;

__sbit __at 0xB0 RXD;
__sbit __at 0xB1 TXD;
__sbit __at 0xB2 INT0;
__sbit __at 0xB3 INT1;
__sbit __at 0xB4 T0;
__sbit __at 0xB5 T1;
__sbit __at 0xB6 WR;
__sbit __at 0xB7 RD;

/* IP */ 
__sbit __at 0xB8 PX0;
__sbit __at 0xB9 PT0;
__sbit __at 0xBA PX1;
__sbit __at 0xBB PT1;
__sbit __at 0xBC PS;
__sbit __at 0xBD PT2;

/* T2CON */
__sbit __at 0xC8 CP_RL2;
__sbit __at 0xC9 C_T2;
__sbit __at 0xCA TR2;
__sbit __at 0xCB EXEN2;
__sbit __at 0xCC TCLK;
__sbit __at 0xCD RCLK;
__sbit __at 0xCE EXF2;
__sbit __at 0xCF TF2;

/* PSW */
__sbit __at 0xD0 P;
__sbit __at 0xD1 FL;
__sbit __at 0xD2 OV;
__sbit __at 0xD3 RS0;
__sbit __at 0xD4 RS1;
__sbit __at 0xD5 F0;
__sbit __at 0xD6 AC;
__sbit __at 0xD7 CY;

/*----------------------------------------General Macros--------------------------------------------------*/
#define ENABLE 1
#define DISABLE 0

// GPIO general macros
#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3

#define OUTPUT 0
#define INPUT 1

#define HIGH 1
#define LOW 0

#define FALLING 1
#define LEVEL 0

// TIMER general macros
#define T0 0
#define T1 1
#define T2 2

#define TIMER 0
#define COUNTER 1

#define TIMER_MODE0 0
#define TIMER_MODE1 1
#define TIMER_MODE2 2
#define TIMER_MODE3 3

#define MS 0
#define US 1

/*------------------------------At89s52 Crystal Clock Frequency------------------------------------------*/
#define CLOCK_SOURCE 12000000UL

/* Interrupt numbers: address = (number * 8) + 3 */
#define INT0_VECTOR        0       /* 0x03 external interrupt 0 */
#define TIMER0_VECTOR      1       /* 0x0b timer 0 */
#define INT1_VECTOR        2       /* 0x13 external interrupt 1 */
#define TIMER1_VECTOR      3       /* 0x1b timer 1 */
#define SERIAL_VECTOR      4       /* 0x23 serial port 0 */
#define TIMER2_VECTOR      5       /* 0x2B timer 2 */

#endif // AT89S52_H
