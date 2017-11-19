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
unsigned long time1;
unsigned long time2;
//4635

bool sigSend(int number, unsigned long timeInterval, int highVal, const int laserPin) {
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
      if (timeInterval <= time2 - time1) {
        analogWrite(laserPin, highVal);
      }
      time2 = millis();
    }
    for (int i = 0; i < 3; i++) {
      if (timeInterval <= time2 - time1) {
        analogWrite(laserPin, 0);
      }
      time2 = millis();
    }
  }
  //

  int i = 0;
  time1 = millis();
  time2 = millis();
  while (numberArr[i]) {
    boxVal = numberArr[i];
    //Sender
    if (boxVal == 1) {
      for (int i = 0; i < 3; i++) {
        if (timeInterval <= time2 - time1) {
          analogWrite(laserPin, one[i] * highVal);
        }
        time2 = millis();
      }
    } else if (boxVal == 2) {
      for (int i = 0; i < 3; i++) {
        if (timeInterval <= time2 - time1) {
          analogWrite(laserPin, two[i] * highVal);
        }
        time2 = millis();
      }
    } else if (boxVal == 3) {
      for (int i = 0; i < 3; i++) {
        if (timeInterval <= time2 - time1) {
          analogWrite(laserPin, three[i] * highVal);
        }
        time2 = millis();
      }
    } else if (boxVal == 4) {
      for (int i = 0; i < 3; i++) {
        if (timeInterval <= time2 - time1) {
          analogWrite(laserPin, four[i] * highVal);
        }
        time2 = millis();
      }
    } else if (boxVal == 5) {
      for (int i = 0; i < 3; i++) {
        if (timeInterval <= time2 - time1) {
          analogWrite(laserPin, five[i] * highVal);
        }
        time2 = millis();
      }
    } else if (boxVal == 6) {
      for (int i = 0; i < 3; i++) {
        if (timeInterval <= time2 - time1) {
          analogWrite(laserPin, six[i] * highVal);
        }
        time2 = millis();
      }
    }
  }

}


bool fastOn(int highVal) {
  analogWrite(laserPin, highVal);
  analogWrite(laserPin, 0);
}




