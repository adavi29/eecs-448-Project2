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
   Animations();
   ~Animations();
   void playHit();
   void playMiss();
   void playSunk();
   void playP1Wins();
   void playP2Wins();
   void playAIWins();
};
#endif
