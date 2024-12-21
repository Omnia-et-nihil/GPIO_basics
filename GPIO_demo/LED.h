#include "LED.h"

LED::LED(){
}

void LED::begin(byte pin){
  _pin = pin;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  _state = false;
}

void LED::on(){
  digitalWrite(_pin, HIGH);
  _state = true;
}

void LED::off(){
  digitalWrite(_pin, LOW);
  _state = false;
}

void LED::toggle(){
  digitalWrite(_pin, !_state);
  _state = !_state;
}

bool LED::status(){
  return _state;
}

void LED::blink(unsigned long spacing){
  if(_state){
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
  if(_state){
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

















