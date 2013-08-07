#include "Wire.h"
#include "WiiClassic.h"

WiiClassic wiiClassy = WiiClassic();

int rightFrontDir = 2;
int rightFrontPwm = 3;

int leftFrontDir = 4;
int leftFrontPwm = 5;

int rightBackDir = 12;
int rightBackPwm = 11;

int leftBackDir = 8;
int leftBackPwm = 9;


void setup() {
  Wire.begin();                                                           // Begin wire connection
  Serial.begin(9600);                                                     // Begin Serial on 9600 baud
  wiiClassy.begin();                                                      // Initialize the Wii Classic controller
  wiiClassy.update();                                                     // Gather data from the controller for the first time as this isually bogus

  pinMode(rightFrontDir, OUTPUT);
  pinMode(rightFrontPwm, OUTPUT);
  pinMode(leftFrontDir, OUTPUT);
  pinMode(leftFrontPwm, OUTPUT);

  pinMode(rightBackDir, OUTPUT);
  pinMode(rightBackPwm, OUTPUT);
  pinMode(leftBackDir, OUTPUT);
  pinMode(leftBackPwm, OUTPUT);

  Serial.println("Setup complete");
}

void loop() {
  wiiClassy.update();                                                     // Poke the controller for status

  Serial.print("LS:");
  if(wiiClassy.leftShoulderPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(",");
  Serial.print(wiiClassy.leftShouldPressure());
  Serial.print(" ");

  Serial.print("RS:");
  if(wiiClassy.rightShoulderPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(",");
  Serial.print(wiiClassy.rightShouldPressure());
  Serial.print(" ");

  Serial.print("LZ:");
  if(wiiClassy.lzPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");

  Serial.print("RZ:");
  if(wiiClassy.rzPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");

  Serial.print("Sel:");
  if(wiiClassy.selectPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");      

  Serial.print("H:");
  if(wiiClassy.homePressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");     

  Serial.print("st:");
  if(wiiClassy.startPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");    

  Serial.print("A:");
  if(wiiClassy.aPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");    

  Serial.print("B:");
  if(wiiClassy.bPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");   

  Serial.print("X:");
  if(wiiClassy.xPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");   

  Serial.print("Y:");
  if(wiiClassy.yPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");   

  Serial.print("DU:");
  if(wiiClassy.upDPressed()){
    Serial.print("1");    
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");

  Serial.print("DD:");
  if(wiiClassy.downDPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");

  Serial.print("DL:");
  if(wiiClassy.leftDPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");

  Serial.print("DR:");
  if(wiiClassy.rightDPressed()){
    Serial.print("1");
  } 
  else {
    Serial.print("0");
  }
  Serial.print(" ");

  Serial.print("LJ:");
  Serial.print(wiiClassy.leftStickX());
  Serial.print(",");
  Serial.print(wiiClassy.leftStickY());
  Serial.print(" ");

  Serial.print("RJ:");
  Serial.print(wiiClassy.rightStickX());
  Serial.print(",");
  Serial.print(wiiClassy.rightStickY());
  Serial.print(" ");

  Serial.println();

  int rightFrontPower = 0;
  int leftFrontPower = 0;
  int rightFrontDirection = HIGH;
  int leftFrontDirection = HIGH;

  int rightBackPower = 0;
  int leftBackPower = 0;
  int rightBackDirection = HIGH;
  int leftBackDirection = HIGH;

  int rightY = wiiClassy.rightStickY();
  if(rightY > 16)
  {
    moveRightWheels(map(rightY, 17, 28, 1, 250), true);
  }
  else if(rightY < 14)
  {
    moveRightWheels(map(rightY, 13, 2, 1, 250), false);
  }
  else{
    moveRightWheels(0, true);
  }

  int leftY = wiiClassy.leftStickY();
  if(leftY > 33)
  {
    moveLeftWheels(map(leftY, 34, 57, 1, 250), true);
  }
  else if(leftY < 31)
  {
    moveLeftWheels(map(leftY, 30, 6, 1, 250), false);
  }
  else {
    moveLeftWheels(0, true);
  }

  delay(100);
}

void moveLeftWheels(int power, boolean isForward){
  if(isForward){
    digitalWrite(leftFrontDir, HIGH);
    digitalWrite(leftBackDir, LOW);
  }
  else{
    digitalWrite(leftFrontDir, LOW);
    digitalWrite(leftBackDir, HIGH);
  }
  analogWrite(leftFrontPwm, power);
  analogWrite(leftBackPwm, power);
}

void moveRightWheels(int power, boolean isForward){
  if(isForward){
    digitalWrite(rightFrontDir, HIGH);
    digitalWrite(rightBackDir, LOW);
  }
  else{
    digitalWrite(rightFrontDir, LOW);
    digitalWrite(rightBackDir, HIGH);
  }
  analogWrite(rightFrontPwm, power);
  analogWrite(rightBackPwm, power);
}





