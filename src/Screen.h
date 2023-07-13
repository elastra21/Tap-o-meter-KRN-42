#ifndef MY_SCREEN_H
#define MY_SCREEN_H
#include <vector>
#include <Arduino.h>
#include <ArduinoJson.h>

// #include "FS.h"
// #include <SPI.h>
// #include <TFT_eSPI.h>
// #include <TFT_eFEX.h>
// #include <JPEGDecoder.h>

#define CALIBRATION_FILE "/TouchCalData1"
#define REPEAT_CAL false

// Keypad start position, key sizes and spacing
#define KEY_X 75 // Centre of key
#define KEY_Y 195
#define KEY_W 140 // Width and height
#define KEY_H 135
#define KEY_SPACING_X 10 // X and Y gap
#define KEY_SPACING_Y 10
#define KEY_TEXTSIZE 1   // Font size multiplier

// Numeric display box size and location
#define DISP_X 1
#define DISP_Y 30
#define DISP_W 238
#define DISP_H 50
#define DISP_TSIZE 3
#define DISP_TCOLOR TFT_CYAN

// We have a status line for messages
#define STATUS_X 160 // Centred on this
#define STATUS_Y 105
#define COG_X 20
#define COG_Y 440



//Screens that we have
enum screens {
  NON_SELECTED = -1 ,
  AP_SCR,
  NO_BEER_SCR,
  CONNECTING_SCR,
  DISCONNECTED_SCR,
  CONFIG_SCR,
  CALIBRATE_SCR,
  SAVE_SCR,
  OTA_UPDATE_SCR,
  RETRY_AP_SCR,
  LOCK_SCR,
  LOADING_SCR,
  SELECT_QTY,
  PINT_QTY,
  TASTER_QTY,
  GROWLER_QTY,
  OPEN_QTY,
  SERVING_SCR,
};

#define AFFECT_INDEX      9

//Buttons that we have
enum buttons {
  NONE = -1,
  Vaso,           
  Taster,         
  Growler,        
  Mermar,         
  Cancelar,       
  Listo,          
  Oz_2,           
  Oz_5,           
  Oz_32,          
  Oz_64,          
  Oz_128,          
  cog,             
  Calibrar,        
  Back,            
  Guardar,         
  Descartar,       
  Oz_8,            
  Oz_10,           
  Oz_16,           
  Actualizar,      
  Retry,           
  CONFIGURAR_WIFI, 
  BOOT_WITH_FILE,  
};

//ERORS
#define WIFI_NOT_CONNECTED_MSG    "Sin conexion a WiFi"
#define NO_SERVER_CONNECTION_MSG  "Error en Servidor" 

enum ERRORS {
  NO_ERROR = -1,
  WIFI_NOT_CONNECTED = 1,
  NO_SERVER_CONNECTION = 2,    
};

struct newLine {  // this should be move to line class
  String keg_id;
  String beer_abv;        // this should be rename as "abv"
  String beer_name;       // this should be rename as "name"
  String beer_style;      // this should be rename as "style"
  uint16_t no_linea;      // this should be rename as "line_number"
};


class Screen {
  public:
    // TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

    // TFT_eFEX  fex = TFT_eFEX(&tft);
    float ppm;
    String kegId;
    String beerAbv;
    String beerName;
    String beerStyle;
    uint16_t noLinea;
    int actualScreen;
    bool isServing = false;
    bool isMermando = false;

    // TFT_eSPI_Button key[19];
    String emergencyCard = "";
    bool isCalibrating = false;
    char keyLabel[4][8] = {"Vaso", "Taster", "Growler", "Mermar"};

    Screen();
    void init();
    // void splash();
    void noWifi();
    void tapCard();
    void drawInfo();
    void Settings();
    void drawError();
    void retryOrAP();
    void showReady();
    void LockScreen();
    void connecting();
    void removeInfo();
    int8_t getError();
    void clearScreen();
    void hideCancell();
    uint8_t isPressed();
    void partialClear();
    void LoadingModal();
    void OptionsScreen();
    bool isOnEmergency();
    bool isTouchEneable();
    void setError(int8_t);
    void NoBeerAssigned();
    void touch_calibrate();
    void otaUpdateScreen();
    void hideLoadingModal();
    bool screenServer(void);
    void mermar(uint16_t ml);
    void ServeOptionsGlass();
    String getErrorMessage();
    void ServeOptionsTaster();
    void notConnectedToSever();
    void ServeOptionsGrowler();
    void status(const char *msg);
    void setEmergency(bool state);
    void setInfo(const char * info);
    void setTouchEneable(bool value);
    bool screenServer(String filename);
    void drawMl(double ml, bool isMl);
    void calibrationScreen( uint16_t ml);
    void saveCalibration(uint16_t pulses);
// nada
// nada
    void AP(String name, bool retriable = false);
    void SelectQty(String user, String client = "" );
    void servingScreen( bool drawIt, uint8_t update, String type);
  private:
    bool loading_modal = false;
    bool emergency_mode = false;
    bool touch_eneable = false;
    int8_t error = NO_ERROR;
    std::vector<int> entryOptions;
};
#endif
