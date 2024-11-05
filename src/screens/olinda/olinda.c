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
#include "olinda.h"

static bool handleChoosePokemon();

static float angle = 0.0f;
static PokeNode *currentPokemon = NULL;
static float timeCounter = 0.0f;
bool isPokemonChosen = false;

void UpdateOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Vector2 circlePosition = {300.0f, 400.0f};
  float innerRadius = (assets.captureCircle.width / 2.0f) * 0.85f;
  float speed = 0.001f;

  if (isPokemonChosen)
  {
    DrawTexture(currentPokemon->pokemon.image, 96, 96, RAYWHITE);
    handleCaptureCircle(assets, circlePosition, innerRadius, speed, &angle);
    bool isInArea = handleUpdateCaptureCircle(circlePosition, innerRadius, &angle);
  }
  else
  {
    isPokemonChosen = handleChoosePokemon();
  }
}

void DrawOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps olindaBackground = resizeImage(assets.olindaMenu);
  DrawTextureEx(assets.olindaMenu, (Vector2){olindaBackground.x, olindaBackground.y}, 0.0f, olindaBackground.scale, WHITE);

  if (currentPokemon != NULL)
  {
    printf("%s -> ", currentPokemon->pokemon.name);
  }
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
        currentPokemon = olindaHead;
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
