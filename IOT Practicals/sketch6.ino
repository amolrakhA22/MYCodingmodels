// Define pin numbers for the LEDs
const int greenPin = 9;
const int yellowPin = 10;
const int redPin = 11;

// Define the counter variable
int counter = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set LED pins as outputs
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // Display the value of the counter variable
  Serial.print("Counter: ");
  Serial.println(counter);

  // Control the LEDs based on the value of the counter
  if (counter < 100) {
    illuminateGreen();
  } else if (counter >= 100 && counter <= 200) {
    illuminateYellow();
  } else {
    illuminateRed();
  }

  // Increment the counter variable
  counter++;

  // Reset the counter if it exceeds 300
  if (counter > 300) {
    counter = 0;
  }

  // Delay for a short time
  delay(100);
}

// Function to illuminate the green LED
void illuminateGreen() {
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
}

// Function to illuminate the yellow LED
void illuminateYellow() {
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, LOW);
}

// Function to illuminate the red LED
void illuminateRed() {
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
}
