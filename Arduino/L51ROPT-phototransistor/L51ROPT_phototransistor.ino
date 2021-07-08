int flame = A0;
int val = 0;

void setup() {
  pinMode(flame, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(flame);
  Serial.println(val);
}
// 포토 트랜지스터 짧은 다리가 콜렉터(5V)
