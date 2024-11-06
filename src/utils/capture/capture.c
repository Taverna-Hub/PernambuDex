#include <math.h>
#include <stdio.h>
#include "raylib.h"
#include "../init/init.h"
#include "capture.h"

Vector2 circlePosition = {850.0f, 550.0f};
static float angle = 0.0f;
float speed = 0.001f;

typedef struct Positions
{
  float x;
  float y;
  float angle;
  float width;
  float height;
} Positions;

Positions rectanglePositions[] = {
    {770, 600, 48.75f, 27.3, 40},
    {730, 500, 18.0f, 33, 40},
    {835, 417, 0.0f, 33, 40},
    {835, 645, 0.0f, 33, 37},
    {721, 531, 0.0f, 32, 37},
    {948, 531, 0.0f, 30, 37},
    {946, 580, 29.0f, 30, 40},
    {938, 450, 45.0f, 30, 40},
};

int position = 7;

bool handleCaptureCircle(Assets assets)
{
  assets.eventCircle.height = assets.eventCircle.width = 272;
  assets.eventIndicator.height = assets.eventIndicator.width = 20;

  float outerRadius = assets.eventCircle.width / 2.0f;
  float innerRadius = (assets.eventCircle.width / 2.0f) * 0.85f;

  angle += speed;

  float ballX = circlePosition.x + innerRadius * cos(angle) - (assets.eventIndicator.width / 2.0f);
  float ballY = circlePosition.y + innerRadius * sin(angle) - (assets.eventIndicator.height / 2.0f);

  DrawTexture(assets.eventCircle, circlePosition.x - outerRadius, circlePosition.y - outerRadius, WHITE);
  DrawTexture(assets.eventIndicator, ballX, ballY, WHITE);

  assets.eventRectangle.width = rectanglePositions[position].width;
  assets.eventRectangle.height = rectanglePositions[position].height;
  DrawTextureEx(assets.eventRectangle,
                (Vector2){rectanglePositions[position].x, rectanglePositions[position].y},
                rectanglePositions[position].angle, 1, WHITE);

  return handleUpdateCaptureCircle(innerRadius);
}

bool handleUpdateCaptureCircle(float innerRadius)
{
  if (IsKeyPressed(KEY_SPACE))
  {
    printf("\n");

    float ballX = circlePosition.x + innerRadius * cos(angle);
    float ballY = circlePosition.y + innerRadius * sin(angle);

    int captureX = ballX >= rectanglePositions[position].x && ballX <= rectanglePositions[position].x + rectanglePositions[position].width;
    int captureY = ballY >= rectanglePositions[position].y && ballY <= rectanglePositions[position].y + rectanglePositions[position].height;

    if (captureX && captureY)
    {
      printf("Capturado!");
      return true;
    }

    return false;
  }
}