#include <raylib.h>
#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "place.h"
#include <stdio.h>

static void handleButtons(Vector2 mousePos, Assets assets);

typedef enum Places
{
  PBOA_VIAGEM = 0,
  PNOIVA = 1,
  POLINDA = 2,
  PPEDRA = 3,
  PFEIRA = 4,
  PSAIR = 5,
} Places;

Places place = PBOA_VIAGEM;

typedef struct SelectBackground
{
  Texture2D texture;
  imageProps props;
} SelectBackground;

typedef struct Button
{
  Rectangle blueRect;
  Rectangle redRect;
  Texture2D blueTexture;
  Texture2D redTexture;
  int place;
} Button;

void DrawSelectPlace(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  SelectBackground backgrounds[] = {
      {assets.boaViagemMenu,
       resizeImage(assets.boaViagemMenu)},
      {assets.noivaMenu,
       resizeImage(assets.noivaMenu)},
      {assets.olindaMenu,
       resizeImage(assets.olindaMenu)},
      {assets.pedraMenu,
       resizeImage(assets.pedraMenu)},
      {assets.feiraMenu,
       resizeImage(assets.feiraMenu)}};

  DrawTextureEx(backgrounds[place].texture,
                (Vector2){backgrounds[place].props.x,
                          backgrounds[place].props.y},
                0.0f,
                backgrounds[place].props.scale,
                WHITE);

  DrawTexture(assets.trapezeSelector, 512, 0, RAYWHITE);
  handleButtons(mousePosition, assets);
}

void UpdateSelectPlace(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Rectangle olindaButtonRedRect = {500, 319, assets.olindaButtonRed.width, assets.olindaButtonRed.height};
  Rectangle feiraButtonRedRect = {519, 485, assets.feiraButtonRed.width, assets.feiraButtonRed.height};
  Rectangle leaveButtonBlueRect = {649, 652, assets.leaveButtonBlue.width, assets.leaveButtonBlue.height};

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    if (CheckCollisionPointRec(mousePosition, feiraButtonRedRect))
    {
      *currentScreen = FEIRA;
      return;
    }

    if (CheckCollisionPointRec(mousePosition, olindaButtonRedRect))
    {
      *currentScreen = OLINDA;
      return;
    }

    if (CheckCollisionPointRec(mousePosition, leaveButtonBlueRect))
    {
      *currentScreen = MENU;
      return;
    }
  }
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

  // Leave button
  assets.leaveButtonBlue.width = 105;
  assets.leaveButtonBlue.height = heightNotSelected;
  Rectangle leaveButtonBlueRect = {649, 652, assets.leaveButtonBlue.width, assets.leaveButtonBlue.height};

  Button buttons[] = {
      {boaViagemButtonBlueRect, boaViagemButtonRedRect, assets.boaViagemButtonBlue, assets.boaViagemButtonRed, PBOA_VIAGEM},
      {olindaButtonBlueRect, olindaButtonRedRect, assets.olindaButtonBlue, assets.olindaButtonRed, POLINDA},
      {noivaButtonBlueRect, noivaButtonRedRect, assets.noivaButtonBlue, assets.noivaButtonRed, PNOIVA},
      {pedraButtonBlueRect, pedraButtonRedRect, assets.pedraButtonBlue, assets.pedraButtonRed, PPEDRA},
      {feiraButtonBlueRect, feiraButtonRedRect, assets.feiraButtonBlue, assets.feiraButtonRed, PFEIRA}};

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (CheckCollisionPointRec(mousePosition, buttons[i].blueRect))
    {
      SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
      place = buttons[i].place;
    }
  }

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (place == buttons[i].place)
    {
      DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
    }
    else
    {
      DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
    }
  }

  DrawTexture(assets.leaveButtonBlue, leaveButtonBlueRect.x, leaveButtonBlueRect.y, RAYWHITE);
}