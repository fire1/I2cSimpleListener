
#include <I2cSimpleListener.h>

I2cSimpleListener i2c(A2,A3);

void setup() {
    Serial.begin(9600);           // start serial for output
}

void loop() {
    uint8_t val = i2c.listen();
    if(val)
        Serial.println(val);
}