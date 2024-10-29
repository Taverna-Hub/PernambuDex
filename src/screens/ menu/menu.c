#include "raylib.h"

#define NUM_IMAGES 4
#define TRANSITION_TIME 2.0f

int InitializeMenu()
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "RayLib - Menu with Background Transition");

  // Load your images
  Texture2D images[NUM_IMAGES];
  images[0] = LoadTexture("./assets/1.png");
  images[1] = LoadTexture("./assets/2.png");
  images[2] = LoadTexture("./assets/3.png");
  images[3] = LoadTexture("./assets/4.png");

  int currentImageIndex = 0;
  float timer = 0.0f;
  float alpha = 1.0f;

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {

    timer += GetFrameTime();

    // Update images based on transition timing
    if (timer >= TRANSITION_TIME)
    {
      timer = 0.0f;
      currentImageIndex = (currentImageIndex + 1) % NUM_IMAGES;
    }

    // Calculate alpha for fade in/out effect
    alpha = 1.0f - (timer / TRANSITION_TIME);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw current and next image with alpha blending
    int nextImageIndex = (currentImageIndex + 1) % NUM_IMAGES;
    DrawTexture(images[currentImageIndex], 0, 0, Fade(WHITE, alpha));
    DrawTexture(images[nextImageIndex], 0, 0, Fade(WHITE, 1.0f - alpha));

    // Draw menu text

    DrawText("MENU", screenWidth / 2 - MeasureText("MENU", 40) / 2, screenHeight / 4, 40, BLACK);
    DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 20) / 2, screenHeight / 2, 20, DARKGRAY);
    DrawText("Options", screenWidth / 2 - MeasureText("Options", 20) / 2, screenHeight / 2 + 30, 20, DARKGRAY);
    DrawText("Exit", screenWidth / 2 - MeasureText("Exit", 20) / 2, screenHeight / 2 + 60, 20, DARKGRAY);

    EndDrawing();
  }

  // Unload images
  for (int i = 0; i < NUM_IMAGES; i++)
  {
    UnloadTexture(images[i]);
  }

  CloseWindow();
  return 0;
}
