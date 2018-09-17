/* 
 * File:   I2CMaster.h
 * Author: Kazusa
 *
 * Created on 2018/09/09, 11:15
 */

#ifndef I2CMASTER_H
#define	I2CMASTER_H

#include <stdint.h>

void init_I2C(void);
uint8_t send_I2C(uint8_t);
uint8_t start_I2C(uint8_t, uint8_t);
void checkIdle_I2C(uint8_t);
void stop_I2C(void);
void isr_I2C(void);

#endif	/* I2CMASTER_H */

