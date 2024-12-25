# **PHÁT TRIỂN HỆ THỐNG IOT VỚI THINGSPEAK VÀ CÁC CÔNG NGHỆ ARDUINO, ESP32, RASPBERRY**

---

## **Giới Thiệu**  
Dự án này sử dụng ESP8266 để giám sát các thông số môi trường như nhiệt độ, độ ẩm đất, và mức độ ánh sáng. Dữ liệu sẽ được hiển thị trên màn hình LCD và gửi lên ThingSpeak để theo dõi từ xa. Ngoài ra, hệ thống tự động điều khiển quạt, động cơ bơm nước, và bóng đèn dựa vào dữ liệu cảm biến.

---

## **Tính Năng**  
- Theo dõi nhiệt độ, độ ẩm đất, và ánh sáng.  
- Hiển thị thông tin trên màn hình LCD.  
- Gửi dữ liệu lên ThingSpeak để theo dõi từ xa.  
- Tự động bật/tắt quạt, động cơ, và bóng đèn khi cần.  

---

## **Hướng Dẫn Cài Đặt**

### **1. Cài Đặt ThingSpeak**  
1. Truy cập [ThingSpeak](https://thingspeak.com) và đăng ký tài khoản.  
2. Tạo một kênh mới:
   - Vào **Channels** → **New Channel**.  
   - Điền thông tin:
     - **Name**: "Smart_Flower_Greenhouse".  
     - **Field 1**: "Nhiệt độ".  
     - **Field 2**: "Độ ẩm đất".  
     - **Field 3**: "Ánh sáng".  
3. Lưu lại và truy cập tab **API Keys** để lấy mã **Write API Key**.  
   - Sao chép mã và thay vào biến `api_key` trong file `wifi_setup.ino`.  

---

### **2. Tạo Mô Phỏng trên TinkerCAD**  
1. Đăng nhập vào [TinkerCAD](https://tinkercad.com).  
2. Tạo **Circuit** mới.  
3. Thêm các thành phần:
   - **ESP8266 Module**.  
   - **LCD Display**.  
   - Cảm biến nhiệt độ, độ ẩm đất, và ánh sáng.  
   - Quạt, động cơ bơm nước, và bóng đèn LED.  
4. Kết nối dây theo sơ đồ mạch:  
   - **ESP8266** với cảm biến và LCD theo sơ đồ trong phần code.  
5. Tải các file `main.ino`, `lcd_display.ino`, `wifi_setup.ino`, và `sensor_data.ino` từ thư mục `src`.  
6. Dán từng file vào **Code Editor** của TinkerCAD.  

---

### **3. Cách Sử Dụng Các File**

#### **Cấu trúc thư mục**  
```
project/
├── src/
│   ├── main.ino         // Mã chính
│   ├── lcd_display.ino   // Quản lý LCD
│   ├── wifi_setup.ino    // Cấu hình Wi-Fi
│   ├── sensor_data.ino   // Xử lý dữ liệu cảm biến
└── readme.md            // File tài liệu
```

#### **Hướng dẫn sử dụng**  
1. Mở file `src/main.ino` bằng Arduino IDE.  
2. Đảm bảo các file `.ino` khác được đặt trong cùng một thư mục.  
3. Cập nhật thông tin Wi-Fi trong file `wifi_setup.ino`:
   ```cpp
   String ssid     = "Tên_Wifi";
   String password = "Mật_khẩu_Wifi";
   ```
4. Cắm Arduino vào máy tính và chọn đúng cổng kết nối trong **Tools**.  
5. Nhấn **Upload** để nạp code vào Arduino.  

---

### **4. Chạy Dự Án**  
- Dữ liệu từ cảm biến sẽ hiển thị trên LCD.  
- ThingSpeak sẽ nhận thông tin và hiển thị trên bảng điều khiển.  
- Quạt, động cơ, và bóng đèn sẽ tự động bật/tắt dựa vào ngưỡng cảm biến.  

---

## **Yêu Cầu Phần Cứng**  
- Arduino (có hỗ trợ ESP8266).  
- Module ESP8266.  
- Cảm biến nhiệt độ, độ ẩm đất, và ánh sáng.  
- Quạt, bơm nước, và bóng đèn LED.  
- Màn hình LCD.  

---

Nếu có vấn đề, vui lòng liên hệ để được hỗ trợ! 😊
