#ifndef NOIVA_H
#define NOIVA_H

void DrawNoiva(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void UpdateNoiva(Screen *currentScreen, Vector2 mousePosition, Assets assets);

extern PokeNode *noivaHead;
extern PokeNode *noivaTail;

#endif