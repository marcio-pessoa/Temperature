/* Temperature.cpp - Temperature Sensor Library
 * 
 */

#include "Arduino.h"
#include "Temperature.h"

/* Temperature
 * 
 * Description
 *   Get temperature from sensor.
 * 
 *   RealTime ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
Temperature::Temperature() {
  _type = LM35;
  _voltage = 5;
  analogReference(DEFAULT);
}

/* attach
 * 
 * Description
 *   Set temperature from sensor electronic pin.
 * 
 *   sensor.attach()
 * 
 * Parameters
 *   pin: Arduino sensor pin
 * 
 * Returns
 *   void
 */
void Temperature::attach(byte pin) {
  pinMode(pin, INPUT);
  _pin = pin;
}

/* type
 * 
 * Description
 *   Set temperature sensor type and working voltage.
 * 
 *   sensor.type()
 * 
 * Parameters
 *   type:
 *     Valid values:
 *       LM35
 *       TMP36
 *   voltage: Sensor voltage (default = 5)
 * 
 * Returns
 *   void
*/
void Temperature::type(byte type, byte voltage) {
  _type = type;
  _voltage = voltage;
}

/* read
 * 
 * Description
 *   Get temperature from sensor.
 * 
 *   sensor.read()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   float: temperature
 */
float Temperature::read() {
  float temperature = analogRead(_pin);
  // Get value from sensor
  switch (_type) {
    default:
    case LM35: {
      temperature = (float)temperature * _voltage / 1024 * 100;
      break;
    }
    case TMP36: {
      temperature = ((float)temperature * _voltage / 1024 - 0.5) * 100;
      break;
    }
  }
  return temperature;
}
