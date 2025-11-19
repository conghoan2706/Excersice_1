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

### Tùy chỉnh nâng cao (tùy chọn)
```cpp
WiFi.softAP(ssid, password, channel, hidden, max_connection);
// channel: Kênh WiFi (1-13), mặc định 1
// hidden: true để ẩn SSID, mặc định false
// max_connection: Số thiết bị tối đa (1-4), mặc định 4
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

## Xử lý lỗi thường gặp

| Lỗi | Nguyên nhân | Giải pháp |
|------|-------------|-----------|
| Không tạo được AP | Mật khẩu dưới 8 ký tự | Đặt mật khẩu tối thiểu 8 ký tự |
| Thiết bị không tìm thấy WiFi | ESP32 chưa khởi động xong | Đợi 5-10 giây sau khi nạp code |
| Serial Monitor không hiển thị | Baud rate sai | Đặt Serial Monitor ở 115200 baud |
| Không kết nối được vào AP | Mật khẩu sai hoặc đã đủ số kết nối | Kiểm tra mật khẩu hoặc tăng max_connection |

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

## Cải tiến có thể thêm

- [ ] Thêm Web Server để hiển thị trang web khi truy cập 192.168.4.1
- [ ] Hiển thị danh sách thiết bị đã kết nối
- [ ] Thêm DNS Server để chuyển hướng mọi domain về ESP32
- [ ] Tạo trang cấu hình WiFi (Captive Portal)
- [ ] Lưu cấu hình SSID và password vào EEPROM
- [ ] Thêm chức năng đổi mật khẩu AP động

## Output mẫu trên Serial Monitor

```
AP IP: 192.168.4.1
```

## Ứng dụng thực tế

- **IoT Configuration Portal**: Cấu hình WiFi cho thiết bị IoT
- **Local Web Server**: Tạo server web cục bộ không cần router
- **Data Logging**: Thu thập dữ liệu từ cảm biến qua WiFi
- **Smart Home Controller**: Điều khiển thiết bị trong nhà
- **Wireless Sensor Network**: Mạng cảm biến không dây

## Lưu ý bảo mật

⚠️ **Cảnh báo**: Mật khẩu mặc định "12345678" không an toàn!
- Đổi mật khẩu mạnh hơn cho ứng dụng thực tế
- Sử dụng mã hóa WPA2 (mặc định)
- Giới hạn số lượng thiết bị kết nối nếu cần

## Giấy phép
Mã nguồn mở, sử dụng tự do cho mục đích học tập và thương mại.

## Tác giả
ESP32 Access Point Project
