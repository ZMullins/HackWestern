const int ldrPin=A0;
const int laserPin1=9;


int mode=0;
int sigReturn[27];

#include "SignalEmitter.h"
#include "SignalSensor.h"

void setup() {
  Serial.begin(9600);
pinMode(ldrPin,INPUT);
pinMode(laserPin1,OUTPUT);

}

void loop() {
  
if(mode==0){
//Stop sign signal
sigSend(216,100,255,laserPin1);
mode=1;
} else {
//  //First Car Count
//  lightRead(ldrPin,sigReturn,650);
//  Serial.println(sigReturn[0]);
//  Serial.println(sigReturn[1]);
//  
//  //Second Car Count
//  lightRead(ldrPin,sigReturn,650);
//  Serial.println(sigReturn[0]);
//  Serial.println(sigReturn[1]+sigReturn[2]);
}

}
