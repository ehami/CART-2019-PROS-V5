#include "main.h"

void on_center_button() { initMotors(); }

void on_left_button() {
  selection = (selection - 1 + (num_scripts - 1)) % num_scripts;
  pros::lcd::set_text(2, titles[selection]);
}
void on_right_button() {
  selection = (selection + 1) % num_scripts;
  pros::lcd::set_text(2, titles[selection]);
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
  pros::lcd::register_btn0_cb(on_left_button);
  pros::lcd::register_btn2_cb(on_right_button);

  pros::lcd::set_text(1, "Initialized");
  pros::lcd::set_text(2, titles[selection]);

  // std::string text("PROS");
  // pros::Task my_task(printTemps, (void *)"PROS", TASK_PRIORITY_DEFAULT,
  //                   TASK_STACK_DEPTH_DEFAULT, "My Task");
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
