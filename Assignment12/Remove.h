#pragma once
#include "Operation.h"
#include <string>
#include "Repository.h"
using namespace std;

class Remove: 
	Operation
{
public:
	Remove(string t, Repository& r) : title{ t }, repo{ r } {};
	void execute() override;
	Repository& getRepo() const override;
	string getClassName() const override;
	string getTitle() const  override;
private:
	string title;
	Repository& repo;
};

