// HC-SR04 Pins
#define TRIG_PIN 9
#define ECHO_PIN 10

// LED Pins
#define GREEN_LED 2
#define BLUE_LED 3
#define RED_LED 4

void setup() {
  Serial.begin(9600);
  
  // Setup sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Setup LED pins
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  // Triggering the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Receiving the echo
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn off all LEDs first
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // Water Level Indication Logic
  if (distance < 20) {
    digitalWrite(GREEN_LED, HIGH);  // High water level
  } else if (distance >= 20 && distance < 30) {
    digitalWrite(BLUE_LED, HIGH);   // Medium water level
  } else {
    digitalWrite(RED_LED, HIGH);    // Low water level
  }

  delay(1000);  // Wait 1 second before next reading
}
