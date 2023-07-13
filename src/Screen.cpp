#include "Screen.h"
// #include <JPEGDecoder.h>


Screen::Screen(){

}
void Screen::init(){

}

bool Screen::isTouchEneable(){
  return touch_eneable;
}

void  Screen::setTouchEneable(bool value){
  touch_eneable = value;
}

void Screen::drawInfo() {
  // tft.fillRect(0, 0, 320, 105, TFT_BLACK);
  // tft.setTextDatum(TL_DATUM);
  // tft.setTextColor(TFT_WHITE, TFT_BLACK);
  // //tft.loadFont("Helvetica-Light-44");
  // tft.setFreeFont(&Roboto_Light_44);
  // const String suffix = beerName.length() > 12 ? "..." : "";
  // tft.drawString(beerName.substring(0,12) + suffix ,8,2);
  // //tft.unloadFont();
  // tft.setFreeFont(&FreeSans12pt7b);
  // tft.drawString(beerStyle,10,50);
  // tft.setFreeFont(&FreeSans18pt7b);
  // tft.drawString(beerAbv+"%",10,75);
}

void Screen::clearScreen(){
  // //tft.fillScreen(TFT_BLACK);
  // tft.fillRect(0, 105, 320, 480, TFT_BLACK);
  // tft.setTextSize(1);
}
void Screen::partialClear(){
  // tft.fillRect(0, STATUS_Y, 320, 480, TFT_BLACK);
}

void Screen::LockScreen(){
  actualScreen=LOCK_SCR;
  Serial2.println("Lock Screen.  Pasar tarjeta");
  entryOptions.push_back(cog);
  Serial2.println("1.- Configuracion");
  // if (actualScreen < 7) {
  //   clearScreen();
  //   drawInfo();
  // }
  // else if(actualScreen == LOCK_SCR){
  //   drawInfo();
  // }
  // else {
  //    tft.setTextColor(TFT_WHITE, TFT_BLACK);
  //    partialClear();
  //  }
  //  actualScreen=LOCK_SCR;
  //  currentScreen = "LOCK_SCR";
  //  fex.drawJpgFile(SPIFFS, "/3.jpg", 60, 150);
  //  tft.setFreeFont(&FreeSans12pt7b);
  //  tft.setTextDatum(TC_DATUM);
  //  tapCard();
  //  key[11].initButton(&tft, 290, 442, 40, 40, TFT_BLACK, TFT_BLACK,TFT_BLACK, "cog",  1, LOCK_SCR, 0 , false);
  //  key[11].drawButton();
  //  fex.drawJpgFile(SPIFFS, "/cog.jpg", 275, 427);
}
void Screen::setInfo(const char * info) {
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, info);
  JsonObject obj = doc.as<JsonObject>();
    beerName = obj["name"].as<String>();
  beerStyle = obj["style"].as<String>();
  beerAbv =  obj["abv"].as<String>();
  kegId = obj["idKeg"].as<String>();
  noLinea = obj["noLinea"].as<uint16_t>();
  emergencyCard = obj["emergencyCard"].as<String>();
}

void Screen::SelectQty(String user, String client) {
  entryOptions.push_back(Vaso);
  entryOptions.push_back(Taster);
  entryOptions.push_back(Growler);
  entryOptions.push_back(Mermar);
  entryOptions.push_back(Cancelar);
  Serial2.println("Seleccionar qty");
  Serial2.println("1.- Vaso");
  Serial2.println("2.- Taster");
  Serial2.println("3.- Growler");
  Serial2.println("4.- Merma");
  Serial2.println("5.- Cancelar");
  // currentScreen = "SEL_QTY";
  actualScreen = SELECT_QTY;
  // //tft.fillScreen(TFT_BLACK);
  // tft.fillRect(0, 120, 320, 360, TFT_BLACK);
  // tft.setFreeFont(&FreeSans12pt7b);
  // int positionY = 0;
  // for (uint8_t row = 0; row < 4; row++) {
  //     uint8_t b = row;
  //     key[b].initButton(&tft, KEY_X + KEY_SPACING_X + ( row%2 != 0 ? KEY_W + KEY_SPACING_X : 0) , // x, y, w, h, outline, fill, text
  //                       KEY_Y + positionY * (KEY_H + KEY_SPACING_Y),KEY_W, KEY_H,
  //                       0x0253, 0x0253,TFT_WHITE,keyLabel[b], KEY_TEXTSIZE, SELECT_QTY);
  //     key[b].drawButton();
  //     positionY = positionY + (row%2 == 0 ? 0 : 1);
  // }
  // key[4].initButton(&tft, 160, 442, 290, 50, 0xE082, 0xE082,TFT_WHITE, "Cancelar",  KEY_TEXTSIZE, SELECT_QTY);
  // key[4].drawButton();
  // //drawInfo();
  // const String totalinfo = user + (client.length() > 0 ? " -> "+ client : "");
  // status(totalinfo.c_str());
}

void Screen::status(const char *msg) {
  // tft.setTextColor(TFT_WHITE, TFT_BLACK);
  // tft.setTextDatum(TC_DATUM);
  // tft.setFreeFont(&FreeSans9pt7b);
  // tft.drawString(msg, STATUS_X, STATUS_Y);
  // tft.setFreeFont(&FreeSansBold9pt7b);
}
void Screen::touch_calibrate(){
  // uint16_t calData[5] = {311,3472,327,3618,2};
  // uint8_t calDataOK = 0;
  // if (!SPIFFS.begin()) {   // check file system exists
  //   Serial2.println("Formating file system");
  //   SPIFFS.format();
  //   SPIFFS.begin();
  // }
  // if (SPIFFS.exists(CALIBRATION_FILE)) {   // check if calibration file exists and size is correct
  //   if (REPEAT_CAL){
  //     SPIFFS.remove(CALIBRATION_FILE);  // Delete if we want to re-calibrate
  //   }
  //   else {
  //     File f = SPIFFS.open(CALIBRATION_FILE, "r");
  //     if (f) {
  //       // if (f.readBytes((char *)calData, 14) == 14)
  //       if (true)
  //         calDataOK = 1;
  //       f.close();
  //     }
  //   }
  // }

  // if (calDataOK && !REPEAT_CAL) {
  //   tft.setTouch(calData); // calibration data valid
  // } else {
  //   // data not valid so recalibrate
  //   tft.fillScreen(TFT_BLACK);
  //   tft.setCursor(20, 0);
  //   tft.setTextFont(2);
  //   tft.setTextSize(1);
  //   tft.setTextColor(TFT_WHITE, TFT_BLACK);
  //   tft.println("Touch corners as indicated");
  //   tft.setTextFont(1);
  //   tft.println();
  //   if (REPEAT_CAL) {
  //     tft.setTextColor(TFT_RED, TFT_BLACK);
  //     tft.println("Set REPEAT_CAL to false to stop this running again!");
  //   }
  //   tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);
  //   tft.setTextColor(TFT_GREEN, TFT_BLACK);
  //   tft.println("Calibration complete!");
  //   // store data
  //   File f = SPIFFS.open(CALIBRATION_FILE, "w");
  //   if (f) {
  //     f.write((const unsigned char *)calData, 14);
  //     f.close();
  //   }
  // }
}
void Screen::removeInfo(){
  String beerName = "";
  String beerStyle = "";
  String beerAbv = "";
  String kegId = "";
}
uint8_t Screen::isPressed(){
  // uint16_t t_x = 0, t_y = 0; // To store the touch coordinates
  // const boolean pressed = tft.getTouch(&t_x, &t_y);// Pressed will be set true is there is a valid touch on the screen
  // for (uint8_t b = 0; b < 19; b++) { // / Check if any key coordinate boxes contain the touch coordinates
  //   if (pressed && key[b].contains(t_x, t_y)) {
  //     key[b].press(true);  // tell the button it is pressed
  //   } else {
  //     key[b].press(false);  // tell the button it is NOT pressed
  //   }
  // }

  // for (uint8_t b = 0; b < 19; b++) { // Check if any screen.key has changed state
  //   if( actualScreen == (key[b].screen()) ){
  //     if (key[b].justPressed()) {
  //       tft.setFreeFont(&FreeSans12pt7b);
  //         key[b].drawButton(true);
  //     }     // draw normal
  //     if (key[b].justReleased()) {
  //       if (b != 11) {
  //         key[b].drawButton();  // draw invert
  //       }
  //       // return key[b].label();
  //       return b;
  //     }
  //   }
  // }

  if (Serial2.available() > 0) {
    // reading incoming integer from serial port
    const uint8_t index = Serial2.parseInt() -1;
    if (index  >= entryOptions.size()) {
      Serial2.print(index);
      Serial2.println(": Invalid option");
      return NONE;
    }
    
    const int8_t option = entryOptions[index]; 

    entryOptions.clear();
    return option;
  }

  return NONE;
}

void Screen::connecting(){
  actualScreen = CONNECTING_SCR;
  // currentScreen = "CONNECTING";
  // clearScreen();
  // tft.fillScreen(TFT_BLACK);
  // tft.setTextDatum(TC_DATUM);
  // tft.setTextColor(TFT_WHITE);
  // tft.setFreeFont(&FreeSans12pt7b);
  // tft.drawString("CONECTANDO",160,300);
  // fex.drawJpgFile(SPIFFS, "/2.jpg", 60, 90);
  //tft.pushImage(60, 90, wifiWidth, wifiHeight, wifi);
  Serial2.println("Connectando nigga! ");
}

void Screen::AP(String name, bool retriable){
  Serial2.println("This shit it's on AP mode");
  actualScreen = AP_SCR;
  // currentScreen = "AP";
  // tft.fillScreen(TFT_BLACK);
  // tft.setTextDatum(TC_DATUM);
  // tft.setTextColor(TFT_WHITE);
  // tft.setFreeFont(&FreeSans18pt7b);
  // tft.drawString(name,160,70);
  // tft.setFreeFont(&FreeSans12pt7b);
  // tft.drawString("Abre la App para",160,340);
  // tft.drawString("iniciar",160,365);
  // fex.drawJpgFile(SPIFFS, "/1.jpg", 60, 120);
  //tft.pushImage(60, 120, wifi_config_Width, wifi_config_Height, wifi_config);
}

void Screen::hideCancell(){
  // Serial2.println("you cant see me");
  // tft.fillRect(15, 417, 290, 50, TFT_BLACK);
}

void Screen::showReady(){
  // Serial2.println("you shall see");
  // tft.setFreeFont(&FreeSans12pt7b);
  // key[4].initButton(&tft, 160, 442, 290, 50, 0x2E6E, 0x2E6E ,TFT_WHITE, "Listo",  KEY_TEXTSIZE, SERVING_SCR);
  // key[4].drawButton();
  entryOptions.push_back(Listo);
  Serial2.println("1.- Listo");
  // tft.setTextColor(TFT_WHITE, TFT_BLACK);
}

void Screen::notConnectedToSever(){
  Serial2.println("Error en el servidor");
  // tft.setTextColor(TFT_RED, TFT_BLACK);
  // tft.drawString("Error en Servidor",160,430);
}

void Screen::setEmergency(bool state){
  if (!state) error = NO_ERROR;
  emergency_mode = state;
}

bool Screen::isOnEmergency(){
  return emergency_mode;
}

String Screen::getErrorMessage(){
  if (error == WIFI_NOT_CONNECTED){
    return WIFI_NOT_CONNECTED_MSG;
  }
  else if (error == NO_SERVER_CONNECTION){
    return NO_SERVER_CONNECTION_MSG;
  }
  return "Otra cosa sucedio";
}

int8_t Screen::getError(){
  return error;
}

void Screen::setError(int8_t err){
  error = err;
}

void Screen::noWifi(){
  Serial2.println("Paga el wifi jodido");
  // actualScreen = DISCONNECTED_SCR;
  // currentScreen = "DISCONNECTED";
  // tft.fillScreen(TFT_BLACK);
  // tft.setTextDatum(TC_DATUM);
  // tft.setTextColor(TFT_WHITE);
  // tft.setFreeFont(&FreeSans12pt7b);
  // tft.drawString("Sin conexion",160,330);
  // tft.drawString("Reintentando",160,355);
  // fex.drawJpgFile(SPIFFS, "/4.jpg", 60, 90);
  //tft.pushImage(60, 120, wifi_config_Width, wifi_config_Height, wifi_config);
}

void Screen::tapCard(){
  Serial2.println("Acercar tarjeta");
  // tft.fillRect(0, 430, 265, 40, TFT_BLACK);
  // tft.setTextColor(TFT_WHITE, TFT_BLACK);
  // tft.drawString("Acercar Tarjeta",160,430);
}

void Screen::servingScreen(boolean drawIt, uint8_t update, String type){
  actualScreen = SERVING_SCR;
  // currentScreen = "SERVING";
  if (drawIt) {
    isServing = true;
    // tft.fillRect(0, STATUS_Y, 320, 375, TFT_BLACK);
    // tft.setFreeFont(&FreeSans12pt7b);
    // key[4].initButton(&tft, 160, 442, 290, 50, 0xE082, 0xE082,TFT_WHITE, "Cancelar",  KEY_TEXTSIZE, SERVING_SCR);
    // key[4].drawButton();
    // tft.setTextDatum(MC_DATUM);
    // tft.setTextColor(TFT_WHITE, TFT_BLACK);
    // status(type.c_str());
  }
    // tft.setFreeFont(&FreeSans24pt7b);
    Serial2.println((String(update,0)+"%").c_str());
    // fex.fillRoundRect(20, 285, 280, 10, 5, 0x9557);
    // fex.fillRoundRect(20, 285, (update/100)* 280, 10, 5, 0x263B);
}


void Screen::NoBeerAssigned(){
  Serial2.println("No beer assigned");
  actualScreen = NO_BEER_SCR;
  // currentScreen = "NO_BEER";
  // clearScreen();
  // tft.fillScreen(TFT_BLACK);
  // tft.setTextDatum(TC_DATUM);
  // tft.setTextColor(TFT_WHITE);
  // tft.setFreeFont(&FreeSans18pt7b);
  // tft.drawString("Linea desconectada",160,40);
  // fex.drawJpgFile(SPIFFS, "/noBeer.jpg", 60, 120);
  // tft.setFreeFont(&FreeSans12pt7b);
  // tft.drawString("Abre la App para",160,380);
  // tft.drawString("configurar",160,410);
  //tft.pushImage(60, 90, wifiWidth, wifiHeight, wifi);
}

void Screen::mermar(uint16_t ml){
  if (ml == 0) {
    Serial2.println("Mermar");
    isMermando = true;
    // partialClear();
    // // clearScreen();
    // // drawInfo();
    // tft.setFreeFont(&FreeSans12pt7b);
    // key[5].initButton(&tft, 160, 442, 290, 50, 0x2E6E, 0x2E6E, TFT_WHITE, "Listo",  KEY_TEXTSIZE, OPEN_QTY);
    // key[5].drawButton();
    // tft.setTextDatum(MC_DATUM);
    // tft.setTextColor(TFT_WHITE, TFT_BLACK);
  }
    // tft.setFreeFont(&FreeSans24pt7b);
    Serial2.println((String(ml,0)+" ml").c_str());

}

void Screen::drawMl(double ml, bool isMl){
  const String unit = isMl ? " mL" : " pul";
  // tft.setFreeFont(&FreeSans24pt7b);
  Serial2.println((String(ml,0)+unit).c_str());
}

void Screen::hideLoadingModal(){
  loading_modal = false;
}

void Screen::LoadingModal(){
  Serial2.println("Ejperate!");
  actualScreen = LOADING_SCR;
  // currentScreen = "LOADING";
  // unsigned int col[8];
  // col[0] = tft.color565(155, 0, 50);
  // col[1] = tft.color565(170, 30, 80);
  // col[2] = tft.color565(195, 60, 110);
  // col[3] = tft.color565(215, 90, 140);
  // col[4] = tft.color565(230, 120, 170);
  // col[5] = tft.color565(250, 150, 200);
  // col[6] = tft.color565(255, 180, 220);
  // col[7] = tft.color565(255, 210, 240);
  // if (value == 8) tft.fillRoundRect(80, 160, 160, 160, 5, TFT_DARKCYAN);
  // tft.fillCircle(160 + 40 * (cos(-value * PI / 4)), 240 + 40 * (sin(-value * PI / 4)), 10,  col[0]); delay(15);
  // tft.fillCircle(160 + 40 * (cos(-(value + 1)*PI / 4)), 240 + 40 * (sin(-(value + 1)*PI / 4)), 10,  col[1]); delay(15);
  // tft.fillCircle(160 + 40 * (cos(-(value + 2)*PI / 4)), 240 + 40 * (sin(-(value + 2)*PI / 4)), 10,  col[2]); delay(15);
  // tft.fillCircle(160 + 40 * (cos(-(value + 3)*PI / 4)), 240 + 40 * (sin(-(value + 3)*PI / 4)), 10,  col[3]); delay(15);
  // tft.fillCircle(160 + 40 * (cos(-(value + 4)*PI / 4)), 240 + 40 * (sin(-(value + 4)*PI / 4)), 10,  col[4]); delay(15);
  // tft.fillCircle(160 + 40 * (cos(-(value + 5)*PI / 4)), 240 + 40 * (sin(-(value + 5)*PI / 4)), 10,  col[5]); delay(15);
  // tft.fillCircle(160 + 40 * (cos(-(value + 6)*PI / 4)), 240 + 40 * (sin(-(value + 6)*PI / 4)), 10,  col[6]); delay(15);
  // tft.fillCircle(160 + 40 * (cos(-(value + 7)*PI / 4)), 240 + 40 * (sin(-(value + 7)*PI / 4)), 10,  col[7]); delay(15);
}

void Screen::drawError(){
  Serial2.println(getErrorMessage());
  // tft.setTextColor(TFT_RED, TFT_BLACK);
  // tft.drawString(getErrorMessage(),160,430);
}

void Screen::ServeOptionsTaster(){
  Serial2.println("Selecciona Taster");
  actualScreen = TASTER_QTY;
  // currentScreen = "TSTR_QTY";
  // //tft.fillScreen(TFT_BLACK);
  // tft.fillRect(0, 120, 320, 360, TFT_BLACK);
  // tft.setFreeFont(&FreeSans12pt7b);
  entryOptions.push_back(Oz_2);
  entryOptions.push_back(Oz_5);
  entryOptions.push_back(Cancelar);
  Serial2.println("1.- 2 Oz");
  Serial2.println("2.- 5 Oz");
  Serial2.println("3.- Cancelar");
  // key[6].drawButton();
  // key[7].drawButton();
  // key[4].drawButton();
  //drawInfo();
}

void Screen::ServeOptionsGlass(){
  Serial2.println("Selecciona vaso");
  actualScreen = PINT_QTY;
  // currentScreen = "GLSS_QTY";
  // //tft.fillScreen(TFT_BLACK);
  // tft.fillRect(0, 120, 320, 360, TFT_BLACK);
  // tft.setFreeFont(&FreeSans12pt7b);
  entryOptions.push_back(Oz_8);
  entryOptions.push_back(Oz_10);
  entryOptions.push_back(Oz_16);
  entryOptions.push_back(Cancelar);
  Serial2.println("1.- 8 Oz");
  Serial2.println("2.- 10 Oz");
  Serial2.println("3.- 16 Oz");
  Serial2.println("4.- Cancelar");
  // key[16].drawButton();
  // key[17].drawButton();
  // key[18].drawButton();
  // key[4].drawButton();
}

void Screen::ServeOptionsGrowler(){
  Serial2.println("Selecionar Growler");
  actualScreen = GROWLER_QTY;
  // currentScreen = "GRLR_QTY";
  // //tft.fillScreen(TFT_BLACK);
  // tft.fillRect(0, 120, 320, 360, TFT_BLACK);
  // tft.setFreeFont(&FreeSans12pt7b);
  entryOptions.push_back(Oz_32);
  entryOptions.push_back(Oz_64);
  entryOptions.push_back(Oz_128);
  entryOptions.push_back(Cancelar);
  Serial2.println("1.- 32 Oz");
  Serial2.println("2.- 64 Oz");
  Serial2.println("3- 128 Oz");
  Serial2.println("4.- Cancelar");
  // key[8].drawButton();
  // key[9].drawButton();
  // key[10].drawButton();
  // key[4].drawButton();
  //drawInfo();
}

void Screen::Settings(){
  actualScreen = CONFIG_SCR;
  Serial2.println("Habemus configuracion, Selecciona:");
  entryOptions.push_back(Calibrar);
  entryOptions.push_back(Actualizar);
  entryOptions.push_back(Back);
  Serial2.println("1.- Calibra");
  Serial2.println("2.- Update OTA");
  Serial2.println("3.- Back");
  // actualScreen = CONFIG_SCR;
  // currentScreen = "CNFG_SCR";
  // tft.fillScreen(TFT_BLACK);
  // key[13].initButton(&tft, 17, 17, 35, 35, TFT_BLACK, TFT_BLACK, TFT_BLACK , "back",  KEY_TEXTSIZE, CONFIG_SCR, 0 , false);
  // key[13].drawButton();
  // fex.drawJpgFile(SPIFFS, "/back.jpg", 0, 2);
  // tft.setTextColor(TFT_WHITE);
  // tft.setFreeFont(&FreeSans24pt7b);
  // tft.drawString("Ajustes",115,2);
  // tft.setFreeFont(&FreeSans12pt7b);
  // key[12].initButton(&tft, 60, KEY_Y - 75 , 600, 68, TFT_BLACK, TFT_BLACK, TFT_WHITE , "Calibrar",  KEY_TEXTSIZE, CONFIG_SCR);
  // key[12].drawButton();
  // tft.drawLine(0, KEY_Y - 41, 320, KEY_Y - 41, TFT_WHITE);
}

void Screen::calibrationScreen(uint16_t ml){
  actualScreen = CALIBRATE_SCR;
  // currentScreen = "CAL_SCR";
  if (ml == 0) {
    isCalibrating = true;
    // tft.fillRect(0, 105, 320, 375, TFT_BLACK);
    // tft.fillScreen(TFT_BLACK);
    // tft.setTextColor(TFT_WHITE);
    // tft.setFreeFont(&FreeSans24pt7b);
    // tft.drawString("Calibrar",8,2);
    // tft.setFreeFont(&FreeSans18pt7b);
    Serial2.println("calibarcion acutal");
    Serial2.println((String)ppm);
    // tft.setFreeFont(&FreeSans9pt7b);
    // tft.drawString("p/ml",100,50);
    Serial2.println("LLenar 300ml y presionar listo.");
    //tft.drawString("", 160, 375);
    // tft.drawString("Valor actual",29,80);
    // tft.setFreeFont(&FreeSans12pt7b);
    // key[5].initButton(&tft, 160, 442, 290, 50, 0x2E6E, 0x2E6E,TFT_WHITE, "Listo",  KEY_TEXTSIZE, CALIBRATE_SCR);
    // key[5].drawButton();
    // tft.setTextDatum(MC_DATUM);
    // tft.setTextColor(TFT_WHITE, TFT_BLACK);
  }
    // tft.setFreeFont(&FreeSans24pt7b);
    Serial2.println((String(ml,0)+" pul").c_str());

}

void Screen::saveCalibration(uint16_t pulses){
  actualScreen = SAVE_SCR;
  // currentScreen = "SAVE_CAL";
  const float newPpm = pulses/300.0;
  // tft.setTextColor(TFT_WHITE, 0x2945);
  // fex.fillRoundRect(20, 20, 280, 440, 10, 0x2945);
  // tft.setFreeFont(&FreeSans24pt7b);
  Serial2.println("Guardar");
  Serial2.println((String)newPpm+" p/ml");
  // tft.setFreeFont(&FreeSans18pt7b);
  Serial2.println("Nuevo valor");
  // tft.setFreeFont(&FreeSans9pt7b);
  entryOptions.push_back(Descartar);
  entryOptions.push_back(Guardar);
  Serial2.println("1- Descartar");
  Serial2.println("2.- Guardar");
  // key[14].drawButton();
  // key[15].drawButton();
}


void Screen::otaUpdateScreen(){
  actualScreen = OTA_UPDATE_SCR;
  Serial2.println("Actualizando OTA ...");
  entryOptions.push_back(Cancelar);
  Serial2.println("1.- Cancelar");
  // tft.fillScreen(TFT_BLACK);
  // tft.setTextDatum(TC_DATUM);
  // tft.setTextColor(TFT_WHITE);
  // tft.setFreeFont(&FreeSans12pt7b);
  // tft.drawString("Esperando",160,320);
  // tft.drawString("Actualización OTA",160,345);
  // fex.drawJpgFile(SPIFFS, "/ota.jpg", 70, 100);
  // key[Cancelar].initButton(&tft, 160, 442, 290, 50, 0xF986, 0xF986, TFT_WHITE, "Cancelar", KEY_TEXTSIZE, OTA_UPDATE_SCR, 5);
  // key[Cancelar].drawButton();
}

void Screen::retryOrAP(){
  actualScreen = RETRY_AP_SCR;
  Serial2.println("No se pudo conectar al WiFi, desea?");
  entryOptions.push_back(Retry);
  entryOptions.push_back(CONFIGURAR_WIFI);
  entryOptions.push_back(BOOT_WITH_FILE);
  Serial2.println("1.- Re-intentar");
  Serial2.println("1.- Conf. WiFi");
  Serial2.println("3.- Modo de Emergencia");
  // tft.fillScreen(TFT_BLACK);
  // tft.setTextDatum(TC_DATUM);
  // tft.setTextColor(TFT_WHITE);
  // tft.setFreeFont(&FreeSans18pt7b);
  // tft.drawString("No se pudo conectar",160,40);
  // tft.drawString("al WiFi, desea?",160,80);
  // tft.setFreeFont(&FreeSans12pt7b);
  // key[Retry].initButton(&tft, 160, 442, 290, 50, 0x2E6E, 0x2E6E ,TFT_WHITE, "Re-intentar",  KEY_TEXTSIZE, RETRY_AP_SCR, 5);
  // key[Retry].drawButton();
  // key[CONFIGURAR_WIFI].initButton(&tft, 160, 372, 290, 50, 0x2E6E, 0x2E6E ,TFT_WHITE, "Conf. WiFi",  KEY_TEXTSIZE, RETRY_AP_SCR, 5);
  // key[CONFIGURAR_WIFI].drawButton();
  // key[BOOT_WITH_FILE].initButton(&tft, 160, 302, 290, 50, 0x2E6E, 0x2E6E ,TFT_WHITE, "Modo de Emergencia",  KEY_TEXTSIZE, RETRY_AP_SCR, 5);
  // key[BOOT_WITH_FILE].drawButton();
}