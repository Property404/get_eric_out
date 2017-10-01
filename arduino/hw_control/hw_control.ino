#include <AccelStepper.h>
#include "Controller.h"
#define BAUD_RATE 9600
// commands
#define YAW_COMMAND 'y'
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
	bool is_yawn = false;
	if(Serial.available() > 0)
 	{
		cbool clear = true;
		switch(Serial.read())
		{
		case SHOOT_COMMAND:
			controller.shoot();
			break;
		case YAW_COMMAND:
			is_yawn = true;
		case PITCH_COMMAND:
			if(Serial.available() > 0)
			{
				clear = false;
				switch(Serial.read())
				{
				case TO:
					if(Serial.available() > 1)
					{
						if(is_yawn)
							controller.yawTo((Serial.read()<<8)+Serial.read());
						else
						  controller.pitchTo((Serial.read()<<8)+Serial.read());
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
				case UP:
					if(Serial.available() > 1)
					{
						controller.pitchUp((Serial.read()<<8)+Serial.read());
					}
					break;
				case DOWN:
					if(Serial.available() > 1)
					{
						controller.pitchDown((Serial.read()<<8)+Serial.read());
					}
					break;
				}
			}else if(!clear){
				Serial.print("Clear\n");
				clear = true;
			}
		break;
		}
	}
}
