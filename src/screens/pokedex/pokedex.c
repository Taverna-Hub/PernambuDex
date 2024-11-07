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

void push(PokeNode **head, Pokemon pokemon, Screen screen)
{
  if (pokemon.place == screen && pokemon.captured)
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
    printf("Limpando Pokémon: %s\n", temp->pokemon.name);
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

void UpdatePokedexScreen(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Rectangle leaveButtonRec = {26, 619, 166, 80};
  Rectangle boaViagemButtonRec = {X, 143, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle olindaButtonRec = {X, 213, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle pedraFuradaButtonRec = {X, 283, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle veuNoivaButtonRec = {X, 353, assets.templateBtnBlue.width, assets.templateBtnBlue.height};
  Rectangle lixaoButtonRec = {62, 546, assets.templateBtnBlue.width, assets.templateBtnBlue.height};

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    if (CheckCollisionPointRec(mousePosition, boaViagemButtonRec))
    {
      boaViagemNode = NULL;
      printf("BV\n");
      for (int i = 0; i < 21; i++)
      {
        push(&boaViagemNode, pokemons[i], BOA_VIAGEM);
      }
      bubbleSort(boaViagemNode);
      ShowPokemonButtons(assets, mousePosition, boaViagemNode);
    }
    else if (CheckCollisionPointRec(mousePosition, olindaButtonRec))
    {
      printf("Olinda\n");
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
      printf("Véu da Noiva\n");
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
      printf("Pedra Furada\n");
      pedraFuradaNode = NULL;
      for (int i = 0; i < 21; i++)
      {
        push(&pedraFuradaNode, pokemons[i], PEDRA);
      }
      bubbleSort(pedraFuradaNode);
      ShowPokemonButtons(assets, mousePosition, pedraFuradaNode);
    }

    if (CheckCollisionPointRec(mousePosition, leaveButtonRec))
    {
      ClearPokedex(&boaViagemNode);
      ClearPokedex(&olindaNode);
      ClearPokedex(&pedraFuradaNode);
      ClearPokedex(&veuDaNoivaNode);
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

  // Adiciona a chamada da função para desenhar os botões de Pokémon
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

    for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
    {
      if (pokemonId == buttons[i].Pokemon.id)
      {
        DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
        showLabel(assets, buttons[i].redRect.x, buttons[i].redRect.y, arrayLocationsLabel[i]);
      }
      else
      {
        DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
        showLabel(assets, buttons[i].blueRect.x, buttons[i].blueRect.y, arrayLocationsLabel[i]);
      }
    }

    DrawTextureRec(buttons[j].blueTexture, (Rectangle){0, 0, buttons[j].blueTexture.width, buttons[j].blueTexture.height}, (Vector2){buttons[j].blueRect.x, buttons[j].blueRect.y}, WHITE);
    showLabel(assets, buttons[j].blueRect.x, buttons[j].blueRect.y, buttons[j].Pokemon.name);

    printf("Renderizando botão para Pokémon: %s\n", buttons[j].Pokemon.name);
  }
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
      printf("click x: %lf y: %lf\n", mousePosition.x, mousePosition.y);
    }
  }

  char *arrayLocationsLabel[] = {"Boa Viagem", "Olinda", "Pedra Furada", "Véu da Noiva", "Lixão"};

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (location == buttons[i].location)
    {
      DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
      showLabel(assets, buttons[i].redRect.x, buttons[i].redRect.y, arrayLocationsLabel[i]);
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