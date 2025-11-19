#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);

  WiFi.softAP("ESP32_AP", "12345678");

  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {}
