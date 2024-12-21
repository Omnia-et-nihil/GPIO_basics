#ifndef LED_h

#include "Arduino.h"

#define LED_h

class LED{
  public:
    LED();
    void begin(byte pin);
    void on();
    void off();
    void toggle();
    bool status();
    void blink(unsigned long spacing);
    void blink(unsigned long timeOn, unsigned long timeOff);
    void pwm(byte val);


    private:
    byte _pin;
    bool _state;
    unsigned long _lastOn;
    unsigned long _lastOff;


};
















#endif

