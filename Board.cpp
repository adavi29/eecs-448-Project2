/**
@author Zackariah Khazraeinazmpour,Hunter Cobb, Brandon Wheat, Justin Khounsombath, William Burdick
@date September 22, 2019
@file Board.h
@brief Implements Board.h methods
*/
#include "Board.h"
#include <iostream>
using namespace std;

Board::~Board()
  {

  }

Board::Board()
{
  for(int r=0; r<8; r++)
  {
    for(int c=0; c<8; c++)
    {
      mapp[r][c]='|';
    }
  }
}
void Board::setPos(int xPos,int yPos, char val)
  {
    mapp[xPos][yPos] = val;
  }
char Board::getPos(int xPos, int yPos)
  {
    return( mapp[xPos][yPos] );
  }

void Board::printBoard()
{
      cout << "  A B C D E F G H\n";
  for(int r=0; r<8; r++)
  {
      cout <<r+1 <<" ";
    for(int c=0; c<8; c++)
    {
      cout << mapp[r][c] << " ";
    }
    cout << "\n";
  }
}
