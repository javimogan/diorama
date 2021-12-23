/*
  TCFM.cpp
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/
#include "TCFM.h"
#include <Arduino.h>

void TCFM::begin()
{
  _isLoad = false;
}
boolean TCFM::setConfig(DynamicJsonDocument _config)
{
  name = _config["name"].as<String>();
  author = _config["author"].as<String>();
  version = _config["version"].as<String>();
  repeat_cycles = _config["repeat_cycles"].as<bool>();

 
  /*for (JsonObject _out : diorama_config["outputs"].as<JsonArray>())
  {
    JsonArray _pins = _out["pin"].as<JsonArray>();
    JsonArray _initialValue = _out["initialValue"].as<JsonArray>();
    for (int i = 0; i < _pins.size(); i++)
    {
      pinMode(string2Pin(_pins[i].as<String>()), OUTPUT);
      if (_out["output_type"].as<String>() == "analog")
      {
        analogWrite(string2Pin(_pins[i].as<String>()), _initialValue[i].as<int>());
      }
      else if (_out["output_type"].as<String>() == "digital")
      {
      }
    }*/
  //TODO: Check response
  return true;
}
void TCFM::run()
{
  if (_isLoad)
  {
    Serial.println("RUN is working");
  }
  else
  {
    Serial.println("Load before");
  }
}
bool TCFM::isLoad()
{
  return _isLoad;
}
bool TCFM::getRepeatCyles()
{
  return repeat_cycles;
}
String TCFM::getName()
{
  return name;
}
String TCFM::getAuthor()
{
  return author;
}
String TCFM::getVersion()
{
  return version;
}
