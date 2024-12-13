#include <Arduino.h>

const int ledPin=5;
const int buttonPin=6;

int button;
int buttonLast;

void setup() {
  // open serial port
  Serial.begin(9600);   // open serial port
  Serial.println("Serial port opened");

  // set the pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.println("Monitoring button...");
}

void loop() {
  button = digitalRead(buttonPin);
  Serial.println(button);

  if (!button && buttonLast) {
    digitalWrite(ledPin, HIGH);
    Serial.println("First condition met");
  }

  if (button && !buttonLast) {
    digitalWrite(ledPin, LOW);
    Serial.println("Second condition met");
  }

  buttonLast = button;
}