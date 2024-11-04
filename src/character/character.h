#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
typedef struct{
    char name[100];
    long money;

}Character;

extern Character character;

void addMoney(int id);
bool buyItem(int price);

void inicializeCharacter(char *name, int money);


#endif