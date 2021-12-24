/*
  TCFM_Output.cpp
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/
#include "TCFM_Output.h"

TCFM_Output::TCFM_Output(){
  
}
TCFM_Output::TCFM_Output(int _id, String _name, String _description, String _type, String _output_type, JsonArray _pin, JsonArray _initialValue)
{
  id = _id;
  name = _name;
  description = _description;
  type = _type;
  output_type = _output_type;
  pin = _pin;
  initialValue = _initialValue;
  currentValue = _initialValue;
  
  this->initialize();
}
bool TCFM_Output::initialize(){
  Serial.println("inicializandooooo");
}
bool TCFM_Output::setValue(JsonArray _values){
  Serial.println("Set value " + String(id) + " " + name);
}