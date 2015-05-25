#ifndef Quiz_H
#define Quiz_H

class ConsoleOut;
class UserDataBase;

class Quiz
{
public:
	Quiz( int, ConsoleOut&, 
		UserDataBase& );
	virtual ~Quiz(void);

	int GetIdNumber(void) const;

	ConsoleOut& GetOutput(void) const;
	UserDataBase& GetUserDataBase(void) const;
	
	virtual void Initiate() = 0;
private:
	ConsoleOut& display;
	UserDataBase& user_database;

	int id_number;
};
#endif