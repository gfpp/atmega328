#define LED_DDR DDRD
#define LED_PORT PORTD
#define LED_MASK 0x0F

uint8_t hex = 0;

// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup()
{
  LED_DDR |= LED_MASK;
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop()
{
  LED_PORT &= ~(LED_MASK);  // Apaga los LEDs
  LED_PORT |= hex;          // Muestra valor
  
  if(++hex > 16)    // Controla rango máximo
    hex = 0;
  
  delay(500);
}
