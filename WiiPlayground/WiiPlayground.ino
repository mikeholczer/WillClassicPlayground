#include "Wire.h"
#include "WiiClassic.h"

WiiClassic wiiClassy = WiiClassic();

int m3dir = 2;
int m3pwm = 3;
int m4dir = 4;
int m4pwm = 5;

void setup() {
  Wire.begin();                                                           // Begin wire connection
  Serial.begin(9600);                                                     // Begin Serial on 9600 baud
  wiiClassy.begin();                                                      // Initialize the Wii Classic controller
  wiiClassy.update();                                                     // Gather data from the controller for the first time as this isually bogus
  
  pinMode(m3dir, OUTPUT);
  pinMode(m3pwm, OUTPUT);
  pinMode(m4dir, OUTPUT);
  pinMode(m4pwm, OUTPUT);
  
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
  
  int rightPower = 0;
  int leftPower = 0;
  int rightDirection = HIGH;
  int leftDirection = HIGH;
  
  int rightY = wiiClassy.rightStickY();
  if(rightY > 16)
  {
    rightDirection = HIGH;
    rightPower = map(rightY, 17, 28, 1, 250);
  }
  if(rightY < 14)
  {
    rightDirection = LOW;
    rightPower = map(rightY, 13, 2, 1, 250);
  }
  
  int leftY = wiiClassy.leftStickY();
  if(leftY > 33)
  {
    leftDirection = HIGH;
    leftPower = map(leftY, 34, 57, 1, 250);
  }
  if(leftY < 31)
  {
    leftDirection = LOW;
    leftPower = map(leftY, 30, 6, 1, 250);
  }
  
  Serial.print("direction:");
  Serial.print(rightDirection);
  
  Serial.print(" ");
  
  Serial.print("rightPower: ");
  Serial.print(rightPower);
  Serial.println();
  
  digitalWrite(m4dir, leftDirection);
  digitalWrite(m3dir, rightDirection);
  
  analogWrite(m4pwm, leftPower);
  analogWrite(m3pwm, rightPower);
  
  delay(100);
}



