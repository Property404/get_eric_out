#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller{
public:
	static const int YAWN_SPEED = 400;
	static const int YAWN_ACCELERATION = 100;
	static const int YAWN_MAX_SPEED = 1000;
	static const int PITCH_SPEED = YAWN_SPEED;
	static const int PITCH_ACCELERATION = YAWN_ACCELERATION;
	static const int PITCH_MAX_SPEED = YAWN_MAX_SPEED;
private:
	// The association between the pins on the Arduino and on the Stepper driver
	static const int YAWN_IN1 = 3;
	static const int YAWN_IN2 = 4;
	static const int YAWN_IN3 = 5;
	static const int YAWN_IN4 = 6;

	static const int PITCH_IN1 = 7;
	static const int PITCH_IN2 = 8;
	static const int PITCH_IN3 = 9;
	static const int PITCH_IN4 = 10;

	// Physical steppers
	AccelStepper yawn_stepper;
	AccelStepper pitch_stepper;

	// Private methods
	void yawn(int);
	void pitch(int);
public:
	Controller();
	// One of these calls yawn(-n) and one calls yawn(n)
	void yawnLeft(int);
	void yawnRight(int);
	// Move to a particular spot
	void yawnTo(int);

	// Pitch counterparts
	void pitchUp(int);
	void pitchDown(int);
	// Move to a particular spot
	void pitchTo(int);
};
#endif
