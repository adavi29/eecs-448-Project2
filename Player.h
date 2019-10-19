/**
    @author Brandon Wheat,William Burdick,Hunter Cobb, Zackariah Khazraeinazmpour, Justin Khounsombath, Runtime Terrors (Abby Davidow, Anissa Khan, Jacob Swearingen, Grant Schnettgoecke, Chongzhi Gao)
    @date 10/16/19
    @file Player.h
    @brief Player class that acts as a storage device for the two players in the gameManager class, holds the ships and boards of each player and fires shots, and can be used for AI
*/
#include "Board.h"
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <stdlib.h>
using namespace std;

class Player
  {
  public:
    ~Player();
    /**
     @brief Default constructor that sets ships and boards to default as well.
    */
    Player();
    /**
     @brief main constructor that sets number of ships and creates an array of myShips
     @param shipNums - Numbers of ships to be included in the player.
    */
    Player(int shipNums,string name);
    /**
     @post sets the positions of the ships on the board.
    */
    void placeShips();
    /**
        @param xPos - x position of shot
        @param yPos - y position of shot
        @param target - player that is to be fired upon.
        @brief function to allow players to fire shots at enemy board.
    */
    bool fireShot(int xPos, int yPos, Player &target);
    /**
      @brief Checks whether a player is still alive
      @return whether or not a players ships have all been sunk
    */
    bool isDead();
    /**
        @param choice - char to decide whether the target board or their own board is to be chosen.
        @return the board specifed
    */
    Board getBoard(char choice);
    /**
      @param xPos - the x position that has been hit
      @param yPos - the y position that has been hit
      @brief takes the enemy player's hit and applies it to the ship that was hit on the opponents board.
    */
    void receiveHit(int xPos, int yPos);
    string getName();

    /**
		@pre player must have been constructed
		@param none
		@return returns the player's member variable score
    */
    int getScore();

    //start runtimeTerrors methods
      /**
       @param
       @brief
       @post
       @return
       */
      Player(int shipNums, int aiDifficulty, string aiName);//constructor for ai
      /**
      @param
      @brief
      @post
      @return
      */
      void placeAiShips();
      /**
      @param
      @brief
      @post
      @return
      */
      string aiEasy();
      /**
      @param
      @brief
      @post
      @return
      */
      string aiMedium(Board enemyBoard);
      /**
      @param
      @brief
      @post
      @return
      */
      string aiHard(Board enemyBoard);//hit the ememy's ship
      /**
      @param
      @brief
      @post
      @return
      */
      string rand0to7();//use for ai coordinate selection
      /**
      @param
      @brief
      @post
      @return
      */
      string randVorH();//use for ai horizontal vs vertical selection; 0=v, 1=h
      /**
      @param
      @brief
      @post
      @return
      */
      string randAtoF();
      /**
      @param
      @brief
      @post
      @return
      */
      string NumtoStrAF(int x);
      /**
      @param
      @brief
      @post
      @return
      */
      string NumtoStr18(int x);
      /**
      @param
      @brief
      @post
      @return
      */
      int getAiDifficulty();

  private:
    Board ownBoard; //Board containing the player's own ships.
    Board enemyBoard; //Board that contains hits and missses for the player
    int numShips;//number of ships assigned to each player
    Ship* ownShips; //Points toward array of ships owned by the player
    string namee;

    //array for aiMedium
    string aiMediumArray[8][8];
    int m_aiDifficulty;
    int score; //a player gets 120 points per hit on an enemy ship
  };
#endif
