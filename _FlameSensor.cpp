#include "_FlameSensor.h"

/*
 * File AI Disclosure:
 * - Converted flame sensor code from repo (below) into a separate
 *   header and class file for readability
 * https://github.com/omron-devhub/d6t-2jcieev01-arduino/blob/master/examples/d6t-44l/d6t-44l.ino
 */

// Initialize static members
uint8_t FlameSensor::rbuf[N_READ];
double FlameSensor::pix_data[N_PIXEL];

void FlameSensor::initialize() {
    Wire.begin(); // i2c master
    delay(620);   // Startup stabilization delay
}

void FlameSensor::update() {
    int i = 0;
    int16_t itemp = 0;

    // Read data via I2C
    memset(rbuf, 0, N_READ);
    Wire.beginTransmission(D6T_ADDR);
    Wire.write(D6T_CMD);
    Wire.endTransmission();

    delay(1);

    Wire.requestFrom((uint8_t)D6T_ADDR, (uint8_t)N_READ);
    while (Wire.available()) {
        rbuf[i++] = Wire.read();
    }

    // Run packet error check
    checkPEC(rbuf, N_READ - 1);

    // Convert raw bytes to temperature data (degC)
    for (i = 0; i < N_PIXEL; i++) {
        itemp = conv8us_s16_le(rbuf, 2 + 2 * i);
        pix_data[i] = (double)itemp / 10.0;
    }
}

double FlameSensor::getPixel(int index) {
    if (index >= 0 && index < N_PIXEL) {
        return pix_data[index];
    }
    return 0.0;
}

uint8_t FlameSensor::calc_crc(uint8_t data) {
    int index;
    uint8_t temp;
    for (index = 0; index < 8; index++) {
        temp = data;
        data <<= 1;
        if (temp & 0x80) { data ^= 0x07; }
    }
    return data;
}

// Packet error checking
bool FlameSensor::checkPEC(uint8_t buf[], int n) {
    int i;
    uint8_t crc = calc_crc((D6T_ADDR << 1) | 1); // I2C Read address (8bit)
    for (i = 0; i < n; i++) {
        crc = calc_crc(buf[i] ^ crc);
    }
    bool ret = crc != buf[n];
    if (ret) {
        Serial.print("PEC check failed: ");
        Serial.print(crc, HEX);
        Serial.print("(cal) vs ");
        Serial.print(buf[n], HEX);
        Serial.println("(get)");
    }
    return ret;
}

int16_t FlameSensor::conv8us_s16_le(uint8_t* buf, int n) {
    uint16_t ret;
    ret = (uint16_t)buf[n];
    ret += ((uint16_t)buf[n + 1]) << 8;
    return (int16_t)ret;
}

int FlameSensor::getCandlesLit(double thresholdTemp) {
    int activeCount = 0;
    for (int i = 0; i < N_PIXEL; i++) {
        if (pix_data[i] >= thresholdTemp) {
            activeCount++;
        }
    }
    return activeCount;
}

void FlameSensor::printArray() {
    for (int i = 0; i < N_PIXEL; i++) {
        Serial.print(pix_data[i]);
        Serial.print("\t");
        if ((i + 1) % 4 == 0) {
            Serial.println(); // Starts a new line every 4 pixels
        }
    }
    Serial.println("--------------------");
}
