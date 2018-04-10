#include "ESC.h"


ESC::ESC(int pin){
  _esc.attach(pin);
  _pin = pin;
  _min = 1000;
  _max = 2000;
}

ESC::ESC(int pin, long min, long max){
  _esc.attach(pin);
  _pin = pin;
  _min = min;
  _max = max;
  writeMicroseconds(min);
}


void ESC::writePowerPercent(float percent){
  if(percent > 1 || percent < 0) return;
  long microseconds = _min + (long)((_max - _min) * percent + .5);
  writeMicroseconds(microseconds);
}

void ESC::writeMicroseconds(long microseconds){
  if(microseconds > _max) microseconds = _max;
  else if(microseconds < _min) microseconds = _min;
  Serial.println("writing " + String(microseconds));
  _esc.writeMicroseconds(microseconds);
}

void ESC::disable(){
  _esc.detach();
}

long ESC::getWriteMicroseconds(){
  return _esc.readMicroseconds();
}

float ESC::getWritePowerPercent(){
  return (float)(getWriteMicroseconds() - _min)/( _max - _min);
}
