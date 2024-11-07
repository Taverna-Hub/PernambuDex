#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../utils/constants.h"
#include "../../utils/resizeImage/resizeImage.h"
#include "../../utils/init/init.h"
#include "../../utils/cleanup/cleanup.h"
#include "../../utils/button/button.h"
#include "../../character/character.h"
#include "feira.h"

static void handleButtons(Vector2 mousePosition, Assets assets);
void DrawLevel(Assets assets);
void showItemFull();

int shopkeeperLevel = 0;
static bool showSpeechBubble = false;
bool isBought = true;

int lvl_Praia = 0;
int lvl_Farol = 0;
int lvl_Encanto = 0;
int botao = 0;

Item PraiaLimpa[3];
Item SinalFarol[3];
Item EncantoItamaraca[3];

void initializeItems(Item *item, char *coinNumber, char *text, Texture2D image, int imageSize)
{
  strncpy(item->coinNumber, coinNumber, sizeof(item->coinNumber) - 1);
  item->coinNumber[sizeof(item->coinNumber) - 1] = '\0';

  strncpy(item->text, text, sizeof(item->text) - 1);
  item->text[sizeof(item->text) - 1] = '\0';

  item->image = image;
  item->imageSize = imageSize;
}

void handleInitializeAllItems(Assets assets)
{
  initializeItems(&PraiaLimpa[0], "5", " Reduz minimamente o lixo das áreas criando um\n ambiente mais limpo e preservado ideal para\n ajudar a manter praias e parquer livres de\n residuos, incentivando pokemons e treinadores\n a se aventurarem mais nesses locais", assets.itemPraiaLimpa_1, 69);
  initializeItems(&PraiaLimpa[1], "15", " Diminuir drasticamente o aparecimento de\n lixo nos locais de captura. redes que pegam\n os Trubbish antes de chegarem à areia. Menos\n lixo, mais diversão.", assets.itemPraiaLimpa_2, 69);
  initializeItems(&PraiaLimpa[2], "100", " Erradica o lixo nas áreas de captura. Porque\n quem quer um Garbodor na praia? Vamos\n transformar nosso paraíso em um lugar livre\n de Trubbish! ", assets.itemPraiaLimpa_3, 69);

  initializeItems(&SinalFarol[0], "7", " Aumenta suavemente a chance de capturar\n um pokemon de raridade maior. Esse farol irá\n ilumiar as aguas e florestas, facilitando a caça\n de pokemons lendarios.", assets.itemFarol_1, 60);
  initializeItems(&SinalFarol[1], "17", " Facilita ainda mais a captura de pokemons.\n Com essa luz encandeante, os pokemons mais\n resistentes se tornam mais facil de serem\n caçados.", assets.itemFarol_2, 60);
  initializeItems(&SinalFarol[2], "107", " Cega temporariamente a maioria dos pokemons,\n facilitando sua captura. Acho que tem uma\n pedra do sol lá dentro.", assets.itemFarol_3, 60);

  initializeItems(&EncantoItamaraca[0], "10", " Aumenta um pouco a sua chance de capturar\n um pokemon. Esse encanto faz com que\n pokemons fiquem mais sucetiveis a cair em\n suas armadilhas e iscas.", assets.itemEncanto_1, 65);
  initializeItems(&EncantoItamaraca[1], "20", " Aumenta ainda mais sua chance de capturar\n um pokemon de raridade maior. Esse encanto\n tem um estranho poder der atrair apenas\n pokemons mais raros.", assets.itemEncanto_2, 65);
  initializeItems(&EncantoItamaraca[2], "110", " Aumenta drasticamente a chance de\n capturar um pokemon de raridade maior. Esse\n farol irá ilumiar as aguas e florestas,\n facilitando a caça de pokemons lendarios.", assets.itemEncanto_3, 65); // todo
}

void DrawFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{
  ClearBackground(RAYWHITE);
  char moneyStr[20];
  imageProps feiraBackground = resizeImage(assets.feiraPlay);
  DrawTextureEx(assets.feiraPlay, (Vector2){feiraBackground.x, feiraBackground.y}, 0.0f, feiraBackground.scale, WHITE);

  if (shopkeeperLevel < 3)
  {
    assets.cyndaquill.width = assets.cyndaquill.height = 392;
    DrawTexture(assets.cyndaquill, 16, 115, RAYWHITE);
  }
  else if (shopkeeperLevel < 6)
  {
    assets.quilava.width = assets.quilava.height = 392;
    DrawTexture(assets.quilava, -25, 113, RAYWHITE);
  }
  else
  {
    assets.typhlosion.width = assets.typhlosion.height = 392;
    DrawTexture(assets.typhlosion, -18, 136, RAYWHITE);
  }

  if (showSpeechBubble)
  {
    assets.speechBubble.width = assets.speechBubble.height = 472;
    DrawTexture(assets.speechBubble, 197, -59, RAYWHITE);
  }

  assets.coin.height = assets.coin.width = 60;
  DrawTexture(assets.coin, 32, 32, RAYWHITE);
  sprintf(moneyStr, "%ld", character.money);
  DrawText(moneyStr, 95, 45, 40, RAYWHITE);

  handleButtons(mousePosition, assets);
  DrawLevel(assets);
}

void showItemLabel(Item item, Assets coin, bool error);

void UpdateFeira(Screen *currentScreen, Vector2 mousePosition, Assets assets)
{

  Rectangle PraiaLimpaButtonRect = {694, 248, assets.PraiaLimpaButtonRed.width, assets.PraiaLimpaButtonRed.height};
  Rectangle SinalFarolButtonRect = {688, 341, assets.SinalFarolButtonRed.width, assets.SinalFarolButtonRed.height};
  Rectangle EncantoIlhaButtonRect = {663, 432, assets.EncantoItamaracaButtonRed.width, assets.EncantoItamaracaButtonRed.height};
  Rectangle leaveButtonRedRec = {749, 578, assets.leaveButtonRed.width, assets.leaveButtonRed.height};
  assets.confirmButton.width = 106;
  assets.confirmButton.height = 40;
  Rectangle confirmButtonRect = {324, 616, assets.confirmButton.width, assets.confirmButton.height};

  // SELEÇÃO DE ITENS

  if (botao == 1)
  {
    (lvl_Praia == 3) ? showItemFull() : showItemLabel(PraiaLimpa[lvl_Praia], assets, isBought);
  }

  else if (botao == 2)
  {
    (lvl_Farol == 3) ? showItemFull() : showItemLabel(SinalFarol[lvl_Farol], assets, isBought);
  }

  else if (botao == 3)
  {
    (lvl_Encanto == 3) ? showItemFull() : showItemLabel(EncantoItamaraca[lvl_Encanto], assets, isBought);
  }

  // BOTOES SAIR E COMPRAR

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    if (CheckCollisionPointRec(mousePosition, PraiaLimpaButtonRect) || CheckCollisionPointRec(mousePosition, SinalFarolButtonRect) || CheckCollisionPointRec(mousePosition, EncantoIlhaButtonRect))
    {
      isBought = true;
    }
    if (CheckCollisionPointRec(mousePosition, leaveButtonRedRec))
    {
      *currentScreen = SELECT_PLACE;
      showSpeechBubble = false;
      return;
    }

    if (CheckCollisionPointRec(mousePosition, confirmButtonRect))
    {

      int itemPrice = 0;
      isBought = false;
      switch (botao)
      {
      case 1:

        if (lvl_Praia < 3)
        {

          itemPrice = atoi(PraiaLimpa[lvl_Praia].coinNumber);
          isBought = buyItem(itemPrice);

          if (isBought)
          {
            printf("Você comprou: Praia Limpa! Novo saldo: %ld\n", character.money);

            lvl_Praia++;
            shopkeeperLevel++;
          }
          else
          {
            printf(" Eres pobre, no tenes dinero\n");
            showItemLabel(PraiaLimpa[lvl_Praia], assets, isBought);
          }
        }
        else
        {
          showItemFull();
        }
        break;

      case 2:

        if (lvl_Farol < 3)
        {

          itemPrice = atoi(SinalFarol[lvl_Farol].coinNumber);
          isBought = buyItem(itemPrice);

          if (isBought)
          {
            printf("Você comprou: Sinal do Farol! Novo saldo: %ld\n", character.money);
            lvl_Farol++;
            shopkeeperLevel++;
          }
          else
          {
            printf("Eres pobre, no tenes dinero\n");
            showItemLabel(SinalFarol[lvl_Farol], assets, isBought);
          }
        }

        break;

      case 3:

        if (lvl_Encanto < 3)
        {
          itemPrice = atoi(EncantoItamaraca[lvl_Encanto].coinNumber);
          isBought = buyItem(itemPrice);

          if (isBought)
          {
            printf("Você comprou: Encanto de itamaraca! Novo saldo: %ld\n", character.money);
            lvl_Encanto++;
            shopkeeperLevel++;
          }
          else
          {
            printf("Eres pobre, no tenes dinero\n");
            showItemLabel(EncantoItamaraca[lvl_Encanto], assets, isBought);
          }
        }
        break;

      default:
        printf("\neres pobre, no tenes denhero");
        showItemLabel(PraiaLimpa[lvl_Praia], assets, isBought);
        break;
      }
    }
  }
}

void showItemLabel(Item item, Assets assets, bool error)
{
  if (error)
  {
    assets.coin.height = assets.coin.width = 60;
    DrawTexture(assets.coin, 356, 142, RAYWHITE);
    DrawText(item.coinNumber, 420, 152, 48, DARKBROWN);
  }
  else if (!error)
  {
    Vector2 position = {332, 135};
    float fontSize = 24;
    char errorMessage[] = " Eres pobre,\n no tenes dinero.";
    DrawText(errorMessage, position.x, position.y, fontSize, DARKGRAY);
  }

  item.image.width = item.image.height = item.imageSize;
  DrawTexture(item.image, 343, 448, RAYWHITE);

  Vector2 position = {101, 521};
  Vector2 size = {300, 0};
  float rotation = 0.0f;
  float fontSize = 18;
  float spacing = 1.0f;

  DrawTextEx(assets.nunito, item.text, position, fontSize, spacing, BLACK);

  assets.confirmButton.width = 106;
  assets.confirmButton.height = 40;
  Rectangle confirmButtonRect = {324, 616, assets.confirmButton.width, assets.confirmButton.height};
  DrawTexture(assets.confirmButton, confirmButtonRect.x, confirmButtonRect.y, RAYWHITE);
}

void showItemFull()
{
  Vector2 position = {332, 135};
  float fontSize = 24;
  char allBought[] = " Ce compro tudo\n meu cumpade, cabô.";
  DrawText(allBought, position.x, position.y, fontSize, DARKGRAY);
}

static void handleButtons(Vector2 mousePosition, Assets assets)
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
      {PraiaLimpaButtonBlueRect, PraiaLimpaButtonRedRect, assets.PraiaLimpaButtonBlue, assets.PraiaLimpaButtonRed, 1},
      {SinalFarolButtonBlueRect, SinalFarolButtonRedRect, assets.SinalFarolButtonBlue, assets.SinalFarolButtonRed, 2},
      {EncantoItamaracaButtonBlueRect, EncantoItamaracaButtonRedRect, assets.EncantoItamaracaButtonBlue, assets.EncantoItamaracaButtonRed, 3},
      {leaveButtonBlueRec, leaveButtonRedRec, assets.leaveButtonBlue, assets.leaveButtonRed, -1}};

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (CheckCollisionPointRec(mousePosition, buttons[i].blueRect) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
      botao = buttons[i].botao;
      showSpeechBubble = true;
    }
  }

  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
  {
    if (botao == buttons[i].botao)
    {
      DrawTexture(buttons[i].redTexture, buttons[i].redRect.x, buttons[i].redRect.y, RAYWHITE);
    }
    else
    {
      DrawTexture(buttons[i].blueTexture, buttons[i].blueRect.x, buttons[i].blueRect.y, RAYWHITE);
    }
  }
}

void DrawLevel(Assets assets)
{
  Vector2 size = {30, 0};
  float fontSize = 32;
  // PRAIA
  Vector2 positionPraia = {921, 263};
  char lvlPraiaStr[2];
  snprintf(lvlPraiaStr, sizeof(lvlPraiaStr), "%d", lvl_Praia);
  DrawTextEx(assets.nunito, lvlPraiaStr, positionPraia, fontSize, 1.0f, WHITE);

  // FAROL
  Vector2 positionFarol = {930, 355};
  char lvlFarolStr[2];
  snprintf(lvlFarolStr, sizeof(lvlFarolStr), "%d", lvl_Farol);
  DrawTextEx(assets.nunito, lvlFarolStr, positionFarol, fontSize, 1.0f, WHITE);

  // ENCANTO
  Vector2 positionEncanto = {959, 440};
  char lvlEncantoStr[2];
  snprintf(lvlEncantoStr, sizeof(lvlEncantoStr), "%d", lvl_Encanto);
  DrawTextEx(assets.nunito, lvlEncantoStr, positionEncanto, fontSize, 1.0f, WHITE);
}
