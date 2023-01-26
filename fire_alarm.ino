const int buzzerPin = 12;
const int flamePin = 11;
int Flame = HIGH;
int redled = 5;
int greenled = 6;

void setup() {
    pinMode(buzzerPin, OUTPUT);
    pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(flamePin, INPUT);
    Serial.begin(9600);
}

void loop() {
    Flame = digitalRead(flamePin);
    if (Flame== LOW) {
        Serial.println("ALL GOOD!");
        digitalWrite(buzzerPin, LOW);
        digitalWrite(redled, LOW);
        digitalWrite(greenled, HIGH);
    } else {
        Serial.println("FIRE!!!!");
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(greenled, LOW);
        digitalWrite(redled, HIGH);
    }
}
