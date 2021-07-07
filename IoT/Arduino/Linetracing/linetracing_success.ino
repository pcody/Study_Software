#include <AFMotor.h>

AF_DCMotor motorL(1);
AF_DCMotor motorR(2);

int senL = 10;
int senR = 13;
int dataL = 0;
int dataR = 0;

void setup() {
  Serial.begin(9600);
  motorL.setSpeed(255);
  motorR.setSpeed(255);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
}

void loop() {
  dataL = digitalRead(senL);
  dataR = digitalRead(senR);
  Serial.print("dataL: ");
  Serial.print(dataL);
  Serial.print(" dataR: ");
  Serial.print(dataR);
  if (dataL == 1 && dataR == 1) { //검검 직진
    m_go();
  }
  else if (dataL == 0 && dataR == 1) { //흰검 오른쪽으로
    m_right();
  }
  else if (dataL == 1 && dataR == 0) { //검흰 왼쪽으로
    m_left();
  }
  else if (dataL == 0 && dataR == 0) { //흰흰 정지
    m_stop();
  }
}

void m_go() {
  motorL.run(FORWARD);
  motorR.run(FORWARD);
  delay(20);
}
void m_stop() {
  motorL.run(RELEASE);
  motorR.run(RELEASE);
  delay(20);
}
void m_left() {
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(20);
}
void m_right() {
  motorL.run(FORWARD);
  motorR.run(BACKWARD);
  delay(20);
}
