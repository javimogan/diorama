/*
  TCFM_Cycle.h
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/

#ifndef TCFM_Cycle_h
#define TCFM_Cycle_h
#include <ArduinoJson.h>

class TCFM_Cycle
{
private:
  String id;
  String name;
  int length;
  //TODO: insert Triggers

public:
  TCFM_Cycle(String _id, String _name, int _length) { begin(_id, _name, _length); }
  void begin(String _id, String _name, int _length);
  bool run();
};

#endif