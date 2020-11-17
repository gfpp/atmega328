#define LED LED_BUILTIN

// La función 'setup' se ejecuta una única vez al encender la placa
// o presionar reset.
void setup() 
{
  // Inicializa el pin digital como salida
  pinMode(LED, OUTPUT);
}

// La función 'loop' corre indefinidamente una y otra vez.
void loop() 
{
  digitalWrite(LED, HIGH);  // Enciende el LED
  delay(1000);              // Espera por 1 seg.
  digitalWrite(LED, LOW);   // Apaga el LED
  delay(1000);              // Espera por 1 seg.
}
