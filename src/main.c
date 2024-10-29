#include "raylib.h"

int main()
{
  InitWindow(400, 400, "Pokemon");
  SetTargetFPS(60);


  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  
  CloseWindow();
  return 0;
}