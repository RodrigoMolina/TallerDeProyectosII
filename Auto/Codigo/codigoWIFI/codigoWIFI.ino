#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
 
//SSID y contraseña de la red
const char* ssid = "AutoTallerII";
const char* password = "12345678";
 
ESP8266WebServer server(80); //Server en puerto 80
SoftwareSerial SerialESP(1, 0);
 
//=======================================================================
//    Esta rutina es ejecutada cuando el dispositivo navega en la pagina
//=======================================================================
void handleRoot() {  
 String s = MAIN_page; //Lee el contenido HTML
 server.send(200, "text/html", s); //Envia la pagina web
 String dato = (server.arg("Data"));   
 Serial.write(dato[0]);  
}
 
//===============================================================
//                  Configuracion
//===============================================================
void setup(void){
  
  Serial.begin(9600);  
  
  WiFi.mode(WIFI_AP);           //Configura el modulo wifi como access point
  WiFi.softAP(ssid, password);  
  
  server.on("/", handleRoot);      //Cuando se navega a la raiz de la pagina se ejecuta
								   //se ejecuta la funcion handleRoot()
  server.begin();                  //Inicia el servidor
    
}
//===============================================================
//                     LOOP
//===============================================================
void loop(void){
  server.handleClient();     
}
