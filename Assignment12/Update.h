#pragma once
#include "Operation.h"
#include "Repository.h"
#include <string>
using namespace std;

class Update : public Operation
{
public:
	Update(string title, string presenter, int duration, int likes, string link, Repository& repo, Repository& watchlist) :
		title{ title }, presenter{ presenter }, duration{ duration }, likes{ likes }, link{ link }, repo {repo},
		watchlist{ watchlist } {};
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
	Repository& watchlist;
};

