#ifndef _ESC_H_
#define _ESC_H_
#include <Arduino.h>
#include <Servo.h>



class ESC{
  Servo _esc;
public:
  ESC(int pin);
  ESC(int pin, long spoolUpValue);
  //ESC(int pin, long min, long max);
  void writePowerPercent(float percent);
  void writeMicroseconds(long microseconds);
  void disable();
  long getWriteMicroseconds();
  float getWritePowerPercent();
private:
  long _min = 1200,_max = 1200, _spoolup = 1200;
  int _pin;
};

#endif
