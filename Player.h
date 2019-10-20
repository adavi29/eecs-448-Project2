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
		@return returns the player's member variable score
    */
    int getScore();

    //start runtimeTerrors methods
      /**
       @param shipNums - number of ships
       @param aiDifficulty - integer difficulty
       @param aiName - name of the ai
       @brief this the construtor for when the user wants to play against the ai. 
       @post places ships on the ai board, sets the name of ai, set the aidifficulty
       @return n/a
       */
      Player(int shipNums, int aiDifficulty, string aiName);//constructor for ai
      /**
      @brief randomly places ships on the ai board
      @post the baord for ai is now filled with ships
      @return N/A
      */
      void placeAiShips();
      /**
      @brief this method returns a string of where the ai will fire its next shot.
      @post aiDifficulty = 2
      @return a string of the next shot for ai
      */
      string aiEasy();
      /**
      @param enemyBoard - Player 1's board of where the ships are placed.
      @brief this method returns a string of where the ai will fire its next shot.
      @post aiDifficulty = 2
      @return a string of the next shot for ai
      */
      string aiMedium(Board enemyBoard);
      /**
      @param enemyBoard - Player 1's board of where the ships are placed.
      @brief this method returns a string of where the ai will fire its next shot.
      @post aiDifficulty = 2
      @return a string of the next shot for ai
      */
      string aiHard(Board enemyBoard);//hit the ememy's ship
      /**
      @brief random number between 0-7
      @return a stirng of 0-7
      */
      string rand0to7();//use for ai coordinate selection
      /**
      @brief randomly picks 0 or 1
      @post converts the number it picked to V or H
      @return a string of V or H
      */
      string randVorH();//use for ai horizontal vs vertical selection; 0=v, 1=h
      /**
      @brief calcualtes a random number betweeen A-H
      @return a string of 0-7 
      */
      string randAtoF();
      /**
      @param x - integer to be converted
      @brief takes the number passed in and then returs
      @post this method is used in the aiEasy, aiMedium, aiHard methods
      @return the string value of the interger passed in.
      */
      string NumtoStrAF(int x);
      /**
      @param x - integer to be converted
      @brief takes the number passed in and then returns a string value frome 1-8 for the game board.
      @post this method is used in the aiEasy, aiMedium, aiHard methods
      @return a string that is 1-8
      */
      string NumtoStr18(int x);
      /**
      @brief Gives the difficualty fo the AI
      @return an integer of 1,2,3 
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
