void setup() {
  Serial.begin(9600); // Initialize serial communication
  while (!Serial);    // Wait until Serial is ready
  Serial.println("Enter a number:"); // Prompt the user to enter a number
}

void loop() {
  if (Serial.available()) { // Check if data is available to read
    int num = Serial.parseInt(); // Read the number entered by the user
    int squared = num * num;     // Calculate the squared value

    // Output the squared value
    Serial.print("Squared value of ");
    Serial.print(num);
    Serial.print(" is ");
    Serial.println(squared);

    // Prompt the user to enter another number
    Serial.println("Enter another number:");
  }
}
