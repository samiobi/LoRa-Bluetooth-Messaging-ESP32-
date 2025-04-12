#include <SPI.h>
#include <LoRa.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Custom LoRa pin configuration
#define LORA_NSS   15
#define LORA_SCK   14
#define LORA_MISO  12
#define LORA_MOSI  13
#define LORA_RST   4
#define LORA_DIO0  2

String incomingBT = "";
String incomingLoRa = "";

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_LoRa"); // This name shows up in Serial Bluetooth Terminal for the second esp32 name ESP32_LoRa2

  // Custom SPI setup for LoRa
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_NSS);

  LoRa.setPins(LORA_NSS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (1);
  }
  Serial.println("LoRa initialized at 433 MHz");
}

void loop() {
  // send Bluetooth -> LoRa
  if (SerialBT.available()) {
    incomingBT = SerialBT.readStringUntil('\n');
    Serial.println("BT to LoRa: " + incomingBT);
    LoRa.beginPacket();
    LoRa.print(incomingBT);
    LoRa.endPacket();
  }

  // receive LoRa -> Bluetooth
  int packetSize = LoRa.parsePacket();// Parse packet loads all the bytes in the buffer and then you read them
  if (packetSize) {
    incomingLoRa = "";
    while (LoRa.available()) {
      incomingLoRa += (char)LoRa.read();
    }
    Serial.println("LoRa to BT: " + incomingLoRa);
    SerialBT.println("From LoRa: " + incomingLoRa);
  }
}
