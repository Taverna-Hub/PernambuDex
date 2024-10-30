#ifndef MENU_H
#define MENU_H

#include "../../utils/init/init.h"

void DrawMenu(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void UpdateMenu(Screen *currentScreen, Vector2 mousePosition, Assets assets);

#endif