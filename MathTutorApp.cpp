#include "MathTutorApp.h"
#include "Quiz.h"
#include "PracticeQuiz.h"
#include "EvaluationQuiz.h"
#include "ShowScores.h"

enum APP_STATE { IN_PRAC = 1, IN_EVAL, END_QUIZ, EXIT };

MathTutorApp::MathTutorApp(void) 
	: current_id_num( 0 ), 
	user_authenticated( false )
{
}

MathTutorApp::~MathTutorApp(void)
{
}

void MathTutorApp::AuthenticateUser(void)
{
	display.ShowMsg("\nPlease enter ID number: ");
	int u_id = get_input.GetNumInput();
	display.ShowMsg("\nEnter your Password: ");
	std::string u_password = get_input.GetStrInput();

	user_authenticated = user_database.AuthenticateUser( u_id, u_password );

	if( !user_authenticated ) 
		display.ShowMsg("\nInvaild ID or Password. Please try again.\n");
	else 
		current_id_num = u_id;
}

void MathTutorApp::Initiate(void)
{
	while( true )
	{
		while( !user_authenticated )
		{
			display.ShowMsg("\nWelcome!");
			AuthenticateUser();
		}

		RunQuiz();
		user_authenticated = false;
		current_id_num = 0;

		display.ShowMsg("\nSaving account...");
		if( !user_database.SaveAccount() )
			display.ShowMsg("\nERROR...couldn't save!");
		else 
			display.ShowMsg("\nSaved!");
		display.ShowMsg("\nGoodbye.\n");
	}
}

void MathTutorApp::RunQuiz(void)
{
	Quiz* ptr_current_quiz;
	bool user_exited = false;
	while( !user_exited )
	{
		int selection = DisplayMainMenu();
		switch( selection )
		{
			case IN_PRAC:
			case IN_EVAL:
			case END_QUIZ:
				ptr_current_quiz = CreateQuiz( selection );
				ptr_current_quiz->Initiate();

				delete ptr_current_quiz;
				break;
			case EXIT:
				display.ShowMsg("\nExiting...");
				user_exited = true;
				break;
			default:
				display.ShowMsg("\nInvalid selection, Try again.\n");
				break;
		}
	}
}

int MathTutorApp::DisplayMainMenu(void) const
{
	display.ShowMsg("\nMain menu:");
	display.ShowMsg("\n1 - Practice Quiz");
	display.ShowMsg("\n2 - Evaluation Quiz");
	display.ShowMsg("\n3 - View Scores");
	display.ShowMsg("\n4 - Exit\n");
	display.ShowMsg("\nEnter a choice: ");
	return get_input.GetNumInput(); 
}

Quiz* MathTutorApp::CreateQuiz( int app_state )
{
	Quiz* ptr_temp = NULL;
	switch( app_state )
	{
	case IN_PRAC:
		ptr_temp = new PracticeQuiz( current_id_num, get_input,
			display, user_database );
		break;
	case IN_EVAL:
		ptr_temp = new EvaluationQuiz( current_id_num, get_input, 
			display, user_database );
		break;
	case END_QUIZ:
		ptr_temp = new ShowScores( current_id_num, get_input,
			display, user_database );
		break;
	}
	return ptr_temp;
}