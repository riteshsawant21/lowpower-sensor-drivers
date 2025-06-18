// File: include/i2c/dht12_driver.h

#ifndef DHT12_DRIVER_H
#define DHT12_DRIVER_H

typedef struct {
    float temperature;
    float humidity;
} DHT12_Data;

void DHT12_Init(void);
DHT12_Data DHT12_ReadData(void);

#endif
