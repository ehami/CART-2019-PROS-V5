

void lcdScriptExecute();
void doNothing();
void justShoot();
void leftNear();
void leftFar();
void rightNear();
void rightFar();
void skillsAutonLeftNear();

extern int selection;
extern const char *titles[7];
extern void (*scripts[7])();
