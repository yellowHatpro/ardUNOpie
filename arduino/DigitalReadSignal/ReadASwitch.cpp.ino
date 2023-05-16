// Digital PIN 2 has a pushbutton connected to it.
int pushButton = 2;

void setup()
{
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
}

void loop()
{
    int buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    delay(1);
}
