# Project Report: Smart Parking System Using AT89C51

## 1. Abstract
The Smart Parking System is a microcontroller-based demonstration that monitors parking occupancy and reports the number of occupied and available spaces. An AT89C51 (8051) reads entry and exit sensor inputs, updates a four-slot counter, displays the result on a 16x2 LCD, and turns on an LED when all slots are occupied. A digital control output is provided for interfacing with an external gate-driver circuit.

## 2. Problem Statement
Manual parking-space monitoring can cause unnecessary searching and poor utilization of limited parking capacity. A small automated counter can provide immediate occupancy information and demonstrate embedded-system principles.

## 3. Objectives
- Count valid vehicle-entry and vehicle-exit events.
- Prevent the count from exceeding the configured capacity or falling below zero.
- Display free and occupied spaces on an LCD.
- Indicate a full parking area using an LED.
- Provide a control output for a separately driven gate interface.

## 4. Hardware Requirements
- AT89C51/8051 microcontroller and clock/reset circuitry
- Two active-low sensor interfaces (entry and exit)
- HD44780-compatible 16x2 LCD
- LED and current-limiting resistor
- External gate driver/actuator interface, if required
- Regulated power supply, wiring, and common ground

## 5. Software Requirements
- Keil µVision with Keil C51 compiler
- Embedded C source file
- 8051 simulator or compatible hardware test setup

## 6. Working Principle
At startup, occupancy is initialized to zero and available spaces to four. The firmware initializes the LCD and displays the initial status. When the entry sensor goes LOW, a debounced event increments occupancy only if the car park is not full. When the exit sensor goes LOW, occupancy decrements only if it is greater than zero. Available spaces are calculated as capacity minus occupancy. The full LED is ON when occupancy reaches the configured capacity. The gate-control output is activated for a delay after a valid entry or exit event.

## 7. Pin Configuration
- P1.0: entry sensor (active LOW)
- P1.1: exit sensor (active LOW)
- P2.0: LCD RS
- P2.1: LCD Enable
- P2.2: full indicator LED
- P2.3: gate-driver logic output
- P2.4–P2.7: LCD data D4–D7
- LCD R/W: GND

See `circuit/circuit_connections.md` for wiring and safety notes.

## 8. Test Plan and Expected Results
| Test | Action | Expected result |
|---|---|---|
| Initial state | Both sensors HIGH after reset | Occupied = 0, free = 4, LED OFF |
| Entry | Pulse entry sensor LOW | Occupied increments by 1; free decrements by 1 |
| Full capacity | Record four valid entries | Occupied = 4, free = 0, LED ON |
| Entry when full | Pulse entry sensor LOW again | Count stays at 4; entry denied message shown |
| Exit | Pulse exit sensor LOW with occupancy > 0 | Occupied decrements; free increments |
| Exit when empty | Pulse exit sensor LOW at occupancy 0 | Count remains 0 |

## 9. Limitations
- The entry and exit sensors must be positioned and calibrated so each vehicle produces one valid event.
- The current firmware uses blocking software delays; sensor polling pauses during the gate delay.
- The gate pin is a logic-level interface only; real actuators require a suitable driver and power arrangement.
- Software delays and LCD timing depend on the actual clock and compiler settings.
- This report describes expected behavior; measured hardware results should be added only after actual tests.

## 10. Conclusion
The project demonstrates basic embedded C programming, GPIO interfacing, LCD operation, state counting, and threshold-based indication using an 8051 microcontroller. Further development can include timer-based gate control, vehicle-presence interlocks, RFID access, and a more robust sensor-validation method.
