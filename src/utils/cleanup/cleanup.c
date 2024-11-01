#include "cleanup.h"
#include "raylib.h"

void UnloadAssets(Assets assets)
{
  UnloadTexture(assets.boaViagemMenu);
  UnloadTexture(assets.boaViagemPlay);
  UnloadTexture(assets.olindaMenu);
  UnloadTexture(assets.olindaPlay);
  UnloadTexture(assets.noivaMenu);
  UnloadTexture(assets.noivaPlay);
  UnloadTexture(assets.pedraMenu);
  UnloadTexture(assets.pedraPlay);
  UnloadTexture(assets.feiraMenu);
  UnloadTexture(assets.feiraPlay);
  UnloadTexture(assets.playButton);
  UnloadTexture(assets.mastersButton);
  UnloadTexture(assets.leaveButtonBlue);
  UnloadTexture(assets.boaViagemButtonBlue);
  UnloadTexture(assets.olindaButtonBlue);
  UnloadTexture(assets.noivaButtonBlue);
  UnloadTexture(assets.pedraButtonBlue);
  UnloadTexture(assets.feiraButtonBlue);
  UnloadTexture(assets.leaveButtonRed);
  UnloadTexture(assets.boaViagemButtonRed);
  UnloadTexture(assets.olindaButtonRed);
  UnloadTexture(assets.noivaButtonRed);
  UnloadTexture(assets.pedraButtonRed);
  UnloadTexture(assets.feiraButtonRed);
  UnloadTexture(assets.pernamBall);

  UnloadTexture(assets.confirmButton);
  UnloadTexture(assets.cyndaquill);
  UnloadTexture(assets.quilava);
  UnloadTexture(assets.typhlosion);
  UnloadTexture(assets.EncantoItamaracaButtonBlue);
  UnloadTexture(assets.EncantoItamaracaButtonRed);
  UnloadTexture(assets.PraiaLimpaButtonBlue);
  UnloadTexture(assets.PraiaLimpaButtonRed);
  UnloadTexture(assets.SinalFarolButtonBlue);
  UnloadTexture(assets.SinalFarolButtonRed);

  UnloadTexture(assets.itemEncanto_1);
  UnloadTexture(assets.itemEncanto_2);
  UnloadTexture(assets.itemEncanto_3);
  UnloadTexture(assets.itemPraiaLimpa_1);
  UnloadTexture(assets.itemPraiaLimpa_2);
  UnloadTexture(assets.itemPraiaLimpa_3);

  UnloadTexture(assets.captureCircle);
  UnloadTexture(assets.captureIndicator);
}
