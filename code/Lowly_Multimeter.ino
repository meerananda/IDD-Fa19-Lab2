/*
  Lowly Multimeter
  
  Part of this is example code that is in the public domain.
  http://www.arduino.cc/en/Tutorial/AnalogInput

  References:
  https://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Voltage");
  
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  // Convert the analog value from the potentiometer to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Set the LED cursor to the second row
  lcd.setCursor(0, 1);
  // Display the voltage value
  lcd.print(voltage);
}
