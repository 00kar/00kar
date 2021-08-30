#pragma once

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
	std::string getPaswd() {
		return password;
	}
	std::string getUsrnm() {
		return username;
	}
	std::string getSurnm() {
		return surname;
	}
	std::string getName() {
		return name;
	}
	std::string getBirth() {
		return birth.getDate();
	}
	
	// Set Functions
	void setPaswd(std::string p) {
		this->password = p;
	}
	void setUsrnm(std::string u) {
		this->username = u;
	}
	void setName(std::string n) {
		this->name = n;
	}
	void setSname(std::string sn) {
		this->surname = sn;	
	}
	void setBirth(std::string b) {
		this->birth.setDate(b);
	}

	// Friend Functions
	friend std::ostream& operator<<(std::ostream& out, const User& temp) {
		out << "name\t\t" << temp.name
		    << "surname\t" << temp.surname
		    << "birth\t\t" << temp.birth
		    << "username\t" << temp.username
		    << "password\t" << temp.password;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, User& temp) {
		std::cout << "name:\t\t"; in >> temp.name;
		std::cout << "surname:\t"; in >> temp.surname;
		std::cout << "birth:\t\t"; in >> temp.birth;
		std::cout << "username:\t"; in >> temp.username;
		std::cout << "password:\t"; in >> temp.password;
		return in;
	}
};