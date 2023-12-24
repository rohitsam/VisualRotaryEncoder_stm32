#pragma once

#include "i2c.h"
#include <stdint.h>
#define ENCODER_I2C_PORT hi2c1

#define VISUAL_ROTARY_ENCODER_DEFAULT_I2C_ADDR   (uint8_t)0xA8      ///< default I2C communication address
#define VISUAL_ROTARY_ENCODER_PID                (uint16_t)0x01F6   ///< module PID (SEN0502)(The highest two of 16-bit data are used to determine SKU type: 00：SEN, 01：DFR, 10：TEL, the next 14 are numbers.)

// VISUAL_ROTARY_ENCODER register address
#define VISUAL_ROTARY_ENCODER_PID_MSB_REG                (uint8_t)0x00   ///< module PID memory register，default value is 0x01F6 (The highest two of 16-bit data are used to determine SKU type: 00：SEN, 01：DFR, 10：TEL, the next 14 are numbers.)
#define VISUAL_ROTARY_ENCODER_PID_LSB_REG                (uint8_t)0x01
#define VISUAL_ROTARY_ENCODER_VID_MSB_REG                (uint8_t)0x02   ///< module VID memory register，default value is 0x3343（for manufacturer DFRobot）
#define VISUAL_ROTARY_ENCODER_VID_LSB_REG                (uint8_t)0x03
#define VISUAL_ROTARY_ENCODER_VERSION_MSB_REG            (uint8_t)0x04   ///< memory register of firmware revision number：0x0100 represents V0.1.0.0
#define VISUAL_ROTARY_ENCODER_VERSION_LSB_REG            (uint8_t)0x05
#define VISUAL_ROTARY_ENCODER_ADDR_REG                   (uint8_t)0x07   ///< memory register of module communication address，default value is 0x54，module device address (1~127)
#define VISUAL_ROTARY_ENCODER_COUNT_MSB_REG              (uint8_t)0x08   ///< encoder count，range 0-1023
#define VISUAL_ROTARY_ENCODER_COUNT_LSB_REG              (uint8_t)0x09
#define VISUAL_ROTARY_ENCODER_KEY_STATUS_REG             (uint8_t)0x0A   ///< encoder button status
#define VISUAL_ROTARY_ENCODER_GAIN_REG                   (uint8_t)0x0B   ///< encoder incremental factor


uint16_t countVal(void);
_Bool getButtonDetect(void);
uint8_t getGainCoefficient(void);
void setGainCoefficient(uint8_t gainValue);
uint8_t writeReg(uint8_t reg, const void* pBuf, size_t size);
size_t readReg(uint8_t reg, void* pBuf, size_t size);
