#define pwm  3
#define in_1  12
#define in_2  13
#define setP pinMode
#define writeD digitalWrite
#define readD digitalRead

int speed = 0;
int step = 5;

void setup() {
  Serial.begin(9600);
  setP(pwm, OUTPUT);
  setP(in_1, OUTPUT);
  setP(in_2, OUTPUT);
  clockWise();
}

void loop() {
  while(speed < 255) {
    analogWrite(pwm, speed);
    speed += step;
    delay(100);
  }
  while(speed > 0) {
    analogWrite(pwm, speed);
    speed -= step;
    delay(100);
  }
  flipDirection();
  delay(333);
}

void flipDirection() {
  writeD(in_1, !readD(in_1));
  writeD(in_2, !readD(in_2));
}

void clockWise() {
  writeD(in_1, HIGH);
  writeD(in_2, LOW);
}

void counterCW() {
  writeD(in_1, LOW);
  writeD(in_2, HIGH);
}
