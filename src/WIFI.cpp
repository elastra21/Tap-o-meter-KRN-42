#include "WIFI.h"
#include "WiFiType.h"

bool WIFI::setUpWiFi(uint8_t max_tries){
  WiFi.begin();
  uint8_t notConnectedCounter = 0;
  bool connection_state = true;
  Serial2.println("WiFi Connecting...");
  // EEPROM.begin(512); 
  preferences.begin("my-app", false);
  while (!isConnected() && connection_state) {
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial2.print(".");  
    notConnectedCounter++;
    if(notConnectedCounter > 3) { // Reset board if not connected after 5s
      Serial2.println("Resetting due to WiFi not connecting...");
      // uint8_t num_of_tries = EEPROM.readInt(WIFI_RETRIES_ADD);
      uint8_t num_of_tries = preferences.getInt("wifi_retries", 0);
      Serial2.println(num_of_tries);
      if (num_of_tries == max_tries) connection_state = false;
      else {
        preferences.putInt("wifi_retries", num_of_tries + 1);
        preferences.end();
        // EEPROM.writeInt(WIFI_RETRIES_ADD, num_of_tries + 1);
        // EEPROM.commit();
        // EEPROM.end();
        ESP.restart();          
      }
    }
  }

  preferences.putInt("wifi_retries", 0);
  preferences.end();
  // EEPROM.writeInt(WIFI_RETRIES_ADD, 0);
  // EEPROM.commit();
  // EEPROM.end();

  if(connection_state) {
    startMDNS();
    Serial2.println("Connected");
  }
  return connection_state;
}

void WIFI::setUpOTA(uint8_t tap_number){
    String formated_name = "Tap-o-meter#";
    formated_name += tap_number > 0 ? tap_number : random(255);
    ArduinoOTA.setHostname(formated_name.c_str());
    ArduinoOTA.onStart([]() {
    String type;
    type = ArduinoOTA.getCommand() == U_FLASH ? "sketch" : "filesystem";
      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial2.println("Start updating " + type);
    }).onEnd([]() {
      Serial2.println("\nEnd");
    }).onProgress([](unsigned int progress, unsigned int total) {
      Serial2.printf("Progress: %u%%\r", (progress / (total / 100)));
    }).onError([](ota_error_t error) {
      Serial2.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial2.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial2.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial2.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial2.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial2.println("End Failed");
    });
    ArduinoOTA.begin();
}

void WIFI::loopOTA(){
  ArduinoOTA.handle();
}

void WIFI::startMDNS(){
  if (!MDNS.begin("tap-o-meter")) {
        Serial2.println("Error setting up MDNS responder!");
        while(1) vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

String WIFI::getIP(){
  String ip = MDNS.queryHost("tom-server").toString();
  Serial2.println(ip);
  return ip;
}

bool WIFI::theresValidSSID(){
  return wifiManager.getSsid().length() > 2;
}

void WIFI::resetWiFiSettings(){
  wifiManager.resetSettings(); 
}

void WIFI::reconnect(bool not_blocking){
  if (not_blocking){
    Serial2.print(".");
    if (retry_connection_in < millis() || retry_connection_in == 0){
      WiFi.begin();
      Serial2.println("Thick");
      retry_connection_in = millis() + RETRY_TIME;
    }
  }
  else {
    WiFi.begin();
    // uint8_t timeout = 0;
    // vTaskDelay( 2000 );

    while ( WiFi.status() != WL_CONNECTED ){
      vTaskDelay(2000 / portTICK_PERIOD_MS);
      // vTaskDelay( 2000 );
      log_i(" waiting on wifi connection" );
      // timeout++;
      // if (timeout == 2) return;
    }
  }
  
}

void WIFI::stopOTA(){
  ArduinoOTA.end();
}

bool WIFI::isConnected(){
  return WiFi.status() == WL_CONNECTED;
}

String WIFI::macAddress(){
  return WiFi.macAddress();
}

