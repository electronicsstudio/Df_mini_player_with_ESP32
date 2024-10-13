/*
Electronics Studio
@file DF_Mini_only.ino
@date  13-10-2024
@url https:https://github.com/electronicsstudio
*/
#include "DFRobotDFPlayerMini.h"
#include <HardwareSerial.h>

// Use the hardware serial ports on the ESP32

DFRobotDFPlayerMini player;
HardwareSerial mySerial(2); // Initialize hardware serial port 2

void setup() 
{
  Serial.begin(115200);//
  mySerial.begin(9600, SERIAL_8N1, 16, 17); // RX = 16, TX = 17

  Serial.println("Initializing DFPlayer...");

  if (!player.begin(mySerial)) {
      Serial.println("Unable to begin:");
      Serial.println("1. Please recheck the connection!");
      Serial.println("2. Please insert the SD card!");
      while (true);
  }
  Serial.println("DFPlayer Mini online.");

  player.volume(10);  // Set volume value (0~30)
  player.play(1);     // Play the first MP3 file
}

void loop() {
    // Nothing to do here
}
