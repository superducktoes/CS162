/***************************************************
 *
 * Author: Nick Roy
 * Date: 4/6/2017
 * Description: Header file for the menu class.
 * Functions take strings to display and handles 
 * input validation.
 *
 **************************************************/

#ifndef MENU_HPP
#define MENU_HPP
using std::string;

int generateRandom(int);
int checkNumber(string);
int checkNumberRange(string,int,int);
bool checkCharacter(string,char,char);
void blankEnter();
void showMenu(int);
#endif
