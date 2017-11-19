const int ldrPin = 0;
const int laserPin = 1;
const int ledPin = 2;


int mode = 0;
int sigReturn[27];
int tempVar;

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

    //First Car Count Output
    sigSend(16,50,255,laserPin);

    //First Car CountRequest Output
    sigSend(565,50,255,laserPin);

    //Second Car Listen
    lightRead(ldrPin, sigReturn, 650);
    tempVar = sigReturn[0]*100+sigReturn[1]*10+sigReturn[2]*1;

    //Second Car Count Output
    sigSend(temp,50,255,laserPin);
  }

}
