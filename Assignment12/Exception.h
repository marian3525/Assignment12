#pragma once
#include <exception>
#include <string>
using namespace std;

class ControllerException : exception
{
private:
	string message;
public:
	ControllerException(string msg) : message{ msg } {};
	string getMessage();
};

class RepositoryException : exception {
private:
	string message;
public:
	string getMessage();
	RepositoryException(string msg) : message{ msg } {};
};

class ValidatorException : exception {
private:
	string message;
public:
	string getMessage();
	ValidatorException(string msg) :message{ msg } {};
};