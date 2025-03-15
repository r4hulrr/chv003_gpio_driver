# CHV003 GPIO DRIVER

A custom GPIO driver developed for the CHV003 MCU series.

## Table of Contents
- [Overview](#overview)
- [Key Features](#key-features)
- [Directory Structure](#directory-structure)
- [Testing](#testing)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)

## Overview

This project was initiated to gain hands-on experience with reading datasheets from vendors outside of ST and ARM. I chose the RISC-V-based CHV003 series microcontrollers, as these are gaining popularity due to their cost and open source nature. 

This driver simplifies GPIO operations on CH32V003 MCUs by providing an easy-to-use abstraction layer for initialization, data handling, and interrupt management.

## Key Features

- **GPIO Initialization & Deinitialization**: Enables or disables GPIO peripheral clock, configures GPIO pin properties and resets them when needed.
- **Data Read & Write Operations**: Supports reading from input pins, writing to output pins, and toggling pins.
- **Interrupt Configuration & Handling**: Allows GPIO interrupts to be configured, enabled, and handled efficiently.

Each of the API functions in the driver have an easy-to-understand description beforehand, allowing for easy implementation
## Directory Structure

```
CHV003_GPIO_Driver/
├── .mrs/                    
├── Core/
├── Ld/
├── Startup/
├── Testing/
│   ├── Testing code/              // Has the testing code which utilizes WCH Libraries to test  
│   └── Testing Results/           // Included videos and images of tests and their results
├── User/
│   ├── ch32v003.h                 // The main files that include the system specific header file and 
│   └── ch32v003_gpio_driver.c     // GPIO driver header and source file
│   ├── ch32v003_gpio_driver.h
├── obj/
├── .cproject
├── .gitignore.txt
├── .project
├── .template
├── CHV003_GPIO_Driver.launch
├── CHV003_GPIO_Driver.wvproj     // The main project file generated in MounRiverStudio
└── README.md
```

## Testing

Unit tests are available in the `Testing/` directory. These tests validate the functionality of the GPIO driver and can be executed using an embedded-compatible testing framework. Testing was done on the CH32V003F4P6 board. The code and results are provided. Three types of tests were carried out:
1. **Hardware Testing**  
   - Configured a GPIO pin to toggle an LED with a delay.  
   - Verified correct timing and response.  
2. **SWDIO (Debugging) Testing**  
   - Configured a GPIO pin as a trigger for another pin acting as an interrupt.  
   - Used MounRiver Studio’s **memory window** to observe real-time register changes.  
3. **UART Testing**  
   - Configured a GPIO pin to toggle while another acted as an input.  
   - Sent GPIO states over UART and confirmed output via the serial monitor.  

## Getting Started

### Prerequisites
- **Development Environment**: [MounRiver Studio IDE](http://www.mounriver.com/)
- **Hardware**: CHV003F4P6 development board

### Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/r4hulrr/chv003_gpio_driver.git
   ```
2. **Open the Project**:
   Load the `CHV003_GPIO_Driver.wvproj` file in MounRiver Studio IDE.
3. **Use the Driver in Your Project**
   - To integrate into your own project, **copy the files** in `User/` into your workspace.  
   - Alternatively, modify the provided project by adding a `main.c` file in `User/` and start coding!




