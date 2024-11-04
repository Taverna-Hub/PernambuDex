#include <stdio.h>
#include <raylib.h>
#include "utils/constants.h"
#include "utils/resizeImage/resizeImage.h"
#include "utils/init/init.h"
#include "utils/cleanup/cleanup.h"
#include "screens/menu/menu.h"
#include "screens/select-place/place.h"
#include "screens/feira/feira.h"
#include "screens/olinda/olinda.h"
#include "character/character.h"

// Lendário - 1
// Raro - 4
// Comum - 6
// Lixo - 9

int main(void)
{
  Screen currentScreen = MENU;

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pernambudex");

  Assets assets = LoadAssets();
  Vector2 mousePosition = GetMousePosition();
  inicializeCharacter("coiso", 0);
  initializePokemon(assets);

  for (int i = 1; i < 5; i++)
  {
    if (pokemons[i].rarity == COMMON)
    {
      for (int j = 0; j < 5; j++)
      {
        inserir(&olindaHead, &olindaTail, pokemons[i]);
      }
    }

    if (pokemons[i].rarity == RARE)
    {
      for (int j = 0; j < 3; j++)
      {
        inserir(&olindaHead, &olindaTail, pokemons[i]);
      }
    }

    inserir(&olindaHead, &olindaTail, pokemons[i]);
  }

  for (int i = 0; i < 9; i++)
  {
    inserir(&olindaHead, &olindaTail, pokemons[0]);
  }

  HideCursor();
  while (!WindowShouldClose())
  {
    BeginDrawing();
    mousePosition = GetMousePosition();

    if (currentScreen == MENU)
    {
      DrawMenu(&currentScreen, mousePosition, assets);
      UpdateMenu(&currentScreen, mousePosition, assets);
    }
    else if (currentScreen == SELECT_PLACE)
    {
      DrawSelectPlace(&currentScreen, mousePosition, assets);
      UpdateSelectPlace(&currentScreen, mousePosition, assets);
    }
    else if (currentScreen == FEIRA)
    {
      DrawFeira(&currentScreen, mousePosition, assets);
      UpdateFeira(&currentScreen, mousePosition, assets);
    }
    else if (currentScreen == OLINDA)
    {
      DrawOlinda(&currentScreen, mousePosition, assets);
      UpdateOlinda(&currentScreen, mousePosition, assets);
    }

    assets.pernamBall.width = 24;
    assets.pernamBall.height = 24;
    DrawTexture(assets.pernamBall, mousePosition.x, mousePosition.y, WHITE);
    EndDrawing();
  }

  UnloadAssets(assets);
  CloseWindow();

  return 0;
}
