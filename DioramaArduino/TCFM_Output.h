/*
  TCFM_Output.h
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/

#ifndef TCFM_Output_h
#define TCFM_Output_h
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>

class TCFM_Output
{
private:
    int id;
    String name;
    String description;
    String type;
    String output_type;
    JsonArray pin;
    JsonArray initialValue;
    JsonArray currentValue;
    Adafruit_NeoPixel pixels;
public:
    TCFM_Output();
    TCFM_Output(int _id, String _name, String _description, String _type, String _output_type, JsonArray _pin, JsonArray _initialValue);//{begin(_id, _name, _description, _type, _output_type, _pin, _initialValue);}
    bool initialize();
    bool setValue(JsonArray _values);
};

#endif 