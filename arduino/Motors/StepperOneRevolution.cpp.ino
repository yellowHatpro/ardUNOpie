// StepperOneRevolution
// The motor should revolve one revolution in one direction, then one revolution in the other direction.
#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);

void setup()
{
    stepper.setSpeed(60);
    Serial.begin(9600);
}

void loop()
{
    // step one revolution in one direction:
    Serial.println("clockwise");
    stepper.step(stepsPerRevolution);
    delay(500);

    // step one revolution in the other direction:
    Serial.println("counterclockwise");
    stepper.step(-stepsPerRevolution);
    delay(500);
}
