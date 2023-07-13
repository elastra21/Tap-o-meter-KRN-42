#ifndef MY_READER_H
#define MY_READER_H
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <ArduinoJson.h>
#include "Screen.h"
#include <SocketIoClient.h>



struct newWorker {
  String id; 
  String name; 
};

struct newClient {
  String id; 
  String name;
};

class Reader {
  private:
    // ----------> this should be remove after implement the structs <---------
    newClient vip_client;
    newWorker worker;
    String user;
    String client;
    String workerId;
    String clientId;

    MFRC522 mfrc522;
    bool emergency = false;
  public:
    bool on();
    void init();
    String getUser();
    void removeUser();
    bool theresUser();
    Reader(byte,byte);
    String getClient();
    void setEmergency();
    bool theresClient();
    bool isOnEmergency();
    String getClientId();
    String getWorkerId();
    String getCardString();
    void setUser(String, String);
    void setClient(String, String);
    String getEmergencyCard(const char * payload);
};
#endif
