#ifndef MY_LINE_H
#define MY_LINE_H
#include <Arduino.h>
#include "secrets.h"
#include "SPIFFS.h"
#include <EEPROM.h>
#include <Preferences.h>

enum lineStatus {
    NO_INFO,
    DISCONNECTED,   
    CONNECTED      
};

#define DEFAULT_PPM 2.0
#define PPM_ADDRESS 1
#define EMERGENCY_CARD_ADDRESS 32
#define MEM_SPACE 512

class Line {
  public:
    bool theresNoInfo();
    bool isConnected(); 
    bool isDisconnected();
    String getInfoFromSF();
    float getPPMFromMemory();
    void savePPM( float ppm );
    lineStatus getLineStatus();
    void saveInfo(String data);
    String getEmergencyCardFromMemory();
    void setLineStatus(lineStatus status);
    bool compareEmergencyCard(String card_id);
    void saveEmergencyCard(const char * payload);
  private:
    Preferences preferences;
    lineStatus line_status = NO_INFO;
};
#endif