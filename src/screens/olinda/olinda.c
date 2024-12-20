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
#include "olinda.h"

static bool handleChoosePokemon();
static void handleTries(Assets Assets);
static void handleShowPokemonCaptured(Assets assets);
static void handleCaptureFailed(Assets assets);
static void handleButtons(Assets assets);
static void resetVariables();

static float angle = 0.0f;
static PokeNode *currentPokemon = NULL;
static float timeCounter = 0.0f;
static bool isPokemonChosen = false;
static bool isInArea = false;
static bool isAnimationPlaying = false;
static bool isButtonAnimationPlaying = true;
static int countTries = 0;

void UpdateOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Rectangle leaveButtonRect = {470, 480, assets.leaveButtonRed.width, assets.leaveButtonRed.height};
  // array de frames da animação
  FrameAndPosition frames[] = {
      {assets.captureGhostbusters1, (Vector2){69, 0}},
      {assets.captureGhostbusters2, (Vector2){69, 0}},
      {assets.captureGhostbusters3, (Vector2){69, 0}},
      {assets.captureGhostbusters4, (Vector2){69, 0}},
      {assets.captureGhostbusters5, (Vector2){69, 0}},
      {assets.captureGhostbusters6, (Vector2){69, 0}},
      {assets.captureGhostbusters7, (Vector2){69, 0}},
      {assets.captureGhostbusters8, (Vector2){69, 0}},
  };
  size_t framesArraySize = sizeof(frames) / sizeof(frames[0]);
  // capturou (animaçao)
  if (countTries >= 2 && !isInArea && !isAnimationPlaying)
  {
  
  if ((CheckCollisionPointRec(mousePosition, leaveButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_SPACE))
  {

    *currentScreen = SELECT_PLACE;
    resetVariables();
    return;
  }
  }

  else if(isInArea)
  {
      if ((CheckCollisionPointRec(mousePosition, leaveButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_SPACE))
  {
      pokemons[currentPokemon->pokemon.id].capCont += 1;
      addMoney(currentPokemon->pokemon.id);
    

    *currentScreen = SELECT_PLACE;
    resetVariables();
    return;
  }
  }
  // vai travar a lista no pokemon atual
  if (IsKeyPressed(KEY_SPACE) && !isAnimationPlaying && isPokemonChosen)
  {
    isAnimationPlaying = true;
  }
  if (isPokemonChosen && isAnimationPlaying)
  {
    DrawSpriteAnimation(frames, &isAnimationPlaying, framesArraySize);
  }
  else if (!isAnimationPlaying)
  {
    DrawTexture(frames[0].frame, frames[0].position.x, WINDOW_HEIGHT - frames[0].frame.height, WHITE);
  }

  if (isPokemonChosen)
  {
    // erra o evento
    if (IsKeyPressed(KEY_SPACE) && !isInArea)
    {
      countTries = countTries + 1;
    }
    // acertou o evento
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
      DrawTexture(currentPokemon->pokemon.shadowImage, 800, 357, RAYWHITE);
    }
  }
  else
  {
    FrameAndPosition buttonFrames[] = {
        {assets.spaceButtonDefault, (Vector2){400, 0}},
        {assets.spaceButtonPressed, (Vector2){400, 0}},
    };

    DrawSpriteAnimation(buttonFrames, &isButtonAnimationPlaying, 2);

    isPokemonChosen = handleChoosePokemon();
  }
  // perde
  if (countTries == 2 && !isInArea && !isAnimationPlaying)
  {
    handleCaptureFailed(assets);
  }
}

void DrawOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps olindaBackground = resizeImage(assets.olindaPlay);
  DrawTextureEx(assets.olindaPlay, (Vector2){olindaBackground.x, olindaBackground.y}, 0.0f, olindaBackground.scale, WHITE);
   handleTries(assets);
}
// percorre a lista, ate SPACE ser clicado
static bool handleChoosePokemon()
{
  timeCounter += GetFrameTime();

  if (!IsKeyPressed(KEY_SPACE))
  {
    if (currentPokemon == NULL)
    {
      currentPokemon = olindaHead;
    }

    if (timeCounter >= 0.5f)
    {
      currentPokemon = currentPokemon->next;
      timeCounter = 0.0f;
    }

    return false;
  }
  else
  {
    return true;
  }
}
// se capturou

static void handleShowPokemonCaptured(Assets assets)
{
  Color capturedColor = {115, 114, 168, 255};
  DrawRectangle(0, 182, 1024, 356, capturedColor);
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
// se não pegou
static void handleCaptureFailed(Assets assets)
{
  Color capturedColor = {220, 38, 38, 255};
  DrawRectangle(0, 182, 1024, 356, capturedColor);
  DrawRectangle(0, 172, 1024, 10, WHITE);
  DrawRectangle(0, 538, 1024, 10, WHITE);
  DrawTexture(assets.captureFailed, 460, 250, RAYWHITE);

  Vector2 position = {170, 400};

  char *message = "Que pena! O pokemon escapou e não foi possível capturá-lo :(";
  DrawTextEx(assets.nunito, message, position, 32, 1.0f, WHITE);
  handleButtons(assets);
}

static void handleButtons(Assets assets)
{
  assets.leaveButtonRed.width = 84;
  assets.leaveButtonRed.height = 41;
  Rectangle leaveButtonRect = {470, 480, assets.leaveButtonRed.width, assets.leaveButtonRed.height};

  DrawTexture(assets.leaveButtonRed, leaveButtonRect.x, leaveButtonRect.y, RAYWHITE);
}
// reseta toda vez que sai da tela
static void resetVariables()
{
  angle = 0.0f;
  currentPokemon = NULL;
  timeCounter = 0.0f;
  isPokemonChosen = false;
  isInArea = false;
  isAnimationPlaying = false;
  countTries = 0;
}
void handleTries(Assets assets){
  for (int i = 0; i < (2 - countTries); i++){
    assets.pernamBall.height =  assets.pernamBall.width = 58;
    DrawTexture(assets.pernamBall, 43 + (i*55), 34, RAYWHITE);
  }
}