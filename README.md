# LoRa-Bluetooth-Messaging-ESP32-
# 📡 LoRa-Bluetooth Messaging with ESP32

This project enables **offline communication between two smartphones** using **ESP32 + LoRa (SX1278)** modules. The phones connect to ESP32 devices via **Bluetooth**, and the ESP32 boards exchange messages over **LoRa** (433MHz), making it ideal for **remote locations without mobile networks or internet**.

## 🔧 Project Components

- 2 × ESP32 boards
- 2 × LoRa SX1278 modules (433MHz)
- 2 × Smartphones with Bluetooth
- Serial Bluetooth Terminal app (or similar)
- Jumper wires and breadboards

## 🎯 Features

- 📲 Send and receive text messages via Bluetooth
- 🌐 Transmit messages over LoRa between two ESP32 boards
- 💬 Offline chat in remote areas
- 🔄 Bi-directional communication

## 🛠️ Circuit Diagram

(Insert diagram or a link to an image here)

## 🧠 How It Works

1. Each phone connects to its nearby ESP32 via Bluetooth.
2. The ESP32 reads incoming Bluetooth messages.
3. It sends the message via LoRa to the second ESP32.
4. The second ESP32 forwards the message to its connected phone.

## 📥 Installation

### Arduino Libraries Required

- `LoRa by Sandeep Mistry`
- `BluetoothSerial`
- `SPI`

### Wiring (ESP32 & LoRa SX1278)

| ESP32 Pin | SX1278 Pin |
|-----------|------------|
| 5V        | VCC        |
| GND       | GND        |
| D5 (GPIO18) | SCK      |
| D19       | MISO       |
| D23       | MOSI       |
| D18       | NSS (CS)   |
| D14       | RST        |
| D26       | DIO0       |

## 🚀 Getting Started

1. Open `ESP32_LoRa_Bluetooth.ino` in Arduino IDE.
2. Upload to both ESP32 boards.
3. Connect each phone to an ESP32 using **Serial Bluetooth Terminal**.
4. Start chatting—LoRa will handle the transmission between devices!

## 📸 Demo

https://youtu.be/C8xI13l99t0?si=Ns9h4TTBWbmZlT2O

## 📂 Folder Structure

