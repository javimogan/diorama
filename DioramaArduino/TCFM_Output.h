/*
  TCFM_Output.h
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/

#ifndef TCFM_Output_h
#define TCFM_Output_h
#include <ArduinoJson.h>

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

public:
    TCFM_Output(int _id, String _name, String _description, String _type, String _output_type, JsonArray _pin, JsonArray _initialValue){begin(_id, _name, _description, _type, _output_type, _pin, _initialValue);}
    void begin(int _id, String _name, String _description, String _type, String _output_type, JsonArray _pin, JsonArray _initialValue);
    bool setValue(JsonArray _values);
};

#endif