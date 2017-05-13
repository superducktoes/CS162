#include <iostream>

#include "tool.hpp"
#include "rock.hpp"
#include "paper.hpp"
#include "scissors.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
  Tool* playerChoice;
  Tool* computerChoice;
  string status;

  cout << "this is where we'd prompt the user for what they want to choose" << endl;
  playerChoice = new Rock(10);
  computerChoice = new Scissors(10);
  cout << "Strength of player is: " << playerChoice->getStrength() << endl;
  cout << "Strength of computer is: " << computerChoice->getStrength() << endl;

  cout << playerChoice->getName() << " VS " << computerChoice->getName() << endl;

  status = playerChoice->fight(computerChoice);
  if(status == "won") {
    cout << "you win!";
  } else if(status == "loss"){
    cout << "you lose";
  } else if(status == "tie") {
    cout << "tie game";
  }

  return 0;
}
