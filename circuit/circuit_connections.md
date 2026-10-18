# Circuit Connections — Smart Parking System (AT89C51)

## Pin map

| Function | AT89C51 pin/port | Connection / notes |
|---|---|---|
| Entry sensor output | P1.0 | Active LOW; HIGH when idle |
| Exit sensor output | P1.1 | Active LOW; HIGH when idle |
| LCD RS | P2.0 | HD44780 LCD RS |
| LCD Enable | P2.1 | HD44780 LCD E |
| Full indicator LED | P2.2 | Connect through a current-limiting resistor and suitable driver as needed |
| Gate control logic | P2.3 | Logic signal to external driver; not a direct motor output |
| LCD D4 | P2.4 | 4-bit LCD data |
| LCD D5 | P2.5 | 4-bit LCD data |
| LCD D6 | P2.6 | 4-bit LCD data |
| LCD D7 | P2.7 | 4-bit LCD data |
| LCD R/W | GND | Write-only mode |
| LCD VSS / VDD | GND / regulated supply | Use the LCD module's rated supply |
| LCD VO | Contrast potentiometer wiper | Potentiometer ends to supply and GND as appropriate |
| AT89C51 reset/clock | RESET / XTAL1 / XTAL2 | Use a standard 8051 reset circuit and crystal/oscillator circuit |

## Input sensor wiring
The firmware expects each sensor input to idle HIGH and go LOW when a vehicle is detected. Use a suitable sensor module or switch interface with a defined logic level. Do not leave input pins floating. Confirm the sensor module output voltage is compatible with the 8051 supply.

## LED wiring
Use a current-limiting resistor. Check the desired active polarity and current limits for the exact AT89C51 device and circuit. A transistor driver is recommended if the indicator current exceeds the pin's safe limits.

## Gate actuator interface
P2.3 becomes HIGH for approximately two seconds after a valid entry or exit event. This is a control signal, not sufficient drive for an actuator. Use a transistor/MOSFET/relay driver, flyback protection for inductive loads, and a separate correctly rated supply. A hobby servo needs a suitable servo pulse train (typically around 1–2 ms pulse width repeated about every 20 ms); this source does **not** generate a calibrated servo waveform. Do not connect a servo signal/power directly based on this pin alone.

## Power and grounding
- Use a regulated supply appropriate for the exact MCU and LCD modules.
- Share ground between the MCU, sensors, LCD, and driver logic.
- Keep actuator power separate as appropriate and connect grounds according to the driver design.
- Verify all pin numbers against the specific AT89C51 package datasheet before wiring.
