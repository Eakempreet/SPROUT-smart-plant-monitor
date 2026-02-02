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



