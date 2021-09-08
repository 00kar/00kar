#ifndef _DATE_HPP_
#define _DATE_HPP_

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
	std::string getDate() const;
	void setDate(std::string);

	// Friend Functions
	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend std::istream& operator>>(std::istream&, Date&);
};

#endif
