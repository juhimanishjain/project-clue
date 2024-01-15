Cluedo - Murder Mystery Game

Compilation and Execution

To compile the game, use the following command:


bash: gcc adventure.c -o adventure


To run the game, execute the following command:

bash: ./adventure


GAME OVERVIEW

- The game features 9 rooms, including "Kitchen," "Ballroom," "Conservatory," "Dining Hall," "Billiard Room," "Library," "Lounge," "Study," and "Hall."

- Memory allocation using `malloc` ensures the connection of rooms via pointers (refer to adventure.c line 82).

- Room directions are initialized to `null` and reassigned based on the game's logic (adventure.c lines 184-188, 198-215).

- Random initialization of room locations is achieved using the Fisher-Yates method in the rooms.c file (line 16).

- The game includes 6 items and 5 characters stored in pointer arrays (items.c line 4, adventure.c line 191).

- A struct is created to store a random room, character, and item as the answer (rooms.h line 21).

GAME OVERVIEW

- Memory is allocated for items and characters initially, creating linked lists for each room (adventure.c lines 218-228).

- An avatar struct is created to store room and name information (adventure.c line 232).

- The game implements a linked list called "inventory" to store all items taken by the avatar.

- Players can use commands such as help, look, list, clue, go, take, drop, and inventory to navigate and interact with the game.

COMMANDS OVERVIEW

- help: Displays a table of available commands (adventure.c lines 7-17).

- list: Allows players to view lists of items, rooms, and characters (adventure.c lines 21-27).

- look: Provides information about rooms, characters, and items in the current location (adventure.c lines 31-74).

- go: Moves the player in the specified direction (adventure.c lines 279-336).

- take: Adds an item from the room to the player's inventory (adventure.c lines 77-88).

- drop: Removes an item from the player's inventory and places it in the room (adventure.c lines 91-109).

- inventory: Displays the player's current inventory (adventure.c lines 429-432).

- clue: Checks the player's guess against the answer, providing feedback to narrow down options (adventure.c lines 384-458).

Additional Notes

- All commands are case-sensitive, and the game offers an option to retype if an invalid command is entered.
