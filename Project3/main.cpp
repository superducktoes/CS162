/************************************************
 *
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Project 3 contains one creature class and several different
 * creatures that inherit from it. The game is designed to roll the dice for each
 * character and based off of their armor and strength update each character playing
 * appropriately.
 *
 **********************************************/

#include <iostream>
#include <time.h>
#include <cstdlib>

#include "creature.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "harrypotter.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"
#include "menu.hpp"

bool playGame();

using std::endl;
using std::cout;
using std::cin;
using std::string;

int main() {
  srand ( time(NULL) );
  bool game = true;

  do {
    game = playGame();
  } while(game == true);


  return 0;
}

bool playGame() {
  int playerOneCreatureChoice, playerTwoCreatureChoice;
  char playNewGame;
  Creature* playerOneCreature;
  Creature* playerTwoCreature;
  int turnCounter = 1;
  bool carryOn = true;
  bool gameOn = true;
  cout << "Player one, what creature do you want to be? " << endl;
  playerOneCreatureChoice = checkNumberRange("1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Potter\n",1,5);

  if(playerOneCreatureChoice == 1) {
    playerOneCreature = new Vampire("vampire");
  } else if(playerOneCreatureChoice == 2) {
    playerOneCreature = new Barbarian("barbarian");
  } else if(playerOneCreatureChoice == 3) {
    playerOneCreature = new BlueMen("bluemen");
  } else if(playerOneCreatureChoice == 4) {
    playerOneCreature = new Medusa("medusa");
  } else if(playerOneCreatureChoice == 5 ) {
    playerOneCreature = new HarryPotter("harrypotter");
  }

  cout << "Player two, what creature do you want to be? " << endl;
  playerTwoCreatureChoice = checkNumberRange("1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Pottar\n",1,5);


  if(playerTwoCreatureChoice == 1) {
      playerTwoCreature = new Vampire("vampire");
    } else if(playerTwoCreatureChoice == 2) {
      playerTwoCreature = new Barbarian("barbarian");
    } else if(playerTwoCreatureChoice == 3) {
      playerTwoCreature = new BlueMen("bluemen");
    } else if(playerTwoCreatureChoice == 4) {
      playerTwoCreature = new Medusa("medusa");
    } else if(playerTwoCreatureChoice == 5 ) {
      playerTwoCreature = new HarryPotter("harrypotter");
    }

  do {
    cout << "Player 1: " << playerOneCreature->getCreatureName() << " vs "
	 << "Player 2: " << playerTwoCreature->getCreatureName() << endl;
    cout << "Round: " << turnCounter << endl;
    cout << "P1 Strength: " << playerOneCreature->getCreatureStrength()
	 << "  P2 Strength: " << playerTwoCreature->getCreatureStrength() << endl;

    cout << "Player One Press ENTER for your turn" << endl;
    blankEnter();

    int pOneAttack = playerOneCreature->attackRollDie();
    cout << "P1 Attack Roll: " << pOneAttack << endl;
    cout << "P2 Defend Roll: " << playerTwoCreature->defendRollDie(pOneAttack) << endl;

    if(playerOneCreature->getCreatureStrength() <= 0 || playerTwoCreature->getCreatureStrength() <= 0) {
      gameOn = false;
      break;
    }

    cout << "Player Two Press Enter for your turn" << endl;
    blankEnter();

    int pTwoAttack = playerTwoCreature->attackRollDie();
    cout << "P2 Attack Roll: " << pTwoAttack << endl;
    cout << "P1 Defend Roll: " << playerOneCreature->defendRollDie(pTwoAttack) << endl;

    if(playerOneCreature->getCreatureStrength() <= 0 || playerTwoCreature->getCreatureStrength() <= 0) {
      gameOn = false;
      break;
    }

    cout << "\nThe round is over. Press ENTER to continue! " << endl;
    turnCounter++;
    blankEnter();
  } while(gameOn == true);

  if(playerOneCreature->getCreatureStrength() <= 0) {
    cout << "The game is over! Player one has no more strength... Player 2 Wins!" << endl;
    cout << "P1 Strength: " << playerOneCreature->getCreatureStrength()
	 << "  P2 Strength: " << playerTwoCreature->getCreatureStrength() << endl;
  } else if(playerTwoCreature->getCreatureStrength() <= 0) {
    cout << "The game is over! Player two has no more strength... Player 1 Wins!" << endl;
    cout << "P1 Strength: " << playerOneCreature->getCreatureStrength()
	 << "  P2 Strength: " << playerTwoCreature->getCreatureStrength() << endl;
  }
  cin.clear();
  // checks with the player to see if they want to keep playing after one creature is dead.
  if(playerOneCreature->getCreatureStrength() <= 0 || playerTwoCreature->getCreatureStrength() <= 0) {
    playNewGame = checkCharacter("Do you want to play another round? (Y or N)", 'Y','N');
    // if the user enters y its true, n is false
    carryOn = playNewGame;
  }

  return carryOn;
}
