// File: include/spi/mcp3008_driver.h

#ifndef MCP3008_DRIVER_H
#define MCP3008_DRIVER_H

#include <stdint.h>

// Reads 10-bit analog value from given channel (0 to 7)
uint16_t MCP3008_ReadChannel(uint8_t channel);

#endif
