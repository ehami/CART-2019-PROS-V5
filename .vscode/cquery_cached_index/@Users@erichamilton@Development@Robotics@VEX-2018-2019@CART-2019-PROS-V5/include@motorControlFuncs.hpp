
// resets all motor encoder positions to zero
void resetMotorEncoderPositions();

// initializes all motors with correct settings
void initMotors();

void setDriveWheelsToPower(int left, int right);

// Sets the left motors to a specific velocity. (positive values go forward)
void setLeftWheelsToPower(int power);

// Sets the right motors to a specific velocity. (positive values go
// backward)
void setRightWheelsToPower(int power);

// sets motor target, but does not wait for motor to reach target.
void driveForDistance(double leftInches, double rightInches,
                      int velocity = 100);

bool atDistanceDriveGoal(int threshold);

// sets both lift motors to the same locations
void setLiftToPosition(double percentRaised);

// stop drive wheels
void brakeDriveWheels();

// allow drive wheels to move
void unBrakeDriveWheels();

// sets motors to a specific velocity (not power) in order to be
// consistent. positive goes up
void selLiftToVelocity(int velocity);

// stop lift motors
void brakeLift();
// allow lift to move
void unBrakeLift();

void turnActuator(int degrees);

void moveActuatorVelocity(int velocity);

void shootBall();

void delayUntilShooterReady();

void printTemps();
