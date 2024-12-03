// Arduino Project 2 - Once Upon an Arduino
// by Wesley Kuykendall + Kaleb Aziz


// Step Variable - keeps track of how many interactions the player has completed
int step = 1;


// Switch Pins
const int Switch1 = 6;
int Switch1State = 0;

const int Switch2 = 7;
int Switch2State = 0;

const int Switch3 = 4;
int Switch3State = 0;

const int Switch4 = 5;
int Switch4State = 0;


// Ultrasonic Sensor
const int Trig = 1;
const int Echo = 2;

long duration;
long distance;
int ultrastatus;
int ultraold;


// LED Pins
const int AltarLight1 = 13;
const int AltarLight2 = 12;


// Servos
#include <Servo.h>

Servo StairServo;
Servo ArceusServo;


void setup() {
  Serial.begin(9600);

  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
  pinMode(Switch4, INPUT);

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  pinMode(AltarLight1, OUTPUT);
  pinMode(AltarLight2, OUTPUT);
  
  StairServo.attach(10);
  ArceusServo.attach(9);

  StairServo.write(0);
  ArceusServo.write(0);
}


void loop() {
  // Interaction 1 - climbing the mountain
  while (step == 1) {
    Switch1State = digitalRead(Switch1);
    if (Switch1State == HIGH) {
      Serial.println("Switch 1 activated");
      digitalWrite(AltarLight1, HIGH);
      step +=1;
    }
    delayMicroseconds(1000);
  }

  // Interaction 2 - stepping onto the altar
  while (step == 2) {
    Switch2State = digitalRead(Switch2);
    if (Switch2State == HIGH) {
      Serial.println("Switch 2 activated");
      digitalWrite(AltarLight1, LOW);
      digitalWrite(AltarLight2, HIGH);
      step += 1;
    }
    delayMicroseconds(1000);
  }

  // Interaction 3 - "playing" the flute
  while (step == 3) {
    Switch3State = digitalRead(Switch3);
    if (Switch3State == HIGH) {
      Serial.println("Switch 3 activated");
      digitalWrite(AltarLight2, LOW);
      StairServo.write(55);
      step +=1;
    }
    delayMicroseconds(1000);
  }

  // Interaction 4 - stepping into the arena
  while (step == 4) {
    Switch4State = digitalRead(Switch4);
    if (Switch4State == HIGH) {
      Serial.println("Switch 4 activated");
      StairServo.write(0);
      ArceusServo.write(180);
      step +=1;
    }
    delayMicroseconds(1000);
  }

  // Interaction 5 - "catching" Arceus
  while (step == 5) {
    // Clears the trigPin
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(Echo, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    
    // Prints the distance on the Serial Monitor
    Serial.println(distance);

    // Confirming that the distance isn't a false 0
    if (distance != 0){
      if (distance <= 10) {
        Serial.println("Ultrasonic Sensor activated");
        ArceusServo.write(0);
        step +=1;
      }
    }

    delayMicroseconds(10);
  }
}
