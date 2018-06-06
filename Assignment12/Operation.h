#pragma once
#include <string>
#include "Repository.h"
using namespace std;
class Operation
{
public:
	virtual void execute()=0;
	virtual Repository& getRepo() const = 0;
	virtual string getClassName() const = 0;
	virtual string getTitle() const = 0;
};

