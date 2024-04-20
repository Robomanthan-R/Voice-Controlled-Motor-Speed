#include <SoftwareSerial.h> // Include the SoftwareSerial library for Bluetooth communication

// Define pins for Bluetooth communication
const int bluetoothTx = 10; // TX pin of Bluetooth module connected to Arduino digital pin 10
const int bluetoothRx = 11; // RX pin of Bluetooth module connected to Arduino digital pin 11

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx); // Create a SoftwareSerial object for Bluetooth communication

// Define motor control pins
const int motorEnablePin = 9; // Pin to enable the motor driver
const int motorInput1Pin = 6; // Input 1 pin of the motor driver
const int motorInput2Pin = 5; // Input 2 pin of the motor driver

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  bluetooth.begin(9600); // Start Bluetooth communication

  pinMode(motorEnablePin, OUTPUT); // Set motor enable pin as output
  pinMode(motorInput1Pin, OUTPUT); // Set motor input 1 pin as output
  pinMode(motorInput2Pin, OUTPUT); // Set motor input 2 pin as output
}

void loop() {
  if (bluetooth.available()) { // Check if data is available to read from Bluetooth
    char command = bluetooth.read(); // Read the incoming command
    
    // Interpret the command and control motor speed accordingly
    switch (command) {
      case 'F': // Forward direction
        digitalWrite(motorInput1Pin, HIGH);
        digitalWrite(motorInput2Pin, LOW);
        break;
      case 'B': // Backward direction
        digitalWrite(motorInput1Pin, LOW);
        digitalWrite(motorInput2Pin, HIGH);
        break;
      case 'S': // Stop
        digitalWrite(motorInput1Pin, LOW);
        digitalWrite(motorInput2Pin, LOW);
        break;
      // Add more cases for controlling motor speed or other actions
    }
  }
}
