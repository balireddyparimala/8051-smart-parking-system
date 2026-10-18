# Smart Parking System Using 8051 Microcontroller

**Author:** Parimala  
**Microcontroller:** AT89C51  
**Programming Language:** Embedded C  
**Development Environment:** Keil µVision5  
**Compiler:** Keil C51  

## 1. Abstract

The Smart Parking System is a microcontroller-based project designed
to monitor parking-space availability and control vehicle entry and exit.

The AT89C51 microcontroller maintains the number of occupied parking
spaces and displays the number of available spaces on a 16x2 LCD.

The project is being developed and documented using Embedded C and Keil
µVision5.

## 2. Objectives

- Monitor vehicle entry and exit.
- Maintain the parking occupancy count.
- Support a maximum of four parking spaces.
- Display parking availability on an LCD.
- Indicate when parking is full.
- Prevent the occupancy count from exceeding the configured capacity.

## 3. Hardware Components

- AT89C51 microcontroller
- 16x2 LCD
- Two push buttons or suitable vehicle sensors
- Four indicator LEDs
- Current-limiting resistors
- External pull-up resistors where required
- Crystal oscillator and capacitors
- Reset circuit
- Regulated 5 V supply

## 4. Software Requirements

- Keil µVision5
- Keil C51 compiler
- Compatible circuit simulator for circuit-level testing

## 5. Working Principle

The system starts with four available parking spaces.

When an entry input is activated, the controller checks whether a
parking space is available. If capacity remains, the occupancy count
increases and the entry indicator operates.

When an exit input is activated, the controller checks whether at least
one vehicle is present. If so, the occupancy count decreases and the
exit indicator operates.

The LCD displays the parking status and the number of available spaces.
When all four spaces are occupied, the parking-full indicator is activated.

## 6. Microcontroller Pin Assignments

| Signal | AT89C51 Pin |
|---|---|
| Vehicle entry input | P1.0 |
| Vehicle exit input | P1.1 |
| Entry indicator | P2.0 |
| Exit indicator | P2.1 |
| Parking-full indicator | P2.2 |
| Parking-available indicator | P2.3 |
| LCD RS | P3.0 |
| LCD Enable | P3.1 |
| LCD data bus | P0.0-P0.7 |

## 7. Development Status

- Initial Embedded C source code created.
- LCD routines incorporated.
- Keil C51 compilation completed successfully.
- HEX file generated.
- Source code uploaded to GitHub.
- Circuit connection documentation added.
- Full circuit simulation and hardware operation remain to be verified.

## 8. Future Enhancements

- Simulate the complete circuit.
- Integrate suitable vehicle-detection sensors.
- Implement a physical or simulated entry gate.
- Improve LCD messages and status updates.
- Test all entry and exit conditions.
- Add simulation screenshots and verified results.

## 9. Conclusion

This project demonstrates the development of a basic parking occupancy
monitoring system using the AT89C51 microcontroller.

The design provides a foundation for further development of an automated
parking system with vehicle detection, display, and gate-control functions.
