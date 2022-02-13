#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"


#define MY_BLUE_LED_PIN 2



//SSID and Password of your WiFi router
const char* ssid = "MobinnetDB60";
const char* password = "zbits1110098";

//void handleRoot() {
//  server.send(200, "text/plain", "hello from esp8266!");
//}

ESP8266WebServer server(80); //Server on port 80


void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(MY_BLUE_LED_PIN, OUTPUT);     // Initialise the LED_BUILTIN pin as an output

  WiFi.begin(ssid, password);     //Connect to your WiFi router
  // Wait for connection
  
  Serial.println("");

  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP

  server.on("/", handleRoot); //Which routine to handle at root location
  server.begin(); //Start server
  Serial.println("HTTP server started");
  
}


void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient(); //Handle client requests
//  digitalWrite(MY_BLUE_LED_PIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
//  delay(500);                      // Wait for a second
//  digitalWrite(MY_BLUE_LED_PIN, HIGH);  // Turn the LED off by making the voltage HIGH
//  delay(3000);                      // Wait for two seconds (to demonstrate the active low LED)

}
