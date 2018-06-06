#pragma once
#include "Operation.h"
#include "Repository.h"

class Like : public Operation
{
public:
	Like(string title, int likesAdded, Repository& repo) : title{ title }, likesAdded{ likesAdded }, repo{ repo } {};
	void execute() override;
	Repository& getRepo() const override;
	string getClassName() const override;
	string getTitle() const override;
private:
	Repository & repo;
	string title;
	int likesAdded;
};

