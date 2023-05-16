const int button1Pin = 2;
const int button2Pin = 4;
const int relay1Pin = 7;
const int relay2Pin = 8;

int button1State = 0;
int button2State = 0;

const int sensorPin = 0;
int sensorValue = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(button1Pin, INPUT);
    pinMode(button2Pin, INPUT);
    pinMode(relay1Pin, OUTPUT);
    pinMode(relay2Pin, OUTPUT);
}

void loop()
{
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);

    button1State = digitalRead(button1Pin);
    button2State = digitalRead(button2Pin);

    if (button1State == HIGH && button2State == LOW)
    {
        digitalWrite(relay1Pin, HIGH);
    }
    else if (digitalRead(relay1Pin) == HIGH)
    {
        digitalWrite(relay1Pin, LOW);
    }

    if (button2State == HIGH && button1State == LOW)
    {
        digitalWrite(relay2Pin, HIGH);
    }
    else if (digitalRead(relay2Pin) == HIGH)
    {
        digitalWrite(relay2Pin, LOW);
    }
}