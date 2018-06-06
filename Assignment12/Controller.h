#pragma once
#include <fstream>
#include "Repository.h"
#include "Writer.h"
#include "UndoController.h"

class Controller {
public:
	Controller();
	Controller& operator=(const Controller& ctrl);
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
	void undo();
	void redo();

private:
	Repository repo = Repository{};
	Repository watchList = Repository{"watchlist"};
	UndoController undoController = UndoController{ repo, watchList };
	void populateRepo();
	void populateRepoFromFile();
	Writer* writer = nullptr;
};
