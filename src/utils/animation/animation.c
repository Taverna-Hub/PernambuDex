#include <stdlib.h>
#include "animation.h"
#include "../constants.h"

void DrawSpriteAnimation(FrameAndPosition *frames, bool *isAnimationPlaying, int framesLength)
{
  if (framesLength <= 0)
    return;

  static float timeCounter = 0.0f;
  static int currentFrame = 0;

  float frameTime = 0.2f;
  timeCounter += GetFrameTime();

  if (timeCounter >= frameTime)
  {
    timeCounter = 0.0f;
    currentFrame = (currentFrame + 1) % framesLength;

    if (currentFrame == 0)
    {
      *isAnimationPlaying = false;
    }
  }

  if (currentFrame < framesLength)
  {
    Vector2 position = {frames[currentFrame].position.x, WINDOW_HEIGHT - frames[currentFrame].frame.height};
    DrawTexture(frames[currentFrame].frame, position.x, position.y, WHITE);
  }
}
