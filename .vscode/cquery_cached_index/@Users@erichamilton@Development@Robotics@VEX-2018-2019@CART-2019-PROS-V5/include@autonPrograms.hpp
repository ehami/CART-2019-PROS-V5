

void lcdScriptExecute();
void doNothing();
void justShoot();
void leftNear();
void leftFar();
void rightNear();
void rightFar();
void skillsAutonLeftNear();
void leftFarCap();
void rightFarCap();

extern int num_scripts;
extern int selection;
extern const char *titles[9];
extern void (*scripts[9])();
