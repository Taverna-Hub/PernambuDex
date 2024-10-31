#include <raylib.h>
#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"

#include "feira.h"

void DrawFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps feiraBeckerShots = resizeImage(assets.feiraPlay);
  DrawTextureEx(assets.feiraPlay, (Vector2){feiraBeckerShots.x, feiraBeckerShots.y}, 0.0f, feiraBeckerShots.scale, WHITE);
}