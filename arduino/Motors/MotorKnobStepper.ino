// MotorKnob
// A stepper motor follows the turns of a potentiometer (or other sensor) on analog input 0.

#include <Stepper.h>

#define STEPS 100

// Stepper motor uses 4 pins
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

void setup()
{
    // set speed of motor to 30 RPMs
    stepper.setSpeed(30);
}

void loop()
{
    int val = analogRead(0);

    // move motor a number of steps equal to the change in the sensor reading
    stepper.step(val - previous);

    // remember previous value of the sensor
    previous = val;
}