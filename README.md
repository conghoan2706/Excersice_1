# ESP32 Access Point (AP Mode)

## Mô tả
Chương trình này biến ESP32 thành một điểm phát WiFi (Access Point), cho phép các thiết bị khác kết nối vào ESP32.

## Yêu cầu phần cứng
- Bo mạch ESP32
- Kết nối USB để nạp code và xem Serial Monitor

## Yêu cầu phần mềm
- Arduino IDE với ESP32 board package đã cài đặt
- Thư viện WiFi.h (có sẵn trong ESP32 package)

## Cấu hình

### Thông tin Access Point
Cập nhật các thông số sau trong code:
```cpp
WiFi.softAP("ESP32_AP", "12345678");
// Tham số 1: Tên WiFi (SSID)
// Tham số 2: Mật khẩu (tối thiểu 8 ký tự)
```

## Cách sử dụng

### 1. Cài đặt ESP32 trong Arduino IDE
- Mở Arduino IDE → File → Preferences
- Thêm URL: `https://dl.espressif.com/dl/package_esp32_index.json`
- Tools → Board → Boards Manager → Tìm "ESP32" và cài đặt

### 2. Nạp code
- Kết nối ESP32 qua USB
- Chọn đúng board: Tools → Board → ESP32 Dev Module
- Chọn đúng Port: Tools → Port
- Nhấn Upload

### 3. Kiểm tra kết quả
- Mở Serial Monitor (baud rate: 115200)
- Xem địa chỉ IP của Access Point (mặc định: 192.168.4.1)
- Dùng điện thoại hoặc laptop tìm WiFi "ESP32_AP"
- Kết nối với mật khẩu "12345678"

## Chức năng

### Hàm `setup()`
- Khởi tạo Serial communication với tốc độ 115200 baud
- Cấu hình ESP32 ở chế độ Access Point (WIFI_AP)
- Tạo điểm phát WiFi với SSID "ESP32_AP" và mật khẩu "12345678"
- Hiển thị địa chỉ IP của Access Point (mặc định: 192.168.4.1)

### Hàm `loop()`
- Không thực hiện gì (có thể thêm các chức năng khác tại đây)

## Thông tin Access Point mặc định

| Thông số | Giá trị |
|----------|---------|
| IP Address | 192.168.4.1 |
| Subnet Mask | 255.255.255.0 |
| Gateway | 192.168.4.1 |
| SSID | ESP32_AP |
| Password | 12345678 |
| Channel | 1 |
| Max Connections | 4 |


## Kiểm tra thiết bị đã kết nối

Thêm code sau để xem số thiết bị đã kết nối:

```cpp
void loop() {
  static unsigned long lastCheck = 0;
  
  if (millis() - lastCheck > 5000) {  // Kiểm tra mỗi 5 giây
    lastCheck = millis();
    int numClients = WiFi.softAPgetStationNum();
    Serial.print("Số thiết bị kết nối: ");
    Serial.println(numClients);
  }
}
```



## Output mẫu trên Serial Monitor

```
AP IP: 192.168.4.1
```



