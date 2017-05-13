/*******************************************************************************
*
* used for testing the attack and defense parts of the program
*
* build using make test_driver and then ./test_driver
*
*******************************************************************************/

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

using std::endl;
using std::cout;
using std::cin;
using std::string;

int main() {

  Creature* testVampire;
  Creature* testBarbarian;
  Creature* testBlueMen;
  Creature* testMedusa;
  Creature* testHarryPotter;

  srand ( time(NULL) );

  int loopStop = 10;
  
  cout << "Testing Vampire: " << endl;
  testVampire = new Vampire("vampire");
  for(int i = 0; i < loopStop; i++) {
    int attack = testVampire->attackRollDie();
    cout << "ATTACK: " << attack << endl;
    int defense = testVampire->defendRollDie(attack);
    cout << "DEFEND: " << defense << endl;
    cout << "ARMOR: 1" << endl;
    cout << "STRENTH: " << testVampire->getCreatureStrength() << endl;
    cout << "------------------" << endl;
  }

  cout << "Testing Barbarian: " << endl;
    testBarbarian = new Barbarian("barbarian");
    for(int i = 0; i < loopStop; i++) {
      int attack = testBarbarian->attackRollDie();
      cout << "ATTACK: " << attack << endl;
      int defense = testBarbarian->defendRollDie(attack);
      cout << "DEFEND: " << defense << endl;
      cout << "NO ARMOR " << endl;
      cout << "STRENTH: " << testBarbarian->getCreatureStrength() << endl;
      cout << "------------------" << endl;
    }
    
    cout << "Testing BlueMen: " << endl;
    testBlueMen = new BlueMen("bluemen");
    for(int i = 0; i < loopStop; i++) {
      int attack = testBlueMen->attackRollDie();
      cout << "ATTACK: " << attack << endl;
      int defense = testBlueMen->defendRollDie(attack);
      cout << "DEFEND: " << defense << endl;
      cout << "ARMOR: 3" << endl;
      cout << "STRENTH: " << testBlueMen->getCreatureStrength() << endl;
      cout << "------------------" << endl;
    }
    
    cout << "Testing Medusa: " << endl;
    testMedusa = new Medusa("medusa");
    for(int i = 0; i < loopStop; i++) {
      int attack = testMedusa->attackRollDie();
      cout << "ATTACK: " << attack << endl;
      int defense = testMedusa->defendRollDie(attack);
      cout << "DEFEND: " << defense << endl;
      cout << "ARMOR: 3" << endl;
      cout << "STRENTH: " << testMedusa->getCreatureStrength() << endl;
      cout << "------------------" << endl;
    }
    
    cout << "Testing HarryPotter: " << endl;
    testHarryPotter = new HarryPotter("harrypotter");
    for(int i = 0; i < loopStop; i++) {
      int attack = testHarryPotter->attackRollDie();
      cout << "ATTACK: " << attack << endl;
      int defense = testHarryPotter->defendRollDie(attack);
      cout << "DEFEND: " << defense << endl;
      cout << "NO ARMOR " << endl;
      cout << "STRENTH: " << testHarryPotter->getCreatureStrength() << endl;
      cout << "------------------" << endl;
    }
    
    return 0;
}
