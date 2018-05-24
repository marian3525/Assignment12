#pragma once
#include <fstream>
#include "Repository.h"
#include "Writer.h"

class Controller {
public:
	Controller();
	~Controller();
	void addTutorial(string title, string presenter, int duration, int likes, string link);
	void removeTutorial(string title);
	void updateTutorial(string title, string presenter, int duration, int likes, string link);
	vector<string> getAllPrintable();
	vector<string> getWatchlistPrintable();
	vector<Tutorial> filterByPresenter(string presenter);
	void addToWatchList(string name);
	vector<Tutorial> getWatchList();
	vector<string> getAllPrintableShort();
	vector<string> getAllPrintableShortWatchlist();
	void likeTutorial(string title);
	void deleteFromWatchlist(string name);
	void sync();
	void setMode(Writer* writer);
	void write();
private:
	Repository repo = Repository{ true };
	Repository watchList = Repository{ true };
	void populateRepo();
	void populateRepoFromFile();
	Writer* writer = nullptr;
};
