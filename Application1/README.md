# Application 1 – Real-Time LED and Telemetry Logger (Space Systems Theme)

**Name:** Destiny Ellenwood  
**UCF ID:** 5276398  
**Course:** Real-Time Systems – Summer 2025  
**Theme:** Space Systems 🛰️  
**Application:** Week 1 – Rev1  
**AI Use:** Used ChatGPT to help generate comments, function explanations, and bonus timing logic.

---

##  Overview

This application simulates a **real-time system on a satellite**, where:

- An **LED acts as a beacon**, blinking at a steady 2 Hz rate to indicate system status.
- A **telemetry task** logs a health packet to the console every 10 seconds.

Both tasks run independently using **FreeRTOS**, which ensures the LED blinks on time even when telemetry logging happens.

---

##  Implementation Details

###  `satellite_beacon_task`
- Runs at **2 Hz** → LED ON/OFF every 250 ms
- Uses `xTaskGetTickCount()` and `portTICK_PERIOD_MS` to measure the exact time between toggles
- Logs:
  - Whether the beacon is ON or OFF
  - Timestamp
  - Elapsed time since last toggle (i.e., period)

###  `telemetry_task`
- Runs every **10 seconds** (0.1 Hz)
- Prints a telemetry packet ID and system timestamp
- Runs with `vTaskDelay(pdMS_TO_TICKS(10000))`

###  `app_main`
- Sets up GPIO4 as the beacon LED output pin
- Creates both tasks with equal priority (1)

---

##  Real-Time Design Principles Used

- **Multitasking:** Each task has its own timing and does not block the other.
- **vTaskDelay:** Ensures tasks yield control to the scheduler, maintaining proper CPU usage.
- **Timing Verification:** Used `xTaskGetTickCount()` to confirm both tasks meet their real-time requirements.

---

##  How to Run

1. Here's my Wokwi link to Application 1:
[(https://wokwi.com/projects/431794950353297409)]

2. README.md file in Wokwi includes analysis/engineering section answers.
---

