# ESP32 Bluetooth Speaker

A Bluetooth speaker built from scratch around an ESP32 microcontroller, with an
RGB LED matrix display that reacts to connection state. Built as a 3-person
Grade 12 engineering capstone.

## Team & roles
- **Misha** — Bluetooth audio (A2DP sink + I2S output)
- **Ricky** — 32x16 RGB LED matrix control & animations
- **Luke** — amplifier, speaker output & wiring

## What it does
- Pairs over Bluetooth and receives audio streamed from a phone (A2DP)
- Outputs audio through the ESP32's built-in DAC via I2S
- Drives an RGB LED matrix that shows a "disconnected" scroll or a
  reactive animation when connected

## Hardware
- ESP32 dev board
- 32x16 RGB LED panel
- 9V power supply, breadboard, resistors (1k / 560 ohm), NPN transistor

## Tech & concepts
- Embedded **C++** (Arduino framework, built with PlatformIO)
- **A2DP** Bluetooth audio sink (pschatzmann/ESP32-A2DP library)
- **I2S** audio output to the built-in DAC
- **FreeRTOS** task scheduling (LED animation runs on a separate core)

## Build
Built with [PlatformIO](https://platformio.org/). Open the project, connect an
ESP32, and upload. See `platformio.ini` for board config.
