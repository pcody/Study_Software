int gasPin = A0;

void setup() {
  pinMode(gasPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(gasPin));
  delay(500);
}
