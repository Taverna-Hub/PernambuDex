#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <math.h>
#include "utils/constants.h"
#include "utils/resizeImage/resizeImage.h"
#include "utils/init/init.h"
#include "utils/cleanup/cleanup.h"
#include "screens/menu/menu.h"
#include "screens/select-place/place.h"
#include "screens/feira/feira.h"
#include "screens/olinda/olinda.h"
#include "screens/viagem/viagem.h"
#include "screens/pedra/pedra.h"
#include "screens/noiva/noiva.h"
#include "screens/pokedex/pokedex.h"
#include "character/character.h"

// Lendário - 1
// Raro - 4
// Comum - 6
// Lixo - 9

PokeNode *olindaHead = NULL;
PokeNode *olindaTail = NULL;

PokeNode *noivaHead = NULL;
PokeNode *noivaTail = NULL;

PokeNode *pedraHead = NULL;
PokeNode *pedraTail = NULL;

PokeNode *boaViagemHead = NULL;
PokeNode *boaViagemTail = NULL;

// Item PraiaLimpa;
// Item SinalFarol;
// Item EncantoItamaraca;

int main(void)
{
  Screen currentScreen = MENU;

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pernambudex");

  Assets assets = LoadAssets();
  Vector2 mousePosition = GetMousePosition();
  inicializeCharacter("coiso", 0);
  handleInitializeAllItems(assets); 
  initializePokemon(assets);

  initializeCircularList(pokemons, &boaViagemHead, &boaViagemTail, 1);
  initializeCircularList(pokemons, &olindaHead, &olindaTail, 6);
  initializeCircularList(pokemons, &pedraHead, &pedraTail, 11);
  initializeCircularList(pokemons, &noivaHead, &noivaTail, 16);

    float scale = 1.0f;
    int offsetX = 0, offsetY = 0;
    bool isFullscreen = false;

  HideCursor();
  while (!WindowShouldClose())
  {
if (IsKeyPressed(KEY_F11)) {
    isFullscreen = !isFullscreen;
    if (isFullscreen) {
        // Ativar modo tela cheia, mas não alterar o tamanho da janela manualmente
        ToggleFullscreen();

        // Obter as dimensões do monitor
        int screenWidth = GetMonitorWidth(0);
        int screenHeight = GetMonitorHeight(0);

        // Calcular a posição central para a janela
        int offsetX = (screenWidth - WINDOW_WIDTH) / 2;
        int offsetY = (screenHeight - WINDOW_HEIGHT) / 2;

        // Definir a posição da janela para centralizar
        SetWindowPosition(offsetX, offsetY);
    } else {
        // Sair do modo tela cheia
        ToggleFullscreen();
        
        // Retornar ao tamanho original da janela
        SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

        // Obter as dimensões do monitor novamente
        int screenWidth = GetMonitorWidth(0);
        int screenHeight = GetMonitorHeight(0);

        // Calcular a posição central para a janela
        int offsetX = (screenWidth - WINDOW_WIDTH) / 2;
        int offsetY = (screenHeight - WINDOW_HEIGHT) / 2;

        // Definir a posição da janela para centralizar novamente
        SetWindowPosition(offsetX, offsetY);
    }
}

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        // Calcular scale para manter a proporção
        scale = fmin((float)screenWidth / WINDOW_WIDTH, (float)screenHeight / WINDOW_HEIGHT);
        offsetX = (screenWidth - (int)(WINDOW_WIDTH * scale)) / 2;
        offsetY = (screenHeight - (int)(WINDOW_HEIGHT * scale)) / 2;

        BeginDrawing();
        ClearBackground(BLACK); // Preencher as barras excedentes com preto

        // Desenhar jogo dentro de uma "viewport" centralizada
        BeginScissorMode(offsetX, offsetY, (int)(WINDOW_WIDTH * scale), (int)(WINDOW_HEIGHT * scale));
        ClearBackground(RAYWHITE); // Fundo do jogo

        // Atualizar posição do mouse
        mousePosition = GetMousePosition();
  
        // Ajustar a posição do mouse de acordo com a scale
        Vector2 adjustedMousePos = {
            (mousePosition.x - offsetX) / scale,
            (mousePosition.y - offsetY) / scale
        };
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
    else if (currentScreen == BOA_VIAGEM)
    {
      if (boaViagemHead != NULL)
      {
        freeCircularList(&boaViagemHead, &boaViagemTail);
      }

      initializeCircularList(pokemons, &boaViagemHead, &boaViagemTail, 1);
      DrawBoaViagem(&currentScreen, mousePosition, assets);
      UpdateBoaViagem(&currentScreen, mousePosition, assets);
    }
    else if (currentScreen == PEDRA)
    {
      if (pedraHead != NULL)
      {
        freeCircularList(&pedraHead, &pedraTail);
      }

      initializeCircularList(pokemons, &pedraHead, &pedraTail, 11);
      DrawPedra(&currentScreen, mousePosition, assets);
      UpdatePedra(&currentScreen, mousePosition, assets);
    }
    else if (currentScreen == NOIVA)
    {
      if (noivaHead != NULL)
      {
        freeCircularList(&noivaHead, &noivaTail);
      }

      initializeCircularList(pokemons, &noivaHead, &noivaTail, 16);
      DrawNoiva(&currentScreen, mousePosition, assets);
      UpdateNoiva(&currentScreen, mousePosition, assets);
    }
    else if (currentScreen == OLINDA)
    {
      if (olindaHead != NULL)
      {
        freeCircularList(&olindaHead, &olindaTail);
      }

      initializeCircularList(pokemons, &olindaHead, &olindaTail, 6);
      DrawOlinda(&currentScreen, mousePosition, assets);
      UpdateOlinda(&currentScreen, mousePosition, assets);
    }
    else if (currentScreen == POKEDEX)
    {
      DrawPokedex(&currentScreen, mousePosition, assets);
      UpdatePokedexScreen(&currentScreen, mousePosition, assets);
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
