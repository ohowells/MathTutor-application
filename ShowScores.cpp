#include "ShowScores.h"
#include "ConsoleOut.h"
#include "UserDataBase.h"

ShowScores::ShowScores(int id, ConsoleIn& app_input,
	ConsoleOut& app_display, UserDataBase& user_database )
	: Quiz( id, app_display, user_database ),
	display( app_display ),
	current_id_num( id ),
	score( 0 )
{ 
}

void ShowScores::Initiate(void)
{
	DisplayScores();
}

void ShowScores::DisplayScores(void)
{
	UserDataBase& user_database = GetUserDataBase();
	score = user_database.SetPlayerScore( current_id_num, score );

	std::cout << "\nScore: " << score;
	if( score < 2 )
		display.ShowMsg("\nYou didn't pass this time...\n");
	else
		display.ShowMsg("\nCongratulations you passed!\n");
}