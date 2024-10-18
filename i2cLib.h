#ifdef I2CLIB_H
#define I2CLIB_H

void I2C_Init();
void I2C_bStart();
void I2C_bStop();
void I2C_Write(uint8_t data);

#endif