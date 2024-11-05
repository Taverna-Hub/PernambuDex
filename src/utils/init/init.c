#include "init.h"
#include "../constants.h"
#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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

  assets.itemEncanto_1 = LoadTexture("assets/items/itemEncanto_1.png");
  assets.itemEncanto_2 = LoadTexture("assets/items/itemEncanto_2.png");
  assets.itemEncanto_3 = LoadTexture("assets/items/itemEncanto_3.png");

  assets.itemFarol_1 = LoadTexture("assets/items/itemFarol_1.png");
  assets.itemFarol_2 = LoadTexture("assets/items/itemFarol_2.png");
  assets.itemFarol_3 = LoadTexture("assets/items/itemFarol_3.png");

  assets.itemPraiaLimpa_1 = LoadTexture("assets/items/itemPraiaLimpa_1.png");
  assets.itemPraiaLimpa_2 = LoadTexture("assets/items/itemPraiaLimpa_2.png");
  assets.itemPraiaLimpa_3 = LoadTexture("assets/items/itemPraiaLimpa_3.png");

  assets.pernamBall = LoadTexture("assets/pernam-ball.png");
  assets.coin = LoadTexture("assets/coin.png");
  assets.confirmButton = LoadTexture("assets/buttons/green/confirmButton.png");

  assets.cyndaquill = LoadTexture("assets/pokemons/feira/cyndaquill.png");
  assets.typhlosion = LoadTexture("assets/pokemons/feira/typhlosion.png");
  assets.quilava = LoadTexture("assets/pokemons/feira/quilava.png");
  assets.captureIndicator = LoadTexture("assets/captureIndicator.png");

  assets.trubbish = LoadTexture("assets/pokemons/trubbish.png");
  assets.magikarp = LoadTexture("assets/pokemons/boaViagem/magikarp.png");
  assets.sharpedo = LoadTexture("assets/pokemons/boaViagem/sharpeedo.png");
  assets.wailord = LoadTexture("assets/pokemons/boaViagem/wailord.png");
  assets.vaporeon = LoadTexture("assets/pokemons/boaViagem/vaporeon.png");
  assets.garchomp = LoadTexture("assets/pokemons/boaViagem/garchomp.png");

  assets.chandelure = LoadTexture("assets/pokemons/olinda/chandelure.png");
  assets.darkrai = LoadTexture("assets/pokemons/olinda/darkrai.png");
  assets.haunter = LoadTexture("assets/pokemons/olinda/haunter.png");
  assets.mismagius = LoadTexture("assets/pokemons/olinda/mismagius.png");
  assets.zoroark = LoadTexture("assets/pokemons/olinda/zoroark.png");

  assets.cacnea = LoadTexture("assets/pokemons/pedraFurada/cacnea.png");
  assets.flygon = LoadTexture("assets/pokemons/pedraFurada/flygon.png");
  assets.groudon = LoadTexture("assets/pokemons/pedraFurada/groudon.png");
  assets.mandibuzz = LoadTexture("assets/pokemons/pedraFurada/mandibuzz.png");
  assets.sandile = LoadTexture("assets/pokemons/pedraFurada/sandile.png");

  assets.hoOh = LoadTexture("assets/pokemons/veuNoiva/ho-oh.png");
  assets.ninjask = LoadTexture("assets/pokemons/veuNoiva/ninjask.png");
  assets.pidove = LoadTexture("assets/pokemons/veuNoiva/pidove.png");
  assets.sweallow = LoadTexture("assets/pokemons/veuNoiva/sweallow.png");
  assets.yammega = LoadTexture("assets/pokemons/veuNoiva/yammega.png");

  assets.unknownPokemon = LoadTexture("assets/pokemons/unknownPokemon.png");

  assets.speechBubble = LoadTexture("assets/speech-bubble.png");

  assets.captureCircle = LoadTexture("assets/captureCircle.png");
  assets.captureIndicator = LoadTexture("assets/captureIndicator.png");
  assets.capturedRectangle = LoadTexture("assets/captured.png");

  return assets;
}

Pokemon pokemons[25];
void initializePokemon(Assets assets)
{
  // lixo
  pokemons[0].id = 0;
  pokemons[0].name = "Trubbish";
  pokemons[0].rarity = TRASH;
  pokemons[0].image = assets.trubbish;

  // boa viagem
  pokemons[1].id = 1;
  pokemons[1].name = "Magikarp";
  pokemons[1].rarity = COMMON;
  pokemons[1].image = assets.magikarp;
  pokemons[1].place = BOA_VIAGEM;

  pokemons[2].id = 2;
  pokemons[2].name = "Sharpedo";
  pokemons[2].rarity = COMMON;
  pokemons[2].image = assets.sharpedo;
  pokemons[2].place = BOA_VIAGEM;

  pokemons[3].id = 3;
  pokemons[3].name = "Vaporeon";
  pokemons[3].rarity = RARE;
  pokemons[3].image = assets.vaporeon;
  pokemons[3].place = BOA_VIAGEM;

  pokemons[4].id = 4;
  pokemons[4].name = "Wailord";
  pokemons[4].rarity = RARE;
  pokemons[4].image = assets.wailord;
  pokemons[4].place = BOA_VIAGEM;

  pokemons[5].id = 5;
  pokemons[5].name = "Garchomp";
  pokemons[5].rarity = LEGENDARY;
  pokemons[5].image = assets.garchomp;
  pokemons[5].place = BOA_VIAGEM;

  // Olinda
  pokemons[6].id = 6;
  pokemons[6].name = "Chandelure";
  pokemons[6].rarity = COMMON;
  pokemons[6].image = assets.chandelure;
  pokemons[6].place = OLINDA;

  pokemons[7].id = 7;
  pokemons[7].name = "Haunter";
  pokemons[7].rarity = COMMON;
  pokemons[7].image = assets.haunter;
  pokemons[7].place = OLINDA;

  pokemons[8].id = 8;
  pokemons[8].name = "Mismagius";
  pokemons[8].rarity = RARE;
  pokemons[8].image = assets.mismagius;
  pokemons[8].place = OLINDA;

  pokemons[9].id = 9;
  pokemons[9].name = "Zoroark";
  pokemons[9].rarity = RARE;
  pokemons[9].image = assets.zoroark;
  pokemons[9].place = OLINDA;

  pokemons[10].id = 10;
  pokemons[10].name = "Darkrai";
  pokemons[10].rarity = LEGENDARY;
  pokemons[10].image = assets.darkrai;
  pokemons[10].place = OLINDA;

  // pedra furada
  pokemons[11].id = 11;
  pokemons[11].name = "Cacnea";
  pokemons[11].rarity = COMMON;
  pokemons[11].image = assets.cacnea;
  pokemons[11].place = PEDRA;

  pokemons[12].id = 12;
  pokemons[12].name = "Sandile";
  pokemons[12].rarity = COMMON;
  pokemons[12].image = assets.sandile;
  pokemons[12].place = PEDRA;

  pokemons[13].id = 13;
  pokemons[13].name = "Mandibuzz";
  pokemons[13].rarity = RARE;
  pokemons[13].image = assets.mandibuzz;
  pokemons[13].place = PEDRA;

  pokemons[14].id = 14;
  pokemons[14].name = "Flygon";
  pokemons[14].rarity = RARE;
  pokemons[14].image = assets.flygon;
  pokemons[14].place = PEDRA;

  pokemons[15].id = 15;
  pokemons[15].name = "Groudon";
  pokemons[15].rarity = LEGENDARY;
  pokemons[15].image = assets.groudon;
  pokemons[15].place = PEDRA;

  // noiva
  pokemons[16].id = 16;
  pokemons[16].name = "Yanmega";
  pokemons[16].rarity = COMMON;
  pokemons[16].image = assets.yammega;
  pokemons[16].place = NOIVA;

  pokemons[17].id = 17;
  pokemons[17].name = "Swellow";
  pokemons[17].rarity = COMMON;
  pokemons[17].image = assets.sweallow;
  pokemons[17].place = NOIVA;

  pokemons[18].id = 18;
  pokemons[18].name = "Pidove";
  pokemons[18].rarity = RARE;
  pokemons[18].image = assets.pidove;
  pokemons[18].place = NOIVA;

  pokemons[19].id = 19;
  pokemons[19].name = "Ninjask";
  pokemons[19].rarity = RARE;
  pokemons[19].image = assets.ninjask;
  pokemons[19].place = NOIVA;

  pokemons[20].id = 20;
  pokemons[20].name = "Ho-oh";
  pokemons[20].rarity = LEGENDARY;
  pokemons[20].image = assets.hoOh;
  pokemons[20].place = NOIVA;

  for (int i = 0; i < 21; i++)
  {
    pokemons[i].captured = false;
  }
}

void insertCircular(PokeNode **head, PokeNode **tail, Pokemon pokemon)
{
  PokeNode *newPokeNode = (PokeNode *)malloc(sizeof(PokeNode));
  newPokeNode->pokemon = pokemon;

  if (newPokeNode != NULL)
  {
    if (*head == NULL)
    {
      *head = *tail = newPokeNode;
    }
    else
    {
      newPokeNode->next = *head;
      *head = newPokeNode;
    }
    (*tail)->next = *head;
  }
}
// Startindex valores = 1, 6, 11, 16
void initializeCircularList(Pokemon pokemons[], PokeNode **head, PokeNode **tail, int startIndex)
{

  for (int i = 0; i < 9; i++)
  {
    insertCircular(head, tail, pokemons[0]);
  }

  for (int j = startIndex; j < startIndex + 5; j++)
  {
    Pokemon pokemon = pokemons[j];

    if (pokemon.rarity == COMMON)
    {
      for (int i = 0; i < 3; i++)
      {
        insertCircular(head, tail, pokemon);
      }
    }

    if (pokemon.rarity == RARE)
    {
      for (int i = 0; i < 2; i++)
      {
        insertCircular(head, tail, pokemon);
      }
    }

    if (pokemon.rarity == LEGENDARY)
    {
      insertCircular(head, tail, pokemon);
    }
  }
}
