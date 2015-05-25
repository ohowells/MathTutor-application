#include "EvaluationQuiz.h"
#include "ConsoleIn.h"
#include "ConsoleOut.h"
#include "UserDataBase.h"
#include "TopicStateEnum.h"


EvaluationQuiz::EvaluationQuiz( int id, ConsoleIn& app_input,
	ConsoleOut& app_display, UserDataBase& user_database )
	: Quiz( id, app_display, user_database ),
	input( app_input ),
	topic_state( 1 )
{
}

void EvaluationQuiz::Initiate(void)
{
	RunEvaluationQuiz();
}

void EvaluationQuiz::RunEvaluationQuiz(void)
{
	std::ifstream infile;
	switch( topic_state )
	{
	case TOPIC_1:
	case TOPIC_2:
	case TOPIC_3:
	case TOPIC_4:
	case TOPIC_5:
		infile.open("eval_topic_1.txt");
		break;
	default:
		std::cout << "Topic not found...";
		break;
	}

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