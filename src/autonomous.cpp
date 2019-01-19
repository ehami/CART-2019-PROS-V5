#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  printf("Auton started\n");

  lcdScriptExecute();

  bool isAutonEnabled = false;

  if (isAutonEnabled) {

    // flip cap
    /*driveForDistance(1450, 1450);
    pros::delay(3000);

    setLiftToPosition(1800);
    pros::delay(3000);

    turnActuator(180);
    driveForDistance(-200, -200);
    pros::delay(2000);

    setLiftToPosition(-1800);
    pros::delay(3000);

    driveForDistance(-600, -600);
    pros::delay(3000);*/
  }

  pros::lcd::set_text(4, "Auton Ended.");
}
