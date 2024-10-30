#include "init.h"
#include "raylib.h"

int frames = 0;

Assets LoadAssets(void)
{
  Assets assets;

  assets.boaViagemMenu = LoadTexture("assets/backgrounds/boaViagemMenu.png");
  assets.noivaMenu = LoadTexture("assets/backgrounds/noivaMenu.png");
  assets.feiraMenu = LoadTexture("assets/backgrounds/feiraMenu.png");
  assets.olindaMenu = LoadTexture("assets/backgrounds/olindaMenu.png");
  assets.pedraMenu = LoadTexture("assets/backgrounds/pedraMenu.png");

  assets.trapezeSelector = LoadTexture("assets/backgrounds/trapezeSelector.png");

  assets.playButton = LoadTexture("assets/buttons/playButton.png");
  assets.mastersButton = LoadTexture("assets/buttons/mastersButton.png");

  assets.leaveButtonRed = LoadTexture("assets/buttons/red/leaveButton.png");
  assets.leaveButtonBlue = LoadTexture("assets/buttons/blue/leaveButton.png");

  assets.boaViagemButtonBlue = LoadTexture("assets/buttons/blue/boaViagemButton.png");
  assets.feiraButtonBlue = LoadTexture("assets/buttons/blue/feiraButton.png");
  assets.noivaButtonBlue = LoadTexture("assets/buttons/blue/noivaButton.png");
  assets.olindaButtonBlue = LoadTexture("assets/buttons/blue/olindaButton.png");
  assets.pedraButtonBlue = LoadTexture("assets/buttons/blue/pedraButton.png");

  assets.boaViagemButtonRed = LoadTexture("assets/buttons/red/boaViagemButton.png");
  assets.feiraButtonRed = LoadTexture("assets/buttons/red/feiraButton.png");
  assets.noivaButtonRed = LoadTexture("assets/buttons/red/noivaButton.png");
  assets.olindaButtonRed = LoadTexture("assets/buttons/red/olindaButton.png");
  assets.pedraButtonRed = LoadTexture("assets/buttons/red/pedraButton.png");

  assets.pernamBall = LoadTexture("assets/pernam-ball.png");

  return assets;
}