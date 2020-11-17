// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  // Inicializa el pin digital como salida
  DDRB |= _BV(DDB5);
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop() 
{
  PORTB |= _BV(PORTB5);   // Enciende LED
  delay(1000);            // Espera por 1 seg.

  PORTB &= ~_BV(PORTB5);  // Apaga LED
  delay(1000);            // Espera por 1 seg.
}
