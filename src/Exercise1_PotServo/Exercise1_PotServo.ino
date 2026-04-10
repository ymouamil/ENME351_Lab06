
const int potPin = A0;
const int servoPin = 9;

// 0 degrees = 600us, 180 degrees = 2400us
const int pulseMin = 600;     
const int pulseMax = 2400;    
const int period = 20000;     // 20ms

void setup() {
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lab 6 Ex1 - Turn the potentiometer");
}

void loop() {
  int potValue = analogRead(potPin);           // 0 to 1023
  int pulseWidth = map(potValue, 0, 1023, pulseMin, pulseMax);
  int angle = map(potValue, 0, 1023, 0, 180);
  
  // Send PWM pulse
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
  delayMicroseconds(period - pulseWidth);
  
  // Print to Serial Monitor
  Serial.print("Pot:");
  Serial.print(potValue);
  Serial.print(" Pulse:");
  Serial.print(pulseWidth);
  Serial.print("us Angle:");
  Serial.println(angle);
  
  delay(15);
}