/**
    @author Hunter Cobb,Brandon Wheat,William Burdick, Zackariah Khazraeinazmpour, Justin Khounsombath, Runtime Terrors (Abby Davidow, Anissa Khan, Jacob Swearingen, Grant Schnettgoecke, Chongzhi Gao)
    @date 10/16/19
    @file gameManager.h
    @brief GameManager acts as the executive class in this game. it has the main gameloop, stores the players, and ends the game when nescessary.
    */
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Player.h"
#include "Animations.h"
#include "scoreBoard.h"
using namespace std;

class gameManager
  {
  public:
    /**Default constructor that sets start to false and starts the run loop.
        */
    gameManager();
    /**Default destructor
        */
    ~gameManager();
    /**method that is called from main.cpp to run rest of the game. opens gameMenu until start is true.
        */
    void run();
    char playerChoice;
		int turnCounter;

  private:
      
    Animations animations;
    int numOfShips = 1;/**holds number of ships that each player will have. defaults to 0*/
    Player p1;/**first player */
    Player p2;/**second player*/
    bool start; /**will signify if gameLoop should be started and menu is left*/
    string PlayerShot;/**string that houses the shot the player takes*/
    /**main menu display where number of ships will be chosen/pre-game
    */
    void playerMenu();
    /**sets the ships of each player individually
        @param name - name of player to be set.
        @param numOfShips - the number of ships to be set to player.
        */
    void setPlayerShips(Player name, int numOfShips);
    /**gameLoop that is entered once all ships have been set and the game is to be played.
        */
    void gameLoop();
    /**Sets a hit on a players ship.
      @param xPos - x position to be marked as a hit.
      @param yPos - y position to be marked as a hit.
    */
    void setHit(int xPos, int yPos);
    /**Sets a miss on a players ship.
      @param xPos - x position to be marked as a miss.
      @param yPos - y position to be marked as a miss.
    */
    void setMiss(int xPos, int yPos);
    /**each run of playerTurn is one players turn. alternates between players based on inputted parameters.
      @param p - player to be passed in as main player of the turn
      @param opponent - player to be passed in as enemy that will be fired upon.
    */
    void playerTurn(Player &p, Player &opponent);
    /**sets game to over when someone sinks their opponenets ships completely.
      @param winner - player who sunk his oppponents ships first.

    */
    void gameOver(Player winner);
      
    void aiTurn(Player &ai, Player &opponent);


      bool inAiMode;
      int aiLevel;

};
#endif
