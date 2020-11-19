#define MENSAJE "Hola mundo"

// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  // Inicializa el puerto serie (UART) a 115200 bps.
  Serial.begin(115200);
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop() 
{
  Serial.println(MENSAJE);
  delay(500);
}
