#define BAUD_RATE_115200 8
uint16_t ubrr = BAUD_RATE_115200;

void setup()
{
  DDRB |= _BV(DDB1);        // Led rojo, salida
  DDRD |= _BV(DDD5);        // Led verde, salida
  
  // Configuración el baud-rate
  UBRR0H = (ubrr >> 8) & 0xFF;   // Byte más significativo
  UBRR0L = ubrr & 0xFF;          // Byte menos significativo
 
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); // UART con trama 8N1
  UCSR0B |= _BV(RXEN0);     // Habilita el receptor
}

void loop()
{
  // Espera a recibir un dato
  while( !(UCSR0A & _BV(RXC0)) );
 
  switch(UDR0) {
    case 'r':
    case 'R':
      PORTB ^= _BV(PORTB1); // Cambia estado de LED rojo
      break;
 
    case 'v':
    case 'V':
      PORTD ^= _BV(PORTD5); // Cambia estado de LED verde
      break;          
  } 
  delay(1);
}
