const int TRIG_PIN = 4;
const int ECHO_PIN = 5;
const int LED_PIN = 3;

int ledValue;
float duration, distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Transmit ultrasonic wave
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Calculate distance based on time between sending and receiving signal
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration*.0343)/2;
  
  // Convert distance to LED brightness value, ensuring the range 0-255
  ledValue = 255 - distance/90*255;
  if (ledValue >= 0){
    analogWrite(LED_PIN, ledValue);
  } else{
    analogWrite(LED_PIN, 0);
  }
 
  // Print distance and ledValue for debugging
  Serial.println("distance = " + String(distance) + ", ledValue = " + String(ledValue));
  
  delay(100);
}
