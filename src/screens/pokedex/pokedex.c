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
#define X 40


int pokemonId = -1;
int location = -1;
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

void UpdatePokedexScreen(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{ 
  Rectangle leaveButtonRec = {26, 619, 166, 80};
  Rectangle boaViagemButtonRec = {X, 143, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle olindaButtonRec = {X, 213, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle pedraFuradaButtonRec = {X, 283, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle veuNoivaButtonRec = {X, 353, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle lixaoButtonRec = {62, 546, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    if(CheckCollisionPointRec(mousePosition, boaViagemButtonRec)){
      printf("BV\n");
      //todo add sorts e push
    }
    else if(CheckCollisionPointRec(mousePosition, olindaButtonRec)){
      printf("tolete\n");
      //todo add sorts e push
    }
    else if(CheckCollisionPointRec(mousePosition, veuNoivaButtonRec)){
      printf("veu\n");
      //todo add sorts e push
    }
    else if(CheckCollisionPointRec(mousePosition, pedraFuradaButtonRec)){
      printf("forada peda\n");
      //todo add sorts e push
    }
    else if(CheckCollisionPointRec(mousePosition,lixaoButtonRec)){
      printf("lixao\n");
    }
    else{
      //todo add c
    }
    
    if (CheckCollisionPointRec(mousePosition, leaveButtonRec))
    {
      *currentScreen = SELECT_PLACE;
    }
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
  int notselectedLocation_x = 40;
  int selectedLocation_x = 100;

  assets.templateBtnBlue.height = assets.templateBtnRed.height = 40;
  assets.templateBtnBlue.width = assets.templateBtnRed.width = 151;

  Rectangle boaViagemBtnBlueRect = {notselectedLocation_x, 143, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle boaViagemBtnRedRect = {selectedLocation_x, 143, assets.templateBtnBlue.width, assets.templateBtnBlue.height};

  Rectangle olindaBtnBlueRect = {notselectedLocation_x, 213, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle olindaBtnRedRect = {selectedLocation_x, 213, assets.templateBtnBlue.width, assets.templateBtnBlue.height};

  Rectangle pedraFuradaBtnBlueRect = {notselectedLocation_x, 283, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle pedraFuradaBtnRedRect = {selectedLocation_x, 283, assets.templateBtnBlue.width, assets.templateBtnBlue.height};

  Rectangle veuNoivaBtnBlueRect = {notselectedLocation_x, 353,  assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle veuNoivaBtnRedRect = {selectedLocation_x, 353, assets.templateBtnBlue.width, assets.templateBtnBlue.height};


    Button buttons[] = {
      {boaViagemBtnBlueRect, boaViagemBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, BOA_VIAGEM},
      {olindaBtnBlueRect, olindaBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, OLINDA},
      {pedraFuradaBtnBlueRect, pedraFuradaBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, PEDRA},
      {veuNoivaBtnBlueRect, veuNoivaBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, NOIVA}};

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (CheckCollisionPointRec(mousePosition, buttons[i].blueRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
      location = buttons[i].pokemon;
      printf("click x: %lf y: %lf\n", mousePosition.x, mousePosition.y);
    }
  }

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (location == buttons[i].pokemon)
    {
      Vector2 position = {buttons[i].redRect.x + 5, buttons[i].redRect.y};
      DrawTextEx(assets.nunito, "label", position, 20, 1.0f, WHITE);
      DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
    }
    else
    {
      DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
    }
  }

  // leave button
  assets.leaveButtonRed.width = 166;
  assets.leaveButtonRed.height = 80;
  Rectangle leaveButtonRect = {26, 619, assets.leaveButtonRed.width, assets.leaveButtonRed.height};
  
  DrawTexture(assets.leaveButtonRed, leaveButtonRect.x, leaveButtonRect.y, RAYWHITE);

  
}



void pokemonButtons(Assets assets, Vector2 mousePosition, Screen location)
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
}
