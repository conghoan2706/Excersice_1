#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_AP_STA);

  // Kết nối router
  WiFi.begin("Cong Hai T3", "hainga123");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Phát AP
  WiFi.softAP("ESP32_AP", "12345678");

  Serial.println("\n--- Dual Mode ---");
  Serial.print("STA IP: ");
  Serial.println(WiFi.localIP());

  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {}
