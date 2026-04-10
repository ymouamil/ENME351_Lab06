/*
 * Test 3-bit R-2R DAC
 * Manually set bits by connecting wires to 5V or GND
 * Read output voltage on A0
 */

const int dacReadPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("3-Bit DAC Test");
  Serial.println("Connect bits to 5V=1 or GND=0");
  Serial.println("Bit2 (MSB), Bit1, Bit0 (LSB)");
  Serial.println("");
}

void loop() {
  int adcValue = analogRead(dacReadPin);
  float voltage = adcValue * (5 / 1023.0);
  
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.println("V");
  
  delay(500);
}