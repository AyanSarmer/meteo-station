#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "text.h"

#define TS_SAVE_FLAG_OFF                         0
#define TS_SAVE_FLAG_ON                          1
#define DS_SAVE_FLAG_OFF                         0
#define DS_SAVE_FLAG_ON                          1

/* menu states */
#define FRAME_SCROLL                             0
#define PARAMETER_SETTING                        1

void displayInit();
void drawMenu();
void drawFrame();
void MAINcontrol();
void TDEcontrol();
void TScontrol();
void TScontrolButtonPressedShort();
void TScontrolRotorTurnedCW();
void TScontrolRotorTurnedCCW();
void DScontrol();
void DScontrolButtonPressedShort();
void DScontrolRotorTurnedCW();
void DScontrolRotorTurnedCCW();

#endif /* DISPLAY_H_ */