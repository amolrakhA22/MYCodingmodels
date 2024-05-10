#include <dht.h>

#define DHTPIN 2 // Pin where the DHT11 sensor is connected
dht DHT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Read temperature and humidity from the DHT11 sensor
  int chk = DHT.read11(DHTPIN);
  
  // Check if reading was successful
  if (chk == DHTLIB_OK) {
    // Print temperature and humidity values to the serial monitor
    Serial.print("Temperature: ");
    Serial.print(DHT.temperature);
    Serial.print("°C\t");
    Serial.print("Humidity: ");
    Serial.print(DHT.humidity);
    Serial.println("%");
  } else {
    // Print error message if reading failed
    Serial.println("Error reading from DHT sensor!");
  }
}
