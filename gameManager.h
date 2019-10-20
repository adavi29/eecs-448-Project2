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
    /**
     @brief Default constructor that sets start to false and starts the run loop.
    */
    gameManager();
    /**
     @brief Default destructor
    */
    ~gameManager();
    /**
     @post runs game and opens gameMenu until start is true.
    */
    void run();
    string playerChoice;
    int turnCounter;

  private:
      
    Animations animations;
    int numOfShips = 1;//holds number of ships that each player will have. defaults to 0
    Player p1;//first player
    Player p2;//second player
    bool start; //will signify if gameLoop should be started and menu is left
    string PlayerShot;/**string that houses the shot the player takes*/
    /**
     @post displays main menu display where number of ships will be chosen/pre-game
    */
    void playerMenu();
    /**
        @param name - name of player to be set.
        @param numOfShips - the number of ships to be set to player.
        @post sets the ships of each player individually
    */
    void setPlayerShips(Player name, int numOfShips);
    /**
     @brief loop that controls user interactions for player turns during game
    */
    void gameLoop();
    /**
      @param xPos - x position to be marked as a hit.
      @param yPos - y position to be marked as a hit.
      @post Sets a hit on a players ship.
    */
    void setHit(int xPos, int yPos);
    /**
      @param xPos - x position to be marked as a miss.
      @param yPos - y position to be marked as a miss.
      @post Sets a miss on a players ship.
    */
    void setMiss(int xPos, int yPos);
    /**
      @param p - player to be passed in as main player of the turn
      @param opponent - player to be passed in as enemy that will be fired upon.
      @brief each run of playerTurn is one players turn, alternates between players based on inputted parameters.
    */
    void playerTurn(Player &p, Player &opponent);
    /**
      @param winner - player who sunk his oppponents ships first.
      @post sets game to over when someone sinks their opponenets ships completely.
    */
    void gameOver(Player winner);
      
    /**
      @param ai - ai player to be passed in as main player of the turn
      @param opponent - player to be passed in as enemy that will be fired upon.
      @brief AI version of playerTurn
    */void aiTurn(Player &ai, Player &opponent);

      bool inAiMode;
      int aiLevel;

};
#endif
