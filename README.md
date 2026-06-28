# Smart Gas Leak Detection System

## Overview
This is an Arduino-based Smart Gas Leak Detection System designed to improve safety by detecting gas leaks and automatically responding to them.

## Features
- Detects gas using MQ-2/MQ-6 sensor
- Displays gas status on 16x2 I2C LCD
- Activates buzzer and warning LED
- Opens a window using a servo motor
- Turns OFF the room light using Relay Channel 1
- Turns ON the exhaust fan using Relay Channel 2

## Components Used
- Arduino Uno
- MQ-2 or MQ-6 Gas Sensor
- 16x2 I2C LCD
- Servo Motor
- 2-Channel Relay Module
- Buzzer
- LED
- Jumper Wires
- Breadboard

## Working
The gas sensor continuously monitors the air. If the gas level exceeds the threshold, the Arduino activates the buzzer and LED, displays a warning on the LCD, opens the window with the servo, turns OFF the light, and turns ON the exhaust fan.

## Author
Sayan Bera
