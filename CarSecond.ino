const int ldrPin = 0;
const int laserPin = 1;
const int ledPin = 2;


int mode = 0;
int sigReturn[27];

#include "SignalEmitter.h"
#include "SignalSensor.h"

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(laserPin, OUTPUT);

}

void loop() {

  if (mode = 0) {
    //Stop sign signal
    lightRead(ldrPin, sigReturn, 650);
    if (sigReturn[0]) {
      digitalWrite(ledPin, HIGH);
    }
    mode=1;
    
  } else {

    //Second Car Count Output
    sigSend(523,50,255,laserPin);
  }

}
