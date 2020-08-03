/*

   Arup IoT Workshop

*/

#include "universal-mqtt.h"
#include <TimeLib.h>

#define PUBLISH_DELAY 10000

int analoguePin = 32;
unsigned long lastMillis = 0;
const int led = 33;

void setup() {
  pinMode (led, OUTPUT);
  Serial.begin(115200);
  setupCloudIoT();
  digitalWrite(led, 1);
}

void loop() {
  mqttClient->loop();
  delay(10);  // wait a little to improve WiFi stability

  if (!mqttClient->connected()) {
    connect();
  }

  // publish a message roughly every PUBLISH_DELAY ms.
  if (millis() - lastMillis > PUBLISH_DELAY) {
    digitalWrite(led, 1);
    lastMillis = millis();

    int reading  = analogRead(analoguePin);
    char ts[26];
    int t = time(nullptr);
    sprintf(ts, "%4d-%02d-%02dT%02d:%02d:%02d.000Z", 
            year(t), 
            month(t), 
            day(t), 
            hour(t),
            minute(t), 
            second(t));

    // UDMI format example
    // {"version":1,"timestamp":"2019-01-17T14:02:29.364Z","points":{"illuminance_sensor":{"present_value":1023}}}'
    String payload = String("{\"version\":") + 1 +
                     String(",\"timestamp\":\"") + ts +
                     String("\",\"points\":{\"illuminance_sensor\":{\"present_value\":") + reading +
                     String("}}}");
                     
    Serial.println(payload);
    publishTelemetry(payload);
    digitalWrite(led, 0);
  }
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}
