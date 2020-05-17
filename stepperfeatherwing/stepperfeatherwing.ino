#include "tmc5130.h"

TMC5130 tmc1(5); // stepper 1
TMC5130 tmc2(4); // stepper 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(4000);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("setup SPI for TMC");
  setupSpiForTMC();
  Serial.println("done");
  Serial.println("setup TMC");
  tmc1.begin();
  tmc2.begin();
  Serial.println("done");
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void loop() {
  tmc1.move(51200, false); // should be one turn with 1.8 degrees and 256 micro steps
  tmc2.move(51200, false); // should be one turn with 1.8 degrees and 256 micro steps
  digitalWrite(LED_BUILTIN, HIGH);
  delay(4000);
  tmc1.move(0, false); // should be one turn back with 1.8 degrees and 256 micro steps
  tmc2.move(0, false); // should be one turn back with 1.8 degrees and 256 micro steps
  digitalWrite(LED_BUILTIN, LOW);
  delay(4000);

}
