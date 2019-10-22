/*  Arduino DC Motor Control - PWM | H-Bridge | L298N  -  Example 01

    by Dejan Nedelkovski, www.HowToMechatronics.com
*/

#define enA 9
#define in1 6
#define in2 7

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  Serial.begin(9600);
}

int incomingByte = 127;
void loop() {
//  int potValue = analogRead(A0); // Read potentiometer value
//  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  incomingByte = Serial.read();
  analogWrite(enA, incomingByte); // Send PWM signal to L298N Enable pin
  if (incomingByte < 127) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(20);
  }
  if (incomingByte > 127) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(20);
  }
}
