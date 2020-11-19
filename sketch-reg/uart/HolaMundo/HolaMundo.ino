#define BAUD_RATE_115200 8

int i;
uint16_t ubrr = BAUD_RATE_115200;
uint8_t dato[] = "Hola mundo\n\r";

void setup()
{
  // Configuración el baud-rate
  UBRR0H = (ubrr >> 8) & 0xFF;   // Byte más significativo
  UBRR0L = ubrr & 0xFF;          // Byte menos significativo
 
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); // UART con trama 8N1
  UCSR0B |= _BV(TXEN0);               // Habilita el transmisor
}

void loop()
{
  for(i = 0; dato[i] != '\0'; i++)
  {   
    // Espera a que el búfer de transmisión esté vacío
    while( !(UCSR0A & _BV(UDRE0)) );
    UDR0 = dato[i]; // Escribe el búfer de transmisión
  }   
  delay(500);
}
