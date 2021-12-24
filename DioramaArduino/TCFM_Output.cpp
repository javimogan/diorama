/*
  TCFM_Output.cpp
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/
#include "TCFM_Output.h"

TCFM_Output::TCFM_Output()
{
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
  pixels = Adafruit_NeoPixel(15, D1, NEO_GRB + NEO_KHZ800);
  pixels.begin();
  this->initialize();
}
bool TCFM_Output::initialize()
{
  if (this->type == "led_strip")
  {
    this->setValue(this->currentValue);
  }
}
bool TCFM_Output::setValue(JsonArray _values)
{
  this->currentValue = _values;
  for (int i = 0; i < 15; i++)
    {

      pixels.setPixelColor(i, pixels.Color(this->currentValue[0].as<int>(), this->currentValue[1].as<int>(), this->currentValue[2].as<int>())); // Brillo moderado en rojo

      pixels.show(); // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB

    }
}