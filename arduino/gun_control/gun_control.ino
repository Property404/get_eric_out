#include <AccelStepper.h>
#include "Controller.h"
#define BAUD_RATE 9600
Controller controller;

void setup()
{
  Serial.begin(BAUD_RATE);
  Serial.print("setup() start\n");
  Serial.print("setup() end\n");
}

void loop() {
  controller.yawTo(20000);
  controller.yawTo(-20000);
}
