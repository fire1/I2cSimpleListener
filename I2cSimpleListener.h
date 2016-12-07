//
// Created by Angel Zaprianov on 7.12.2016
//

#ifndef ARDUINO_I2C_SIMPLE_LISTENER_H
#define ARDUINO_I2C_SIMPLE_LISTENER_H

#define I2C_SIMPLE_LISTENER_VERSION 1

#ifndef IC2_LISTENER_LENGTH
#define IC2_LISTENER_LENGTH 8
#endif


#include <Arduino.h>

/**
 * Simple I2C listener
 *      Class provides option to I2C listen messages over I2C network
 */
class I2cSimpleListener {

private:
    //
    // Pins containers
    uint8_t _sclPin, _sdaPin;
    //
    // Mask container
    uint8_t _sclBitMask, _sdaBitMask;

    volatile uint8_t *_sclPortReg;
    volatile uint8_t *_sdaPortReg;
    volatile uint8_t *_sclDirReg;
    volatile uint8_t *_sdaDirReg;


protected:

    /**
     * Read message
     * @return
     */
    uint8_t i2cRead(void);

    /**
     * Read single bit
     * @return
     */
    uint8_t i2cReadBit(void);

public:
    /**
     * Constructor
     */
    I2cSimpleListener(void);

    /**
     * Constructor with init
     */
    I2cSimpleListener(uint8_t sclPin, uint8_t sdaPin);

    /**
     * Pin setup method
     * @param sdaPin
     * @param sclPin
     */
    void setPins(uint8_t sdaPin, uint8_t sclPin);

    /**
     * Method returns messages over I2C network
     * @return
     */
    uint8_t listen(void);

};


#endif //ARDUINO_I2C_SIMPLE_LISTENER_H
