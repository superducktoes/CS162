#include <iostream>

#include "tool.hpp"
#include "rock.hpp"
#include "paper.hpp"
#include "scissors.hpp"

void playGame()

Tool* playerChoice;
Tool* computerChoice;


using std::cout;
using std::cin;
using std::endl;

int main()
{

    int select;
    rpsGame g1;
    bool progRun = true;

    while (progRun != false)
    {
        cout << "Rock Paper Scissors" << endl;
        cout << "*******************************\n";
        cout << "Select a number from the below options then press enter." << endl << endl;
        cout << "1 -- Play Game" << endl;
        cout << "2 -- Play Again" << endl;
        cout << "3 -- Quit" << endl;
        cin >> select;

        switch (select)
        {
        case 1:
            g1.playGame();
            break;
        case 2:
            g1.playGame();
            break;
        case 3:
            cout << "End the program." << endl << endl;
            break;
        default:
            if (cin.fail())
            {
            cin.clear();
            cin.ignore();
            cout << "Not a valid choice."  << endl;
            cout << "Choose again." << endl;
            cin >> select;
            }
            break;
        }

        if (select == 8)
        {
            progRun = false;
        }
    }
}


void playGame()
{
  char choice;

  cout << "Choose a tool for the user: " << endl;
  cout << "Rock: Enter r." << endl;
  cout << "Paper: Enter p." << endl;
  cout << "scissors: Enter s." << endl;
  cin >> choice;

  if (choice == 'r' || 'R')
  {
      playerChoice = new Rock(10);
  }
  else if (choice == 'p' || 'P')
  {
      playerChoice = new Paper(10);
  }
  else if (choice == 's' || 'S')
  {
      playerChoice = new Scissors(10);
  }
  else
  {
      cout << "The value you entered is not valid" << endl;
  }

 int rand = rpsRand();

  if (rand == 1)
  {
      computerChoice = new Rock(10);
  }
  else if (rand == 2)
  {
      computerChoice = new Paper(10);
  }
  else if (rand == 3)
  {
      computerChoice = new Scissors(10);
  }
  else
  {
      cout << "The value you entered is not valid" << endl;
  }


  cout << "Strength of player is: " << playerChoice->getStrength() << endl;
  cout << "Strength of computer is: " << computerChoice->getStrength() << endl;

  cout << playerChoice->getName() << " VS " << computerChoice->getName() << endl;

  status = playerChoice->fight(computerChoice);

  trackscore(status);

  cout <<  endl << human_wins << endl;
  cout << computer_wins << endl;
  cout << ties << endl;
}
