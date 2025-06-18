// File: src/i2c/dht12_driver.c

#include "dht12_driver.h"
#include "utils.h"

// DHT12 I2C address (7-bit): 0x5C
#define DHT12_ADDR 0x5C

#define DHT12_TEMP_MSB_REG 0x02

// Initialize I2C for DHT12 (bit-bang or register-based)
void DHT12_Init(void) {
    I2C_Init();  // Custom low-level I2C init
}

// Read temperature and humidity
DHT12_Data DHT12_ReadData(void) {
    DHT12_Data data = {0};

    uint8_t raw[5] = {0};  // 5 bytes: RH_Int, RH_Dec, T_Int, T_Dec, Checksum

    I2C_Start();
    I2C_WriteByte((DHT12_ADDR << 1) | 0); // Write
    I2C_WriteByte(DHT12_TEMP_MSB_REG);   // Start from 0x02
    I2C_Stop();

    delay_ms(50);  // Datasheet: wait before reading

    I2C_Start();
    I2C_WriteByte((DHT12_ADDR << 1) | 1); // Read
    for (int i = 0; i < 5; i++) {
        raw[i] = I2C_ReadByte(i < 4); // ACK until last byte
    }
    I2C_Stop();

    data.humidity = raw[0] + raw[1] / 10.0;
    data.temperature = raw[2] + raw[3] / 10.0;

    return data;
}
