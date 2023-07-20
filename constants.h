#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace cw_osc
{

    static const short LED_PIN = 2;
    static const short LED_MILLS_OFF = 1500;
    static const short LED_MILLS_ON = 100;
    static const short TONE_PIN = 8;
    static const short KEY_PIN = 4;
    static const short MAX_TONE_POT_VALUE = 1200;
    static unsigned long KEY_DOWN_TUNE_THRESHOLD = 2000;
}

#endif // CONSTANTS_H