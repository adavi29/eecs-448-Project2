/**
 @author Runtime Terrors (Abby Davidow, Anissa Khan, Jacob Swearingen, Grant Schnettgoecke, Chongzhi Gao)
 @date 10/16/19
 @file score.h
 @brief methods to hold score and initials
*/
#ifndef SCORE_H
#define SCORE_H
#include <fstream>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class score {

public:
	/**
	@post creates score object w/o member variables declared
	*/
	score(){}

	/**
	@param  scoreTotal - player's score
	@post creates score object with scoreTotal; prompts user for initials
	*/
	score(int scoreTotal);

	/**
	@param  initials  - initials of the player
     @param  scoreTotal - player's score
	@post  creates score object with initials and scoreTotal member variables defined
	*/
	score(string initials, int scoreTotal);

	/**
	@pre  score object must have been constructed and initials declared
	@return  returns the member variable  initials of a score
	*/
	string getInitials();

	/**
	@pre  score object must have been constructed and scoreTotal member variable declared
	@return  returns member variable scoreTotal integer
	*/
	int getScoreTotal();

private:
	string m_initials; //holds champs's name
	int m_scoreTotal; //holds champ's score

};
#endif
