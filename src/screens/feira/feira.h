#ifndef FEIRA_H
#define FEIRA_H

void DrawFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void UpdateFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets);

typedef struct Item
{
  Texture2D image;
  int imageSize;
  char text[300];
  char coinNumber[100];
} Item;

typedef struct Button
{
  Rectangle blueRect;
  Rectangle redRect;
  Texture2D blueTexture;
  Texture2D redTexture;
  int botao;
} Button;

void handleInitializeAllItems(Assets assets);
void initializeItems(Item *item, char *coinNumber, char *text, Texture2D image, int imageSize);

#endif