/*
  TCFM_Trigger.h
  Created by @javimogan, December 23, 2021.
  https://javimogan.com
*/

#ifndef TCFM_Trigger_h
#define TCFM_Trigger_h
#include <ArduinoJson.h>

class TCFM_Trigger
{
private:
  //TODO: Pointer to TCFM.Output

public:
  TCFM_Trigger() { begin(); }
  void begin();
  bool run();
};

#endif