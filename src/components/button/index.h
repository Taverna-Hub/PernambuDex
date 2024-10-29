#include "raylib.h"

bool CheckButton(Rectangle rect, Vector2 mousePoint)
{
  return (CheckCollisionPointRec(mousePoint, rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}
