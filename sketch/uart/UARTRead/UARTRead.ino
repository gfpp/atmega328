#define PIN_LED_VERDE    5
#define PIN_LED_ROJO     9

// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  // Inicializa el puerto serie (UART) a 115200 bps.
  Serial.begin(115200); 
 
  // inicialización de los pines GPIO como salida para los LEDs.
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_ROJO, OUTPUT);
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop() 
{
  size_t n;
  char letra;

  // Lee la letra (1 byte) por puerto serie.
  n = Serial.readBytes(&letra, 1);
  if(n == 1)
  {
    switch(letra)
    {
      case 'v':
      case 'V':
        toggle(PIN_LED_VERDE);
        break;
      case 'r':
      case 'R':
        toggle(PIN_LED_ROJO);
        break;
    }
  }
}

// Función para cambiar el estado de un LED (GPIO).
void toggle(uint8_t gpio)
{
  if(digitalRead(gpio) == HIGH)
    digitalWrite(gpio, LOW);
  else
    digitalWrite(gpio, HIGH);
}
