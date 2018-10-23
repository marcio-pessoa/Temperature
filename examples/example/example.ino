#include <Temperature.h>

Temperature sensor_a;  // Create sensor object
Temperature sensor_b;  // Create sensor object

void setup() {
  Serial.begin(9600);
  sensor_a.attach(0);  // Analog input 0
  sensor_a.type(LM35);  // Set sensor type as LM35
  sensor_b.attach(1);  // Analog input 1
  sensor_b.type(TMP36);  // Set sensor type as TMP36
}

void loop() {
  // Display results
  Serial.println(String(sensor_a.read()) + " celsius");
  Serial.println(String(sensor_b.read()) + " celsius");
  Serial.println();
  delay(2000);  // Wait for 2 seconds
}
