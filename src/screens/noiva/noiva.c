#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "../../utils/capture/capture.h"
#include "../../utils/animation/animation.h"
#include "../../character/character.h"
#include "noiva.h"

static bool handleChoosePokemon();
static void handleShowPokemonCaptured(Assets assets);
static void handleButtons(Assets assets);
static void resetVariables();

static float angle = 0.0f;
static PokeNode *currentPokemon = NULL;
static float timeCounter = 0.0f;
static bool isPokemonChosen = false;
static bool isInArea = false;
static bool isAnimationPlaying = false;

void UpdateNoiva(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Rectangle leaveButtonRect = {470, 480, assets.leaveButtonRed.width, assets.leaveButtonRed.height};
  FrameAndPosition frames[] = {
      {assets.captureNet1, (Vector2){86, 0}},
      {assets.captureNet2, (Vector2){0, 0}},
      {assets.captureNet3, (Vector2){213, 0}},
      {assets.captureNet4, (Vector2){213, 0}},
  };
  size_t framesArraySize = sizeof(frames) / sizeof(frames[0]);

  if (CheckCollisionPointRec(mousePosition, leaveButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    if (isInArea)
    {
      pokemons[currentPokemon->pokemon.id].capCont += 1;
      addMoney(currentPokemon->pokemon.id);
    }

    *currentScreen = SELECT_PLACE;
    resetVariables();
  }

  if (IsKeyPressed(KEY_SPACE) && !isAnimationPlaying && isPokemonChosen)
  {

    isAnimationPlaying = true;
  }
  if (isPokemonChosen && isAnimationPlaying)
  {
    DrawSpriteAnimation(frames, &isAnimationPlaying, framesArraySize);
  }
  if (!isAnimationPlaying)
  {
    DrawTexture(frames[0].frame, frames[0].position.x, WINDOW_HEIGHT - frames[0].frame.height, WHITE);
  }

  if (isPokemonChosen)
  {
    if (isInArea)
    {
      if (!isAnimationPlaying)
      {
        handleShowPokemonCaptured(assets);
        pokemons[currentPokemon->pokemon.id].captured = true;
      }
    }
    else
    {
      isInArea = handleCaptureCircle(assets, currentPokemon->pokemon);

      currentPokemon->pokemon.shadowImage.width = currentPokemon->pokemon.shadowImage.height = 96;
      DrawTexture(currentPokemon->pokemon.shadowImage, 800, 507, RAYWHITE);
    }
  }
  else
  {
    isPokemonChosen = handleChoosePokemon();
    if (currentPokemon != NULL)
    {
      printf("%s -> ", currentPokemon->pokemon.name);
    }
  }
}

void DrawNoiva(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps noivaBackground = resizeImage(assets.noivaPlay);
  DrawTextureEx(assets.noivaPlay, (Vector2){noivaBackground.x, noivaBackground.y}, 0.0f, noivaBackground.scale, WHITE);
}

static bool handleChoosePokemon()
{
  timeCounter += GetFrameTime();

  if (!IsKeyPressed(KEY_SPACE))
  {
    if (timeCounter >= 0.5f)
    {
      if (currentPokemon == NULL)
      {
        currentPokemon = noivaHead;
      }
      else
      {
        currentPokemon = currentPokemon->next;
      }

      timeCounter = 0.0f;
    }

    return false;
  }
  else
  {
    return true;
  }
}

static void handleShowPokemonCaptured(Assets assets)
{
  Color capturedBackgroundColor = {21, 128, 61, 255};
  DrawRectangle(0, 182, 1024, 356, capturedBackgroundColor);
  DrawRectangle(0, 172, 1024, 10, WHITE);
  DrawRectangle(0, 538, 1024, 10, WHITE);
  currentPokemon->pokemon.image.height = currentPokemon->pokemon.image.width = 250;

  DrawTexture(currentPokemon->pokemon.image, 371, 150, RAYWHITE);

  Vector2 position = {310, 400};

  char message[100];
  sprintf(message, "Parabéns! %s foi capturado!", currentPokemon->pokemon.name);
  DrawTextEx(assets.nunito, message, position, 32, 1.0f, WHITE);
  handleButtons(assets);

  char money[5];
  Vector2 moneyPosition = {882, 215};
  sprintf(money, "+ %d", currentPokemon->pokemon.rarity * 5);
  DrawTextEx(assets.nunito, money, moneyPosition, 36, 1.0f, WHITE);

  assets.coin.width = assets.coin.height = 60;
  DrawTexture(assets.coin, 943, 202, RAYWHITE);
}

static void handleButtons(Assets assets)
{
  assets.leaveButtonRed.width = 84;
  assets.leaveButtonRed.height = 41;
  Rectangle leaveButtonRect = {470, 480, assets.leaveButtonRed.width, assets.leaveButtonRed.height};

  DrawTexture(assets.leaveButtonRed, leaveButtonRect.x, leaveButtonRect.y, RAYWHITE);
}

static void resetVariables()
{
  angle = 0.0f;
  currentPokemon = NULL;
  timeCounter = 0.0f;
  isPokemonChosen = false;
  isInArea = false;
}