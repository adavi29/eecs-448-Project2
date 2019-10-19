/**
    @author Zackariah Khazraeinazmpour,Hunter Cobb, Brandon Wheat, Justin Khounsombath, William Burdick
    @date September 22, 2019
    @file Board.h
    @brief Board Class that acts as a data structure to store ship placement.
*/
#ifndef BOARD_H
#define BOARD_H
#include "Ship.h"
#include <iostream>

using namespace std;
class Board
{
public:
/**
   @post Default constructor. Initializes all positions on board to water.
*/
Board();
/**
  @post Default destructor.
*/
~Board();
/**
    @param xPos - x coordinate of the point
    @param yPos - y coordinate of the point
    @param val - value to be inputted.
    @post Set a position on the board.
*/
void setPos(int xPos,int yPos, char val);
/**
    @param xPos - x coordinate of the point
    @param yPos - y coordinate of the point
    @post Set a position on the board.
    @return letter at position provided
*/
char getPos(int xPos, int yPos);
/**
 @post Prints out the Board to the player through console.
*/
void printBoard(); // w = water; s = ship; h = hit; m = miss;

private:
char mapp[8][8];/**2D array of chars that holds the board */
};
#endif
