# Boardoza GP8403 DAC Board Breakout Board

The **Boardoza GP8403 DAC Board** is a high-precision **dual-channel digital-to-analog converter (DAC) breakout board** designed for applications requiring accurate analog voltage generation from digital signals. Based on the **GP8403**, the board provides **two independent 12-bit analog output channels** that can be controlled over the **I²C communication interface**.

Supporting both **0–5V** and **0–10V** selectable output ranges, this breakout board is ideal for **industrial automation, signal generation, lighting control, motor control, programmable analog outputs, PLC interfacing, laboratory equipment, and other embedded systems requiring reliable analog voltage outputs**.


| Front Side | Back Side |
|:---:|:---:|
| ![GP8403 Front](./assets/GP8403%20Front.png) | ![GP8403 Back](./assets/GP8403%20Back.png) |

---

## Key Features

- **GP8403-Based DAC:** Dual independent analog output channels.
- **12-Bit Resolution:** Smooth and accurate voltage generation with 4096 output levels.
- **Wide Input Supply Voltage Range:** Accepts **3.3VDC to 12VDC input** through the onboard voltage regulator.  
- **Selectable Output Range:** Supports both **0–5V** and **0–10V** analog outputs.
- **I²C Communication:** Easy integration with Arduino, ESP32, STM32, Raspberry Pi, and other microcontrollers.
- **Multi-Device Support:** Supports up to **8 configurable I²C addresses** on the same bus.
- **Protected Outputs:** Built-in short-circuit protection improves reliability.
- **Industrial Ready:** Suitable for automation, process control, and analog interfacing applications.

---

## Technical Specifications

**Model:** GP8403  
**Manufacturer:** Boardoza  
**Manufacturer IC:** Shenzhen Keyi Electronics   
**Functions:** Dual-channel Digital-to-Analog Converter (DAC)  
**DAC Resolution:** 12-bit  
**Communication Interface:** I²C  
**Supply Voltage:** 3.3VDC – 12VDC    
**Output Voltage:** Selectable 0–5V / 0–10V by register   
**Maximum Output Current:** Up to 20mA per channel  
**Output Voltage Accuracy:** ±0.5% (typical)  
**Supported I²C Devices:** Up to 8 on a single bus  
**Operating Temperature:** -40°C to +85°C  
**Board Dimensions:** 40mm × 20mm

---

## Board Pinout

### ( J1 ) I²C Connector

| Pin Number | Pin Name | Description |
|:---:|:---:|---|
| 1 | VCC | Power Supply (3.3VDC–12VDC) |
| 2 | SCLK | I²C Serial Clock |
| 3 | SDA | I²C Serial Data |
| 4 | GND | Ground |

### ( J2 ) Analog Output Connector

| Pin Number | Pin Name | Description |
|:---:|:---:|---|
| 1 | OUT0 | Analog Voltage Output Channel 0 |
| 2 | GND | Ground |
| 3 | OUT1 | Analog Voltage Output Channel 1 |

---

## Board Dimensions

<img src="./assets/GP8403 Dimensions.png" alt="Board Dimensions" width="450"/>

---

## Step Files

[Boardoza GP8403.step](./assets/GP8403%20Step.step)

---

## Datasheet

[GP8403 Datasheet.pdf](./assets/GP8403%20Datasheet.pdf)

---

## Version History

- V1.0.0 - Initial Release

---

## Support

- If you have any questions or need support, please contact **support@boardoza.com**

---

## **License**

This repository contains both hardware and software components:

### **Hardware Design**

[![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

All hardware design files are licensed under [Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

### **Software/Firmware**

[![BSD-3-Clause][bsd-shield]][bsd]

All software and firmware are licensed under [BSD 3-Clause License][bsd].

[bsd]: https://opensource.org/licenses/BSD-3-Clause
[bsd-shield]: https://img.shields.io/badge/License-BSD%203--Clause-blue.svg
