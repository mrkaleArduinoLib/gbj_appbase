/*
  NAME:
  gbj_appbase

  DESCRIPTION:
  Library provides common methods for project centric application libraries
  and acts as their parent class.
  - Library implements basic error handling.
  - Library hase pure virual method(s).

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
  #if ARDUINO >= 100
    #include <Arduino.h>
  #else
    #include <WProgram.h>
  #endif
  #include <inttypes.h>
#elif defined(ESP8266) || defined(ESP32)
  #include <Arduino.h>
#elif defined(PARTICLE)
  #include <Particle.h>
#endif

class gbj_appbase
{
public:
  //------------------------------------------------------------------------------
  // Public constants
  //------------------------------------------------------------------------------
  static const String VERSION;
  enum ResultCodes : byte
  {
    SUCCESS, // It should be always the first with index 0
    ERROR_UKNOWN, // Not recognized error
    ERROR_NOINIT, // Not initialized yet
    ERROR_NODEVICE, // No device detected
    ERROR_ADDR, // Wrong address
    ERROR_DATA, // Wrong data
    ERROR_CONNECT, // Connection failed
    ERROR_PUBLISH, // Publishing failed
    ERROR_SUBSCRIBE, // Subsribing failed
  };

  //------------------------------------------------------------------------------
  // Abstract methods
  //------------------------------------------------------------------------------
  virtual void run() = 0;
  virtual unsigned long getPeriod() = 0;
  virtual void setPeriod(unsigned long period) = 0;

  //------------------------------------------------------------------------------
  // Public setters - they usually return result code or void.
  //------------------------------------------------------------------------------
  inline ResultCodes setLastResult(ResultCodes lastResult = ResultCodes::SUCCESS)
  {
    return _lastResult = lastResult;
  };

  //------------------------------------------------------------------------------
  // Public getters
  //------------------------------------------------------------------------------
  inline ResultCodes getLastResult() { return _lastResult; };
  inline bool isSuccess() { return _lastResult == ResultCodes::SUCCESS; };
  inline bool isError() { return !isSuccess(); };

private:
  ResultCodes _lastResult =
    ResultCodes::ERROR_NOINIT; // Result of a recent operation
};

#endif
