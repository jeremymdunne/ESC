#include "ESC.h"


ESC::ESC(int pin){
  _esc.attach(pin);
  _pin = pin;
}

ESC::ESC(int pin, long spoolUpValue){
  _esc.attach(pin);
  _pin = pin;
  _spoolup = spoolUpValue;
  writeMicroseconds(_min);
}


void ESC::writePowerPercent(float percent){
  if(percent > 1 || percent < 0) return;
  if(percent < .01) writeMicroseconds(_min);
  else{
    long microseconds = _spoolup + (long)((_spoolup - _min) * percent + .5);
    writeMicroseconds(microseconds);
  }
}

void ESC::writeMicroseconds(long microseconds){
  if(microseconds > _max) microseconds = _max;
  else if(microseconds < _min) microseconds = _min;
  //Serial.println("writing " + String(microseconds));
  _esc.writeMicroseconds(microseconds);
}

void ESC::disable(){
  _esc.detach();
}

long ESC::getWriteMicroseconds(){
  return _esc.readMicroseconds();
}

float ESC::getWritePowerPercent(){
  return (float)(getWriteMicroseconds() - _spoolup)/( _max - _spoolup);
}
