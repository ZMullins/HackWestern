#include "math.h"

boolean one[3] = {0, 0, 1};
boolean two[3] = {0, 1, 0};
boolean three[3] = {0, 1, 1};
boolean four[3] = {1, 0, 0};
boolean five[3] = {1, 0, 1};
boolean six[3] = {1, 1, 0};

int numberArr[8];
int temp;
int sizeArr = 8;
int sigArray[8]={0,0,0,0,0,0,0,0};
int boxVal;

//4635

bool sigSend(int number,int delayVal,int highVal, const int laserPin) {

  //NumberFix
  //Splitter
  for (int i = 0; i < 8; i++) {
    numberArr[i] = number / (pow(10,i));
    temp = numberArr[i] % 10;
    if (temp == 0) {
      sizeArr = i;
      break;
    }
    numberArr[i] = temp;
    Serial.println(numberArr[i]);
  }

//  //Reverse
//  temp = sizeArr / 2;
//  for (int i = 0; i <= temp; i++) {
//    int t = numberArr[i];
//    numberArr[i] = numberArr[7 - i];
//    numberArr[7 - i] = t;
//    Serial.println(numberArr[0]);
//    Serial.println(numberArr[1]);
//    Serial.println(numberArr[2]);
//    Serial.println(numberArr[3]);
//  }

  //Callibration Sender
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      analogWrite(laserPin, highVal);
      delay(delayVal);
    }
    for (int i = 0; i < 3; i++) {
      analogWrite(laserPin, 0);
      delay(delayVal);
    }
  }
  

  int j = 0;
  while (j<sizeArr) {
    Serial.println(numberArr[j]);
    boxVal = numberArr[j];
    j++;
    //Sender
    if (boxVal == 1) {
      for (int i = 0; i < 3; i++) {
        analogWrite(laserPin, one[i] * highVal);
        delay(delayVal);
      }
    } else if (boxVal == 2) {
      for (int i = 0; i < 3; i++) {
        analogWrite(laserPin, two[i] * highVal);
        delay(delayVal);
      }
    } else if (boxVal == 3) {
      for (int i = 0; i < 3; i++) {
        analogWrite(laserPin, three[i] * highVal);
        delay(delayVal);
      }
    } else if (boxVal == 4) {
      for (int i = 0; i < 3; i++) {
        analogWrite(laserPin, four[i] * highVal);
        delay(delayVal);
      }
    } else if (boxVal == 5) {
      for (int i = 0; i < 3; i++) {
        analogWrite(laserPin, five[i] * highVal);
        delay(delayVal);
      }
    } else if (boxVal == 6) {
      for (int i = 0; i < 3; i++) {
        analogWrite(laserPin, six[i] * highVal);
        delay(delayVal);
      }
    }
  }
}


bool fastOn(int fast, int , const int laserPin) {
  analogWrite(laserPin, 225);
  delay(fast);
  analogWrite(laserPin, 0);
}




