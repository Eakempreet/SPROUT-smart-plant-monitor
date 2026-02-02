#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "DFRobot_DHT11.h"
#include <Servo.h>

/*
  ============================
  WiFi & Cloud Configuration
  ============================
  NOTE:
  - Replace these placeholders with your own credentials
  - Do NOT hardcode secrets in public repositories
*/

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* host = "api.thingspeak.com";
const char* writeAPIKey = "YOUR_THINGSPEAK_API_KEY";

// ============================
// Sensors & Actuators
// ============================

DFRobot_DHT11 DHT;
Servo servoMotor;

// Pin configuration (ESP8266)
int dhtPin = D2;
int moisturePin = A0;
int irSensorPin = D5;
int buzzerPin = D7;
int ledPin = D8;
int servoPin = D6;

// Soil moisture threshold (adjust after calibration)
int moistureThreshold = 500;

void setup() {
  Serial.begin(9600);

  // Configure input/output pins
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Ensure actuators start in a safe state
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  // Attach servo and set neutral position
  servoMotor.attach(servoPin);
  servoMotor.write(90);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
}

void loop() {
  // Read temperature and humidity from DHT11
  DHT.read(dhtPin);
  int temperature = DHT.temperature;
  int rh = DHT.humidity;

  // Read soil moisture and IR sensor
  int moistureValue = analogRead(moisturePin);
  int irState = digitalRead(irSensorPin);

  // Calculate absolute humidity (g/m³)
  float absHumidity = 0.0;

  if (temperature > 0 && rh > 0) {
    float temp = float(temperature);
    float relHumidity = float(rh);

    float es = 6.112 * exp((17.67 * temp) / (temp + 243.5));
    absHumidity = (es * relHumidity * 2.1674) / (273.15 + temp);
  }

  // Debug output to Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Abs Humidity: ");
  Serial.print(absHumidity, 2);
  Serial.print(" g/m³ | Soil: ");
  Serial.print(moistureValue);
  Serial.print(" | IR: ");
  Serial.println(irState);

  // LED alert when soil moisture is low
  digitalWrite(ledPin, moistureValue < moistureThreshold ? HIGH : LOW);

  // Intruder detection logic
  if (irState == LOW) {
    digitalWrite(buzzerPin, HIGH);

    // Servo movement pattern for deterrence
    for (int i = 0; i < 2; i++) {
      servoMotor.write(0);   delay(300);
      servoMotor.write(90);  delay(300);
      servoMotor.write(180); delay(300);
      servoMotor.write(90);  delay(300);
    }
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    String url = "http://";
    url += host;
    url += "/update?api_key=" + String(writeAPIKey);
    url += "&field1=" + String(moistureValue);
    url += "&field2=" + String(temperature);
    url += "&field3=" + String(absHumidity, 2);
    url += "&field4=" + String(irState);

    http.begin(client, url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.println("Data sent to ThingSpeak");
    } else {
      Serial.print("HTTP Error: ");
      Serial.println(httpCode);
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  // ThingSpeak allows one update every 15 seconds
  delay(15000);
}
