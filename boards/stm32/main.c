// File: boards/stm32/main.c

#include "dht12_driver.h"
#include "mcp3008_driver.h"
#include "aht10_driver.h"
#include "utils.h"
#include <stdio.h>

int main(void) {
    // Init low-level drivers
    I2C_Init();
    SPI_Init();
    UART_Init();

    // Init sensors
    DHT12_Init();
    AHT10_UART_Init();

    while (1) {
        // Read DHT12 via I2C
        DHT12_Data dht = DHT12_ReadData();
        printf("DHT12 Temp: %.1f C | Humidity: %.1f%%\n", dht.temperature, dht.humidity);

        // Read from MCP3008 Channel 0 via SPI
        uint16_t analog = MCP3008_ReadChannel(0);
        printf("MCP3008 CH0: %u (10-bit)\n", analog);

        // Read AHT10 via UART
        AHT10_Data aht = AHT10_UART_Read();
        printf("AHT10 Temp: %.1f C | Humidity: %.1f%%\n", aht.temperature, aht.humidity);

        delay_ms(2000);
    }
}
