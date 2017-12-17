#include <Servo.h>  // libreria utilizada para controlar al servo
Servo servo;  // crea el objeto servo
int motorPin = 6;
int motorControlPin = 8;
int servoPin = 11;
int servoControlPin = 10;
int nuevoComando = 0;   // for incoming serial data
int estadoDireccion = 0;
int estadoTraccion = 0;
int velocidad = 0;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(motorPin, OUTPUT);  //configura el pin 3 como salida
  pinMode(motorControlPin, OUTPUT);  //configura el pin 8 como salida
  digitalWrite(motorControlPin, LOW);
  analogWrite(motorPin, velocidad);
  
  servo.attach(servoControlPin);  
  pinMode(servoPin, OUTPUT);  
  pinMode(servoControlPin, OUTPUT);  //configura el pin 3 como salida
  digitalWrite(servoPin, HIGH);
  servo.write(90);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  // send data only when you receive data:
  if (Serial.available() > 0) {
    
          // read the incoming byte:
          nuevoComando = Serial.read();
          
          Serial.write(nuevoComando);
          
          switch(nuevoComando){
             case 'D':
                if(estadoDireccion == -1){
                  servo.write(90);
                  estadoDireccion = 0;
                }else{
                  servo.write(110);                  
                  estadoDireccion = 1;                     
                }
                break;  
             case 'I':        
                if(estadoDireccion == 1){
                   servo.write(90);
                   estadoDireccion = 0;
                }else{
                  servo.write(70); 
                  estadoDireccion = -1;                    
                }   
                break;  
             case 'R':
                if(estadoTraccion == 0){
                  velocidad = -150;
                  estadoTraccion = -1;
                  digitalWrite(motorControlPin, HIGH);    //velocidad maxima en 0
                }else{
                  if(estadoTraccion == -1){
                    if(velocidad>75){
                      velocidad += -75;
                    }else{
                      velocidad = 0;
                    }
                  }else{
                    if(velocidad<150){
                      velocidad = 0;
                      estadoTraccion = 0;
                      digitalWrite(motorControlPin, LOW);   //velocidad maxima en 255
                    }else{
                      velocidad += -75;
                    }
                  }
                }
                analogWrite(motorPin, velocidad);
                break; 
             case 'A':
                if(estadoTraccion == 0){
                  velocidad = 150;
                  estadoTraccion = 1;
                  digitalWrite(motorControlPin, LOW); //velocidad maxima en 255
                }else{
                  if(estadoTraccion == 1){
                    if(velocidad<175){
                      velocidad += 75;
                    }else{
                      velocidad = 255;
                    }
                  }else{
                    if(velocidad>175){
                      velocidad = 0;
                      estadoTraccion = 0;
                      digitalWrite(motorControlPin, LOW);    //velocidad maxima en 255
                    }else{
                      velocidad += 75;
                    }
                  }
                }
                analogWrite(motorPin, velocidad);
                break;
             case 'N':
                estadoTraccion == 0;
                velocidad = 0;
                digitalWrite(motorControlPin, LOW);     //velocidad maxima en 255
                analogWrite(motorPin, velocidad);
                break;
             default :
             break;
          }
  }
}

