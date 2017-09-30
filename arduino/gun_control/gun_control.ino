#include <AccelStepper.h>
#include "Controller.h"
#define BAUD_RATE 9600
// commands
#define YAWN_COMMAND 'y'
#define PITCH_COMMAND 'p'
#define SHOOT_COMMAND 's'
// Command modifiers
#define TO 't'
#define RIGHT 'r'
#define LEFT 'l'
#define UP 'u'
#define DOWN 'd'

Controller controller;

void parseCommands(void);

void setup()
{
  Serial.begin(BAUD_RATE);
  Serial.print("setup() start\n");
  Serial.print("setup() end\n");
}

void loop()
{
	parseCommands();
}

void parseCommands()
{
	if(Serial.available() > 0)
  {
		switch(Serial.read())
		{
		case YAWN_COMMAND:
			if(Serial.available() > 0)
			{
				switch(Serial.read())
				{
					case TO:
						if(Serial.available() > 1)
						{
							controller.yawTo((Serial.read()<<8)+Serial.read());
						}
						break;
					case RIGHT:
						if(Serial.available() > 1)
						{
							controller.yawRight((Serial.read()<<8)+Serial.read());
						}
						break;
					case LEFT:
						if(Serial.available() > 1)
						{
							controller.yawLeft((Serial.read()<<8)+Serial.read());
						}
						break;
				}
			}
			break;
		}
	}
}
