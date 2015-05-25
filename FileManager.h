#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Login.h"

class FileManager
{
public:
	FileManager( std::string );
	~FileManager();

	bool ReadAccount( std::vector< Login > &temp );
	bool SaveAccount( const std::vector< Login > &temp );
private:
	std::string file_name;
};
#endif