#ifndef BOAVIAGEM_H
#define BOAVIAGEM_H

void DrawBoaViagem(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void UpdateBoaViagem(Screen *currentScreen, Vector2 mousePosition, Assets assets);

extern PokeNode *boaViagemHead;
extern PokeNode *boaViagemTail;

#endif