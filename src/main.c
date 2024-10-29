#include <raylib.h>
#include "utils/constants.h"
#include "utils/resizeImage.h"

int main(void)
{
  // Initialize the window dimensions
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Full Window Image");

  // Load the image and convert it to a texture
  Image image = LoadImage("./assets/1.png"); // Load your image here
  Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image); // Unload the image, we only need the texture now

  imageProps imageProps = resizeImage(texture);

  // Main game loop
  while (!WindowShouldClose())
  {
    // Start drawing
    BeginDrawing();
    ClearBackground(RAYWHITE); // Clear background with white color

    // Draw the texture at the calculated position and size
    DrawTextureEx(texture, (Vector2){imageProps.x, imageProps.y}, 0.0f, imageProps.scale, WHITE);

    EndDrawing();
  }

  // Cleanup
  UnloadTexture(texture); // Unload the texture
  CloseWindow();          // Close the window and OpenGL context

  return 0;
}
