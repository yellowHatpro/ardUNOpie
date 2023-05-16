// StepperSpeedControl

/*
 *The motor will rotate in a clockwise direction. The higher the potentiometer
 * value, the faster the motor speed. Because setSpeed() sets the delay between
 * steps, you may notice the motor is less responsive to changes in the sensor value at low speeds.
 */

#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;

void setup()
{
}

void loop()
{
    // Read potentiometer value
    int sensorReading = analogRead(A0);
    // Map it to a range from 0 to 100
    int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
    // Set the motor speed
    if (motorSpeed > 0)
    {
        stepper.setSpeed(motorSpeed);
        // Step 1/100 of a revolution
        stepper.step(stepsPerRevolution / 100);
    }
}