const int capSwitch1 = 1;
const int capSwitch2 = 2;
const int capSwitch3 = 3;
const int capSwitch4 = 4;
const int sigLight = 5;

const int ldrPin=A0;

const int startButton=6;

int mode=2;
int winMail;
bool isFull;
bool firstOnly;
int carID[27];


#include "SignalSensor.h"


void setup() {
  Serial.begin(9600);
  
  //Capactive Sensors
  pinMode(capSwitch1, INPUT);
  pinMode(capSwitch2, INPUT);
  pinMode(capSwitch3, INPUT);
  pinMode(capSwitch4, INPUT);
  //ModeStart
  pinMode(startButton,INPUT);
  //LaserEmitter
  pinMode(sigLight, OUTPUT);

}

void loop() {

//Begin Mailbox Demo
if (startButton){
  mode=1;
}

  //mailbox signal is being outputted

  //mailbox receives car ID and chooses mailbox
  lightRead(ldrPin, carID, 650);
  Serial.println(carID[0]+carID[1]+carID[2]+carID[3]);
  

  //mailbox sends isFull value
  if (mode = 3) {
    if (firstOnly) {
      if (winMail == 1) {
        isFull = digitalRead(capSwitch1);
      } else if (winMail == 2) {
        isFull = digitalRead(capSwitch2);
      } else if (winMail == 3) {
        isFull = digitalRead(capSwitch3);
      } else if (winMail == 4) {
        isFull = digitalRead(capSwitch4);
      }
      firstOnly=false;
    }

    //send out the isFull value to car
    //mode=0;
    //firstOnly=true;

  }



}
