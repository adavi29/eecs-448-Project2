/**
    @author William Burdick,Hunter Cobb, Brandon Wheat, Zackariah Khazraeinazmpour, Justin Khounsombath
    @date September 22, 2019
    @file Ship.h
    @brief Ship class that handles all cases of ships being shot. Is used by player to store ship information as a type of data structure.
*/
#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;
class Ship
{
public:
  /**
   @brief Contsructor that takes in the size of the ship to store.marks sunk as false and hits at 0.
   */
  Ship(int ShipSize);
  /**
   @brief Default constructor.
   */
  Ship();

  ~Ship();
  /**
   @param val - size to make the ship.
   @post sets the size of the ship to be created.
   */
  void setSize(int val);
  /**
      @return the size of the ship.
   */
  int getSize();
  /**
   @param vh - char to determine whether the ship will be vertical('v') or horizontal('h')
   @post Set a position on the board.
  */
  void setOrientation(string vh);
  /**
      @return the orientation of the ship(vertical or Horizontal)
  */
  string getOrientation();
  /**
    @param tf - boolean value of whether or not the ship is completely sunk.
    @post Sets whether the ship is sunk or not
   */
  void setSunk(bool tf);
  /**
     @return returns whether or not the ship is sunk.
   */
  bool isSunk();
  /**
   @post Adds a hit to the ship to keep track of whether its sunk yet or not.
   */
  void addHit();
  /**
    @return number of hits on a ship.
   */
  int getHits();
  /**
      @param xPos - x coordinate of the point
      @param yPos - y coordinate of the point
      @post Sets the positions of the ships on the board.
   */
  void setPositions(int xPos, int yPos);
  /**
      @return the xPositions of the ships
      */
  int getXPositions();
  /**
      @return the yPositions of the ships
   */
  int getYPositions();
  /**
      @brief Checks if a coordinate is a hit, miss, or sunk
      @param xPos - x position to check
      @param yPos - y position to check
      @return boolean value of whether or not a coord is used.
   */
  bool coordCheck(int xPos, int yPos);

private:
  int size;//size of the ship
  string orientation;//Orientation of the ship
  bool sunk;//Boolean that stores whether or not the ship is sunk
  int hits;//stores the number of hits the ship has taken.
  int xPositions[5]; //Points to an array of the X postions of each segment of the ship
  int yPositions[5]; //Points to an array of the Y postions of each segment of the ship
};
#endif
