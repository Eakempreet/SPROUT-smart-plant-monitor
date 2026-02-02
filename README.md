# 🌱 SPROUT — Smart Plant Monitoring & Protection System

SPROUT is a small IoT-based system designed to monitor plant conditions and provide basic protection against external disturbances using sensors, local decision logic, and a microcontroller.

The project focuses on building a simple, reliable system that reacts to real-world conditions rather than theoretical scenarios.


## Motivation

The motivation for building SPROUT came from observing a recurring real-world problem.

Plants in open or semi-open environments are often damaged by small animals such as monkeys or squirrels. These animals disturb the soil, damage roots, or break stems—usually when no one is around to notice it in time.

SPROUT was built to act as a simple monitoring and protection layer. Instead of relying on constant human supervision, the system observes key conditions around a plant and responds locally when unusual activity is detected.

The aim was not to eliminate the problem completely, but to reduce unnoticed damage through timely awareness and basic deterrence.


## What the System Does

SPROUT operates as a small, self-contained monitoring system placed near a plant.

At a high level, the system:
- monitors soil moisture to indicate plant water condition
- observes temperature to understand the surrounding environment
- detects motion near the plant area
- reacts locally when predefined conditions are met

When soil moisture drops below a set threshold, the system provides a visual indication.  
When motion is detected near the plant, the system triggers a basic protective response.

In addition to local responses, the system is designed to send sensor data to a cloud platform (ThingSpeak) for remote monitoring.  
This data can be viewed through dashboards or a simple Android application, allowing plant conditions to be observed without being physically present.

Local decision-making ensures the system remains responsive, while cloud integration enables observation and future expansion.


All decisions are made locally on the device, keeping the system simple, responsive, and independent of constant network availability.


## System Workflow

SPROUT follows a simple and repeatable workflow designed for reliability.

1. The system continuously reads data from the connected sensors, including soil moisture, temperature, and motion.
2. Sensor values are processed locally and compared against predefined thresholds.
3. If soil moisture falls below the threshold, the system provides a visual alert to indicate that attention is required.
4. If motion is detected near the plant, the system triggers a basic protective response using actuators.
5. Sensor readings are periodically sent to the cloud platform for remote observation and record keeping.

This workflow allows the system to react immediately to local conditions while also supporting remote monitoring and future analysis.


## Hardware Components

SPROUT is built using commonly available, low-cost components to keep the system accessible and easy to replicate.

### Controller
- Arduino Uno (used for simulation and wiring validation)
- NodeMCU ESP8266 (intended deployment hardware)

### Sensors
- Soil Moisture Sensor (analog)
- Temperature Sensor (TMP36 used in simulation)
- IR Motion Sensor

### Actuators & Indicators
- Servo Motor (used for physical response)
- Buzzer (audio alert)
- LED with resistor (visual indication)

### Supporting Components
- Breadboard
- Jumper wires
- USB power source


## Hardware Components (Visual Reference)

Below are the actual components used in the SPROUT system.  
They are grouped by role to keep the section readable and visually balanced.

---

### Controller

| Component | Preview |
|---------|--------|
| NodeMCU ESP8266 | ![NodeMCU](media/components/nodemcu.jpg) |

---

### Sensors

| Component | Preview |
|---------|--------|
| Soil Moisture Sensor | ![Soil Moisture](media/components/soil-moisture-sensor.jpg) |
| IR Motion Sensor | ![IR Sensor](media/components/ir-sensor.jpg) |
| DHT11 Sensor | ![DHT11](media/components/dht11.jpg) |

---

### Actuators & Indicators

| Component | Preview |
|---------|--------|
| Servo Motor | ![Servo Motor](media/components/servo-motor.jpg) |
| Buzzer | ![Buzzer](media/components/buzzer.jpg) |
| LED | ![LED](media/components/led.jpg) |
| Resistor (220Ω) | ![Resistor](media/components/Resistor%20(for%20LED,%20typically%20220Ω).jpg) |

---

### Supporting Components

| Component | Preview |
|---------|--------|
| Breadboard | ![Breadboard](media/components/breadboard.jpg) |
| Jumper Wires | ![Jumper Wires](media/components/jumper-wires.jpg) |
| USB Cable | ![USB Cable](media/components/usb-cable.jpg) |


## Wiring Diagram & Simulation Notes

The wiring diagram below represents the validated hardware connections used during simulation.

![Wiring Diagram](media/wiring-diagram.png)

### Important Notes

- The wiring diagram was created and tested using **Arduino Uno in Tinkercad** for ease of simulation and validation.
- The **actual hardware implementation uses NodeMCU ESP8266**.
- Pin numbers differ between Arduino Uno and NodeMCU, but the **logical connections remain the same**.
- This approach allows reliable testing in simulation while keeping the final deployment flexible.

The diagram focuses on clarity and correctness rather than physical enclosure or layout aesthetics.










