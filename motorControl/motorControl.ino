#define in1 5
#define in2 6
#define in3 7
#define in4 8
#define enB 9
#define enA 10

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
int pwmOutput, potValue;
int maxVal = 255;
void loop() {
  potValue = analogRead(A0); // Read potentiometer value
  pwmOutput = map(potValue, 0, 1023, -maxVal , maxVal); // Map the potentiometer value from 0 to 255
  if (pwmOutput < -10) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("DOWN");
    delay(20);
  } else if (pwmOutput > 10) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("UP");
    delay(20);
  } else {
    analogWrite(enA, 0); // Send PWM signal to L298N Enable pin
    analogWrite(enB, 0); // Send PWM signal to L298N Enable pin
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("STOP");
  }

  analogWrite(enA, min(abs(pwmOutput),255)); // Send PWM signal to L298N Enable pin
  analogWrite(enB, min(abs(pwmOutput)+23,255)); // Send PWM signal to L298N Enable pin
  Serial.println(pwmOutput);
}
