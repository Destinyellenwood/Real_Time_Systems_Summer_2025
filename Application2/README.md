# Application 2 – Preemptive Scheduling with Eclipse Detection (Space Systems Theme)

**Name:** Destiny Ellenwood  
**UCF ID:** 5276398  
**Course:** Real-Time Systems – Summer 2025  
**Theme:** Space Systems  
**Application:** 2 **  


---

## Overview

This application enhances the satellite simulation by adding a **critical sensor-monitoring task** that detects eclipse conditions. All three tasks run on **Core 1** of the ESP32 using **FreeRTOS**, allowing for clear observation of **priority-based preemption**.

- The **LED beacon** continues blinking to show system status.
- The **telemetry task** logs status every second.
- The new **solar sensor task** samples light levels every 500 ms and raises an alert if light drops too low (simulating orbital eclipse).

---

## Implementation Details

### `satellite_beacon_task`
- Blinks LED every **500 ms** (1 Hz)
- Uses `vTaskDelay()` for periodic delay
- Logs LED state and time to the console  
- **Priority:** `1 (Low)`

### `telemetry_task`
- Logs a telemetry message every **1000 ms** (1 second)
- Tracks packet ID and system uptime
- Uses `vTaskDelay()` to yield the CPU  
- **Priority:** `2 (Medium)`

### `solar_sensor_task`
- Runs every **500 ms** using `vTaskDelayUntil()` for precise periodicity
- Reads analog light sensor (photoresistor)
- Converts ADC to voltage → resistance → lux
- Computes a moving average over 10 samples
- If lux drops below **200**, triggers `"**Eclipse Warning!**"` alert  
- **Priority:** `3 (High)`

---

## Real-Time Design Principles Used

- **Preemptive Scheduling:** Sensor task interrupts lower-priority tasks on wake.
- **vTaskDelay vs. vTaskDelayUntil:** Demonstrates drift vs. stable timing.
- **Sensor Filtering:** Moving average smooths data to avoid false alarms.
- **Core Pinning:** All tasks assigned to **Core 1** for consistent behavior.

---

## How to Run

1. Here's my Wokwi link to Application 2:
[(https://wokwi.com/projects/432787867109849089)]

2. README.md file in Wokwi includes analysis/engineering section answers.

---

