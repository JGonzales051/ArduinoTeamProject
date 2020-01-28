/* Programmer(s): Andrew Gowan Jeremiah Gonzales
   Date:1/7/20
   Program: Traffic Light Simulator
*/

#define sensorPin  A0
#define greenLED 8
#define yellowLED 9
#define redLED 10

void setup()
{
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  Serial.print(voltage); Serial.print(" volts  -  ");
  Serial.print(temperatureC); Serial.print(" degrees C  -  ");
  Serial.print(temperatureF); Serial.println(" degrees F");

  if (temperatureF >= 90) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else if (temperatureF >= 80 && temperatureF < 90) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }

  delay(100);
}
