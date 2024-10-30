#include "raylib.h"

void handleButtonCollision(Vector2 mousePosition, Texture2D buttonTexture, Rectangle buttonRect)
{
  DrawTexture(buttonTexture, buttonRect.x, buttonRect.y, RAYWHITE);

  if (CheckCollisionPointRec(mousePosition, buttonRect))
  {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
  }
}