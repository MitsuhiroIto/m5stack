#include <M5Stack.h>
#include "utility/DHT12.h"
#include <Wire.h>     //The DHT12 uses I2C comunication.
DHT12 dht12;          //Preset scale CELSIUS and ID 0x5c.

/*
For configuration library:
DHT12 dht12("Scale temperature","ID device for I2C");
On "Scale temperature" you can select the preset scale:
CELSIUS, FAHRENHEIT or KELVIN.
And on "ID device", you can put ID sensor, on DHT12
normally is 0x5c.
Examples:
  DHT12 dht12;
The preset scale is CELSIUS and ID is 0x5c.
  DHT12 dht12(KELVIN);
the preset scale is KELVIN and ID is 0x5c.
  DHT12 dht12(FAHRENHEIT,0x53);
The preset scale is FAHRENHEIT and ID is 0x53.
*/

void setup() {
  M5.begin();
  Wire.begin();
  
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
  
  Serial.println("Prueba de libreria DHT12:");
//  M5.Lcd.println("Prueba de libreria DHT12:");
}

void loop() {
  //Read temperature and humidity with preset scale.
  float temp = dht12.readTemperature();
  float humid = dht12.readHumidity();
  
  Serial.print("Temperatura: ");
//  M5.Lcd.print("Temperatura: ");
  Serial.print(temp);
//  M5.Lcd.print(temp);

  Serial.print("*C  Humedad: ");
//  M5.Lcd.print("*C  Humedad: ");
  Serial.print(humid);
//  M5.Lcd.println(humid);
  
  int xpos = 140;
  M5.Lcd.drawFloat(temp, 1, xpos, 50, 7);
  M5.Lcd.drawString("Temp : ", xpos-100, 50, 4);
  M5.Lcd.drawString("C", xpos+120, 78, 4);
  M5.Lcd.drawFloat(humid, 1, xpos, 150, 7);
  M5.Lcd.drawString("Humid : ", xpos-100, 150, 4);
  M5.Lcd.drawString("%", xpos+120, 178, 4);

  delay(1000);
}
