/*
  what here: wifiCar code with ESP8266 wifi controller web
  ver at 30.08.2022 for ESP01
  TODO:
  LED indicator controller
  Buzzer dinamyc controller
  Servo (motor modification) controller
  wifi in STA mode with "welcome page"
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

#define STASSID "tp3020"
#define STAPASS "1234567890"

#define LED 1
#define BUZ 2
#define SRV 3

Servo mov;
ESP8266WebServer server(80);


// send admin page to client
void adminPanel() {
    String user = server.pathArg(0);
    server.send(200, "text/plain", "User: '" + user + "'");
}

// send controller page to client
void controllerPage() {
    server.send(200, "text/plain", "<h1>Control page</h1>");
}

// send debug page to client
void webDebbuger() {
  String answer = "";

  answer += ""
  

  
  server.send(200, "text/plain", "<h1>Control page</h1>");
}


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZ, OUTPUT);
  mov.attach(SRV);
  server.on("/", controllerPage);
  server.on(UriBraces("/admin/{}"), adminPanel);
//  server.on("/admin", controllerPage);
}

void loop() {
  server.handleClient()
}
