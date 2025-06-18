# 📐 Project Architecture

This project focuses on developing **custom, lightweight peripheral drivers** for low-power digital sensors using bare-metal C. It avoids vendor SDKs and HALs, offering complete control for optimization, learning, and real-world deployment.

---

## 🏗️ System Overview

Application Layer (STM32 / ESP32 Demos)
↓
Sensor Driver Layer (DHT12 / MCP3008 / AHT10)
↓
Protocol Abstraction (I2C / SPI / UART)
↓
MCU Hardware (Registers, GPIOs, Interrupts)

yaml
Copy
Edit


---

## 🧱 Layer Descriptions

### 1. Sensor Driver Layer
- Drivers are built **from scratch** based on sensor datasheets.
- Handles sensor init, read/write, and power state management.

### 2. Protocol Layer
- Implements core communication protocols:
  - I2C (bit-banged or register-level)
  - SPI (polling-based, low-latency)
  - UART (non-blocking or polling)
- No middleware or HAL.

### 3. Board Abstraction
- Two MCU families:
  - **STM32**: Low-power modes + I2C/SPI examples
  - **ESP32**: Deep sleep, UART, wakeup from GPIO

---

## 📦 Modular Directory Structure

src/ → Source code for drivers
include/ → Header files
boards/ → Platform-specific demos
docs/ → Architecture, diagrams, power notes


---

## 🧠 Why Custom Drivers?

- Learn hardware-level control
- Achieve better power & memory efficiency
- Make sensor drivers reusable & portable
