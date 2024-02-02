#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Redmi 9T";
const char *password = "123456789";

IPAddress staticIP(192, 168, 1, 100); // Set your desired static IP address
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  
  // Set static IP address
  WiFi.config(staticIP, gateway, subnet);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String data = "";

  while (Serial.available()) {
    char c = Serial.read();
    data += c;
  }

  server.send(200, "application/json", data);
}
