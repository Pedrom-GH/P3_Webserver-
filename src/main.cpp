#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "iPhone de Pedro";      // ← Cambia esto
const char* password = "pedro1010";  // ← Cambia esto

WebServer server(80);

// Página HTML (la modificarás en el punto 2 del informe)
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Mi Primera Pagina con ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";

void handle_root() {
  server.send(200, "text/html", HTML);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Conectando a: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_root);
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
}