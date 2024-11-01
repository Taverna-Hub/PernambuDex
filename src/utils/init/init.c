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

  assets.feiraPlay = LoadTexture("assets/backgrounds/feiraPlay.png");

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
  assets.PraiaLimpaButtonBlue = LoadTexture("assets/buttons/blue/praiaLimpaButton.png");
  assets.SinalFarolButtonBlue = LoadTexture("assets/buttons/blue/sinalFarolButton.png");
  assets.EncantoItamaracaButtonBlue = LoadTexture("assets/buttons/blue/encantoItamaracaButton.png");

  assets.boaViagemButtonRed = LoadTexture("assets/buttons/red/boaViagemButton.png");
  assets.feiraButtonRed = LoadTexture("assets/buttons/red/feiraButton.png");
  assets.noivaButtonRed = LoadTexture("assets/buttons/red/noivaButton.png");
  assets.olindaButtonRed = LoadTexture("assets/buttons/red/olindaButton.png");
  assets.pedraButtonRed = LoadTexture("assets/buttons/red/pedraButton.png");
  assets.PraiaLimpaButtonRed = LoadTexture("assets/buttons/red/praiaLimpaButton.png");
  assets.SinalFarolButtonRed = LoadTexture("assets/buttons/red/sinalFarolButton.png");
  assets.EncantoItamaracaButtonRed = LoadTexture("assets/buttons/red/encantoItamaracaButton.png");
  assets.pernamBall = LoadTexture("assets/pernam-ball.png");
  assets.coin = LoadTexture("assets/coin.png");
  assets.confirmButton = LoadTexture("assets/buttons/green/confirmButton.png");

  assets.typhlosion = LoadTexture("assets/pokemons/feira/typhlosion.png");
  assets.quilava = LoadTexture("assets/pokemons/feira/quilava.png");
  assets.cyndaquill = LoadTexture("assets/pokemons/feira/cyndaquill.png");
  assets.speechBubble = LoadTexture("assets/speech-bubble.png");

  assets.captureCircle = LoadTexture("assets/captureCircle.png");
  assets.captureIndicator = LoadTexture("assets/captureIndicator.png");

  return assets;
}