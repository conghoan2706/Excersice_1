#include <WiFi.h>

const char* ssid = "Cong Hai T3";
const char* password = "hainga123";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Đang kết nối WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nKết nối thành công!");
  Serial.print("IP ESP32: ");
  Serial.println(WiFi.localIP());

  // Test TCP gửi tin đến server
  WiFiClient client;
  if (client.connect("192.168.1.100", 8888)) {
    client.println("Hello from ESP32!");
    Serial.println("Đã gửi TCP đến server.");
  }
}

void loop() {}
