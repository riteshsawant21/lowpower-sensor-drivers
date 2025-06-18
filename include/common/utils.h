// File: include/common/utils.h

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

// These functions will be implemented per board
void delay_ms(uint32_t ms);

// I2C low-level prototypes (bit-bang or register based)
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WriteByte(uint8_t data);
uint8_t I2C_ReadByte(uint8_t ack);

// SPI (bit-bang or register-based)
void SPI_Init(void);
uint8_t SPI_Transfer(uint8_t data);
void SPI_CS_Low(void);
void SPI_CS_High(void);

// UART functions (to be implemented per board)
void UART_Init(void);
void UART_WriteBytes(const uint8_t *data, uint8_t len);
int  UART_ReadBytes(uint8_t *buffer, uint8_t len, uint32_t timeout_ms);

#endif
