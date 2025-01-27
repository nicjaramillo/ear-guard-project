#include <Servo.h>  // Include the Servo library

#define NOISE_SENSOR_PIN 2  // Digital pin for noise sensor (DO)
#define SERVO_PIN 3         // PWM pin for the servo

Servo myServo;  

void setup() {
  pinMode(NOISE_SENSOR_PIN, INPUT);
  myServo.attach(SERVO_PIN);  // Attach the servo to pin 3
  myServo.write(90);          // Initialise servo to the original position
  Serial.begin(9600);
}

void loop() {
  int noiseDetected = digitalRead(NOISE_SENSOR_PIN);

  if (noiseDetected == HIGH) {
    Serial.println("Noise detected!");
    myServo.write(0);  // Move 0 degrees
    delay(10000);        // Wait for 10 seconds
    myServo.write(90); // Return servo to original position
  } else {
    Serial.println("No noise.");
  }

  delay(100);  // Small delay to prevent excessive readings
}
