#ifndef CONSOLE_IN_H
#define CONSOLE_IN_H

#include <iostream>
#include <string>

class ConsoleIn
{
public:
	int GetNumInput(void) const
	{
		int u_num;
		bool is_valid = false;
		while( !is_valid )
		{
			std::cin >> u_num;
			if( std::cin.fail() )
			{
				std::cout << "Invalid get_input, please re-enter: ";
				std::cin.clear();
				std::cin.ignore( std::numeric_limits< std::streamsize >::max(),
					'\n');
			}
			else is_valid = true;	
		}
		return u_num;
	}
	std::string GetStrInput(void) const
	{
		std::string u_str;
		std::cin >> u_str;
		return u_str;
	}
};
#endif