int ldrVal;
int ldrValDig;
int fin = 1;
int x = 0;
int ldr = 2;
int receivedVal = 0;
bool notDone = 1;

int[27] lightRead(const int ldrPin, int[27] sigReturn, int senseVal) {

  boolean cal[3] = {0, 0, 0};
  boolean received[3] = {0, 0, 0};
  int count = 0;
  if (notDone) {}
  while (count < 4)
  {
    int plusCount = 0;
    while (plusCount < 3)
    {
      ldrVal = analogRead(ldrPin);
      if (ldrVal >= senseVal)
      {
        plusCount++;
      }
      else
      {
        plusCount = 0;
      }
      delay(50);
    }
    int zeroCount = 0;
    while (zeroCount < 3)
    {
      ldrVal = analogRead(ldrPin);
      if (ldrVal >= senseVal)
      {
        zeroCount = 0;
      }
      else
      {
        zeroCount++;
      }
      delay(50);
    }
    count++;
  }
  if (count == 3)
  {
    fin = 1;
  }
  while (fin != 0)
  {
    ldrVal = analogRead(ldrPin);
    if (ldrVal >= senseVal)
    {
      ldrValDig = 1;
    }
    else if (ldrVal < senseVal)
    {
      ldrValDig = 0;
    }
    if (x < 3)
    {
      received[x] = ldrValDig;
      x++;
    }
    if (x == 3)
    {
      if (received[0] == 1)
      {
        receivedVal = receivedVal + 4;
      }
      if (received[1] == 1)
      {
        receivedVal = receivedVal + 2;
      }
      if (received[2] == 1)
      {
        receivedVal = receivedVal + 1;
      }

      fin = receivedVal;
      sigReturn[place] = receivedVal;
      if (fin = -0) {
        notDone = false;
      }
      Serial.println(fin);
      receivedVal = 0;
      place++;
      x = 0;
    }
    delay (50);
  }
return sigReturn[];
}

