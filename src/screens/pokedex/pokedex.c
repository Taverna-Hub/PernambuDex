#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "pokedex.h"

int pokemonId = -1;

typedef struct Button
{
  Rectangle blueRect;
  Rectangle redRect;
  Texture2D blueTexture;
  Texture2D redTexture;
  int pokemon;
} Button;

static void handleButtons(Assets assets, Vector2 mousePosition);

void push(PokeNode **head, Pokemon pokemon, Screen screen)
{
  if (pokemon.place == screen)
  {

    if (!pokemon.captured)
    {
      return;
    }
    PokeNode *newPokemon = (PokeNode *)malloc(sizeof(PokeNode));
    newPokemon->pokemon = pokemon;
    newPokemon->next = *head;
    *head = newPokemon;
  }
}

void ClearPokedex(PokeNode **head)
{
  while (head != NULL)
  {
    PokeNode *temp = (*head);
    *head = (*head)->next;
    temp = NULL;
    free(temp);
  }
}

void bubbleSort(PokeNode *head)
{
  int swapped;
  PokeNode *actual;
  PokeNode *last = NULL;

  if (head == NULL)
    return;

  do
  {
    swapped = 0;
    actual = head;

    while (actual->next != last)
    {
      if (actual->pokemon.id > actual->next->pokemon.id)
      {
        int temp = actual->pokemon.id;
        actual->pokemon.id = actual->next->pokemon.id;
        actual->next->pokemon.id = temp;
        swapped = 1;
      }
      actual = actual->next;
    }
    last = actual;
  } while (swapped);
}

void updatePokedexScreen(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Rectangle leaveButtonRec = {26, 619, 166, 80};
  if (CheckCollisionPointRec(mousePosition, leaveButtonRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    *currentScreen = SELECT_PLACE;
  }
}

void DrawPokedex(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps olindaBackground = resizeImage(assets.olindaMenu);
  DrawTextureEx(assets.olindaMenu, (Vector2){olindaBackground.x, olindaBackground.y}, 0.0f, olindaBackground.scale, WHITE);

  handleButtons(assets, mousePosition);
}

static void handleButtons(Assets assets, Vector2 mousePosition)
{
  int selectedPokemon = 707;
  int notselectedPokemon = 805;
  // templateBlue
  assets.templateBtnBlue.width = 139;
  assets.templateBtnBlue.height = 40;

  Rectangle templateButtonBlueRec_1 = {notselectedPokemon, 126, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle templateButtonBlueRec_2 = {notselectedPokemon, 221, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle templateButtonBlueRec_3 = {notselectedPokemon, 316, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle templateButtonBlueRec_4 = {notselectedPokemon, 411, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle templateButtonBlueRec_5 = {notselectedPokemon, 506, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  // templateRed

  assets.templateBtnRed.width = 139;
  assets.templateBtnRed.height = 40;

  Rectangle templateBtnRedRec_1 = {selectedPokemon, 126, assets.templateBtnRed.width, assets.templateBtnRed.height};
  Rectangle templateBtnRedRec_2 = {selectedPokemon, 221, assets.templateBtnRed.width, assets.templateBtnRed.height};
  Rectangle templateBtnRedRec_3 = {selectedPokemon, 316, assets.templateBtnRed.width, assets.templateBtnRed.height};
  Rectangle templateBtnRedRec_4 = {selectedPokemon, 411, assets.templateBtnRed.width, assets.templateBtnRed.height};
  Rectangle templateBtnRedRec_5 = {selectedPokemon, 506, assets.templateBtnRed.width, assets.templateBtnRed.height};

  // leave button
  assets.leaveButtonRed.width = 166;
  assets.leaveButtonRed.height = 80;
  Rectangle leaveButtonRect = {26, 619, assets.leaveButtonRed.width, assets.leaveButtonRed.height};

  Button buttons[] = {
      {templateButtonBlueRec_1, templateBtnRedRec_1, assets.templateBtnBlue, assets.templateBtnRed, 0},
      {templateButtonBlueRec_2, templateBtnRedRec_2, assets.templateBtnBlue, assets.templateBtnRed, 1},
      {templateButtonBlueRec_3, templateBtnRedRec_3, assets.templateBtnBlue, assets.templateBtnRed, 2},
      {templateButtonBlueRec_4, templateBtnRedRec_4, assets.templateBtnBlue, assets.templateBtnRed, 3},
      {templateButtonBlueRec_5, templateBtnRedRec_5, assets.templateBtnBlue, assets.templateBtnRed, 4}};

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (CheckCollisionPointRec(mousePosition, buttons[i].blueRect))
    {
      SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
      pokemonId = buttons[i].pokemon;
    }
  }

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (pokemonId == buttons[i].pokemon)
    {
      DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
    }
    else
    {
      DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
    }
  }
  DrawTexture(assets.leaveButtonRed, leaveButtonRect.x, leaveButtonRect.y, RAYWHITE);
}
