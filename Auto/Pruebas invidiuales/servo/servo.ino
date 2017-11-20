
#include <Servo.h>  // libreria utilizada para controlar al servo

Servo myservo;  // crea el objeto servo


int pos = 0;    // posicion en grados del servo

void setup() {
  myservo.attach(9);  // se configura el pin 9 del microcontrolador
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // barre las posiciones del angulo 0 hasta el 180
    // in steps of 1 degree
    myservo.write(pos);              // indica al servo que vaya a la posicion establecida por la variable 'pos'
    delay(15);                       // espera 15ms para que el servo llegue a la posicion
  }
  for (pos = 180; pos >= 0; pos -= 1) { // barre las posiciones del angulo 180 hasta el 0
    myservo.write(pos);              // indica al servo que vaya a la posicion establecida por la variable 'pos'
    delay(15);                       // espera 15ms para que el servo llegue a la posicion
  }
}

