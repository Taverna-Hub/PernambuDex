#ifndef OLINDA_H
#define OLINDA_H

void DrawOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void UpdateOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void initializePokemonsOlindaList(PokeNode *head, PokeNode *tail);

extern PokeNode *olindaHead;
extern PokeNode *olindaTail;

#endif