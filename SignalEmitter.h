boolean one[3] = {0, 0, 1};
boolean two[3] = {0, 1, 0};
boolean three[3] = {0, 1, 1};
boolean four[3] = {1, 0, 0};
boolean five[3] = {1, 1, 0};
boolean six[3] = {1, 1, 9};

int numberArr[8];
int temp;
int sizeArr = 8;
int sigArray[8];
int boxVal;

//4635

bool sigSend(int number,int delayVal,int highVal, const int laserPin) {

  //NumberFix
  //Splitter
  for (int i = 0; i < 8; i++) {
    numberArr[i] = number / (10 * (i + 1));
    temp = numberArr[i] % 10;
    if (!temp) {
      sizeArr = i;
      break;
    }
    numberArr[i] = temp;
  }

  //Reverse
  temp = sizeArr / 2;
  for (int i = 0; i < temp; i++) {
    int temp = numberArr[i];
    numberArr[i] = numberArr[7 - i];
    numberArr[7 - i] = temp;
  }

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
  //

  int i = 0;
  while (numberArr[i]) {
    boxVal = numberArr[i];
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


bool fastOn(int fast, int highVal) {
  analogWrite(laserPin, highVal);
  delay(fast);
  analogWrite(laserPin, 0);
}




