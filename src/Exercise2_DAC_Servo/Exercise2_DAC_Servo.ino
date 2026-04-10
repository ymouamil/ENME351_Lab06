const int dacPin   = A0;
const int servoPin = 9;

const int tMin = 700;       // this changes the 
const int tMax = 2300;      // adjust if needed
const int tPeriod = 20000;  // 20 ms

int adcMin = 0;    // set this to measured ADC for 000
int adcMax = 895;  // set this to measured ADC for 111

void setup() {
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("DAC -> Servo calibrated test");
}

void loop() {
  int adcValue = analogRead(dacPin);

  if (adcValue < adcMin) adcValue = adcMin;
  if (adcValue > adcMax) adcValue = adcMax;

  int tControl = map(adcValue, adcMin, adcMax, tMin, tMax);

  float angle = (tControl - tMin) * 180.0 / (tMax - tMin);
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;

  digitalWrite(servoPin, HIGH);
  delayMicroseconds(tControl);
  digitalWrite(servoPin, LOW);
  delayMicroseconds(tPeriod - tControl);

  Serial.print("ADC = ");
  Serial.print(adcValue);
  Serial.print(" | tControl = ");
  Serial.print(tControl);
  Serial.print(" us | Angle ~= ");
  Serial.println(angle, 1);
}