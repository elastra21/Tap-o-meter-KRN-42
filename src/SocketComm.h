#ifndef MY_SOCKET_H
#define MY_SOCKET_H
#include <Arduino.h>
#include "secrets.h"
#include <ArduinoJson.h>
#include <SocketIoClient.h>

#define JSON_END        "\"}"

// ------------------------------>Socket Handlers <------------------------------
#define VALIDATED_USER      "validated user"
#define CONNECT             "connect"
#define DISCONNECT          "disconnect"
#define DEVICE_INFO         "device info"
#define CHANGE_LINE         "changeLine"
#define DISCONNECTED_LINE   "disconnectedLine"
#define ADD_EMERGENCY_CARD  "addEmergencyCard"
#define VALIDATED_CLIENT    "validated client"
#define CLAIM_BEER          "claimBeer"
#define REMOTE_SELL         "remoteSell"

// ------------------------------>  Socket events <------------------------------
#define REDEEM_BEER         "redeemBeer"
#define SET_UP              "setUp"
#define GET_WORKER          "getWorker"
#define GET_CLIENT          "getClient"
#define SALE_COMPLETE       "sale_complete"


class SocketIO {
  struct response{
    String worker_id;
    String worker_name;
  };
  
  public:
    void loop();
    bool isConnected();
    void requestLineData();
    String getConfigString();
    void connect(const char * ip);
    void setConfigString(String line_id);
    JsonObject decodeJson(const char * payload);
    void redeemBeer(String client_id, String keg_id);
    bool validateJsonResponse(JsonObject json_response);
    void fetchCardId(String card_id, bool client = false);
    void on(const char* event, std::function<void (const char * payload, size_t length)> func);
    void registerPurchase(String client_id, String worker_id, String concept, String qty, String keg_id);
  private:
    SocketIoClient webSocket;
    String set_up = "";
};
#endif