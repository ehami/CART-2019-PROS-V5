#include "main.h"

// Motor definitions
pros::Motor
    left_wheels(LEFT_WHEELS_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, false,
                pros::E_MOTOR_ENCODER_DEGREES); // sets gearset and
                                                // encoder to degree mode
pros::Motor right_wheels(
    RIGHT_WHEELS_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, true,
    pros::E_MOTOR_ENCODER_DEGREES); // reverses motor, sets gearset, and
                                    // encoder to degree mode

pros::Motor left_lift(LEFT_LIFT_MOTOR_PORT, false);
pros::Motor right_lift(RIGHT_LIFT_MOTOR_PORT, true);
pros::Motor actuator(ACTUATOR_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, true,
                     pros::E_MOTOR_ENCODER_DEGREES);
// set motors to actively hold position

// initializes all motors with correct settings
void initMotors() {
  left_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  right_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  actuator.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

// resets all motor encoder positions to zero
void resetMotorEncoderPositions() {
  left_wheels.set_zero_position(left_wheels.get_position());
  right_wheels.set_zero_position(right_wheels.get_position());

  left_lift.set_zero_position(left_lift.get_position());
  right_lift.set_zero_position(right_lift.get_position());
}

// sets motors to a specific velocity (not actually power) in order to be
// consistent. positive goes forward
void setDriveWheelsToPower(int left, int right) {
  setLeftWheelsToPower(left);
  setRightWheelsToPower(right);
}

// Sets the left motors to a specific velocity. (positive values go forward)
void setLeftWheelsToPower(int power) { left_wheels.move(power); }

// Sets the right motors to a specific velocity. (positive values go
// forward sice motor is reversed)
void setRightWheelsToPower(int power) { right_wheels.move(power); }

// sets motor target, but does not wait for motor to reach target.
void driveForDistance(double leftInches, double rightInches) {
  left_wheels.move_relative(leftInches / 30, 600);
  right_wheels.move_relative(rightInches / 30, 600);
}

// returns true/false as to wheter the drive wheels have reached their position
// goal set by driveForDistance
bool atDistanceDriveGoal(int threshold) {
  return (abs(right_wheels.get_position() -
              right_wheels.get_target_position()) < threshold) &&
         (abs(left_wheels.get_position() - left_wheels.get_target_position()) <
          threshold);
}

// sets both lift motors to the same locations
void setLiftToPosition(double percentRaised) {
  if (percentRaised > 100) {
    percentRaised = 100;
  } else if (percentRaised < -100) {
    percentRaised = -100;
  }

  left_lift.move_absolute(percentRaised * 320 * 10.0 / 8, 600);
  right_lift.move_absolute(percentRaised * 320 * 10.0 / 8, 600);
}

// stop drive wheels
void brakeDriveWheels() {
  left_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  driveForDistance(0, 0);
}
// allwo drive wheels to move
void unBrakeDriveWheels() {
  left_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  right_wheels.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

// sets motors to a specific velocity (not power) in order to be
// consistent. positive goes up
void selLiftToVelocity(int velocity) {
  left_lift.move_velocity(velocity);
  right_lift.move_velocity(velocity);
}

// stop lift motors
void brakeLift() {
  left_lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  left_lift.move_relative(0, 200);
  right_lift.move_relative(0, 200);
}
// allow lift to move
void unBrakeLift() {
  left_lift.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  right_lift.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void turnActuator(int degrees) { actuator.move_relative(degrees * 5, 200); }
