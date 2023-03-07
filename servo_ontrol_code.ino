#include <Servo.h>

int buttonPin = 12;
int buttonRead;
int dt = 50; //100ms

int controlPin = 11;

int servoOnePin = 10;
int servoTwoPin = 9;
int servoPosOne = 0;
int servoPosTwo = 90;


Servo servoOne;
Servo servoTwo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoOne.attach(servoOnePin);
  servoTwo.attach(servoTwoPin);
  pinMode(buttonPin, INPUT);
  pinMode(controlPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonRead = digitalRead(buttonPin);
  delay(dt);
  if(buttonRead == 0){
    digitalWrite(controlPin, LOW);
    servoOne.write(servoPosOne);
    servoTwo.write(servoPosOne);
  }
  if(buttonRead == 1){
    digitalWrite(controlPin, HIGH);
    servoOne.write(servoPosTwo);
    servoTwo.write(servoPosTwo);
  }
}
