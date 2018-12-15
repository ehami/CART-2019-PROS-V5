#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  printf("Opcontrol started\n");

  // master (Ian's) controller
  pros::Controller master(pros::E_CONTROLLER_MASTER);

  int power;
  int turn;

  while (true) {
    // Drive Wheels
    power = master.get_analog(ANALOG_LEFT_Y);
    turn = master.get_analog(ANALOG_RIGHT_X);
    pros::lcd::print(4, "p:%d t:%d/n", power, turn);

    if (master.get_digital(DIGITAL_B)) {
      brakeDriveWheels();
    } else if (abs(power) > 5 || abs(turn) > 5) {
      unBrakeDriveWheels();
      setDriveWheelsToPower(power + turn, power - turn);
    } else {
      setDriveWheelsToPower(0, 0);
    }
    // Raise/Lower Lift
    if (master.get_digital(DIGITAL_L1)) {
      unBrakeLift();
      selLiftToVelocity(200);
    } else if (master.get_digital(DIGITAL_R1)) {
      unBrakeLift();
      selLiftToVelocity(-200);
    } else {
      brakeLift();
    }

    if (master.get_digital_new_press(DIGITAL_LEFT)) {
      turnActuator(-180);
    } else if (master.get_digital_new_press(DIGITAL_RIGHT)) {
      turnActuator(180);
    }

    pros::delay(20);
  }
}
