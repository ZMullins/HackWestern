const int ldrPin=0;
const int laserPin=1;


int mode=0;
int sigReturn[27];

#include "SignalEmitter.h"
#include "SignalSensor.h"

void setup() {
pinMode(ldrPin,INPUT);
pinMode(laserPin,OUTPUT);

}

void loop() {
  
if(mode=0){
//Stop sign signal
sigSend(565,50,255,laserPin);
mode=1;
} else {
  //First Car Count
  lightRead(ldrPin,sigReturn,650);
  Serial.println(sigReturn[0]);
  Serial.println(sigReturn[1]);
  
  //Second Car Count
  lightRead(ldrPin,sigReturn,650);
  Serial.println(sigReturn[0]);
  Serial.println(sigReturn[1]+sigReturn[2]);
}

}
