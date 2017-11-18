
const int output1=2;
const int input1=7;

int testval=1;

void setup() {
wire.begin();
Serial.begin(2400);

pinMode(output1, OUTPUT);
pinMode(input1, INPUT);
}

void loop() {

  output1=100;

  delay(400);

  output1=0;

  delay(400);

}
