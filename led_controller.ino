int buttonPin = 11; // Pin del botón
int ledPin = 12;   // Pin del LED
int buttonState = LOW; // Estado actual del botón
int lastButtonState = LOW; // Estado previo del botón
int ledState = LOW; // Estado del LED

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    // Si el botón se ha pulsado
    if (ledState == LOW) {
      ledState = HIGH; // Enciende el LED si está apagado
    } else {
      ledState = LOW; // Apaga el LED si está encendido
    }
  }

  digitalWrite(ledPin, ledState);

  lastButtonState = buttonState;
}