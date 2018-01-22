#include <Temperature.h>

Temperature sensor_a;
Temperature sensor_b;

void setup() {
  Serial.begin(9600);
  sensor_a.attach(0);
  sensor_a.type(LM35);
  sensor_b.attach(1);
  sensor_b.type(TMP36);
}

void loop() {
  Serial.println(String(sensor_a.read()) + " celsius");
  Serial.println(String(sensor_b.read()) + " celsius");
  Serial.println();
  delay(2000);
}
