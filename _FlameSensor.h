#pragma once

#include <Arduino.h>
#include <Wire.h>

class FlameSensor {
public:
    // Initialization
    static void initialize();

    // Call this periodically in loop() to poll the sensor
    static void update();

    // Data getters
    static double getPtav();
    static double getPixel(int index);
    static int getCandlesLit(double thresholdTemp = 50.0);

    static void printArray();

private:
    static const uint8_t D6T_ADDR = 0x0A;  // I2C 7-bit address
    static const uint8_t D6T_CMD = 0x4C;   // D6T command register
    static const int N_ROW = 4;
    static const int N_PIXEL = 16;         // 4x4 grid
    static const int N_READ = ((N_PIXEL + 1) * 2 + 1);

    static uint8_t rbuf[N_READ];
    static double pix_data[N_PIXEL];

    // Helper functions for CRC and byte conversion
    static uint8_t calc_crc(uint8_t data);
    static bool checkPEC(uint8_t buf[], int n);
    static int16_t conv8us_s16_le(uint8_t* buf, int n);
};
