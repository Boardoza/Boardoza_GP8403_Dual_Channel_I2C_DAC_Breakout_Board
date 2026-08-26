#include "GP8403.h"
#include <math.h>

/**
 * @brief Constructs a new GP8403 object.
 * 
 * @param address I2C address of the device.
 */
GP8403::GP8403(uint8_t address) {
  _address = address;
}

/**
 * @brief Initializes the GP8403 to output in the 0-5V range.
 */
void GP8403::init5VMode() {
  Wire.beginTransmission(_address);
  Wire.write(GP8403_REG_CONFIG); 
  Wire.write(GP8403_VAL_5V); 
  Wire.endTransmission();
}

/**
 * @brief Initializes the GP8403 to output in the 0-10V range.
 */
void GP8403::init10VMode() {
  Wire.beginTransmission(_address);
  Wire.write(GP8403_REG_CONFIG); 
  Wire.write(GP8403_VAL_10V); 
  Wire.endTransmission();
}

/**
 * @brief Sets the DAC value for channel VOUT0.
 * 
 * @param dac_value A 12-bit value (0-4095) representing the desired output voltage.
 */
void GP8403::setVOUT0(uint16_t dac_value) {
  if (dac_value > 4095) dac_value = 4095;
  
  uint8_t low_byte  = (uint8_t)((dac_value & 0x0F) << 4);
  uint8_t high_byte = (uint8_t)((dac_value >> 4) & 0xFF);

  Wire.beginTransmission(_address);
  Wire.write(GP8403_REG_VOUT0); 
  Wire.write(low_byte);
  Wire.write(high_byte);
  Wire.endTransmission();
}

/**
 * @brief Sets the DAC value for channel VOUT1.
 * 
 * @param dac_value A 12-bit value (0-4095) representing the desired output voltage.
 */
void GP8403::setVOUT1(uint16_t dac_value) {
  if (dac_value > 4095) dac_value = 4095;

  uint8_t low_byte  = (uint8_t)((dac_value & 0x0F) << 4);
  uint8_t high_byte = (uint8_t)((dac_value >> 4) & 0xFF);

  Wire.beginTransmission(_address);
  Wire.write(GP8403_REG_VOUT1); 
  Wire.write(low_byte);
  Wire.write(high_byte);
  Wire.endTransmission();
}

/**
 * @brief Generates a ramp-up wave on both VOUT0 and VOUT1 channels.
 * 
 * @param stepDelay Delay in milliseconds between each voltage step.
 * @param stepSize Increment step size for the DAC value.
 */
void GP8403::rampUp(uint16_t stepDelay, uint16_t stepSize) {
  for (int i = 0; i <= 4095; i += stepSize) {
    setVOUT0(i);
    setVOUT1(i);
    delay(stepDelay);
  }
}

/**
 * @brief Generates a ramp-down wave on both VOUT0 and VOUT1 channels.
 * 
 * @param stepDelay Delay in milliseconds between each voltage step.
 * @param stepSize Decrement step size for the DAC value.
 */
void GP8403::rampDown(uint16_t stepDelay, uint16_t stepSize) {
  for (int i = 4095; i >= 0; i -= stepSize) {
    setVOUT0(i);
    setVOUT1(i);
    delay(stepDelay);
  }
}

/**
 * @brief Outputs a single cycle of a square wave on both channels.
 * 
 * @param halfPeriodMs Half of the period in milliseconds. Output stays high and low for this duration.
 */
void GP8403::squareWaveCycle(uint32_t halfPeriodMs) {
  setVOUT0(4095);
  setVOUT1(4095);
  delay(halfPeriodMs);
  setVOUT0(0);
  setVOUT1(0);
  delay(halfPeriodMs);
}

/**
 * @brief Outputs a high-speed sine wave cycle on both channels.
 */
void GP8403::sineWaveCycle() {
  const int samples = 256;
  uint16_t sineTable[samples];
  
  // Pre-calculate sine table
  for (int i = 0; i < samples; i++) {
    float angle = (i * 2.0 * PI) / samples;
    sineTable[i] = (uint16_t)((sin(angle) + 1.0) * 2047.5);
  }

  // Write to both channels quickly
  for (int i = 0; i < samples; i++) {
    setVOUT0(sineTable[i]);
    setVOUT1(sineTable[i]);
  }
}