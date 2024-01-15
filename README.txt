(1) The game must be compiled using the gcc command and the file being compiled is adventure.c as it contains the main method. 
    • The compilation line would be  gcc adventure.c -o adventure

    • For running the game we use ./adventure command

(2) The game has 9 rooms in an array room_names namely as "Kitchen", "Ballroom", "Conservatory", "Dining Hall", "Billiard Room", 
   "Library", "Lounge", "Study", "Hall".
    • Allocated memory using malloc for each room and  connected the rooms using the pointers. (adventur.c line 82)

    • We initialized all the direction pointers to null. (adventure.c line185-188)

    • Then reassigned the directions which are not null. (adventure.c line 184-188,line198-215)

    • The game randomly initializes the location of each room using the method fisher yates in rooms.c file(line 16)

    • In this function fisher yates we use srand and rand to generate random number and swap the rooms each time new game 
      starts. (rooms.c line 20-24)
    • The game contains 6 items stord in an pionter array *items ={"candlestick", "dagger", "lead pipe", "revolver", "rope", "wrench", 
      "poison", "sword", "pillow"}. ( items.c line 4)

    • The game contains 5 characters other than the player's avatar stored in an pointer array as 
      *character_list = {"Miss Scarlet", "Colonel Mustard", "Mrs. White", "The Reverend Green", "Mrs. Peacock", "Prof. Plum",
                       "Mr. Park", "Diya", "Charles"} (adventure.c line 191)

    • Creating a struct to store a random room,character and an item as the answer.(rooms.h line21)

    • Allocating memory for each item entered initially to create a itemlist for each room(adventure.c line 218-221)

    • Allocating memory for each character entered initially to create a characterlist for each room(adventure.c line 225-228)

    • So we have made the linkedlist of items and linkedlist of character for each room.

    • Allocating memeory for avatar to store room,name.(adventure.c line 232)

    • Creating a linkedlist called inventory for the avatar to store all the items that are taken.

    • Displaying a table with different commands such as help, look, list, clue, go, take, drop, inventory at the start of 
    the game and asking the player to enter a command. (adventur.c line 8-17)
    
    • help command shows the player a table of all the commands available.(adventure.c lines 7-17)

    • list command allows the player to see the lists of items,rooms and characters,(adventure.c lines 21-27)

    • look command allows the player to see the rooms in each direction, the characters in the current room and the items in the 
    current room.

    Implementation of the "look" command :- 
    (i) We check all the directions if it is not null to check the rooms in each directions and 
    then print the rooms next to the current room.(adventure.c lines 31-45)
    (ii) Checking the itemlist and characterlist of that room to see the characters and items in the room 
    and print them.(adventure.c line 50-74)

    Implementation of the "go" command :-
    (i) The 'go' command asks the direction the player wants to move and then moves in that direction if it possible or 
    prints that it is not possible and asks to retype.(adventure.c lines 279-336)

    Implementation of the "take" command :-
    (i) The 'take' command implements a method add_item_to_list where we add the item in the room to the 
    list of inventory.(adventure.c line 77-88)

    Implementation of the "drop" command :-
    (i) The 'drop' command implements the method drop_item_from_list  where we take the item from the inventory linkedlist 
    and add in the itemlist of the room.(adventure.c line 91-109)

    Implementation of the "inventory" command :-
    (i) The 'inventory' command displays the list of items the inventory linkedlist.(adventure.c line 429-432)

    Implementation of the "clue" command :-
    (i) The 'clue' command is the command used to check each guess of the player with answer and decide the winning and losing 
    state. (adventure.c line 384-458)
    (ii) The 'clue' command has a counter set up at 10 and each time the chance is used and wrong the counter decreases.
    (iii) When the counter reaches 0 ,all the chances are done and we show the player that they lost the game.
    (iv) The clue command checks the room,item and character individually and prints the the matches each time 
    which helps in narrowing the options.
    (v) When the player makes a correct guess the player wins the game.

(3) All the commands are case sensitive and the game gives an option to retype if the command is invalid.