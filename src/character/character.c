#include "character.h"
#include "raylib.h"
#include "../utils/init/init.h"
#include "../utils/constants.h"
#include <string.h>
Character character;

void inicializeCharacter(char *name, int money)
{
    strcpy(character.name, name);
    character.money = money;
}

void addMoney(int id)
{
    character.money += (BASE_PRICE * pokemons[id].rarity);
}

bool buyItem(int price)
{
    if (character.money >= price)
    {
        character.money -= price;
        return true;
    }

    return false;
}