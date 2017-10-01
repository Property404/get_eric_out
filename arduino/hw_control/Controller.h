#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller{
public:
	static const int YAW_SPEED = 400;
	static const int YAW_ACCELERATION = 1000;
	static const int YAW_MAX_SPEED = 1000;
	static const int PITCH_SPEED = YAW_SPEED;
	static const int PITCH_ACCELERATION = YAW_ACCELERATION;
	static const int PITCH_MAX_SPEED = YAW_MAX_SPEED;

	static const int GUN_PIN = 11;
private:
	// The association between the pins on the Arduino and on the Stepper driver
	static const int YAW_IN1 = 3;
	static const int YAW_IN2 = 4;
	static const int YAW_IN3 = 5;
	static const int YAW_IN4 = 6;

	static const int PITCH_IN1 = 7;
	static const int PITCH_IN2 = 8;
	static const int PITCH_IN3 = 9;
	static const int PITCH_IN4 = 10;

	// Physical steppers
	AccelStepper yaw_stepper;
	AccelStepper pitch_stepper;

	// Private methods
	void yaw(int);
	void pitch(int);
public:
	Controller();
	// One of these calls yaw(-n) and one calls yaw(n)
	void yawLeft(int);
	void yawRight(int);
	// Move to a particular spot
	void yawTo(int);

	// Pitch counterparts
	void pitchUp(int);
	void pitchDown(int);
	// Move to a particular spot
	void pitchTo(int);

	void shoot();
};
#endif
