#include "./encoder.h"


uint8_t writeReg(uint8_t reg, const void* pBuf, size_t size){

	 HAL_StatusTypeDef x = HAL_I2C_Mem_Write(&ENCODER_I2C_PORT, VISUAL_ROTARY_ENCODER_DEFAULT_I2C_ADDR, reg, 1, (uint8_t *)pBuf, size, 0xffffff);

	return (uint8_t)x;
}


size_t readReg(uint8_t reg, void* pBuf, size_t size){


	HAL_I2C_Mem_Read(&ENCODER_I2C_PORT,VISUAL_ROTARY_ENCODER_DEFAULT_I2C_ADDR, reg, 1, (uint8_t*)pBuf, size, 0xffffff);

}

uint16_t countVal(void){

	uint8_t CountValue[2] = {0};
	readReg(VISUAL_ROTARY_ENCODER_COUNT_MSB_REG, CountValue, sizeof(CountValue));
	return (uint16_t)CountValue[0] << 8 | (uint16_t)CountValue[1];
}
_Bool getButtonDetect(void){

	_Bool ret = 0;
	 uint8_t buttonStatus, clearStatus=0x00;

	 readReg(VISUAL_ROTARY_ENCODER_KEY_STATUS_REG, &buttonStatus, sizeof(buttonStatus));

	 if( 0 != (buttonStatus & 0x01) ){
	   writeReg(VISUAL_ROTARY_ENCODER_KEY_STATUS_REG, &clearStatus, sizeof(clearStatus));
	   ret = 1;
	 }

	 return ret;


}

uint8_t getGainCoefficient(void) {
  uint8_t RotateGain = 0;
  readReg(VISUAL_ROTARY_ENCODER_GAIN_REG, &RotateGain, sizeof(RotateGain));

  return RotateGain;
}

void setGainCoefficient(uint8_t gainValue) {
  if((0x01 <= gainValue) && (0x33 >= gainValue)){
    writeReg(VISUAL_ROTARY_ENCODER_GAIN_REG, &gainValue, sizeof(gainValue));
  }
}
