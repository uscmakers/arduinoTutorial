const int POT_PIN = 19;
const int LED_PIN = 3;
int potValue;
int ledValue;

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // Note: analogRead only reads values from 0 to 1023 for Arduino Uno
  potValue = analogRead(POT_PIN);
  // Convert potValue to ledValue since analogWrite only writes values from 0 to 255
  ledValue = float(potValue)/1023*255;
  
  // Print potValue and ledValue for troubleshooting assistance
  Serial.println("potValue = " + String(potValue) + ", ledValue = " + String(ledValue));

  // Adjust brightness of LED based on potentiometer reading
  analogWrite(LED_PIN, ledValue);
  delay(10);
}

