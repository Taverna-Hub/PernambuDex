#include <raylib.h>
#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "feira.h"
#include "../../character/character.h"
#include <stdio.h>
#include <string.h>

static void handleBUttons(Vector2 mousePosition, Assets assets, Levels lvlPraia, Levels lvlFarol, Levels lvlEncanto);

Levels level = LVL_0;
int shopkeeperLevel = 0;

void DrawFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);
  char moneyStr[20];
  imageProps feiraBackground = resizeImage(assets.feiraPlay);
  DrawTextureEx(assets.feiraPlay, (Vector2){feiraBackground.x, feiraBackground.y}, 0.0f, feiraBackground.scale, WHITE);

  if (shopkeeperLevel <= 3)
  {
    assets.cyndaquill.width = assets.cyndaquill.height = 392;
    DrawTexture(assets.cyndaquill, 16, 115, RAYWHITE);
  }
  else if (shopkeeperLevel <= 6)
  {
    assets.quilava.width = assets.quilava.height = 392;
    DrawTexture(assets.quilava, -25, 113, RAYWHITE);
  }
  else
  {
    assets.typhlosion.width = assets.typhlosion.height = 392;
    DrawTexture(assets.typhlosion, -18, 136, RAYWHITE);
  }

  assets.speechBubble.width = assets.speechBubble.height = 472;
  DrawTexture(assets.speechBubble, 197, -59, RAYWHITE);

  assets.coin.height = assets.coin.width = 60;
  DrawTexture(assets.coin, 32, 32, RAYWHITE);
  sprintf(moneyStr, "%ld", character.money);
  DrawText(moneyStr, 95, 45, 40, RAYWHITE);

  handleBUttons(mousePosition, assets, );
}

void showItemLabel(Item item, Assets coin);

void UpdateFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{

  Rectangle PraiaLimpaButtonRect = {694, 248, assets.PraiaLimpaButtonRed.width, assets.PraiaLimpaButtonRed.height};
  Rectangle SinalFarolButtonRect = {688, 341, assets.SinalFarolButtonRed.width, assets.SinalFarolButtonRed.height};
  Rectangle EncantoIlhaButtonRect = {663, 432, assets.EncantoItamaracaButtonRed.width, assets.EncantoItamaracaButtonRed.height};
  Rectangle leaveButtonRedRec = {749, 578, assets.leaveButtonRed.width, assets.leaveButtonRed.height};
  Rectangle confirmButtonRect = {292, 184, assets.confirmButton.width, assets.confirmButton.height};

  if (level == LPRAIA_LIMPA_1)
  {
    Item item;
    // item.text = character.name;
    item.text = " Reduz minimamente o lixo das áreas criando um\n ambiente mais limpo e preservado ideal para\n ajudar a manter praias e parquer livres de\n residuos, incentivando pokemons e treinadores\n a se aventurarem mais nesses locais";

    item.coinNumber = "5";
    item.image = assets.itemPraiaLimpa_1;
    item.imageSize = 69;
    showItemLabel(item, assets);
  }

  if (level == LPRAIA_LIMPA_2)
  {
    Item item;
    item.text = " Diminuir drasticamente o aparecimento de\n lixo nos locais de captura. redes que pegam\n os Trubbish antes de chegarem à areia. Menos\n lixo, mais diversão.";

    item.coinNumber = "30";
    item.image = assets.itemPraiaLimpa_3;
    item.imageSize = 69;
    showItemLabel(item, assets);
  }

  if (level == LPRAIA_LIMPA_3)
  {
    Item item;
    item.text = " Erradica o lixo nas areas de captura. Porque\n quem quer um Garbodor na praia? Vamos\n transformar nosso paraíso em um lugar livre\n de Trubbish! ";

    item.coinNumber = "200";
    item.image = assets.itemPraiaLimpa_3;
    item.imageSize = 69;
    showItemLabel(item, assets);
  }

  if (level == LSINAL_FAROL_1)
  {
    Item item;
    // item.text = pokemons[0].name;
    item.text = " Aumenta suavemente a chance de capturar\n um pokemon de raridade maior. Esse farol irá\n ilumiar as aguas e florestas, facilitando a caça\n de pokemons lendarios.";
    item.coinNumber = "10";
    item.image = assets.itemFarol_1;
    item.imageSize = 60;
    showItemLabel(item, assets);
  }

  if (level == LSINAL_FAROL_2)
  {
    Item item;
    item.text = " Facilita ainda mais a captura de pokemons.\n Com essa luz encandeante, os pokemons mais\n resistentes se tornam mais facil de serem\n caçados.";
    item.coinNumber = "75";
    item.image = assets.itemFarol_2;
    item.imageSize = 60;
    showItemLabel(item, assets);
  }

  if (level == LSINAL_FAROL_3)
  {
    Item item;
    item.text = " Aumenta suavemente a chance de capturar\n um pokemon de raridade maior. Esse farol irá\n ilumiar as aguas e florestas, facilitando a caça\n de pokemons lendarios.";
    item.coinNumber = "500";
    item.image = assets.itemFarol_3;
    item.imageSize = 60;
    showItemLabel(item, assets);
  }

  if (level == LENCT_ITAM_1)
  {
    Item item;
    item.text = " Aumenta um pouco a sua chance de capturar\n um pokemon. Esse encanto faz com que\n pokemons fiquem mais sucetiveis a cair em\n suas armadilhas e iscas.";
    item.coinNumber = "7";
    item.image = assets.itemEncanto_1;
    item.imageSize = 60;
    showItemLabel(item, assets);
  }

  if (level == LENCT_ITAM_2)
  {
    Item item;
    item.text = " Aumenta ainda mais sua chance de capturar\n um pokemon de raridade maior. Esse encanto\n tem um estramho poder der atrair apenas\n pokemons mais raros.";
    item.coinNumber = "20";
    item.image = assets.itemEncanto_2;
    item.imageSize = 65;
    showItemLabel(item, assets);
  }
  if (level == LENCT_ITAM_3)
  {
    Item item;
    item.text = " Aumenta drasticamente a chance de\n capturar um pokemon de raridade maior. Esse\n farol irá ilumiar as aguas e florestas,\n facilitando a caça de pokemons lendarios.";
    item.coinNumber = "200";
    item.image = assets.itemEncanto_3;
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
    if (CheckCollisionPointRec(mousePosition, confirmButtonRect))
    {
      switch (level)
      {
      case LPRAIA_LIMPA_1:

        if (buyItem(10))
        {
        }
        else
        {
          printf("\neres pobre, no tenes denhero");
        }
        break;
      case LPRAIA_LIMPA_2:
        /* code */
        break;
      case LPRAIA_LIMPA_3:
        /* code */
        break;
      case LENCT_ITAM_1:
        /* code */
        break;
      case LENCT_ITAM_2:
        /* code */
        break;
      case LENCT_ITAM_3:
        /* code */
        break;
      case LSINAL_FAROL_1:
        /* code */
        break;
      case LSINAL_FAROL_2:
        /* code */
        break;
      case LSINAL_FAROL_3:
        /* code */
        break;

      default:
        printf("\neres pobre, no tenes denhero");
        break;
      }
    }
  }
}

void showItemLabel(Item item, Assets assets)
{
  assets.coin.height = assets.coin.width = 60;

  DrawTexture(assets.coin, 356, 142, RAYWHITE);

  DrawText(item.coinNumber, 420, 152, 48, DARKBROWN);
  item.image.width = item.image.height = item.imageSize;
  DrawTexture(item.image, 343, 448, RAYWHITE);

  Vector2 position = {380, 521};
  Vector2 size = {300, 0};
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

static void handleBUttons(Vector2 mousePosition, Assets assets, Levels lvlPraia, Levels lvlFarol, Levels lvlEncanto)
{
  // Praia LimpaBUtton
  assets.PraiaLimpaButtonBlue.width = 271;
  assets.PraiaLimpaButtonBlue.height = 61;
  Rectangle PraiaLimpaButtonBlueRect = {694, 248, assets.PraiaLimpaButtonBlue.width, assets.PraiaLimpaButtonBlue.height};

  assets.PraiaLimpaButtonRed.width = 271;
  assets.PraiaLimpaButtonRed.height = 61;
  Rectangle PraiaLimpaButtonRedRect = {694, 248, assets.PraiaLimpaButtonRed.width, assets.PraiaLimpaButtonRed.height};

  // SInal Farol BUtton
  assets.SinalFarolButtonBlue.width = 285;
  assets.SinalFarolButtonBlue.height = 59;
  Rectangle SinalFarolButtonBlueRect = {688, 341, assets.SinalFarolButtonBlue.width, assets.SinalFarolButtonBlue.height};

  assets.SinalFarolButtonRed.width = 285;
  assets.SinalFarolButtonRed.height = 59;
  Rectangle SinalFarolButtonRedRect = {688, 341, assets.SinalFarolButtonRed.width, assets.SinalFarolButtonRed.height};

  // Encanto Itamaraca BUtton
  assets.EncantoItamaracaButtonBlue.width = 333;
  assets.EncantoItamaracaButtonBlue.height = 51;
  Rectangle EncantoItamaracaButtonBlueRect = {663, 432, assets.EncantoItamaracaButtonBlue.width, assets.EncantoItamaracaButtonBlue.height};

  assets.EncantoItamaracaButtonRed.width = 333;
  assets.EncantoItamaracaButtonRed.height = 51;
  Rectangle EncantoItamaracaButtonRedRect = {663, 432, assets.EncantoItamaracaButtonRed.width, assets.EncantoItamaracaButtonRed.height};

  // COnfirm BUtton
  assets.confirmButton.width = 106;
  assets.confirmButton.height = 40;
  Rectangle confirmButtonRect = {292, 184, assets.confirmButton.width, assets.confirmButton.height};

  // Leave button
  assets.leaveButtonBlue.width = 166;
  assets.leaveButtonBlue.height = 80;
  Rectangle leaveButtonBlueRec = {749, 578, assets.leaveButtonBlue.width, assets.leaveButtonBlue.height};

  assets.leaveButtonRed.width = 166;
  assets.leaveButtonRed.height = 80;
  Rectangle leaveButtonRedRec = {749, 578, assets.leaveButtonRed.width, assets.leaveButtonRed.height};

  Button buttons[] = {
      {PraiaLimpaButtonBlueRect, PraiaLimpaButtonRedRect, assets.PraiaLimpaButtonBlue, assets.PraiaLimpaButtonRed, lvlPraia},
      {SinalFarolButtonBlueRect, SinalFarolButtonRedRect, assets.SinalFarolButtonBlue, assets.SinalFarolButtonRed, lvlFarol},
      {EncantoItamaracaButtonBlueRect, EncantoItamaracaButtonRedRect, assets.EncantoItamaracaButtonBlue, assets.EncantoItamaracaButtonRed, lvlEncanto},
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
