#include <raylib.h>
#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/button/button.h"
#include "place.h"

static void handleButtons(Vector2 mousePos, Assets assets);

typedef enum Places
{
  BOA_VIAGEM = 0,
  NOIVA = 1,
  OLINDA = 2,
  FEIRA = 3,
  PEDRA = 4,
} Places;

Places place = BOA_VIAGEM;

void DrawSelectPlace(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps imageProps = resizeImage(assets.noivaMenu);
  DrawTextureEx(assets.noivaMenu, (Vector2){imageProps.x, imageProps.y}, 0.0f, imageProps.scale, WHITE);

  DrawTexture(assets.trapezeSelector, 512, 0, RAYWHITE);
  handleButtons(mousePosition, assets);
}

static void handleButtons(Vector2 mousePosition, Assets assets)
{
  int heightNotSelected = 51;
  int heightSelected = 67;

  // BV button
  assets.boaViagemButtonBlue.width = 272;
  assets.boaViagemButtonBlue.height = heightNotSelected;
  Rectangle boaViagemButtonBlueRect = {671, 137, assets.boaViagemButtonBlue.width, assets.boaViagemButtonBlue.height};

  assets.boaViagemButtonRed.width = 358;
  assets.boaViagemButtonRed.height = heightSelected;
  Rectangle boaViagemButtonRedRect = {530, 137, assets.boaViagemButtonRed.width, assets.boaViagemButtonRed.height};

  // Noiva button
  assets.noivaButtonBlue.width = 335;
  assets.noivaButtonBlue.height = heightNotSelected;
  Rectangle noivaButtonBlueRect = {600, 236, assets.noivaButtonBlue.width, assets.noivaButtonBlue.height};

  assets.noivaButtonRed.width = 440;
  assets.noivaButtonRed.height = heightSelected;
  Rectangle noivaButtonRedRect = {491, 236, assets.noivaButtonRed.width, assets.noivaButtonRed.height};

  // Olinda button
  assets.olindaButtonBlue.width = 319;
  assets.olindaButtonBlue.height = heightNotSelected;
  Rectangle olindaButtonBlueRect = {601, 319, assets.olindaButtonBlue.width, assets.olindaButtonBlue.height};

  assets.olindaButtonRed.width = 419;
  assets.olindaButtonRed.height = heightSelected;
  Rectangle olindaButtonRedRect = {500, 319, assets.olindaButtonRed.width, assets.olindaButtonRed.height};

  // Pedra button
  assets.pedraButtonBlue.width = 192;
  assets.pedraButtonBlue.height = heightNotSelected;
  Rectangle pedraButtonBlueRect = {713, 402, assets.pedraButtonBlue.width, assets.pedraButtonBlue.height};

  assets.pedraButtonRed.width = 252;
  assets.pedraButtonRed.height = heightSelected;
  Rectangle pedraButtonRedRect = {494, 402, assets.pedraButtonRed.width, assets.pedraButtonRed.height};

  // Feira button
  assets.feiraButtonBlue.width = 232;
  assets.feiraButtonBlue.height = heightNotSelected;
  Rectangle feiraButtonBlueRect = {671, 485, assets.feiraButtonBlue.width, assets.feiraButtonBlue.height};

  assets.feiraButtonRed.width = 304;
  assets.feiraButtonRed.height = heightSelected;
  Rectangle feiraButtonRedRect = {519, 485, assets.feiraButtonRed.width, assets.feiraButtonRed.height};

  if (CheckCollisionPointRec(mousePosition, boaViagemButtonBlueRect))
  {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    DrawTexture(assets.boaViagemButtonRed, boaViagemButtonRedRect.x, boaViagemButtonRedRect.y, RAYWHITE);
  }
  else
  {
    DrawTexture(assets.boaViagemButtonBlue, boaViagemButtonBlueRect.x, boaViagemButtonBlueRect.y, RAYWHITE);
  }

  if (CheckCollisionPointRec(mousePosition, olindaButtonBlueRect))
  {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    DrawTexture(assets.olindaButtonRed, olindaButtonRedRect.x, olindaButtonRedRect.y, RAYWHITE);
  }
  else
  {
    DrawTexture(assets.olindaButtonBlue, olindaButtonBlueRect.x, olindaButtonBlueRect.y, RAYWHITE);
  }

  if (CheckCollisionPointRec(mousePosition, noivaButtonBlueRect))
  {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    DrawTexture(assets.noivaButtonRed, noivaButtonRedRect.x, noivaButtonRedRect.y, RAYWHITE);
  }
  else
  {
    DrawTexture(assets.noivaButtonBlue, noivaButtonBlueRect.x, noivaButtonBlueRect.y, RAYWHITE);
  }

  if (CheckCollisionPointRec(mousePosition, pedraButtonBlueRect))
  {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    DrawTexture(assets.pedraButtonRed, pedraButtonRedRect.x, pedraButtonRedRect.y, RAYWHITE);
  }
  else
  {
    DrawTexture(assets.pedraButtonBlue, pedraButtonBlueRect.x, pedraButtonBlueRect.y, RAYWHITE);
  }

  if (CheckCollisionPointRec(mousePosition, feiraButtonBlueRect))
  {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    DrawTexture(assets.feiraButtonRed, feiraButtonRedRect.x, feiraButtonRedRect.y, RAYWHITE);
  }
  else
  {
    DrawTexture(assets.feiraButtonBlue, feiraButtonBlueRect.x, feiraButtonBlueRect.y, RAYWHITE);
  }
}