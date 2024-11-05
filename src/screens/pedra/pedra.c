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
#include "pedra.h"

static bool handleChoosePokemon();

static float angle = 0.0f;
static PokeNode *currentPokemon = NULL;
static float timeCounter = 0.0f;
// bool isPokemonChosen = false;
// bool isInArea = false;

void UpdatePedra(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
}

void DrawPedra(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps pedraBackground = resizeImage(assets.pedraMenu);
  DrawTextureEx(assets.pedraMenu, (Vector2){pedraBackground.x, pedraBackground.y}, 0.0f, pedraBackground.scale, WHITE);
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
        currentPokemon = pedraHead;
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
