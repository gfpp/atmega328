// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  // Inicializa el puerto serie (UART) a 115200 bps.
  Serial.begin(57600); 
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
    if( (letra >= 'a') && (letra <= 'z') )
      letra -= 32;

    Serial.write(letra);
  }
}
