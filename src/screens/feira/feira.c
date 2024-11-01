#include <raylib.h>
#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "feira.h"
#include <stdio.h>


typedef enum Levels
{
  LVL_0 = 0,
  LPRAIA_LIMPA_1 = 1,
  LPRAIA_LIMPA_2 = 2,
  LPRAIA_LIMPA_3 = 3,
  LSINAL_FAROL_1 = 4,
  LSINAL_FAROL_2 = 5,
  LSINAL_FAROL_3 = 6,
  LENCT_ITAM_1 = 7,
  LENCT_ITAM_2 = 8,
  LENCT_ITAM_3 = 9,
} Levels;

Levels level = LVL_0;

typedef struct Button
{
  Rectangle blueRect;
  Rectangle redRect;
  Texture2D blueTexture;
  Texture2D redTexture;
  int level;
} Button;


typedef struct itemLabel
{
  Assets image;
  int imageX;
  int imageY;
  char * text;
  int textX;
  int textY; 
  char * coinNumber;
  int numberX;
  int numberY;
  
}itemLabel;

static void handleBUttons(Vector2 mousePosition, Assets assets);

void DrawFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps feiraBeckerShots = resizeImage(assets.feiraPlay);
  DrawTextureEx(assets.feiraPlay, (Vector2){feiraBeckerShots.x, feiraBeckerShots.y}, 0.0f, feiraBeckerShots.scale, WHITE);
  DrawTexture(assets.cyndaquill, 281, 226, RAYWHITE);
  handleBUttons(mousePosition, assets);

}
void showItemLabel(itemLabel item, Assets coin);


void UpdateFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
    
    Rectangle PraiaLimpaButtonRect = {694, 248, assets.PraiaLimpaButtonRed.width, assets.PraiaLimpaButtonRed.height};
    Rectangle SinalFarolButtonRect = {688, 341, assets.SinalFarolButtonRed.width, assets.SinalFarolButtonRed.height};
    Rectangle EncantoIlhaButtonRect = {663, 432, assets.EncantoItamaracaButtonRed.width, assets.EncantoItamaracaButtonRed.height};

    if(level == LPRAIA_LIMPA_1){
          itemLabel item;
          item.text = "Reduz minimamente o lixo das áreas criando um ambiente mais limpo e preservado ideal para ajudar a manter praias e parquer livres de residuos, incentivando pokemons e treinadores a se aventurarem mais nesses locais";
          item.textX = 62;
          item.textY = 89;

          item.numberX = 105;
          item.numberY = 48;
          item.coinNumber = "5";

          showItemLabel(item, assets);
        
      }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
      
      if(CheckCollisionPointRec(mousePosition, PraiaLimpaButtonRect)){
          printf("cu");
        
      }
      
      // if(CheckCollisionPointRec(mousePosition, SinalFarolButtonRect)){
        
      //   return;
      // }

      // if(CheckCollisionPointRec(mousePosition, EncantoIlhaButtonRect)){
        
      //   return;
      // }
    }
    
}

void showItemLabel(itemLabel item, Assets coin)
{    
  Rectangle limit = {62, 89, 329, 89};
  coin.coin.height = coin.coin.width = 40;
  DrawTexture(coin.coin, 94, 467, RAYWHITE);

  DrawText(item.coinNumber, item.numberX, item.numberY, 20,BLACK);
  Vector2 size = {item.textX , item.textY};
  Vector2 origem = {0, 0};

  DrawTextPro(GetFontDefault(), item.text, size, origem, 0.0f, 14, 1.0f, BLACK);
  

  

}

  static void handleBUttons(Vector2 mousePosition, Assets assets)
  {
    //Praia LimpaBUtton
    assets.PraiaLimpaButtonBlue.width = 271;
    assets.PraiaLimpaButtonBlue.height = 61;
    Rectangle PraiaLimpaButtonBlueRect = {694, 248, assets.PraiaLimpaButtonBlue.width, assets.PraiaLimpaButtonBlue.height};

    assets.PraiaLimpaButtonRed.width = 271;
    assets.PraiaLimpaButtonRed.height = 61;
    Rectangle PraiaLimpaButtonRedRect = {694, 248, assets.PraiaLimpaButtonRed.width, assets.PraiaLimpaButtonRed.height};
    
    //SInal Farol BUtton
    assets.SinalFarolButtonBlue.width = 285;
    assets.SinalFarolButtonBlue.height = 59;
    Rectangle SinalFarolButtonBlueRect = {688, 341, assets.SinalFarolButtonBlue.width, assets.SinalFarolButtonBlue.height};

    assets.SinalFarolButtonRed.width = 285;
    assets.SinalFarolButtonRed.height = 59;
    Rectangle SinalFarolButtonRedRect = {688, 341, assets.SinalFarolButtonRed.width, assets.SinalFarolButtonRed.height};
    
    //Encanto Itamaraca BUtton
    assets.EncantoItamaracaButtonBlue.width = 333;
    assets.EncantoItamaracaButtonBlue.height = 51;
    Rectangle EncantoItamaracaButtonBlueRect ={663, 432, assets.EncantoItamaracaButtonBlue.width, assets.EncantoItamaracaButtonBlue.height};

    assets.EncantoItamaracaButtonRed.width = 333;
    assets.EncantoItamaracaButtonRed.height = 51;
    Rectangle EncantoItamaracaButtonRedRect ={663, 432, assets.EncantoItamaracaButtonRed.width, assets.EncantoItamaracaButtonRed.height};

    //COnfirm BUtton
    assets.confirmButton.width = 106;
    assets.confirmButton.height = 40;
    Rectangle confirmButtonRect = {292, 184, assets.confirmButton.width, assets.confirmButton.height };
  
    //Leave button
    assets.leaveButtonBlue.width = 166;
    assets.leaveButtonBlue.height = 80;
    Rectangle leaveButtonBlueRec = {749, 578, assets.leaveButtonBlue.width, assets.leaveButtonBlue.height };

    assets.leaveButtonRed.width = 166;
    assets.leaveButtonRed.height = 80;
    Rectangle leaveButtonRedRec = {749, 578, assets.leaveButtonRed.width, assets.leaveButtonRed.height };


    Button buttons[] = {
      {PraiaLimpaButtonBlueRect, PraiaLimpaButtonRedRect, assets.PraiaLimpaButtonBlue, assets.PraiaLimpaButtonRed, LPRAIA_LIMPA_1},
      {SinalFarolButtonBlueRect, SinalFarolButtonRedRect, assets.SinalFarolButtonBlue, assets.SinalFarolButtonRed, LSINAL_FAROL_1},
      {EncantoItamaracaButtonBlueRect, EncantoItamaracaButtonRedRect, assets.EncantoItamaracaButtonBlue, assets.EncantoItamaracaButtonRed, LENCT_ITAM_1},
      {leaveButtonBlueRec, leaveButtonRedRec, assets.leaveButtonBlue, assets.leaveButtonRed, -1}};

    for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
    {
      if (CheckCollisionPointRec(mousePosition, buttons[i].blueRect) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
      {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        level = buttons[i].level;
      }
    }

    for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
    {
      if (level == buttons[i].level)
      {
        DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
      }
      else
      {
        DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
      }
    }
    
  }
  