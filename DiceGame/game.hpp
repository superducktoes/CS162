/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: Game class creates two dice and is instantiated using the
  * number of turns, sides on the dice, and whether or not they are loaded
  * dice.
  *
  *****************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "dice.hpp"
class Game {
  private:
  int playerOneScore, playerTwoScore; // score for each player
  int turns; // used for tracking how many turns have been played
  int dieOneSides, dieTwoSides; // used for the number of sides on each die
  char playerOneLoaded, playerTwoLoaded;

public:
  // default constructor. takes five arguments relating to the game.
  Game(int t, int dOne, int dTwo, char pOneLoaded, char pTwoLoaded)
  : turns(t), dieOneSides(dOne), dieTwoSides(dTwo), playerOneLoaded(pOneLoaded), playerTwoLoaded(pTwoLoaded)
  {
    playerOneScore = 0;
    playerTwoScore = 0;
  }

  void startGame();

};
#endif
