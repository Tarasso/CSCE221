/*****************************************
** File:    Exceptions.h
** Project: CSCE 221 Project 2
** Author:  Bryson Mrosko
** Date:    3/5/20
** Section: 518
** E-mail:  kylemrosko@tamu.edu
**
**  Exceptions to be thrown
**
*******************************************/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class ItemNotFound : public exception {
	virtual const char* what() const throw() {
		return "Item Not Found Exception: There does not exist an nth element in the BST";
	}
};

class CommandNotFound : public exception {
private:
	string message;
public:
	explicit CommandNotFound(const string& m){
		message = "Invalid Command Exception: " + m + " is not a valid command";
	}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

class NodeNotFound : public exception {
private:
	string message;
public:
	explicit NodeNotFound(const string& m){
		message = "Node Not Found Exception: BST does not contain element " + m;
	}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

class InvalidArgument : public exception {
	virtual const char* what() const throw() {
		return "INVALID ARGUMENT EXCEPTION:";
	}
};

class NullArgumentException : public exception {
private:
	string message;
public:
	explicit NullArgumentException(const string& m){
		message = "NULL Argument Exception: " + m;
	}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

#endif
