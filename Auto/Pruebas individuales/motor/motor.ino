int motorPin = 3;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);  //configura el pin 3 como salida
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt();  // recibe por consola el valor a establecer
    if (speed >= 0 && speed <= 255) // chequea que este dentro del rango
    {
      analogWrite(motorPin, speed); // establece el valor al puerto
    }
  }
} 
