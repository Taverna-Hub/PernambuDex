#ifndef FEIRA_H
#define FEIRA_H

typedef enum Levels
{
  LVL_0 = 0,
  LVL_1 = 1,
  LVL_2 = 2,
  LVL_3 = 3,

} Levels;

typedef struct Button
{
  Rectangle blueRect;
  Rectangle redRect;
  Texture2D blueTexture;
  Texture2D redTexture;
  int level;
} Button;

typedef struct Item
{
  Texture2D image;
  int imageSize;
  char *text;
  char *coinNumber;
  Levels level;

} Item;

void DrawFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets);
void UpdateFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets);

#endif