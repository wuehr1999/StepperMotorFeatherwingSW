#include "tmc5130.h"

TMC5130 tmc(25);

void setup() {
  // put your setup code here, to run once:
  tmc.begin();
}

void loop() {
  tmc.move(51200, false);
  delay(20000);
  tmc.move(0, false);
  delay(20000);

}
