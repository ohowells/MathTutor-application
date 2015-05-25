#ifndef PRACTICE_H
#define PRACTICE_H

#include "Quiz.h"
class ConsoleIn;

class PracticeQuiz
	: public Quiz
{
public:
	PracticeQuiz( int, ConsoleIn&,
		ConsoleOut&, UserDataBase& );

	virtual void Initiate();
private:
	const ConsoleIn& input;
	int topic_state;

	void RunPracticeQuiz(void);
};
#endif