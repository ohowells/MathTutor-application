#include "PracticeQuiz.h"
#include "ConsoleIn.h"
#include "ConsoleOut.h"
#include "UserDataBase.h"
#include "TopicStateEnum.h"

PracticeQuiz::PracticeQuiz( int id, ConsoleIn& app_input, 
	ConsoleOut& app_display, UserDataBase& user_database)
	: Quiz( id, app_display, user_database ),
	input( app_input ),
	topic_state( 1 )
{
}

void PracticeQuiz::Initiate(void)
{
	RunPracticeQuiz();
}

void PracticeQuiz::RunPracticeQuiz(void)
{
	std::ifstream infile;
	switch( topic_state )
	{
	case TOPIC_1:
		infile.open("prac_topic_1.txt");
		break;
	case TOPIC_2:
		infile.open("prac_topic_2.txt");
		break;
	case TOPIC_3:
		infile.open("prac_topic_3.txt");
		break;
	case TOPIC_4:
		infile.open("prac_topic_4.txt");
		break;
	case TOPIC_5:
		infile.open("prac_topic_5.txt");
		break;
	default:
		std::cout << "Topic not found...";
		break;
	}
	/* read questions from infile and prints them to the screen */
	if( infile.is_open() )
	{
		for( std::string t_string; std::getline( infile, t_string ); )
			std::cout << t_string << std::endl;

		float answer_q1, answer_q2, answer_q3;
		std::cin >> answer_q1 
				 >> answer_q2 
				 >> answer_q3;
	}
	else infile.close();
	topic_state++;
}