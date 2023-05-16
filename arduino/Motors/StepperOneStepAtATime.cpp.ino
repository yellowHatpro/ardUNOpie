// StepperOneStepAtATime

// The motor will step one step at a time, very slowly.
// You can use this to test that you've got the four wires of your stepper wired to the correct pins.
// If wired correctly, all steps should be in the same direction.

#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    stepper.step(1);
    Serial.print("steps:");
    Serial.println(stepCount);
    stepCount++;
    delay(500);
}