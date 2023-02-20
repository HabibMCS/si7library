#include "si7lib.h"
#include <Wire.h>

SI7::SI7() {
  Wire.begin();
}

uint16_t SI7::getFieldStrength() {
  Wire.endTransmission();
  Wire.beginTransmission(0x30);
  Wire.write(0xc4);
  Wire.write(0b00000100);
  Wire.endTransmission();
  Wire.beginTransmission(0x30);
  Wire.write(0xc1);
  Wire.endTransmission();
  Wire.requestFrom(0x30, 1);
  uint8_t sigm = Wire.read();
  Wire.beginTransmission(0x30);
  Wire.write(0xc2);
  Wire.endTransmission();
  Wire.requestFrom(0x30, 1);
  uint8_t sign = Wire.read();
  uint16_t field = ((sigm & 0x7f) << 8) | sign;
  unsigned long start_time = millis();
  while (millis() - start_time < 500) {
    // Wait for 500 milliseconds using the millis() function
  }
  return field;
}