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


void Controller::yawn(int b)
{
	move(&yawn_stepper, b);
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
	moveTo(&yawn_stepper, b);
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
