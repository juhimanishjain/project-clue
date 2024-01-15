#include <stdio.h>

typedef struct Item{
  char *name;
  struct Item *next;
}Item;