// File: src/spi/mcp3008_driver.c

#include "mcp3008_driver.h"
#include "utils.h"

// MCP3008 requires sending a 3-byte SPI command:
// Start bit, SGL/DIF, D2, D1, D0, followed by 2 dummy bytes to receive 10-bit result

uint16_t MCP3008_ReadChannel(uint8_t channel) {
    if (channel > 7) return 0;

    // Command to read specific channel
    uint8_t command = 0b00000001; // Start bit
    uint8_t config  = (0b10000000 | (channel << 4)); // Single-ended + channel

    SPI_CS_Low(); // Pull CS low

    SPI_Transfer(command);          // Send start bit
    uint8_t high = SPI_Transfer(config); // Receive high bits
    uint8_t low  = SPI_Transfer(0x00);   // Receive low bits

    SPI_CS_High(); // Pull CS high

    // Combine 10-bit ADC value
    uint16_t result = ((high & 0x03) << 8) | low;
    return result;
}
