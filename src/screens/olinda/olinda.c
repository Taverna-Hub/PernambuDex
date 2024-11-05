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

static float angle = 0.0f;

void UpdateOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Vector2 circlePosition = {300.0f, 400.0f};
  float innerRadius = (assets.captureCircle.width / 2.0f) * 0.85f;
  float speed = 0.001f;

  handleCaptureCircle(assets, circlePosition, innerRadius, speed, &angle);
  handleUpdateCaptureCircle(circlePosition, innerRadius, &angle);
}

void DrawOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps olindaBackground = resizeImage(assets.olindaMenu);
  DrawTextureEx(assets.olindaMenu, (Vector2){olindaBackground.x, olindaBackground.y}, 0.0f, olindaBackground.scale, WHITE);
}
