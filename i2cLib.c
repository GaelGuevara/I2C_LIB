#include "i2cLib.h"
#include "MKL25Z4.h"

void I2C_Init(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTE_MASK;
    SIM -> SCGC4 |= SIM_SCGC4_I2C0_MASK;
    PORTE -> PCR[8] = PORT_PCR_MUX(2);
    PORTE -> PCR[9] = PORT_PCR_MUX(2);
    I2C0 -> C1 = 0;
    I2C0 -> F = 0x14;
    I2C0 -> C1 = I2C_C1_IICEN_MASK;
}

void I2C_bStart(){
    I2C0->C1 |= I2C_C1_TX_MASK;
    I2C0->C1 |= I2C_C1_MST_MASK;
}

void I2C_bStop(){
    I2C0->C1 |= ~I2C_C1_TX_MASK;
    I2C0->C1 |= ~I2C_C1_MST_MASK;
}

void I2C_Write(uint8_t data){
    I2C0->D = data;
    while (!(I2C0->S & I2C_S_IICIF_MASK));
    I2C0->S |= I2C_S_IICIF_MASK;
}