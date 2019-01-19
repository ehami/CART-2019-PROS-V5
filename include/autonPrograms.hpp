

void lcdScriptExecute();
void doNothing();
void justShoot();
void leftNear();
void leftFar();
void rightNear();
void rightFar();

extern int selection;
extern const char *titles[6];
extern void (*scripts[])();
