// Week 9: Tilt Switch Alarm
// Author: 0xHitek

#define TILT_PIN 2
#define LED_PIN 9
#define BUZZER_PIN 8

void setup() {
  pinMode(TILT_PIN, INPUT_PULLUP);  // internal pull-up
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  int tiltState = digitalRead(TILT_PIN);

  if (tiltState == LOW) {   // sensor closed = tilted
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);   // alarm sound
    Serial.println("⚠️ Tilt detected!");
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("Stable.");
  }

  delay(100);
}
