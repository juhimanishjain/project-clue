#include <stdio.h>
#include <stdlib.h>
#include "rooms.h"
#include "items.c"
#include "items.h"
#include <time.h>
#define ROOM_NUMBER 9
#define CHARACTER_NAMES 9

int i,random_number, count=10;
int flag=1;
char *rooms_names[ROOM_NUMBER]={"Kitchen", "Ballroom", "Conservatory", "Dining Hall", "Billiard Room", "Library", "Lounge", "Study", "Hall"};
char *character_name;

/*This method generates random number using srand and rand functions.
Swaps the room at i index and the room at the random number index from the rooms_names array
*/
void fisher_yates(char **rooms_names){
  char *swap;
  srand(time(NULL));
  for(i=8; i>0; i--){
    random_number=rand()%(i+1);
    swap=rooms_names[i];
    rooms_names[i]=rooms_names[random_number];
    rooms_names[random_number]=swap;
  }
}

int compare(char one[],char two[])  
{
  i=0;  
  while(one[i]!='\0' && two[i]!='\0')  
  {  
    if(one[i]!=two[i])  
    {  
      return 1;  
    }  
    i++;  
  }
  return 0;
}  