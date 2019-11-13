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
//  int potValue = analogRead(A0); // Read potentiometer value
//  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  while(Serial.available()==0){}
  String power = Serial.readString();
  
  analogWrite(enA, 255); // Send PWM signal to L298N Enable pin
  analogWrite(enB, 255); // Send PWM signal to L298N Enable pin
  if (power.equals("UP\n")) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("UP");
    delay(20);
  }
  if (power.equals("DOWN\n")) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("DOWN");
    delay(20);
  }
  if (power.equals("STOP\n")){
    analogWrite(enA, 127); // Send PWM signal to L298N Enable pin
    analogWrite(enB, 127); // Send PWM signal to L298N Enable pin
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
//    digitalWrite(in3, LOW);
//    digitalWrite(in4, LOW);
    Serial.println("STOP");
  }
}
