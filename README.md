# 🔌 Customised Peripheral Driver Development for Low Power Sensors

This repository demonstrates the development of **bare-metal, lightweight drivers** for interfacing **low-power digital sensors** with microcontrollers like STM32 and ESP32 — **without** relying on vendor-provided HALs or SDKs.

The aim is **not just to make sensors work**, but to do it in a **power-aware**, **modular**, and **optimized** manner — ideal for battery-powered applications such as wearables, remote sensing, and environmental monitoring.

---

## 📦 Project Structure
<pre> ```plaintext custom-lowpower-sensor-drivers/ ├── README.md ├── LICENSE ├── docs/ │ ├── architecture.md │ ├── power-optimization.md │ └── interface-diagram.png ├── src/ │ ├── i2c/ │ │ └── dht12_driver.c │ ├── spi/ │ │ └── mcp3008_driver.c │ └── uart/ │ └── aht10_driver.c ├── include/ │ ├── i2c/ │ │ └── dht12_driver.h │ ├── spi/ │ │ └── mcp3008_driver.h │ ├── uart/ │ │ └── aht10_driver.h │ └── common/ │ └── utils.h ├── boards/ │ ├── stm32/ │ │ └── main.c │ └── esp32/ │ └── deep_sleep_driver_test.c └── tests/ └── mock_run_logs/ ├── stm32_log.txt └── esp32_log.txt ``` </pre>

---

## 🎯 Why This Project?

> 💡 In the world of embedded systems, **vendor SDKs and HALs** make things easier — but they come with bloat, lack transparency, and consume power unnecessarily.

By developing **custom drivers**, we:
- Gain **full control** over sensor behavior and microcontroller resources
- Minimize power usage by **managing sensor power states**
- Improve startup time, reduce memory footprint
- Learn the fundamentals of **bare-metal embedded systems development**

---

## 🧰 Tech Stack

- ⚙️ **Microcontrollers**: STM32F4 Series, ESP32 (Xtensa)
- 💾 **Interfaces**: I2C, SPI, UART (bit-bang or register-level)
- 🧠 **Language**: C (No HAL or RTOS)
- 🔋 **Low Power**: ESP32 Deep Sleep APIs, Sensor Sleep Management

---

## 🧪 Mock Output Logs

Want to see what the output looks like without real hardware?

- [📄 STM32 Test Logs](tests/mock_run_logs/stm32_log.txt)
- [📄 ESP32 Deep Sleep Logs](tests/mock_run_logs/esp32_log.txt)

---

## 🧱 Sensors Used

- **DHT12** — I2C, Low-power temp & humidity sensor
- **MCP3008** — SPI, 8-channel ADC (great for analog sensors like LDRs)
- **AHT10 (UART Sim)** — UART-based simulated version of a temperature/humidity sensor for educational use

---

## 📁 Docs

- [`architecture.md`](docs/architecture.md) — System design, communication strategy
- [`power-optimization.md`](docs/power-optimization.md) — Power handling per interface & board
- [`interface-diagram.png`](docs/interface-diagram.png) — Visual diagram of sensor-MCU setup *(upload pending)*

---

## 🛠️ Build & Test Instructions

> ⚠️ No build system or makefiles are provided — intended for integration with STM32CubeIDE or ESP-IDF.

### STM32
- Compile `main.c` in your STM32 IDE with relevant `src/` and `include/` files
- Ensure `utils.h` maps to your board's I2C/SPI/UART implementation

### ESP32
- Use ESP-IDF
- Place `deep_sleep_driver_test.c` inside a project’s `main/` folder
- Run via `idf.py flash monitor`

---

## 📬 Author

**Ritesh Sawant**  
🎓 B.Tech | Electronics & Computer Science | 2026  graduating 
💡 Embedded Systems Enthusiast | 
[![GitHub](https://img.shields.io/badge/GitHub-%2312100E.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/riteshsawant21)  
[![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/ritesh-sawant21)

---

