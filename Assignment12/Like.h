#pragma once
#include "Operation.h"
#include "Repository.h"

class Like : public Operation
{
public:
	Like(string title, Repository& repo, Repository& watchlist) : title{ title }, repo{ repo }, watchlist{ watchlist } {};
	void execute() override;
	Repository& getRepo() const override;
	string getClassName() const override;
	string getTitle() const override;
private:
	Repository & repo;
	Repository& watchlist;
	string title;
};

