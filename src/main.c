/* --------------------------------------------------------------
   Destiny Ellenwood
   UCFID: 5276398
   Application: 01 - Rev1
   Class: Real Time Systems - Su 2025
   AI Use: Commented inline, assisted with defining function uses to help me fill in parameters
---------------------------------------------------------------*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_4 // LED as satellite status beacon


// Task to simulate beacon LED blinking at 2 Hz
void satellite_beacon_task(void *pvParameters) {
    bool beacon_on = false;
    TickType_t previous_tick = xTaskGetTickCount();  // Store the time of the last toggle

    while (1) {
        TickType_t current_tick = xTaskGetTickCount();  // Time at this execution
        uint32_t elapsed_ms = (current_tick - previous_tick) * portTICK_PERIOD_MS;  // Calculate elapsed time
        previous_tick = current_tick;  // Update the last toggle time

        if (beacon_on) {
            gpio_set_level(LED_PIN, 1);  // Turn LED ON
            printf("Beacon ON | Time = %lu ms | Period = %lu ms\n",
       (unsigned long)(current_tick * portTICK_PERIOD_MS),
       (unsigned long)elapsed_ms);

        } else {
            gpio_set_level(LED_PIN, 0);  // Turn LED OFF
            printf("Beacon OFF | Time = %lu ms | Period = %lu ms\n",
       (unsigned long)(current_tick * portTICK_PERIOD_MS),
       (unsigned long)elapsed_ms);
        }

        beacon_on = !beacon_on;  // Toggle LED state
        vTaskDelay(pdMS_TO_TICKS(250));  // Wait 250 ms
    }

    // Task runs forever, so this is not reached
    vTaskDelete(NULL);
}

// Task to 
void telemetry_task(void *pvParameters) {
  int packet_id = 1;
  while (1) {
    printf("Telemetry Packet %d: Status OK | Time = %lu ms\n", packet_id, xTaskGetTickCount() * portTICK_PERIOD_MS);
    packet_id++;
    vTaskDelay(pdMS_TO_TICKS(10000)); // Wait 10 seconds
  }

  vTaskDelete(NULL);
}

void app_main() {
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    
    xTaskCreate(satellite_beacon_task, "Beacon Task", 2048, NULL, 1, NULL);
    xTaskCreate(telemetry_task, "Telemetry Task", 2048, NULL, 1, NULL);
}
