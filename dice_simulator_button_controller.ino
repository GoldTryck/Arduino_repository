int buttonPin = 11;        // Pin del botón
int buttonState = LOW;     // Estado actual del botón
int lastButtonState = LOW; // Estado previo del botón
int displayState = LOW;    // Estado del display

// Definimos las matrices para los números
int numeros[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

// Función para mostrar un número en el display
void mostrarNumero(int numero)
{
  // Recorremos la matriz del número
  for (int pos = 0; pos <= 6; pos++)
  {
    // Encendemos el pin correspondiente al segmento
    digitalWrite(pos + 2, numeros[numero][pos]);
  }
}
void setup()
{
  // Configuramos los pines como salidas
  for (int i = 2; i <= 8; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(buttonPin, INPUT); // Configuramos el pin del botón como entrada
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastButtonState == LOW)
  {
    // Si el botón se ha pulsado
    if (displayState == LOW)
    {
      displayState = HIGH;
      mostrarNumero(random(0, 10));
      // Esperamos un momento
      delay(800);
    }
    else
    {
      displayState = LOW; // Apaga el si está encendido
      for (int i = 2; i <= 8; i++)
      {
        digitalWrite(i, 0);
      }
      delay(800);
    }
  }
}