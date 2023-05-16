/* How to read analog input from physical world using potentiometer
 * 3 pins of potentiometer
 * 1st pin : GND
 * 2nd pin : 5 volts
 * 3rd pin : analog input pin (A0)
 */

#define ANALOG_PIN A0

void setup()
{
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop()
{
    int sensorValue = analogRead(ANALOG_PIN);
    Serial.println(sensorValue);
    // Print voltage
    float voltage = sensorValue * (5.0 / 1023.0);
    Serial.println(voltage);
    delay(1); // delay in between reads for stability
}