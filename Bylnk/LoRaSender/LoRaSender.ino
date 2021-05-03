#include <SPI.h>
#include <LoRa.h>


int counter = 0;
#define ss 5
#define rst 15
#define dio0 2
#define SensorPin1 36
#define SensorPin2 39
#define SensorPin3 32
#define SensorPin4 33

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Sender");
   LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int sensorValue1 = map(analogRead(SensorPin1), 1024, 250, 0 ,100);
  Serial.print("Temperature1:  ");
  Serial.println(sensorValue1);
  delay(1000);

  int sensorValue2 = map(analogRead(SensorPin2), 1024, 250, 0 ,100);
  Serial.print("Temperature2:  ");
  Serial.println(sensorValue2);
  delay(1000);

  int sensorValue3 = map(analogRead(SensorPin3), 1024, 250, 0 ,100);
  Serial.print("Temperature3:  ");
  Serial.println(sensorValue3);
  delay(1000);

  int sensorValue4 = map(analogRead(SensorPin4), 1024, 250, 0 ,100);
  Serial.print("Temperature4:  ");
  Serial.println(sensorValue4);
  delay(1000);
  
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.println(((String)sensorValue1+'/'+(String)sensorValue2+'/'+(String)sensorValue3 +'/' +(String) sensorValue4));
  LoRa.endPacket();

  

  delay(10000);
}
