#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib.h"
#include "../constants.h"

void DrawSpriteAnimation(FrameAndPosition *frames, bool *isAnimationPlaying, int framesLength);

#endif