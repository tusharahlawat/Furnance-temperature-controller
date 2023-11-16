#include <DHT.h> // Include DHT sensor library

#define relayPin 5 // Relay module connected to Arduino digital pin 5
#define sensorPin 2 // Temperature sensor connected to Arduino digital pin 2
#define sensorType DHT11 // DHT11 sensor type

#define desiredTemperature 35 

// Desired temperature in degrees Celsius

DHT dht(sensorPin, sensorType); // Create DHT sensor object

void setup() {
  pinMode(relayPin, OUTPUT); // Set relay pin as output
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  dht.begin(); // Initialize DHT sensor
}

void loop() {
  // Read temperature from sensor
  float temperature = dht.readTemperature();

  // Check if sensor has returned valid temperature
  if (isnan(temperature)) {
    Serial.println("Failed to read temperature");
    return;
  }

  // Print temperature to serial monitor
  Serial.print("Current temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Check if temperature is above or below desired temperature
  if (temperature > desiredTemperature) {
    // Turn on fan
    digitalWrite(relayPin, HIGH);
  } else {
    // Turn off fan
    digitalWrite(relayPin, LOW);
  }

  // Wait for 2 seconds before reading temperature again
  delay(2000);
}