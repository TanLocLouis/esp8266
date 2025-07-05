# 💻 ESP8266 Computer Remote Control + Weather Monitor

This is a simple project using an **ESP8266** to:

- ✅ Remotely **turn on** a computer using a relay.
- 🔁 **Reboot** the computer automatically when it freezes.
- 🌡️ Read **temperature and humidity** data from a **DHT11** sensor.

## 📦 Features

- Simple web-based control.
- JSON API for weather data.
- Reliable physical control using relays.

## 🚀 How to Use

| Action         | URL                              | Description                            |
|----------------|----------------------------------|----------------------------------------|
| Power On       | `http://<esp_ip>/poweron`        | Turns on the computer via relay.       |
| Reboot         | `http://<esp_ip>/reboot`         | Reboots the computer if frozen.        |
| Read Weather   | `http://<esp_ip>/weather`        | Returns temperature & humidity in JSON.|

> Replace `<esp_ip>` with the actual IP address of your ESP8266 module.

## 📝 Example JSON Response (from `/weather`)

```json
{
  "temperature": 28.5,
  "humidity": 62
}
