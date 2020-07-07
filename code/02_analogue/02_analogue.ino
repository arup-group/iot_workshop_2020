/*
 * 
 * Arup IoT Workshop
 * 
 */

int analoguePin = 2;
int delayInterval = 1000;

void setup() 
{
  Serial.begin(115200);  
}

void loop() 
{
  int reading  = analogRead(analoguePin);
  Serial.println(reading);
  delay(delayInterval);
}
