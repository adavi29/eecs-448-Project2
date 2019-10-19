/**
 @author Runtime Terrors (Abby Davidow, Anissa Khan, Jacob Swearingen, Grant Schnettgoecke, Chongzhi Gao)
 @date 10/16/19
 @file Animations.h
 @brief Methods that call specific animations
*/

#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include<iostream>
using namespace std;

class Animations{

 public:
    /**
       @post creates Animations object
     */
   Animations();
    /**
      @post deletes Animations object
    */
   ~Animations();
    /**
      @pre player must have hit part of a ship
      @post plays hit animation
    */
   void playHit();
    /**
      @pre player must have missed their shot
      @post plays miss animation
    */
   void playMiss();
    /**
      @pre player must have hit all parts of the ship
      @post plays sunk ship animation
    */
   void playSunk();
    /**
      @pre player 1 has sunk all of player 2's ships
      @post plays player 1 wins animation
    */
   void playP1Wins();
    /**
      @pre player 2 has sunk all of player 1's ships
      @post plays player 2 wins animation
    */
   void playP2Wins();
    /**
      @pre AI has hit all of the player's ships
      @post plays AI wins animation
    */
   void playAIWins();
};
#endif
