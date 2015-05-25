#ifndef MATH_TUTOR_H
#define MATH_TUTOR_H

#include "ConsoleIn.h"
#include "ConsoleOut.h"
#include "UserDataBase.h"
class Quiz;

class MathTutorApp
{
public:
	MathTutorApp(void);
	~MathTutorApp(void);

	void Initiate(void);
private:
	ConsoleIn get_input;
	ConsoleOut display;
	UserDataBase user_database;

	int current_id_num;
	bool user_authenticated;

	void AuthenticateUser(void);
	int DisplayMainMenu(void) const;
	void RunQuiz(void);

	Quiz* CreateQuiz( int );
};
#endif