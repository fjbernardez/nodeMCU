#include <ESP8266WiFi.h>                  //Incluye la librería ESP8266WiFi

const char ssid[] = "NodeMCU-ESP8266";    //SSDI del servidor WiFi
const char password[] = "12345678";       //contraseña del servidor
const uint16_t port = 80;

const char command [] = {'w','a','s','d','e','#','$','?'};
const int len = 8;

  //declaro servidor
  WiFiServer server (port);


void setup() {
  //baudrate
  Serial.begin(9600);  
  //inicio servidor
  server.begin();
  //modo servidor, nombre y clave visible  
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("Servidor iniciado :)");
  
}

void loop() {

  //Serial.println("Esperando cliente...");
  //delay(2000);
  
  WiFiClient client;
  client = server.available();
  
  if (client) {

    //Serial.println("Cliente conectado");
    
    while ( client.connected() ) {

      char c = client.read();

      if( charInList (c,len) ) {
        
        Serial.write(c);
      }
    }
  } 
}


int charInList (char c , int len) {
  int i ;
  int flag = 0;
  
  for(i=0;i<len;i++){
    
    if(command[i] == c){
      flag = 1; 
      break;            
    }
      
  }
  return flag;
}
