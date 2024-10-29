#include "constants.h"
#include "resizeImage.h"
#include <raylib.h>

imageProps resizeImage(Texture2D texture)
{
  // Calculate the scale based on the window and texture dimensions
  float scaleX = (float)WINDOW_WIDTH / (float)texture.width;
  float scaleY = (float)WINDOW_HEIGHT / (float)texture.height;
  float scale = (scaleX > scaleY) ? scaleX : scaleY; // Use the larger scale to fill the window

  // Calculate new dimensions for the texture
  int newWidth = (int)(texture.width * scale);
  int newHeight = (int)(texture.height * scale);

  // Calculate position to center the texture in the window
  int posX = (WINDOW_WIDTH - newWidth) / 2;
  int posY = (WINDOW_HEIGHT - newHeight) / 2;

  imageProps props;
  props.scale = scale; // Store scale as float
  props.y = posY;
  props.x = posX;

  return props; // Return the populated struct
}
