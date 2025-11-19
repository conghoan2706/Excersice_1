#include <WiFi.h>

WiFiServer server(8080);

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin("Cong Hai T3", "hainga123");
  WiFi.softAP("ESP32_AP", "12345678");

  Serial.println("AP IP:");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected!");

    while (client.connected()) {
      if (client.available()) {
        String data = client.readString();
        Serial.print("Recv: ");
        Serial.println(data);

        client.println("ESP32 Received: " + data);
      }
    }
  }
}
