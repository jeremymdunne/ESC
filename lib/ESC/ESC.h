#ifndef _ESC_H_
#define _ESC_H_

#include <Servo.h>

Servo esc; 

class ESC{
public:
  ESC(int pin);
  ESC(int pin, long min, long max);
  ESC(int pin, long min, long max);


};

#endif
