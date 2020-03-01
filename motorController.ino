#define pwm  3
#define in_1  12
#define in_2  13

int speed = 0;
int step = 5;

void setup() {
  Serial.begin(9600);
  pinMode(pwm, OUTPUT);
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
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
  digitalWrite(in_1, !digitalRead(in_1));
  digitalWrite(in_2, !digitalRead(in_2));
}

void clockWise() {
  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
}

void counterCW() {
  digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);
}
