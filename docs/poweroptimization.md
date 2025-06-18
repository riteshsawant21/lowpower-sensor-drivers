# 🔋 Power Optimization Strategies

Embedded systems often operate on battery or energy-constrained environments. This project applies multiple techniques to keep energy usage minimal without losing functional reliability.

---

## 🔌 Sensor-Level Techniques

### ✅ DHT12 (I2C Temp + Humidity)
- Initiate reading only when needed (polling strategy)
- Put the sensor to sleep after each read using available commands (if supported)

### ✅ MCP3008 (SPI ADC)
- Power off analog sensor connected to MCP3008 when not in use
- Keep SPI clock off until needed (software-controlled CS)

### ✅ AHT10 (UART)
- Use sleep mode command in datasheet
- UART enabled only during communication; disabled otherwise

---

## ⚙️ Microcontroller-Level Optimizations

### STM32:
- Use `SLEEP` / `STOP` modes when idle
- Enable wake-up via external interrupt (from sensor or timer)
- Minimize system clock when not transmitting

### ESP32:
- Deep sleep with wakeup via GPIO or timer
- Disable unused peripherals (e.g., ADC, WiFi, Bluetooth)
- Use RTC memory to store state between sleep cycles

---

## 🧠 Software Best Practices

- Delay-based polling instead of busy loops
- Avoid floating point and large buffers
- Organize sensor reads using modular, interrupt-friendly design

---

## 📊 To Be Added: Power Profiling

- Measure total current during active vs. sleep states
- Compare power draw: vendor driver vs custom driver
- Evaluate battery life under different polling intervals
