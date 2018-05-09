#include <M5Stack.h>

// the setup routine runs once when M5Stack starts up
void setup(){

  // Initialize the M5Stack object
  M5.begin();

  // LCD display
  uint8_t mac[6];
  esp_efuse_mac_get_default(mac);
  M5.Lcd.printf("MAC Address = %02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

// the loop routine runs over and over again forever
void loop() {

}
