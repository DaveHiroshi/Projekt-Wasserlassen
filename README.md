# 🌱 Projekt-Wasserlassen

A smart ESP32-based automatic plant watering system designed for keeping your plants happy while you're on vacation.

---

## 🧠 Overview

**Projekt-Wasserlassen** is a microcontroller-driven system that uses an ESP32, a humidity sensor, and plant-specific settings to control a water pump. It intelligently waters plants based on soil moisture and individual plant needs.

---

## 🚀 Features

- 🕹️ **ESP32-powered** control
- 🌿 **Soil humidity monitoring** using capacitive sensor
- 💧 **Automatic water delivery** via 5V micro water pump
- 📊 **Plant-specific configuration** for optimal care
- 📱 (Optional) **Web-based status interface** via Wi-Fi

---

## 🔧 Hardware

- ✅ ESP32 Dev Board (e.g. DOIT ESP32 DEVKIT V1)
- ✅ Capacitive Soil Moisture Sensor
- ✅ Relay Module (or MOSFET)
- ✅ 5V Water Pump
- ✅ Power Supply (e.g. 5V USB or battery pack)
- ✅ Tubing, reservoir, optional 3D-printed plant spike

---

## 🛠️ Setup

1. Flash the firmware to your ESP32
2. Connect:
   - Moisture sensor to an analog GPIO pin
   - Pump via relay to digital GPIO pin
3. Configure plant thresholds in the firmware (or via config file)
4. Power up the system
5. Sit back and enjoy your vacation 🌴

---

## 🧪 Logic

```text
IF soil moisture < plant-specific threshold:
    → activate pump
    → run for predefined duration (or until threshold met)
ELSE
    → do nothing

