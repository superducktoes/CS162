#include <iostream>
#include <time.h>
#include <cstdlib>

#include "gameplay.hpp"
#include "monstersqueue.hpp"
#include "monsterstack.hpp"
#include "creature.hpp"
#include "menu.hpp"

#include "barbarian.hpp"
#include "vampire.hpp"
#include "harrypotter.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void Gameplay::playGame() {
  int monstersPerTeam;
  int counter = 0;
  int playerOneCreatureChoice, playerTwoCreatureChoice;
  MonstersQueue playerOneQueue, playerTwoQueue;
  srand ( time(NULL) );
  playerOneScore = 0;
  playerTwoScore = 0;
  cout << "Let's start the monster battle tournament. " << endl;
  monstersPerTeam = checkNumber("How many monsters should be on each team? ");

  cout << "Now let's set player one's monster lineup! " << endl;

  // find out why it segfaults when creating a new creature at the loop limit
  while(counter < monstersPerTeam) {

    cout << "1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Potter\n" << endl;
    cin >> playerOneCreatureChoice;

    if(playerOneCreatureChoice == 1) {
      playerOneQueue.addToQueue(new Vampire("vampire","player one"));
    } else if(playerOneCreatureChoice == 2) {
      playerOneQueue.addToQueue(new Barbarian("barbarian","player one"));
    } else if(playerOneCreatureChoice == 3) {
      playerOneQueue.addToQueue(new BlueMen("bluemen","player one"));
    } else if(playerOneCreatureChoice == 4) {
      playerOneQueue.addToQueue(new Medusa("medusa","player one"));
    } else if(playerOneCreatureChoice == 5 ) {
      playerOneQueue.addToQueue(new HarryPotter("harrypotter","player one"));
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
      playerTwoQueue.addToQueue(new Vampire("vampire","player two"));
    } else if(playerTwoCreatureChoice == 2) {
      playerTwoQueue.addToQueue(new Barbarian("barbarian","player two"));
    } else if(playerTwoCreatureChoice == 3) {
      playerTwoQueue.addToQueue(new BlueMen("bluemen","player two"));
    } else if(playerTwoCreatureChoice == 4) {
      playerTwoQueue.addToQueue(new Medusa("medusa","player two"));
    } else if(playerTwoCreatureChoice == 5 ) {
      playerTwoQueue.addToQueue(new HarryPotter("harrypotter","player two"));
    }

    counter++;
  }

  // reset the counter again for the game
  counter = 0;

  // segfaults for some reason after showing the monsters
  do {
    Creature* playerOneBattle = playerOneQueue.getFront();
    Creature* playerTwoBattle = playerTwoQueue.getFront();

    cout << "Player 1: " << playerOneBattle->getCreatureName() << " vs Player 2: " << playerTwoBattle->getCreatureName() << endl;
    cout << "Round: " << (counter + 1) << endl;
    cout << "\n\n";

    //this is an abbreviated game play for right now
    cout << "player one is attacking player two " << endl;
    int pOneAttack = playerOneBattle->attackRollDie();
    playerTwoBattle->defendRollDie(pOneAttack);
    cout << "player two is attacking player one " << endl;
    int pTwoAttack = playerTwoBattle->attackRollDie();
    playerOneBattle->defendRollDie(pTwoAttack);
    cout << "\n\n";

    // depending on who wins we can add the losers to the loser stack
    if(playerOneBattle->getCreatureStrength() > playerTwoBattle->getCreatureStrength()) {
      cout << "\nPlayer One Wins!" << endl;
      playerOneScore = playerOneScore + 2;
      loserStack.addToStack(playerTwoBattle);
      cout << "\nPlayer two's monster added to the loser stack" << endl;
    } else if(playerOneBattle->getCreatureStrength() < playerTwoBattle->getCreatureStrength()) {
      cout << "\nPlayer Two Wins! " << endl;
      playerTwoScore = playerTwoScore + 2;
      loserStack.addToStack(playerOneBattle);
      cout << "\nPlayer one's monster added to the loser stack" << endl;
    } else if(playerOneBattle->getCreatureStrength() == playerTwoBattle->getCreatureStrength()) {
      cout << "\nThe round is a tie! Both monsters are added to the losers pile. "<< endl;
      loserStack.addToStack(playerOneBattle);
      loserStack.addToStack(playerTwoBattle);
      playerOneScore++;
      playerTwoScore++;
    }

    counter++;
  } while(counter < monstersPerTeam);
}

void Gameplay::compareScore() {
  if(playerOneScore > playerTwoScore) {
    cout << "Player One wins the tournament! " << endl;
  } else if(playerTwoScore > playerOneScore) {
    cout << "Player Two wins the tournament! " << endl;
  } else {
    cout << "The tournament ended in a tie. I'd suggest playing again. " << endl;
  }
}

void Gameplay::showLosingMonsters() {
  bool keepLooping = true;

  do {
    Creature *tempNode = loserStack.removeFromStack();
    if(tempNode != NULL) {
      cout << tempNode->getCreatureName() << " -- " << tempNode->getCreaturePlayer() << endl;
    } else {
      keepLooping = false;
    }
  } while(keepLooping == true);
}
