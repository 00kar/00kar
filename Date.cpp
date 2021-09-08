#include "Date.hpp"


// Set/Get Functions
std::string Date::getDate() const
{
	return std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
}
void Date::setDate(std::string date) {
	char d[date.length() + 1];
	strcpy(d, date.c_str());
	day = std::stoi(strtok(d, "/"));
	month = std::stoi(strtok(NULL, "/"));
	year = std::stoi(strtok(NULL, "/"));
}

// Friend Functions
std::ostream& operator<<(std::ostream& out, const Date& temp) {
	out << temp.day << "/" << temp.month << "/" << temp.year << "\n";
	return out;
}
std::istream& operator>>(std::istream& in, Date& temp) {
	in >> temp.day >> temp.month >> temp.year;
	return in;
}
