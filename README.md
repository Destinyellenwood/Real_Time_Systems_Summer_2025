# Real-Time Systems – Summer 2025

**Student:** Destiny Ellenwood  
**UCF ID:** 5276398  
**Course:** EEE4775 – Real-Time Systems  
**Semester:** Summer 2025  
**Platform:** ESP32 + FreeRTOS (simulated in Wokwi and built in PlatformIO)  

---

## Repository Overview

This repository contains my projects and applications developed for the Real-Time Systems course, using the **ESP32 microcontroller** and **FreeRTOS** for cooperative multitasking.

Each folder represents a standalone application with source code, simulation files, and documentation.

---

## 🔗 Applications

| Week | Title & Theme | Folder | Description |
|------|----------------|--------|-------------|
|  1  | [Application 1 – Satellite Beacon & Telemetry](./Application1/) | `Application1/` | Simulates a satellite with a 2 Hz beacon LED and 10-second telemetry logging task. Bonus features include timing logs and task structuring. |
|  2  | Up next   |

---

## Technologies Used

- **ESP32** (ESP-IDF)
- **FreeRTOS** (Task creation, scheduling, `vTaskDelay`)
- **Wokwi** Simulator (visualize timing, LED, and serial output)
- **PlatformIO** (local development in VSCode)

---

## Running Projects in Wokwi

Each application includes:
- A `main.c` file with FreeRTOS tasks
- A `diagram.json` defining the hardware layout
- An optional `wokwi.toml` for simulation config


---


