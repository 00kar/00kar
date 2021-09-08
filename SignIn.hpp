#ifndef _SIGNIN_HPP_
#define _SIGNIN_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include "User.hpp"


class SignIn
{
private:
	// Fields
	char cwd[PATH_MAX];
	User* DataBase;
	int len;
	
	// Private Methods
	void Write();
	void Read();
	void LogIn();
	void Register();
	bool exist(User&) const;
	std::string EnterUser();
	std::string EnterPaswd();

public:
	// Public Methods
	SignIn();
	void Interface();
};

#endif
