// Preset Position using Positional Feedback

const int button1Pin = 2;
const int button2Pin = 4;
const int relay1Pin = 7;
const int relay2Pin = 8;

int button1State = 0;
int button2State = 0;

int sensorValue = 0;

int goalPosition = 350;
int currentPosition = 0;

bool Extending = false;
bool Retracting = false;

void setup()
{
    Serial.begin(9600);
    pinMode(button1Pin, INPUT);
    pinMode(button2Pin, INPUT);
    pinMode(relay1Pin, OUTPUT);
    pinMode(relay2Pin, OUTPUT);
    // preset the relays to low
    digitalWrite(relay1Pin, LOW);
    digitalWrite(relay2Pin, LOW);
}

void loop()
{
    Serial.print("Current = ");
    Serial.print(currentPosition);
    Serial.print("\t Goal = ");
    Serial.println(goalPosition);

    button1State = digitalRead(button1Pin);
    button2State = digitalRead(button2Pin);

    if (button1State == HIGH)
    {
        // set new goal position
        goalPosition = 300;
        if (goalPosition > currentPosition)
        {
            Extending = true;
            Retracting = false;
            digitalWrite(relay1Pin, HIGH);
            digitalWrite(relay2Pin, LOW);
            Serial.println("Extending");
        }
        else if (goalPosition < currentPosition)
        {
            Extending = false;
            Retracting = true;
            digitalWrite(relay1Pin, LOW);
            digitalWrite(relay2Pin, HIGH);
            Serial.println("Retracting");
        }
    }
    if (button2State == HIGH)
    {
        // set new goal position
        goalPosition = 500;
        if (goalPosition > currentPosition)
        {
            Extending = true;
            Retracting = false;
            digitalWrite(relay1Pin, HIGH);
            digitalWrite(relay2Pin, LOW);
            Serial.println("Extending");
        }
        else if (goalPosition < currentPosition)
        {
            Extending = false;
            Retracting = true;
            digitalWrite(relay1Pin, LOW);
            digitalWrite(relay2Pin, HIGH);
            Serial.println("Retracting");
        }
    }

    if (Extending == true && currentPosition > goalPosition)
    {
        // we reached the goal position
        digitalWrite(relay1Pin, LOW);
        Extending = false;
        Serial.println("IDLE");
    }
    if (Retracting == true && currentPosition < goalPosition)
    {
        // we reached the goal position
        digitalWrite(relay2Pin, LOW);
        Retracting = false;
        Serial.println("IDLE");
    }