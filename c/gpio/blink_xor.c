#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main (void)
{
  /* Inicializa el pin digital como salida */
	DDRB |= _BV(DDB5);

	while(1) 
  {
		PORTB ^= _BV(PORTB5);    /* Toggle LED */
		_delay_ms(BLINK_DELAY_MS);
	}
	return 0;
}

