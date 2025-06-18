// File: boards/esp32/deep_sleep_driver_test.c

#include "dht12_driver.h"
#include "utils.h"
#include <stdio.h>
#include "esp_sleep.h"

void app_main(void) {
    I2C_Init();
    DHT12_Init();

    // Wake source: GPIO or timer
    esp_sleep_enable_timer_wakeup(10 * 1000000);  // 10 seconds

    // Read sensor
    DHT12_Data dht = DHT12_ReadData();
    printf("Wake from Deep Sleep:\n");
    printf("DHT12 Temp: %.1f C | Humidity: %.1f%%\n", dht.temperature, dht.humidity);

    // Go to sleep again
    printf("Entering deep sleep for 10s...\n");
    esp_deep_sleep_start();
}
