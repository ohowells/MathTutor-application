#include "Login.h"

Login::Login(void)
{
}

Login::Login( int id_num, std::string password, int sore)
	: id_number( id_num ), 
	password( password ),
	score( 0 )
{
}

Login::~Login(void)
{
}

bool Login::ValidatePassword( std::string str_entered ) const
{
	if( str_entered != password )
		return false;
	else
		return true;
}