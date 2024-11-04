#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "olinda.h"

static float angle = 0.0f;

void handleCaptureCircle(Assets assets, Vector2 circlePosition, float innerRadius, float speed);

void UpdateOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Vector2 circlePosition = {300.0f, 400.0f};
  float innerRadius = (assets.captureCircle.width / 2.0f) * 0.85f;
  float speed = 0.001f;

  handleCaptureCircle(assets, circlePosition, innerRadius, speed);

  if (IsKeyReleased(KEY_SPACE))
  {
    printf("\n");

    float ballX = circlePosition.x + innerRadius * cos(angle);
    float ballY = circlePosition.y + innerRadius * sin(angle);

    int captureX = ballX >= 169 && ballX <= 185;
    int captureY = ballY >= 471 && ballY <= 491;

    if (captureX && captureY)
    {
      printf("Capturado!");
    }
  }
}

void DrawOlinda(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps olindaBackground = resizeImage(assets.olindaMenu);
  DrawTextureEx(assets.olindaMenu, (Vector2){olindaBackground.x, olindaBackground.y}, 0.0f, olindaBackground.scale, WHITE);
}

void initializeCircularList(PokeNode **head, PokeNode **tail, Pokemon pokemon)
{
  PokeNode *newPokeNode = (PokeNode *)malloc(sizeof(PokeNode));
  newPokeNode->pokemon = pokemon;

  if (newPokeNode != NULL)
  {
    if (*head == NULL)
    {
      *head = *tail = newPokeNode;
    }
    else
    {
      newPokeNode->next = *head;
      *head = newPokeNode;
    }
    (*tail)->next = *head;
  }
}

void handleCaptureCircle(Assets assets, Vector2 circlePosition, float innerRadius, float speed)
{
  float outerRadius = assets.captureCircle.width / 2.0f;

  angle += speed;

  float ballX = circlePosition.x + innerRadius * cos(angle) - (assets.captureIndicator.width / 2.0f);
  float ballY = circlePosition.y + innerRadius * sin(angle) - (assets.captureIndicator.height / 2.0f);

  DrawTexture(assets.captureCircle, circlePosition.x - outerRadius, circlePosition.y - outerRadius, WHITE);
  DrawTexture(assets.captureIndicator, ballX, ballY, WHITE);
}