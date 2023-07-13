#include "Line.h"

bool Line::theresNoInfo(){
  return line_status == NO_INFO;
}

bool Line::isConnected(){
  return line_status == CONNECTED;
}

bool Line::isDisconnected(){
  return line_status == DISCONNECTED;
}

lineStatus Line::getLineStatus(){
  return line_status;
}

void Line::setLineStatus(lineStatus status){
  line_status = status;
}

void Line::saveInfo(String data){
  File f = SPIFFS.open(INFO_FILE, "w");
  if (f) {
    f.print(data);
    f.close();
  }
}

float Line::getPPMFromMemory(){
  // float ppm = 0.0;
  // EEPROM.begin(MEM_SPACE);
  // ppm = EEPROM.readFloat(PPM_ADDRESS);
  // const bool is_valid = !isnan(ppm);
  // EEPROM.end();
  // if (!is_valid) savePPM(DEFAULT_PPM);
  // return is_valid ? ppm : DEFAULT_PPM; 
  preferences.begin("my-app", false);
  float ppm = preferences.getFloat("ppm", DEFAULT_PPM);
  preferences.end();
  return ppm;
}

String Line::getInfoFromSF(){
  if (SPIFFS.exists(INFO_FILE)) {
    File f = SPIFFS.open(INFO_FILE, "r");
    if (f) {
      String stored_data;
      stored_data = f.readString();
      // Serial2.print(stored_data);
      f.close();
      setLineStatus(CONNECTED);
      return stored_data;
    } else { // I should find the way to catch this.
      return "";
    }
  } else { // I should find the way to catch this.
      return "";
    } 
}

void Line::savePPM( float ppm ){
  Serial2.println(ppm);
  // EEPROM.begin(MEM_SPACE);
  // EEPROM.writeFloat(PPM_ADDRESS, ppm);
  // EEPROM.commit();
  // EEPROM.end();
  preferences.begin("my-app", false);
  preferences.putFloat("ppm", ppm);
  preferences.end();
}

void Line::saveEmergencyCard(const char * emergency_card){
  // EEPROM.begin(MEM_SPACE);
  // EEPROM.writeString(EMERGENCY_CARD_ADDRESS, emergency_card);
  // EEPROM.commit();
  // EEPROM.end();
  preferences.begin("my-app", false);
  preferences.putString("emergency_card", emergency_card);
  preferences.end();
}

String Line::getEmergencyCardFromMemory(){
  // EEPROM.begin(MEM_SPACE);
  // const String emergency_card_id = EEPROM.readString(EMERGENCY_CARD_ADDRESS);
  // EEPROM.end();
  // return emergency_card_id;
  preferences.begin("my-app", false);
  const String emergency_card_id = preferences.getString("emergency_card", "");
  preferences.end();
  return emergency_card_id;
}

bool Line::compareEmergencyCard(String card_id){
  const String emergency_card = getEmergencyCardFromMemory();
  return emergency_card.equals(card_id);
}