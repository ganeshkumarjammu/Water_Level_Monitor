// Define the pins for the ultrasonic sensor, water pump, and LEDs
const int trigPin = 9;
const int echoPin = 10;
const int pumpPin = 6;
const int redLedPin = 2;
const int greenLedPin = 4;
const int yellowLedPin = 3;

// Define the water level thresholds in centimeters
const int highLevel = 30;
const int mediumLevel = 20;
const int lowLevel = 10;

void setup() {
  // Initialize the serial communication for debugging
  Serial.begin(9600);

  // Set the pins as outputs or inputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
}

void loop() {
  // Send a pulse to the ultrasonic sensor to trigger a reading
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the echo pulse and convert it to distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // Determine the water level and turn on the appropriate LED
  if (distance >= highLevel) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(pumpPin, HIGH);
  } else if (distance >= mediumLevel) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(pumpPin, LOW);
  } else if (distance >= lowLevel) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(pumpPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(pumpPin, LOW);
  }

  // Wait for a short amount of time before repeating the loop
  delay(100);
}
