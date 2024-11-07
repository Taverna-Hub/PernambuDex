#include <stdlib.h>
#include "animation.h"
#include "../constants.h"

void DrawSpriteAnimation(FrameAndPosition frames[4], bool *isAnimationPlaying)
{
  static float timeCounter = 0.0f;
  static int currentFrame = 0;

  float frameTime = 0.2f;
  timeCounter += GetFrameTime();

  if (timeCounter >= frameTime)
  {
    timeCounter = 0.0f;
    currentFrame = (currentFrame + 1) % 4;
  }

  if (currentFrame >= 3)
  {
    currentFrame = 0;
    *isAnimationPlaying = false;
  }

  Vector2 position = {frames[currentFrame].position.x, WINDOW_HEIGHT - frames[currentFrame].frame.height};

  DrawTexture(frames[currentFrame].frame, position.x, position.y, WHITE);
}
