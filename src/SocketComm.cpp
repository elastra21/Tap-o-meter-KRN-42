#include "SocketComm.h"

void SocketIO::loop(){
  webSocket.loop();
}

void SocketIO::connect(const char *ip){
  webSocket.begin(ip, PORT);
}

void SocketIO::redeemBeer(String client_id, String keg_id){
  webSocket.emit(REDEEM_BEER, ("{ \"clientId\":\"" + client_id + "\", \"kegId\":\"" + keg_id + JSON_END).c_str());
}

bool SocketIO::isConnected(){
  return webSocket.connected;
}

void SocketIO::requestLineData(){
  webSocket.emit(SET_UP, set_up.c_str());
}

void SocketIO::on(const char* event, std::function<void (const char * payload, size_t length)> func){
  webSocket.on(event, func);
}

void SocketIO::registerPurchase(String client_id, String worker_id, String concept, String qty, String keg_id){
  const String data = "{ \"workerId\":\"" + worker_id + "\", \"kegId\":\"" + keg_id + "\", \"concept\":\"" + concept + "\", \"qty\": \"" + qty;
  const String client = (client_id.length() > 0 ? "\", \"clientId\": \"" + client_id : "");
  webSocket.emit(SALE_COMPLETE, (data + client + JSON_END).c_str());
}

void SocketIO::setConfigString(String line_id){
  set_up = "{ \"id\": \"" + line_id + JSON_END;
}

String SocketIO::getConfigString(){
  return set_up;
}

void SocketIO::fetchCardId(String card_id, bool client){
  webSocket.emit(client ? GET_CLIENT : GET_WORKER, ("{\"cardId\":\"" + card_id + JSON_END).c_str());
}

// JsonObject SocketIO::decodeJson(const char * payload){
//   JsonObject json_response = JsonObject();
//   DynamicJsonDocument doc (1024);
//   auto error = deserializeJson(doc, payload);
//   if (error) {
//     Serial2.print(F("deserializeJson() failed with code "));
//     Serial2.println(error.c_str());
//   }
//   json_response = doc.as<JsonObject>();
//   doc.clear();
//   return json_response;
// }

// bool SocketIO::validateJsonResponse(JsonObject json_response){
//   const char* confirmation = json_response["confirmation"];
//   return strcmp(confirmation, "success") == 0;
// }