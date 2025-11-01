# 💻 ESP8266 Multi-Purpose IoT Controller

A comprehensive ESP8266-based project that combines remote computer control, environmental monitoring, and servo automation. Perfect for home automation, remote PC management, and IoT experiments.

## ✨ Features

- 🖥️ **Computer Remote Control** - Remotely power on and reboot your computer via relay
- 🌡️ **Weather Monitoring** - Real-time temperature and humidity sensing with DHT11
- 🤖 **Servo Control** - Automated servo motor control for various applications
- 📊 **RESTful API** - Simple HTTP API for all functions
- 🔍 **Power State Detection** - Check if computer is on using optocoupler
- 📝 **Data Logging** - Python scripts for automated data collection
- 🎙️ **Voice Control** - Optional voice-activated servo control

## 🛠️ Hardware Requirements

### Main Components
- **ESP8266** (NodeMCU recommended)
- **DHT11** Temperature & Humidity Sensor
- **Relay Module** (5V single-channel)
- **Servo Motor** (SG90 or similar)
- **Optocoupler** (for power state detection, optional)

### Pin Configuration
| Component | GPIO Pin | NodeMCU Pin | Description |
|-----------|----------|-------------|-------------|
| DHT11     | GPIO5    | D1          | Temperature/Humidity sensor |
| Servo     | GPIO2    | D4          | Servo motor control |
| Relay     | GPIO15   | D8          | Computer power control |
| Optocoupler | GPIO13 | D7          | Computer state detection |

## 📦 Software Dependencies

### Arduino Libraries
```
ESP8266WiFi
Servo
Adafruit_Sensor
DHT
```

### Python Requirements (for scripts)
```bash
pip install requests
pip install SpeechRecognition  # For voice control
```

## 🔧 Installation & Setup

### 1. Arduino IDE Setup
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Add ESP8266 board support:
   - Go to **File → Preferences**
   - Add to Additional Board URLs: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
   - Go to **Tools → Board → Board Manager**, search "esp8266" and install

3. Install required libraries:
   - Go to **Sketch → Include Library → Manage Libraries**
   - Search and install: `Adafruit Unified Sensor`, `DHT sensor library`, `Servo`

### 2. Configure WiFi Credentials
Edit the `esp.ino` file and update your WiFi credentials:
```cpp
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
```

### 3. Upload to ESP8266
1. Connect your ESP8266 to your computer via USB
2. Select the correct board: **Tools → Board → NodeMCU 1.0**
3. Select the correct port: **Tools → Port → [Your ESP8266 Port]**
4. Click **Upload**

### 4. Get ESP8266 IP Address
After uploading, open the Serial Monitor (115200 baud) to see the assigned IP address:
```
Connecting.....
Connected to WiFi. IP: 192.168.1.100
```

## 🚀 API Endpoints

### Computer Control

#### Power On
```bash
GET http://<esp_ip>/poweron
```
Sends a 1-second pulse to the relay, simulating a power button press.

**Response:**
```
Relay power cycled.
```

#### Reboot
```bash
GET http://<esp_ip>/reboot
```
Holds the relay ON for 10 seconds to force a shutdown/reboot.

**Response:**
```
Relay held ON for 10 seconds.
```

### Environmental Monitoring

#### Get Weather Data
```bash
GET http://<esp_ip>/weather
```

**Response:**
```json
{
  "temperature": 28.5,
  "humidity": 62.0
}
```

### System Status

#### Check Power State
```bash
GET http://<esp_ip>/ispoweron
```
Returns whether the computer is powered on (detected via optocoupler).

**Response:**
```json
{
  "status": 1
}
```
- `1` = Computer is ON
- `0` = Computer is OFF

### Servo Control

#### Trigger Servo
```bash
GET http://<esp_ip>/hit
```
Moves servo from 0° to 180° (useful for automated button pressing or mechanical triggers).

**Response:**
```
OK
```

## 💻 Using the Python Scripts

### Weather Data Logger (`curl_weather_from_esp.py`)

Automatically fetches and logs weather data every 20 seconds.

**Configuration:**
```python
URL = "http://192.168.1.2/weather"  # Update with your ESP IP
```

**Usage:**
```bash
python curl_weather_from_esp.py
```

**Output:**
Creates daily log files in `data/` directory:
```
data/01-15-2025.txt
```

**Log Format:**
```
[14:30:15] {"temperature":25.5,"humidity":60.0}
[14:30:35] {"temperature":25.6,"humidity":59.8}
```

### Voice-Controlled Servo (`esp.py`)

Control the servo using voice commands (experimental).

**Configuration:**
```python
ESP_IP = "http://192.168.1.2"  # Update with your ESP IP
```

**Usage:**
```bash
python esp.py
```

**Voice Commands:**
- Say "open" to trigger the servo
- Say "close" to return servo to position

**Note:** Requires a microphone and internet connection for Google Speech Recognition.

## 📋 Usage Examples

### Using cURL

**Power on computer:**
```bash
curl http://192.168.1.100/poweron
```

**Get current weather:**
```bash
curl http://192.168.1.100/weather
```

**Check if computer is on:**
```bash
curl http://192.168.1.100/ispoweron
```

### Using Python

```python
import requests

ESP_IP = "http://192.168.1.100"

# Power on computer
response = requests.get(f"{ESP_IP}/poweron")
print(response.text)

# Get weather data
weather = requests.get(f"{ESP_IP}/weather").json()
print(f"Temperature: {weather['temperature']}°C")
print(f"Humidity: {weather['humidity']}%")
```

### Using Web Browser

Simply navigate to the endpoints in your browser:
- `http://192.168.1.100/weather`
- `http://192.168.1.100/poweron`
- `http://192.168.1.100/ispoweron`

## 🔌 Wiring Guide

### DHT11 Sensor
```
DHT11 VCC  → ESP8266 3.3V
DHT11 GND  → ESP8266 GND
DHT11 DATA → ESP8266 D1 (GPIO5)
```

### Relay Module
```
Relay VCC  → ESP8266 5V (or 3.3V depending on relay)
Relay GND  → ESP8266 GND
Relay IN   → ESP8266 D8 (GPIO15)
Relay COM  → Computer Power Button (+)
Relay NO   → Computer Power Button (-)
```

### Servo Motor
```
Servo VCC (Red)    → ESP8266 5V
Servo GND (Brown)  → ESP8266 GND
Servo Signal (Orange) → ESP8266 D4 (GPIO2)
```

### Optocoupler (Optional)
```
Optocoupler VCC → ESP8266 3.3V
Optocoupler GND → ESP8266 GND
Optocoupler OUT → ESP8266 D7 (GPIO13)
Optocoupler IN+ → Computer Power LED (+)
Optocoupler IN- → Computer Power LED (-)
```

## 🔒 Security Considerations

⚠️ **Important:** This device provides physical control over your computer. Consider these security measures:

1. **Use strong WiFi password** - Protect your WiFi network
2. **Change default credentials** - Update WiFi SSID/password in code
3. **Local network only** - Don't expose to the internet without proper authentication
4. **Physical security** - Keep the device in a secure location
5. **Add authentication** - Consider adding API key authentication for production use

## 🐛 Troubleshooting

### ESP8266 won't connect to WiFi
- Double-check SSID and password
- Ensure WiFi is 2.4GHz (ESP8266 doesn't support 5GHz)
- Check Serial Monitor for connection status

### DHT11 returns null/NaN
- Verify wiring connections
- Try adding a 10kΩ pull-up resistor between DATA and VCC
- Wait 2 seconds between readings

### Relay doesn't trigger
- Check relay module voltage requirements (some need 5V)
- Verify GPIO15 connection
- Test relay with `digitalWrite(RELAY_PIN, HIGH)`

### Computer won't power on
- Verify relay is connected to correct power button pins
- Test manually shorting the power button pins
- Some motherboards require longer pulse duration

## 📄 License

This project is open source and available for personal and educational use.

## 🤝 Contributing

Feel free to submit issues, fork the repository, and create pull requests for any improvements.

## 📧 Support

For questions and support, please open an issue on the GitHub repository.

---

**Made with ❤️ for the IoT community**
