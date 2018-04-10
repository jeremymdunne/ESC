#include <Arduino.h>
#include "ESC.h"

ESC *motor1;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    while(!Serial.available());
    motor1 = new ESC(PA6, 1280, 2000);
    delay(1000);
    Serial.println("Writing LOW!");
    motor1->writePowerPercent(0);
    Serial.flush();
}
long value = 1260;
void loop() {
    // put your main code here, to run repeatedly:
    while(!Serial.available()){
      value += 10;
      motor1->writeMicroseconds(value);
      delay(300);
    }
    if(Serial.available()){
      motor1->writeMicroseconds(1200);
      while(true);
    }
}
