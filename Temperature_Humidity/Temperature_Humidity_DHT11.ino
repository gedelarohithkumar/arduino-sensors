#include "DHT.h"

// Define pin and sensor type
#define DHTPIN 2        // Data pin connected to D2
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Sensor Test");

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display data
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
