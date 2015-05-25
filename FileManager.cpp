#include "FileManager.h"


FileManager::FileManager( std::string file_name )
	: file_name( file_name )
{
}

FileManager::~FileManager()
{
}

bool FileManager::ReadAccount( std::vector< Login > &temp )
{
	temp.clear();
	std::string t_id_num_str;
	std::string t_pass_str;
	std::string t_score_str;

	std::ifstream infile("accounts.txt");
	if( infile.is_open() )
	{
		while( !(infile.eof()) )
		{
			infile >> t_id_num_str;
			infile >> t_pass_str;
			infile >> t_score_str;
			temp.push_back(Login( atoi( t_id_num_str.c_str()),
								 	    t_pass_str.c_str(),
				                  atoi( t_score_str.c_str())
								 ));
		}
	}
	else
	{
		std::cout << "Unable to open file";
		return false;
	}
	return true;
}

bool FileManager::SaveAccount( const std::vector< Login > &temp )
{
	std::ofstream output_file("accounts.txt");
	if( output_file.is_open() )
	{
		for( unsigned int i = 0; i < temp.size(); i++ )
		{
			output_file << temp[i].GetIdNumber();
			output_file << " ";
			output_file << temp[i].GetPassword();
			output_file << " ";
			output_file << temp[i].GetScore();
			if( i < temp.size() - 1 ) 
				output_file << std::endl;
		}
		output_file.close();
	}
	else
	{
		std::cout << "Unable to open file";
		return false;
	}
	return true;
}