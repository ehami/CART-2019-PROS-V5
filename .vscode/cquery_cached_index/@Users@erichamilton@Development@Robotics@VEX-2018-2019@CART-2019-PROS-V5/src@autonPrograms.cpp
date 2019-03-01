#include "main.h"

// All of the different autotnomous routines for the normal game and for robot
// skills
int num_scripts = 9; // CHANGE LENGTHS OF LISTS IN extern STATEMENTS IN HEADER!!
int selection = 7;
const char *titles[] = {
    "Do Nothing",       "Just Shoot", "Left Near",           "Left Far",
    "Right Near",       "Right Far",  "skillsAutonLeftNear", "Left Far AND CAP",
    "Right Far AND CAP"};
void (*scripts[])() = {
    &doNothing, &justShoot,           &leftNear,   &leftFar,    &rightNear,
    &rightFar,  &skillsAutonLeftNear, &leftFarCap, &rightFarCap};

void lcdScriptExecute() { scripts[selection](); }

void justShoot() {
  pros::lcd::set_text(4, "Auton Enabled. Starting.");

  // more reliable distance independent of battery level.
  brakeDriveWheels();
  // weird motor bugs w/o delay here
  pros::delay(200);

  shootBall();              // turns shooter trigger ~1/3 of a turn
  delayUntilShooterReady(); // wait until shooter has shot
  pros::delay(
      400); // wait for ball to leave robot (to posibly start moving robot)
}

void doNothing() { // highly decriptive.
  pros::lcd::set_text(1, "running do nothing");
  pros::delay(1000);
}

void leftNear() {               // Red, near flags
  justShoot();                  // shoot ball
  driveForDistance(-270, -270); // drive away from wall
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5)); // wait until reached goal

  driveForDistance(395, -395); // turn CW
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15)); // account for greater dif. between wheels

  driveForDistance(-620, -620); // drive to line up with platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-385, 385); // turn CCW towards platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1400, -1400, 200); // drive onto platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}

void leftFar() {                // Red, away from flags
  justShoot();                  // shoot
  driveForDistance(-270, -270); // drive away from wall
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-395, 395); // turn CW
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-570, -570);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  // CW
  driveForDistance(385, -385);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1300, -1300, 200);
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
  driveForDistance(470, -470);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-560, -560);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
  // turn CW 90
  driveForDistance(480, -480);
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
  driveForDistance(250, 250);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  // turn CW 90
  driveForDistance(-390, 390);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-595, -595);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
  // turn CW 90
  driveForDistance(-430, 430);
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
  brakeDriveWheels();
  driveForDistance(-220, -220);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(395, -395);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-575, -575);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-375, 375);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1750, -1750, 150);
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}

void leftFarCap() {             // Red, away from flags
  justShoot();                  // shoot
  driveForDistance(-350, -350); // drive away from wall
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-700, 700); // turn CCW
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(1000, 1000, 100); // drive towards cap
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(20));

  turnActuator(180);
  pros::delay(1000);

  // driveForDistance(100, 100); // back up from cap
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(10));

  driveForDistance(-1100, -1100, 200); // back up from cap
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(190, -190, 200); // turn to begin lineup with platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));
  setLiftToPosition(0);

  // CW
  driveForDistance(-420, -420); // move to lineup wiyth platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  // CW
  driveForDistance(410, -410, 200); // turn to face platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(25));

  driveForDistance(-1100, -1100, 200); // drive onto platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}

void rightFarCap() {
  justShoot();                // shoot
  driveForDistance(350, 350); // drive away from wall
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-200, 200); // turn CCW
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(25));

  driveForDistance(900, 900); // drive towards cap
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(30));

  turnActuator(180);
  pros::delay(1000);
  driveForDistance(100, 100); // back up from cap
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(10));

  driveForDistance(-1100, -1100); // back up from cap
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));

  driveForDistance(-200, 200); // turn to begin lineup with platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));
  setLiftToPosition(0);

  // CW
  driveForDistance(-420, -420); // move to lineup wiyth platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  // CW
  driveForDistance(-410, 410); // turn to face platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(15));

  driveForDistance(-1100, -1100, 200); // drive onto platform
  do {
    pros::delay(20);
  } while (!atDistanceDriveGoal(5));
}
