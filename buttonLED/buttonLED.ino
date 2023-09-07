const int BUTTON_PIN = 2;
const int LED_PIN = 3;
bool buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  buttonState = digitalRead(BUTTON_PIN);
  // Print buttonState for troubleshooting assistance
  Serial.println(String(buttonState));

  if (buttonState == HIGH) {
    // Turn LED on if button is pressed
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Turn LED off if button is not pressed
    digitalWrite(LED_PIN, LOW);
  }
}
