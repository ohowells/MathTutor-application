#include "UserDataBase.h"
#include "FileManager.h"

UserDataBase::UserDataBase(void)
{
	file_name = "accounts.txt";
	ReadAccount();
}

UserDataBase::~UserDataBase(void)
{
}

int UserDataBase::SetPlayerScore( int id_number, int score )
{
	Login* const ptr_user_account = GetAccount( id_number );
	return ptr_user_account->SetScore( score );
}

Login* UserDataBase::GetAccount( int id_number )
{
	for( size_t i = 0; i < temp_store.size(); i++ )
		if( temp_store[i].GetIdNumber() == id_number )
			return &temp_store[i];
	return NULL;
}

int UserDataBase::GetPlayerScore( int id_number )
{
	Login* const ptr_user_acoount = GetAccount( id_number );
	return ptr_user_acoount->GetScore();
}

bool UserDataBase::AuthenticateUser( int id_entered, std::string str_entered )
{
	Login* const ptr_user_account = GetAccount( id_entered );

	if( ptr_user_account != nullptr )
		return ptr_user_account->ValidatePassword( str_entered );
	else 
		return false;
}

bool UserDataBase::ReadAccount(void)
{
	FileManager temp_file_manager( file_name );
	return temp_file_manager.ReadAccount( temp_store );
}

bool UserDataBase::SaveAccount(void)
{
	FileManager temp_file_manager( file_name );
	return temp_file_manager.SaveAccount( temp_store );
}