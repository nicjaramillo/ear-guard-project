// Define pins
const int noiseSensorPin = A0;  // Analog pin for noise sensor
const int servoPin = 9;         // Digital pin for servo motor

Servo myServo;

// Threshold for detecting noise
const int noiseThreshold = 500;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(0);  // Initial position
}

void loop() {
  int noiseLevel = analogRead(noiseSensorPin);
  Serial.println(noiseLevel);

  if (noiseLevel > noiseThreshold) {
    myServo.write(90);  // Move mechanism to close position
    delay(10000);        // Keep it closed for 10 second
    myServo.write(0);   // Return to original position
  }

  delay(100);
}
