#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

struct DHT11_data {
  float temperatura;
  float humedad;
};


DHT11_data read_DHT11_data();

DHT11_data data;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  data = read_DHT11_data();

  Serial.print("Humedad: ");
  Serial.println(data.humedad);
  Serial.print("Temperatura: ");
  Serial.println(data.temperatura);

  delay(1000); 
}

DHT11_data read_DHT11_data() {
  DHT11_data data;
  data.temperatura = dht.readTemperature();
  data.humedad = dht.readHumidity();
  return data;
}