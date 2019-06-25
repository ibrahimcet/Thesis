#include <Servo.h>
Servo sg90;
const int trig = 2;
const int echo = 3;
int deger;
int derece;
int sure = 0;
int mesafe = 0;

void setup() {
 
  sg90.attach(7);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {

  deger = analogRead(A0);
  derece = map(deger , 0 , 1023 , 0 , 180);
  sg90.write(derece);
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  sure = pulseIn(echo,HIGH);
  mesafe = (sure/2)/29.1;
  Serial.println(mesafe);
  delay(250);
}
