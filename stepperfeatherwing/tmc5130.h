#ifndef TMC5130_H
#define TMC5130_H

#include "spiHelper.h"

class TMC5130
{
public:
  TMC5130(int csPin);

  void begin();

  void move(unsigned long steps, bool backwards);
  
private:
  int csPin;
  
};

#endif
