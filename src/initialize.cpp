#include "main.h"

void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "Oooh, touchy~");
  } else {
    pros::lcd::clear_line(2);
  }
  initMotors();
}

void on_right_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "Auton Enabled.");
  } else {
    pros::lcd::set_text(2, "Auton Disabled.");
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  printf("Init started\n");
  pros::lcd::initialize();

  // Sets a callback function for the buttons
  pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn2_cb(on_right_button);

  pros::lcd::set_text(1, "Initialized");
  printf("Init finished\n");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  printf("Robot disabled\n");
  pros::lcd::set_text(1, "How Rude! Someone Disabled Me!");
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() { printf("Comp Init Started&Ended\n"); }
