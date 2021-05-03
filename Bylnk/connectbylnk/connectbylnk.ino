/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>



// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "yeiyxhd8qCsjRqucjoMEgJKL6WD-Tyy9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LPNATTO_2.4G";
char pass[] = "Nattpong209";

#define SensorPin1 A0  // used for ESP32
#define SensorPin2 39
#define SensorPin3 32
#define SensorPin4 33
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  
  
  float sensorValue1 = analogRead(SensorPin1);
  Serial.print("Temperature1:  ");
  Serial.println(sensorValue1);
  Blynk.virtualWrite(A0, sensorValue1/100+60);
  delay(1000);

  float sensorValue2 = analogRead(SensorPin2);
  Serial.print("Temperature2:  ");
  Serial.println(sensorValue2);
  Blynk.virtualWrite(39, sensorValue2);
  delay(1000);

  float sensorValue3 = analogRead(SensorPin3);
  Serial.print("Temperature3:  ");
  Serial.println(sensorValue3);
  Blynk.virtualWrite(32, sensorValue3);
  delay(1000);

  float sensorValue4 = analogRead(SensorPin4);
  Serial.print("Temperature4:  ");
  Serial.println(sensorValue4);
  Blynk.virtualWrite(33, sensorValue4);
  delay(1000);

  Blynk.run();
}
