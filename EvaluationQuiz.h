#ifndef EVALUATION_H
#define EVALUATION_H

#include "Quiz.h"
class ConsoleIn;

class EvaluationQuiz
	: public Quiz
{
public:
	EvaluationQuiz( int, ConsoleIn&,
		ConsoleOut&, UserDataBase& );

	virtual void Initiate();
private:
	const ConsoleIn& input;
	int topic_state;

	void RunEvaluationQuiz(void);
};
#endif