#include <iostream>
#include <string>

#include "Labyrinth.h"

bool inventoryComplete(MazeCell* current, bool& spellbook, bool& potion, bool& wand) {
  if(current->whatsHere == Item::SPELLBOOK) {
    spellbook = true;
  }
  if(current->whatsHere == Item::POTION) {
    potion = true;
  }
  if(current->whatsHere == Item::WAND) {
    wand = true;
  }

  if (spellbook && potion && wand) {
    return true;
  }

  return false;
}

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
  int pathLength = moves.length();
  //necessary components
  bool spellbook = false;
  bool potion = false;
  bool wand = false;

  for(int i = 0; i < pathLength; i++) {
    inventoryComplete(start, spellbook, potion, wand);
    if(inventoryComplete(start, spellbook, potion, wand)) {
      return true;
    }

    if(moves[i] == 'N' || moves[i] == 'n') {
      if(start->north == nullptr) { //if a pointer in this direction doesnt exist, break
        return false;
      }
      start = start->north; //go in the direction since we've checked that it exists
      inventoryComplete(start, spellbook, potion, wand);

      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS GO NORTH^^^^^
      */
    } else if(moves[i] == 'S' || moves[i] == 's') {
      if(start->south == nullptr) {
        return false;
      }
      start = start->south;
      inventoryComplete(start, spellbook, potion, wand);

      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS GO SOUTH^^^^^
      */
    } else if(moves[i] == 'E'  || moves[i] == 'e') {
      if(start->east == nullptr) {
        return false;
      }
      start = start->east;
      inventoryComplete(start, spellbook, potion, wand);

      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS GO EAST^^^^^
      */
    } else if(moves[i] == 'W' || moves[i] == 'w') {
      if(start->west == nullptr) {
        return false;
      }
      start = start->west;
      inventoryComplete(start, spellbook, potion, wand);

      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS WEST^^^^^
      */
    }
    inventoryComplete(start, spellbook, potion, wand);
  }

  return inventoryComplete(start, spellbook, potion, wand);
}
