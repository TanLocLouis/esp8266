
// ---------------------------DHT11 control------------------------
// #include <Adafruit_Sensor.h>
// #include <DHT.h>

// #define DHTPIN 2       // Change this to the pin you connected (e.g., GPIO15)
// #define DHTTYPE DHT11  // or DHT22

// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   Serial.begin(115200);
//   dht.begin();
// }

// void loop() {
//   delay(2000);  // Wait between readings

//   float temperature = dht.readTemperature();
//   float humidity = dht.readHumidity();

//   if (isnan(temperature) || isnan(humidity)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.print(" °C, Humidity: ");
//   Serial.print(humidity);
//   Serial.println(" %");
// }


// ---------------------------Servo control------------------------
// #include <Servo.h>

// Servo myservo;

// #define SERVO_PIN 2  // GPIO2 = D4 on NodeMCU

// void setup() {
//   Serial.begin(115200);
//   myservo.attach(SERVO_PIN);
//   myservo.write(90);  // Start at center
//   delay(1000);
// }

// void loop() {
//   Serial.println("Moving to 0°");
//   myservo.write(0);   // Move to 0°
//   delay(1000);

//   Serial.println("Moving to 180°");
//   myservo.write(180); // Move to 180°
//   delay(1000);

//   Serial.println("Moving to 90°");
//   myservo.write(90);  // Move to center
//   delay(1000);
// }


// ---------------------------Sling Gun------------------------
// #include <ESP8266WiFi.h>      // Use <WiFi.h> if using ESP32
// #include <Servo.h>

// const char* ssid = "Xiaomi_BE60";
// const char* password = "phong5032";

// WiFiServer server(80);
// Servo myservo;

// void setup() {
//   Serial.begin(115200);
//   myservo.attach(2); // GPIO2 = D4
//   myservo.write(90); // Start at center

//   WiFi.begin(ssid, password);
//   Serial.print("Connecting");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500); Serial.print(".");
//   }

//   Serial.println("\nConnected to WiFi. IP: " + WiFi.localIP().toString());
//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (!client) return;

//   String request = client.readStringUntil('\r');
//   Serial.println("Request: " + request);
//   client.flush();

//   if (request.indexOf("/open") != -1) {
//     myservo.write(0);   // Open
//   } else if (request.indexOf("/close") != -1) {
//     myservo.write(180); // Close
//   }

//   // Basic HTTP response
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println();
//   client.println("OK");
//   client.stop();
// }

// ---------------------------Sling Gun------------------------
// #include <ESP8266WiFi.h>      // Use <WiFi.h> if using ESP32
// #include <Servo.h>

// const char* ssid = "Xiaomi_BE60";
// const char* password = "phong5032";

// WiFiServer server(80);
// Servo myservo;

// void setup() {
//   Serial.begin(115200);
//   myservo.attach(2); // GPIO2 = D4
//   myservo.write(90); // Start at center

//   WiFi.begin(ssid, password);
//   Serial.print("Connecting");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500); Serial.print(".");
//   }

//   Serial.println("\nConnected to WiFi. IP: " + WiFi.localIP().toString());
//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (!client) return;

//   String request = client.readStringUntil('\r');
//   Serial.println("Request: " + request);
//   client.flush();

//   if (request.indexOf("/open") != -1) {
//     myservo.write(0);   // Open
//   } else if (request.indexOf("/close") != -1) {
//     myservo.write(180); // Close
//   }

//   // Basic HTTP response
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println();
//   client.println("OK");
//   client.stop();
// }







// ---------------------------DHT11 control------------------------
// #include <Adafruit_Sensor.h>
// #include <DHT.h>

// #define DHTPIN 2       // Change this to the pin you connected (e.g., GPIO15)
// #define DHTTYPE DHT11  // or DHT22

// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   Serial.begin(115200);
//   dht.begin();
// }

// void loop() {
//   delay(2000);  // Wait between readings

//   float temperature = dht.readTemperature();
//   float humidity = dht.readHumidity();

//   if (isnan(temperature) || isnan(humidity)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.print(" °C, Humidity: ");
//   Serial.print(humidity);
//   Serial.println(" %");
// }



// ---------------------------Sling Gun------------------------
// #include <ESP8266WiFi.h>      // Use <WiFi.h> if using ESP32
// #include <Servo.h>

// // DHT11
// #include <Adafruit_Sensor.h>
// #include <DHT.h>
// #define DHTPIN 5       // Change this to the pin you connected (e.g., GPIO15)
// #define DHTTYPE DHT11  // or DHT22
// DHT dht(DHTPIN, DHTTYPE);

// // Relay
// #define RELAY_PIN 2

// // Wifi
// const char* ssid = "Xiaomi_BE60";
// const char* password = "phong5032";
// WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);

//   // Setup DHT11
//   dht.begin();

//   // Setup relay
//   pinMode(RELAY_PIN, OUTPUT);
//   digitalWrite(RELAY_PIN, LOW);     // Start with relay OFF

//   // Setup Wifi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500); Serial.print(".");
//   }

//   Serial.println("\nConnected to WiFi. IP: " + WiFi.localIP().toString());
//   server.begin();
// }

// void FUNC_DHT11() {
//   float temperature = dht.readTemperature();
//   float humidity = dht.readHumidity();

//   if (isnan(temperature) || isnan(humidity)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.print(" °C, Humidity: ");
//   Serial.print(humidity);
//   Serial.println(" %");

//   delay(1000);
// }

// void FUNC_Relay() {
//   WiFiClient client = server.available();
//   if (!client) return;

//   String request = client.readStringUntil('\r');
//   Serial.println("Request: " + request);
//   client.flush();

//   // Execute command from cliente
//   if (request.indexOf("/poweron") != -1) {
//     digitalWrite(RELAY_PIN, HIGH);    // Relay ON
//     Serial.println("ON");
//     delay(1000);
//     digitalWrite(RELAY_PIN, LOW);    // Relay ON
//     Serial.println("OFF");
//   } else if (request.indexOf("/reboot") != -1) {
//     digitalWrite(RELAY_PIN, HIGH);    // Relay ON
//     Serial.println("ON");
//     delay(10000);
//     digitalWrite(RELAY_PIN, LOW);    // Relay ON
//     Serial.println("OFF");
//   }

//   // Basic HTTP response
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println();
//   client.println("OK");
//   client.stop();

//   delay(1000);
// }

// void loop() {
//   FUNC_DHT11();
//   FUNC_Relay();
// }

// --------------------------- Sling Gun with API ------------------------
#include <ESP8266WiFi.h>
#include <Servo.h>

// DHT11
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTPIN 5       // GPIO5 = D1 on NodeMCU
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// Global vars for sensor data
float temperature = NAN;
float humidity = NAN;

// Servo
Servo myservo;
#define SERVO_PIN 2  // GPIO2 = D4 on NodeMCU

// Relay
#define RELAY_PIN 15    // GPIO15 = D4

// WiFi
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
WiFiServer server(80);

// GPIO13 check OPTO is closed?
#define OPTO_PIN 13     // GPIO13 = D8

void setup() {
  // Set time for ESP8266 to fully booted
  delay(2000);

  Serial.begin(115200);

  // Servo
  myservo.attach(SERVO_PIN);
  myservo.write(90);  // Start at center

  // Setup DHT11
  dht.begin();

  // Setup relay
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);     // Start with relay OFF

  // Enable internal pull-up resistor for GPIO 16
  pinMode(OPTO_PIN, INPUT_PULLUP);

  // Setup WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }

  Serial.println("\nConnected to WiFi. IP: " + WiFi.localIP().toString());
  server.begin();
}

void readDHT11() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (!isnan(t) && !isnan(h)) {
    temperature = t;
    humidity = h;
    Serial.printf("DHT: %.1f°C, %.1f%%\n", temperature, humidity);
  } else {
    Serial.println("❌ Failed to read DHT11");
  }
}

bool is_OCTO_Closed() {
  int state = digitalRead(OPTO_PIN);
  if (state == LOW) {
    Serial.println("Circuit is CLOSED (Optocoupler conducting)");
    return true;
  } else {
    Serial.println("Circuit is OPEN (Optocoupler not conducting)");
    return false;
  }
}

void handleClient() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  Serial.println("Request: " + request);
  client.flush();

  // Relay control
  if (request.indexOf("/poweron") != -1) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Relay ON");
    delay(1000);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay OFF");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println(); client.println("Relay power cycled.");

  } else if (request.indexOf("/reboot") != -1) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Relay ON (10s)");
    delay(10000);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay OFF");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println(); client.println("Relay held ON for 10 seconds.");

  // Read data from DHT11 and create API
  } else if (request.indexOf("/weather") != -1) {
    // Read fresh DHT values before serving
    readDHT11();

    // Create JSON payload
    String json = "{";
    json += "\"temperature\":";
    json += isnan(temperature) ? "null" : String(temperature, 1);
    json += ",\"humidity\":";
    json += isnan(humidity) ? "null" : String(humidity, 1);
    json += "}";

    // Send HTTP response with correct headers
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.print("Content-Length: ");
    client.println(json.length());
    client.println("Connection: close");  // Make sure to close
    client.println();  // End of headers

    client.print(json);
    client.flush();

  // Check whether GPIO16 is closed
  } else if (request.indexOf("/ispoweron") != -1) {
    int status = is_OCTO_Closed() == true ? 1 : 0;

    // Create JSON payload
    String json = "{";
    json += "\"status\":";
    json += String(status);
    json += "}";

    // Send HTTP response with correct headers
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.print("Content-Length: ");
    client.println(json.length());
    client.println("Connection: close");  // Make sure to close
    client.println();  // End of headers

    client.print(json);
    client.flush();
  // Control Servo
  } else if (request.indexOf("/hit") != -1) {
    Serial.println("Moving to 0°");
    myservo.write(0);   // Move to 0°
    delay(1000);
    Serial.println("Moving to 180°");
    myservo.write(180);   // Move to 0°

  // Unknown request
  } else {
    client.println("HTTP/1.1 404 Not Found");
    client.println("Content-Type: text/plain");
    client.println(); client.println("Not Found");
  }

  delay(1000);
  client.stop();
}

void loop() {
  handleClient();
}



// #include <ESP8266WiFi.h>
// #include <DHT.h>

// #define DHTPIN 5           // D1 on NodeMCU
// #define DHTTYPE DHT11
// DHT dht(DHTPIN, DHTTYPE);

// // WiFi credentials
// const char* ssid = "Xiaomi_BE60";
// const char* password = "phong5032";

// WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);
//   dht.begin();

//   WiFi.begin(ssid, password);
//   Serial.print("Connecting");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500); Serial.print(".");
//   }

//   Serial.println("\nConnected. IP: " + WiFi.localIP().toString());
//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (!client) return;

//   // Wait until the client sends some data
//   Serial.println("📡 Client connected");
//   unsigned long timeout = millis();
//   while (!client.available() && millis() - timeout < 1000) {
//     delay(10);
//   }

//   if (!client.available()) {
//     Serial.println("❌ Client timeout");
//     client.stop();
//     return;
//   }

//   // Read full request
//   String req = client.readStringUntil('\r');
//   Serial.println("Request: " + req);
//   client.flush();

//   if (req.indexOf("GET /weather") != -1) {
//     float temp = dht.readTemperature();
//     float hum = dht.readHumidity();

//     // ✅ Proper HTTP response
//     client.println("HTTP/1.1 200 OK");
//     client.println("Content-Type: application/json");
//     client.println("Connection: close");
//     client.println("Access-Control-Allow-Origin: *");
//     client.println(); // End of headers

//     // JSON body
//     client.print("{\"temperature\":");
//     client.print(isnan(temp) ? "null" : String(temp, 1));
//     client.print(",\"humidity\":");
//     client.print(isnan(hum) ? "null" : String(hum, 1));
//     client.println("}");

//   } else {
//     // 404 Not Found
//     client.println("HTTP/1.1 404 Not Found");
//     client.println("Content-Type: text/plain");
//     client.println("Connection: close");
//     client.println();
//     client.println("Not Found");
//   }

//   delay(1); // Small delay before closing
//   client.stop();
//   Serial.println("✅ Response sent, client disconnected");
// }





