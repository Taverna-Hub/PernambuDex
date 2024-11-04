#include "character.h"
#include "raylib.h"
#include <string.h>
Character character;

void inicializeCharacter(char *name, int money){
    strcpy(character.name, name);
    character.money = money;
}

void addMoney(int id){
    int price = 0;
    // if (id == 1){ //todo: ira ser a busca pelo id do pokemon (Arvore?)
    //     price = 10;
    // }
    character.money+=price;
}

bool buyItem(int price){

    if (character.money >= price){

        character.money -= price;
        return true;
    }

    return false;
}