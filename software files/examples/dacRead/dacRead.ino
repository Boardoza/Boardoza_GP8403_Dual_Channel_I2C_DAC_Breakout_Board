#include <Wire.h>
#include "GP8403.h"

// Define I2C Pins for your specific board
#define SDA_PIN 1
#define SCL_PIN 2

// Instantiate the DAC object
GP8403 dac;

// Function prototype
void printMenu();

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Start I2C at 400kHz for smooth updates
  Wire.begin(SDA_PIN, SCL_PIN, 400000);

  Serial.println("\n====================================");
  Serial.println("    GP8403 DAC LIBRARY TEST         ");
  Serial.println("====================================");

  // Initialize with 5V mode by default
  dac.init5VMode();
  delay(300);

  printMenu();
}

void printMenu() {
  Serial.println("\n--- MAIN MENU ---");
  Serial.println("1: Ramp Up");
  Serial.println("2: Ramp Down");
  Serial.println("3: Square Wave (Send any char to stop)");
  Serial.println("4: Sine Wave Smooth (Send any char to stop)");
  Serial.println("5: Set 0-5V Mode");
  Serial.println("6: Set 0-10V Mode");
  Serial.println("-----------------");
  Serial.print("Select an option: ");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    // Clear the serial buffer from newline characters
    while(Serial.available()) {
      Serial.read();
    }

    Serial.println(cmd); // Echo the command

    switch (cmd) {
      case '1':
        Serial.println("Executing Ramp Up...");
        dac.rampUp();
        Serial.println("Ramp Up Finished.");
        printMenu();
        break;

      case '2':
        Serial.println("Executing Ramp Down...");
        dac.rampDown();
        Serial.println("Ramp Down Finished.");
        printMenu();
        break;

      case '3':
        Serial.println("Generating Square Wave. Send any character to stop...");
        // Keep generating until a character is sent
        while (!Serial.available()) {
          dac.squareWaveCycle();
        }
        // Clear the stop character from buffer
        while(Serial.available()) Serial.read();
        
        dac.setVOUT0(0);
        dac.setVOUT1(0);
        Serial.println("Square Wave Stopped.");
        printMenu();
        break;

      case '4':
        Serial.println("Generating Smooth Sine Wave. Send any character to stop...");
        // Keep generating until a character is sent
        while (!Serial.available()) {
          dac.sineWaveCycle();
        }
        // Clear the stop character from buffer
        while(Serial.available()) Serial.read();
        
        dac.setVOUT0(0);
        dac.setVOUT1(0);
        Serial.println("Sine Wave Stopped.");
        printMenu();
        break;

      case '5':
        dac.init5VMode();
        Serial.println("Mode changed to: 0-5V");
        printMenu();
        break;

      case '6':
        dac.init10VMode();
        Serial.println("Mode changed to: 0-10V");
        printMenu();
        break;

      default:
        // Ignore invalid inputs like newlines
        if(cmd != '\n' && cmd != '\r') {
          Serial.println("Invalid option. Please try again.");
          printMenu();
        }
        break;
    }
  }
}