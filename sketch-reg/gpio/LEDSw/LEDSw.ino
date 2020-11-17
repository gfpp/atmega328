// LED: pin 9 --> PB1 (Salida)
// Sw: pin 7 --> PD7 (Entrada)

#define SW_MASK _BV(PIND7)
#define SW_PRES 0

uint8_t sw;

// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  // Configuración de entrada/salida digitales
  DDRB |= _BV(DDB1);      // LED como salida
  DDRD &= ~_BV(DDD7);     // Sw como entrada
  PORTB &= ~_BV(PORTB1);  // Apaga el LED
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop() 
{
  // Lee el valor del pulsador
  sw = (PIND & SW_MASK) >> PIND7;
 
  if(sw == SW_PRES)
  {   
    PORTB |= _BV(PORTB1);   // Enciende LED
    delay(1000);
    PORTB &= ~_BV(PORTB1);  // Apaga LED
  }   
  delay(1);
}
