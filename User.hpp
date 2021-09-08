#ifndef _USER_HPP_
#define _USER_HPP_

#include <iostream>
#include <string>
#include "Date.hpp"


class User
{
private:
	std::string password;
	std::string username;
	std::string surname;
	std::string name;
	Date birth;
	
public:
	// Get Functions
	std::string getPaswd();
	std::string getUsrnm();
	std::string getSurnm();
	std::string getName();
	std::string getBirth();
	
	// Set Functions
	void setPaswd(std::string);
	void setUsrnm(std::string);
	void setName(std::string);
	void setSname(std::string);
	void setBirth(std::string);

	// Friend Functions
	friend std::ostream& operator<<(std::ostream&, const User&);
	friend std::istream& operator>>(std::istream&, User&);
};

#endif
