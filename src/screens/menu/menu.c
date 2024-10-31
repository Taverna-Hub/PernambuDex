#include <raylib.h>
#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "menu.h"

static void handleButtons(Vector2 mousePos, Assets assets);

void DrawMenu(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps imageProps = resizeImage(assets.noivaMenu);
  DrawTextureEx(assets.noivaMenu, (Vector2){imageProps.x, imageProps.y}, 0.0f, imageProps.scale, WHITE);
  handleButtons(mousePosition, assets);
}

void UpdateMenu(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  Rectangle playButtonRect = {411, 293, assets.playButton.width, assets.playButton.height};
  Rectangle mastersButtonRect = {298, 405, assets.mastersButton.width, assets.mastersButton.height};
  Rectangle leaveButtonRect = {427, 517, assets.leaveButtonRed.width, assets.leaveButtonRed.height};

  if (CheckCollisionPointRec(mousePosition, playButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    *currentScreen = SELECT_PLACE;
  }

  if (CheckCollisionPointRec(mousePosition, leaveButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    UnloadAssets(assets);
    CloseWindow();
  }
}

static void handleButtons(Vector2 mousePosition, Assets assets)
{
  int buttonsHeight = 80;

  // Play button
  assets.playButton.width = 200;
  assets.playButton.height = buttonsHeight;
  Rectangle playButtonRect = {411, 293, assets.playButton.width, assets.playButton.height};

  // Masters button
  assets.mastersButton.width = 428;
  assets.mastersButton.height = buttonsHeight;
  Rectangle mastersButtonRect = {298, 405, assets.mastersButton.width, assets.mastersButton.height};

  // Leave button
  assets.leaveButtonRed.width = 166;
  assets.leaveButtonRed.height = buttonsHeight;
  Rectangle leaveButtonRect = {427, 517, assets.leaveButtonRed.width, assets.leaveButtonRed.height};

  DrawTexture(assets.playButton, playButtonRect.x, playButtonRect.y, RAYWHITE);
  DrawTexture(assets.mastersButton, mastersButtonRect.x, mastersButtonRect.y, RAYWHITE);
  DrawTexture(assets.leaveButtonRed, leaveButtonRect.x, leaveButtonRect.y, RAYWHITE);

  handleButtonCollision(mousePosition, assets.playButton, playButtonRect);
  handleButtonCollision(mousePosition, assets.mastersButton, mastersButtonRect);
  handleButtonCollision(mousePosition, assets.leaveButtonRed, leaveButtonRect);

  if (!CheckCollisionPointRec(mousePosition, playButtonRect) &&
      !CheckCollisionPointRec(mousePosition, mastersButtonRect) &&
      !CheckCollisionPointRec(mousePosition, leaveButtonRect))
  {
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
  }
}