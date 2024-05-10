// Define the pins for the LEDs
const int greenPin = 2;
const int yellowPin = 3;
const int redPin = 4;

void setup() {
  // Set the LED pins as outputs
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  
  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if there is any data available to read from Serial
  if (Serial.available() > 0) {
    // Read the incoming byte
    char incomingByte = Serial.read();
    
    // Check the value of the incoming byte and control the LEDs accordingly
    if (incomingByte == 'B' || incomingByte == 'b') {
      blinkGreen(); // Blink green LED
    } else if (incomingByte == 'G' || incomingByte == 'g') {
      digitalWrite(greenPin, HIGH); // Turn on green LED
      digitalWrite(yellowPin, LOW); // Turn off yellow LED
      digitalWrite(redPin, LOW); // Turn off red LED
    } else if (incomingByte == 'Y' || incomingByte == 'y') {
      digitalWrite(greenPin, LOW); // Turn off green LED
      digitalWrite(yellowPin, HIGH); // Turn on yellow LED
      digitalWrite(redPin, LOW); // Turn off red LED
    } else if (incomingByte == 'R' || incomingByte == 'r') {
      digitalWrite(greenPin, LOW); // Turn off green LED
      digitalWrite(yellowPin, LOW); // Turn off yellow LED
      digitalWrite(redPin, HIGH); // Turn on red LED
    }
  }
}

// Function to blink the green LED
void blinkGreen() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(greenPin, HIGH); // Turn on green LED
    delay(500); // Wait for 500 milliseconds
    digitalWrite(greenPin, LOW); // Turn off green LED
    delay(500); // Wait for 500 milliseconds
  }
}
