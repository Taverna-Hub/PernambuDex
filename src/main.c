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

void imprimir(PokeNode *head, PokeNode *tail)
{
  if (head != NULL)
  {
    do
    {
      printf("%s -> ", head->pokemon.name);
      head = head->next;
    } while (head != tail->next);
  }
  printf("NULL\n");
}

int main(void)
{
  Screen currentScreen = MENU;

  PokeNode *olindaHead = NULL;
  PokeNode *olindaTail = NULL;

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pernambudex");

  Assets assets = LoadAssets();
  Vector2 mousePosition = GetMousePosition();
  inicializeCharacter("coiso", 0);
  initializePokemon(assets);

  initializeCircularList(pokemons, &olindaHead, &olindaTail, 1);

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
