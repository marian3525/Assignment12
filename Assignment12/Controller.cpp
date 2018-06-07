#include <algorithm>
#include "Controller.h"
#include "Validator.h"
#include "Exception.h"
#include "CSVWriter.h"
#include "HTMLWriter.h"
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

Controller::Controller() {
	this->repo = Repository{};
	this->watchList = Repository{"watchlist"};
	this->populateRepoFromFile();
	this->repo.sync();
}
Controller& Controller::operator=(const Controller & ctrl)
{
	this->repo = ctrl.repo;
	this->watchList = ctrl.watchList;
	this->writer = ctrl.writer;
	return *this;
}
#pragma warning(disable : 4996)
void Controller::populateRepoFromFile() {
	ifstream f("items.csv");
	string title;
	string presenter;
	int duration = 0;
	int likes = 0;
	string link;

	int field = 0;

	char line[100];

	while (!f.eof()) {
		field = 0;
		f.getline(line, 1000, '\n');
		;
		if (strchr(line, ';') != nullptr) {
			break;
		}
		char* ptr = strtok(line, ",");

		while (ptr != nullptr) {
			switch (field) {
			case(0): {
				field = 1;
				title = string(ptr);
				break;
			}
			case(1): {
				field = 2;
				presenter = string(ptr);
				break;
			}
			case(2): {
				field = 3;
				auto p = (char**)malloc(sizeof(char*));   //...fmm
				string dur_string(ptr);
				duration = int(strtol(dur_string.c_str(), p, 10));
				break;
			}
			case(3): {
				auto p = (char**) malloc(sizeof(char*));   //...fmm
				field = 4;
				string like_string(ptr);
				likes = int(strtol(like_string.c_str(), p, 10));
				break;
			}
			case(4): {
				link = string(ptr);
				field = 5;
				break;
			}
			case(5): {
				break;
			}
			}
			ptr = strtok(nullptr, ",");
		}
		//if(!f.eof())
		{
			try {
				addTutorial(title, presenter, duration, likes, link);
			}
			catch (ValidatorException& e) {

			}
			//cout<<title<<" "<<presenter<<" "<<duration<<" "<<likes<<" "<<link<<endl;
		}
	}
	f.close();

	//clear the undo/redo stacks
	undoController.clearStacks();
}

void Controller::populateRepo() {
	/**
	* Populate the main repo with some test tutorials
	*/
	addTutorial(string("OOP"), string("Iuliana Bocicor"), 7000, 110, string("link1"));

	addTutorial(string("DSA"), string("Marian Zsuzsanna"), 7005, 129, string("link2"));

	addTutorial(string("GA"), string("Lupsa Radu-Lucian"), 6822, 98, string("link3"));

	addTutorial(string("OS"), string("Rares"), 6411, 77, string("link4"));

	addTutorial(string("SysDyn"), string("Buica Adriana"), 7212, 132, string("link5"));

	addTutorial(string("Geometry"), string("Name"), 5983, 70, string("link6"));

	addTutorial(string("FP"), string("Molnar Arthur"), 7022, 133, string("link7"));

	addTutorial(string("ASC"), string("Vancea Alexandru"), 6841, 121, string("link8"));

	addTutorial(string("Algebra"), string("Crivei Septimiu"), 6745, 111, string("link9"));

	addTutorial(string("Calculus"), string("Popovici Nicolae"), 6683, 71, string("link10"));

	addTutorial(string("OS1"), string("Rares"), 6411, 77, string("link4"));
}

vector<string> Controller::getAllPrintable() {
	/**
	* Return a list of strings containing the printable version of each existing tutorial
	* @param n: number of elements found
	*/
	vector<string> output;

	vector<Tutorial> all = repo.getAll();

	for_each(all.begin(), all.end(), [&output](const Tutorial& t) {output.push_back(t.toString()); });
	//delete[] all;
	return output;
}

vector<string> Controller::getWatchlistPrintable()
{
	vector<string> output;
	vector<Tutorial> all = watchList.getAll();

	for_each(all.begin(), all.end(), [&output](const Tutorial& t) {output.push_back(t.toString()); });
	return output;
}

void Controller::addTutorial(string title, string presenter, int duration, int likes, string link) {
	/**
	* @param title: title of the tutorial
	* @param presenter: the name of the presenter
	* @param duration; duration in seconds
	* @param likes: the numberof likes for the tutorial
	* @link: the link to the tutorial
	* @throws: ValidatorException if the validation doesn't pass
	*/
	Validator::validateAdd(title, presenter, duration, likes, link);
	Tutorial tutorial{ title, presenter, duration, likes, link };

	if (repo.existsByTitle(title)) {
		throw ControllerException{ "Element already exists!" };
	}
	else {
		try {
			undoController.clearRedoStack();
			undoController.onAdd(title, presenter, duration, likes, link, "main");
			repo.add(tutorial);
		}
		catch (ValidatorException& e) {

		}
	}
}

void Controller::removeTutorial(string title) {
	/**
	* @param title: The title of the tutorial to be removed
	* @throws; ValidatorException if the validation doesn;t pass
	* @throws: ControllerException if the elem doesn't exist
	* @throws: ValidatorExeption, ControllerException
	*/
	Validator::validateRemove(title);
	if (watchList.existsByTitle(title)) {
		undoController.onRemove(title, "watchlist");
		this->watchList.remove(title);
		undoController.onRemove(title, "main");
		this->repo.remove(title);
	}
	else {
		if (repo.existsByTitle(title)) {
			undoController.clearRedoStack();
			undoController.onRemove(title, "main");
			this->repo.remove(title);
		}
		else {
			throw ControllerException{ "Element doesn't exist" };
		}
	}
}

void Controller::updateTutorial(string title, string newpresenter, int newduration, int newlikes, string newlink) {
	/**
	*  @param: the title of the tutorial to be updated
	*  @param: presenter: new name of the presenter
	*  @param: duration: new duration
	*  @param: likes: new number of likes
	*  @param: link: new link to the tutorial
	*  @throws: ValidatorException, ControllerException
	*/
	Validator::validateAdd(title, newpresenter, newduration, newlikes, newlink);

	if (repo.existsByTitle(title)) {
		Tutorial t = repo.getByTitle(title);
		string presenter = t.getPresenter();
		int duration = t.getDuration();
		int likes = t.getLikes();
		string link = t.getLink();

		undoController.clearRedoStack();
		undoController.onUpdate(title, presenter, duration, likes, link, "main", newpresenter, newduration, newlikes, newlink);
		repo.update(title, presenter, duration, likes, link);
	}
	else {
		throw ControllerException{ "Elemeeent doesn't exist" };
	}
}

vector<Tutorial> Controller::filterByPresenter(string presenter) {
	/**
	* @param: presenter: the name of the presenter to filter by
	* Return all if the name string is empty
	*/
	vector<Tutorial> results;
	//results.reserve(10);
	vector<Tutorial> all = this->repo.getAll();

	if (presenter == string("")) {
		return all;
	}
	//copy_if(all.begin(), all.end(), results.begin(), [&presenter](const Tutorial& t){return t.getPresenter() == presenter;});

	for (auto t : all) {
		if (t.getPresenter() == presenter) {
			results.push_back(t);
		}
	}

	return results;
}

void Controller::addToWatchList(string name) {
	/**
	* Will add the tutorial with the given name iff. it doesn't exist already
	* @param name: name of the tutorial to  be added
	* @throws: ControllerException
	*/
	if (!watchList.existsByTitle(name)) {
		//get the info for the undoController
		Tutorial t = repo.getByTitle(name);
		string presenter = t.getPresenter();
		int duration = t.getDuration();
		int likes = t.getLikes();
		string link = t.getLink();

		undoController.clearRedoStack();
		undoController.onAdd(name, presenter, duration, likes, link, "watchlist");
		watchList.add(repo.getByTitle(name));
	}
	else {
		//already included
		throw ControllerException{ "Item already included" };
	}
}

vector<Tutorial> Controller::getWatchList() {
	/**
	* @parm n: variable to return the number of tutorials in the watchList
	* Return a list of pointer to tutorials currently in the watch list
	*/
	vector<Tutorial> result;
	vector<Tutorial> workingList = watchList.getAll();
	//copy(workingList.begin(), workingList.end(), result.begin());
	for (const auto& t : workingList)
		result.push_back(t);
	return result;
}

vector<string> Controller::getAllPrintableShort()
{
	vector<Tutorial> all = repo.getAll();
	vector<string> result;
	for_each(all.begin(), all.end(), [&](const Tutorial& t) {
		string temp; 
		temp += t.getTitle(); 
		temp += " " + t.getPresenter(); 
		temp += " " + to_string(t.getLikes());
		temp += " " + to_string(t.getDuration() / 60) + "m" + to_string(t.getDuration() % 60) + "s";
		temp += " " + t.getLink();
		result.push_back(temp);
	});
	return result;
}

vector<string> Controller::getAllPrintableShortWatchlist()
{
	vector<Tutorial> all = watchList.getAll();
	vector<string> result;
	for_each(all.begin(), all.end(), [&](const Tutorial& t) {
		string temp;
		temp += t.getTitle();
		temp += " " + t.getPresenter();
		temp += " " + to_string(t.getLikes());
		temp += " " + to_string(t.getDuration() / 60) + "m" + to_string(t.getDuration() % 60) + "s";
		temp += " " + t.getLink();
		result.push_back(temp);
	});
	return result;
}

void Controller::deleteFromWatchlist(string name) {
	/**
	* Removes the specified tutorial if it exists in the repo
	* @param name: name of the tutorial to be removed
	* @throws: RepositoryException if the tutorial wioth the given name doesn't exist
	*/
	undoController.clearRedoStack();
	undoController.onRemove(name, "watchlist");
	watchList.remove(name);
}

void Controller::likeTutorial(string title) {
	/**
	* Increment the likes of the tutorial with the given name
	* @param title: the titile of the tutorial to like
	*/
	repo.getByTitle(title).incLikes();
	//and for the watchlist
	if (watchList.existsByTitle(title)) {

		undoController.clearRedoStack();
		undoController.onLike(title);
		watchList.getByTitle(title).incLikes();
	}
}

void Controller::sync() {
	/*
	Sync the memory repo with the files
	*/
	repo.sync();
}

void Controller::setMode(Writer* writer) {
	this->writer = writer;
}

void Controller::write() {
	writer->write(watchList);
}

void Controller::undo()
{
	undoController.undo();
}

void Controller::redo()
{
	undoController.redo();
}
