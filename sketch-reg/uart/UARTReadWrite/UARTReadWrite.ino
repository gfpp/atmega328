
#define BAUD_RATE_57600 16
uint16_t ubrr = BAUD_RATE_57600;

void setup()
{
  // Configuración el baud-rate
  UBRR0H = (ubrr >> 8) & 0xFF;   // Byte más significativo
  UBRR0L = ubrr & 0xFF;          // Byte menos significativo
 
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); // UART con trama 8N1
  UCSR0B |= _BV(TXEN0);     // Habilita el transmisor
  UCSR0B |= _BV(RXEN0);     // Habilita el receptor
}

void loop()
{
  uint8_t car;
  
  // Espera a recibir un dato
  while( !(UCSR0A & _BV(RXC0)) );
  car = UDR0; // Lee caracter
 
  if( (car >= 'a') && (car <= 'z') )
    car -= 32; 
 
  // Espera a que el búfer de transmisión esté vacío
  while( !(UCSR0A & _BV(UDRE0)) );
  UDR0 = car;     // Escribe el búfer de transmisión
}
