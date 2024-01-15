# include <stdio.h>
# define NUM_CHARACTER 100

typedef struct Room{
      char *name;
      struct Room *North;
      struct Room *South;
      struct Room *East;
      struct Room *West;
      struct Item *itemList; 
      struct Character *characterList;
}Room;

typedef struct Character{
      char *name;
      struct Character *next;
      struct Room *room;
      struct Item *inventory;
}Character;

typedef struct Clue{
      char *room;
      char *name;
      char *item;
}Clue;
