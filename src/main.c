#include "raylib.h"

int main()
{
  InitWindow(400, 400, "pica");
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
  }

  CloseWindow();
  return 0;
}