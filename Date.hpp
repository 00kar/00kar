#pragma once

#include <iostream>
#include <cstring>


class Date
{
private:
	short day;
	short month;
	int year;
	
public:
	// Default Constructor
	Date(short d=1, short m=1, int y=2000)
		:day(d), month(m), year(y)
	{}
	
	// Set/Get Functions
	std::string getDate() const
	{
		return std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
	}
	void setDate(std::string date) {
		char d[date.length() + 1];
		strcpy(d, date.c_str());
		day = std::stoi(strtok(d, "/"));
		month = std::stoi(strtok(NULL, "/"));
		year = std::stoi(strtok(NULL, "/"));
	}
	
	// Friend Functions
	friend std::ostream& operator<<(std::ostream& out, const Date& temp) {
		out << temp.day << "/" << temp.month << "/" << temp.year << "\n";
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Date& temp) {
		in >> temp.day >> temp.month >> temp.year;
		return in;
	}
};