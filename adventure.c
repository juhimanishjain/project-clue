#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rooms.c" 

// list of all the commands
void help(){
printf("------------------------------------------------------------------------------------------------\n");     
printf("| help      : shows a list of all the commands that'll help in mazing through the game         |\n");
printf("| list      : shows a list of items, rooms, and characters present in the game                 |\n");
printf("| look      : shows the current room, and items and characters present in that room            |\n");
printf("| go        : helps in moving through the maze                                                 |\n");
printf("| take      : helps in adding items to your pack of inventory                                  |\n");
printf("| drop      : helps in removing an item from the inventory                                     |\n");
printf("| inventory : helps in removing an item from the inventory                                     |\n");
printf("| clue      : provides with a clue to help solve the game                                      |\n");
printf("------------------------------------------------------------------------------------------------\n"); 
}

// list of items, rooms and characters
void list(){
  printf("----------------------------------------------------------------------------------------------------------\n");     
  printf("| Rooms      : Kitchen, Ballroom, Conservatory, Dining room, Billiard Room, Library, Lounge, Hall, Study |\n");
  printf("| Characters : Miss Scarlet, Colonel Mustard, Mrs. White, The Reverend Green, Mrs. Peacock, Prof. Plum   |\n");
  printf("| Items      : candlestick, dagger, lead pipe, revolver, rope, wrench, poison, sword, pillow             |\n");
  printf("----------------------------------------------------------------------------------------------------------\n"); 
}

/*look function checks with all directions and checks the itemlist and characterlist for the room and
   print the current room,items in the room,character in the room and the rooms in all directions.*/
void look(struct Room *room){
  if(room != NULL){
    printf("Room: %s\n",room->name);
    printf("\n");
    printf("Take a look of the setting around %s.\n", room->name);
    if(room->North != NULL){
      printf("North: %s\n", room->North->name);
    }
    if(room->South != NULL){
      printf("South: %s\n", room->South->name);
    }
    if(room->East != NULL){
      printf("East: %s\n", room->East->name);
    }
    if(room->West != NULL){
      printf("West: %s\n", room->West->name);
    }
  }
  printf("\n");

//Checking the items in the itemlist of the room
  Item *currentItem=room->itemList;
  if(currentItem==NULL){
    printf("No item/s are present in this room\n");
  }
  else{
    printf("Item/s in this room include:\n");
    while(currentItem!=NULL){
      printf("%s\n", currentItem->name);
      currentItem=currentItem->next;
    }
  }
  printf("\n");
  //Checking the character in the characterlist of the room
  Character *currentCharacter=room->characterList;
  if(currentCharacter==NULL){
    printf("No characters are present in this room\n");
  }
  else{
    printf("Characters in this room include:\n");
    while(currentCharacter!=NULL){
      printf("%s\n", currentCharacter->name);
      currentCharacter=currentCharacter->next;
    }
  }
}

// adding items to a linked list
/*Tranversing through the list and adding the current item to the list
*/
void add_item_to_list(struct Item **itemList, struct Item *item){
  Item *current_item=*itemList;
  if(current_item == NULL){
    item->next=NULL;
    *itemList=item;
    return;
  }
  while(current_item->next != NULL){
    current_item=current_item->next;
  }
  current_item->next=item;
}

// removing item from a linked list
/*Tranversing through the list till the name of the item matches with name 
and then remove the item from list.
*/
Item* remove_item_from_list(struct Item **itemList, char* itemName){
  Item *previous_item = NULL;
  Item *current_item=*itemList;
  while(current_item != NULL){
    char* name=current_item->name;
    if(compare(name, itemName) == 0){
      if(previous_item == NULL){
        *itemList=current_item->next;
      }
      else{
        previous_item->next=current_item->next;
      }
      current_item->next=NULL;
      //  printf("safe %s", current_item->name);
      return current_item;
    }
    previous_item=current_item;
    current_item=current_item->next;
  }
  return NULL; //if item doesn't exists ask the user name of another item
}

// add character to the linked list
/*Tranversing through the list and adding the current character to the list
*/
void add_character_to_list(struct Character **characterList, struct Character *character){
  Character *current_character=*characterList;
  if(current_character == NULL){
    *characterList=character;
    return;
  }
  while(current_character->next != NULL){
    current_character=current_character->next;
  }
  current_character->next=character;
}

// remove character from the linked list
/*Tranversing through the list till the name of the character matches with name 
and then remove the character from list.
*/
Character* remove_character_from_list(struct Character **characterList, char* characterName){
  Character *previous_character = NULL;
  Character *current_character=*characterList;
  while(current_character != NULL){
    char* name = current_character->name;
    if(strcmp(name, characterName) == 0){
      if(previous_character == NULL){
        *characterList=current_character->next;
      }
      else{
        previous_character->next=current_character->next;
      }
      current_character->next=NULL;
      return current_character;
    }
    previous_character=current_character;
    current_character=current_character->next;
  }
  return NULL; 
}

// for finding the avatar's location
Room* find_character_by_name(char* characterName, Room* rooms[]){
  for(int i=0; i<ROOM_NUMBER; i++){
    Character* character_list=rooms[i]->characterList;
    if(character_list!=NULL){
      while(character_list!=NULL){
        if(strcmp(character_list->name, characterName)==0){
          return rooms[i];
        }
        character_list=character_list->next;
      }
    }
  }
  return NULL;
}

void main(){

  // Allocating memory for each room and initializing all direction pointers as null.
  Room **r=NULL;
  r=(Room **) malloc(ROOM_NUMBER * sizeof(Room *));
  for (i=0; i<ROOM_NUMBER; i++){
    r[i]=(Room *) malloc(sizeof(Room));
    r[i]->North=NULL;
    r[i]->South=NULL;
    r[i]->East=NULL;
    r[i]->West=NULL;
  }

  char *character_list[CHARACTER_NAMES] = {"Miss Scarlet", "Colonel Mustard", "Mrs. White", "The Reverend Green", "Mrs. Peacock", "Prof. Plum", "Mr. Park", "Charles", "Diya"};

  fisher_yates(rooms_names);
  for(i=0;i<ROOM_NUMBER;i++){
    r[i]->name=rooms_names[i];
  }
// Connecting rooms via pointers (in all directions except those directions which are NULL)
  r[0]->South=r[3];
  r[0]->East=r[1];
  r[1]->South=r[4];
  r[1]->East=r[2];
  r[1]->West=r[0];
  r[2]->South=r[5];
  r[2]->West=r[1];
  r[3]->North=r[0];
  r[3]->South=r[6];
  r[3]->East=r[4];
  r[4]->North=r[1];
  r[4]->West=r[3];
  r[4]->South=r[7];
  r[4]->East=r[5];
  r[5]->South=r[8];
  r[5]->North=r[2];
  r[5]->West=r[4];
  r[6]->North=r[3];
  r[6]->East=r[7];
  r[7]->North=r[4];
  r[7]->East=r[8];
  r[7]->West=r[6];
  r[8]->North=r[5];
  r[8]->West=r[7];

  fisher_yates(items);
  for(int i=0; i<ITEMS_NUMBER; i++){
    //Allocating memory for linkedlist of items for each room
    Item* item=malloc(sizeof(Item));
    item->name=items[i]; //Assigning names for the items
    item->next=NULL;
    r[i]->itemList=item; 
  }

  fisher_yates(character_list);
  for(int i=0; i<CHARACTER_NAMES; i++){
    //Allocating memory for linkedlist of character for each room
    Character* character=malloc(sizeof(Character));
    character->name=character_list[i];  //Assigning names for the characters
    character->next=NULL;  
    r[i]->characterList=character; 
  }

  // Allocating memory for avatar and assigning name,room
  Character* avatar=malloc(sizeof(Character));
  avatar->name="You";
  avatar->next=NULL;
  avatar->room=r[0];

  //adding the avatar to the characterlist of the room 
  add_character_to_list(&(r[0]->characterList), avatar);

  // Allocating memory for the answer
  Clue* murder=malloc(sizeof(Clue));
  murder->room = r[8]->name;
  murder->name = character_list[5];
  murder->item = items[3];

  char *buffer;
  char *buffer2;
  size_t buffsize=100;
  Room *current_room=r[0];

  // initial introduction lines
  printf("\n");
  printf("Welcome to the online implementation of the interactive fiction game Clue.\n");
  printf("Clue is an adventure game published during the year 1943.\n");
  printf("\n");
  printf("To get to know about the available commands in this game type help !\n");
  while(1){
    printf("\n");
    printf("Enter a command: ");
    getline(&buffer, &buffsize, stdin);

    // help command
    if(strcmp(buffer, "help\n")==0){
      help();
    }

    // list command
    if(strcmp(buffer, "list\n")==0){
      list();
    }

    // finds the room the avatar is in and dives into the look function 
    if(strcmp(buffer, "look\n")==0){
      Room* current_room = find_character_by_name("You", r);
      look(current_room);
    }

    /* Asks the user the direction they want to move to and checks if there is a possibility to move in 
    that direction. If yes, the user is moved to that particular direction inputted.*/
    if(strcmp(buffer, "go\n")==0){
      flag=1;
      printf("Enter the direction: ");
      getline(&buffer, &buffsize, stdin);
      Room* current_room = find_character_by_name("You", r);
      if(compare("North", buffer)==0 || compare("north", buffer)==0){
        if(current_room->North == NULL){
          printf("You can't move North.\n");
          flag=0;
        }
        if(flag==1){
          Character* change_avatar_direction = remove_character_from_list(&(current_room->characterList), "You");
          avatar->room=current_room->North;
          add_character_to_list(&(avatar->room->characterList), change_avatar_direction);
          printf("You have moved to North.\n");
        }
      }

      else if(compare("South", buffer)==0 || compare("south", buffer)==0){
        if(current_room->South == NULL){
          printf("You can't move South.\n");
          flag=0;
        }
        if(flag==1){
          Character* change_avatar_direction = remove_character_from_list(&(current_room->characterList), "You");
          avatar->room=current_room->South;
          add_character_to_list(&(avatar->room->characterList), change_avatar_direction);
          printf("You have moved to South.\n");
        }
      }

      else if(compare("East", buffer)==0 || compare("east", buffer)==0){
        if(current_room->East == NULL){
          printf("You can't move East.\n");
          flag=0;
        }
        if(flag==1){
          Character* change_avatar_direction = remove_character_from_list(&(current_room->characterList), "You");
          avatar->room=current_room->East;
          add_character_to_list(&(avatar->room->characterList), change_avatar_direction);
          printf("You have moved to East.\n");
        }
      }

      else if(compare("West", buffer)==0 || compare("west", buffer)==0){
        if(current_room->West == NULL){
          printf("You can't move West.\n");
          flag=0;
        }
        if(flag==1){
          Character* change_avatar_direction = remove_character_from_list(&(current_room->characterList), "You");
          avatar->room=current_room->West;
          add_character_to_list(&(avatar->room->characterList), change_avatar_direction);
          printf("You have moved to West.\n");
        }
      }
    }

    /* finds the room the character is in and dives into the function remove_item_from_list in which
       the item is being removed from the linkedlist of item of the room and then add it to list of 
       inventory.
     */ 
    if(strcmp(buffer, "take\n")==0){
      printf("Enter the item to be added to your inventory: ");
      getline(&buffer, &buffsize, stdin);
      Room* current_room = find_character_by_name("You", r);
      Item* item_name = remove_item_from_list(&(current_room->itemList), buffer);
      if(item_name == NULL){
        printf("No such item found. Please retype !\n");
      }
      else if(item_name!=NULL){
        add_item_to_list(&(avatar->inventory), item_name);
        printf("Item added to your inventory.\n");
      } 
    }

    /* finds the room the character is in and dives into the function remove_item_from_list in which
       the item is being removed from the linkedlist of item of the room
     */ 
    if(strcmp(buffer, "drop\n")==0){
      printf("Enter the item to be dropped from your inventory: ");
      getline(&buffer, &buffsize, stdin);
      printf("You typed: %s\n", buffer);
      Item* item_name = remove_item_from_list(&(avatar->inventory), buffer);
      if(item_name==NULL){
        printf("No such item found. Please retype !\n");
      }
      else if(item_name!=NULL){
        Room* current_room = find_character_by_name("You", r);
        add_item_to_list(&(current_room->itemList), item_name);
        printf("Item has been dropped from your inventory.\n");
      }
    }

    /* traversing through the linkedlist of items of the inventory and printing them out. */
    if(strcmp(buffer, "inventory\n")==0){
      Item* itemList = avatar->inventory;
      if(itemList != NULL){
        while (itemList!=NULL)
        {
          printf("%s\n", itemList->name);
          itemList=itemList->next;
        }
      }
      else{
        printf("The inventory is empty.\n");
      }
    }

    /* Compares the user inputted character, item, and the room wherein the player is with the clue
       struct. If it matches the clue, the user wins the game. Otherwise, one chance is deductted each
       item, the user inputs don't match the clue.
    */
    if(strcmp(buffer, "clue\n")==0){
      int character_flag=1;
      int item_flag=1;
      printf("Enter the name of the character: ");
      getline(&buffer, &buffsize, stdin);
      printf("Enter the name of the item: ");
      getline(&buffer2, &buffsize, stdin);
      Room *current_room = find_character_by_name("You", r);
      Room *murderer_room = find_character_by_name(murder->name, r);
      Character *murderer = remove_character_from_list(&(murderer_room->characterList), murder->name);
      char *name=murder->name;
      char *item=murder->item;
      char *room=murder->room;
      add_character_to_list(&(current_room->characterList), murderer);

      if(compare(buffer, name)==0){
        character_flag=0;
        printf("Character match.\n");
      }

      else if(compare(buffer, name)!=0){
        printf("Character didn't match.\n");
      }

      if(compare(buffer2, item)==0){
        Item *item_list=current_room->itemList;
        Item *inventory=avatar->inventory;

        // to check the items present in the room
        while (item_list!=NULL)
        {
          if(compare(item_list->name, item)==0){
            printf("Item matched.\n");
            item_flag=0;
          }
          item_list=item_list->next;
        }

        // to check the inventory present with the avatar
        while (inventory!=NULL)
        {
          if(compare(inventory->name, item)==0){
            printf("Item matched.\n");
            item_flag=0;
          }
          inventory=inventory->next;
        }
      }

      else if(compare(buffer2, name)!=0){
        printf("Item didn't match.\n");
      }

      if((compare(room, current_room->name)!=0) || character_flag==1 || item_flag==1){
        count=count-1;
        printf("Room didn't match.\n");
        printf("Wrong Guess.\n");
        printf("%d chances left.\n", count);
      }

      if((compare(room, current_room->name)==0) && character_flag==0 && item_flag==0){
        printf("You have won the game.\n");
        break;
      }
    }

    if(count==0){
        printf("You have lost the game.\n");
        break;
    }
  }
}