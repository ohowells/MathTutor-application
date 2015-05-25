#include "Quiz.h"
#include "ConsoleIn.h"
#include "ConsoleOut.h"
#include "UserDataBase.h"
#include "PracticeQuiz.h"

Quiz::Quiz( int id, ConsoleOut& app_display, 
	UserDataBase& user_database )
	: id_number( id ), 
	display( app_display ), 
	user_database( user_database )
{
}

Quiz::~Quiz(void)
{
}

int Quiz::GetIdNumber(void) const
{
	return id_number;
}

ConsoleOut& Quiz::GetOutput(void) const
{
	return display;
}

UserDataBase& Quiz::GetUserDataBase(void) const
{
	return user_database;
}