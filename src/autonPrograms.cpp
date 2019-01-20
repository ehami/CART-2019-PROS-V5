#include "main.h"

// All of the different autotnomous routines for the normal game and for robot
// skills
int selection = 0;
const char *titles[] = {"Do Nothing",         "Just Shoot", "Left Near",
                        "Left Far",           "Right Near", "Right Far",
                        "skillsAutonLeftNear"};
void (*scripts[])() = {&doNothing, &justShoot, &leftNear,           &leftFar,
                       &rightNear, &rightFar,  &skillsAutonLeftNear};

void lcdScriptExecute() { scripts[selection](); }

void justShoot() {
  pros::lcd::set_text(4, "Auton Enabled. Starting.");
  brakeDriveWheels();
  pros::delay(100);

  shootBall();
  delayUntilShooterReady();
  pros::delay(200);
}

void doNothing() {
  pros::lcd::print(1, "running do nothing");
  pros::delay(1000);
}

void leftNear() {
  justShoot();
  driveForDistance(-270, -270);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(395, -395);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-550, -550);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-385, 385);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1400, -1400, 200);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}

void leftFar() {
  justShoot();
  driveForDistance(-270, -270);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  // CCW
  driveForDistance(-395, 395);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-550, -550);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  // CW
  driveForDistance(385, -385);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1400, -1400, 200);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}

void rightNear() {
  justShoot();
  // drive forward
  driveForDistance(270, 270);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  // turn CW 90
  driveForDistance(395, -395);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-530, -530);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
  // turn CW 90
  driveForDistance(420, -420);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1400, -1400, 200);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}

void rightFar() {
  justShoot();
  // drive forward
  driveForDistance(270, 270);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  // turn CW 90
  driveForDistance(-395, 395);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-580, -580);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
  // turn CW 90
  driveForDistance(-420, 420);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1400, -1400, 200);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}

void skillsAutonLeftNear() {
  justShoot();
  driveForDistance(-270, -270);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(395, -395);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-550, -550);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-385, 385);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1700, -1700, 200);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}
