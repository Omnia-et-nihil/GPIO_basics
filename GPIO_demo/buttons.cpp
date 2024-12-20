
// v1.0

#include "buttons.h"

#define DEBOUNCE_DEFAULT 50

pullupButton::pullupButton(){
  _debounceDelay = DEBOUNCE_DEFAULT;
}

void pullupButton::begin(byte pin, unsigned long debounceDelay){
  _pin = pin;
  _debounceDelay = debounceDelay;
  pinMode(_pin, INPUT_PULLUP);
}

void pullupButton::begin(byte pin){
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

void pullupButton::changeDebounceDelay(unsigned long debounceDelay){
  _debounceDelay = debounceDelay;
}

void pullupButton::end(){
  pinMode(_pin, OUTPUT);
}

bool pullupButton::releaseRead(){
  _readingRR = digitalRead(_pin);
  if(_readingRR){
    _debounceTimeRR = micros();
    if(_buttonReturnRR){
      _buttonReturnRR = false;
      return true;
    }else{
      return false;
    }
  }else{
    if(micros() - _debounceTimeRR > _debounceDelay){
      _buttonReturnRR = true;
      return false;
    }else{
      return false;
    }
  }
}

bool pullupButton::singlePressRead(){   
  _readingSPR = digitalRead(_pin);
  if(_readingSPR){
    _debounceTimeSPR =  micros();
    _buttonReturnSPR = true;
    return false;
  }else{
    if(micros() - _debounceTimeSPR > _debounceDelay){
      if(_buttonReturnSPR){
        _buttonReturnSPR = false;
        return true;
      }else{
        return false;
      }
    }else{
      return false;
    }
  }
}

bool pullupButton::_pressHoldBegin(){   
  _readingPHB = digitalRead(_pin);
  if(_readingPHB){
    _debounceTimePHB =  micros();
    _buttonReturnPHB = true;
    return false;
  }else{
    if(micros() - _debounceTimePHB > _debounceDelay){
      if(_buttonReturnPHB){
        _buttonReturnPHB = false;
        return true;
      }else{
        return false;
      }
    }else{
      return false;
    }
  }
}

bool pullupButton::_pressHoldEnd(){
  _readingPHE = digitalRead(_pin);
  if(_readingPHE){
    _debounceTimePHE = micros();
    if(_buttonReturnPHE){
      _buttonReturnPHE = false;
      return true;
    }else{
      return false;
    }
  }else{
    if(micros() - _debounceTimePHE > _debounceDelay){
      _buttonReturnPHE = true;
      return false;
    }else{
      return false;
    }
  }
}

unsigned long pullupButton::pressHoldRead(unsigned long spacing){
  if(_pressHoldBegin()){
    _count = 1;
    _spacingStart = micros();
  }
  if(_count && micros() - _spacingStart > spacing){
    _count++;
    _spacingStart = micros();
  }
  if(_pressHoldEnd()){
    _count = 0;
  }
  return _count; 
}

bool pullupButton::_multiReadBegin(){   
  _readingMRB = digitalRead(_pin);
  if(_readingMRB){
    _debounceTimeMRB =  micros();
    _buttonReturnMRB = true;
    return false;
  }else{
    if(micros() - _debounceTimeMRB > _debounceDelay){
      if(_buttonReturnMRB){
        _buttonReturnMRB = false;
        return true;
      }else{
        return false;
      }
    }else{
      return false;
    }
  }
}

unsigned long pullupButton::multiClickRead(unsigned long spacing){
  if(_count == 0){
    if(_multiReadBegin()){
      _count = 1;
      _spacingStart = micros();
    }
  }else{
    if(micros() - _spacingStart < spacing){
      if(_multiReadBegin()){
        _count++;
        _spacingStart = micros();
      }
    }else{
      _count = 0;
    }
  }
  return _count; 
}





