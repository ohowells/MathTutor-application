#ifndef USER_DATABASE_H
#define USER_DATABASE_H

#include <fstream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>
#include "Login.h"

class UserDataBase
{
public:
	UserDataBase(void);
	~UserDataBase(void);

	int SetPlayerScore( int, int );
	int GetPlayerScore( int );

	bool AuthenticateUser( int, std::string );
	bool ReadAccount(void);
	bool SaveAccount(void);

	std::string file_name;
private:
	std::vector< Login > temp_store;

	Login* GetAccount( int );
};
#endif