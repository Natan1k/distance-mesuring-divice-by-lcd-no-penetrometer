#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
  
 void setup()
 {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
  } 
     void loop()
 { 
     // Clears the trigPin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance= duration*0.034/2;
      lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
      lcd.print("Distance: "); // Prints string "Distance" on the LCD
      lcd.print(distance); // Prints the distance value from the sensor
      lcd.print(" cm");

 
 }
