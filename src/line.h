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

struct pouringLog {
  String user;
  uint16_t pulses;
  uint16_t poured_pulses;
};

#define DEFAULT_PPM 2.0
#define PPM_ADDRESS 1
#define EMERGENCY_CARD_ADDRESS 32
#define MEM_SPACE 512

class Line {
  public:
    bool isConnected(); 
    void closeLogFile();
    bool theresNoInfo();
    bool isDisconnected();
    String getInfoFromSF();
    void deletePouringLog();
    float getPPMFromMemory();
    void savePPM( float ppm );
    lineStatus getLineStatus();
    void saveInfo(String data);
    pouringLog getPouringLog();
    bool theresNoFinishedLog();
    String getEmergencyCardFromMemory();
    void setLineStatus(lineStatus status);
    void savePouredPulses(uint16_t pulses);
    bool compareEmergencyCard(String card_id);
    void saveEmergencyCard(const char * payload);
    void initPouringLog(String user, uint16_t pulses);
  private:
    File logFile;
    Preferences preferences;
    lineStatus line_status = NO_INFO;
};
#endif