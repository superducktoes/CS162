#include <iostream>
#include <time.h>
#include <cstdlib>

#include "monstersqueue.hpp"
#include "monsterstack.hpp"
#include "creature.hpp"
#include "menu.hpp"

#include "creature.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "harrypotter.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"

using std::cout;
using std::cin;
using std::endl;

void playerOneChoice(int);

int main() {
  srand ( time(NULL) );

  int monstersPerTeam;
  int playerOneScore = 0;
  int playerTwoScore = 0;
  int counter = 0;
  int playerOneCreatureChoice, playerTwoCreatureChoice;

  MonstersQueue playerOneQueue, playerTwoQueue;
  MonsterStack playerOneStack, playerTwoStack;

  cout << "Let's start the monster battle tournament. " << endl;
  monstersPerTeam = checkNumber("How many monsters should be on each team? ");

  cout << "Now let's set player one's monster lineup! " << endl;

  // find out why it segfaults when creating a new creature at the loop limit
  while(counter < monstersPerTeam) {

    cout << "1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Potter\n" << endl;
    cin >> playerOneCreatureChoice;

    if(playerOneCreatureChoice == 1) {
      playerOneQueue.addToQueue(new Vampire("vampire"));
    } else if(playerOneCreatureChoice == 2) {
      playerOneQueue.addToQueue(new Barbarian("barbarian"));
    } else if(playerOneCreatureChoice == 3) {
      playerOneQueue.addToQueue(new BlueMen("bluemen"));
    } else if(playerOneCreatureChoice == 4) {
      playerOneQueue.addToQueue(new Medusa("medusa"));
    } else if(playerOneCreatureChoice == 5 ) {
      playerOneQueue.addToQueue(new HarryPotter("harrypotter"));
    }

    counter++;
  }
  // reset for player two's loop
  counter = 0;
  cout << "Player Two pick your monsters: " << endl;
  while(counter < monstersPerTeam) {

    cout << "1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Potter\n" << endl;
    cin >> playerTwoCreatureChoice;

    if(playerTwoCreatureChoice == 1) {
      playerTwoQueue.addToQueue(new Vampire("vampire"));
    } else if(playerTwoCreatureChoice == 2) {
      playerTwoQueue.addToQueue(new Barbarian("barbarian"));
    } else if(playerTwoCreatureChoice == 3) {
      playerTwoQueue.addToQueue(new BlueMen("bluemen"));
    } else if(playerTwoCreatureChoice == 4) {
      playerTwoQueue.addToQueue(new Medusa("medusa"));
    } else if(playerTwoCreatureChoice == 5 ) {
      playerTwoQueue.addToQueue(new HarryPotter("harrypotter"));
    }

    counter++;
  }

  // reset the counter again for the game
  counter = 0;

  // segfaults for some reason after showing the monsters
  do {
    Creature* playerOneBattle = playerOneQueue.getFront();
    cout << playerOneBattle->getCreatureName() << endl;
    Creature* playerTwoBattle = playerTwoQueue.getFront();
    cout << playerTwoBattle->getCreatureName() << endl;

    //this is an abbreviated game play for right now
    cout << "player one is attacking player two " << endl;
    int pOneAttack = playerOneBattle->attackRollDie();
    playerTwoBattle->defendRollDie(pOneAttack);

    int pTwoAttack = playerTwoBattle->attackRollDie();
    playerOneBattle->defendRollDie(pTwoAttack);


    // depending on who wins we can add the losers to the loser stack
    if(playerOneBattle->getCreatureStrength() > playerTwoBattle->getCreatureStrength()) {
      cout << "player one wins";
      playerTwoStack.addToStack(playerTwoBattle);
      cout << "player two's monster added to the loser stack" << endl;
    } else if(playerOneBattle->getCreatureStrength() < playerTwoBattle->getCreatureStrength()) {
      cout << "player two wins";
      playerOneStack.addToStack(playerOneBattle);
      cout << "player one's monster added to the loser stack";
    } else if(playerOneBattle->getCreatureStrength() == playerTwoBattle->getCreatureStrength()) {
      cout << "the game is a tie. both players are gone";
      playerOneStack.addToStack(playerOneBattle);
      playerTwoStack.addToStack(playerTwoBattle);
    }

    counter++;
  } while(counter < monstersPerTeam);
  return 0;
}
