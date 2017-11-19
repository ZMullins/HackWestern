const int ldrPin = A1;
const int laserPin = A2;
const int ldrBackPin=A0;
const int laserBackPin=A3;
const int ledPin = 2;


int mode = 0;
int sigReturn[8]={0,0,0,0,0,0,0,0};
int tempVar;

#include "SignalEmitter.h"
#include "SignalSensor.h"

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(laserPin, OUTPUT);

}

void loop() {
if (mode == -1) {
  delay(40);
  Serial.println(analogRead(A1));
}
  else if (mode == 0) {
    //Stop sign signal
    lightRead(ldrPin, sigReturn, 600);
    if (sigReturn[0]) {
          mode=1;
              for (int i = 0; i < 3; i++){
    Serial.println(sigReturn[i]);}
    }

    

  } 
  else {

    //First Car Count Output
    sigSend(16,100,255,laserPin);
 
    //First Car CountRequest Output
    sigSend(565,100,255,laserBackPin);

    //Second Car Listen
    lightRead(ldrBackPin, sigReturn, 650);
    tempVar = sigReturn[0]*100+sigReturn[1]*10+sigReturn[2]*1;

    //Second Car Count Output
    sigSend(temp,100,255,laserPin);
  }

}
