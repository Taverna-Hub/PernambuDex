#ifndef RESIZE_IMAGE_H
#define RESIZE_IMAGE_H

#include <raylib.h>

typedef struct imageProps
{
  float scale; // Change to float for precision
  int x;
  int y;
} imageProps;

// Function prototype
imageProps resizeImage(Texture2D texture);

#endif // RESIZE_IMAGE_H
