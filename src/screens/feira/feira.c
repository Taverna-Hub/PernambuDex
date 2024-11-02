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
  Texture2D image;
  int imageSize;
  char * text;
  char * coinNumber;
  
}itemLabel;

static void handleBUttons(Vector2 mousePosition, Assets assets);

void DrawFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);

  imageProps feiraBeckerShots = resizeImage(assets.feiraPlay);
  DrawTextureEx(assets.feiraPlay, (Vector2){feiraBeckerShots.x, feiraBeckerShots.y}, 0.0f, feiraBeckerShots.scale, WHITE);

  assets.typhlosion.width = assets.typhlosion.height = 392;
  DrawTexture(assets.typhlosion, -18, 136, RAYWHITE);

  assets.speechBubble.width = assets.speechBubble.height = 472;
  DrawTexture(assets.speechBubble, 197, -59, RAYWHITE);
  
  handleBUttons(mousePosition, assets);

}

void showItemLabel(itemLabel item, Assets coin);


void UpdateFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
    
    Rectangle PraiaLimpaButtonRect = {694, 248, assets.PraiaLimpaButtonRed.width, assets.PraiaLimpaButtonRed.height};
    Rectangle SinalFarolButtonRect = {688, 341, assets.SinalFarolButtonRed.width, assets.SinalFarolButtonRed.height};
    Rectangle EncantoIlhaButtonRect = {663, 432, assets.EncantoItamaracaButtonRed.width, assets.EncantoItamaracaButtonRed.height};
    Rectangle leaveButtonRedRec = {749, 578, assets.leaveButtonRed.width, assets.leaveButtonRed.height };

    if(level == LPRAIA_LIMPA_1)
    {
          itemLabel item;
          item.text = " Reduz minimamente o lixo das áreas criando um\n ambiente mais limpo e preservado ideal para\n ajudar a manter praias e parquer livres de\n residuos, incentivando pokemons e treinadores\n a se aventurarem mais nesses locais";

          item.coinNumber = "5";
          item.image = assets.itemPraiaLimpa_1;
          item.imageSize = 69;
          showItemLabel(item, assets);

        
    }

    if(level == LSINAL_FAROL_1){
      itemLabel item;
      item.text = "Aumenta suavemente a chance de capturar\n um pokemon de raridade maior. Esse farol irá\n ilumiar as aguas e florestas, facilitando a caça\n de pokemons lendarios.";
      item.coinNumber = "10";
      // item.image = ;
      // item.imageSize = ;
      showItemLabel(item, assets);
    }

    if(level == LENCT_ITAM_1)
    {
      itemLabel item;
      item.text = " Aumenta um pouco a sua chance de capturar\n um pokemon. Esse encanto faz com que\n pokemons fiquem mais sucetiveis a cair em\n suas armadilhas e iscas.";
      item.coinNumber = "7";
      item.image = assets.itemEncanto_1;
      item.imageSize = 65;
      showItemLabel(item, assets);
    }


    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      if (CheckCollisionPointRec(mousePosition, leaveButtonRedRec))
      {
        *currentScreen = SELECT_PLACE;
        return;
      }
    }
    
}

void showItemLabel(itemLabel item, Assets assets)
{
    assets.coin.height = assets.coin.width = 60;

    DrawTexture(assets.coin, 326, 141, RAYWHITE);

    DrawText(item.coinNumber, 390, 152, 40, DARKBROWN);
    item.image.width = item.image.height = item.imageSize;
    DrawTexture(item.image, 343, 448, RAYWHITE);


    Vector2 position = { 380, 521 }; 
    Vector2 size = { 300, 0 }; 
    float rotation = 0.0f; 
    float fontSize = 15; 
    float spacing = 1.0f; 

    Font font = GetFontDefault();
    DrawTextPro(font, item.text, position, size, rotation, fontSize, spacing, BLACK);

    assets.confirmButton.width = 106;
    assets.confirmButton.height = 40;
    Rectangle confirmButtonRect = {324, 616, assets.confirmButton.width, assets.confirmButton.height};
    DrawTexture(assets.confirmButton, confirmButtonRect.x, confirmButtonRect.y, RAYWHITE);
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
  