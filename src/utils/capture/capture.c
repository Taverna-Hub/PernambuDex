#include <math.h>
#include <stdio.h>
#include "raylib.h"
#include "../init/init.h"
#include "capture.h"

void handleCaptureCircle(Assets assets, Vector2 circlePosition, float innerRadius, float speed, float *angle)
{
  float outerRadius = assets.captureCircle.width / 2.0f;

  *angle += speed;

  float ballX = circlePosition.x + innerRadius * cos(*angle) - (assets.captureIndicator.width / 2.0f);
  float ballY = circlePosition.y + innerRadius * sin(*angle) - (assets.captureIndicator.height / 2.0f);

  DrawTexture(assets.captureCircle, circlePosition.x - outerRadius, circlePosition.y - outerRadius, WHITE);
  DrawTexture(assets.captureIndicator, ballX, ballY, WHITE);
}

bool handleUpdateCaptureCircle(Vector2 circlePosition, float innerRadius, float *angle)
{
  if (IsKeyPressed(KEY_SPACE))
  {
    printf("\n");

    float ballX = circlePosition.x + innerRadius * cos(*angle);
    float ballY = circlePosition.y + innerRadius * sin(*angle);

    int captureX = ballX >= 169 && ballX <= 185;
    int captureY = ballY >= 471 && ballY <= 491;

    if (captureX && captureY)
    {
      printf("Capturado!");
      return true;
    }

    return false;
  }
}