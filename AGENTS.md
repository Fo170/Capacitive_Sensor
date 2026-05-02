# AGENTS.md

## Project

Simple Arduino capacitive soil moisture sensor library.

## Key Files

- `Capacitive_Sensor.h` - Main library with humidity calculation function
- `capteur capacitif.txt` - Notes and calibration data
- `capteur capacitif.png` / `capteur capacitif - schéma.png` - Documentation images

## Usage

This is an Arduino library. Include `Capacitive_Sensor.h` in your Arduino sketch and call `Calcule_HumiditeSol_CapteurCapacitif(voltage)` to get humidity percentage (0-100%).

## Calibration

- Dry soil (out of ground): ~1.696V → 0%
- Wet soil: ~1.087V → 100%

## Notes

- No build system or tests - compiles directly in Arduino IDE
- Works with capacitive soil moisture sensors (not resistive)