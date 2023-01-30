#include <DHT.h>;

#define dhtPIN 7
#define dhtTYPE DHT22
DHT dht(dhtPIN, dhtTYPE);

float hum;
float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  checkData();
}

void checkData() {
  delay(2000);
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.println(String("Humidity: ") + hum + String(" %"));
  Serial.println(String("Temp: ") + temp + String(" Celsius"));
  Serial.println("-------------------------------");
  delay(2000);
}
  