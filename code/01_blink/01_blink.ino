/***
 * 
 * Arup IoT Workshop
 * 
 */

const int ledPin = 5;
const int delayInterval = 2000;

void setup() {
  pinMode (ledPin, OUTPUT);
}

void loop() {
  digitalWrite (ledPin, HIGH);
  delay(delayInterval);
  digitalWrite (ledPin, LOW);
  delay(delayInterval);
}
