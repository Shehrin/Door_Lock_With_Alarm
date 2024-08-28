#include <Keypad.h>
#include <Servo.h>

// Define the keypad layout
const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo doorServo;
const int servoPin = 10;
const int buzzerPin = 11;
//const char correctCode = 'A'; 
//char inputCode = ""; 

void setup() {
  doorServo.attach(servoPin);
  pinMode(buzzerPin, OUTPUT);
  doorServo.write(0); // Start with the door locked (servo at 0 degrees)
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '#') {
  
        doorServo.write(180); // Unlock the door (servo at 90 degrees)
        delay(1000); // Keep the door unlocked for 3 seconds
        doorServo.write(0); // Lock the door again
      }
      else {
        tone(buzzerPin, 1000); // Sound buzzer at 1kHz
        delay(1000); // Wait for 1 second
       noTone(buzzerPin); // Stop the buzzer
      }
    }

}











/*


  if (key) {
    if (key == 'A') { // Check if the user presses the # key
     //char key1 = keypad.getKey();
      //inputCode = key1;
      //if (key1 == correctCode) {
        doorServo.write(90); // Unlock the door (servo at 90 degrees)
        delay(3000); // Keep the door unlocked for 3 seconds
        doorServo.write(0); // Lock the door again
      }
      // else
       {
       // tone(buzzerPin, 1000); // Sound buzzer at 1kHz
       // delay(1000); // Wait for 1 second
       // noTone(buzzerPin); // Stop the buzzer
      }
    }
      //inputCode = ""; // Reset the input code
     else {
     // inputCode += key; // Append the pressed key to the input code
    }
  
}
}*/