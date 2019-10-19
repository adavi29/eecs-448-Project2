/**
 @author Runtime Terrors (Abby Davidow, Anissa Khan, Jacob Swearingen, Grant Schnettgoecke, Chongzhi Gao)
 @date 10/16/19
 @file scoreBoard.h
 @brief methods to read/write to scoreboard file and print scoreboard
*/
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "score.h"

using namespace std;

class scoreBoard {

public:

	/**
	@pre scoreBoard object must have been constructed; scoreBoard.txt must exist and have pairs of initials and scores.
	@return returns the number of scores in scoreBoard.txt
	*/
	int getTxtSize();

	/**
	@pre scoreBoard object constructed; scoreBoard.txt is correctly formatted (only pairs of scores and initials)
	@param newScore - the score object to be recorded in scoreBoard.txt
	@post reads in any old scores into a vector<scores>, inserts newScore in to the vector, and then calls printScoreBoard()
	*/
	void readOldScores(score newScore);

	/**
	@pre scoreBoard object constructed; scoreBoard.txt is correctly formatted
	@param score - a score object to be couted and written to scoreBoard.txt
	@post appends score to scoreBoard.txt; prints the score to terminal
	*/
	void writeNewScore(score score);

	/**
	@pre scoreBoard object constructed
	@param vector<score> - a vector containing any old scores along with the newest high Score in its proper position
	@post clears scoreBoard.h and then calls writeNewScore iteratively to append each score in highScores to scoreBoard.txt
	*/
	void printScoreBoard(vector<score> highScores);

};

#endif
