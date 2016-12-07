//
// Created by Angel Zaprianov on 7.12.2016 г..
//
#include "I2cSimpleListener.h"

/**
 * Constructor
 */
I2cSimpleListener::I2cSimpleListener(void) {
    // do nothing, use setPins() later
}

/**
 *
 * @param sclPin
 * @param sdaPin
 */
I2cSimpleListener::I2cSimpleListener(uint8_t sclPin, uint8_t sdaPin) {
    setPins(sclPin, sdaPin);
}

/**
 * Sets pin as inputs
 * @param sdaPin
 * @param sclPin
 */
void I2cSimpleListener::setPins(uint8_t sdaPin, uint8_t sclPin) {
    uint8_t port;


    _sclPin = sclPin;
    _sdaPin = sdaPin;

    _sclBitMask = digitalPinToBitMask(sclPin);
    _sdaBitMask = digitalPinToBitMask(sdaPin);

    port = digitalPinToPort(sclPin);
    _sclPortReg = portInputRegister(port);
    _sclDirReg = portModeRegister(port);

}

/**
 * Read a byte from the I2C slave device
 * @return
 */
uint8_t I2cSimpleListener::i2cRead(void) {
    uint8_t res = 0;

    for (uint8_t i = 0; i < IC2_LISTENER_LENGTH; i++) {
        res <<= 1;
        res |= i2cReadBit();
    }


    return res;
}

/**
 * Reads message when is coming
 * @return bits
 */
uint8_t I2cSimpleListener::listen() {
    if (!digitalRead(_sclPin))
        return i2cRead();
}
/**
 * Reads single bit
 * @return uint8_t
 */
uint8_t I2cSimpleListener::i2cReadBit(void) {
    uint8_t port = digitalPinToPort(_sdaPin);
    volatile uint8_t *pinReg = portInputRegister(port);
    uint8_t c = *pinReg;  // I2C_PIN;
    return (c & _sdaBitMask) ? 1 : 0;
}

