# AT89S52-C-Drivers

This repository contains driver code written in Embedded C for the AT89S52 microcontroller. These drivers are designed to help you interface with the various peripherals of the AT89S52 microcontroller, making it easier to develop embedded systems projects.

## Repository Structure

The repository is organized as follows:
.
├── Header/                 # Contains header files (.h) for the drivers
│   ├── at89s52.h           # Main header file for the AT89S52 microcontroller
│   ├── at89s52_gpio.h      # GPIO driver header file
│   ├── at89s52_serial.h    # UART (serial) driver header file
│   └── at89s52_timer.h     # Timer driver header file
│
└── Source/                 # Contains source files (.c) for the drivers
    ├── at89s52_gpio.c      # GPIO driver source file
    ├── at89s52_serial.c    # UART (serial) driver source file
    └── at89s52_timer.c     # Timer driver source file
