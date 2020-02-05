/*  Arduino DC Motor Control - PWM | H-Bridge | L298N  -  Example 01

    by Dejan Nedelkovski, www.HowToMechatronics.com
*/

#define enA 4
#define in1 5
#define in2 6
#define in3 7
#define in4 8
#define enB 9

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

String power = "STOP";
void loop() {
  int pwmOutputA, pwmOutputB;
  int potValue;

  potValue = analogRead(A0); // Read potentiometer value
  pwmOutputA = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  //pwmOutputB = map(potValue, 0, 1023, 100 , 355);

  if (pwmOutputA < 120) {
    pwmOutputA = -(pwmOutputA - 120)*2;
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("DOWN");
    delay(20);
  } else if (pwmOutputA > 134) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("UP");
    delay(20);
  } else {
    analogWrite(enA, 127); // Send PWM signal to L298N Enable pin
    analogWrite(enB, 127); // Send PWM signal to L298N Enable pin
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("STOP");
  }

  analogWrite(enA, pwmOutputA); // Send PWM signal to L298N Enable pin
  //analogWrite(enB, pwmOutputB); // Send PWM signal to L298N Enable pin
  Serial.println(pwmOutputA);
}
