#include <Stepper.h>
#include <LiquidCrystal.h> 

// Defines the lcd backlight
#define backLight 11
// Defined stepper motor 28PYJ-48 pins connected to the ULN2003 driver
#define IN1 = 9
#define IN2 = 10
#define IN3 = 11
#define IN4 = 12

// Defines the number of steps per revolution
const int STEPS_PER_REV = 2048;
// Defines the lcd contrast
const int CONTRAST = 100;
const int TEMPERATURE = 0;

// Defines a new lcd screen
LiquidCrystal lcd(1, 2, 7, 6, 5, 4);
// Defines a new stepper object
Stepper stepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

void setup() {
  analogWrite(backLight, CONTRAST);
  // Set the ULN2003 driver pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  lightDisplay();
  motorTurn();
}

// Function to print out the current temperature of the water in the fish tank
void lightDisplay() {
  // Writes in the first line of the lcd
  lcd.begin(16, 2); 
  lcd.print("Temperature:"); 
  // Writes in the second line of the lcd
  lcd.setCursor(0,1); 
  lcd.print(TEMPERATURE + String(" °C")); 
}

// Function to turn the motor to feed the fish
void motorTurn() {
  stepper.setSpeed(10);
  stepper.step(STEPS_PER_REV / 4);
  delay(3000);

  stepper.step(0);
  delay(7000);
}