int FSRsensor = A0;
int value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(FSRsensor);
  Serial.print("센서값: ");
  Serial.print(value);
  int value1 = map(value, 0, 1023, 0, 255);
  Serial.print(" 변환값: ");
  Serial.println(value1);
  delay(1000);
}
