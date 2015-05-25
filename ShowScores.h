#ifndef SHOW_SCORES_H
#define SHOW_SCORES_H

#include "Quiz.h"
class ConsoleIn; 

class ShowScores
	: public Quiz
{
public:
	ShowScores( int, ConsoleIn&,
		ConsoleOut&, UserDataBase& );

	virtual void Initiate();
private:
	const ConsoleOut& display;
	int current_id_num;
	int score;

	void DisplayScores(void);
};
#endif