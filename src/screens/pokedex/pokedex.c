#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  int location;
} Button;

typedef struct ButtonPokemon
{
  Rectangle blueRect;
  Rectangle redRect;
  Texture2D blueTexture;
  Texture2D redTexture;
  Pokemon Pokemon;
} ButtonPokemon;

static void showLabel(Assets assets, int x, int y, char *label);
static void handleButtons(Assets assets, Vector2 mousePosition);
void ShowPokemonButtons(Assets assets, Vector2 mousePosition, PokeNode *pokeLocation);
void showPokemon(Assets assets, Pokemon pokemonShown);

void push(PokeNode **head, Pokemon pokemon, Screen screen)
{
  if (pokemon.place == screen)
  {
    PokeNode *newPokemon = (PokeNode *)malloc(sizeof(PokeNode));
    newPokemon->pokemon = pokemon;
    newPokemon->next = *head;
    *head = newPokemon;
  }
}

void ClearPokedex(PokeNode **head)
{
  while (*head != NULL)
  {
    PokeNode *temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

void bubbleSort(PokeNode *head)
{
  if (head == NULL)
    return;

  int swapped;
  PokeNode *actual;
  PokeNode *last = NULL;

  do
  {
    swapped = 0;
    actual = head;
    while (actual->next != last)
    {
      if (actual->pokemon.id > actual->next->pokemon.id)
      {
        Pokemon temp = actual->pokemon;
        actual->pokemon = actual->next->pokemon;
        actual->next->pokemon = temp;
        swapped = 1;
      }
      actual = actual->next;
    }
    last = actual;
  } while (swapped);
}

PokeNode *boaViagemNode;
PokeNode *olindaNode;
PokeNode *pedraFuradaNode;
PokeNode *veuDaNoivaNode;
bool wasClosed = false;
void UpdatePokedexScreen(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Rectangle leaveButtonRec = {26, 619, 166, 80};
  Rectangle boaViagemButtonRec = {X, 143, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle olindaButtonRec = {X, 213, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle pedraFuradaButtonRec = {X, 283, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle veuNoivaButtonRec = {X, 353, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle lixaoButtonRec = {100, 546, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  if (checkCompletion() && !wasClosed){

    assets.completionBanner.width = 1024;
    assets.completionBanner.height = 356;
    DrawTexture(assets.completionBanner, 0, 182, RAYWHITE);

    Rectangle closeCompleteBannerBntRec = {432, 279, assets.templateBtnRed.width, assets.templateBtnRed.height};
    DrawTexture(assets.templateBtnRed, 432, 279, RAYWHITE);
    showLabel(assets, 432, 279, "Fechar");
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePosition, closeCompleteBannerBntRec)){
        wasClosed = true;
    }


  }
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    if (CheckCollisionPointRec(mousePosition, boaViagemButtonRec))
    {
      boaViagemNode = NULL;
      for (int i = 0; i < 21; i++)
      {
        push(&boaViagemNode, pokemons[i], BOA_VIAGEM);
      }
      bubbleSort(boaViagemNode);
      ShowPokemonButtons(assets, mousePosition, boaViagemNode);
    }
    else if (CheckCollisionPointRec(mousePosition, olindaButtonRec))
    {
      olindaNode = NULL;
      for (int i = 0; i < 21; i++)
      {
        push(&olindaNode, pokemons[i], OLINDA);
      }
      bubbleSort(olindaNode);
      ShowPokemonButtons(assets, mousePosition, olindaNode);
    }
    else if (CheckCollisionPointRec(mousePosition, veuNoivaButtonRec))
    {
      veuDaNoivaNode = NULL;
      for (int i = 0; i < 21; i++)
      {
        push(&veuDaNoivaNode, pokemons[i], NOIVA);
      }
      bubbleSort(veuDaNoivaNode);
      ShowPokemonButtons(assets, mousePosition, veuDaNoivaNode);
    }
    else if (CheckCollisionPointRec(mousePosition, pedraFuradaButtonRec))
    {
      pedraFuradaNode = NULL;
      for (int i = 0; i < 21; i++)
      {
        push(&pedraFuradaNode, pokemons[i], PEDRA);
      }
      bubbleSort(pedraFuradaNode);
      ShowPokemonButtons(assets, mousePosition, pedraFuradaNode);
    }
    else if (CheckCollisionPointRec(mousePosition, lixaoButtonRec))
    {
      Pokemon trubbish = pokemons[0];
      showPokemon(assets, trubbish);
    }

    if (CheckCollisionPointRec(mousePosition, leaveButtonRec))
    {
      ClearPokedex(&boaViagemNode);
      ClearPokedex(&olindaNode);
      ClearPokedex(&pedraFuradaNode);
      ClearPokedex(&veuDaNoivaNode);
      location = -1;
      wasClosed = false;
      *currentScreen = SELECT_PLACE;
    }
  }
}

void DrawPokedex(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);
  imageProps pokedexBackground = resizeImage(assets.pokedexBack);
  DrawTextureEx(assets.pokedexBack, (Vector2){pokedexBackground.x, pokedexBackground.y}, 0.0f, pokedexBackground.scale, WHITE);
  handleButtons(assets, mousePosition);

  if (location == BOA_VIAGEM)
    ShowPokemonButtons(assets, mousePosition, boaViagemNode);
  else if (location == OLINDA)
    ShowPokemonButtons(assets, mousePosition, olindaNode);
  else if (location == NOIVA)
    ShowPokemonButtons(assets, mousePosition, veuDaNoivaNode);
  else if (location == PEDRA)
    ShowPokemonButtons(assets, mousePosition, pedraFuradaNode);
}

static void showLabel(Assets assets, int x, int y, char *label)
{
  float fontSize = 24;
  float spacing = 1.0f;
  Vector2 textSize = MeasureTextEx(assets.nunito, label, fontSize, spacing);
  Vector2 position = {x + (assets.templateBtnBlue.width - textSize.x) / 2, y + (assets.templateBtnBlue.height - textSize.y) / 2};
  DrawTextEx(assets.nunito, label, position, fontSize, spacing, WHITE);
}

void ShowPokemonButtons(Assets assets, Vector2 mousePosition, PokeNode *pokeLocation)
{
  int selectedPokemon = 707;
  int notselectedPokemon = 805;

  assets.templateBtnBlue.width = 139;
  assets.templateBtnBlue.height = 40;
  assets.templateBtnRed.width = 139;
  assets.templateBtnRed.height = 40;

  Rectangle templateButtonBlueRec[] = {
      {notselectedPokemon, 126, assets.templateBtnBlue.width, assets.templateBtnBlue.height},
      {notselectedPokemon, 221, assets.templateBtnBlue.width, assets.templateBtnBlue.height},
      {notselectedPokemon, 316, assets.templateBtnBlue.width, assets.templateBtnBlue.height},
      {notselectedPokemon, 411, assets.templateBtnBlue.width, assets.templateBtnBlue.height},
      {notselectedPokemon, 506, assets.templateBtnBlue.width, assets.templateBtnBlue.height}};

  Rectangle templateButtonRedRec[] = {
      {selectedPokemon, 126, assets.templateBtnRed.width, assets.templateBtnRed.height},
      {selectedPokemon, 221, assets.templateBtnRed.width, assets.templateBtnRed.height},
      {selectedPokemon, 316, assets.templateBtnRed.width, assets.templateBtnRed.height},
      {selectedPokemon, 411, assets.templateBtnRed.width, assets.templateBtnRed.height},
      {selectedPokemon, 506, assets.templateBtnRed.width, assets.templateBtnRed.height}};

  ButtonPokemon buttons[5];
  int i = 0;

  while (pokeLocation != NULL && i < 5)
  {
    buttons[i].blueRect = templateButtonBlueRec[i];
    buttons[i].redRect = templateButtonRedRec[i];
    buttons[i].blueTexture = assets.templateBtnBlue;
    buttons[i].redTexture = assets.templateBtnRed;
    buttons[i].Pokemon = pokeLocation->pokemon;
    i++;
    pokeLocation = pokeLocation->next;
  }

  for (int j = 0; j < i; j++)
  {
    if (CheckCollisionPointRec(mousePosition, buttons[j].blueRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      if (buttons[j].Pokemon.id > 0)
      {
        pokemonId = buttons[j].Pokemon.id;
      }
    }
    char pokemonName[30];
    for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
    {
      if (buttons[i].Pokemon.captured)
      {
        strcpy(pokemonName, buttons[i].Pokemon.name);
        //}
        // else
        //{
        // strcpy(pokemonName, "???");
        //}
        if (pokemonId == buttons[i].Pokemon.id)
        {
          DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
          showLabel(assets, buttons[i].redRect.x, buttons[i].redRect.y, pokemonName);
          showPokemon(assets, buttons[i].Pokemon);
        }
        else
        {
          DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
          showLabel(assets, buttons[i].blueRect.x, buttons[i].blueRect.y, pokemonName);
        }
      }
    }
  }
}

void showPokemon(Assets assets, Pokemon pokemonShown)
{
  float spacing = 1.0f;
  Vector2 positionName = {392, 492};

  if (!pokemonShown.captured)
  {

    // pokemon image shadow
    pokemonShown.image.width = pokemonShown.image.height = 379;
    pokemonShown.shadowImage.width = pokemonShown.shadowImage.height = 379;
    DrawTexture(pokemonShown.shadowImage, 322, 96, RAYWHITE);

    DrawTextEx(assets.nunito, "??????", positionName, 48, spacing, BLACK);
  }
  else
  {

    // pokemon image
    pokemonShown.image.width = pokemonShown.image.height = 379;
    pokemonShown.shadowImage.width = pokemonShown.shadowImage.height = 379;
    DrawTexture(pokemonShown.image, 322, 96, RAYWHITE);

    // pokemon name
    DrawTextEx(assets.nunito, pokemonShown.name, positionName, 48, spacing, BLACK);
  }

  // pokemon id
  char idLabel[10];
  sprintf(idLabel, "Nº %d", pokemonShown.id);
  Vector2 positionNumber = {452, 52};
  DrawTextEx(assets.nunito, idLabel, positionNumber, 48, spacing, BLACK);

  // pokeball
  assets.pernamBall.width = assets.pernamBall.height = 120;
  DrawTexture(assets.pernamBall, 275, 581, RAYWHITE);

  // pokemon quantity
  char quantLabel[30];
  if (pokemonShown.capCont <= 1)
  {
    sprintf(quantLabel, " %d capturado", pokemonShown.capCont);
  }
  else
  {
    sprintf(quantLabel, " %d capturados", pokemonShown.capCont);
  }
  Vector2 positionCaptured = {434, 634};
  DrawTextEx(assets.nunito, quantLabel, positionCaptured, 20, spacing, WHITE);
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

  Rectangle veuNoivaBtnBlueRect = {notselectedLocation_x, 353, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle veuNoivaBtnRedRect = {selectedLocation_x, 353, assets.templateBtnBlue.width, assets.templateBtnBlue.height};

  Rectangle lixaoBtnBlueRect = {notselectedLocation_x, 546, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle lixaoBtnRedRect = {selectedLocation_x, 546, assets.templateBtnBlue.width, assets.templateBtnBlue.height};

  Button buttons[] = {
      {boaViagemBtnBlueRect, boaViagemBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, BOA_VIAGEM},
      {olindaBtnBlueRect, olindaBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, OLINDA},
      {pedraFuradaBtnBlueRect, pedraFuradaBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, PEDRA},
      {veuNoivaBtnBlueRect, veuNoivaBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, NOIVA},
      {lixaoBtnBlueRect, lixaoBtnRedRect, assets.templateBtnBlue, assets.templateBtnRed, LIXO}};

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (CheckCollisionPointRec(mousePosition, buttons[i].blueRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
      location = buttons[i].location;
    }
  }

  char *arrayLocationsLabel[] = {"Boa Viagem", "Olinda", "Pedra Furada", "Véu da Noiva", "Lixão"};

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (location == buttons[i].location)
    {
      DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
      showLabel(assets, buttons[i].redRect.x, buttons[i].redRect.y, arrayLocationsLabel[i]);
      if (location == LIXO)
      {
        showPokemon(assets, pokemons[0]);
      }
    }
    else
    {
      DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
      showLabel(assets, buttons[i].blueRect.x, buttons[i].blueRect.y, arrayLocationsLabel[i]);
    }
  }

  // leave button
  assets.leaveButtonRed.width = 166;
  assets.leaveButtonRed.height = 80;
  Rectangle leaveButtonRect = {26, 619, assets.leaveButtonRed.width, assets.leaveButtonRed.height};

  DrawTexture(assets.leaveButtonRed, leaveButtonRect.x, leaveButtonRect.y, RAYWHITE);
}

bool checkCompletion(){
  for (int i = 0; i < 21; i++)
  { 
    if (!pokemons[i].captured) return false; 
  }
    return true;
}