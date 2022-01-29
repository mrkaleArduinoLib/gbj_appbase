/*
  NAME:
  gbj_appbase

  DESCRIPTION:
  Library adds virtual methods to its parent class with common core methods
  for project centric application libraries and acts as their parent class.
  - Library only has pure virual method(s).

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the license GNU GPL v3
  http://www.gnu.org/licenses/gpl-3.0.html (related to original code) and MIT
  License (MIT) for added code.

  CREDENTIALS:
  Author: Libor Gabaj
  GitHub: https://github.com/mrkaleArduinoLib/gbj_appbase.git
*/
#ifndef GBJ_APPBASE_H
#define GBJ_APPBASE_H

#if defined(__AVR__)
  #include <Arduino.h>
  #include <inttypes.h>
#elif defined(ESP8266)
  #include <Arduino.h>
#elif defined(ESP32)
  #include <Arduino.h>
#elif defined(PARTICLE)
  #include <Particle.h>
#endif
#include "gbj_appcore.h"

class gbj_appbase : public gbj_appcore
{
public:
  static const String VERSION;

  // Abstract methods
  virtual void run() = 0;
  virtual void setPeriod(unsigned long period) = 0;
  virtual unsigned long getPeriod() = 0;
};

#endif
