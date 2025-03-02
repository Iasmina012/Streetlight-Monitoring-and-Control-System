# Streetlight-Monitoring-and-Control-System

## Overview

This project aims to reduce electricity consumption by activating streetlights only when motion is detected and in low-light conditions. The system utilizes sensors to detect movement and ambient light levels, improving energy efficiency.

## Architecture
![arhitectura](https://github.com/user-attachments/assets/e670d7d7-03ff-4c9b-a600-7893052f7634)

## UML Diagram

<img width="305" alt="UML" src="https://github.com/user-attachments/assets/e2f1a7f2-0224-40b1-91dd-639c32349c1d" />

## Technologies Used

- **Arduino**
- **C**
- **Python**

## Hardware Components

### Arduino UNO R3 Development Board

- Operating Voltage: 5V
- Power Jack Voltage: 7V - 12V
- I/O Pins: 14 (6 PWM)
- ADC Pins: 8
- Flash Memory: 32kB (8kB used by bootloader)
- Communication: TWI, SPI, and UART
- Operating Frequency: 16 MHz

![image](https://github.com/user-attachments/assets/c38f8f2d-f184-4c17-bb4c-5689a0ccc812)

### HC-05 Bluetooth Module

- Operating Voltage: 3.6V - 6V
- Maximum Current Consumption: 30mA
- Baudrate: 9600 - 460800 bps
- Transmission Distance: up to 10m
  
![image](https://github.com/user-attachments/assets/8c76ecc5-4c12-410e-9c76-09642a369550)

### PIR Motion Sensor

- Operating Voltage: DC 3V-5V
- Detection Distance: 3 - 7m (adjustable)
- Detection Angle: < 140°

![image](https://github.com/user-attachments/assets/fc9698db-60b8-494c-ad1a-70bcf9717e95)

### Light Sensor Module

- Operating Voltage: 3.3V - 5V
- Output: Digital switch display (0 and 1)
- Detection Distance: 3 - 7m (adjustable)
  
![image](https://github.com/user-attachments/assets/7624bc70-3c15-451e-abf2-4b1b71f4076d)

### LED

- Maximum Current: 20mA
- Voltage Range: 1.63V - 4.4V (depending on color)

### Additional Components

- **Resistors**: Adjust current flow and prevent damage.
- **Breadboard**: Facilitates circuit prototyping.

## Software Description

This system is controlled via an Android application developed using MIT App Inventor. The app sends control signals via Bluetooth to the Arduino board, which processes and executes the corresponding commands.

## Functionalities

- **'0'**: Turn off LED.
- **'1'**: Turn on LED.
- **'2'**: Control LED based on motion sensor.
- **'3'**: Control LED based on light sensor.
- **'4'**: Control LED based on both sensors.

## Application Implementation

### App Diagram 

![image](https://github.com/user-attachments/assets/320290fd-902c-4b34-8619-a5aa4e32a4b7)

### App Features

The Android app consists of five buttons, each assigned to a different functionality of the system. The app interface allows users to control streetlights efficiently.

![image](https://github.com/user-attachments/assets/9d26fff6-f2aa-49aa-b7ce-84a45190059b)

### Steps to Use the System

1. Activate Bluetooth on your phone.
2. Pair the phone with the HC-05 Bluetooth module.
3. Open the application and establish a Bluetooth connection.
4. Use the interface to send commands to the Arduino board.

## Block Diagram

The system architecture includes the Arduino board, Bluetooth module, sensors, and LEDs, all working together to optimize energy usage.

![image](https://github.com/user-attachments/assets/25f1e16d-dd52-41d2-9ace-aa8a7a263962)
