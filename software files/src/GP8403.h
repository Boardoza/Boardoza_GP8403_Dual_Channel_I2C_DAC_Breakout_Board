#ifndef GP8403_H
#define GP8403_H

#include <Arduino.h>
#include <Wire.h>

// --- GP8403 Registers & Configuration Values ---
#define GP8403_REG_CONFIG    0x01
#define GP8403_VAL_5V        0x00
#define GP8403_VAL_10V       0x11

#define GP8403_REG_VOUT0     0x02
#define GP8403_REG_VOUT1     0x04

class GP8403 {
  private:
    uint8_t _address;

  public:
    // Default I2C address is 0x58
    GP8403(uint8_t address = 0x58);

    // Initialization and Mode Setup
    void init5VMode();
    void init10VMode();
    
    // Output Setters
    void setVOUT0(uint16_t dac_value);
    void setVOUT1(uint16_t dac_value);

    // Effects (Single Cycle)
    void rampUp(uint16_t stepDelay = 10, uint16_t stepSize = 64);
    void rampDown(uint16_t stepDelay = 10, uint16_t stepSize = 64);
    void squareWaveCycle(uint32_t halfPeriodMs = 500);
    void sineWaveCycle();
};

#endif