#include <AccelStepper.h>
#include "Controller.h"

Controller::Controller()
{
	const int HALFSTEP = 8;
	yaw_stepper = AccelStepper(HALFSTEP, YAW_IN1, YAW_IN3, YAW_IN2, YAW_IN4);
	yaw_stepper.setMaxSpeed(YAW_MAX_SPEED);
	yaw_stepper.setAcceleration(YAW_ACCELERATION);
	yaw_stepper.setSpeed(YAW_SPEED);
}

static void move(AccelStepper* s, int b)
{
	s->move(b);
}
static void moveTo(AccelStepper* s, int b)
{
	s->moveTo(b);
	while(s->distanceToGo() != 0)
	{
		s->run();
	}
}


void Controller::yaw(int b)
{
	move(&yaw_stepper, b);
}

void Controller::yawRight(int b)
{
	yaw(b);
}

void Controller::yawLeft(int b)
{
	yawRight(-b);
}

void Controller::yawTo(int b)
{
	moveTo(&yaw_stepper, b);
}

void Controller::pitch(int b)
{
	move(&pitch_stepper, b);
}

void Controller::pitchUp(int b)
{
	pitch(b);
}

void Controller::pitchDown(int b)
{
	pitchUp(-b);
}

void Controller::pitchTo(int b)
{
	moveTo(&pitch_stepper, b);
}
