#include <AccelStepper.h>
#include "Controller.h"

Controller::Controller()
{
	const int HALFSTEP = 8;
	yawn_stepper = AccelStepper(HALFSTEP, YAWN_IN1, YAWN_IN3, YAWN_IN2, YAWN_IN4);
	yawn_stepper.setMaxSpeed(YAWN_MAX_SPEED);
	yawn_stepper.setAcceleration(YAWN_ACCELERATION);
	yawn_stepper.setSpeed(YAWN_SPEED);
}

void Controller::yawn(int b)
{
	yawn_stepper.move(b);
}

void Controller::yawnRight(int b)
{
	yawn(b);
}

void Controller::yawnLeft(int b)
{
	yawnRight(-b);
}

void Controller::yawnTo(int b)
{
	yawn_stepper.moveTo(b);
	while(yawn_stepper.distanceToGo() != 0)
	{
		yawn_stepper.run();
	}
}
