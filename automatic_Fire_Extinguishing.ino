const int fireSensorPin = 12; // Analog pin for fire sensor
const int relayPin = 26; // Pin connected to relay
const int fireThreshold = 500; // Threshold value for fire detection
const int relayOffDelay = 10000; // Delay after turning off relay (in milliseconds)

void setup() {
  pinMode(fireSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Initially turn off relay
  Serial.begin(9600);
}

void loop() {
  // Read the value from the fire sensor   
  int fireValue = analogRead(fireSensorPin);
  
  // If the fire sensor detects fire (adjust threshold value as needed)
  if (fireValue > fireThreshold) {
    digitalWrite(relayPin, HIGH); // Turn on relay
    Serial.println("Fire detected! Relay turned on.");
    delay(relayOffDelay); // Wait for specified delay
    digitalWrite(relayPin, LOW); // Turn off relay after delay
    Serial.println("Relay turned off after 10 seconds.");
  } else if (fireValue < fireThreshold){
    digitalWrite(relayPin, LOW); // Turn off relay
  }

  delay(100); // Delay to avoid rapid readings
}