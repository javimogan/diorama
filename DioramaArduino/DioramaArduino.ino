/*********
 Time Controller for Mockups Core
  @javimogan
  https://javimogan.com

*********/

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include "TCFM.h"
#define config_url "https://raw.githubusercontent.com/javimogan/diorama/main/config.json"

WiFiManager wifiManager;
HTTPClient http;
WiFiClientSecure client;
TCFM tcfm;
//TODO: Check size of DynamicJsonDocument
DynamicJsonDocument diorama_config(2048);
//TODO: String to pins
//static const uint8_t ESPdatapins[] = {D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10};

void setup()
{
  Serial.begin(115200);

  client.setInsecure();

  // Descomentar para resetear configuración
  //wifiManager.resetSettings();

  // Creamos AP y portal cautivo
  wifiManager.autoConnect("DioramaAP");
  // Ya estas conectado
  if (updateConfig())
  {
    tcfm.setConfig(diorama_config);
  }
  else
  {
    Serial.println("Update error");
  }
}

void loop()
{
  tcfm.run();
  //core(diorama_config);
}

void core(DynamicJsonDocument diorama_config)
{
 /* JsonArray cycles = diorama_config["cycles"].as<JsonArray>();
  JsonArray outputs = diorama_config["outputs"].as<JsonArray>();
  JsonObject current_cycle;

  for (int current_cycle_index = 0; current_cycle_index < cycles.size(); current_cycle_index++)
  {
    current_cycle = cycles[current_cycle_index].as<JsonObject>();

    for (JsonObject _trigger : current_cycle["triggers"].as<JsonArray>())
    {
      JsonObject _out = outputs[_trigger["outputId"]];
      setOutput(false, _out["type"], _out["output_type"], _out["pin"].as<JsonArray>(), _trigger["setValue"].as<JsonArray>());
    }

    delay(current_cycle["lenght"]);

    //Repeat all cycles?
    if (current_cycle_index == cycles.size() - 1 && diorama_config["repeat_cycles"].as<bool>())
    {
      current_cycle_index = -1;
    }
  }*/
}

void setOutput(bool _initialize, String _type, String _output_type, JsonArray _pins, JsonArray _values)
{

  /*for (int i = 0; i < _pins.size(); i++)
  {
    if (_initialize)
    {
      pinMode(string2Pin(_pins[i].as<String>()), OUTPUT);
    }
    if (_output_type == "analog")
    {
      analogWrite(string2Pin(_pins[i].as<String>()), _values[i].as<int>());
    }
    else if (_output_type == "digital")
    {
    }
  }*/
}
bool updateConfig()
{
  return getJSONFromURL(config_url, diorama_config);
}
//Return a DynamicJsonDocument from URL
bool getJSONFromURL(char *_url, DynamicJsonDocument &_output)
{
  bool _response = false;
  //Specify request destination
  http.begin(client, _url);
  //Send the request
  int httpCode = http.GET();
  if (httpCode > 0)
  { //Check the returning code
    deserializeJson(_output, http.getStream());
    _response = true;
  }
  //Close connection
  http.end();
  return _response;
}
/*byte string2Pin(String _pin)
{
  //check if it's a valid pin name
  if (_pin.length() >= 2 && _pin[0] == 'D')
  {
    //skip the first character (D) and convert it to an integer
    uint8_t pin = ESPdatapins[_pin.substring(1).toInt()];
    return pin;
  }
}*/
