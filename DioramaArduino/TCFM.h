/*
  TCFM.h
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/

#ifndef TCFM_h
#define TCFM_h
#include <ArduinoJson.h>

class TCFM
{
private:
    bool _isLoad;
    String name;
    String author;
    String version;
    bool repeat_cycles;

public:
    TCFM(){begin();}
    void begin();
    bool setConfig(DynamicJsonDocument _config);
    //Getters
    bool isLoad();
    String getName();
    String getAuthor();
    String getVersion();
    bool getRepeatCyles();
    void run();
};

#endif