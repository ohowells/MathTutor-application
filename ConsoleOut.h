#ifndef CONSOLE_OUT_H
#define CONSOLE_OUT_H

#include <iostream>
#include <string>

class ConsoleOut
{
public:
	void ShowMsg( std::string msg ) const
	{
		std::cout << msg;
	}
};
#endif