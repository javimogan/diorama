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
  cycles = _config["cycles"].as<JsonArray>();

  initializeOutputs(_config["outputs"].as<JsonArray>());
  //TODO: Check response
  return true;
}

void TCFM::initializeOutputs(JsonArray _outputs)
{

  int i = 0;
  for (JsonObject _output : _outputs)
  {
    Serial.println("output " + String(i));
    if (_output["type"] == "led_strip")
    {
      Serial.println("creamos Output " + _output["name"].as<String>());
      outputs[i] = new TCFM_Output(_output["id"].as<int>(),
                                   _output["name"].as<String>(),
                                   _output["description"].as<String>(),
                                   _output["type"].as<String>(),
                                   _output["output_type"].as<String>(),
                                   _output["pin"].as<JsonArray>(),
                                   _output["initialValue"].as<JsonArray>());
    }
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
  _isLoad = true;
}
void TCFM::run()
{
  if (_isLoad)
  {
    JsonObject current_cycle;
    Serial.println("Size viene debajo");
      Serial.println("Size: " + cycles.size());
    for (int current_cycle_index = 0; current_cycle_index < cycles.size(); current_cycle_index++)
    {
      Serial.println("index: " + current_cycle_index);
      current_cycle = this->cycles[current_cycle_index].as<JsonObject>();
      Serial.println("id: " + current_cycle["id"].as<String>());
      Serial.println("name: " + current_cycle["name"].as<String>());
      for (JsonObject _trigger : current_cycle["triggers"].as<JsonArray>())
      {
        outputs[0]->setValue( _trigger["setValue"].as<JsonArray>());
        //JsonObject _out = outputs[_trigger["outputId"]];

        //setOutput(false, _out["type"], _out["output_type"], _out["pin"].as<JsonArray>(), _trigger["setValue"].as<JsonArray>());
      }

      delay(current_cycle["lenght"]);

      //Repeat all cycles?
      if (current_cycle_index == cycles.size() - 1 && repeat_cycles)
      {
        current_cycle_index = -1;
      }
    }
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