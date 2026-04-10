# ENME 351 Lab 6 — Digital to Analog Conversion and Servo Motors

## Overview

This project demonstrates how to control a servo motor using two different methods:

1. A potentiometer (continuous analog control)
2. A 3-bit R-2R Digital-to-Analog Converter (DAC) (discrete digital control)

The DAC converts digital bit inputs into analog voltage levels. The Arduino reads this voltage using its ADC and maps it to a PWM signal to control the servo position.

---

## System Flow

Digital bits → R-2R DAC → Analog voltage → Arduino ADC → PWM → Servo motor

---

## DAC Theory

For a 3-bit R-2R DAC:

Vout = Vref * (b2/2 + b1/4 + b0/8)

Where:
- Vref = 5V
- b2 = MSB, b0 = LSB

The least significant bit (LSB) voltage is:

VLSB = 5 / 8 = 0.625 V

---

## Output Voltage Table

| Bits | Decimal | Voltage (V) |
|------|--------:|------------:|
| 000  | 0       | 0.000       |
| 001  | 1       | 0.625       |
| 010  | 2       | 1.250       |
| 011  | 3       | 1.875       |
| 100  | 4       | 2.500       |
| 101  | 5       | 3.125       |
| 110  | 6       | 3.750       |
| 111  | 7       | 4.375       |

---

## Simulation

The DAC was simulated using CircuitLab to verify expected output voltages.

### Example Simulation Outputs

![DAC Output 001](dac_simulation_001.png)

![DAC Output 100](dac_simulation_100.png)

---

## Physical Implementation

The DAC was built using:

- R = 10 kΩ
- 2R = 20 kΩ
- Manual switching of bits using 5V (logic 1) and GND (logic 0)

The output voltage was measured using the Arduino analog input.

### Sources of Error

Small discrepancies between theoretical and measured values are expected due to:

- Resistor tolerances
- Breadboard wiring resistance
- ADC quantization
- Loading effects

---

## Servo Control Using DAC

The DAC output voltage is read by the Arduino (A0) and mapped into a PWM signal that drives the servo motor.

Control pipeline:

Digital → Analog → Digital → PWM → Mechanical motion

---

## Observed Behavior

- The servo moves in discrete steps
- Each DAC input combination produces a unique position
- Motion is not smooth, unlike potentiometer control

---

## Number of Positions

A 3-bit DAC provides:

2^3 = 8 possible input combinations

Therefore, the servo can move to **8 discrete positions**

---

## Approximate Angle Mapping

Ideally, the servo positions span the full range:

| Bits | Approx Angle |
|------|-------------|
| 000  | ~0°         |
| 001  | ~26°        |
| 010  | ~51°        |
| 011  | ~77°        |
| 100  | ~103°       |
| 101  | ~129°       |
| 110  | ~154°       |
| 111  | ~180°       |

Actual angles may vary due to servo nonlinearity and calibration.

---

## Comparison

| Method          | Resolution        | Behavior          |
|-----------------|------------------|-------------------|
| Potentiometer   | Continuous       | Smooth motion     |
| 3-bit DAC       | 8 discrete steps | Stepped motion    |

---

## Improvements

To improve resolution and smoothness:

- Increase DAC resolution (4-bit, 8-bit, etc.)
- Use precision resistors
- Use a dedicated DAC IC
- Add buffering (op-amp) to reduce loading

---

## Files

- main.tex — LaTeX lab report
- dac_simulation_001.png — simulation result for input 001
- dac_simulation_100.png — simulation result for input 100

---

## Author

Yahya Mouamil  
ENME 351 — Spring 2026
