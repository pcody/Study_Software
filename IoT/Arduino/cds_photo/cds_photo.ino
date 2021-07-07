int cds = A0;
void setup() {
  pinMode(cds, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(cds);
  Serial.println(val);
  delay(500);
}
