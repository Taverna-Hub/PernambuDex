#ifndef INIT_H
#define INIT_H

#include "raylib.h"

typedef struct
{
  Texture2D boaViagemMenu;
  Texture2D boaViagemPlay;

  Texture2D olindaMenu;
  Texture2D olindaPlay;

  Texture2D noivaMenu;
  Texture2D noivaPlay;

  Texture2D pedraMenu;
  Texture2D pedraPlay;

  Texture2D feiraMenu;
  Texture2D feiraPlay;

  Texture2D trapezeSelector;

  Texture2D playButton;
  Texture2D mastersButton;

  Texture2D leaveButtonRed;
  Texture2D leaveButtonBlue;

  Texture2D boaViagemButtonRed;
  Texture2D olindaButtonRed;
  Texture2D noivaButtonRed;
  Texture2D pedraButtonRed;
  Texture2D feiraButtonRed;

  Texture2D boaViagemButtonBlue;
  Texture2D olindaButtonBlue;
  Texture2D noivaButtonBlue;
  Texture2D pedraButtonBlue;
  Texture2D feiraButtonBlue;

  Texture2D pernamBall;

} Assets;

Assets LoadAssets(void);

#endif