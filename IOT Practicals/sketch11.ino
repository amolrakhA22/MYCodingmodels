#include <DHT.h> // Include DHT library

#define DHTPIN 4 // Define DHT data pin
#define DHTTYPE DHT11 // Define DHT type

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

float tempF; // Variable to store temperature in Fahrenheit
float maxTemp = -100; // Variable to store maximum temperature
float minTemp = 100; // Variable to store minimum temperature

void setup() {
  Serial.begin(9600); // Initialize serial communication
  dht.begin(); // Initialize DHT sensor
}

void loop() {
  delay(2000); // Wait for 2 seconds
  
  // Read temperature in Celsius
  float tempC = dht.readTemperature();
  
  // Convert temperature to Fahrenheit
  tempF = (tempC * 1.8) + 32;
  
  // Check if current temperature is higher than maximum temperature
  if (tempF > maxTemp) {
    maxTemp = tempF; // Update maximum temperature
  }
  
  // Check if current temperature is lower than minimum temperature
  if (tempF < minTemp) {
    minTemp = tempF; // Update minimum temperature
  }
  
  // Print temperature in Fahrenheit, maximum temperature, and minimum temperature
  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.print("F, Max Temp: ");
  Serial.print(maxTemp);
  Serial.print("F, Min Temp: ");
  Serial.print(minTemp);
  Serial.println("F");
}

