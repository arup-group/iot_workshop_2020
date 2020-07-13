/*
 * 
 * Arup IoT Workshop
 * 
 */

#include "universal-mqtt.h"

#define PUBLISH_DELAY 10000

int analoguePin = 32;
unsigned long lastMillis = 0;

void setup() {
  Serial.begin(115200);
  setupCloudIoT();
}

void loop() {
  mqttClient->loop();
  delay(10);  // wait a little to improve WiFi stability

  if (!mqttClient->connected()) {
    connect();
  }

  // publish a message roughly every PUBLISH_DELAY ms.
  if (millis() - lastMillis > PUBLISH_DELAY) {
    lastMillis = millis();

    int reading  = analogRead(analoguePin);
    Serial.println(reading);

    String payload = String("{\"timestamp\":") + time(nullptr) +
                     String(",\"reading\":") + reading +
                     String("}");
    publishTelemetry(payload);
  }
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}
