// File: src/uart/aht10_driver.c

#include "aht10_driver.h"
#include "utils.h"

// Simulated AHT10 UART protocol (for demo purposes)
// Normally it's I2C, but this acts as a template for UART-based sensors

#define UART_TIMEOUT_MS 100

void AHT10_UART_Init(void) {
    UART_Init();  // Provided by utils.h per board
}

AHT10_Data AHT10_UART_Read(void) {
    AHT10_Data data = {0};
    uint8_t tx_cmd[3] = {0xAC, 0x33, 0x00};  // Trigger measurement command
    uint8_t rx_data[6] = {0};

    UART_WriteBytes(tx_cmd, 3);
    delay_ms(80);  // Sensor conversion time

    if (UART_ReadBytes(rx_data, 6, UART_TIMEOUT_MS) == 6) {
        // Parse received 6 bytes (20 bits temp + 20 bits humidity)
        uint32_t hum_raw = ((rx_data[1] << 12) | (rx_data[2] << 4) | (rx_data[3] >> 4));
        uint32_t temp_raw = (((rx_data[3] & 0x0F) << 16) | (rx_data[4] << 8) | rx_data[5]);

        data.humidity = (hum_raw * 100.0) / 1048576.0;
        data.temperature = (temp_raw * 200.0) / 1048576.0 - 50.0;
    }

    return data;
}
