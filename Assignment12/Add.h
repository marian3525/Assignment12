#pragma once
#include "Operation.h"
#include "Repository.h"
using namespace std;

class Add: Operation
{
public:
	Add(string title, string presenter, int duration, int likes, string link, Repository& repo) :
		 title{ title }, duration{ duration }, likes{ likes }, link{ link }, repo{ repo } {};
	// Inherited via Operation
	void execute() override;
	Repository& getRepo() const override;
	string getClassName() const override;
	string getTitle() const override;
private:
	string title;
	string presenter;
	int duration;
	int likes;
	string link;
	Repository& repo;
};

