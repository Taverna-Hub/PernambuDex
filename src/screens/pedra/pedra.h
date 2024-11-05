#ifndef PEDRA_H
#define PEDRA_H

void DrawPedra(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void UpdatePedra(Screen *currentScreen, Vector2 mousePosition, Assets assets);

extern PokeNode *pedraHead;
extern PokeNode *pedraTail;

#endif