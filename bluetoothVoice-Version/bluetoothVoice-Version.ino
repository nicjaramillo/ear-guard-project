
Servo myServo;  
String command = "";  // Store incoming command

void setup() {
  Serial.begin(9600);  // For Bluetooth communication
  myServo.attach(3);   // Servo connected to pin 3
  myServo.write(90);   // Neutral position
  Serial.println("Waiting for Bluetooth comands...");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();  // Read incoming character
    if (c == '\n') {         // Command ends with newline
      command.trim();        // Remove extra spaces/newline
      if (command == "OPEN") {
        myServo.write(0);    // Move to 0 degrees
        Serial.println("Servo Opened");
      } else if (command == "CLOSE") {
        myServo.write(90);   // Move to 90 degrees
        Serial.println("Servo Closed");
      }
      command = "";  // Reset the command string
    } else {
      command += c;  // Build command string
    }
  }
}
