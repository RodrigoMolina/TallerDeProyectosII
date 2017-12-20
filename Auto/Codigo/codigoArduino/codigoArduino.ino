#include <Servo.h>  // libreria utilizada para controlar al servo

#define MOTOR_PIN              6
#define MOTOR_CONTROL_PIN      8
#define SERVO_PIN             10

#define SERVO_IZQUIERDA       70
#define SERVO_CENTRO          90
#define SERVO_DERECHA        110

/* Variales globales */
Servo servo;  // crea el objeto servo

int nuevoComando = 0;   
int estadoDireccion = 0;
int estadoTraccion = 0;
int velocidad = 0;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(MOTOR_PIN, OUTPUT);  //configura el pin 3 como salida
  pinMode(MOTOR_CONTROL_PIN, OUTPUT);  //configura el pin 8 como salida
  digitalWrite(MOTOR_CONTROL_PIN, LOW);
  analogWrite(MOTOR_PIN, velocidad);
  
  servo.attach(SERVO_PIN);  
  servo.write(SERVO_CENTRO);
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
                  servo.write(SERVO_CENTRO);
                  estadoDireccion = 0;
                }else{
                  servo.write(SERVO_DERECHA);                  
                  estadoDireccion = 1;                     
                }
                break;  
             case 'I':        
                if(estadoDireccion == 1){
                   servo.write(SERVO_CENTRO);
                   estadoDireccion = 0;
                }else{
                  servo.write(SERVO_IZQUIERDA); 
                  estadoDireccion = -1;                    
                }   
                break;  
             case 'R':
                if(estadoTraccion == 0){
                  velocidad = 105;
                  estadoTraccion = -1;
                  digitalWrite(MOTOR_CONTROL_PIN, HIGH);    //velocidad maxima en 0
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
                      digitalWrite(MOTOR_CONTROL_PIN, LOW);   //velocidad maxima en 255
                    }else{
                      velocidad += -75;
                    }
                  }
                }
                analogWrite(MOTOR_PIN, velocidad);
                break; 
             case 'A':
                if(estadoTraccion == 0){
                  velocidad = 150;
                  estadoTraccion = 1;
                  digitalWrite(MOTOR_CONTROL_PIN, LOW); //velocidad maxima en 255
                }else{
                  if(estadoTraccion == 1){
                    if(velocidad<175){
                      velocidad += 75;
                    }else{
                      velocidad = 255;
                    }
                  }else{
                    if(velocidad>100){
                      velocidad = 0;
                      estadoTraccion = 0;
                      digitalWrite(MOTOR_CONTROL_PIN, LOW);    //velocidad maxima en 255
                    }else{
                      velocidad += 75;
                    }
                  }
                }
                analogWrite(MOTOR_PIN, velocidad);
                break;
             case 'N':
                estadoTraccion == 0;
                velocidad = 0;
                digitalWrite(MOTOR_CONTROL_PIN, LOW);     //velocidad maxima en 255
                analogWrite(MOTOR_PIN, velocidad);
                break;
             default :
             break;
          }
  }
}

