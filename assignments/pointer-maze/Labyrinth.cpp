#include <iostream>
#include <string>

#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
  int pathLength = moves.length();
  //necessary components
  bool spellbook = false;
  bool potion = false;
  bool wand = false;

  for(int i = 0; i < pathLength; i++) {
    if(moves[i] == 'N' || moves[i] == 'n') {
      if(start->north == nullptr) { //if a pointer in this direction doesnt exist, break
        return false;
      }
      start = start->north; //go in the direction since we've checked that it exists

      //check if it has any of the special items we need
      if(start->whatsHere == Item::SPELLBOOK) {
        spellbook = true;
      }
      if(start->whatsHere == Item::POTION) {
        potion = true;
      }
      if(start->whatsHere == Item::WAND) {
        wand = true;
      }
      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS GO NORTH^^^^^
      */
    } else if(moves[i] == 'S' || moves[i] == 's') {
      if(start->south == nullptr) {
        return false;
      }
      start = start->south;

      //check if it has any of the special items we need
      if(start->whatsHere == Item::SPELLBOOK) {
        spellbook = true;
      }
      if(start->whatsHere == Item::POTION) {
        potion = true;
      }
      if(start->whatsHere == Item::WAND) {
        wand = true;
      }

      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS GO SOUTH^^^^^
      */
    } else if(moves[i] == 'E'  || moves[i] == 'e') {
      if(start->east == nullptr) {
        return false;
      }
      start = start->east;

      //check if it has any of the special items we need
      if(start->whatsHere == Item::SPELLBOOK) {
        spellbook = true;
      }
      if(start->whatsHere == Item::POTION) {
        potion = true;
      }
      if(start->whatsHere == Item::WAND) {
        wand = true;
      }
      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS GO EAST^^^^^
      */
    } else if(moves[i] == 'W' || moves[i] == 'w') {
      if(start->west == nullptr) {
        return false;
      }
      start = start->west;

      //check if it has any of the special items we need
      if(start->whatsHere == Item::SPELLBOOK) {
        spellbook = true;
      }
      if(start->whatsHere == Item::POTION) {
        potion = true;
      }
      if(start->whatsHere == Item::WAND) {
        wand = true;
      }
      /*
      im lazy and my code sucks so theres a gap
      ^^^^^ABOVE IS IF THE STRING SAYS WEST^^^^^
      */
    }

    if (spellbook && potion && wand) {
      return true;
    }
  }

  return false;
}
