/*
 * Whack-A-MoLED is a game where there are two LEDs and two corresponding switches. One of the LEDs will light up at random, 
 * and the user has 3 seconds to hit the correct switch to win the round. If they hit the correct switch, the indicator LED 
 * will turn green. If the time runs out, then the indicator LED in the middle will turn red. The next round will begin 
 * immediately after.
 * 
 * References used:
 * https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
 * https://www.hackster.io/courtlandjensen/led-light-whack-a-mole-20c319
 * https://forum.arduino.cc/index.php?topic=565344.0
 * http://www.uwyo.edu/esp4t/arduino-modules/game-modules/whack-a-mole.html
 *
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Set the pin numbers for the LEDs and Switches
int led1 = A0;
int led2 = A3;
int switch1 = A1;
int switch2 = A4;

// Set the pin numbers for the RGB LED.
int red_pin = 9;
int green_pin = 8;
int blue_pin = 7;

// Set the time duration for the countdown clock
long milliseconds = 3000;

void setup() {
  // put your setup code here, to run once:

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the top line of the LCD.
  lcd.print("Countdown :");

  // Set the switches as inputs
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);

  // Set the LEDs as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);

  // Set the initial color of the RGB LED to white
  RGB_color(255, 255, 255);

}

void loop() {
  // put your main code here, to run repeatedly:

  int mole = random(2); // Choose one of the two LEDs to light up

  // If the first LED, then run the below loop
  if (mole == 0) {
    digitalWrite(led1, HIGH); // Turn on LED 1
    
    int start_time = millis();

    // While the time is less than 3000 milliseconds, go through the while loop
    while (millis() - start_time < milliseconds) {
      lcd.setCursor(0, 1);
      lcd.print(3 - (millis()-start_time)/1000);

      if (digitalRead(switch1) == LOW) { // If you hit the right switch
        digitalWrite(led1, LOW); // Turn off LED 1
        RGB_color(255, 0, 255); // Light the indicator LED Green (Success)
        delay(1000);
        RGB_color(255, 255, 255); // Turn off the indicator LED
        return;
      }
    }

    // If the correct switch is not hit within 3000 milliseconds
    digitalWrite(led1, LOW); // Turn off LED 1
    RGB_color(255, 255, 125); // Light the indicator LED Red (Failure)
    delay(1000); 
    RGB_color(255, 255, 255); // Turn off the indicator LED
    delay(1000);
  }


// If the second LED is selected, then run the below loop
  else {
    digitalWrite(led2, HIGH);
    
    int start_time = millis();
    
    while (millis() - start_time < milliseconds) {
     lcd.setCursor(0, 1);
     lcd.print(3 - (millis()-start_time)/1000);

     if (digitalRead(switch2) == LOW) {
        digitalWrite(led2, LOW);
        RGB_color(255, 0, 255); // Green
        delay(1000);
        RGB_color(255, 255, 255); // Green
        Serial.println("Correct!");
        return;
      }
    }

    digitalWrite(led2, LOW);
    RGB_color(255, 255, 125);
    delay(1000); 
    RGB_color(255, 255, 255);
    delay(1000); 
  }  
  
  delay(1000);
}


// Function to write the analog inputs to the RGB LED.
void RGB_color(int red, int green, int blue)
 {
  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);
 }
