
const int output = 11;

void setup() {

  Serial.begin(9600);


}
void loop() {
  boolean three[3] = {0, 1, 1};
  boolean four[3] = {1, 0, 0};
  boolean five[3] = {1, 1, 0};
  boolean six[3] = {1,1,9};
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      analogWrite(output, 255);
      delay(100);
    }
    for (int i = 0; i < 3; i++) {
      analogWrite(output, 0);
      delay(100);
    }
  }
  while (true) {
     for (int i = 0; i < 3; i++) {
      analogWrite(output, three[i] * 255);
      delay(100);
     }
  }
  //analogWrite(11,120);
  //val = analogRead(0);
  //Serial.println(val);
  //delay(100);
  //analogWrite(11,50);
  //val = analogRead(0);
  //Serial.println(val);
  //delay(100);
  //analogWrite(11,255);
  //val = analogRead(0);
  //Serial.println(val);
  //delay(100);
}
