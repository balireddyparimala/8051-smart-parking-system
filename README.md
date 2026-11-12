# Smart Parking System – Embedded Parking Management Simulation

## 1. Project Overview

The Smart Parking System is an embedded-system project designed to monitor vehicle entry and exit and manage parking-space availability.

The original project concept is based on the AT89C51 (8051) microcontroller. For interactive online simulation, the parking-management functionality is implemented separately using an Arduino Uno in the Wokwi simulator.

The system supports four parking spaces, displays parking availability on a 16×2 LCD, indicates parking-full status using an LED, and demonstrates automatic gate operation using a servo motor.

**Important:** The Arduino/Wokwi implementation is a functional adaptation of the original 8051 concept. It does not execute the original AT89C51 firmware or HEX file.

## 2. Objectives

- Detect vehicle entry and exit.
- Maintain parking occupancy for four spaces.
- Display occupied and available spaces.
- Prevent entry when parking is full.
- Prevent the occupancy count from becoming negative.
- Indicate parking-full status using an LED.
- Demonstrate automatic gate operation.

## 3. Technologies Used

### Simulation Environment
- Wokwi Online Simulator
- Arduino Uno R3
## Live Wokwi Simulation

**Project:** Smart Parking System  
**Microcontroller:** Arduino Uno  
**Simulation Platform:** Wokwi  
**Programming Language:** Arduino C++  
**Parking Capacity:** 4 Vehicles

**Run the simulation:**

https://wokwi.com/projects/480496077575254017

### Simulation Features

- Automatic vehicle entry and exit detection using HC-SR04 sensors.
- Real-time parking availability displayed on a 16×2 LCD.
- Four-slot parking occupancy management.
- Parking-full indication using a red LED.
- Entry denial when all parking spaces are occupied.
- Automatic gate operation using a servo motor.

### Simulation Status

The Arduino-based Wokwi simulation has been implemented and functionally tested.

The original AT89C51 source code and HEX file are preserved separately as reference artifacts. The Wokwi simulation does not execute the original 8051 firmware.
### Programming
- Arduino C++

### Components
- Arduino Uno
- LCD 16×2
- Two HC-SR04 ultrasonic sensors
- Red LED
- 220 Ω resistor
- Servo motor
- Breadboard
- Jumper wires

### Original 8051 Reference
- AT89C51 microcontroller
- Embedded C source code
- Keil C51-generated HEX file

The original 8051 source and HEX files are retained as reference artifacts and are not used by the Wokwi simulation.

## 4. System Architecture

The system consists of:

1. Entry vehicle detection.
2. Exit vehicle detection.
3. Parking occupancy management.
4. LCD display.
5. Parking-full LED indication.
6. Servo-based gate demonstration.

The total parking capacity is four vehicles.

## 5. Working Principle

1. Initially, all four parking spaces are available.
2. When the entry sensor detects a vehicle, the occupied-space count increases.
3. The LCD displays the updated parking availability.
4. The servo motor opens the gate after a valid entry.
5. When the exit sensor detects a vehicle, the occupied-space count decreases.
6. When all four spaces are occupied, the red LED turns ON.
7. Additional entry attempts are rejected.
8. When a vehicle exits, the available-space count increases.

## 6. Software Requirements

- Wokwi Online Simulator
- Arduino C++ programming environment
- LiquidCrystal library
- Servo library

No Keil C51 compiler or Proteus software is required for the Arduino/Wokwi simulation.

## 7. Pin Configuration

| Component | Arduino Pin |
|---|---|
| Entry sensor TRIG | D2 |
| Entry sensor ECHO | D3 |
| Exit sensor TRIG | D4 |
| Exit sensor ECHO | D5 |
| LCD D4 | D6 |
| LCD D5 | D7 |
| LCD D6 | D8 |
| LCD D7 | D9 |
| Full indicator LED | D10 |
| LCD Enable | D11 |
| LCD RS | D12 |
| Servo signal | D13 |

LCD RW is connected to GND.

## 8. Expected Test Cases

| Test | Expected Result |
|---|---|
| Initial condition | 4 free spaces |
| First vehicle entry | 3 free spaces |
| Second vehicle entry | 2 free spaces |
| Third vehicle entry | 1 free space |
| Fourth vehicle entry | Parking full |
| Fifth vehicle entry | Entry denied |
| Vehicle exit | Available spaces increase |
| Exit when empty | Occupancy remains zero |

Actual test results and screenshots will be added after simulation.

## 9. Repository Structure

```text
8051-smart-parking-system/
│
├── README.md
│
├── source_code/
│   └── smart_parking.c
│
├── hex/
│   └── SmartParking.hex
│
├── wokwi_simulation/
│   ├── sketch.ino
│   ├── diagram.json
│   └── libraries.txt
│
├── circuit/
│   └── circuit_connections.md
│
├── documentation/
│   └── project_report.md
│
└── screenshots/
    ├── circuit.png
    ├── initial_condition.png
    ├── parking_full.png
    └── vehicle_exit.png
```

## 10. Development Status

- [x] Original AT89C51 Embedded C source developed
- [x] Original HEX file generated
- [x] Original source code uploaded to GitHub
- [ ] Wokwi Arduino simulation created
- [ ] LCD operation verified
- [ ] Entry sensor tested
- [ ] Exit sensor tested
- [ ] Four-slot parking logic verified
- [ ] Parking-full LED tested
- [ ] Servo gate operation tested
- [ ] Simulation screenshots uploaded
- [ ] Final project report updated

## 11. Limitations

- The Wokwi implementation uses Arduino Uno instead of AT89C51.
- The simulation demonstrates the parking-management functionality rather than the original 8051 hardware.
- Ultrasonic sensor detection depends on simulated distance.
- The servo motor demonstrates gate movement and is not a complete real-world gate mechanism.

## 12. Future Enhancements

- RFID-based vehicle authentication.
- IoT-based parking monitoring.
- Real-time parking availability.
- Vehicle identification.
- Mobile application integration.

## 13. Author

**Parimala Balireddy**

Project: Smart Parking System.
