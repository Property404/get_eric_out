#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller{
public:
	static const int YAWN_SPEED = 400;
	static const int YAWN_ACCELERATION = 100;
	static const int YAWN_MAX_SPEED = 1000;
private:
	// The association between the pins on the Arduino and on the Stepper driver
	static const int YAWN_IN1 = 3;
	static const int YAWN_IN2 = 4;
	static const int YAWN_IN3 = 5;
	static const int YAWN_IN4 = 6;
	// Physical stepper
	AccelStepper yawn_stepper;

	// Private methods
	void yawn(int);
public:
	Controller();
	// One of these calls yawn(-n) and one calls yawn(n)
	void yawnLeft(int);
	void yawnRight(int);
	// Move to a particular spot
	void yawnTo(int);
};
#endif
