# SPROUT – Smart Plant Monitoring & Protection System

SPROUT is an IoT-based system built to monitor plant health and provide basic protection using sensors, actuators, and cloud connectivity.  
The project focuses on reliability, safety, and real-world usability rather than automation for its own sake.

---

## Problem Overview

Manual plant care is time-consuming and error-prone.  
Overwatering, missed temperature changes, and unnoticed intrusions can damage plants over time.

SPROUT addresses this by continuously monitoring environmental conditions and reacting locally while also logging data remotely for observation.

---

## System Overview

The system is built around a NodeMCU ESP8266 microcontroller and operates in a continuous loop:

1. Read sensor data (soil moisture, temperature, humidity, motion)
2. Process values and derive meaningful metrics
3. Trigger alerts or actions when thresholds are crossed
4. Upload data to a cloud dashboard for monitoring

---

## Hardware Components

- NodeMCU ESP8266 (Wi-Fi enabled microcontroller)
- Soil Moisture Sensor
- DHT11 Temperature & Humidity Sensor
- IR Motion Sensor
- Servo Motor
- LED
- Buzzer
- Breadboard and jumper wires
- USB power source

> 📷 Component images will be added in the `media/` folder for easy replication.

---

## Pin Configuration

| Component | NodeMCU Pin |
|---------|-------------|
| Soil Moisture Sensor | A0 |
| DHT11 Sensor | D2 |
| IR Sensor | D5 |
| Servo Motor | D6 |
| Buzzer | D7 |
| LED | D8 |

---

## How the System Works

### Sensor Reading
- Soil moisture is read as an analog value.
- Temperature and relative humidity are read using the DHT11 sensor.
- Absolute humidity is calculated from temperature and relative humidity.
- The IR sensor checks for motion near the plant.

### Decision Logic
- If soil moisture drops below a defined threshold, the LED is turned ON.
- If motion is detected, the buzzer is activated and the servo motor performs a movement pattern.
- All actuators return to a safe state when conditions normalize.

### Cloud Communication
- Data is sent to ThingSpeak every 15 seconds (rate-limit compliant).
- Values uploaded:
  - Soil moisture
  - Temperature
  - Absolute humidity
  - Intruder detection state

---

## Software & Tools Used

- Arduino IDE
- Embedded C / Arduino
- ESP8266 WiFi & HTTP libraries
- ThingSpeak IoT Cloud Platform

---

## Security Note

WiFi credentials and API keys are intentionally excluded from this repository.

Before running the project:
- Replace placeholder values in the code with your own credentials
- Never commit real secrets to a public repository

---

## Folder Structure

```text
sprout-smart-plant-monitor/
├── firmware/
│ └── sprout.ino
├── media/
│ └── (images and demo videos)
└── README.md
```
---

## Future Improvements

- Automated irrigation system
- Machine learning for plant health prediction
- Mobile notifications (Telegram / WhatsApp)
- Solar power support
- Improved dashboard UI/UX

---

## Project Status

This project is a working prototype built for learning, experimentation, and real-world understanding of IoT systems.

