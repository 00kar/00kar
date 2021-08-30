#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include "User.hpp"


class SignIn
{
private:
	char cwd[PATH_MAX];
	User* DataBase;
	int len;
	
public:
	SignIn() {
		len = 0;
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/.data.txt");
		std::ofstream data;
		data.open(cwd, std::ios_base::app);
		data.close();
		Read();
	}

	void Interface() {
		std::string choice;
		for(int i=0; i < 174; ++i) { std::cout << '*'; }
		std::cout << "\n\t\t\t\t\t\t\t__________________________"
			      << "\n\t\t\t\t\t\t\t| 1. LogIn | 2. Register |"
			      << "\n\nYour choice:\t";
		std::cin >> choice;
		if(choice == "Register") {
			Register();
			LogIn();
		}
		else if(choice == "LogIn") {
			LogIn();
		}
		Interface();
	}

	void Write() {
		std::ofstream data;
		data.open(cwd, std::ios_base::app);
		data << "User: " << len << "\n"
			 << DataBase[len-1].getName() << "\n"
			 << DataBase[len-1].getSurnm() << "\n"
			 << DataBase[len-1].getBirth() << "\n"
			 << DataBase[len-1].getUsrnm() << "\n"
			 << DataBase[len-1].getPaswd() << "\n";
		data.close();
	}
	
	void Read() {
		std::ifstream data;
		std::string line;
		int count = 0;
		data.open(cwd);
		while( getline(data, line) ) {
			if ( count%6 == 0) {
				++len;
				User* temp = DataBase;
				DataBase = new User[len];
				for(int i = 0; i < len - 1; ++i) { DataBase[i] = temp[i]; }
				delete [] temp;
			}
			else if( count%6 == 1 ) { DataBase[len-1].setName(line); }
			else if( count%6 == 2 ) { DataBase[len-1].setSname(line); }
			else if( count%6 == 3 ) { DataBase[len-1].setBirth(line); }
			else if( count%6 == 4 ) { DataBase[len-1].setUsrnm(line); }
			else if( count%6 == 5 ) { DataBase[len-1].setPaswd(line); }
			++count;
		}
		data.close();
	}
	
	void LogIn() {
		User temp;
		while(true) {
			int check = 0;
			std::string username = EnterUser();
			for(int i=0; i < len; ++i) {
				if( username == DataBase[i].getUsrnm() ) { 
					temp = DataBase[i];
					check = 1;
					break;
			       	}
			}
			if(check == 1) { break; }
			else
				std::cout << "\nNo such user name. Try again!\n";
		}
		int i=0;
		for(; i < 3; ++i) {
			int check = 0;
			std::string password = EnterPaswd();
			if( temp.getPaswd() == password ) {
				std::cout << "\nLoggin Successed!\nPress any key to continue...";
				char a;
				std::cin >> a;
				i = -1;
				break;
			}
			std::cout << "\nWrong password, try again!\n";
		}
		if(i != -1) {
			std::cerr << "\nWrong password, Loggin failed!\n";
			exit(1);
		}
	}
	
	void Register() {
		User newUser;
		do { std::cin >> newUser; }
		while(exist(newUser));
		User* t = DataBase;
		DataBase = new User[++len];
		for(int i = 0; i < len - 1; ++i)
			DataBase[i] = t[i];
		DataBase[len-1] = newUser;
		delete [] t;
		Write();
		std::cout << "\nRegisteration successed, now you can log in.\n\n";
	}

	bool exist(User& given) const
	{
		for(int i = 0; i < len; ++i) {
			if(given.getUsrnm() == DataBase[i].getUsrnm()) {
				std::cout << "\nThe user already exists!\n";
				return true;
			}
		}
		return false;
	}

	// Uname/Pass Entery Functions
	std::string EnterUser() {
		std::string username;
		std::cout << "____________\n| Username |\t";
		std::cin >> username;
		return username;
	}
	std::string EnterPaswd() {
		std::string password;
		std::cout << "____________\n| Password |\t";
		std::cin >> password;
		return password;
	}
};