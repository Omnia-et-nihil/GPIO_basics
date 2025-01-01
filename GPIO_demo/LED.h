#ifndef LED_h

#include "Arduino.h"

#define LED_h

class LED{
  public:
    LED();
    void begin(byte pin);
    bool state;
    void on();
    void off();
    void pwOff();
    void toggle();
    void blink(unsigned long spacing);
    void blink(unsigned long timeOn, unsigned long timeOff);
    void pwm(byte val);
    byte breathe(unsigned long breatheRate);
    bool pulseRunning;
    void pulse(bool &pulseBegin, unsigned long pulseDuration);
    bool patternRunning;
    void pattern(bool &patternBegin, unsigned int ptrn[]);


    private:
    byte _pin;
    unsigned long _lastOn;
    unsigned long _lastOff;


};
















#endif

