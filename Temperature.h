/* Temperature.h - Temperature Sensor Library
 * 
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 * 
 * Sensor technical specification
 *   LM35 (default)
 *     Temperature range: Specified -55 °C to +150 °C
 *     Output range: *****need to research*****
 *     Power supply: 4V to 20V, 0.06 mA
 *     Pinout package TO-92:
 *     
 *       Front          Bottom
 *       ┌───┐          ┌───┐
 *       │123│          │ooo│
 *       └┬┬┬┘          \───/
 *        │││           1 2 3
 *        │││
 *       1 2 3
 *       
 *       1 - Vcc
 *       2 - Output
 *       3 - GND
 * 
 *   TMP36
 *     Temperature range: Specified -40 °C to +125 °C (±0.5 °C)
 *                        Operation to +150 °C (±2 °C)
 *     Output range: 0.1V (-40°C) to 2.0V (150°C)
 *     Power supply: 2.7V to 5.5V only, 0.05 mA
 *     Pinout package TO-92:
 *     
 *       Front          Bottom
 *       ┌───┐          ┌───┐
 *       │123│          │ooo│
 *       └┬┬┬┘          \───/
 *        │││           1 2 3
 *        │││
 *       1 2 3
 *       
 *       1 - Vcc
 *       2 - Output
 *       3 - GND
 * 
 * Change log
 * 2016-09-08
 *         * Temperature
 *         Added analogReference with DEFAULT value to define reference
 *         voltage used on sensor.
 * 
 * 2015-05-24
 *         * temperatureRead
 *         method renamed to "read".
 * 
 * 2015-01-15
 *         * Temperature
 *         added support to TMP36.
 *         * convert_temp
 *         added function to convert temperature units.
 * 
 * 2015-01-14
 *         * LM35
 *         library renamed from LM35 to Temperature.
 * 
 * 2014-11-05
 *         * temperature
 *         changed method temperature to temperatureRead.
 * 
 * 2014-07-06
 *         Experimental version.
 *         Support LM35.
 */

#ifndef Temperature_h
#define Temperature_h

#include "Arduino.h"

#define LM35 0
#define TMP36 1

class Temperature
{
  public:
    Temperature();
    void attach(byte pin);
    void type(byte type, byte voltage = 5);
    float read();
  private:
    byte _pin;
    byte _type;
    byte _voltage;
};

float convert_temp(float celcius, char from_unit, char to_unit);

#endif
