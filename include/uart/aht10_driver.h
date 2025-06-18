// File: include/uart/aht10_driver.h

#ifndef AHT10_DRIVER_H
#define AHT10_DRIVER_H

typedef struct {
    float temperature;
    float humidity;
} AHT10_Data;

void AHT10_UART_Init(void);
AHT10_Data AHT10_UART_Read(void);

#endif
