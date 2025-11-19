#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "ESP32_AP";        // AP name
const char* password = "12345678";    // AP password

WiFiUDP udp;
unsigned int localPort = 1234;        // port ESP32 nhận

void setup() {
  Serial.begin(115200);

  // Dual mode hoặc AP mode
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(ssid, password);

  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  udp.begin(localPort);
  Serial.println("UDP server started");
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char incomingPacket[255];
    int len = udp.read(incomingPacket, 255);
    if (len > 0) incomingPacket[len] = 0;
    Serial.print("Received: ");
    Serial.println(incomingPacket);

    // Gửi lại confirm
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.print("ESP32 got: ");
    udp.println(incomingPacket);
    udp.endPacket();
  }
}
