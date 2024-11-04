#include <stdio.h>
#include "constants.h"
#include "raylib.h"
#include "init/init.h"

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
