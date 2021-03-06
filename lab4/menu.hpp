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
double checkNumberRange(string,double,double);
char checkCharacter(string,char,char);
void blankEnter();
void showMenu(int);
char menuPlayOn();
#endif
