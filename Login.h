#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class Login
{
public:
	Login(void);
	Login( int, std::string, int );
	~Login(void);

	int SetScore( int score_gained )
	{
		return score += score_gained;
	}
	int GetIdNumber(void) const
	{
		return id_number;
	}
	int GetScore(void) const
	{
		return score;
	}
	std::string GetPassword(void) const
	{
		return password;
	}

	bool ValidatePassword( std::string ) const;
private:
	int id_number;
	int score;
	std::string password;
};
#endif