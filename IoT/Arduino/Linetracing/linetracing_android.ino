#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motorL(1);
AF_DCMotor motorR(2);
SoftwareSerial RPI(2,3); //RXD=2, TXD=3

int senL = 10;
int senR = 13;
int dataL = 0;
int dataR = 0;
int autoOrManual = 1;

void setup() {
  Serial.begin(9600);
  RPI.begin(9600);
  motorL.setSpeed(255);
  motorR.setSpeed(255);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
}

void loop() {
  char ch;
  
  dataL = digitalRead(senL);
  dataR = digitalRead(senR);
  
  if (RPI.available()) {
    ch = RPI.read();
    Serial.print("읽은 값:");
    Serial.println(ch);
    if (ch == 'a') {
      autoOrManual = 1;
    }
    else if (ch == 'm') {
      autoOrManual = 2;
    }
  }

  if (autoOrManual == 1 && (ch == 'p' || ch == 'w')) {
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
  else if (autoOrManual == 2) {
    if (ch == 'f') {
      m_go();
    }
    else if (ch == 'l') {
      m_left();
    }
    else if (ch == 'r') {
      m_right();
    }
    else if (ch == 's') {
      m_stop();
    }
    else if (ch == 'b') {
      m_back();
    }
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
void m_back() {
  motorL.run(BACKWARD);
  motorR.run(BACKWARD);
  delay(20);
}
