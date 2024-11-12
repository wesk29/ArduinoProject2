// Arduino Project 2 - Once Upon an Arduino
// by Wesley Kuykendall + Kaleb Aziz


// Step Variable - keeps track of how many interactions the player has completed
int step = 1;


// Switch Pins
const int Switch1 = 2;
int Switch1State = 0;

const int Switch2 = 3;
int Switch2State = 0;

const int Switch3 = 4;
int Switch3State = 0;

const int Switch4 = 5;
int Switch4State = 0;

const int Switch5 = 6;
int Switch5State = 0;


// LED Pins
const int AltarLight = 13;
const int FluteLight = 12;


// Servos
#include <Servo.h>

Servo StairServo;
Servo ArceusServo;


void setup() {
  Serial.begin(9600);

  pinMode(Switch1, INPUT);

  pinMode(AltarLight, OUTPUT);
  pinMode(FluteLight, OUTPUT);
  
  StairServo.attach(11);
  ArceusServo.attach(10);
}


void loop() {
  // Interaction 1 - climbing the mountain
  while (step == 1) {
    Switch1State = digitalRead(Switch1);
    if (Switch1State == HIGH) {
      Serial.print("Switch 1 activated");
      digitalWrite(AltarLight, HIGH);
      step +=1;
    }
  }

  // Interaction 2 - stepping onto the altar
  while (step == 2) {
    Switch2State = digitalRead(Switch2);
    if (Switch2State == HIGH) {
      Serial.print("Switch 2 activated");
      digitalWrite(AltarLight, LOW);
      digitalWrite(FluteLight, HIGH);
      step +=1;
    }
  }

  // Interaction 3 - "playing" the flute
  while (step == 3) {
    Switch3State = digitalRead(Switch3);
    if (Switch3State == HIGH) {
      Serial.print("Switch 3 activated");
      StairServo.write(90);
      step +=1;
    }
  }

  // Interaction 4 - stepping into the arena
  while (step == 4) {
    Switch4State = digitalRead(Switch4);
    if (Switch4State == HIGH) {
      Serial.print("Switch 4 activated");
      StairServo.write(0);
      ArceusServo.write(90);
      step +=1;
    }
  }

  // Interaction 5 - "catching" Arceus
  while (step == 5) {
    Switch5State = digitalRead(Switch5);
    if (Switch5State == HIGH) {
      Serial.print("Switch 5 activated");
      ArceusServo.write(270);
      step +=1;
    }
  }

  delayMicroseconds(10);
}
