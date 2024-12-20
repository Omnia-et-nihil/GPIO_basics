// v1.0

#ifndef buttons_h


#include "Arduino.h"

#define buttons_h

class pullupButton{
  public:
    pullupButton();
    void begin(byte pin, unsigned long debounceDelay);
    void begin(byte pin);
    void end();
    void changeDebounceDelay(unsigned long newDebounceDelay);
    bool releaseRead();
    bool singlePressRead();
    unsigned long pressHoldRead(unsigned long spacing);
    unsigned long multiClickRead(unsigned long spacing);
    
  private:
    byte _pin;
    unsigned long _debounceDelay;
    bool  _readingRR;
    bool _lastButtonStateRR;
    bool _buttonReturnRR;
    unsigned long _debounceTimeRR;

    bool  _readingSPR;
    bool _lastButtonStateSPR;
    bool _buttonReturnSPR;
    unsigned long _debounceTimeSPR;

    bool  _readingPHB;
    bool _lastButtonStatePHB;
    bool _buttonReturnPHB;
    unsigned long _debounceTimePHB;
    bool  _readingPHE;
    bool _lastButtonStatePHE;
    bool _buttonReturnPHE;
    unsigned long _debounceTimePHE;
    unsigned long _spacingStart;
    unsigned long _count;
    bool _pressHoldBegin();
    bool _pressHoldEnd();

    bool _buttonReturnMRB;
    bool _readingMRB;
    bool _lastButonStateMRB;
    unsigned long _debounceTimeMRB;
    bool _multiReadBegin();

};

 




#endif


