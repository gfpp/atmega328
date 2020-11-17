#include <avr/io.h>
#include <util/delay.h>

/*
 * LED: pin 9 --> PB1 (Salida)
 * Sw:  pin 7 --> PD7 (Entrada)
 */
#define SW_MASK _BV(PIND7)
#define SW_PRES 0

int main(void)
{
  uint8_t sw;

  /* Configuración de entrada/salida digitales */
  DDRB |= _BV(DDB1);      /* LED como salida */
  DDRD &= ~_BV(DDD7);     /* Sw como entrada */
  PORTB &= ~_BV(PORTB1);  /* Apaga el LED */
  
  while(1)
  {
    /* Lee el valor del pulsador */
    sw = (PIND & SW_MASK) >> PIND7;

    if(sw == SW_PRES)
    {
      PORTB |= _BV(PORTB1);   /* Enciende LED */
      _delay_ms(1000);
      PORTB &= ~_BV(PORTB1);  /* Apaga LED */
    }
		_delay_ms(1);
  }
  return 0;
}

