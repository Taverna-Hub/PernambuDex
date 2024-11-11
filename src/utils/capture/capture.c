#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../init/init.h"
#include "../animation/animation.h"
#include "../../screens/feira/feira.h"
#include "capture.h"

Vector2 circlePosition = {850.0f, 400.0f};
static float angle = 0.0f;

typedef struct Positions
{
  float x;
  float y;
  float angle;
  float width;
  float height;
} Positions;

Positions rectanglePositions[] = {
    {770, 450, 48.75f, 27.3, 40},
    {730, 350, 18.0f, 33, 40},
    {835, 267, 0.0f, 33, 40},
    {835, 495, 0.0f, 33, 37},
    {721, 381, 0.0f, 32, 37}, // 4
    {948, 381, 0.0f, 30, 37}, // 5
    {946, 430, 29.0f, 30, 40},
    {938, 300, 45.0f, 30, 40},
};

int position;

float calculateSpeed(Pokemon chosenPokemon);

bool handleCaptureCircle(Assets assets, Pokemon chosenPokemon)
{
  srand(time(NULL));
  position = rand()%8;
  assets.eventCircle.height = assets.eventCircle.width = 272;
  assets.eventIndicator.height = assets.eventIndicator.width = 20;

  float outerRadius = assets.eventCircle.width / 2.0f;
  float innerRadius = (assets.eventCircle.width / 2.0f) * 0.85f;

  float calculatedSpeed = calculateSpeed(chosenPokemon);
  float speed[] = {
      calculatedSpeed,
      calculatedSpeed * 0.8,
      calculatedSpeed * 0.6,
      calculatedSpeed * 0.4,
  };

  angle += speed[lvlFarol];

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

    float ballX = circlePosition.x + innerRadius * cos(angle);
    float ballY = circlePosition.y + innerRadius * sin(angle);

    int captureX = ballX >= rectanglePositions[position].x - 20 && ballX <= rectanglePositions[position].x + rectanglePositions[position].width;
    int captureY = ballY >= rectanglePositions[position].y - 20 && ballY <= rectanglePositions[position].y + rectanglePositions[position].height;

    if (captureX && captureY)
    {
      return true;
    }

    return false;
  }
}

float calculateSpeed(Pokemon chosenPokemon)
{ 

    // A velocidade base depende da raridade do Pokémon
    float speed;

    if (chosenPokemon.rarity == TRASH)
    {
        speed = 0.001f;
    }
    else if (chosenPokemon.rarity == COMMON)
    {
        speed = 0.002f;
    }
    else if (chosenPokemon.rarity == RARE)
    {
        speed = 0.003f;
    }
    else if (chosenPokemon.rarity == LEGENDARY)
    {
        speed = 0.004f;
    }


    return speed;
}

