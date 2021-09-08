#include "User.hpp"


// Get Functions
std::string User::getPaswd() {
	return password;
}
std::string User::getUsrnm() {
	return username;
}
std::string User::getSurnm() {
	return surname;
}
std::string User::getName() {
	return name;
}
std::string User::getBirth() {
	return birth.getDate();
}

// Set Functions
void User::setPaswd(std::string p) {
	this->password = p;
}
void User::setUsrnm(std::string u) {
	this->username = u;
}
void User::setName(std::string n) {
	this->name = n;
}
void User::setSname(std::string sn) {
	this->surname = sn;	
}
void User::setBirth(std::string b) {
	this->birth.setDate(b);
}

// Friend Functions
std::ostream& operator<<(std::ostream& out, const User& temp) {
	out << "name\t\t" << temp.name
	    << "surname\t" << temp.surname
	    << "birth\t\t" << temp.birth
	    << "username\t" << temp.username
	    << "password\t" << temp.password;
	return out;
}
std::istream& operator>>(std::istream& in, User& temp) {
	std::cout << "name:\t\t"; in >> temp.name;
	std::cout << "surname:\t"; in >> temp.surname;
	std::cout << "birth:\t\t"; in >> temp.birth;
	std::cout << "username:\t"; in >> temp.username;
	std::cout << "password:\t"; in >> temp.password;
	return in;
}
