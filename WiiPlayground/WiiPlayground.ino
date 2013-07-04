#include "Wire.h"
#include "WiiClassic.h"

WiiClassic wiiClassy = WiiClassic();

void setup() {
  Wire.begin();                                                           // Begin wire connection
  Serial.begin(9600);                                                     // Begin Serial on 9600 baud
  wiiClassy.begin();                                                      // Initialize the Wii Classic controller
  wiiClassy.update();                                                     // Gather data from the controller for the first time as this isually bogus
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
  delay(100);
}



