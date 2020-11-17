uint8_t hex = 0;
uint8_t mask;

// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  // Inicializa salidas digitales
  pinMode(0, OUTPUT);   // PD0
  pinMode(1, OUTPUT);   // PD1
  pinMode(2, OUTPUT);   // PD2
  pinMode(3, OUTPUT);   // PD3
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop() 
{
  mask = 0x01;
  
  for(uint8_t i = 0; i < 4; i++)
  {
    if(hex & mask)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
    mask <<= 1;
  }
  
  if(++hex > 16)    // Controla rango máximo
    hex = 0;
  
  delay(500);
}
