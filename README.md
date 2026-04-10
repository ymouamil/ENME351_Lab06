# ENME 351 Lab 6: Digital to Analog Conversion & Servo Motors

**University:** [Your University Name]  
**Course:** ENME 351 - Electronics & Instrumentation II  
**Semester:** Spring 2026  
**Author:** [Your Name]  
**Date:** [Current Date]

---

## 📋 Overview

This lab demonstrates two methods of controlling a servo motor using an Arduino Uno:
1. **Analog Control** using a potentiometer
2. **Digital Control** using a 3-bit R-2R Digital-to-Analog Converter (DAC)

The lab also includes theoretical analysis, simulation, and physical construction of a 3-bit R-2R DAC.

---

## 🧪 Lab Objectives

- Generate manual PWM signals (no `Servo.h` library) to control an SG92R servo
- Control servo position using a potentiometer input
- Design and build a 3-bit R-2R DAC
- Simulate DAC operation using CircuitLab
- Control servo position using only DAC output (8 discrete positions)
- Compare analog vs. digital control methods

---

## 🔧 Components Used

| Component | Quantity | Specification |
|-----------|----------|---------------|
| Arduino Uno | 1 | 5V logic |
| SG92R Servo Motor | 1 | 4.8V-6V, 90° range |
| B10K Potentiometer | 1 | 10kΩ linear |
| Resistors (R) | 3 | 10kΩ (or 1kΩ) |
| Resistors (2R) | 3 | 20kΩ (or 2kΩ) |
| AA Batteries | 4 | 1.5V each (6V total) |
| Battery Holder | 1 | 4xAA |
| Breadboard | 1 | 400+ points |
| Jumper Wires | ~15 | Male-to-male |

---

## 📊 Exercise 1: Potentiometer → Servo Control

### Wiring Diagram
