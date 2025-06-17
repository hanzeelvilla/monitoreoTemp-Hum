#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define DIRECCION_LCD 0x27
#define COLUMNAS 16
#define FILAS 2

struct DHT11_data {
  float temperatura;
  float humedad;
};


DHT11_data read_DHT11_data();
void print_DHT11_data_lcd(const DHT11_data* data);
void print_DHT11_data_serial(const DHT11_data* data);

DHT11_data data;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(DIRECCION_LCD, COLUMNAS, FILAS);

void setup() {
  Serial.begin(115200);
  dht.begin();

  lcd.init();
  lcd.backlight();
}

void loop() {
  data = read_DHT11_data();

  print_DHT11_data_lcd(&data);
  //print_DHT11_data_serial(&data);

  delay(1000); 
}

DHT11_data read_DHT11_data() {
  DHT11_data data;
  data.temperatura = dht.readTemperature();
  data.humedad = dht.readHumidity();
  return data;
}

void print_DHT11_data_lcd(const DHT11_data* data) {
  lcd.setCursor(0, 0);
  lcd.print("Tem: ");
  lcd.print(data->temperatura);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(data->humedad);
  lcd.print("%"); 
}

void print_DHT11_data_serial(const DHT11_data* data) {
  Serial.print("Humedad: ");
  Serial.println(data->humedad);
  Serial.print("Temperatura: ");
  Serial.println(data->temperatura);
}