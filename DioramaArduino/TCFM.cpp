/*
  TCFM.cpp
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/
#include "TCFM.h"

void TCFM::begin()
{
  _isLoad = false;
}

uint8_t TCFM::ESPdatapins[] = {D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10};

boolean TCFM::setConfig(DynamicJsonDocument _config)
{
  name = _config["name"].as<String>();
  author = _config["author"].as<String>();
  version = _config["version"].as<String>();
  repeat_cycles = _config["repeat_cycles"].as<bool>();
  //outputs = _config["outputs"].as<JsonArray>();
  //cycles = _config["cycles"].as<JsonArray>();

  initializeOutputs(_config["outputs"].as<JsonArray>());
  //TODO: Check response
  return true;
}

void TCFM::initializeOutputs(JsonArray _outputs)
{

  int i = 0;
  for (JsonObject _output : _outputs)
  {
    outputs[i] = new TCFM_Output(_output["id"].as<int>(),
                               _output["name"].as<String>(),
                               _output["description"].as<String>(),
                               _output["type"].as<String>(),
                               _output["output_type"].as<String>(),
                               _output["pin"].as<JsonArray>(),
                               _output["initialValue"].as<JsonArray>());
    i++;
    //outputs[i].setValue( _output["initialValue"].as<JsonArray>());
    /*JsonArray _pins = _output["pin"].as<JsonArray>();
    JsonArray _initialValue = _output["initialValue"].as<JsonArray>();
    String _output_type = _output["output_type"].as<String>();
    for (int i = 0; i < _pins.size(); i++)
    {
      pinMode(string2Pin(_pins[i].as<String>()), OUTPUT);
      if (_output_type == "analog")
      {
        analogWrite(string2Pin(_pins[i].as<String>()), _initialValue[i].as<int>());
      }
      else if (_output_type == "digital")
      {
        digitalWrite(string2Pin(_pins[i].as<String>()), _initialValue[i].as<int>());
      }
    }*/
  }
}
void TCFM::run()
{
  if (_isLoad)
  {
    Serial.println("RUN is working");
  }
  else
  {
    //Serial.println("Load before");
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
TCFM::~TCFM()
{
  //TODO: REmove Outputs
}
byte TCFM::string2Pin(String _pin)
{
  //check if it's a valid pin name
  if (_pin.length() >= 2 && _pin[0] == 'D')
  {
    //skip the first character (D) and convert it to an integer
    uint8_t pin = ESPdatapins[_pin.substring(1).toInt()];
    return pin;
  }
}