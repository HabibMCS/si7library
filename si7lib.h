#ifndef si7lib_h
#define si7lib_h

#include <Arduino.h>

class SI7 {
  public:
    SI7();
    uint16_t getFieldStrength();
};

#endif