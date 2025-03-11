# CHV003 GPIO DRIVER

A custom GPIO driver developed for the CHV003 microcontroller (MCU), specifically designed for the CHV003F4P6 board. 

## Table of Contents
- [Overview](#overview)
- [Key Features](#key-features)
- [Directory Structure](#directory-structure)
- [Testing](#testing)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)

## Overview

This project was initiated to gain hands-on experience with reading datasheets from vendors outside of ST and ARM. I chose the RISC-V-based CHV003 series microcontrollers, as these are gaining popularity due to their open source nature. 

The **CHV003 GPIO Driver** provides an abstraction layer for configuring and controlling the General-Purpose Input/Output (GPIO) pins, ensuring a structured and efficient way to interact with the microcontroller’s peripherals.

## Key Features

- **GPIO Initialization & Deinitialization**: Enables or disables GPIO peripheral clock, configures GPIO pin properties and resets them when needed.
- **Data Read & Write Operations**: Supports reading from input pins, writing to output pins, and toggling pins.
- **Interrupt Configuration & Handling**: Allows GPIO interrupts to be configured, enabled, and handled efficiently.

Each of the API functions in the driver have an easy-to-understand description beforehand, allowing for easy implementation
## Directory Structure

```
CHV003_GPIO_Driver/
├── Core/
│   ├── gpio.c
│   └── gpio.h
├── Startup/
│   ├── startup.s
│   └── system_init.c
├── User/
│   ├── main.c
│   └── user_config.h
├── Testing/
│   ├── test_gpio.c
│   └── mock_gpio.h
├── Ld/
│   └── linker_script.ld
├── .gitignore
├── README.md
└── CHV003_GPIO_Driver.wvproj
```

## Testing

Unit tests are available in the `Testing/` directory. These tests validate the functionality of the GPIO driver and can be executed using an embedded-compatible testing framework.

## Getting Started

### Prerequisites
- **Development Environment**: [MounRiver Studio IDE](http://www.mounriver.com/)
- **Toolchain**: RISC-V GCC Compiler
- **Hardware**: CHV003F4P6 development board

### Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/r4hulrr/chv003_gpio_driver.git
   ```
2. **Open the Project**:
   Load the `CHV003_GPIO_Driver.wvproj` file in MounRiver Studio IDE.
3. **Build the Project**:
   Compile the source code to generate the firmware binary.
4. **Flash the Firmware**:
   Upload the binary to the CHV003F4P6 board using a compatible programmer.


