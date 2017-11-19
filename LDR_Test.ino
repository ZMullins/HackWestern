const int ldrPin=A0;

int ldrVal;
int ldrValDig;
int fin = 1;
int x = 0;
int ldr = 2;
int receivedVal = 0;
unsigned long time1;
unsigned long time2;

void setup() {
  // put your setup code here, to run once:
  pinMode (A0, INPUT);


  Serial.begin(9600);
}

void loop() {
  boolean cal[3] = {0, 0, 0};
  boolean received[3] = {0, 0, 0};
  int count = 0;
  while (count < 4)
  {
    int plusCount = 0;
    while (plusCount < 3)
    {
      ldrVal = analogRead(A0);
      if (ldrVal >= 650)
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
      ldrVal = analogRead(A0);
      if (ldrVal >= 650)
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
    ldrVal = analogRead(A0);
    if (ldrVal >= 650)
    {
      ldrValDig = 1;
    }
    else if (ldrVal < 650)
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
//      Serial.print ("ARR");
//      Serial.print(" ");
//      Serial.print (received[0]);
//      Serial.print(" ");
//      Serial.print(received[1]);
//      Serial.print(" ");
//      Serial.println(received[2]);
      Serial.println(fin);
      receivedVal = 0;
      x = 0;
    }
    //    {
    //      for (int i = 0; i < 3; i++)
    //      {
    //        if (received[i])
    //        {
    //          receivedVal = receivedVal | (1 << i);
    //        }
    //      }
    //      //receivedVal = received[0] | (received[1] << 1) | (received[2] << 2);
    //      x = 0;
    //    }
    // if (ldrVal > 300)
    //Serial.println (ldrValDig);



    delay (50);
  }

}
