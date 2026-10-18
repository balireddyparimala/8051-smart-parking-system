# Circuit Connections

## Project
Smart Parking System Using AT89C51 Microcontroller

**Author:** Parimala

## 1. Microcontroller

- Microcontroller: AT89C51
- Compiler: Keil C51
- Supply voltage: +5 V

## 2. Vehicle Sensors

| Component | AT89C51 Pin | Function |
|---|---|---|
| Entry sensor | P1.0 | Detects vehicle entry |
| Exit sensor | P1.1 | Detects vehicle exit |

The inputs are active LOW in the current program.

Push buttons can be used to represent the sensors during testing.

## 3. LCD Connections

The project uses a standard 16x2 LCD in 8-bit mode.

| LCD Pin | AT89C51 Connection |
|---|---|
| RS | P3.0 |
| RW | Ground |
| Enable | P3.1 |
| D0-D7 | P0.0-P0.7 |
| VSS | Ground |
| VDD | +5 V |
| V0 | Contrast adjustment |

Port 0 requires appropriate external pull-up resistors.

## 4. Indicator LEDs

| LED | AT89C51 Pin | Function |
|---|---|---|
| Entry gate | P2.0 | Indicates entry gate operation |
| Exit gate | P2.1 | Indicates exit gate operation |
| Parking full | P2.2 | Indicates all spaces are occupied |
| Parking available | P2.3 | Indicates available parking spaces |

Use suitable current-limiting resistors for LEDs.

## 5. Clock and Reset

The AT89C51 requires appropriate clock and reset circuitry.

The crystal oscillator, capacitors, reset network, and power connections must follow the microcontroller datasheet.

## 6. Parking Capacity

The current program is configured for four parking spaces.

- Initial available spaces: 4
- Maximum occupied spaces: 4
- Entry is restricted when all spaces are occupied.
- Exit decreases the occupied-space count.

## 7. Simulation Status

The source code has compiled successfully in Keil C51.

Full circuit simulation and LCD operation remain to be verified in a compatible circuit simulator.
