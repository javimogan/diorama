/*
  TCFM.h
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/

#ifndef TCFM_h
#define TCFM_h
#include <Arduino.h>
#include <ArduinoJson.h>
#include "TCFM_Output.h"

#define MAX_OUTPUTS 15
class TCFM
{
private:
    bool _isLoad;
    String name;
    String author;
    String version;
    bool repeat_cycles;

    TCFM_Output *outputs[MAX_OUTPUTS];
    //JsonArray *cycles;

    static uint8_t ESPdatapins[11];
    static byte string2Pin(String _pin);
public:
    TCFM(){begin();}
    ~TCFM();
    void begin();
    bool setConfig(DynamicJsonDocument _config);
    //Getters
    bool isLoad();
    String getName();
    String getAuthor();
    String getVersion();
    bool getRepeatCyles();
    void initializeOutputs(JsonArray _outputs);
    void run();
};

#endif