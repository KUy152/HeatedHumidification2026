// Please install DHT Sensor Library to run code
#include <DHT.h>

// Define the pin for the DHT22
#define DHTPIN 2  // Change this to the pin you're using
#define DHTTYPE DHT22

// Create a DHT object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  Serial.println("DHT22 Data Logging to PC.");

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait 5 seconds between measurements
  delay(5000);

  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if readings failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  /*
  // Remove comments to include more details in serial monitor output
  // Send data to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  */

  // Outputs humidity then temperature.
  // Separated data by comma to input into CSV or MATLAB.
  Serial.print(humidity);
  Serial.print(",");
  Serial.println(temperature);
}
