#include "LED.h"

LED::LED(){
}

void LED::begin(byte pin){
  _pin = pin;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  state = false;
  pulseRunning = false;
  patternRunning = false;
}

void LED::on(){
  digitalWrite(_pin, HIGH);
  state = true;
}

void LED::off(){
  digitalWrite(_pin, LOW);
  state = false;
}

void LED::toggle(){
  digitalWrite(_pin, !state);
  state = !state;
}

void LED::blink(unsigned long spacing){
  if(state){
    if(millis() - _lastOn > spacing){
      off();
      _lastOff = millis();
    }
  }else{
    if(millis() - _lastOff > spacing){
      on();
      _lastOn = millis();
    }
  }
}

void LED::blink(unsigned long timeOn, unsigned long timeOff){
  if(state){
    if(millis() - _lastOn > timeOn){
      off();
      _lastOff = millis();
    }
  }else{
    if(millis() - _lastOff > timeOff){
      on();
      _lastOn = millis();
    }
  }
}

void LED::pwm(byte val){
  analogWrite(_pin, val);
}


byte LED::breathe(unsigned long breatheRate){
  static int breatheDirection;
  static byte breatheVal;
  static unsigned long breatheTime;
  if(millis() - breatheTime > breatheRate){
    if(breatheVal == 255){
      breatheDirection = -1;
    }else if(breatheVal == 0){
      breatheDirection = 1;
    }
    breatheVal += breatheDirection;
    pwm(breatheVal);
    breatheTime -= millis();
    return breatheVal;
  }
}
      
void LED::pulse(bool &pulseBegin, unsigned long pulseDuration){
  static unsigned long pulseStart;
  if(pulseBegin){
    on();
    pulseStart = millis();
    pulseBegin = false;
    pulseRunning = true;
  }
  if(pulseRunning){
    if(millis - pulseStart > pulseDuration){
      off();
      pulseRunning = false;
    }
  }
}

void LED::pattern(bool &patternBegin, unsigned int ptrn[]){
  static unsigned int count;
  static unsigned long lastChange;

  if(patternBegin){
    count = 0;
    on();
    lastChange = millis();
    patternBegin = false;
    patternRunning = true;
  }
  if(patternRunning){
    if(millis() - lastChange > ptrn[count]){
      toggle();
      lastChange = millis();
      count++;
      if(ptrn[count] == 0){
        off();
        patternRunning = 0;
      }
    }
  }
}
















