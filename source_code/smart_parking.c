/*
 * Project: Smart Parking System Using AT89C51 (8051)
 * Toolchain: Keil C51 / uVision
 * Features:
 *   - Active-low entry and exit sensors
 *   - Four-slot occupancy counter
 *   - 16x2 LCD in 4-bit mode
 *   - Parking-full LED
 *   - Digital gate-driver control output
 *
 * IMPORTANT HARDWARE NOTES:
 *   - LCD R/W must be connected to GND.
 *   - P0 is not used, avoiding its external pull-up requirement.
 *   - GATE_CTRL is a logic-level control signal only. Do not connect a
 *     motor/servo/relay coil directly to an AT89C51 pin. Use a suitable
 *     driver circuit and a separate, correctly rated supply.
 *   - Timing delays are approximate and depend on oscillator frequency.
 */

#include <reg51.h>

#define TOTAL_SLOTS 4

/* Sensors: active LOW */
sbit ENTRY_SENSOR = P1^0;
sbit EXIT_SENSOR  = P1^1;

/* P2 low-nibble outputs */
sbit LCD_RS   = P2^0;
sbit LCD_EN   = P2^1;
sbit FULL_LED = P2^2;
sbit GATE_CTRL = P2^3;

/* LCD data bus: D4-D7 connected to P2.4-P2.7 */
unsigned char occupied_slots = 0;
unsigned char available_slots = TOTAL_SLOTS;

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    /* Approximate delay for a typical 11.0592/12 MHz 8051 clock.
       Calibrate for the actual crystal and compiler settings. */
    for (i = 0; i < ms; i++)
        for (j = 0; j < 123; j++);
}

void lcd_pulse_enable(void)
{
    LCD_EN = 1;
    delay_ms(1);
    LCD_EN = 0;
    delay_ms(1);
}

void lcd_write_nibble(unsigned char value)
{
    /* Preserve P2.0-P2.3 control outputs and write P2.4-P2.7. */
    P2 = (P2 & 0x0F) | (value & 0xF0);
    lcd_pulse_enable();
}

void lcd_write_byte(unsigned char value, bit is_data)
{
    LCD_RS = is_data;
    lcd_write_nibble(value & 0xF0);
    lcd_write_nibble((value << 4) & 0xF0);
    delay_ms(2);
}

void lcd_command(unsigned char command)
{
    lcd_write_byte(command, 0);
}

void lcd_data(unsigned char value)
{
    lcd_write_byte(value, 1);
}

void lcd_init(void)
{
    LCD_RS = 0;
    LCD_EN = 0;
    delay_ms(20);

    /* Standard HD44780 4-bit initialization sequence */
    lcd_write_nibble(0x30);
    delay_ms(5);
    lcd_write_nibble(0x30);
    delay_ms(2);
    lcd_write_nibble(0x30);
    delay_ms(2);
    lcd_write_nibble(0x20);
    delay_ms(2);

    lcd_command(0x28); /* 4-bit, 2-line, 5x8 font */
    lcd_command(0x0C); /* Display ON, cursor OFF */
    lcd_command(0x06); /* Increment cursor */
    lcd_command(0x01); /* Clear display */
    delay_ms(3);
}

void lcd_print(char *text)
{
    while (*text)
        lcd_data(*text++);
}

void lcd_show_number(unsigned char number)
{
    lcd_data((number / 10) + '0');
    lcd_data((number % 10) + '0');
}

void update_parking_status(void)
{
    available_slots = TOTAL_SLOTS - occupied_slots;
    FULL_LED = (occupied_slots >= TOTAL_SLOTS) ? 1 : 0;

    lcd_command(0x80);
    lcd_print("Smart Parking   ");
    lcd_command(0xC0);
    lcd_print("Free: ");
    lcd_show_number(available_slots);
    lcd_print(" Occ: ");
    lcd_show_number(occupied_slots);
    lcd_print(" ");
}

void gate_open_delay(void)
{
    /* Digital output to an external gate-driver interface.
       Gate is held active for approximately 2 seconds. */
    GATE_CTRL = 1;
    delay_ms(2000);
    GATE_CTRL = 0;
}

void main(void)
{
    ENTRY_SENSOR = 1; /* Configure sensor inputs high */
    EXIT_SENSOR = 1;
    FULL_LED = 0;
    GATE_CTRL = 0;

    lcd_init();
    update_parking_status();

    while (1)
    {
        /* Vehicle entering */
        if (ENTRY_SENSOR == 0)
        {
            delay_ms(30); /* debounce */
            if (ENTRY_SENSOR == 0)
            {
                if (occupied_slots < TOTAL_SLOTS)
                {
                    occupied_slots++;
                    update_parking_status();
                    gate_open_delay();
                }
                else
                {
                    FULL_LED = 1;
                    lcd_command(0x80);
                    lcd_print("PARKING FULL    ");
                    lcd_command(0xC0);
                    lcd_print("Entry denied    ");
                    delay_ms(1000);
                    update_parking_status();
                }

                while (ENTRY_SENSOR == 0);
                delay_ms(50);
            }
        }

        /* Vehicle exiting */
        if (EXIT_SENSOR == 0)
        {
            delay_ms(30); /* debounce */
            if (EXIT_SENSOR == 0)
            {
                if (occupied_slots > 0)
                {
                    occupied_slots--;
                    update_parking_status();
                    gate_open_delay();
                }
                else
                {
                    lcd_command(0x80);
                    lcd_print("Parking Empty   ");
                    lcd_command(0xC0);
                    lcd_print("No car to exit  ");
                    delay_ms(1000);
                    update_parking_status();
                }

                while (EXIT_SENSOR == 0);
                delay_ms(50);
            }
        }
    }
}
