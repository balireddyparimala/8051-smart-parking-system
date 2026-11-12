/*
  Project: Smart Parking System
  Author: Parimala
  Platform: Arduino Uno
  Simulation: Wokwi
  Parking Capacity: 4
*/

#include <LiquidCrystal.h>
#include <Servo.h>

// LCD configuration
LiquidCrystal lcd(12, 11, 6, 7, 8, 9);

// Entry sensor
#define ENTRY_TRIG 2
#define ENTRY_ECHO 3

// Exit sensor
#define EXIT_TRIG 4
#define EXIT_ECHO 5

// Output devices
#define FULL_LED 10
#define GATE_SERVO 13

// Parking capacity
#define TOTAL_SLOTS 4

int occupiedSlots = 0;

Servo gate;

bool entryDetected = false;
bool exitDetected = false;

bool gateOpen = false;

unsigned long gateStartTime = 0;

// Measure ultrasonic distance
float getDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
    return 999;

  return duration * 0.0343 / 2;
}

// Open gate
void openGate()
{
  gate.write(90);

  gateStartTime = millis();
  gateOpen = true;
}

// Update LCD and LED
void updateParkingStatus()
{
  lcd.clear();

  lcd.setCursor(0, 0);

  if (occupiedSlots == TOTAL_SLOTS)
  {
    lcd.print("PARKING FULL!");
  }
  else
  {
    lcd.print("SMART PARKING");
  }

  lcd.setCursor(0, 1);

  lcd.print("FREE:");
  lcd.print(TOTAL_SLOTS - occupiedSlots);

  lcd.print(" OCC:");
  lcd.print(occupiedSlots);

  digitalWrite(FULL_LED,
    occupiedSlots == TOTAL_SLOTS ? HIGH : LOW);
}

// Initialize system
void setup()
{
  pinMode(ENTRY_TRIG, OUTPUT);
  pinMode(ENTRY_ECHO, INPUT);

  pinMode(EXIT_TRIG, OUTPUT);
  pinMode(EXIT_ECHO, INPUT);

  pinMode(FULL_LED, OUTPUT);

  gate.attach(GATE_SERVO);
  gate.write(0);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("SMART PARKING");

  lcd.setCursor(0, 1);
  lcd.print("INITIALIZING");

  delay(2000);

  updateParkingStatus();
}

// Main program
void loop()
{
  float entryDistance =
    getDistance(ENTRY_TRIG, ENTRY_ECHO);

  float exitDistance =
    getDistance(EXIT_TRIG, EXIT_ECHO);

  // VEHICLE ENTRY
  if (entryDistance < 10 && !entryDetected)
  {
    entryDetected = true;

    if (occupiedSlots < TOTAL_SLOTS)
    {
      occupiedSlots++;

      updateParkingStatus();

      openGate();
    }
    else
    {
      lcd.clear();
      lcd.print("ENTRY DENIED");

      lcd.setCursor(0, 1);
      lcd.print("PARKING FULL");
    }
  }

  // Reset entry detection
  if (entryDistance > 15)
  {
    entryDetected = false;
  }

  // VEHICLE EXIT
  if (exitDistance < 10 && !exitDetected)
  {
    exitDetected = true;

    if (occupiedSlots > 0)
    {
      occupiedSlots--;

      updateParkingStatus();

      openGate();
    }
  }

  // Reset exit detection
  if (exitDistance > 15)
  {
    exitDetected = false;
  }

  // Close gate after two seconds
  if (gateOpen &&
      millis() - gateStartTime >= 2000)
  {
    gate.write(0);
    gateOpen = false;
  }

  delay(100);
}
