#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#include <LoRa.h>
#define ss 5
#define rst 15
#define dio0 2
int Solenoid = 34;
String A;
int C=0;
String B[4];
float AA2;
float AA3;
float AA4;
float AA5;
//float CC[4];
char auth[] = "yeiyxhd8qCsjRqucjoMEgJKL6WD-Tyy9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LPNATTO_2.4G"; /* name wifi */
char pass[] = "Nattpong209";  /* password wifi */

#define SensorPin1 36
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "none";
}

void setup() {
  Serial.begin(115200);
  while (!Serial);
  LoRa.setPins(ss, rst, dio0);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Blynk.begin(auth, ssid, pass);
  pinMode(Solenoid, OUTPUT);
}

void loop() {
  // try to parse packet
  AA2=0;
  AA3=0;
  AA4=0;
  AA5=0;
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); 
      int index = 0;
      String data_Array[25];
      while(true)
      {
        String split_data = getValue(LoRaData,'/',index);
        if(split_data.indexOf("none") == 0)
        {
          break;
        }
        data_Array[index++] = split_data;
      }
      if(index > 3)
      {
        AA2 = atof(data_Array[0].c_str());
        AA3 = atof(data_Array[1].c_str());
        AA4 = atof(data_Array[2].c_str());
        AA5 = atof(data_Array[3].c_str());
    
        Serial.println(AA2);
        Serial.println(AA3);
        Serial.println(AA4);
        Serial.println(AA5);

  Blynk.virtualWrite(36,AA2); //ค่าsensorตัวที่ 1
  Blynk.virtualWrite(39,AA3); //ค่าsensorตัวที่ 2
  Blynk.virtualWrite(32,AA4); //ค่าsensorตัวที่ 3
  Blynk.virtualWrite(33,AA5); //ค่าsensorตัวที่ 4
  Blynk.virtualWrite(34,Solenoid); //เปิดปิดวาล์น้ำ
      }
    }

    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  
  }
  Blynk.run();
 // if (AA2>=80){
//      digitalWrite(Solenoid, HIGH);   // turn the Solenoid on (HIGH is the voltage level)    
 //     Blynk.virtualWrite(V20, 1);    
//      delay(1000*3600);
 // }
 // else if(AA2<=50){
 //     digitalWrite(Solenoid, LOW);   // turn the Solenoid of (HIGH is the voltage level)
 //     Blynk.virtualWrite(V20, 0);
 //     delay(1000*3600); 
  }
  
  
}
