// Arduino Project 2 - Once Upon an Arduino
// by Wesley Kuykendall

//declare LED Pins
int LedPin1 = 9;
int LedPin2 = 10;
int LedPin3 = 11;
int LedPin4 = 12;
int LedPin5 = 13;
//declare LED Brightness
int LedBrightness1 = 0;
int LedBrightness2 = 0;
int LedBrightness3 = 0;
int LedBrightness4 = 0;
int LedBrightness5 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
