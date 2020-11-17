// LED: pin 9 --> PB1 (Salida)
// Sw: pin 7 --> PD7 (Entrada)
#define LED 9
#define SW 7

#define LED_ON HIGH
#define LED_OFF LOW
#define SW_PRES LOW

// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  pinMode(LED, OUTPUT);       // LED como salida
  pinMode(SW, INPUT);         // Sw como entrada
  digitalWrite(LED, LED_OFF); // Apaga LED
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop() 
{
  if(digitalRead(SW) == SW_PRES)
  {
    digitalWrite(LED, LED_ON);
    delay(1000);
    digitalWrite(LED, LED_OFF);
  }
  delay(1);
}
